#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gopher"); 
  set_alias("gopher");
  set_short("Gopher");
  set_long("Gopher is small, covered in brown fur with some sharp teeth.  Currently\n"+
           "he is studying with Pig in the school.\n");
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
  load_chat("Gopher says: lets go play.\n");
  load_chat("Gopher says: please don't take my pen.\n");
  set_chat_chance(20);
move_object(clone_object("/players/pestilence/blue/weps/pen.c"),
        this_object()); }
