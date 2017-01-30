#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
add_action("wave");add_verb("wave");
init_my_objects();
}


init_my_objects() {
  object tricorder;

  if (!present("tricorder")) {
    tricorder = clone_object("obj/treasure");
    call_other(tricorder,"set_id","tricorder");
    call_other(tricorder,"set_short","tricorder");
    call_other(tricorder,"set_name","tricorder");
    call_other(tricorder,"set_long","The Trouble with Tribbles\n");
    call_other(tricorder,"set_weight",1);
    call_other(tricorder,"set_value",12);
    move_object(tricorder,this_object());
  }
}

wave(str){
  object ob;

  if(str=="tricorder"){
     write(ob->query_name() + "\n");
     write("Level:\t" + ob->query_level() + "\n");
     write("HP:\t" + ob->query_max_hp() + "\n");
     write("AC:\t" + ob->query_ac() + "\n");
     write("WC:\t" + ob->query_wc() + "\n");
    }
  }


ONE_EXIT("players/rich/quest/tapedud.c", "west",
	 "Jetty",
	 "You are at a jetty. The waves rolls in from east.\n"+
	 "A small path leads back to west.\n", 1)
