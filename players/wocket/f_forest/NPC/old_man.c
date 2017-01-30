#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset();
  if(arg) return;
  move_object(clone_object("/players/wocket/f_forest/OBJ/cane.c"),this_object());
  set_name("palum");
  set_short("An old man");
  set_alt_name("man");
  set_alias("old man");
  set_long("A whithered old man.  He looks like he has forgotten a lot of\n"+
  "his past.  His clothes are tattered and dusty.  He carries\n"+
    "a small wooden cane.\n");
  set_level(7);
  set_wc(14);
  set_ac(6);
  set_hp(105);
  set_race("human");
  set_gender("male");
  load_chat("Palum say:  I wouldn't go south if I were you.\n");
  load_chat("Palum says:  Now what was I going to say?\n");
  load_chat("Palum says:  The forest makes you forget things.\n");
  load_chat("Palum says:  Hello, Do I know you?\n");
  load_chat("Palum says:  Now where did I put my cane?\n");
  load_chat("Palum says:  The forest is very dangerous.\n");
  set_chat_chance(20);
  command("wield cane");
}
