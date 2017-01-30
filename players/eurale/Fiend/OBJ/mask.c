#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
  set_name("mask");
  set_short(HIB+"Pha"+HIC+"nt"+HIB+"om M"+HIC+"as"+HIB+"k"+NORM);
  set_long(
	"This hammered-metal mask is worn to protect the identity of\n"+
	"the wearer and to shield him against attack.\n");
  set_ac(2);
  set_params("magical",1,0,0); /* ill */
  set_type("helmet");
  set_weight(1);
  set_value(1000 + random(100));
}
