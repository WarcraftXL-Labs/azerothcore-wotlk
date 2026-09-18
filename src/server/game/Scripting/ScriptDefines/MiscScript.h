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

#ifndef SCRIPT_OBJECT_MISC_SCRIPT_H_
#define SCRIPT_OBJECT_MISC_SCRIPT_H_

#include "ObjectGuid.h"
#include "ScriptObject.h"
#include <vector>

struct Condition;
class Unit;
class WorldSession;
struct ItemTemplate;
class WorldPacket;

enum MiscHook
{
    MISCHOOK_ON_CONSTRUCT_OBJECT,
    MISCHOOK_ON_DESTRUCT_OBJECT,
    MISCHOOK_ON_CONSTRUCT_PLAYER,
    MISCHOOK_ON_DESTRUCT_PLAYER,
    MISCHOOK_ON_CONSTRUCT_GROUP,
    MISCHOOK_ON_DESTRUCT_GROUP,
    MISCHOOK_ON_CONSTRUCT_INSTANCE_SAVE,
    MISCHOOK_ON_DESTRUCT_INSTANCE_SAVE,
    MISCHOOK_ON_ITEM_CREATE,
    MISCHOOK_CAN_APPLY_SOULBOUND_FLAG,
    MISCHOOK_CAN_ITEM_APPLY_EQUIP_SPELL,
    MISCHOOK_CAN_SEND_AUCTIONHELLO,
    MISCHOOK_VALIDATE_SPELL_AT_CAST_SPELL,
    MISCHOOK_VALIDATE_SPELL_AT_CAST_SPELL_RESULT,
    MISCHOOK_ON_AFTER_LOOT_TEMPLATE_PROCESS,
    MISCHOOK_ON_PLAYER_SET_PHASE,
    MISCHOOK_ON_INSTANCE_SAVE,
    MISCHOOK_GET_DIALOG_STATUS,
    MISCHOOK_ON_CONDITION_CHECK_RACE,
    MISCHOOK_ON_CONDITION_VALIDATE_RACE,
    MISCHOOK_ON_ITEM_QUERY_SINGLE_RACE_MASK,
    MISCHOOK_ON_CHECK_RACE_MASK,
    MISCHOOK_ON_CHECK_CLASS_MASK,
    MISCHOOK_END
};

class MiscScript : public ScriptObject
{
protected:
    MiscScript(char const* name, std::vector<uint16> enabledHooks = std::vector<uint16>());

public:
    [[nodiscard]] bool IsDatabaseBound() const override { return false; }

    virtual void OnConstructObject(Object* /*origin*/) { }

    virtual void OnDestructObject(Object* /*origin*/) { }

    virtual void OnConstructPlayer(Player* /*origin*/) { }

    virtual void OnDestructPlayer(Player* /*origin*/) { }

    virtual void OnConstructGroup(Group* /*origin*/) { }

    virtual void OnDestructGroup(Group* /*origin*/) { }

    virtual void OnConstructInstanceSave(InstanceSave* /*origin*/) { }

    virtual void OnDestructInstanceSave(InstanceSave* /*origin*/) { }

    virtual void OnItemCreate(Item* /*item*/, ItemTemplate const* /*itemProto*/, Player const* /*owner*/) { }

    [[nodiscard]] virtual bool CanApplySoulboundFlag(Item* /*item*/, ItemTemplate const* /*proto*/) { return true; }

    [[nodiscard]] virtual bool CanItemApplyEquipSpell(Player* /*player*/, Item* /*item*/) { return true; }

    [[nodiscard]] virtual bool CanSendAuctionHello(WorldSession const* /*session*/, ObjectGuid /*guid*/, Creature* /*creature*/) { return true; }

    virtual void ValidateSpellAtCastSpell(Player* /*player*/, uint32& /*oldSpellId*/, uint32& /*spellId*/, uint8& /*castCount*/, uint8& /*castFlags*/) { }

    virtual void ValidateSpellAtCastSpellResult(Player* /*player*/, Unit* /*mover*/, Spell* /*spell*/, uint32 /*oldSpellId*/, uint32 /*spellId*/) { }

    virtual void OnAfterLootTemplateProcess(Loot* /*loot*/, LootTemplate const* /*tab*/, LootStore const& /*store*/, Player* /*lootOwner*/, bool /*personal*/, bool /*noEmptyError*/, uint16 /*lootMode*/) { }

    virtual void OnPlayerSetPhase(AuraEffect const* /*auraEff*/, AuraApplication const* /*aurApp*/, uint8 /*mode*/, bool /*apply*/, uint32& /*newPhase*/) { }

    virtual void OnInstanceSave(InstanceSave* /*instanceSave*/) { }

    /**
     * @brief This hook called before get Quest Dialog Status
     *
     * @param player Contains information about the Player
     * @param questgiver Contains information about the Object
     */
    virtual void GetDialogStatus(Player* /*player*/, Object* /*questgiver*/) { }

    /**
     * @brief Called when evaluating CONDITION_RACE for a unit
     *
     * @param cond Condition being checked
     * @param unit Unit being checked
     * @param result Output whether the condition is met
     * @return true if handled by script, false to fallback to default logic
     */
    virtual bool OnConditionCheckRace(Condition const* /*cond*/, Unit const* /*unit*/, bool& /*result*/) { return false; }

    /**
     * @brief Called when validating CONDITION_RACE parameters
     *
     * @param cond Condition being validated
     * @param result Output whether the condition is valid
     * @return true if handled by script, false to fallback to default logic
     */
    virtual bool OnConditionValidateRace(Condition const* /*cond*/, bool& /*result*/) { return false; }

    /**
     * @brief Called when serializing AllowableRace in SMSG_ITEM_QUERY_SINGLE_RESPONSE
     *
     * @param session WorldSession of the player querying the item
     * @param proto Item template being queried
     * @param data WorldPacket response buffer to serialize race mask into
     * @return true if handled by script (custom serialization written), false to fallback to default uint32
     */
    virtual bool OnItemQuerySingleRaceMask(WorldSession* /*session*/, ItemTemplate const* /*proto*/, WorldPacket& /*data*/) { return false; }

    virtual bool OnCheckRaceMask(uint8 /*table*/, uint32 /*recordId*/, uint8 /*maskIndex*/, uint32 /*fallbackMask*/, uint8 /*race*/, bool& /*result*/) { return false; }

    virtual bool OnCheckClassMask(uint8 /*table*/, uint32 /*recordId*/, uint8 /*maskIndex*/, uint32 /*fallbackMask*/, uint8 /*class_*/, bool& /*result*/) { return false; }
};

#endif
