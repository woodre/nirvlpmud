#include <ansi.h>
#include "/sys/lib.h"
object key;
inherit "obj/treasure";

reset(arg)  
{
        if(arg) return;

		SetMultipleIds( ({ "key","fragment","kf2" }) );
        set_short(""+HIK+"Key"+NORM+" fragment");
        set_long("This key is rusted and jagged. Blood stains its surface.\n");
        set_weight(1);
        set_value(10);
}
 
  init() {
        ::init();

        if(present("kf1") && present("kf2") && present("kf3")) {
        key=clone_object("/players/sami/area/GPO/quest/key.c");
		move_object(key, environment(this_object()));
		destruct(present("kf1", environment(this_object())));
		destruct(present("kf3", environment(this_object())));
		destruct(present("kf2", environment(this_object())));
        write("The key fragments "+HIY+"glow"+NORM+" and merge into one.\n");
		return;
        }
}