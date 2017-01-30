inherit "/players/darkfire/castle/circus/monsters/golem/_golem";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "../../circus.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("gnome");
  set_short("Animatronic gnome");

  set_long(UTIL->wrap("The gnome is a short, stocky pile of steel pipes "
  	+ "and pneumatic motors held together with baling wire, duct tape, and rusty springs. "
  	+ "It has a sharp, pointed beard and beady " + hig("green eyes") + ". "
  	+ "The wicked little thing is somehow still animated, perhaps it has been "
  	+ "inhabited by the "+hiw("spirit")+" of something unfriendly.")+"\n"
  );
}
