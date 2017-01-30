#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(3);
short_desc = YEL+"City Square"+NORM;
long_desc = YEL+
 "   Four large towers loom above the center of the courtyard.  Straw\n"+
 "and mud muck up the ground along the street from the many travelers\n"+
 "entering and leaving the city.  To the eastern part of the castle the\n"+
 "sounds of laughter and music is carried across the air from the local\n"+
 "pub.  In the western half, the market hagglers can be heard bartering\n"+
 "their wares.  There is a path leading to all directions from here.\n"+NORM; 

items = ({
  "city","The city appears to be small but very active",
  "towers","There is a tower in every corner of the city to protect it from\n"+
           "all sides of the land and ocean surrounding",
  "street","The street is made from cobbled-stones and lead to all\n"+
            "directions within the city",
  "cobbled streets","The streets are made from cobbled-stones and lead to all\n"+
                    "directions within the city",
  "courtyard","The courtyard is the main part of the city, it is where the\n"+
              "life begins for the city\n",
  "straw","The straw is put here to soak up the rain and mud from the streets\n"+
          "to help keep them clean",
  "mud","The mud is brought into the city from wagons and horses entering the gates",
  "ground","The ground consists of dirt and rock that hugs the streets on either side",
  "path","The path leads to many areas of the city",
    
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/courtyrd.c","backward",
    "players/nikki/Tintagel/Rooms/nhouse.c","forward",
    "players/nikki/Tintagel/Rooms/street1.c","left",
    "players/nikki/Tintagel/Rooms/street2.c","right",
});
}}

init() {
  ::init();
    add_action("looke","look");
    add_action("lok","l");
}

looke(str) {
  if(str != "east" && str != "west" && !str){
    return 0;
    }
  if(str == "east"){
    write(YEL+"A street leads to the pub and the eastern towers\n"+NORM);
    say(capitalize(TP->query_name())+" looks east.\n");
    return 1;
    }
  if(str == "west"){
    write(YEL+"A street leads to the market square and the western towers\n"+NORM);
    say(capitalize(TP->query_name())+" looks west.\n");
    return 1;
    }
}
lok(str) {
  if(str != "east" && str != "west" && !str){
    return 0;
    }
  if(str == "east"){
    write(YEL+"A street leads to the pub and the eastern towers\n"+NORM);
    say(capitalize(TP->query_name())+" looks east.\n");
    return 1;
    }
  if(str == "west"){
    write(YEL+"A street leads to the market square and the western towers\n"+NORM);
    say(capitalize(TP->query_name())+" looks west.\n");
    return 1;
    }
}