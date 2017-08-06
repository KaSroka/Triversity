/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 21-08-2017
 * last modification: 21-08-2017
 *
 * @copyright Copyright (c) 2017, microHAL
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *     2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *     3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "Fonts.h"
#include "microhal.h"

namespace Fonts {
namespace Roboto {
//
//  Font data for Roboto 9pt
//

// Character bitmaps for Roboto 9pt
static const uint8_t Bitmaps[] = {
    // @0 ' ' (2 pixels wide)
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    0x00, 0x00, 0x00, 0x00,

    // @4 '0' (5 pixels wide)
    //  ###
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // #  ##
    //  ###
    //
    //
    0xFE, 0x01, 0x01, 0x81, 0xFE, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @14 '1' (3 pixels wide)
    //   #
    // ###
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //
    //
    0x02, 0x02, 0xFF, 0x00, 0x00, 0x01,

    // @20 '2' (5 pixels wide)
    //  ###
    // #  ##
    // #   #
    //     #
    //    #
    //   #
    //  #
    // #
    // #####
    //
    //
    0x86, 0x41, 0x21, 0x13, 0x0E, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @30 '3' (5 pixels wide)
    //  ###
    // #  ##
    //     #
    //    ##
    //  ###
    //     #
    //     #
    // #   #
    //  ###
    //
    //
    0x82, 0x11, 0x11, 0x1B, 0xEE, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @40 '4' (6 pixels wide)
    //     #
    //    ##
    //    ##
    //   # #
    //  #  #
    //  #  #
    // ######
    //     #
    //     #
    //
    //
    0x40, 0x70, 0x48, 0x46, 0xFF, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,

    // @52 '5' (5 pixels wide)
    //  ####
    // ##
    // #
    // ####
    // #   #
    //     #
    //     #
    // #   #
    //  ###
    //
    //
    0x9E, 0x0B, 0x09, 0x09, 0xF1, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @62 '6' (5 pixels wide)
    //   ##
    //  #
    // #
    // ####
    // #   #
    // #   #
    // #   #
    // #   #
    //  ###
    //
    //
    0xFC, 0x0A, 0x09, 0x09, 0xF0, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @72 '7' (6 pixels wide)
    // ######
    //      #
    //     #
    //     #
    //     #
    //    #
    //    #
    //   #
    //   #
    //
    //
    0x01, 0x01, 0x81, 0x61, 0x1D, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,

    // @84 '8' (5 pixels wide)
    //  ###
    // #  ##
    // #   #
    // #  ##
    //  ###
    // #   #
    // #   #
    // #   #
    //  ###
    //
    //
    0xEE, 0x11, 0x11, 0x1B, 0xEE, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @94 '9' (5 pixels wide)
    //  ###
    // #  ##
    // #   #
    // #   #
    // #  ##
    //  ## #
    //     #
    //    #
    //  ##
    //
    //
    0x1E, 0x21, 0x21, 0x93, 0x7E, 0x00, 0x01, 0x01, 0x00, 0x00,

    // @104 'A' (8 pixels wide)
    //    ##
    //    ##
    //    ##
    //   #  #
    //   #  #
    //   #  #
    //  ######
    //  #    #
    // ##    ##
    //
    //
    0x00, 0xC0, 0x78, 0x47, 0x47, 0x78, 0xC0, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,

    // @120 'B' (6 pixels wide)
    // #####
    // #   #
    // #   ##
    // #   #
    // ####
    // #   ##
    // #    #
    // #   ##
    // #####
    //
    //
    0xFF, 0x11, 0x11, 0x11, 0xAF, 0xE4, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @132 'C' (6 pixels wide)
    //  ####
    // ##   #
    // #    #
    // #
    // #
    // #
    // #    #
    // ##   #
    //  ####
    //
    //
    0xFE, 0x83, 0x01, 0x01, 0x01, 0xC6, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @144 'D' (6 pixels wide)
    // ####
    // #   #
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    // #   #
    // ####
    //
    //
    0xFF, 0x01, 0x01, 0x01, 0x82, 0x7C, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,

    // @156 'E' (5 pixels wide)
    // #####
    // #
    // #
    // #
    // #####
    // #
    // #
    // #
    // #####
    //
    //
    0xFF, 0x11, 0x11, 0x11, 0x11, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @166 'F' (5 pixels wide)
    // #####
    // #
    // #
    // #
    // #####
    // #
    // #
    // #
    // #
    //
    //
    0xFF, 0x11, 0x11, 0x11, 0x11, 0x01, 0x00, 0x00, 0x00, 0x00,

    // @176 'G' (6 pixels wide)
    //  ####
    // ##   #
    // #    #
    // #
    // #  ###
    // #    #
    // #    #
    // ##   #
    //  ####
    //
    //
    0xFE, 0x83, 0x01, 0x11, 0x11, 0xF6, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @188 'H' (7 pixels wide)
    // #    ##
    // #    ##
    // #    ##
    // #    ##
    // #######
    // #    ##
    // #    ##
    // #    ##
    // #    ##
    //
    //
    0xFF, 0x10, 0x10, 0x10, 0x10, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,

    // @202 'I' (1 pixels wide)
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    //
    //
    0xFF, 0x01,

    // @204 'J' (6 pixels wide)
    //      #
    //      #
    //      #
    //      #
    //      #
    //      #
    //      #
    // ##  #
    //  ####
    //
    //
    0x80, 0x80, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @216 'K' (7 pixels wide)
    // #    #
    // #   #
    // #  #
    // # #
    // ###
    // #  #
    // #  ##
    // #   #
    // #    ##
    //
    //
    0xFF, 0x10, 0x18, 0x64, 0xC2, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,

    // @230 'L' (5 pixels wide)
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #####
    //
    //
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @240 'M' (8 pixels wide)
    // ##     #
    // ##    ##
    // ##    ##
    // # #   ##
    // # #  # #
    // # ## # #
    // #  # # #
    // #  ##  #
    // #   #  #
    //
    //
    0xFF, 0x07, 0x38, 0xE0, 0x80, 0x70, 0x0E, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01,

    // @256 'N' (7 pixels wide)
    // ##    #
    // ##    #
    // # #   #
    // # ##  #
    // #  #  #
    // #   # #
    // #   # #
    // #    ##
    // #    ##
    //
    //
    0xFF, 0x03, 0x0C, 0x18, 0x60, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,

    // @270 'O' (7 pixels wide)
    //  ####
    // ##   #
    // #    #
    // #    ##
    // #    ##
    // #    ##
    // #    #
    // ##   #
    //  ####
    //
    //
    0xFE, 0x83, 0x01, 0x01, 0x01, 0xFE, 0x38, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,

    // @284 'P' (6 pixels wide)
    // #####
    // #    #
    // #    #
    // #    #
    // #####
    // #
    // #
    // #
    // #
    //
    //
    0xFF, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,

    // @296 'Q' (6 pixels wide)
    //  ####
    // ##  ##
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    // ##  ##
    //  ####
    //      #
    //
    0xFE, 0x83, 0x01, 0x01, 0x83, 0xFE, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02,

    // @308 'R' (6 pixels wide)
    // #####
    // #   #
    // #   ##
    // #   #
    // #####
    // #  #
    // #   #
    // #   #
    // #    #
    //
    //
    0xFF, 0x11, 0x11, 0x31, 0xDF, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,

    // @320 'S' (7 pixels wide)
    //   ###
    //  #   #
    //  #   ##
    //  ##
    //   ###
    //      #
    // ##   ##
    //  #   #
    //   ####
    //
    //
    0x40, 0xCE, 0x19, 0x11, 0x11, 0xE6, 0x44, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @334 'T' (7 pixels wide)
    // #######
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //
    //
    0x01, 0x01, 0x01, 0xFF, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,

    // @348 'U' (6 pixels wide)
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    // ##  ##
    //  ####
    //
    //
    0xFF, 0x80, 0x00, 0x00, 0x80, 0xFF, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @360 'V' (8 pixels wide)
    // ##    ##
    //  #    #
    //  #    #
    //   #  #
    //   #  #
    //   #  #
    //    ##
    //    ##
    //    ##
    //
    //
    0x01, 0x07, 0x38, 0xC0, 0xC0, 0x38, 0x07, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00,

    // @376 'W' (10 pixels wide)
    // ##   #   #
    //  #   #   #
    //  #  # #  #
    //  #  # #  #
    //  #  # # #
    //   ##  # #
    //   ##   ##
    //   ##   ##
    //   ##   #
    //
    //
    0x01, 0x1F, 0xE0, 0xE0, 0x1C, 0x03, 0x3C, 0xC0, 0xF0, 0x0F, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @396 'X' (7 pixels wide)
    // ##    #
    //  ##  #
    //   # ##
    //    ##
    //    #
    //   ###
    //   # ##
    //  ##  #
    // ##    #
    //
    //
    0x01, 0x83, 0xE6, 0x38, 0x6C, 0xC6, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,

    // @410 'Y' (7 pixels wide)
    // ##    #
    //  #   #
    //  ##  #
    //   # #
    //   ###
    //    #
    //    #
    //    #
    //    #
    //
    //
    0x01, 0x07, 0x1C, 0xF0, 0x18, 0x06, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,

    // @424 'Z' (7 pixels wide)
    //  ######
    //      #
    //     #
    //     #
    //    #
    //   #
    //   #
    //  #
    // #######
    //
    //
    0x00, 0x81, 0x61, 0x11, 0x0D, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @438 'a' (5 pixels wide)
    //
    //
    //  ###
    // #   #
    //     #
    //  ####
    // #   #
    // #   #
    //  ####
    //
    //
    0xC8, 0x24, 0x24, 0x24, 0xF8, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @448 'b' (5 pixels wide)
    // #
    // #
    // ####
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // ####
    //
    //
    0xFF, 0x04, 0x04, 0x04, 0xF8, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @458 'c' (6 pixels wide)
    //
    //
    //   ###
    //  #  ##
    // ##
    // #
    // ##
    //  #  ##
    //   ###
    //
    //
    0x70, 0xD8, 0x04, 0x04, 0x8C, 0x88, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @470 'd' (5 pixels wide)
    //     #
    //     #
    //  ####
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //  ####
    //
    //
    0xF8, 0x04, 0x04, 0x04, 0xFF, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @480 'e' (6 pixels wide)
    //
    //
    //   ###
    //  #  #
    // ##   #
    // ######
    // ##
    //  #  #
    //   ####
    //
    //
    0x70, 0xF8, 0x24, 0x24, 0xAC, 0x30, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @492 'f' (4 pixels wide)
    //   ##
    //  #
    // ####
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    //
    //
    0x04, 0xFE, 0x05, 0x05, 0x00, 0x01, 0x00, 0x00,

    // @500 'g' (5 pixels wide)
    //
    //
    //  ####
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //  ####
    //     #
    // ####
    0xF8, 0x04, 0x04, 0x04, 0xFC, 0x04, 0x05, 0x05, 0x05, 0x03,

    // @510 'h' (5 pixels wide)
    // #
    // #
    // # ##
    // ##  #
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //
    //
    0xFF, 0x08, 0x04, 0x04, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @520 'i' (1 pixels wide)
    // #
    //
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    //
    //
    0xFD, 0x01,

    // @522 'j' (2 pixels wide)
    //  #
    //
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    // ##
    0x00, 0xFD, 0x04, 0x07,

    // @526 'k' (5 pixels wide)
    // #
    // #
    // #  ##
    // # ##
    // ###
    // ###
    // # #
    // #  #
    // #  ##
    //
    //
    0xFF, 0x30, 0x78, 0x8C, 0x04, 0x01, 0x00, 0x00, 0x01, 0x01,

    // @536 'l' (1 pixels wide)
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    //
    //
    0xFF, 0x01,

    // @538 'm' (9 pixels wide)
    //
    //
    // #### ###
    // #   #   #
    // #   #   #
    // #   #   #
    // #   #   #
    // #   #   #
    // #   #   #
    //
    //
    0xFC, 0x04, 0x04, 0x04, 0xF8, 0x04, 0x04, 0x04, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @556 'n' (5 pixels wide)
    //
    //
    // # ##
    // ##  #
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //
    //
    0xFC, 0x08, 0x04, 0x04, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @566 'o' (5 pixels wide)
    //
    //
    //  ###
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //  ###
    //
    //
    0xF8, 0x04, 0x04, 0x04, 0xF8, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @576 'p' (5 pixels wide)
    //
    //
    // ####
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // ####
    // #
    // #
    0xFC, 0x04, 0x04, 0x04, 0xF8, 0x07, 0x01, 0x01, 0x01, 0x00,

    // @586 'q' (5 pixels wide)
    //
    //
    //  ####
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //  ####
    //     #
    //     #
    0xF8, 0x04, 0x04, 0x04, 0xFC, 0x00, 0x01, 0x01, 0x01, 0x07,

    // @596 'r' (3 pixels wide)
    //
    //
    // ###
    // #
    // #
    // #
    // #
    // #
    // #
    //
    //
    0xFC, 0x04, 0x04, 0x01, 0x00, 0x00,

    // @602 's' (5 pixels wide)
    //
    //
    //  ####
    //  #  #
    //  #
    //   ###
    //     #
    // ##  #
    //  ####
    //
    //
    0x80, 0x9C, 0x24, 0x24, 0xEC, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @612 't' (4 pixels wide)
    //  #
    //  #
    // ####
    //  #
    //  #
    //  #
    //  #
    //  #
    //   ##
    //
    //
    0x04, 0xFF, 0x04, 0x04, 0x00, 0x00, 0x01, 0x01,

    // @620 'u' (5 pixels wide)
    //
    //
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //  ####
    //
    //
    0xFC, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @630 'v' (6 pixels wide)
    //
    //
    // ##  ##
    //  #  #
    //  #  #
    //  #  #
    //   ##
    //   ##
    //   ##
    //
    //
    0x04, 0x3C, 0xC0, 0xC0, 0x3C, 0x04, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,

    // @642 'w' (9 pixels wide)
    //
    //
    // #   #   #
    //  #  #  #
    //  # # # #
    //  # # # #
    //  # # # #
    //   #   #
    //   #   #
    //
    //
    0x04, 0x78, 0x80, 0x70, 0x0C, 0x70, 0x80, 0x78, 0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @660 'x' (6 pixels wide)
    //
    //
    // ##  ##
    //  #  #
    //   ##
    //   ##
    //   ##
    //  #  #
    // ##  ##
    //
    //
    0x04, 0x8C, 0x70, 0x70, 0x8C, 0x04, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,

    // @672 'y' (6 pixels wide)
    //
    //
    // ##  ##
    //  #  #
    //  #  #
    //   ##
    //   ##
    //   ##
    //   #
    //   #
    //  ##
    0x04, 0x1C, 0xE0, 0xE0, 0x1C, 0x04, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00,

    // @684 'z' (5 pixels wide)
    //
    //
    // ####
    //    #
    //   #
    //  ##
    //  #
    // #
    // #####
    //
    //
    0x84, 0x64, 0x34, 0x0C, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
};

// Character descriptors for Roboto 9pt
// { [Char width in bits], [Offset into roboto_9ptCharBitmaps in bytes] }
static const Font::FontDescriptor Descriptors[] = {
    {2, 0},     //
    {0, 0},     // !
    {0, 0},     // "
    {0, 0},     // #
    {0, 0},     // $
    {0, 0},     // %
    {0, 0},     // &
    {0, 0},     // '
    {0, 0},     // (
    {0, 0},     // )
    {0, 0},     // *
    {0, 0},     // +
    {0, 0},     // ,
    {0, 0},     // -
    {0, 0},     // .
    {0, 0},     // /
    {5, 4},     // 0
    {3, 14},    // 1
    {5, 20},    // 2
    {5, 30},    // 3
    {6, 40},    // 4
    {5, 52},    // 5
    {5, 62},    // 6
    {6, 72},    // 7
    {5, 84},    // 8
    {5, 94},    // 9
    {0, 0},     // :
    {0, 0},     // ;
    {0, 0},     // <
    {0, 0},     // =
    {0, 0},     // >
    {0, 0},     // ?
    {0, 0},     // @
    {8, 104},   // A
    {6, 120},   // B
    {6, 132},   // C
    {6, 144},   // D
    {5, 156},   // E
    {5, 166},   // F
    {6, 176},   // G
    {7, 188},   // H
    {1, 202},   // I
    {6, 204},   // J
    {7, 216},   // K
    {5, 230},   // L
    {8, 240},   // M
    {7, 256},   // N
    {7, 270},   // O
    {6, 284},   // P
    {6, 296},   // Q
    {6, 308},   // R
    {7, 320},   // S
    {7, 334},   // T
    {6, 348},   // U
    {8, 360},   // V
    {10, 376},  // W
    {7, 396},   // X
    {7, 410},   // Y
    {7, 424},   // Z
    {0, 0},     // [
    {0, 0},     // \ /
    {0, 0},     // ]
    {0, 0},     // ^
    {0, 0},     // _
    {0, 0},     // `
    {5, 438},   // a
    {5, 448},   // b
    {6, 458},   // c
    {5, 470},   // d
    {6, 480},   // e
    {4, 492},   // f
    {5, 500},   // g
    {5, 510},   // h
    {1, 520},   // i
    {2, 522},   // j
    {5, 526},   // k
    {1, 536},   // l
    {9, 538},   // m
    {5, 556},   // n
    {5, 566},   // o
    {5, 576},   // p
    {5, 586},   // q
    {3, 596},   // r
    {5, 602},   // s
    {4, 612},   // t
    {5, 620},   // u
    {6, 630},   // v
    {9, 642},   // w
    {6, 660},   // x
    {6, 672},   // y
    {5, 684},   // z
};

// Font information for Roboto 9pt
static const Font::FontInfo FontInfo = {11,   //  Character height
                                        ' ',  //  Start character
                                        'z',  //  End character
                                        2};

const Font pt9{FontInfo, Bitmaps, Descriptors};
}
}
