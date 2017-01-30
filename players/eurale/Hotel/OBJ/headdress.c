/* Geronimo's Apache Headdress */

inherit "obj/armor";
#include "/players/eurale/closed/ansi.h"

reset(arg) {
set_name("headdress");
set_short(HIR+"Ap"+HIY+"ac"+HIB+"he "+
          HIR+"He"+HIY+"ad"+HIB+"dr"+HIR+"es"+HIY+"s"+NORM);
set_long(
	"  This full chieftan headdress is made with eagle feathers and \n"+
	"has intricate beadwork.  Only a high-ranking member of the tribe \n"+
	"would be allowed to wear it. \n");
  set_ac(2);
  set_type("helmet");
  set_weight(1);
  set_value(200);
 /* Added by Illarion May 2005 */
  set_params("magical",2,0,0);
}
