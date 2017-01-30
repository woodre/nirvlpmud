#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object treasure;

  ::reset(arg);
  if(arg) return;

set_name("jon");
set_alias("miller");
set_alt_name("thane");
set_race("human");
set_short("Jon Thane");
set_long(
  "Jon is the village miller, as was his father before him.  He walks\n"+
  "with a slight limp ever since the accident which crushed his leg in\n"+
  "the mill wheel several years ago.  His hair is covered in a fine layer\n"+
  "of white flour and makes him appear older then he really is.  He is\n"+
  "concerned because the wheat is far too soft this year to make good\n"+
  "flour.  Jon also likes to cheat his customers by using a light bag\n"+
  "when he weighs out the flour.  Keep your eye on him. \n");

set_level(12);
set_hp(150 + random (35));
set_al(-350);
set_wc(13 + random (4));
set_ac(7 + random (3));
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Jon says: The wheat is not right this year. Something is very wrong. \n");
  load_chat("Jon shrugs and says: This does not bode well for our village...not one bit. \n");
  load_chat("The miller frowns and rubs his bum leg. \n");
  load_chat("Jon mumbles: It is the work of the Dark One, I just know it... \n");
  load_chat("Jon fumbles with his purse and says: Mighty light on the coins this year. \n");
set_a_chat_chance(10);
  load_a_chat("Jon says: I didn't mean to cheat you on your flour order, honest. \n");
  load_a_chat("The miller throws his hands in the air and begs you spare his life. \n");
  load_a_chat("Jon looks for someone to help him. \n");

treasure=clone_object("/players/fakir/inn/OBJ/purse1.c");
move_object(treasure,this_object());

}

monster_died() {
  tell_room(environment(this_object()),
    "Jon spins from the force of your blow and drops like a rock.\n");
    return 0; }
