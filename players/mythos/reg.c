#include "/players/mythos/closed/ansi.h"
inherit "room/room";

short() { return RED+"Healing Chamber"+NORM; }
reset(arg) {
  if(!arg) {
  set_light(1);
    long_desc =
    "You are in a small chamber\n"+
    "The chamber's walls are covered with glyphs of great power\n"+
    "This place was created by a powerful mage.\n"+
     "This place is a Holy place, a place of peace.\n"+
    "Rest your weary body and mind....\n"+
     "You are filled with the Calm of the Ages.\n";
  items = ({
    "out","The way out of the healing chamber",
  });

  dest_dir = ({
    "/players/mythos/entrance.c", "out",
  });
} }

no() { write("You may not do that here.\n"); return 1; }

init() { ::init();
   tell_object(this_player(),"The Chamber flashes as you enter....\n");
  write_file("/players/mythos/logs/heal",ctime(time())+" "+this_player()->query_real_name()+"\n");
  add_action("no","kill");
  add_action("no","fire",2);
  add_action("no","sonic",2);
  add_action("no","shock",2);
  add_action("no","missle",2);
  move_object(clone_object("/players/mythos/block.c"),this_player());
}

exit() { object heal; if(heal = present("h1r2",this_player())) destruct(heal); 
  if(this_player()) if(this_player()->query_money() < 0) this_player()->add_money(-this_player()->query_money());
}
