#include "/players/dusan/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("giant skeleton");
set_alias("skeleton");
set_alt_name("giant");
set_race("skeleton");
set_short("Giant skeleton");
set_long(
  "This mammoth skeleton seems to have be resurrected from the dead \n"+
  "unlike the rest of the skeletons in this swamp.  There seems to be \n"+
  "something lodged in it's skull.\n");

set_level(19);
set_hp(500+random(100));
set_al(-1000);
set_wc(28);
set_ac(16);
set_heal(5,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The skeleton rattles as it shuffles around the room. \n");
set_a_chat_chance(15);
  load_a_chat("The Giant skeleton crushes you with a massive hand. \n");

set_chance(25);
set_spell_dam(10+random(20));

set_spell_mess1(
  "The giant skeleton "+RED+"SQUASHES"+NORM+" his attacker!!! \n");
set_spell_mess2(
  "The giant skeleton "+RED+"SQUASHES"+NORM+" you!!! \n");
}

monster_died() {
  object corpse;  
  corpse = present("corpse",environment());
  move_object(clone_object("/players/dusan/town/items/metal.c"),
      environment(this_object()));
  move_object(clone_object("/players/dusan/area1/items/pieces.c"),
       environment(this_object()));
  move_object(clone_object("/players/dusan/area1/items/pieces.c"),
       environment(this_object()));
  tell_room(environment(this_object()),
	"As you smash the Giant skeleton with your last blow \n"+
      "its skull drops, cracks open and a large metal object\n"+
      "drops out.\n");
 if(corpse)
    destruct(corpse);
return 1; }
