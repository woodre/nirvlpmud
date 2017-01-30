#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure";
object fire;

reset(arg){
  if(arg) return;
  set_id("w_branch");
set_alias("branch");
  set_short("A broken branch");

 set_weight(random(3)+1);
  set_value(50);
}

init(){
  add_action("build_fire","build");
}

build_fire(str){
  if(str != "fire"){
    notify_fail("What would you like to build?\n");
    return 0;
  }
  if(!present("w_branch 3",this_player())){
    write("You dont have enough branches to build a fire.\n");
    return 1;
  }
  write("You begin to build a fire.\n");
 fire = clone_object("/players/jaraxle/3rd/alt/items/fire.c");
  fire->set_time(200);
  move_object(fire,environment(this_player()));
  destruct(present("w_branch 3",this_player()));
  destruct(present("w_branch 2",this_player()));
  destruct(this_object());
  return 1;
}

void long(string arg)
{
   ::long(arg);
   if(this_player()->query_attrib("int") > random(150))
return (write("If you have enough branches you can "+BOLD+"build"+NORM+" a "+BOLD+"fire"+NORM+".\n"));
}
