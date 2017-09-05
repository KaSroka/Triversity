/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 05-09-2017
 * last modification: 05-09-2017
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
namespace RobotoMono {
//
//  Font data for Roboto Mono 10pt
//

// Character bitmaps for Roboto Mono 10pt
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
    //
    //
    0x00, 0x00, 0x00, 0x00,

    // @4 '0' (6 pixels wide)
    //
    //  ####
    // ##  ##
    // #    #
    // #   ##
    // # ## #
    // ##   #
    // #    #
    // ##  ##
    //  ####
    //
    //
    //
    0xFC, 0x46, 0x22, 0x22, 0x16, 0xFC, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01,

    // @16 '1' (4 pixels wide)
    //
    //   ##
    // ## #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //
    //
    //
    0x04, 0x04, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x03,

    // @24 '2' (6 pixels wide)
    //
    //  ###
    // #   #
    // #   #
    //     #
    //    #
    //   ##
    //  ##
    // ##
    // ######
    //
    //
    //
    0x0C, 0x82, 0xC2, 0x62, 0x1C, 0x00, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02,

    // @36 '3' (5 pixels wide)
    //
    //  ###
    // #   #
    //     #
    //     #
    //  ###
    //     #
    //     #
    // #   #
    //  ###
    //
    //
    //
    0x04, 0x22, 0x22, 0x22, 0xDC, 0x01, 0x02, 0x02, 0x02, 0x01,

    // @46 '4' (7 pixels wide)
    //
    //     ##
    //     ##
    //    # #
    //   #  #
    //   #  #
    //  #   #
    // #######
    //      #
    //      #
    //
    //
    //
    0x80, 0xC0, 0xB0, 0x88, 0x86, 0xFE, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,

    // @60 '5' (6 pixels wide)
    //
    //  #####
    //  #
    //  #
    //  ####
    //  #  ##
    //      #
    // #    #
    // ##  ##
    //  ####
    //
    //
    //
    0x80, 0x3E, 0x12, 0x12, 0x32, 0xE2, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01,

    // @72 '6' (6 pixels wide)
    //
    //   ##
    //  #
    // #
    // # ###
    // ##  #
    // #    #
    // #    #
    // ##  #
    //  ####
    //
    //
    //
    0xF8, 0x24, 0x12, 0x12, 0x30, 0xC0, 0x01, 0x03, 0x02, 0x02, 0x03, 0x00,

    // @84 '7' (6 pixels wide)
    //
    // ######
    //     ##
    //     #
    //     #
    //    #
    //    #
    //   #
    //   #
    //  #
    //
    //
    //
    0x02, 0x02, 0x82, 0x62, 0x1E, 0x06, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00,

    // @96 '8' (6 pixels wide)
    //
    //  ####
    //  #  ##
    // ##   #
    //  #  ##
    //   ##
    // ##  ##
    // #    #
    // ##  ##
    //  ####
    //
    //
    //
    0xC8, 0x5E, 0x22, 0x22, 0x56, 0xDC, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01,

    // @108 '9' (6 pixels wide)
    //
    //  ###
    // ##  #
    // #   ##
    // #    #
    // ##  ##
    //  ### #
    //     #
    //     #
    //  ###
    //
    //
    //
    0x3C, 0x66, 0x42, 0x42, 0xAC, 0x78, 0x00, 0x02, 0x02, 0x02, 0x01, 0x00,

    // @120 'A' (6 pixels wide)
    //
    //   ##
    //   ##
    //   ##
    //  #  #
    //  #  #
    //  ####
    // #    #
    // #    #
    // #    #
    //
    //
    //
    0x80, 0x70, 0x4E, 0x4E, 0x70, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03,

    // @132 'B' (6 pixels wide)
    //
    // #####
    // #   ##
    // #    #
    // #   ##
    // #####
    // #    #
    // #    #
    // #    #
    // #####
    //
    //
    //
    0xFE, 0x22, 0x22, 0x22, 0x36, 0xDC, 0x03, 0x02, 0x02, 0x02, 0x02, 0x01,

    // @144 'C' (6 pixels wide)
    //
    //  ####
    // ##  ##
    // #    #
    // #
    // #
    // #
    // #    #
    // ##  ##
    //  ####
    //
    //
    //
    0xFC, 0x06, 0x02, 0x02, 0x06, 0x8C, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01,

