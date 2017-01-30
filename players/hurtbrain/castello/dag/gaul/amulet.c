
inherit "obj/armor";
#include "/open/ansi.h"

reset(arg){
   if(arg) return;
   ::reset(arg);
        set_name("amulet") ;
        set_alias("lucky amulet");
        set_short(HIG+"Lucky amulet"+NORM) ;
        set_long("This is a tipical gaulic amulet. It seems magical.\n") ;
        set_weight(2) ;
        set_value(1500);
        set_type("amulet") ;
        set_ac(2) ;
}
