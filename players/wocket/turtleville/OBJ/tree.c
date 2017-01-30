#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
if(arg) return;
set_id("tree");
set_alias("oak");
set_short(HIG+"A great oak tree"+NORM);
}

get(){ return 0; }

init(){
  add_action("engrave","carve");
  add_action("aread","read");
}

engrave(str){
if(!str){
  notify_fail("What would you like to carve?\nUsage: carve <msg>\n");
  return 0;
}
  write("You carve \""+str+"\" into the tree.\n");
  say(this_player()->query_name()+" carves into the tree.\n");
  write_file("/players/wocket/turtleville/OBJ/treelog","\t - "+str+"\n");
  return 1;
}

long(){
    write("This great oak has stood up against the test of time.  Many markings cover\n"+
          "this mighty tree as its leaves give wonderfull shade from the bright sun.\n"+
          "Perhaps you want to 'carve' a message into the tree or 'read' messages of\n"+
          "the past.\n");
    return 1;
}

aread(str){
if(!str || str != "tree"){
  notify_fail("What would you like to read?\n");
  return 0;
}
write(""+
  HIG+" ***                                                ***\n"+
   "*****                                              *****\n"+
    " *"+NORM+YEL+"|"+HIG+"*"+NORM+
    "   Some of the messages carved into the tree:   "+
    HIG+"*"+NORM+YEL+"|"+HIG+"*\n"+NORM+YEL+
     "  |                                                  |\n"+NORM); 
   tail("/players/wocket/turtleville/OBJ/treelog");
    return 1;
}
