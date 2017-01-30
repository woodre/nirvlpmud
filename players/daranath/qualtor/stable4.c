#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";
   int a;

reset(int arg){
   a=0;
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Stables)");
    long_desc=
     "A wooden flooring and walls make for a stuffy enclosure that is\n"+
     "to house visiting horses here in the city. A layer of hay is\n"+
     "spread across the floor, making the area somewhat comfortable.\n";

    items=({
     "hay","The hay covers the wooden floor of the stable, giving\n"+
           "horses both a place to eat and sleep. Perhaps you could\n"+
          ""+YEL+"<"+NORM+" rustle "+YEL+">"+NORM+" some of the hay to see what is under it",
     "floor","You cannot see the floor because of the hay",
     "walls","The walls are made of a normal wood",
    });

    dest_dir=({
      "/players/daranath/qualtor/stable2.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("rustle","rustle");
    }

rustle(){
  if(a<2) {
move_object(clone_object("/players/daranath/qualtor/mon/scurry.c"),this_object());
write("When you move the hay, something scurries away from you.\n");
say("As "+tp+" digs through the hay, something scurries about the area\n");
    a++;
 return 1;
}
  if(a>1) {
write("You find nothing within the flooring of the stable.\n");
say(tp +" digs through the hay, finding nothing.\n");
 return 1;
    }
}

search() {
write("You find nothing within the stable of interest.\n");
say(tp +"searches the area.\n");
 return 1;
}
