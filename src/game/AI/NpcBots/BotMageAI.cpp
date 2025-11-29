//
// Created by ceo on 2025/11/29.
//


class mage_bot : public CreatureScript
{
    public:
        mage_bot() : CreatureScript("mage_bot") {}

        CreatureAI *GetAI(Creature *creature) const override {
            return new mage_botAI(creature);
        }

        struct mage_botAI : public bot_ai {
            mage_botAI(Creature *creature) : bot_ai(creature) {
                _botclass = BOT_CLASS_MAGE;

                InitUnitFlags();
            }

            bool removeShapeshiftForm() override {
                return true;
            }

            bool doCast(Unit *victim, uint32 spellId) {
                if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                    return false;
                return bot_ai::doCast(victim, spellId);
            }
        }
}