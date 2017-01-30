#include "/players/mythos/closed/ansi.h"
inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("tsolin");
  set_race("yokai");
  set_short("A Yokai: Tsolin");
  set_long("You see a small creature.  It looks like a rather large\n"+
      "bug except that it has one only one eye\n"+
       "which is set at the front of its body.   \n"+
      "At the other end is a whip like tail.\n");
  set_hp(450);
  set_level(18);
  set_al(0);
  set_wc(29);
  set_ac(18);
  set_aggressive(1);
  set_a_chat_chance(15);
  load_a_chat("Tsolin flies at you.....There is no escape!\n");
  load_a_chat("The air seems to hum as Tsolin rushes at you.\n");
  set_chance(75);
  set_spell_dam(15);
  set_spell_mess1("Tsolin seems to shiver......\n"+"Then ....\n\n"+HIR+"\t\tBANG!\n\n"+NORM+"Tsolin slams into its enemy!\n");
  set_spell_mess2("Tsolin seems to shiver.....\n"+"Then.....\n\n"+HIR+"\t\tBANG!\n\n"+NORM+"Tsolin slams into you....you feel shaken...\n");
  call_out("stun",5);
}

stun() {
  if(this_object()->query_hp() < 80) {
  object ob;
  tell_room(environment(this_object()),
  "Tsolin falls over- it is stunned.\n");
  ob = clone_object("/players/mythos/amisc/stun2.c");
  move_object(ob,environment(this_object()));
  destruct(this_object());
  return 1; }
  call_out("stun",5);
return 1;
}
