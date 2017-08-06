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
//  Font data for Roboto 8pt
//

// Character bitmaps for Roboto 8pt
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
    //
    //  ###
    // #  #
    // #   #
    // #   #
    // #   #
    // #  #
    // #  #
    //  ###
    //
    //
    0xFC, 0x02, 0x02, 0xC6, 0x38, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @14 '1' (3 pixels wide)
    //
    //  ##
    // # #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //
    //
    0x04, 0x02, 0xFE, 0x00, 0x00, 0x01,

    // @20 '2' (6 pixels wide)
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

    // @32 '3' (5 pixels wide)
    //
    //  ####
    //  #  #
    //     #
    //   ##
    //     #
    //     #
    // ##  #
    //  ####
    //
    //
    0x80, 0x86, 0x12, 0x12, 0xEE, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @42 '4' (6 pixels wide)
    //
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
    0x40, 0x70, 0x48, 0x46, 0xFE, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,

    // @54 '5' (5 pixels wide)
    //
    // #####
    // #
    // #
    // ####
    //    ##
    //     #
    // #  ##
    //  ###
    //
    //
    0x9E, 0x12, 0x12, 0xB2, 0xE2, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @64 '6' (5 pixels wide)
    //
    //  ###
    // ##
    // #
    // ####
    // #  ##
    // #   #
    // #  #
    //  ###
    //
    //
    0xFC, 0x16, 0x12, 0xB2, 0x60, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @74 '7' (6 pixels wide)
    //
    // ######
    //     #
    //     #
    //    #
    //    #
    //    #
    //   #
    //  ##
    //
    //
    0x02, 0x02, 0x82, 0x72, 0x0E, 0x02, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00,

    // @86 '8' (5 pixels wide)
    //
    // ####
    // #  #
    // #  #
    //  ##
    // #  #
    // #   #
    // #  #
    // ####
    //
    //
    0xEE, 0x12, 0x12, 0xAE, 0x40, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @96 '9' (4 pixels wide)
    //
    // ###
    // #  #
    // #  #
    // #  #
    // ####
    //    #
    //    #
    //  ##
    //
    //
    0x3E, 0x22, 0x22, 0xFC, 0x00, 0x01, 0x01, 0x00,

    // @104 'A' (7 pixels wide)
    //
    //    #
    //   # #
    //   # #
    //   # #
    //  #   #
    //  #####
    //  #   #
    // #     #
    //
    //
    0x00, 0xE0, 0x5C, 0x42, 0x5C, 0xE0, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,

    // @118 'B' (5 pixels wide)
    //
    // ####
    // #   #
    // #   #
    // ####
    // #   #
    // #   #
    // #   #
    // ####
    //
    //
    0xFE, 0x12, 0x12, 0x12, 0xEC, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @128 'C' (6 pixels wide)
    //
    //  ####
    // #   #
    // #    #
    // #
    // #
    // #    #
    // #   #
    //  ####
    //
    //
    0xFC, 0x02, 0x02, 0x02, 0x86, 0x48, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @140 'D' (6 pixels wide)
    //
    // ####
    // #   #
    // #   #
    // #    #
    // #    #
    // #   #
    // #   #
    // ####
    //
    //
    0xFE, 0x02, 0x02, 0x02, 0xCC, 0x30, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,

    // @152 'E' (5 pixels wide)
    //
    // #####
    // #
    // #
    // ####
    // #
    // #
    // #
    // #####
    //
    //
    0xFE, 0x12, 0x12, 0x12, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @162 'F' (5 pixels wide)
    //
    // #####
    // #
    // #
    // #
    // ####
    // #
    // #
    // #
    //
    //
    0xFE, 0x22, 0x22, 0x22, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,

    // @172 'G' (6 pixels wide)
    //
    //  ####
    // #   #
    // #    #
    // #
    // #  ###
    // #    #
    // ##   #
    //  ####
    //
    //
    0xFC, 0x82, 0x02, 0x22, 0x26, 0xE8, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @184 'H' (6 pixels wide)
    //
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
    0xFE, 0x10, 0x10, 0x10, 0x10, 0xFE, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,

    // @196 'I' (1 pixels wide)
    //
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
    0xFE, 0x01,

    // @198 'J' (5 pixels wide)
    //
    //     #
    //     #
    //     #
    //     #
    //     #
    //     #
    // ##  #
    //  ###
    //
    //
    0x80, 0x80, 0x00, 0x00, 0xFE, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @208 'K' (6 pixels wide)
    //
    // #   ##
    // #  #
    // # #
    // ###
    // ###
    // #  #
    // #   #
    // #   ##
    //
    //
    0xFE, 0x30, 0x38, 0x44, 0x82, 0x02, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01,

    // @220 'L' (5 pixels wide)
    //
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
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @230 'M' (8 pixels wide)
    //
    // #     ##
    // ##    ##
    // ##   # #
    // # #  # #
    // # #  # #
    // # # #  #
    // #  ##  #
    // #  #   #
    //
    //
    0xFE, 0x0C, 0x70, 0x80, 0xC0, 0x38, 0x06, 0xFE, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @246 'N' (6 pixels wide)
    //
    // #    #
    // ##   #
    // ###  #
    // # #  #
    // #  # #
    // #  ###
    // #   ##
    // #    #
    //
    //
    0xFE, 0x0C, 0x18, 0x60, 0xC0, 0xFE, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,

    // @258 'O' (6 pixels wide)
    //
    //  ####
    // #   #
    // #    #
    // #    #
    // #    #
    // #    #
    // #   #
    //  ####
    //
    //
    0xFC, 0x02, 0x02, 0x02, 0x86, 0x78, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @270 'P' (6 pixels wide)
    //
    // #####
    // #   #
    // #    #
    // #   #
    // #####
    // #
    // #
    // #
    //
    //
    0xFE, 0x22, 0x22, 0x22, 0x36, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,

    // @282 'Q' (6 pixels wide)
    //
    //  ####
    // ##  ##
    // #    #
    // #    #
    // #    #
    // #    #
    // ##  ##
    //  ####
    //      #
    //
    0xFC, 0x86, 0x02, 0x02, 0x86, 0xFC, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02,

    // @294 'R' (6 pixels wide)
    //
    // ####
    // #   #
    // #   #
    // #   #
    // ####
    // #  #
    // #   #
    // #   ##
    //
    //
    0xFE, 0x22, 0x22, 0x62, 0x9C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01,

    // @306 'S' (5 pixels wide)
    //
    //  ###
    // #   #
    // #
    //  ##
    //    ##
    //     #
    // #   #
    //  ###
    //
    //
    0x8C, 0x12, 0x12, 0x22, 0xE4, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @316 'T' (6 pixels wide)
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

    // @328 'U' (5 pixels wide)
    //
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //  ###
    //
    //
    0xFE, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @338 'V' (7 pixels wide)
    //
    // #     #
    //  #   #
    //  #   #
    //  #   #
    //   # #
    //   # #
    //   ##
    //    #
    //
    //
    0x02, 0x1C, 0xE0, 0x80, 0x60, 0x1C, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,

    // @352 'W' (10 pixels wide)
    //
    // #   ##  ##
    //  #  ##  #
    //  #  ##  #
    //  # # #  #
    //  # #  ##
    //   ##  ##
    //   ##  ##
    //   #    #
    //
    //
    0x02, 0x3C, 0xC0, 0xF0, 0x0E, 0x1E, 0xE0, 0xE0, 0x1E, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @372 'X' (7 pixels wide)
    //
    // ##   ##
    //  #  ##
    //   # #
    //    #
    //    #
    //   # #
    //  #  ##
    // ##   ##
    //
    //
    0x02, 0x86, 0x48, 0x30, 0xCC, 0x86, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01,

    // @386 'Y' (7 pixels wide)
    //
    // ##   ##
    //  #   #
    //  ## #
    //   # #
    //    #
    //    #
    //    #
    //    #
    //
    //
    0x02, 0x0E, 0x18, 0xE0, 0x18, 0x06, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,

    // @400 'Z' (6 pixels wide)
    //
    //  #####
    //     ##
    //     #
    //    #
    //   #
    //   #
    //  #
    // ######
    //
    //
    0x00, 0x82, 0x62, 0x12, 0x0E, 0x06, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,

    // @412 'a' (4 pixels wide)
    //
    //
    //
    // ####
    //    #
    // ####
    // #  #
    // #  #
    // ####
    //
    //
    0xE8, 0x28, 0x28, 0xF8, 0x01, 0x01, 0x01, 0x01,

    // @420 'b' (5 pixels wide)
    //
    // #
    // #
    // ####
    // #  #
    // #   #
    // #   #
    // #  #
    // ####
    //
    //
    0xFE, 0x08, 0x08, 0x98, 0x60, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @430 'c' (5 pixels wide)
    //
    //
    //
    //  ###
    // #  #
    // #   #
    // #
    // #  ##
    //  ###
    //
    //
    0xF0, 0x08, 0x08, 0x98, 0xA0, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @440 'd' (5 pixels wide)
    //
    //     #
    //     #
    //  ####
    //  #  #
    // #   #
    // #   #
    //  #  #
    //  ####
    //
    //
    0x60, 0x98, 0x08, 0x08, 0xFE, 0x00, 0x01, 0x01, 0x01, 0x01,

    // @450 'e' (5 pixels wide)
    //
    //
    //
    //  ###
    // #  #
    // #####
    // #
    // #  #
    //  ###
    //
    //
    0xF0, 0x28, 0x28, 0xB8, 0x20, 0x00, 0x01, 0x01, 0x01, 0x00,

    // @460 'f' (4 pixels wide)
    //   ##
    //  #
    //  #
    // ####
    //  #
    //  #
    //  #
    //  #
    //  #
    //
    //
    0x08, 0xFE, 0x09, 0x09, 0x00, 0x01, 0x00, 0x00,

    // @468 'g' (5 pixels wide)
    //
    //
    //
    //  ####
    //  #  #
    // #   #
    // #   #
    //  #  #
    //  ####
    //     #
    //  ####
    0x60, 0x98, 0x08, 0x08, 0xF8, 0x00, 0x05, 0x05, 0x05, 0x07,

    // @478 'h' (4 pixels wide)
    //
    // #
    // #
    // ####
    // #  #
    // #  #
    // #  #
    // #  #
    // #  #
    //
    //
    0xFE, 0x08, 0x08, 0xF8, 0x01, 0x00, 0x00, 0x01,

    // @486 'i' (1 pixels wide)
    //
    // #
    //
    // #
    // #
    // #
    // #
    // #
    // #
    //
    //
    0xFA, 0x01,

    // @488 'j' (2 pixels wide)
    //
    //  #
    //
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    // ##
    0x00, 0xFA, 0x04, 0x07,

    // @492 'k' (5 pixels wide)
    // #
    // #
    // #
    // #  #
    // # #
    // ##
    // # #
    // # #
    // #  ##
    //
    //
    0xFF, 0x20, 0xD0, 0x08, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01,

    // @502 'l' (1 pixels wide)
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

    // @504 'm' (8 pixels wide)
    //
    //
    //
    // #### ###
    // #  ##  #
    // #  #   #
    // #  #   #
    // #  #   #
    // #  #   #
    //
    //
    0xF8, 0x08, 0x08, 0xF8, 0x10, 0x08, 0x08, 0xF8, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,

    // @520 'n' (4 pixels wide)
    //
    //
    //
    // ####
    // #  #
    // #  #
    // #  #
    // #  #
    // #  #
    //
    //
    0xF8, 0x08, 0x08, 0xF8, 0x01, 0x00, 0x00, 0x01,

    // @528 'o' (6 pixels wide)
    //
    //
    //
    //  ####
    //  #  #
    // #    #
    // #    #
    //  #  #
    //  ####
    //
    //
    0x60, 0x98, 0x08, 0x08, 0x98, 0x60, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,

    // @540 'p' (5 pixels wide)
    //
    //
    //
    // ####
    // #  #
    // #   #
    // #   #
    // #  #
    // ####
    // #
    // #
    0xF8, 0x08, 0x08, 0x98, 0x60, 0x07, 0x01, 0x01, 0x01, 0x00,

    // @550 'q' (5 pixels wide)
    //
    //
    //
    //  ####
    //  #  #
    // #   #
    // #   #
    //  #  #
    //  ####
    //     #
    //     #
    0x60, 0x98, 0x08, 0x08, 0xF8, 0x00, 0x01, 0x01, 0x01, 0x07,

    // @560 'r' (3 pixels wide)
    //
    //
    //
    // ###
    // #
    // #
    // #
    // #
    // #
    //
    //
    0xF8, 0x08, 0x08, 0x01, 0x00, 0x00,

    // @566 's' (4 pixels wide)
    //
    //
    //
    // ####
    // #  #
    // ###
    //    #
    // #  #
    // ####
    //
    //
    0xB8, 0x28, 0x28, 0xD8, 0x01, 0x01, 0x01, 0x01,

    // @574 't' (3 pixels wide)
    //
    //
    //  #
    // ###
    //  #
    //  #
    //  #
    //  #
    //   #
    //
    //
    0x08, 0xFC, 0x08, 0x00, 0x00, 0x01,

    // @580 'u' (4 pixels wide)
    //
    //
    //
    // #  #
    // #  #
    // #  #
    // #  #
    // #  #
    // ####
    //
    //
    0xF8, 0x00, 0x00, 0xF8, 0x01, 0x01, 0x01, 0x01,

    // @588 'v' (5 pixels wide)
    //
    //
    //
    // #   #
    // #  #
    //  # #
    //  # #
    //  ##
    //   #
    //
    //
    0x18, 0xE0, 0x80, 0x70, 0x08, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @598 'w' (8 pixels wide)
    //
    //
    //
    // #  ##  #
    // #  ## #
    //  # ## #
    //  ## # #
    //  ##  ##
    //   #  #
    //
    //
    0x18, 0xE0, 0xC0, 0x38, 0x78, 0x80, 0xF0, 0x08, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,

    // @614 'x' (5 pixels wide)
    //
    //
    //
    // ##  #
    //  # #
    //   ##
    //   ##
    //  # #
    // ##  #
    //
    //
    0x08, 0x98, 0x60, 0xF0, 0x08, 0x01, 0x01, 0x00, 0x00, 0x01,

    // @624 'y' (5 pixels wide)
    //
    //
    //
    // #   #
    //  # #
    //  # #
    //  # #
    //   #
    //   #
    //   #
    // ##
    0x08, 0x70, 0x80, 0x70, 0x08, 0x04, 0x04, 0x03, 0x00, 0x00,

    // @634 'z' (5 pixels wide)
    //
    //
    //
    //  ####
    //    #
    //   ##
    //   #
    //  #
    // #####
    //
    //
    0x00, 0x88, 0x68, 0x38, 0x08, 0x01, 0x01, 0x01, 0x01, 0x01,
};

