#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);

set_name("coat of arms");
set_short("Coat of Arms ("+WHT+"Wyrmskull"+NORM+")");
set_alias("coat");
set_long("A long tabbard or surcoat to be worn over a suit of chainmail or similar\n"+
         "light armors, the coat of arms shows one's alliegance or hometown.\n");
type = "surcoat";
set_ac(0);
set_weight(1);
set_value(450);
}

extra_look() {
if(worn)
  write(environment(this_object())->query_name()+" swears alliegance to the Wyrmskull area.\n");
}

