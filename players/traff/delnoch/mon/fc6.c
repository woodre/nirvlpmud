/*
    fc6.c - A forest creature.
    Used in /players/traff/delnoch/forest
    Level 14 critter
    Still needs editing as of 2-27-00
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("timber wolf");
  set_race("critter");
  set_alias("wolf");
  set_short(YEL+"Timber Wolf"+NORM);
    if(random(100)>36) { set_aggressive(1); }
    if(random(100)>64) { set_whimpy(1); }
  set_long(HIR+
  "A very large timber wolf.  He looks mean!\n"+NORM);
  set_level(14);
  set_hp(210);
  set_al(700-random(1400));
  set_dead_ob(this_object());
/* I may want to increase chat numbers later, after testing */
  set_chat_chance(2);
  set_a_chat_chance(5);
  load_chat("The timber wolf howls.\n");
  load_a_chat("The timber wolf charges!\n");
  set_chance(40+random(20));
  set_spell_mess1("The timber wolf bites his victim!\n");
  set_spell_mess2("The timber wolf bites you!\n");
  set_spell_dam(30+random(15));
/* weap will be changed */
  weapon = clone_object("/players/traff/delnoch/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  set_wc(18);
  set_ac(11);
  set_alt_name("crtg");
}
monster_died() {
  object ob;
  call_other("/players/traff/delnoch/forest/forest2.c","dead_mon");
  write_file("/players/traff/delnoch/forest/CRITTERS",ctime()+" Timber Wolf killed\n");
/* Trinket will be changed to pelt or skin or something */
move_object(clone_object("players/traff/misc/trinket.c"),environment(this_object()));
  ob=present("crta",(environment(this_object())));
  if(ob) {  command("north",ob);  }
  ob=present("crtb",(environment(this_object())));
  if(ob) {  command("south",ob);  }
  ob=present("crtc",(environment(this_object())));
  if(ob) {  command("east",ob);  }
  ob=present("crtd",(environment(this_object())));
  if(ob) {  command("west",ob);  }
  ob=present("crte",(environment(this_object())));
  if(ob) {  command("north",ob);  }
  ob=present("crtf",(environment(this_object())));
  if(ob) {  command("south",ob);  }
  ob=present("crth",(environment(this_object())));
  if(ob) {  command("west",ob);  }
  ob=present("crti",(environment(this_object())));
  if(ob) {  command("north",ob);  }
  ob=present("crtj",(environment(this_object())));
  if(ob) {  command("south",ob);  }
  return 0; }
