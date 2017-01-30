#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure";

reset(arg){
  if(arg) return;
  set_id("branch");
  set_id("w_branch");
  set_short("A broken branch");
  set_weight(random(3)+1)
  set_value(50);
}

init(){
  add_action("build_fire","build");
}

build(str){
  if(str != "fire"){
    notify_fail("What would you like to build?\n");
    return 0;
  }
  if(!present("w_branch 3",this_player())){
    write("You dont have enough branches to build a fire.\n");
    return 1;
  }
  write("You begin to build a fire.\n");
  fire = clone_object("/players/wocket/f_forest/OBJ/fire.c");
  fire->set_time(200);
  move_object(fire,environment(this_player()));
  destruct(present("w_branch 3",this_player()));
  destruct(present("w_branch 2",this_player()));
  destruct(this_object());
  return 1;
}
