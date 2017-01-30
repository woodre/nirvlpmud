/*  Velociraptor  */

#include "/players/eurale/closed/ansi.h"
#define ETO environment(this_object())
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
set_hp(510 + random(60));
set_al(-1);
set_aggressive(1);
set_dead_ob(this_object());
set_wc(30);
set_ac(17);


set_chat_chance(5);
  load_chat("The raptor hisses...... \n");
set_a_chat_chance(7);
  load_a_chat("The raptor spits acid at your eyes..... \n");


set_chance(14);
set_spell_dam(20 + random(10));
set_spell_mess1(
  "\n\nThe raptor SPITS at its prey...\n\n");
set_spell_mess2(
  "\n\nThe raptor "+RED+"SPITS ACID "+NORM+"in your face...\n\n");

}

monster_died() {
tell_room(environment(this_object()),
  "The killing blow is struck!  The raptor begins to hemorrhage..\n"+
  "and right before your eyes its left eyeball literally 'blows' out\n"+
  "of its head, a disgusting sight..........\n\n");
move_object(clone_object("players/eurale/Park/OBJ/eye3"),ETO);
return 0; }
