inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/HighLevelGuard.c"

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("dummy");
    set_race("dummy");
    set_alias("dummy");
    set_ep(3300);
    set_short("A dummy");
    set_level(4);
    set_long("This is basically a dummy. There isn't much to say about him.\n"+
    "He simply does'nt look too bright, and he's annoying as heck.\n");
    set_hp(60);
    set_al(-1000);
    set_wc(8);
    set_ac(3);
    set_chance(20);
    set_spell_dam(4);
    set_spell_mess1("Dummy goes: OoO0OoO0OooO0oOo0Oo0OoO0OoOH! Ouch! That  HURT!");
    set_spell_mess2("Dummy screams loudly!");
    set_chat_chance(20);
    load_chat("Dummy goes: DUH!\n");
    load_chat("Dummy says: I'm a DUMMY!\n");
    load_chat("Dummy lets out a real rip-roarer.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
}
