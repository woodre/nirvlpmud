inherit "room/room";
#include <ansi.h>
#define MEMBER present("gym_membership", this_player())
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=(""+YELLOW+"Gold's Gym"+OFF+"");
   long_desc=
   "Welcome to Gold's Gym, the world's largest fitness center.\n"+
   "As a member of Gold's you are entitled to full use of all our facilities.\n"+
   "We offer a large number of machines that allow you to increase your strength,\n"+
   "as well as aerobic fitness. It is recommended you use all of\n"+
   "the machines to obtain the maximum benifits.\n"+
   "Remember:  Fitness is FUN!\n"+
   "",
   items=
   ({
    });
   dest_dir=
   ({
   "players/beck/room/street1.c","exit",
    });
   if(!present("golds_gym_machine", this_object())){
      move_object("/players/beck/object/golds_gym_machine.c", this_object());
   }
   if(!present("golds_gym_pool", this_object())){
      move_object("/players/beck/object/golds_gym_pool.c", this_object());
   }
if(!present("hanz", this_object())){
move_object("/players/beck/monster/hanz_franz.c", this_object());
}
}
query_no_fight(){ return 1; }
realm(){ return "NT";}

