#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";
int a;

reset(int arg){
a = random(4);
if(!present("gravemon")){
if(a < 2) {
move_object(clone_object(ROOT+"mon/morgue_toad.c"),this_object());
}
if(a == 2) {
move_object(clone_object(ROOT+"mon/frightcrawler.c"),this_object());
move_object(clone_object(ROOT+"mon/frightcrawler.c"),this_object()); }
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BLK+BOLD+"Dark Graveyard"+NORM+")");
    long_desc=
 "Deep within the old garden in the ruined city of Qual'tor, this area was used\n"+
 "to honor the knights of the king himself. Whenever a single knight gave his\n"+
 "life to the crown, he was given a tombstone here.\n"+
 "There are several tombstones around you, all former heroes of the crown.\n";

    items=({
"keep","The ruined keep is a sad reminder of the days of old",
 "gravel","The gravel itself is dark grey in color",
 "path","The gravel path is simple in design, leading north and south",
 "pathway","The gravel path is simple in design, leading north and south",
 "garden","The ruins of Qual'tors garden lies north",
 "lords","The Lords of Qual'tor are long since gone",
 "spot","The garden was a favorite spot of the king",
    });

    dest_dir=({
  ROOT +"garden_shrine.c","north",
  ROOT +"garden2.c","east",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search() {
write("The tombs have recently been disturbed.\n");
return 1;
 }

