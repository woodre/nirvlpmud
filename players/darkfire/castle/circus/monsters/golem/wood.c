inherit "/players/darkfire/castle/circus/monsters/golem/_golem";
inherit "/players/darkfire/obj/color";

#include <ansi.h>
#include "../../circus.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("sticks");
  set_short("A pile of sharpened sticks");

  set_long(UTIL->wrap("This weird creature looks like a pile of sharp, splintered "
  	+ "boards that have been stuck together with long, rusty nails, tangles of wire, "
  	+ "and hatred. It makes strange chittering noises and clacks spiked "
  	+ "boards together threateningly as it scrambles towards you on crablike legs. "
  	+ "Perhaps it has been inhabited by the "+hiw("spirit")+" of something unfriendly.")+"\n"
  );
}
