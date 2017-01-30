/*
    fc8.c - A forest creature.
    Used in /players/traff/delnoch/forest
    Level 16 critter
    Still needs editing as of 2-27-00
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("wild boar");
  set_race("critter");
  set_alias("boar");
  set_short(YEL+"Wild Boar"+NORM);
    if(random(100)>28) { set_aggressive(1); }
    if(random(100)>72) { set_whimpy(1); }
  set_long(HIR+
  "A very large boar.  He looks mean!\n"+NORM);
  set_level(16);
  set_hp(400);
  set_al(800-random(1600));
  set_dead_ob(this_object());
/* I may want to increase chat numbers later, after testing */
  set_chat_chance(2);
  set_a_chat_chance(5);
  load_chat("The boar snorts.\n");
  load_a_chat("The boar snarles and charges!\n");
  set_chance(40+random(20));
  set_spell_mess1("The boar bites his victim!\n");
  set_spell_mess2("The boar bites you!\n");
  set_spell_dam(40+random(20));
/* Sword will be changed to teeth or claws or... */
  weapon = clone_object("/players/traff/delnoch/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  set_wc(22);
  set_ac(13);
  set_alt_name("crti");
}
monster_died() {
  object ob;
  call_other("/players/traff/delnoch/forest/forest2.c","dead_mon");
  write_file("/players/traff/delnoch/forest/CRITTERS",ctime()+" Wild Boar killed\n");
/* Trinket will be changed to skin or pelt or something. */
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
  ob=present("crtg",(environment(this_object())));
  if(ob) {  command("east",ob);  }
  ob=present("crth",(environment(this_object())));
  if(ob) {  command("west",ob);  }
  ob=present("crtj",(environment(this_object())));
  if(ob) {  command("south",ob);  }
  return 0; }
