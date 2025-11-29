//
// Created by ceo on 2025/11/29.
//

#ifndef UECORE_BOTAI_H
#define UECORE_BOTAI_H

#endif //UECORE_BOTAI_H

static constexpr GossipOptionIcon BOT_ICON_ON = GOSSIP_ICON_BATTLE;
static constexpr GossipOptionIcon BOT_ICON_OFF = GOSSIP_ICON_CHAT;

class BotAI : public CreatureAI
{
    public:
        virtual ~BotAI();

        virtual void OnBotSummon(Creature* /*summon*/) {}
        virtual void OnBotDespawn(Creature* /*summon*/) {}
        virtual void UnSummonAll() {}

        virtual void OnBotDamageTaken(Unit* /*attacker*/, uint32 /*damage*/, CleanDamage const* /*cleanDamage*/, DamageEffectType /*damagetype*/, SpellInfo const* /*spellInfo*/) {}
        virtual void OnBotDamageDealt(Unit* /*victim*/, uint32 /*damage*/, CleanDamage const* /*cleanDamage*/, DamageEffectType /*damagetype*/, SpellInfo const* /*spellInfo*/) {}
        virtual void OnBotDispelDealt(Unit* /*dispelled*/, uint8 /*num*/) {}


        Player* master;
        Player* m_prevRRobin;
        Unit* opponent;
        Unit* disttarget;

        ObjectGuid botPetGuid;
        EventProcessor Events;
        ObjectGuid aftercastTargetGuid;
        uint32 GC_Timer;

        uint8 m_botclass;
        uint8 m_spec, m_newspec;
        int8 m_primaryIconTank, m_primaryIconDamage;

        BotVehicleStrats curVehStrat;
        uint8 vehcomboPoints;
        bool shouldEnterVehicle;


    private:
        uint32 _reviveTimer, _powersTimer, _chaseTimer, _engageTimer, _potionTimer;
        uint32 lastdiff, checkAurasTimer, checkMasterTimer, roleTimer, ordersTimer, regenTimer, _updateTimerMedium, _updateTimerEx1;
        uint32 _moveBehindTimer;
        uint32 _wmoAreaUpdateTimer;
        uint32 waitTimer;
        uint32 itemsAutouseTimer;
        uint32 evadeDelayTimer;
        uint32 indoorsTimer;
        uint32 outdoorsTimer;
        uint32 _contestedPvPTimer;
        uint32 _groupUpdateTimer;
}