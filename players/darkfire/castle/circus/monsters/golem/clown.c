inherit "/players/darkfire/castle/circus/monsters/golem/_golem";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "../../circus.h"

#define SUSPENDERS UTIL->alternate("rainbow suspenders", CH_RAINBOW, 2) + NORM

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("clown");
  set_short("Animatronic clown");

  set_long(UTIL->wrap("The clown is a jumbled pile of pipes and pneumatic motors "
  	+ "held together with baling wire, duct tape, and rusty springs. "
  	+ "The whole thing is covered in the shredded remains of a clown "
  	+ "costume held on by a pair of " + SUSPENDERS + ". "
  	+ "The tall, gangly pile of parts is somehow still animated, perhaps it has been "
  	+ "inhabited by the "+hiw("spirit")+" of something unfriendly. It has "
  	+ "a wicked " + red("gleam") + " in its eyes.")+"\n"
  );
}
