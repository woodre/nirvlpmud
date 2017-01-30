#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("large lobster");
  set_alt_name("lobster");
  set_alias("lobster");
  set_short("A Large Lobster");
  set_long(
"The lobster holds his large claw with pride as he moves\n"+
"around the sandy bottom.  He looks like a veteran and you\n"+
"wonder how many of your type he has fought off successfully\n"
  );
  set_gender("male");
  set_race("crustacean");
  set_level(8);
  set_wc(12+random(2));
  set_ac(7+random(2));
  set_hp(95+random(15));
  set_al(100);
  set_chat_chance(6); 
  set_a_chat_chance(8);
  load_chat("The lobster moves around holding it's claw proudly.\n");
  load_a_chat("The lobster holds his claw high as he rushes!\n");
  set_chance(5);
  set_spell_mess1(
"\n\tThe Lobster rushes his opponent, crashing into their\n"+
"\t\tfeet with a large thunk.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe Lobster rushes you, crashing into your feet with\n"+
"\t\ta large thunk.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(5);
}
monster_died() {
tell_room(environment(this_object()),
  "The lobster dies and it's large claw detaches. You can\n"+
  "now use it to defend yourself as the lobster did.\n");
move_object(clone_object("players/jamila/beach/mobs/claw"),
        environment(this_object()));
return 1; }