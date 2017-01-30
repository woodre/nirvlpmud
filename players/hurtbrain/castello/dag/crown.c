
#include "/obj/ansi.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("crown") ;
	set_alias("laurel");
set_short(GRN+"crown of laurel"+NORM);
        set_long("This is a simple crown made of laurel leaves. Only mighty warriors have it.\n") ;
        set_weight(1) ;
        set_value(2000);
	set_type("helmet") ;
        set_ac(2) ;
  set_params("magical",1,0,0);
  set_params("other|water",0,15,0);
  set_params("other|fire",0,-15,0);
}
