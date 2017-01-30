inherit "obj/treasure";
#include "/players/maledicta/ansi.h"

reset (arg) {
if(!arg){

  set_id("tool");
  set_short("set tool");
  set_long("Usage: set\n");
    }
  }

  init(){
  ::init();
  add_action("set_cmd", "set");
}

set_cmd(string str){
object ob;
ob = find_living(str);	
if(ob){
    ob->set_guild_rank(4);	
   return 1;
write("not on.\n");
return 1;
}
