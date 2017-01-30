#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int c;

reset(int arg){
if(!present("child")) {
 c = random(4);
if(c == 0) {move_object(clone_object(ROOT+"folk/chld_shadow.c"),this_object()); }
if(c == 1) {move_object(clone_object(ROOT+"folk/chld_light.c"),this_object()); }
if(c == 2) {move_object(clone_object(ROOT+"folk/chld_flame.c"),this_object()); }
if(c == 3) {move_object(clone_object(ROOT+"folk/chld_death.c"),this_object()); }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Children's Pathway"+NORM+" (north, south)\n"+
"               "+BOLD+"Scimitar Alley"+NORM+" (east)\n"+
"The cobble stone roadway that makes up Children's Pathway has been repaired\n"+
"recently, along with most of what is now called City Ward. The citizens are\n"+
"taking back thier homes, and this north/south roadway is no exception.\n";

    items=({
"roadway","The roadway itself of made up of cobble stones strong enough for wagons\n"+
     "to travel across all day long",
"stone","The cobble stone roadway was recently rebuilt",
"stones","The cobble stone roadway was recently rebuilt",
    });

    dest_dir=({
      "/players/daranath/qualtor/child_path3.c","north",
      "/players/daranath/qualtor/child_path1.c","south",
      "/players/daranath/qualtor/scim_alley.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
write("The roadway has seen a lot of traffic recently, given the rebirth of\n"+
      "City Ward and Qual'tor in general.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


