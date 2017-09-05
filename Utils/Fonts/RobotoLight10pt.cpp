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
namespace RobotoLight {

//
//  Font data for Roboto Light 10pt
//

// Character bitmaps for Roboto Light 10pt
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

    // @4 '0' (5 pixels wide)
    //
    //  ###
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
    //
    0xFC, 0x02, 0x02, 0x02, 0xFC, 0x01, 0x02, 0x02, 0x02, 0x01,

    // @14 '1' (3 pixels wide)
    //
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
    //
    0x04, 0x04, 0xFE, 0x00, 0x00, 0x03,

    // @20 '2' (6 pixels wide)
    //
    //  ###
    // #   #
    // #   #
    //     #
    //    #
    //   #
    //  #
    // #
    // ######
    //
    //
    //
    0x0C, 0x82, 0x42, 0x22, 0x1C, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,

    // @32 '3' (5 pixels wide)
    //
    //  ###
    // #   #
    //     #
    //     #
    //  ###
    //     #
    // #   #
    // #   #
    //  ###
    //
    //
    //
    0x84, 0x22, 0x22, 0x22, 0xDC, 0x01, 0x02, 0x02, 0x02, 0x01,

    // @42 '4' (7 pixels wide)
    //
    //     ##
    //    # #
    //    # #
    //   #  #
    //  #   #
    //  #   #
    // #######
    //      #
    //      #
    //
    //
    //
    0x80, 0xE0, 0x90, 0x8C, 0x82, 0xFE, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,

    // @56 '5' (6 pixels wide)
    //
    //  ####
    // #
    // #
    // ####
    // #   #
    //      #
    //      #
    // #   #
    //  ###
    //
    //
    //
    0x3C, 0x12, 0x12, 0x12, 0x22, 0xC0, 0x01, 0x02, 0x02, 0x02, 0x01, 0x00,

    // @68 '6' (5 pixels wide)
    //
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
    //
    0xF8, 0x14, 0x12, 0x12, 0xE0, 0x01, 0x02, 0x02, 0x02, 0x01,

    // @78 '7' (7 pixels wide)
    //
    // #######
    //      #
    //      #
    //     #
    //     #
    //    #
    //    #
    //   #
    //   #
    //
    //
    //
    0x02, 0x02, 0x02, 0xC2, 0x32, 0x0E, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,

    // @92 '8' (5 pixels wide)
    //
    //  ###
    // #   #
    // #   #
    // #   #
    //  ###
    // #   #
    // #   #
    // #   #
    //  ###
    //
    //
    //
    0xDC, 0x22, 0x22, 0x22, 0xDC, 0x01, 0x02, 0x02, 0x02, 0x01,

    // @102 '9' (5 pixels wide)
    //
    //  ###
    // #   #
    // #   #
    // #   #
    // #   #
    //  ####
    //     #
    //    #
    //  ##
    //
    //
    //
    0x3C, 0x42, 0x42, 0x42, 0xFC, 0x00, 0x02, 0x02, 0x01, 0x00,

    // @112 'A' (8 pixels wide)
    //
    //    ##
    //    ##
    //   # #
    //   #  #
    //   #  #
    //  #    #
    //  ######
    //  #    #
    // #      #
    //
    //
    //
    0x00, 0xC0, 0xB8, 0x86, 0x8E, 0xB0, 0xC0, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02,

    // @128 'B' (6 pixels wide)
    //
    // #####
    // #    #
    // #    #
    // #    #
    // #####
    // #    #
    // #    #
    // #    #
    // #####
    //
    //
    //
    0xFE, 0x22, 0x22, 0x22, 0x22, 0xDC, 0x03, 0x02, 0x02, 0x02, 0x02, 0x01,

    // @140 'C' (6 pixels wide)
    //
    //  ####
    // #    #
    // #    #
    // #
    // #
    // #
    // #    #
    // #    #
    //  ####
    //
    //
    //
    0xFC, 0x02, 0x02, 0x02, 0x02, 0x8C, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01,

    // @152 'D' (7 pixels wide)
    //
    // #####
    // #    #
    // #     #
    // #     #
    // #     #
    // #     #
    // #     #
    // #    #
    // #####
    //
    //
    //
    0xFE, 0x02, 0x02, 0x02, 0x02, 0x04, 0xF8, 0x03, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00,

    // @166 'E' (6 pixels wide)
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

    // @178 'F' (6 pixels wide)
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

    // @190 'G' (7 pixels wide)
    //
    //   ####
    //  #   ##
    // #     #
    // #
    // #
    // #   ###
    // #     #
    //  #    #
    //   ####
    //
    //
    //
    0xF8, 0x04, 0x02, 0x02, 0x42, 0x46, 0xCC, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01,

