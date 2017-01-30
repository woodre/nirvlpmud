/*  Velociraptor  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg) {

::reset(arg);
if(arg) return;
set_name("raptor");
set_race("creature");
set_short(GRY+"Velociraptor"+NORM);
set_alias("velociraptor");
set_long(
	"  This quick, 6 foot tall reptile immobilizes its prey by \n"+
	"spitting acid in its eyes, rendering it sightless.  It then \n"+
	"proceeds to attack at will, disemboweling its victim. \n");
set_level(20);
set_hp(random(100)+500);
set_al(-1);
set_aggressive(1);
set_dead_ob(this_object());
set_wc(30);
set_ac(17);


set_chat_chance(5);
  load_chat("The raptor hisses...... \n");
set_a_chat_chance(7);
  load_a_chat("The raptor spits acid at your eyes..... \n");


set_chance(12);
set_spell_dam(20 + random(10));
set_spell_mess1(
  "\n\nThe raptor SPITS at its prey...\n\n");
set_spell_mess2(
  "\n\nThe raptor "+GRN+"SPITS ACID "+NORM+"in your face...\n\n");

}

monster_died() {
tell_room(environment(this_object()),
  "As you smash the raptor with your final blow, one of its large,\n"+
  "bulging eyeballs pops out and lands at your feet.\n");
move_object(clone_object("players/eurale/Park/OBJ/eye1"),
	environment(this_object()));
return 0; }
