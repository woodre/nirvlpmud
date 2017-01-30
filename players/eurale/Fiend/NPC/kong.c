#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("kong");
set_alias("king kong");
set_race("creature");
set_short("King Kong");
set_long(
	"  You look upon the largest gorilla to ever walk.  King Kong\n"+
	"was brought to life in 1933 by RKO Studios.  The film was\n"+
	"directed by Merian Cooper and Ernest Schoendsack but the real\n"+
	"genius was special effects director Willis O'Brien.  This huge\n"+
	"gorilla was made to look 50 feet tall with the use of models\n"+
	"while in fact it was a mere 18 inch detailed doll.\n");

set_level(20);
  set_hp(550);
  set_al(100);
  set_wc(30);
  set_ac(17);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Kong grunts.........\n");
set_a_chat_chance(15);
  load_a_chat("Kong SCREECHES......\n");

}

monster_died() {
tell_room(environment(this_object()),
  "With a giant SCREECH, the giant ape falls at your feet dead!\n\n");
  move_object(clone_object("players/eurale/Fiend/OBJ/kong_fur.c"),
    environment(this_object()));
return 0; }
