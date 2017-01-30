inherit "obj/monster";

reset(arg) {
::reset(arg);
if(!arg) {
    set_name("demon");
set_short("A malformed demon");
    set_race("demon");
    set_long(
"This is a creature of pure evil.  He lashes out at everything around him.\n"+
"He belches black smoke with every breath he exhales.  You get the impression\n"+
"that he himself is also a former human soul.  Perhaps he offered his soul\n"+
"to the black master in order to gain this position?\n");
   set_level(6);
   set_wc(15);
   set_al(-1000);
  set_aggressive(1);
    set_a_chat_chance(20);
load_a_chat("The demon belches fire and screams at you.\n");
load_a_chat("Demon screams:  Scarthlag Meshkartsz!!!!!\n");
}
}
