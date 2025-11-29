//
// Created by ceo on 2025/11/29.
//


class druid_bot : public CreatureScript
{
    public:
        druid_bot() : CreatureScript("druid_bot") {}

        CreatureAI *GetAI(Creature *creature) const override {
            return new bot_druid_ai(creature);
        }

        struct bot_druid_ai : public bot_ai {
            bot_druid_ai(Creature *creature) : bot_ai(creature) {
                _botclass = BOT_CLASS_DRUID;

                InitUnitFlags();
            }

            bool doCast(Unit *victim, uint32 spellId) {
                if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                    return false;
                return bot_ai::doCast(victim, spellId);
            }
        }

}