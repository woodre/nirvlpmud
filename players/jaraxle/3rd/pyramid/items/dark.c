#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
call_out("kill_it", 5);
   if(arg) return;
set_light(-4);
}
id(str){ return str == "jar_dark_item"; }

kill_it(){
say("The "+BLK+BOLD+"Spirits of the Dark"+NORM+" subside.\n");
destruct(this_object());
return 1; }
