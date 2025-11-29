//
// Created by ceo on 2025/11/29.
//


BotAI::BotAI(Creature* creature) : CreatureAI(creature)
{
    _powersTimer = 0;
    _chaseTimer = 0;
    _engageTimer = 0;

    _unreachableCount = 0;
    _jumpCount = 0;
    _evadeCount = 0;
}