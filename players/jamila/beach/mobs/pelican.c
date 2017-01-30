#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  set_name("large pelican");
  set_alt_name("pelican");
  set_alias("bird");
  set_short("A Large Pelican");
  set_long(
"The pelican glides easily above the water searching for\n"+
"brave small fish that swim too close to the surface.  He\n"+
"is a vary large bird and you are weary of his presence.\n"
  );
  set_gender("male");
  set_race("bird");
  set_level(8);
  set_wc(12+random(2));
  set_ac(7+random(2));
  set_hp(95+random(15));
  set_al(100); 
  set_chat_chance(6); 
  set_a_chat_chance(8);
  load_chat("The pelican swoops down and takes in a mouthfull of water hoping for a fish.\n");
  load_a_chat("The pelican swoops in low to attack!\n");
  set_chance(5);
  set_spell_mess1(
"\n\tThe Pelican swoops down and snaps with his large beak\n"+
"\t\tleaving a large welt where his beak meets flesh.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe Pelican swoops down at you and snaps with his large\n"+
"\t\tbeak leaving a large welt where his beak met your flesh.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(5);
}
monster_died() {
tell_room(environment(this_object()),
  "The pelican falls from the sky as it dies and drops\n"+
  "a large shell shield at your feet.  It must have found\n"+
  "the shell in the ocean somewhere.\n");
move_object(clone_object("players/jamila/beach/mobs/shell"),
        environment(this_object()));
return 1; }