#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("headdress");
set_short(HIR+"Chief's "+HIY+"Headdress"+NORM);
  set_long(
	"  This full chieftan headdress is made with eagle feathers and \n"+
	"has intricate beadwork.  Only a high-ranking member of the tribe \n"+
	"would be allowed to wear it. \n");
  set_ac(1);
  set_type("helmet");
  set_weight(1);
  set_value(200);
}