    // @156 'D' (6 pixels wide)
    //
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
    //
    0xFE, 0x02, 0x02, 0x02, 0x04, 0xF8, 0x03, 0x02, 0x02, 0x02, 0x01, 0x00,

    // @168 'E' (6 pixels wide)
    //
    // ######
    // #
    // #
    // #
    // #####
    // #
    // #
    // #
    // ######
    //
    //
    //
    0xFE, 0x22, 0x22, 0x22, 0x22, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,

    // @180 'F' (6 pixels wide)
    //
    // ######
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
    //
    0xFE, 0x22, 0x22, 0x22, 0x22, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,

    // @192 'G' (6 pixels wide)
    //
    //  ####
    // ##  ##
    // #
    // #
    // #  ###
    // #    #
    // #    #
    // ##   #
    //  ####
    //
    //
    //
    0xFC, 0x06, 0x02, 0x22, 0x26, 0xE4, 0x01, 0x03, 0x02, 0x02, 0x02, 0x01,

    // @204 'H' (6 pixels wide)
    //
    // #    #
    // #    #
    // #    #
    // #    #
    // ######
    // #    #
    // #    #
    // #    #
    // #    #
    //
    //
    //
    0xFE, 0x20, 0x20, 0x20, 0x20, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03,

    // @216 'I' (6 pixels wide)
    //
    // ######
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    // ######
    //
    //
    //
    0x02, 0x02, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02,

    // @228 'J' (6 pixels wide)
    //
    //     ##
    //     ##
    //     ##
    //     ##
    //     ##
    //     ##
    // #   ##
    // #   #
    //  ###
    //
    //
    //
    0x80, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x01, 0x02, 0x02, 0x02, 0x01, 0x00,

    // @240 'K' (7 pixels wide)
    //
    // #   ##
    // #   #
    // #  #
    // # #
    // ###
    // ## #
    // #  ##
    // #   ##
    // #    ##
    //
    //
    //
    0xFE, 0x60, 0x30, 0xC8, 0x86, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02,

    // @254 'L' (6 pixels wide)
    //
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // ######
    //
    //
    //
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,

    // @266 'M' (6 pixels wide)
    //
    // ##  ##
    // ##  ##
    // ##  ##
    // # ## #
    // # ## #
    // # ## #
    // #    #
    // #    #
    // #    #
    //
    //
    //
    0xFE, 0x0E, 0x70, 0x70, 0x0E, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03,

    // @278 'N' (6 pixels wide)
    //
    // #    #
    // ##   #
    // ##   #
    // # #  #
    // # #  #
    // #  # #
    // #  ###
    // #   ##
    // #   ##
    //
    //
    //
    0xFE, 0x0C, 0x30, 0xC0, 0x80, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03,

    // @290 'O' (6 pixels wide)
    //
    //  ####
    // ##  #
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    // ##  ##
    //  ####
    //
    //
    //
    0xFC, 0x06, 0x02, 0x02, 0x06, 0xF8, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01,

    // @302 'P' (6 pixels wide)
    //
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
    //
    0xFE, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,

    // @314 'Q' (6 pixels wide)
    //
    //  ####
    // ##  ##
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    // ##  ##
    //  ####
    //     ##
    //
    //
    0xFC, 0x06, 0x02, 0x02, 0x06, 0xFC, 0x01, 0x03, 0x02, 0x02, 0x07, 0x05,

    // @326 'R' (6 pixels wide)
    //
    // #####
    // #   ##
    // #    #
    // #   ##
    // #####
    // #  ##
    // #   #
    // #   ##
    // #    #
    //
    //
    //
    0xFE, 0x22, 0x22, 0x62, 0xF6, 0x1C, 0x03, 0x00, 0x00, 0x00, 0x01, 0x03,

    // @338 'S' (6 pixels wide)
    //
    //  ####
    // ##  ##
    // #    #
    // ##
    //   ###
    //     ##
    // #    #
    // ##   #
    //  ####
    //
    //
    //
    0x9C, 0x16, 0x22, 0x22, 0x66, 0xCC, 0x01, 0x03, 0x02, 0x02, 0x02, 0x01,

    // @350 'T' (7 pixels wide)
    //
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
    //
    0x02, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,

    // @364 'U' (6 pixels wide)
    //
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
    //
    0xFE, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01,

