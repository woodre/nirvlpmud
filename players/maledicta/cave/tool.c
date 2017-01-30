inherit "obj/treasure";
#include "/players/maledicta/ansi.h"

reset (arg) {
if(!arg){

  set_id("tool");
  set_short("test tool");
  set_long("Usage: testroom\n");
    }
  }

  init(){
  ::init();
  add_action("set_cmd", "testroom");
  
}

set_cmd(){
   object test;
   test = clone_object("/players/maledicta/cave/rooms/randomcave.c");
   move_object(test, environment(this_player()));
   test->creation();
   test->renew_room();
   move_object(this_player(), test);
   write("done.\n");
   return 1;
 } 