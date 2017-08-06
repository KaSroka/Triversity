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
namespace RobotoMono {

//
//  Font data for Roboto Mono 8pt
//

// Character bitmaps for Roboto Mono 8pt
static const uint8_t Bitmaps[] = {
    // @0 ' ' (6 pixels wide)
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    // @12 '0' (6 pixels wide)
    //
    //   ###
    //  #   #
    //  #   #
    //  # ###
    //  ##  #
    //  #   #
    //  #   #
    //   ###
    //
    //
    0x00, 0xFC, 0x22, 0x12, 0x12, 0xFC, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @24 '1' (6 pixels wide)
    //
    //    #
    //  ###
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //
    //
    0x00, 0x04, 0x04, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @36 '2' (6 pixels wide)
    //
    //  ####
    //  #  #
    // #   #
    //     #
    //    #
    //   #
    //  #
    //  #####
    //
    //
    0x08, 0x86, 0x42, 0x22, 0x1E, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @48 '3' (6 pixels wide)
    //
    //  ####
    //  #  #
    //     #
    //   ##
    //     #
    // #   #
    //  #  #
    //  ####
    //
    //
    0x40, 0x86, 0x12, 0x12, 0xEE, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @60 '4' (6 pixels wide)
    //
    //     #
    //    ##
    //   # #
    //   # #
    //  #  #
    // ######
    //     #
    //     #
    //
    //
    0x40, 0x60, 0x58, 0x44, 0xFE, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,

    // @72 '5' (6 pixels wide)
    //
    //   ####
    //  #
    //  #
    //  ####
    //      #
    //      #
    //  #   #
    //   ###
    //
    //
    0x00, 0x9C, 0x12, 0x12, 0x12, 0xE2, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @84 '6' (6 pixels wide)
    //
    //   ###
    //  ##
    //  #
    //  ####
    //  #  ##
    //  #   #
    //  #   #
    //   ###
    //
    //
    0x00, 0xFC, 0x16, 0x12, 0x32, 0xE0, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @96 '7' (6 pixels wide)
    //
    //  #####
    //     #
    //     #
    //     #
    //    #
    //    #
    //   #
    //   #
    //
    //
    0x00, 0x02, 0x82, 0x62, 0x1E, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,

    // @108 '8' (6 pixels wide)
    //
    //   ###
    //  #   #
    //  #   #
    //   ###
    //  #   #
    //  #   #
    //  #   #
    //   ###
    //
    //
    0x00, 0xEC, 0x12, 0x12, 0x12, 0xEC, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @120 '9' (6 pixels wide)
    //
    //   ###
    //  #  #
    //  #   #
    //  #  ##
    //   ## #
    //      #
    //     #
    //   ##
    //
    //
    0x00, 0x1C, 0x22, 0x22, 0x96, 0x78, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,

    // @132 'A' (6 pixels wide)
    //
    //    #
    //   ##
    //   # #
    //   # #
    //   # #
    //  #####
    //  #   #
    // ##   #
    //
    //
    0x00, 0xC0, 0x7C, 0x46, 0x78, 0xC0, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @144 'B' (6 pixels wide)
    //
    //  ####
    //  #   #
    //  #   #
    //  ####
    //  #   #
    //  #   #
    //  #   #
    //  ####
    //
    //
    0x00, 0xFE, 0x12, 0x12, 0x12, 0xEC, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @156 'C' (6 pixels wide)
    //
    //   ###
    //  #   #
    //  #
    //  #
    //  #
    //  #
    //  #   #
    //   ###
    //
    //
    0x00, 0xFC, 0x02, 0x02, 0x02, 0x84, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @168 'D' (6 pixels wide)
    //
    //  ####
    //  #  ##
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #  ##
    //  ####
    //
    //
    0x00, 0xFE, 0x02, 0x02, 0x86, 0xFC, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @180 'E' (6 pixels wide)
    //
    //  #####
    //  #
    //  #
    //  ####
    //  #
    //  #
    //  #
    //  #####
    //
    //
    0x00, 0xFE, 0x12, 0x12, 0x12, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @192 'F' (6 pixels wide)
    //
    //  #####
    //  #
    //  #
    //  #
    //  ####
    //  #
    //  #
    //  #
    //
    //
    0x00, 0xFE, 0x22, 0x22, 0x22, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,

    // @204 'G' (6 pixels wide)
    //
    //   ###
    //  #   #
    //  #
    //  #
    //  # ###
    //  #   #
    //  #   #
    //   ###
    //
    //
    0x00, 0xFC, 0x02, 0x22, 0x22, 0xE4, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @216 'H' (6 pixels wide)
    //
    //  #   #
    //  #   #
    //  #   #
    //  #####
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //
    //
    0x00, 0xFE, 0x10, 0x10, 0x10, 0xFE, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @228 'I' (6 pixels wide)
    //
    //  #####
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //  #####
    //
    //
    0x00, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @240 'J' (6 pixels wide)
    //
    //      #
    //      #
    //      #
    //      #
    //      #
    //      #
    //  #  #
    //  ####
    //
    //
    0x00, 0x80, 0x00, 0x00, 0x80, 0x7E, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @252 'K' (6 pixels wide)
    //
    //  #   #
    //  #  #
    //  # #
    //  ###
    //  ###
    //  #  #
    //  #  #
    //  #   #
    //
    //
    0x00, 0xFE, 0x30, 0x38, 0xC4, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @264 'L' (6 pixels wide)
    //
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #####
    //
    //
    0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @276 'M' (6 pixels wide)
    //
    //  #   #
    //  ## ##
    //  ## ##
    //  ### #
    //  # # #
    //  # # #
    //  #   #
    //  #   #
    //
    //
    0x00, 0xFE, 0x1C, 0x70, 0x0C, 0xFE, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @288 'N' (6 pixels wide)
    //
    //  #   #
    //  ##  #
    //  ##  #
    //  # # #
    //  # # #
    //  #  ##
    //  #  ##
    //  #   #
    //
    //
    0x00, 0xFE, 0x0C, 0x30, 0xC0, 0xFE, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @300 'O' (6 pixels wide)
    //
    //   ###
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //   ###
    //
    //
    0x00, 0xFC, 0x02, 0x02, 0x02, 0xFC, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @312 'P' (6 pixels wide)
    //
    //  ####
    //  #   #
    //  #   #
    //  #   #
    //  ####
    //  #
    //  #
    //  #
    //
    //
    0x00, 0xFE, 0x22, 0x22, 0x22, 0x1C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,

    // @324 'Q' (6 pixels wide)
    //
    //   ###
    //  #   #
    //  #   #
    //  #   #
    // ##   #
    //  #   #
    //  #   #
    //   ###
    //      #
    //
    0x20, 0xFC, 0x02, 0x02, 0x02, 0xFC, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02,

    // @336 'R' (6 pixels wide)
    //
    //  ####
    //  #   #
    //  #   #
    //  #   #
    //  ####
    //  #  #
    //  #  #
    //  #   #
    //
    //
    0x00, 0xFE, 0x22, 0x22, 0xE2, 0x1C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @348 'S' (6 pixels wide)
    //
    //   ###
    //  #   #
    //  #
    //  ###
    //    ##
    //      #
    //  #   #
    //   ###
    //
    //
    0x00, 0x9C, 0x12, 0x32, 0x22, 0xC4, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @360 'T' (6 pixels wide)
    //
    // ######
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //
    //
    0x02, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @372 'U' (6 pixels wide)
    //
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //   ###
    //
    //
    0x00, 0xFE, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @384 'V' (6 pixels wide)
    //
    // ##   #
    //  #   #
    //  #  #
    //  #  #
    //   # #
    //   ##
    //   ##
    //    #
    //
    //
    0x02, 0x1E, 0xE0, 0xC0, 0x38, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @396 'W' (6 pixels wide)
    //
    // #  # #
    //  # # #
    //  # # #
    //  ## ##
    //  ## ##
    //  ## ##
    //  ## ##
    //  #  #
    //
    //
    0x02, 0xFC, 0xF0, 0x0E, 0xF0, 0xFE, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,

    // @408 'X' (6 pixels wide)
    //
    //  #   #
    //  ## #
    //   # #
    //    #
    //    #
    //   # #
    //  #  #
    // ##   #
    //
    //
    0x00, 0x86, 0x4C, 0x30, 0xCC, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @420 'Y' (6 pixels wide)
    //
    // ##   #
    //  #  #
    //   # #
    //   ##
    //    #
    //    #
    //    #
    //    #
    //
    //
    0x02, 0x06, 0x18, 0xF0, 0x0C, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @432 'Z' (6 pixels wide)
    //
    //  #####
    //     #
    //    ##
    //    #
    //   #
    //   #
    //  #
    //  #####
    //
    //
    0x00, 0x82, 0x62, 0x1A, 0x0E, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @444 'a' (6 pixels wide)
    //
    //
    //
    //   ###
    //  #   #
    //   ####
    //  #   #
    //  #  ##
    //  ### #
    //
    //
    0x00, 0xD0, 0x28, 0x28, 0xA8, 0xF0, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01,

    // @456 'b' (6 pixels wide)
    //
    //  #
    //  #
    //  ####
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  ####
    //
    //
    0x00, 0xFE, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @468 'c' (6 pixels wide)
    //
    //
    //
    //   ###
    //  #   #
    //  #
    //  #
    //  #   #
    //   ###
    //
    //
    0x00, 0xF0, 0x08, 0x08, 0x08, 0x90, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @480 'd' (6 pixels wide)
    //
    //      #
    //      #
    //   ####
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //   ####
    //
    //
    0x00, 0xF0, 0x08, 0x08, 0x08, 0xFE, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @492 'e' (6 pixels wide)
    //
    //
    //
    //   ###
    //  #   #
    //  #####
    //  #
    //  #   #
    //   ###
    //
    //
    0x00, 0xF0, 0x28, 0x28, 0x28, 0xB0, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @504 'f' (6 pixels wide)
    //    ###
    //    #
    //   #
    //  #####
    //   #
    //   #
    //   #
    //   #
    //   #
    //
    //
    0x00, 0x08, 0xFC, 0x0B, 0x09, 0x09, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,

    // @516 'g' (6 pixels wide)
    //
    //
    //
    //   ####
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //   ####
    //      #
    //  ####
    0x00, 0xF0, 0x08, 0x08, 0x08, 0xF8, 0x00, 0x04, 0x05, 0x05, 0x05, 0x03,

    // @528 'h' (6 pixels wide)
    //
    //  #
    //  #
    //  ####
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //
    //
    0x00, 0xFE, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @540 'i' (6 pixels wide)
    //
    //    #
    //
    //  ###
    //    #
    //    #
    //    #
    //    #
    //  #####
    //
    //
    0x00, 0x08, 0x08, 0xFA, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @552 'j' (6 pixels wide)
    //
    //    ##
    //
    //   ###
    //     #
    //     #
    //     #
    //     #
    //     #
    //    #
    //  ###
    0x00, 0x00, 0x08, 0x0A, 0xFA, 0x00, 0x00, 0x04, 0x04, 0x06, 0x01, 0x00,

    // @564 'k' (6 pixels wide)
    //
    //  #
    //  #
    //  #  ##
    //  # #
    //  ##
    //  # #
    //  #  #
    //  #  ##
    //
    //
    0x00, 0xFE, 0x20, 0x50, 0x88, 0x08, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01,

    // @576 'l' (6 pixels wide)
    //
    //  ###
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //  #####
    //
    //
    0x00, 0x02, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @588 'm' (6 pixels wide)
    //
    //
    //
    // ######
    // #  # #
    // #  # #
    // #  # #
    // #  # #
    // #  # #
    //
    //
    0xF8, 0x08, 0x08, 0xF8, 0x08, 0xF8, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01,

    // @600 'n' (6 pixels wide)
    //
    //
    //
    //  ####
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //
    //
    0x00, 0xF8, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @612 'o' (6 pixels wide)
    //
    //
    //
    //   ###
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //   ###
    //
    //
    0x00, 0xF0, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @624 'p' (6 pixels wide)
    //
    //
    //
    //  ####
    //  #  ##
    //  #   #
    //  #   #
    //  #  ##
    //  ####
    //  #
    //  #
    0x00, 0xF8, 0x08, 0x08, 0x98, 0xF0, 0x00, 0x07, 0x01, 0x01, 0x01, 0x00,

    // @636 'q' (6 pixels wide)
    //
    //
    //
    //   ####
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //   ####
    //      #
    //      #
    0x00, 0xF0, 0x08, 0x08, 0x08, 0xF8, 0x00, 0x00, 0x01, 0x01, 0x01, 0x07,

    // @648 'r' (6 pixels wide)
    //
    //
    //
    //   ####
    //   #
    //   #
    //   #
    //   #
    //   #
    //
    //
    0x00, 0x00, 0xF8, 0x08, 0x08, 0x08, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,

    // @660 's' (6 pixels wide)
    //
    //
    //
    //   ###
    //  #   #
    //  ###
    //     ##
    //  #   #
    //   ###
    //
    //
    0x00, 0xB0, 0x28, 0x28, 0x48, 0xD0, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @672 't' (6 pixels wide)
    //
    //   #
    //   #
    //  #####
    //   #
    //   #
    //   #
    //   #
    //    ###
    //
    //
    0x00, 0x08, 0xFE, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,

    // @684 'u' (6 pixels wide)
    //
    //
    //
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //  #   #
    //   ####
    //
    //
    0x00, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @696 'v' (6 pixels wide)
    //
    //
    //
    //  #   #
    //  #  #
    //  #  #
    //   # #
    //   ##
    //    #
    //
    //
    0x00, 0x38, 0xC0, 0x80, 0x70, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @708 'w' (6 pixels wide)
    //
    //
    //
    // #  # #
    // #  # #
    //  ### #
    //  ## ##
    //  ## #
    //  #  #
    //
    //
    0x18, 0xE0, 0xE0, 0x38, 0xC0, 0x78, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,

    // @720 'x' (6 pixels wide)
    //
    //
    //
    //  #   #
    //   # #
    //   ##
    //   ##
    //   # #
    //  #   #
    //
    //
    0x00, 0x08, 0xF0, 0x60, 0x90, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @732 'y' (6 pixels wide)
    //
    //
    //
    // ##   #
    //  #  ##
    //   # #
    //   # #
    //   ##
    //    #
    //   #
    //  ##
    0x08, 0x18, 0xE0, 0x80, 0x70, 0x18, 0x00, 0x04, 0x06, 0x01, 0x00, 0x00,

    // @744 'z' (6 pixels wide)
    //
    //
    //
    //  #####
    //     #
    //    #
    //   #
    //  ##
    //  #####
    //
    //
    0x00, 0x88, 0xC8, 0x28, 0x18, 0x08, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
};

// Character descriptors for Roboto Mono 8pt
// { [Char width in bits], [Offset into robotoMono_8ptCharBitmaps in bytes] }
static const Font::FontDescriptor Descriptors[] = {
    {6, 0},    //
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
    {6, 12},   // 0
    {6, 24},   // 1
    {6, 36},   // 2
    {6, 48},   // 3
    {6, 60},   // 4
    {6, 72},   // 5
    {6, 84},   // 6
    {6, 96},   // 7
    {6, 108},  // 8
    {6, 120},  // 9
    {0, 0},    // :
    {0, 0},    // ;
    {0, 0},    // <
    {0, 0},    // =
    {0, 0},    // >
    {0, 0},    // ?
    {0, 0},    // @
    {6, 132},  // A
    {6, 144},  // B
    {6, 156},  // C
    {6, 168},  // D
    {6, 180},  // E
    {6, 192},  // F
    {6, 204},  // G
    {6, 216},  // H
    {6, 228},  // I
    {6, 240},  // J
    {6, 252},  // K
    {6, 264},  // L
    {6, 276},  // M
    {6, 288},  // N
    {6, 300},  // O
    {6, 312},  // P
    {6, 324},  // Q
    {6, 336},  // R
    {6, 348},  // S
    {6, 360},  // T
    {6, 372},  // U
    {6, 384},  // V
    {6, 396},  // W
    {6, 408},  // X
    {6, 420},  // Y
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
    {6, 552},  // j
    {6, 564},  // k
    {6, 576},  // l
    {6, 588},  // m
    {6, 600},  // n
    {6, 612},  // o
    {6, 624},  // p
    {6, 636},  // q
    {6, 648},  // r
    {6, 660},  // s
    {6, 672},  // t
    {6, 684},  // u
    {6, 696},  // v
    {6, 708},  // w
    {6, 720},  // x
    {6, 732},  // y
    {6, 744},  // z
};

// Font information for Roboto Mono 8pt
static const Font::FontInfo FontInfo = {
    11,   //  Character height
    ' ',  //  Start character
    'z',  //  End character
    1,
};

const Font pt8{FontInfo, Bitmaps, Descriptors};
}
}