    // @376 'V' (7 pixels wide)
    //
    // ##    #
    //  #    #
    //  #   ##
    //   #  #
    //   #  #
    //   # ##
    //    ##
    //    ##
    //    ##
    //
    //
    //
    0x02, 0x0E, 0x70, 0x80, 0xC0, 0x78, 0x0E, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00,

    // @390 'W' (8 pixels wide)
    //
    // ## ## ##
    //  # ## #
    //  # ## #
    //  # ## #
    //  # ## #
    //  ##  ##
    //  ##  ##
    //  ##  ##
    //   #  #
    //
    //
    //
    0x02, 0xFE, 0xC0, 0x3E, 0x3E, 0xC0, 0xFE, 0x02, 0x00, 0x01, 0x03, 0x00, 0x00, 0x03, 0x01, 0x00,

    // @406 'X' (6 pixels wide)
    //
    // #    #
    //  #  #
    //  #  #
    //   ##
    //   ##
    //   ##
    //  #  #
    // ##  #
    // #    #
    //
    //
    //
    0x02, 0x8C, 0x70, 0x70, 0x8C, 0x02, 0x03, 0x01, 0x00, 0x00, 0x01, 0x02,

    // @418 'Y' (7 pixels wide)
    //
    // ##    #
    //  #   ##
    //   #  #
    //   # #
    //    ##
    //    #
    //    #
    //    #
    //    #
    //
    //
    //
    0x02, 0x06, 0x18, 0xE0, 0x30, 0x0C, 0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,

    // @432 'Z' (6 pixels wide)
    //
    // ######
    //     #
    //    ##
    //    #
    //   #
    //  ##
    //  #
    // #
    // ######
    //
    //
    //
    0x02, 0xC2, 0x62, 0x1A, 0x0E, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,

    // @444 'a' (6 pixels wide)
    //
    //
    //
    //  ####
    // ##  #
    //     ##
    //  #####
    // #   ##
    // #   ##
    //  #####
    //
    //
    //
    0x90, 0x58, 0x48, 0x48, 0xF8, 0xE0, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03,

    // @456 'b' (6 pixels wide)
    // #
    // #
    // #
    // # ###
    // ##  ##
    // #    #
    // #    #
    // #    #
    // ##  ##
    // # ###
    //
    //
    //
    0xFF, 0x10, 0x08, 0x08, 0x18, 0xF0, 0x03, 0x01, 0x02, 0x02, 0x03, 0x01,

    // @468 'c' (6 pixels wide)
    //
    //
    //
    //  ####
    // ##  ##
    // #
    // #
    // #
    // ##  ##
    //  ####
    //
    //
    //
    0xF0, 0x18, 0x08, 0x08, 0x18, 0x10, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01,

    // @480 'd' (6 pixels wide)
    //     ##
    //     ##
    //     ##
    //  #####
    // ##  ##
    // #   ##
    // #   ##
    // #   ##
    // ##  ##
    //  ### #
    //
    //
    //
    0xF0, 0x18, 0x08, 0x08, 0xFF, 0xFF, 0x01, 0x03, 0x02, 0x02, 0x01, 0x03,

    // @492 'e' (6 pixels wide)
    //
    //
    //
    //  ####
    // ##  ##
    // #    #
    // ######
    // #
    // ##   #
    //  ####
    //
    //
    //
    0xF0, 0x58, 0x48, 0x48, 0x58, 0x70, 0x01, 0x03, 0x02, 0x02, 0x02, 0x01,

    // @504 'f' (6 pixels wide)
    //    ###
    //   #
    //   #
    // ######
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //
    //
    //
    0x08, 0x08, 0xFE, 0x09, 0x09, 0x09, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,

    // @516 'g' (6 pixels wide)
    //
    //
    //
    //  ### #
    // ##  ##
    // #    #
    // #    #
    // #    #
    // ##  ##
    //  ### #
    //     ##
    // #   #
    //  ####
    0xF0, 0x18, 0x08, 0x08, 0x10, 0xF8, 0x09, 0x13, 0x12, 0x12, 0x1D, 0x07,

    // @528 'h' (6 pixels wide)
    // #
    // #
    // #
    // # ###
    // ##  ##
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    //
    //
    //
    0xFF, 0x10, 0x08, 0x08, 0x18, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03,

