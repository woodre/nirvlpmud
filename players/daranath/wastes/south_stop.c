#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Swamp"+NORM);
long_desc=
"A deep, murky swamp seems to start here, leading from the Gundar plateau south\n"+
"into the unknown. Dark patches of slimy water are everywhere, hiding all sorts\n"+
"of critters from view. There doesn't seem to be a safe pathway through the\n"+
"swamp, meaning your only option is to turn back north\n",

items=({
"swamp","The swamplands here in the Gundar area have only been a recent problem.\n"+
     "Another residual effect from the magical warfare that rocked this land",
"plateau","The gundar plateau rises up into the sky to the north of the swamp",
"critters","The deep, murky waters can easily hide all sorts of creatures",
"water","The dark water is covered in a thick layer of slime",
    });

    dest_dir=({
  ROOT+"plateau_base.c","north",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("None of the thick slime across the water is disturbed, leading you to believe\n"+
      "that nothing has passed this area recently.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
