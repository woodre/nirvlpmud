#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("roc")){
move_object(clone_object(ROOT+"mon/roc.c"),this_object());
}
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Plateau"+NORM);
long_desc=
"Nestled between a couple of oversized boulders, a large nest seems to have been\n"+
"built here. Entire branches instead of twigs have been used to build the nest\n"+
"and you seem to be able to pick out finished beams and long pieces of cut wood.\n"+
"Whatever built this nest was large and powerful.\n";

items=({
"boulders","Two gigantic boulders provide shelter for the nest",
"branches","It looks like entire branches have been pulled from trees to make the nest",
"beams","Whatever made this nest pulled apart houses and buildings to find wood",
"wood","Whatever made this nest pulled apart houses and buildings to find wood",
"twigs","There is not a single twig within the nest",
"nest","Whatever made this nest needed a lot of large wood to finish it.\n"+
     "It must have pulled apart homes and other buildings to get enough materials",
"plateau","You are on top of the Gundar plateau",
    });

    dest_dir=({
  ROOT+"plateau1.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The nest itself is empty, devoid of food and eggs.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
