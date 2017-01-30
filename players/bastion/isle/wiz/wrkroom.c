#include "std.h"
#include "/obj/door.h"

object bench;

#undef EXTRA_INIT
#define EXTRA_INIT \
     add_action("north", "north");

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     if(!bench) {
          bench=clone_object("players/bastion/obj/static");
          bench->set_name("workbench");
          bench->set_alias("bench");
          bench->set_short("workbench");
          bench->set_long(
               "The workbench is bestained by various past experiments.\n"+
               "Scralled notes and other items liter the counter.\n");
          bench->set_object(this_object());
          bench->set_summon("summon_daemon");
          bench->set_beat(4);
          move_object(bench, this_object());
          bench->start_check(); }
     bench->load_summon();
}

summon_daemon(arg) {
     object daemon, key;
     if(present("daemon")) {
          bench->unload_summon();
          return 1; }
     daemon=clone_object("players/bastion/monster/daemon");
     daemon->set_heart_beat(1);
     key=clone_object("obj/treasure");
     key->set_id("strange key");
     key->set_alias("key");
     key->set_short("A strange key");
     key->set_long("This is a strange key. Wonder where it fits?\n");
     key->set_value(10);
     key->set_weight(0);
     key->set_save_flag(0);
     say("A daemon steps from a puff of blue smoke!\n");
     move_object(daemon, this_object());
     transfer(key, daemon);
     call_out("dest_daemon", 25);
     bench->unload_summon();
}

dest_daemon() {
     object ob;
     ob=present("daemon");
     ob->self_destruct();
     return 1;
}

north() {
     if((this_player()->query_level()<21) &&
       !secure(this_player()->query_real_name())) {
          write("A strong magic force stops you.\n");
          say(call_other(this_player(),"query_name") +
             " tries to go through the field and fails.\n");
          return 1;}
     write("You wriggle through the force field...\n");
     this_player()->move_player("north#players/bastion/closed/workroom");
     return 1;
}

TWO_EXIT("players/bastion/isle/wiz/base_hall3", "southeast",
     "players/bastion/isle/wiz/base_hall2", "southwest",
     "Damian's Workroom",
     "You have entered a room lined with shelves of test tubes, beakers,\n"+
     "and other alchemical paraphenalia. A workbench occupies the center\n"+
     "of the room, atop which sit crumpled notes and unwashed laboratory\n"+
     "equipment. Doors lead southeast and southwest, while an archway of\n"+
     "shimmering blue light leads north.\n",
     1)

secure(str) {
     return(str=="shalee" || str=="damian" || str=="ozymandias" ||
       str=="saber" || str=="daranath");
}
