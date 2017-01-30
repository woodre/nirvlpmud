#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    The desert spreads around you except for the rocky hill that \n"+
"stands to the south blocking you from going that way.  The sun glares\n"+
"at you angrily and you feel the hot sand being thrown at you by an\n"+
"invisible force as you find yourself in what looks like a forbidden area.\n"+
"An old sign was knocked down beside a stone road that was built with\n"+
"great care.  The stone road starts here and heads deep into the heart\n"+
"of the infinite desert.\n";

items = ({
  "desert",
  "The yellow sandy dunes expands in every direction",
  "dunes",
  "The accumulation of sand through the years have created small sandy hills.",
  "sand",
  "Hot golden sand cover the face of desert. The wind blows the\n"+
  "sand directly at you",
  "sun",
  "The sun looks angry as it glows hot sending it's burning sunrays\n"+
  "directly at you",
  "road",
  "The stone road starts here leading north toward the desert",
  "rocks",
  "The brown rocks bonds together high forming a rocky hill",
  "hill",
  "A rocky hill stands 90 feet tall with few cracks toward the bottom",
  "sign",
  "An old sign thrown on the side of the road with negligence",
  "cracks",
  "On a closer look, you notice a crack big enough for you\n"+
  "to "+BOLD+"squeeze"+NORM+" yourself south through",   
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v8.c","north",
});

}
init(){
  ::init();
  add_action("squeeze_hill", "squeeze");
  add_action("read_sign", "read");
  }
  
  squeeze_hill(string str){
  if(!str){ write("Squeeze yourself where?\n"); return 1; }
        if(str == "south" || str == "in" || str == "hill" || str == "through hill" || str == "rocks" || str == "through rocks" || str == "crack") {
move_object(this_player(), "/players/coldwind/desert/rooms/v5.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}	
}
read_sign(string str){
  if(!str){ write("Read what?\n"); return 1; }
	if(str == "sign"){
write(BOLD+" To  T  e  Cav rn  of A ' EL' Ma s  r"+NORM);
say(""+tpn+" reads the sign!");
return 1;
}
}
