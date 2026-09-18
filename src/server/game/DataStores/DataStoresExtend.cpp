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

#include "DataStoresExtend.h"
#include "ScriptMgr.h"

bool MatchesRaceMask(uint8 table, uint32 recordId, uint8 maskIndex, uint32 fallbackMask, uint8 race)
{
    bool result = false;
    if (sScriptMgr->OnCheckRaceMask(table, recordId, maskIndex, fallbackMask, race, result))
    {
        return result;
    }

    if (fallbackMask == 0)
    {
        return true;
    }

    if (race == 0)
    {
        return false;
    }

    return (fallbackMask & (1U << (race - 1))) != 0;
}

bool MatchesClassMask(uint8 table, uint32 recordId, uint8 maskIndex, uint32 fallbackMask, uint8 class_)
{
    bool result = false;
    if (sScriptMgr->OnCheckClassMask(table, recordId, maskIndex, fallbackMask, class_, result))
    {
        return result;
    }

    if (fallbackMask == 0)
    {
        return true;
    }

    if (class_ == 0)
    {
        return false;
    }

    return (fallbackMask & (1U << (class_ - 1))) != 0;
}

bool MatchesRaceMask(uint32 fallbackMask, uint8 race)
{
    if (fallbackMask == 0)
    {
        return true;
    }

    if (race == 0)
    {
        return false;
    }

    return (fallbackMask & (1U << (race - 1))) != 0;
}

bool MatchesClassMask(uint32 fallbackMask, uint8 class_)
{
    if (fallbackMask == 0)
    {
        return true;
    }

    if (class_ == 0)
    {
        return false;
    }

    return (fallbackMask & (1U << (class_ - 1))) != 0;
}
