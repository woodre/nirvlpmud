inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
if(arg) return;
  set_name("tickety tock");
  set_alt_name("tickety");
  set_alias("clock");
set_short("Tickety Tock the clock");
set_long("Blue's friend Tickety the alarm clock is pink with a white face.  The\n"+
"purple numbers 1 through 12 circle his face and his black hands point to\n"+
"12 and 6.  On top of his head sit 2 large silver bells.\n");
set_level(4);
set_wc(8);
set_ac(5);
set_hp(60);
set_ep(1000);
add_money(0);
set_aggressive(0);
set_al(200);
load_chat("Tickety counts: ...1 ...2 ...3 ...4 ...5\n");
set_chat_chance(20);
move_object(clone_object("/players/pestilence/blue/obj/hands.c"),
this_object());
}
