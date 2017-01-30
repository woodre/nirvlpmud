#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);

set_name("signet ring");
set_short("Signet Ring ("+HIB+"Ryllian"+NORM+")");
set_alias("ring");
set_long("A strong ring made for couriers and travelling knights, the signet\n"+
         "rings were favored to show alliegance to one's homeland.\n");
set_type("ring");
set_ac(1);
set_weight(1);
set_value(300);
}

extra_look() {
if(worn)
  write(environment(this_object())->query_name()+" hails from the the magical city called Ryllian.\n");
}

