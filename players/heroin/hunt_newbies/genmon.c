inherit "obj/monster.talk";

object gold;
reset(arg) {
||reset(arg);
if (!arg) {
set_name("change");
set_alias("change");
set_short("change");
set_race("change");
set_long(
"change me \n"+
"same here\n");
gold = clone_object("obj/money");
gold -> set_money (random(###)+###);
set_level(#);
call_other(this_object(),"set_heal",#,#);
set_ac(#);
set_wc(#);
set_hp(#);
set_al(#);
set_chance(#);
set_spell_dam(#);
set_spell_mess2("blah");
set_spell_mess1("blah");
set_aggressive(#);
set_a_chat_chance(#);
set_chat_chance(#);
load_chat("blah \n");
load_a_chat("blah \n");
}
}

