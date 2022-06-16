/*
 *  This file is part of LSST M2 support system package.
 *
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the LSST License Statement and
 * the GNU General Public License along with this program.  If not,
 * see <http://www.lsstcorp.org/LegalNotices/>.
 */

// Class header
#include "demo/FpgaDemo.h"

// System headers
#include <iostream>
#include <thread>

// Project headers
#include "crio/NiFpga_FPGA_VI.h"

using namespace std;
namespace LSST {

int FpgaDemo::run() {
    cout << "Initializing...\n";
    NiFpga_Status status = NiFpga_Initialize();
    if (NiFpga_IsNotError(status)) {
        NiFpga_Session session;
        // opens a session, downloads the bitstream, and runs the FPGA
        cout << "Opening a session...\n";
        // TODO: NiFpga_FPGA_VI_Bitfile probably needs to be prepended with a path
        string bitfile = NiFpga_FPGA_VI_Bitfile;
        cout << "opening " << bitfile << endl;
        NiFpga_MergeStatus(&status,
                           NiFpga_Open(bitfile.c_str(), NiFpga_FPGA_VI_Signature,
                                       "RIO0", NiFpga_OpenAttribute_NoRun, &session));
        if (NiFpga_IsNotError(status)) {


            // run the FPGA application
            cout << "Running the FPGA...\n";
            NiFpga_MergeStatus(&status, NiFpga_Run(session, 0));

            /* TODO -- not for our system, delete
            int16_t rawTemperature = 0;
            double fahrenheit;
            // read the current temperature
            NiFpga_MergeStatus(
                    &status, NiFpga_ReadI16(session, NiFpga_ExampleCompactRIO_IndicatorI16_DeviceTemperature,
                                            &rawTemperature));
            fahrenheit = (rawTemperature / 4.0) * (9.0 / 5.0) + 32;
            printf("Current temperature in Fahrenheit: %.1f\n", fahrenheit);
            */

            cout << "loop start" << endl;
            NiFpga_Bool userSw0 = 0;
            while (loop) {

                // read UserSwitch0
                NiFpga_MergeStatus(
                    &status, NiFpga_ReadBool(session, NiFpga_FPGA_VI_IndicatorBool_UserSwitch0,
                                            &userSw0));
                cout << "userSw0=" << ((userSw0) ? "true" : "false") << endl;
                this_thread::sleep_for(200ms);
            }

            /* TODO: There's no stop control in this FPGA VI. Maybe one should be added.
            cout << "Stopping the FPGA...\n";
            NiFpga_MergeStatus(&status,
                               NiFpga_WriteBool(session, NiFpga_ExampleCompactRIO_ControlBool_Stop, 1));
            */
            // close the session now that we're done
            printf("Closing the session...\n");
            NiFpga_MergeStatus(&status, NiFpga_Close(session, 0));
        }
        // must be called after all other calls
        printf("Finalizing...\n");
        NiFpga_MergeStatus(&status, NiFpga_Finalize());
    }
    // check if anything went wrong
    if (NiFpga_IsError(status)) {
        cout << "Error " << status << endl;
        cout << "Press <Enter> to quit...\n";
        getchar();
    }
    return status;
}

}  // namespace LSST
