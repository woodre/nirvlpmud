inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define USER environment(this_object()) 
reset (arg) {
if(!arg){

  set_id("game");
  set_short("a "+HIR+"tag"+NORM+" game");
  set_long("Usage: tag <who>\n"+
           "Note: you must be in the same room as the person you tag.\n");
  set_weight(0);
  set_value(0);
    }
  }

  init(){
  ::init();
  
  write(
  "\n\n\n You just got "+HIR+"TAGGED"+NORM+", YOU'RE IT!!!\n"+
  "Usage is: tag <who>.\n\n");
  add_action("set_cmd", "tag");
}

set_cmd(string str){
object ob;
ob = find_living(str);	
if(!str){ write("Tag who??\n"); }
if(present(ob, environment(USER))){
tell_object(USER,
"You tagged "+ob->query_name()+"!!!\n");
move_object(this_object(), ob);	
return 1;
    }
write("That person isn't present.\n");
return 1;
}

drop(){
write("The game destructs as you drop it.\n");	
destruct(this_object());
return 1; }
