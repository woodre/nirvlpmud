#include "/open/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("cape");
set_alias("hooded cape");
set_short(GRN+"Velvety "+RED+"Hooded"+GRN+" Cape"+NORM);
set_long(
	"This velvety hooded cape with the red bands is worn exclusively\n"+
	"by the Imperial Shaman Disirs.  It is a badge of honor and a\n"+
	"sign of immense power.\n");
  set_ac(2);
  set_type("cloak");
  set_weight(2);
  set_value(1000);
}
