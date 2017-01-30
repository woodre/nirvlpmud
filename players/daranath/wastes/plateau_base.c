#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= ("Base of the "+BLK+BOLD+"Gundar Plateau"+NORM);
long_desc=
"Standing within a small open area at the base of the Gundar Plateau, the mountain\n"+
"itself rises up into the sky before you. A small trail heads up the side of the\n"+
"plateau, while the open area itself extends to the north and south.\n"+
"\nA small wooden sign has been placed here.\n";

items=({
"area","The small open area is very flat and covered in thick mud",
"mud","The thick mud seems to be the result of the swampy area to the south",
"mountain","The top of the mountain has been sheared off, perhaps by magic",
"plateau","The plateau rises up before you, a small trail making easy access for \n"+
     "those who want to climb it",
"footprints","A variety of footprints have been perfectly preserved in the mud.\n"+
     "There are too many to accuratly track a single kind or type",
"sign","The wooden sign reads:\n"+
     ""+BOLD+"\n Beware: Plateau is infested by centipedes"+NORM+"\n\n"+
     "A signature on the sign seems to have worn off",
"north","A small clearing sits to the north",
"south","Looks like a swampy area starts to the south from here",
    });

    dest_dir=({
  ROOT+"north_stop.c","north",
  ROOT+"south_stop.c","south",
  ROOT+"east_path5.c","west",
  ROOT+"plateau_entry.c","up",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("dar_up","up");
}

search(){
write("The thick mud that covers the area preserves footprints for a long time.\n");
  say(tp +" searches the area.\n");
 return 1;
}

dar_up(){
write("\nYou make the long climb up the side of the plateau.\n\n");
return 0;
}

realm() {return "NT"; }
