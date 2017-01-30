/*
    fc4.c - A forest creature.
    Used in /players/traff/delnoch/forest
    Level 12 critter
    Still needs editing as of 2-27-00
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("deer");
  set_race("critter");
  set_alias("deer");
  set_short(YEL+"Deer"+NORM);
    if(random(100)>44) { set_aggressive(1); }
    if(random(100)>56) { set_whimpy(1); }
  set_long(HIR+
  "A very large deer.  He looks mean!\n"+NORM);
  set_level(12);
  set_hp(180);
  set_al(600-random(1200));
  set_dead_ob(this_object());
/* I may want to increase chat numbers later, after testing */
  set_chat_chance(2);
  set_a_chat_chance(5);
  load_chat("The deer bleats.\n");
  load_a_chat("The deer charges!\n");
  set_chance(40+random(20));
  set_spell_mess1("The deer gores his victim!\n");
  set_spell_mess2("The deer gores you!\n");
  set_spell_dam(30+random(15));
/* weap will be changed */
  weapon = clone_object("/players/traff/delnoch/weps/sword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  set_wc(16);
  set_ac(9);
  set_alt_name("crte");
}
monster_died() {
  object ob;
  call_other("/players/traff/delnoch/forest/forest2.c","dead_mon");
  write_file("/players/traff/delnoch/forest/CRITTERS",ctime()+" Deer killed\n");
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
