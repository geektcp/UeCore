//
// Created by ceo on 2025/11/29.
//


class paladin_bot : public CreatureScript
{
    public:
        paladin_bot() : CreatureScript("paladin_bot") {}

        CreatureAI *GetAI(Creature *creature) const override {
            return new paladin_botAI(creature);
        }

        struct paladin_botAI : public bot_ai {
            paladin_botAI(Creature *creature) : bot_ai(creature) {
                _botclass = BOT_CLASS_PALADIN;

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