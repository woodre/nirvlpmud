#include "/players/snakespear/closed/ansi.h"
inherit "room/room";

reset(arg) {
   if(arg) return;
      
set_light(0);
short_desc="dark room";
long_desc=
 "  This is a seemingly dull room, but upon closer inspection, it's\n"+
 "far more than dull.  The walls are made of granite and the floor is\n"+
 "made of obsidian.  Looking to the left, two elaborately decorated\n"+
 "coffins are setting on raised platforms.  Both coffins are very large,\n"+
 "probably big enough for at least two people in each.  On the wall,\n"+
 "adjacent from the coffins is a fireplace, set deep into the granite\n"+
 "wall.  There is a couch and coffee table in front of the fireplace.\n"+
 "Placed quite nicely in the corner is a small cabinet, housing an\n"+
 "expensive looking stereo with many flashing lights.\n"+
 "There is a little sign by the door.\n";
      
items=({
     "coffins","Beautiful coffins made especially for Rachel and Snakespear",
     "sign","A neatly written sign on a piece of paper.  Perhaps you should"+
            "read it.",
});
      
}

realm() { return "NT"; }

init() {
   ::init();
   add_action("vamp","vamp");
   add_action("church","church");
   add_action("hotel","hotel");
   add_action("smell","smell");
   add_action("portal","portal");
   add_action("read_sign","read");
}
church() {
   call_other(this_player(),"move_player","church#room/church");
   return 1;
}
vamp() {
   call_other(this_player(),"move_player","vampires#players/nooneelse/black/guild_lower_hall");
   return 1;
}
smell() {
   write("You breath in deeply, inhaling the strong aroma of patchouli.\n");
   return 1;
}
hotel() {
   call_other(this_player(),"move_player","hotel#players/boltar/hotel/hotel");
   return 1;
}
portal() {
   call_other(this_player(),"move_player","portal#players/saber/ryllian/portal");
   return 1;
}
read_sign(str) {
   if(!str) {
     write("What do you want to read?\n");
     return 1;
   }
   if(str == "sign") {
     write("You can leave by choosing a place to leave to:\n"+
           "\tVampire Guild Hall -> vamp\n"+
           "\tHotel              -> hotel\n"+
           "\tBlack Chamber      -> portal\n"+
           "\tVillage Church     -> church\n");
    return 1;
    }
    else {
       write("You can't read the "+str+"\n");
       return 1;
    }
}

