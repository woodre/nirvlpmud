#include "/players/snakespear/closed/ansi.h"
inherit "room/room";
reset(arg){
   if(!arg){
      
set_light(3);
short_desc="Warning Room!";
long_desc=
 "  This room is rather large and empty.  There is a sign that\n"+
 "lays on the ground covered in rubble.  A portal spreads itself\n"+
 "along the far wall, almost mesmerizing you into a daze, as it\n"+
 "spins and turns endlessly within itself.\n";

items=({
     "sign","A marble sign with blood splattered on it and covered in\n"+
            "rubble from crumbling rock",
     "rubble","Bits and pieces of rock from inside the room and from\n"+
              "the sign itself",
     "ground","The floor is solid rock and has many cracks",
     "portal","The portal appears to be a mass of swirling energies.\n"+
              "You might be able to proceed through it",
     "wall","A steep wall with a mass of swirling energy in it",
     "cracks","There is one crack that has a light in it\n"+
              "Perhaps it would lead somewhere more lit, like a church",
     "blood","Old, dried up blood from earlier victims",
});

    
}  }

realm() { return "NT"; }

init() {
    ::init();
    write(HIW+"\n\n\n!!! WARNING !!! DANGER LURKS VERY NEAR!!!\n\n\n"+NORM);
    add_action("church","church");
    add_action("proceed","proceed");
    add_action("read","read");
}

church() {
      call_other(this_player(),"move_player","the room#room/church.c");
      return 1;
}
read(str) {
      if(!str) {
        write("Read what?\n");
        return 1; }
      if( str == "sign" ) { 
          write("       THIS IS YOUR LAST WARNING!\n\n"+
                "       IF YOU PROCEED, YOU ARE PLACING\n"+
                "       YOURSELF NEAR DEATH.  THERE WILL\n"+
                "       BE NO COMPENSATION FOR LOST GEAR,\n"+
                "       COINS, OR ANYTHING ELSE!!\n\n"+
                "       PROCEED WITH CAUTION!\n");
          return 1; }
      else {
          write("You can't read "+str+".\n");
          return 1; }                
}
proceed() {
      call_other(this_player(),"move_player","into danger#players/snakespear/zultayne/rooms/destiny.c");
      return 1;
}