    // @540 'i' (6 pixels wide)
    //
    //   ##
    //
    // ####
    //    #
    //    #
    //    #
    //    #
    //    #
    // ######
    //
    //
    //
    0x08, 0x08, 0x0A, 0xFA, 0x00, 0x00, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02,

    // @552 'j' (4 pixels wide)
    //
    //    #
    //
    //  ###
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    // ###
    0x00, 0x08, 0x08, 0xFA, 0x10, 0x10, 0x10, 0x0F,

    // @560 'k' (6 pixels wide)
    // #
    // #
    // #
    // #   ##
    // #  #
    // # #
    // ###
    // #  #
    // #   #
    // #   ##
    //
    //
    //
    0xFF, 0x40, 0x60, 0x90, 0x08, 0x08, 0x03, 0x00, 0x00, 0x00, 0x03, 0x02,

    // @572 'l' (6 pixels wide)
    // ####
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    // ######
    //
    //
    //
    0x01, 0x01, 0x01, 0xFF, 0x00, 0x00, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02,

    // @584 'm' (6 pixels wide)
    //
    //
    //
    // ######
    // # ## #
    // # #  #
    // # #  #
    // # #  #
    // # #  #
    // # #  #
    //
    //
    //
    0xF8, 0x08, 0xF8, 0x18, 0x08, 0xF8, 0x03, 0x00, 0x03, 0x00, 0x00, 0x03,

    // @596 'n' (6 pixels wide)
    //
    //
    //
    // # ###
    // ##  ##
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    //
    //
    //
    0xF8, 0x10, 0x08, 0x08, 0x18, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03,

    // @608 'o' (6 pixels wide)
    //
    //
    //
    //  ####
    // ##  ##
    // #    #
    // #    #
    // #    #
    // ##  ##
    //  ####
    //
    //
    //
    0xF0, 0x18, 0x08, 0x08, 0x18, 0xF0, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01,

    // @620 'p' (6 pixels wide)
    //
    //
    //
    // # ###
    // ##  ##
    // #    #
    // #    #
    // #    #
    // ##  ##
    // # ###
    // #
    // #
    // #
    0xF8, 0x10, 0x08, 0x08, 0x18, 0xF0, 0x1F, 0x01, 0x02, 0x02, 0x03, 0x01,

    // @632 'q' (6 pixels wide)
    //
    //
    //
    //  ### #
    // ##  ##
    // #   ##
    // #   ##
    // #   ##
    // ##  ##
    //  #####
    //     ##
    //     ##
    //     ##
    0xF0, 0x18, 0x08, 0x08, 0xF0, 0xF8, 0x01, 0x03, 0x02, 0x02, 0x1F, 0x1F,

    // @644 'r' (5 pixels wide)
    //
    //
    //
    // # ###
    // ##
    // #
    // #
    // #
    // #
    // #
    //
    //
    //
    0xF8, 0x10, 0x08, 0x08, 0x08, 0x03, 0x00, 0x00, 0x00, 0x00,

    // @654 's' (6 pixels wide)
    //
    //
    //
    //  ####
    // ##  ##
    // ##
    //   ###
    //     ##
    // ##   #
    //  ####
    //
    //
    //
    0x30, 0x38, 0x48, 0x48, 0xD8, 0x90, 0x01, 0x03, 0x02, 0x02, 0x02, 0x01,

    // @666 't' (6 pixels wide)
    //
    //   #
    //   #
    // ######
    //   #
    //   #
    //   #
    //   #
    //   #
    //   ####
    //
    //
    //
    0x08, 0x08, 0xFE, 0x08, 0x08, 0x08, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02,

    // @678 'u' (6 pixels wide)
    //
    //
    //
    // #    #
    // #    #
    // #    #
    // #    #
    // #    #
    // ##  ##
    //  ### #
    //
    //
    //
    0xF8, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x03, 0x02, 0x02, 0x01, 0x03,

    // @690 'v' (6 pixels wide)
    //
    //
    //
    // #    #
    // #   ##
    //  #  #
    //  #  #
    //  ###
    //   ##
    //   ##
    //
    //
    //
    0x18, 0xE0, 0x80, 0x80, 0x70, 0x18, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00,

