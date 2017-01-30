
#include "/open/ansi.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("tunic") ;
        set_alias("scarlet tunic");
/* changed to red [6.25.01] */
set_short(RED+"scarlet tunic"+NORM);
        set_long("This is the tunic that all roman's tribunes worn.\n") ;
       set_weight(2) ;  /* We need more light armors for Fallen/Necros -Forbin 2005.04.27 */
        set_value(2000);
	set_type("armor") ;
        set_ac(4) ;
}