    // @204 'H' (7 pixels wide)
    //
    // #     #
    // #     #
    // #     #
    // #     #
    // #######
    // #     #
    // #     #
    // #     #
    // #     #
    //
    //
    //
    0xFE, 0x20, 0x20, 0x20, 0x20, 0x20, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,

    // @218 'I' (1 pixels wide)
    //
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
    //
    0xFE, 0x03,

    // @220 'J' (6 pixels wide)
    //
    //      #
    //      #
    //      #
    //      #
    //      #
    //      #
    // #    #
    //  #   #
    //  ####
    //
    //
    //
    0x80, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x03, 0x02, 0x02, 0x02, 0x01,

    // @232 'K' (7 pixels wide)
    //
    // #    ##
    // #   #
    // #  #
    // # #
    // ###
    // #  #
    // #   #
    // #    #
    // #    ##
    //
    //
    //
    0xFE, 0x20, 0x30, 0x48, 0x84, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02,

    // @246 'L' (6 pixels wide)
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

    // @258 'M' (9 pixels wide)
    //
    // #       #
    // ##     ##
    // ##     ##
    // # #   # #
    // # #   # #
    // #  # #  #
    // #  # #  #
    // #  # #  #
    // #   #   #
    //
    //
    //
    0xFE, 0x0C, 0x30, 0xC0, 0x00, 0xC0, 0x30, 0x0C, 0xFE, 0x03, 0x00, 0x00, 0x01, 0x02, 0x01, 0x00, 0x00, 0x03,

    // @276 'N' (7 pixels wide)
    //
    // #     #
    // ##    #
    // # #   #
    // # #   #
    // #  #  #
    // #   # #
    // #   # #
    // #    ##
    // #     #
    //
    //
    //
    0xFE, 0x04, 0x18, 0x20, 0xC0, 0x00, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03,

    // @290 'O' (7 pixels wide)
    //
    //   ###
    //  #   #
    // #     #
    // #     #
    // #     #
    // #     #
    // #     #
    //  #   #
    //   ###
    //
    //
    //
    0xF8, 0x04, 0x02, 0x02, 0x02, 0x04, 0xF8, 0x00, 0x01, 0x02, 0x02, 0x02, 0x01, 0x00,

    // @304 'P' (6 pixels wide)
    //
    // #####
    // #    #
    // #    #
    // #    #
    // #    #
    // #####
    // #
    // #
    // #
    //
    //
    //
    0xFE, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,

    // @316 'Q' (7 pixels wide)
    //
    //   ###
    //  #   #
    // #     #
    // #     #
    // #     #
    // #     #
    // #     #
    //  #   #
    //   ###
    //      ##
    //
    //
    0xF8, 0x04, 0x02, 0x02, 0x02, 0x04, 0xF8, 0x00, 0x01, 0x02, 0x02, 0x02, 0x05, 0x04,

    // @330 'R' (7 pixels wide)
    //
    // #####
    // #    #
    // #    #
    // #    #
    // #    #
    // #####
    // #   #
    // #   #
    // #    ##
    //
    //
    //
    0xFE, 0x42, 0x42, 0x42, 0xC2, 0x3C, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02,

    // @344 'S' (6 pixels wide)
    //
    //  ####
    // #    #
    // #    #
    // ##
    //   ###
    //      #
    // #    #
    // #    #
    //  ####
    //
    //
    //
    0x9C, 0x12, 0x22, 0x22, 0x22, 0xCC, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01,

    // @356 'T' (7 pixels wide)
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

    // @370 'U' (7 pixels wide)
    //
    // #     #
    // #     #
    // #     #
    // #     #
    // #     #
    // #     #
    // #     #
    //  #   #
    //   ###
    //
    //
    //
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x01, 0x02, 0x02, 0x02, 0x01, 0x00,

    // @384 'V' (8 pixels wide)
    //
    // #      #
    //  #    #
    //  #    #
    //  #   #
    //   #  #
    //   #  #
    //   # #
    //    ##
    //    ##
    //
    //
    //
    0x02, 0x1C, 0xE0, 0x00, 0x80, 0x70, 0x0C, 0x02, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00,

    // @400 'W' (11 pixels wide)
    //
    // #    #    #
    //  #   ##   #
    //  #  # #   #
    //  #  # #  #
    //  #  #  # #
    //   # #  # #
    //   ##   # #
    //   ##   ##
    //    #    #
    //
    //
    //
    0x02, 0x3C, 0xC0, 0x80, 0x78, 0x06, 0x1C, 0xE0, 0x00, 0xF0, 0x0E, 0x00, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x03, 0x00, 0x00,

    // @422 'X' (8 pixels wide)
    //
    // ##    ##
    //  #   #
    //   #  #
    //    ##
    //    #
    //    ##
    //   #  #
    //  #    #
    // ##    ##
    //
    //
    //
    0x02, 0x06, 0x88, 0x70, 0x50, 0x8C, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02,

