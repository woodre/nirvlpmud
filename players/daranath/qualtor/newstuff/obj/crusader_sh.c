#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("crusader shield");
set_short(WHT+"Crusader Shield"+NORM);
set_alias("shield");
set_long("A full length white battle shield painted in the insignia\n"+
         "of the crusaders, a red cross emblazened on a white\n"+
         "background. Very good protection in a fight.\n");
set_type("shield");
set_ac(2);
set_weight(1);
set_value(1175);
}
