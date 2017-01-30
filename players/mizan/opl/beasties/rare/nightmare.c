inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"

reset(arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("nightmare");
    set_short("A terrible nightmare");
    set_level(STATS_DM->get_level_easy());
    set_hp(STATS_DM->get_hp_easy());
    set_al(-500);
    set_wc(STATS_DM->get_wp_easy());
    set_ac(STATS_DM->get_ac_easy());

    set_hp_bonus(STATS_DM->get_hp_bonus_easy());
    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;
}

