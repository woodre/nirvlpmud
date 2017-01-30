#include "/players/coldwind/define.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);


long_desc =  
""+WHT+"    You stand in a strange place.  Everything around you is made\n"+
       "of clear transparant crystal, except for some crystalline dust\n"+
       "that covers the ground of the plane."+NORM+"\n"; 
                           

items = ({
  "dust",  "A Small layer of tiny crytalline particles spreads covering\n"+
           "the ground",
  "ground", "You are stepping on a clear crystal ground that has been\n"+
            "covered by crystalline dust",
});
}
init() {
  ::init();
  add_action("boo","e");
  add_action("boo","w");  
  add_action("boo","s");
  add_action("boo","n");
  add_action("boo","ne");
  add_action("boo","se");
  add_action("boo","sw");
  add_action("boo","nw");
}
short(){
 return ""+HIW+"Crystalline Plane"+NORM+"";
}
realm() {
  return "NT";
}

boo() {
 move_object(this_player(),"/players/coldwind/crystal/rooms/"+random(33)+".c");
  command("look",this_player());
  return 1;
}
