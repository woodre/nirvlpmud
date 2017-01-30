#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("porcupine"); 
  set_alias("porcupine");
  set_short("Porcupine");
  set_long("Porcupine is a small animal covered with sharp quills, currently\n"+
           "he is studying with Pig and Gopher in the school.\n");
  set_race("rodent");
  set_gender("male");
  set_level(6);
  set_wc(10);
  set_ac(5);
  set_hp(90);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
  set_al(200);
  load_chat("Porcupine pokes you with his quills.\n");
  load_chat("Porcupine says: are my quills really sharp or what?\n");
  set_chat_chance(20);
move_object(clone_object("/players/pestilence/blue/weps/quill.c"),
        this_object()); }
