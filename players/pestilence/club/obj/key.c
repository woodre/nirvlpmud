#include "/players/pestilence/define.h"
inherit "/obj/treasure.c";


reset(arg){
if(arg) return;
set_id("club key");
set_alias("key");
set_short("a small door key"+NORM+"");
set_long(
"This is a small key used for locking the backdoor of Pesty's.\n"+
"Strip Club.\n");
set_value(5);
set_weight(1);
}