    // @438 'Y' (8 pixels wide)
    //
    // #     ##
    //  #    #
    //   #  #
    //   #  #
    //    ##
    //    #
    //    #
    //    #
    //    #
    //
    //
    //
    0x02, 0x04, 0x18, 0xE0, 0x20, 0x18, 0x06, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,

    // @454 'Z' (6 pixels wide)
    //
    // ######
    //      #
    //     #
    //    #
    //   #
    //  #
    //  #
    // #
    // ######
    //
    //
    //
    0x02, 0xC2, 0x22, 0x12, 0x0A, 0x06, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,

    // @466 'a' (5 pixels wide)
    //
    //
    //
    //  ###
    // #   #
    //     #
    //  ####
    // #   #
    // #   #
    // #####
    //
    //
    //
    0x90, 0x48, 0x48, 0x48, 0xF0, 0x03, 0x02, 0x02, 0x02, 0x03,

    // @476 'b' (5 pixels wide)
    // #
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
    //
    0xFF, 0x08, 0x08, 0x08, 0xF0, 0x03, 0x02, 0x02, 0x02, 0x01,

    // @486 'c' (5 pixels wide)
    //
    //
    //
    //  ###
    // #   #
    // #
    // #
    // #
    // #   #
    //  ###
    //
    //
    //
    0xF0, 0x08, 0x08, 0x08, 0x10, 0x01, 0x02, 0x02, 0x02, 0x01,

    // @496 'd' (5 pixels wide)
    //     #
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
    //
    0xF0, 0x08, 0x08, 0x08, 0xFF, 0x01, 0x02, 0x02, 0x02, 0x03,

    // @506 'e' (5 pixels wide)
    //
    //
    //
    //  ###
    // #   #
    // #   #
    // #####
    // #
    // #   #
    //  ####
    //
    //
    //
    0xF0, 0x48, 0x48, 0x48, 0x70, 0x01, 0x02, 0x02, 0x02, 0x03,

    // @516 'f' (4 pixels wide)
    //   ##
    //  #
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
    //
    0x08, 0xFE, 0x09, 0x09, 0x00, 0x03, 0x00, 0x00,

    // @524 'g' (5 pixels wide)
    //
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
    // #   #
    //  ###
    0xF0, 0x08, 0x08, 0x08, 0xF8, 0x09, 0x12, 0x12, 0x12, 0x0F,

    // @534 'h' (5 pixels wide)
    // #
    // #
    // #
    // ####
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //
    //
    //
    0xFF, 0x08, 0x08, 0x08, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x03,

    // @544 'i' (1 pixels wide)
    //
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
    //
    0xFA, 0x03,

    // @546 'j' (3 pixels wide)
    //
    //   #
    //
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    // ##
    0x00, 0x00, 0xFA, 0x10, 0x10, 0x0F,

    // @552 'k' (5 pixels wide)
    // #
    // #
    // #
    // #   #
    // #  #
    // # #
    // ###
    // # #
    // #  #
    // #   #
    //
    //
    //
    0xFF, 0x40, 0xE0, 0x10, 0x08, 0x03, 0x00, 0x00, 0x01, 0x02,

    // @562 'l' (1 pixels wide)
    // #
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
    //
    0xFF, 0x03,

    // @564 'm' (10 pixels wide)
    //
    //
    //
    // # ### ###
    // ##  ##   #
    // #   #    #
    // #   #    #
    // #   #    #
    // #   #    #
    // #   #    #
    //
    //
    //
    0xF8, 0x10, 0x08, 0x08, 0xF8, 0x10, 0x08, 0x08, 0x08, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03,

    // @584 'n' (5 pixels wide)
    //
    //
    //
    // ####
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    // #   #
    //
    //
    //
    0xF8, 0x08, 0x08, 0x08, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x03,

    // @594 'o' (7 pixels wide)
    //
    //
    //
    //   ###
    //  #   #
    // #    #
    // #     #
    // #    #
    //  #   #
    //   ###
    //
    //
    //
    0xE0, 0x10, 0x08, 0x08, 0x08, 0xB0, 0x40, 0x00, 0x01, 0x02, 0x02, 0x02, 0x01, 0x00,

    // @608 'p' (5 pixels wide)
    //
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
    // #
    0xF8, 0x08, 0x08, 0x08, 0xF0, 0x1F, 0x02, 0x02, 0x02, 0x01,

    // @618 'q' (5 pixels wide)
    //
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
    //     #
    0xF0, 0x08, 0x08, 0x08, 0xF8, 0x01, 0x02, 0x02, 0x02, 0x1F,

    // @628 'r' (3 pixels wide)
    //
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
    //
    0xF8, 0x08, 0x08, 0x03, 0x00, 0x00,

