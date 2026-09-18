/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ACORE_DATASTORESEXTEND_H
#define ACORE_DATASTORESEXTEND_H

#include "Define.h"

enum DynamicMaskOverlayTable : uint8
{
    DYNAMIC_MASK_TABLE_SKILL_LINE_ABILITY  = 0,
    DYNAMIC_MASK_TABLE_SKILL_RACE_CLASS    = 1,
    DYNAMIC_MASK_TABLE_TALENT_TAB          = 2,
    DYNAMIC_MASK_TABLE_DANCE_MOVES         = 3,
    DYNAMIC_MASK_TABLE_FACTION             = 4
};

bool MatchesRaceMask(uint8 table, uint32 recordId, uint8 maskIndex, uint32 fallbackMask, uint8 race);
bool MatchesClassMask(uint8 table, uint32 recordId, uint8 maskIndex, uint32 fallbackMask, uint8 class_);
bool MatchesRaceMask(uint32 fallbackMask, uint8 race);
bool MatchesClassMask(uint32 fallbackMask, uint8 class_);

#endif // ACORE_DATASTORESEXTEND_H
