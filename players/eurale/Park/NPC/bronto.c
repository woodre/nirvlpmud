#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
reset(arg) {

::reset(arg);
if(arg) return;
set_name("brontosaurus");
set_race("creature");
set_short("Brontosaurus");
set_alias("bronto");
set_long(
	"  This was one of the largest animals to ever live.  It measured \n"+
	"over 65 feet in length and could raise its head over 30 feet \n"+
	"above the ground.  This monstrous beast weighed almost 50 tons, \n"+
	"as much as 10 elephants.  It spent much of its time wading in \n"+
	"swamps and marshes as the water helped support its heavy body. \n");
set_level(20);
set_hp(520 + random(50));
set_al(-1);
set_ac(18);
set_aggressive(0);
set_dead_ob(this_object());

set_wc(31);


set_chat_chance(5);
  load_chat("The brontosaurus raises its head...... \n");
set_a_chat_chance(7);
  load_a_chat("\n\nThe huge tail just wizzes by your head.... \n\n");
  load_a_chat("The beast takes a fearsome BITE at you.. \n");


set_chance(9);
set_spell_dam(30 + random(10));
  set_spell_mess1(
  "\n\nThe huge beast swings its tail and..... \n\n"+
  "           T H W A C K .... \n\n"+
  "hits its foe in the chest..... \n\n");
  set_spell_mess2(
  "\n\nThe mighty brontosaurus swings its tail and.... \n\n"+
BOLD+"            T T H H W W A A C C K K ......"+NORM+"\n\n"+
  "hits you square in the chest... \n\n");

}

monster_died() {
  tell_room(environment(this_object()),
  "\nS P L A S H..... as the gigantic beast hits the water, something\n"+
  "comes floating to the top.....\n\n");
  move_object(clone_object("players/eurale/Park/OBJ/bronto_nail"),
    environment(this_object()));
return 0; }