    // @702 'w' (8 pixels wide)
    //
    //
    //
    // #  #  ##
    //  # ## #
    //  # ## #
    //  # ## #
    //  ## # #
    //  ##  #
    //   #  #
    //
    //
    //
    0x08, 0xF0, 0x80, 0x78, 0xF0, 0x00, 0xF8, 0x08, 0x00, 0x01, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00,

    // @718 'x' (6 pixels wide)
    //
    //
    //
    // #   ##
    //  #  #
    //   ##
    //   ##
    //   ##
    //  #  #
    // #    #
    //
    //
    //
    0x08, 0x10, 0xE0, 0xE0, 0x18, 0x08, 0x02, 0x01, 0x00, 0x00, 0x01, 0x02,

    // @730 'y' (7 pixels wide)
    //
    //
    //
    // ##    #
    //  #   ##
    //   #  #
    //   #  #
    //   ###
    //    ##
    //    ##
    //    #
    //   ##
    //  ##
    0x08, 0x18, 0xE0, 0x80, 0x80, 0x70, 0x18, 0x00, 0x10, 0x18, 0x0F, 0x03, 0x00, 0x00,

    // @744 'z' (6 pixels wide)
    //
    //
    //
    // ######
    //     #
    //    #
    //   ##
    //  ##
    //  #
    // ######
    //
    //
    //
    0x08, 0x88, 0xC8, 0x68, 0x18, 0x08, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02,
};

// Character descriptors for Roboto Mono 10pt
// { [Char width in bits], [Offset into robotoMono_10ptCharBitmaps in bytes] }
static const Font::FontDescriptor Descriptors[] = {
    {2, 0},    //
    {0, 0},    // !
    {0, 0},    // "
    {0, 0},    // #
    {0, 0},    // $
    {0, 0},    // %
    {0, 0},    // &
    {0, 0},    // '
    {0, 0},    // (
    {0, 0},    // )
    {0, 0},    // *
    {0, 0},    // +
    {0, 0},    // ,
    {0, 0},    // -
    {0, 0},    // .
    {0, 0},    // /
    {6, 4},    // 0
    {4, 16},   // 1
    {6, 24},   // 2
    {5, 36},   // 3
    {7, 46},   // 4
    {6, 60},   // 5
    {6, 72},   // 6
    {6, 84},   // 7
    {6, 96},   // 8
    {6, 108},  // 9
    {0, 0},    // :
    {0, 0},    // ;
    {0, 0},    // <
    {0, 0},    // =
    {0, 0},    // >
    {0, 0},    // ?
    {0, 0},    // @
    {6, 120},  // A
    {6, 132},  // B
    {6, 144},  // C
    {6, 156},  // D
    {6, 168},  // E
    {6, 180},  // F
    {6, 192},  // G
    {6, 204},  // H
    {6, 216},  // I
    {6, 228},  // J
    {7, 240},  // K
    {6, 254},  // L
    {6, 266},  // M
    {6, 278},  // N
    {6, 290},  // O
    {6, 302},  // P
    {6, 314},  // Q
    {6, 326},  // R
    {6, 338},  // S
    {7, 350},  // T
    {6, 364},  // U
    {7, 376},  // V
    {8, 390},  // W
    {6, 406},  // X
    {7, 418},  // Y
    {6, 432},  // Z
    {0, 0},    // [
    {0, 0},    // \ /
    {0, 0},    // ]
    {0, 0},    // ^
    {0, 0},    // _
    {0, 0},    // `
    {6, 444},  // a
    {6, 456},  // b
    {6, 468},  // c
    {6, 480},  // d
    {6, 492},  // e
    {6, 504},  // f
    {6, 516},  // g
    {6, 528},  // h
    {6, 540},  // i
    {4, 552},  // j
    {6, 560},  // k
    {6, 572},  // l
    {6, 584},  // m
    {6, 596},  // n
    {6, 608},  // o
    {6, 620},  // p
    {6, 632},  // q
    {5, 644},  // r
    {6, 654},  // s
    {6, 666},  // t
    {6, 678},  // u
    {6, 690},  // v
    {8, 702},  // w
    {6, 718},  // x
    {7, 730},  // y
    {6, 744},  // z
};

// Font information for Roboto Mono 10pt
static const Font::FontInfo FontInfo = {
    13,   //  Character height
    ' ',  //  Start character
    'z',  //  End character
    1     //  Interchar space
};

const Font pt10{FontInfo, Bitmaps, Descriptors};
}
}
