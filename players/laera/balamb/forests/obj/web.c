#include "/players/laera/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("silk web");
  set_alias("web");
  set_short(HIW+"Silk Web"+OFF);
set_long(
	"A fragile web, weaved by a Caterchipillar.  It is made from the same\n" +
	"strands the caterchipillar uses to paralyze its prey.  It can be \n" +
	"harvested to make fine clothing, but at one time the web was used as\n" +
	"a spell component.\n");

  set_value(650 + random(250));
  set_weight(1);
}

