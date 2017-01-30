
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
    object money;
    ::reset(arg);
    if(arg) return;
    set_name("missionary");
    set_alias("demon");
    set_short("Demon Missionary");
   set_long(
      "This humanoid demon is a minor thrall of the Demon Lord \n\
       Brakian. As Brakian's power spreads, so do his thralls. \n\
       Be careful of them, for while each individual missionary \n\
       demon may not be hard to overcome, in great numbers you may \n\
       be overwhelmed.\n");
/*
" This fellow is a follower of the Demon Lord Brakian. As his power \n\
spreads, so do his followers. Be careful of them for in great numbers \n\
you may be overwelmed.\n");
*/
    set_level(5);
    set_aggressive(0);
    set_race("demon");
    set_chat_chance(3);
    load_chat("Missionary scolds: Beware the Demon Lord's wrath!!!!\n");
    load_chat("Missionary whispers: Come join us, brother.\n");
    load_chat("Demon Missionary raises his hands to the sky.\n");
    load_chat("Demon Missionary gestures at your life-force.\n");
    set_hp(100);
    set_al(-300);
    set_wc(9);
    set_ac(5);
   add_spell("Demon Screech",
      "#MN# summons a swarm of demons, who screech loudly around you.\n",
      "A swarm of demons screech loudly, paralyzing #TN# briefly.\n",
      20,5, "other|sonic");
    set_can_kill("monk");
    money = clone_object("obj/money");
    money->set_money(200);
    move_object(money, this_object());
}
