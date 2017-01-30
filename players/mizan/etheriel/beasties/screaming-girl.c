inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/HighLevelGuard.c"

reset(arg) 
{
    object weapon,treasure,coins;
    ::reset(arg);
    if(arg) return;
    set_name("screaming girl");
    set_race("girl");
    set_short("A screaming girl");
    set_long("This is a screaming girl. She is obviously a teenager, but why\n"+
    "is she screaming? Well, why did the chicken cross the road?\n"+
    "To get to the other side? No!! Because he felt like it! \n"+
    "Likewise, this girl feels like screaming.\n");
    set_level(4);
    set_hp(60);
    set_al(100);
    set_ac(4);
    set_wc(8);
    set_chance(15);
    set_spell_dam(8);
    set_spell_mess1("The girl screams and kicks at you!");
    set_spell_mess2("The girl shouts: What the hell are you doing??");
    set_chat_chance(4);
    load_chat("The girl screams.\n");
    load_chat("The girl goes: AAAAAUGH!!! eeeeEEEEE!!!!\n");
    coins=clone_object("obj/money");
    coins->set_money(100+random(50));
    move_object(coins, this_object());
}

