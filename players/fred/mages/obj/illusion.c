
#include "/players/fred/mages/defs.h"
inherit "obj/treasure";

init(){
::init();
        
	add_action("kill","kill");
	add_action("kill","punch");
	add_action("kill","kick");
}

reset(arg) {
set_short("A generic illusion");
set_alias("illusion");
set_long("Some illusion created by some Black Circle Mage.\n");
set_value(1);
}

kill(str){
 if(str == "illusion"){
   write("Your wild attack destroys "+TO->short()+".\n");
   say(capitalize(TPN)+"'s wild attack destroys "+TO->short()+".\n");
   destruct(TO);
   return 1;
   }
 return 0;
}

get(){ return; }