    // @634 's' (5 pixels wide)
    //
    //
    //
    //  ###
    // #   #
    // #
    //  ###
    //     #
    // #   #
    //  ###
    //
    //
    //
    0x30, 0x48, 0x48, 0x48, 0x90, 0x01, 0x02, 0x02, 0x02, 0x01,

    // @644 't' (4 pixels wide)
    //
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
    //
    0x08, 0xFE, 0x08, 0x08, 0x00, 0x01, 0x02, 0x02,

    // @652 'u' (5 pixels wide)
    //
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
    //
    0xF8, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x02, 0x02, 0x02, 0x03,

    // @662 'v' (6 pixels wide)
    //
    //
    //
    // #    #
    // #   #
    //  #  #
    //  #  #
    //  # #
    //   ##
    //   #
    //
    //
    //
    0x18, 0xE0, 0x00, 0x80, 0x70, 0x08, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00,

    // @674 'w' (9 pixels wide)
    //
    //
    //
    // #   #   #
    //  #  ##  #
    //  # # #  #
    //  # # # #
    //  # #  ##
    //   ##  ##
    //   #   #
    //
    //
    //
    0x08, 0xF0, 0x00, 0xE0, 0x18, 0x70, 0x80, 0xC0, 0x38, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x03, 0x01, 0x00,

    // @692 'x' (6 pixels wide)
    //
    //
    //
    // ##   #
    //  #  #
    //   ##
    //    #
    //   ##
    //  #  #
    // ##   #
    //
    //
    //
    0x08, 0x18, 0xA0, 0xE0, 0x10, 0x08, 0x02, 0x03, 0x00, 0x00, 0x01, 0x02,

    // @704 'y' (6 pixels wide)
    //
    //
    //
    // #    #
    // #   #
    //  #  #
    //  #  #
    //   ##
    //   ##
    //    #
    //   #
    //   #
    // ##
    0x18, 0x60, 0x80, 0x80, 0x70, 0x08, 0x10, 0x10, 0x0D, 0x03, 0x00, 0x00,

    // @716 'z' (5 pixels wide)
    //
    //
    //
    // #####
    //    #
    //   #
    //   #
    //  #
    // #
    // #####
    //
    //
    //
    0x08, 0x88, 0x68, 0x18, 0x08, 0x03, 0x02, 0x02, 0x02, 0x02,
};

// Character descriptors for Roboto Light 10pt
// { [Char width in bits], [Offset into robotoLight_10ptCharBitmaps in bytes] }
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
    {7, 42},    // 4
    {6, 56},    // 5
    {5, 68},    // 6
    {7, 78},    // 7
    {5, 92},    // 8
    {5, 102},   // 9
    {0, 0},     // :
    {0, 0},     // ;
    {0, 0},     // <
    {0, 0},     // =
    {0, 0},     // >
    {0, 0},     // ?
    {0, 0},     // @
    {8, 112},   // A
    {6, 128},   // B
    {6, 140},   // C
    {7, 152},   // D
    {6, 166},   // E
    {6, 178},   // F
    {7, 190},   // G
    {7, 204},   // H
    {1, 218},   // I
    {6, 220},   // J
    {7, 232},   // K
    {6, 246},   // L
    {9, 258},   // M
    {7, 276},   // N
    {7, 290},   // O
    {6, 304},   // P
    {7, 316},   // Q
    {7, 330},   // R
    {6, 344},   // S
    {7, 356},   // T
    {7, 370},   // U
    {8, 384},   // V
    {11, 400},  // W
    {8, 422},   // X
    {8, 438},   // Y
    {6, 454},   // Z
    {0, 0},     // [
    {0, 0},     // \ /
    {0, 0},     // ]
    {0, 0},     // ^
    {0, 0},     // _
    {0, 0},     // `
    {5, 466},   // a
    {5, 476},   // b
    {5, 486},   // c
    {5, 496},   // d
    {5, 506},   // e
    {4, 516},   // f
    {5, 524},   // g
    {5, 534},   // h
    {1, 544},   // i
    {3, 546},   // j
    {5, 552},   // k
    {1, 562},   // l
    {10, 564},  // m
    {5, 584},   // n
    {7, 594},   // o
    {5, 608},   // p
    {5, 618},   // q
    {3, 628},   // r
    {5, 634},   // s
    {4, 644},   // t
    {5, 652},   // u
    {6, 662},   // v
    {9, 674},   // w
    {6, 692},   // x
    {6, 704},   // y
    {5, 716},   // z
};

// Font information for Roboto Light 10pt
static const Font::FontInfo FontInfo = {
    13,   //  Character height
    ' ',  //  Start character
    'z',  //  End character
    2     //  Interchar space
};

const Font pt10{FontInfo, Bitmaps, Descriptors};
}
}
