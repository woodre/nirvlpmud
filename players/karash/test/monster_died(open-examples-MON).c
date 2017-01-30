/*
This is an example of a monster that clones a treasure and shows a message
after it dies.
       -Feldegast
*/
#include "/players/feldegast/defines.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("panther");
  set_alias("leopard");
  set_short(BOLD+"A black panther"+NORM);
  set_long(
"The panther is a large animal, approximately 2 meters in\n"+
"length with large claws and sharp fangs.  It's hide is\n"+
"colored pitch black and is difficult to make out as it\n"+
"slips through the shadows.\n"
  );
  set_gender("male");
  set_race("cat");
  set_level(6);
  set_wc(10);
  set_ac(5);
  set_hp(90);
  set_al(0);
  set_chat_chance(2);
  load_chat("The panther makes a low growling sound.\n");
  set_dead_ob(this_object()); /* Specifies what object the monster_died function is in. */
}

monster_died(ob) {
  object skin;

  write("With great skill, you quickly skin the panther.\n");
  tell_room(environment(),
            this_player()->query_name()+" skins the panther.\n",
            ({ this_player() }) /* tp won't see this message */
  );

  skin=clone_object("/obj/treasure");
  skin->set_id("hide");
  skin->set_short("A panther hide");
  skin->set_long(
"This is the raw hide of a black panther.  It could be valuable.\n"
  );
  skin->set_value(250);
  skin->set_weight(1);

  move_object(skin,environment(ob));

/* If you'd rather clone a file that you've created, you'd do
  move_object(clone_object(FILENAME),this_object());
   instead and omit the skin variable.
*/

}
