inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!present("zapphod")){
  move_object(clone_object("players/persephone/monster/zap"), TOB);
 }
 if(!arg) {
  set_light(1);
  short_desc="A Bed Room";
  long_desc="You are standing in a poky little bedroom with\n" +
            "four beds, a small chest and a wardrobe that appears\n" +
            "to be full of scraps.  To the south is the exit\n" +
            "to the hall and in the middle of the room is standing\n" +
            "a froody looking dude. \n\n";
  items=({"beds","The beds actually look more like sacks than beds",
          "chest","Actually it is an old tea chest made into a chest of drawers",
          "wardrobe","This is actually a large box that someone\n" +
                     "through away",
          "actually not scraps but the wombles clothes",
        });    
  dest_dir=({ 
             "players/persephone/rooms/hala","south",
           });
 }
}
realm(){ return "NT";}
