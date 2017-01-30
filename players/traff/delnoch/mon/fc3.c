/*
    fc3.c - A forest creature.
    Used in /players/traff/delnoch/forest
    Level 11 critter
    Still needs editing as of 2-27-00
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("wild dog");
  set_race("critter");
  set_alias("dog");
  set_short(YEL+"Wild Dog"+NORM);
    if(random(100)>48) { set_aggressive(1); }
    if(random(100)>52) { set_whimpy(1); }
  set_long(HIR+
  "A very large wild dog.  He looks mean!\n"+NORM);
  set_level(11);
  set_hp(165);
  set_al(550-random(1100));
  set_dead_ob(this_object());
/* I may want to increase chat numbers later, after testing */
  set_chat_chance(2);
  set_a_chat_chance(5);
  load_chat("The wild dog barks.\n");
  load_a_chat("The wild dog charges!\n");
  set_chance(40+random(20));
  set_spell_mess1("The wild dog bites his victim!\n");
  set_spell_mess2("The wild dog bites you!\n");
  set_spell_dam(30+random(15));
/* weap will be changed */
  weapon = clone_object("/players/traff/delnoch/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  set_wc(15);
  set_ac(9);
  set_alt_name("crtd");
}
monster_died() {
  object ob;
  call_other("/players/traff/delnoch/forest/forest2.c","dead_mon");
  write_file("/players/traff/delnoch/forest/CRITTERS",ctime()+" Wild Dog killed\n");
/* Trinket will be changed to pelt or skin or something */
move_object(clone_object("players/traff/misc/trinket.c"),environment(this_object()));
  ob=present("crta",(environment(this_object())));
  if(ob) {  command("north",ob);  }
  ob=present("crtb",(environment(this_object())));
  if(ob) {  command("south",ob);  }
  ob=present("crtc",(environment(this_object())));
  if(ob) {  command("east",ob);  }
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
