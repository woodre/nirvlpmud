/*
    fc1.c - A forest creature.
    Used in /players/traff/delnoch/forest
    Level 9 critter
    Still needs editing as of 2-27-00
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("otter");
  set_race("critter");
  set_alias("cat");
  set_short(YEL+"Otter"+NORM);
    if(random(100)>56) { set_aggressive(1); }
    if(random(100)>44) { set_whimpy(1); }
  set_long(HIR+
  "A very large otter.  He looks mean!\n"+NORM);
  set_level(9);
  set_hp(135);
  set_al(450-random(900));
  set_dead_ob(this_object());
/* I may want to increase chat numbers later, after testing */
  set_chat_chance(2);
  set_a_chat_chance(5);
  load_chat("The otter screams.\n");
  load_a_chat("The otter charges!\n");
  set_chance(40+random(20));
  set_spell_mess1("The bobcat bites his victim!\n");
  set_spell_mess2("The bobcat bites you!\n");
  set_spell_dam(20+random(10));
/* weap will be changed */
  weapon = clone_object("/players/traff/delnoch/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  set_wc(13);
  set_ac(7);
  set_alt_name("crtb");
}
monster_died() {
  object ob;
  call_other("/players/traff/delnoch/forest/forest2.c","dead_mon");
  write_file("/players/traff/delnoch/forest/CRITTERS",ctime()+" Otter killed\n");
/* Trinket will be changed to pelt or skin or something */
move_object(clone_object("players/traff/misc/trinket.c"),environment(this_object()));
  ob=present("crta",(environment(this_object())));
  if(ob) {  command("north",ob);  }
  ob=present("crtc",(environment(this_object())));
  if(ob) {  command("east",ob);  }
  ob=present("crtd",(environment(this_object())));
  if(ob) {  command("west",ob);  }
  ob=present("crte",(environment(this_object())));
  if(ob) {  command("north",ob);  }
  ob=present("crtf",(environment(this_object())));
  if(ob) {  command("south",ob);  }
  ob=present("crtg",(environment(this_object())));
  if(ob) {  command("east",ob);  }
  ob=present("crth",(environment(this_object())));
  if(ob) {  command("west",ob);  }
  ob=present("crti",(environment(this_object())));
  if(ob) {  command("north",ob);  }
  ob=present("crtj",(environment(this_object())));
  if(ob) {  command("south",ob);  }
  return 0; }
