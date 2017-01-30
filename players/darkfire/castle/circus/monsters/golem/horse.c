inherit "/players/darkfire/castle/circus/monsters/golem/_golem";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "../../circus.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("horse");
  set_short("Animatronic carousel horse");

  set_long(UTIL->wrap("The carousel horse looms high above you. Its workmanship is still superb, "
  	+ "despite the cracks running through its wooden body. The brass spiral "
  	+ "pole that used to move it up and down now sticks straight out of it like a spear. "
  	+ "The rusty, jagged end is tipped with " + hir("blood") + ". It is pointed directly at you. "
  	+ "The horse is somehow still animated, perhaps it has been "
  	+ "inhabited by the "+hiw("spirit")+" of something unfriendly.")+"\n"
  );
}