// Character descriptors for Roboto 8pt
// { [Char width in bits], [Offset into roboto_8ptCharBitmaps in bytes] }
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
    {6, 20},    // 2
    {5, 32},    // 3
    {6, 42},    // 4
    {5, 54},    // 5
    {5, 64},    // 6
    {6, 74},    // 7
    {5, 86},    // 8
    {4, 96},    // 9
    {0, 0},     // :
    {0, 0},     // ;
    {0, 0},     // <
    {0, 0},     // =
    {0, 0},     // >
    {0, 0},     // ?
    {0, 0},     // @
    {7, 104},   // A
    {5, 118},   // B
    {6, 128},   // C
    {6, 140},   // D
    {5, 152},   // E
    {5, 162},   // F
    {6, 172},   // G
    {6, 184},   // H
    {1, 196},   // I
    {5, 198},   // J
    {6, 208},   // K
    {5, 220},   // L
    {8, 230},   // M
    {6, 246},   // N
    {6, 258},   // O
    {6, 270},   // P
    {6, 282},   // Q
    {6, 294},   // R
    {5, 306},   // S
    {6, 316},   // T
    {5, 328},   // U
    {7, 338},   // V
    {10, 352},  // W
    {7, 372},   // X
    {7, 386},   // Y
    {6, 400},   // Z
    {0, 0},     // [
    {0, 0},     // \ /
    {0, 0},     // ]
    {0, 0},     // ^
    {0, 0},     // _
    {0, 0},     // `
    {4, 412},   // a
    {5, 420},   // b
    {5, 430},   // c
    {5, 440},   // d
    {5, 450},   // e
    {4, 460},   // f
    {5, 468},   // g
    {4, 478},   // h
    {1, 486},   // i
    {2, 488},   // j
    {5, 492},   // k
    {1, 502},   // l
    {8, 504},   // m
    {4, 520},   // n
    {6, 528},   // o
    {5, 540},   // p
    {5, 550},   // q
    {3, 560},   // r
    {4, 566},   // s
    {3, 574},   // t
    {4, 580},   // u
    {5, 588},   // v
    {8, 598},   // w
    {5, 614},   // x
    {5, 624},   // y
    {5, 634},   // z
};

// Font information for Roboto 8pt
static const Font::FontInfo FontInfo = {
    11,   //  Character height
    ' ',  //  Start character
    'z',  //  End character
    1,
};

const Font pt8{FontInfo, Bitmaps, Descriptors};
}
}
