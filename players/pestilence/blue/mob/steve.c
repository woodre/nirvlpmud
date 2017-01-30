#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("steve"); 
  set_alias("steve");
  set_short("Steve");
  set_long("Steve has brown hair and brown eyes, he is wearing a dark green shirt with\n"+
           "light green stripes and brown slacks, with his sneakers.\n");
  set_race("human");
  set_gender("male");
  set_level(8);
  set_wc(12);
  set_ac(7);
  set_hp(120);
  set_ep(1000);
  add_money(10 + random(300));
  set_aggressive(0);
  set_al(200);
  load_chat("Steve says: will you help me play Blue's clue's.\n");
  set_chat_chance(10);
  move_object(clone_object("/players/pestilence/blue/obj/crayon"),
        this_object()); }
