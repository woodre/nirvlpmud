#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/sal_king.c"),this_object());
move_object(clone_object(ROOT+"mon/pheonix.c"),this_object());
move_object(clone_object(ROOT+"mon/sal_priest.c"),this_object());
move_object(clone_object(ROOT+"mon/sal_assassin.c"),this_object());
move_object(clone_object(ROOT+"mon/sal_war.c"),this_object());
move_object(clone_object(ROOT+"mon/sal_war.c"),this_object());
move_object(clone_object(ROOT+"mon/sal_war.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (RED+"Salamander Throne Room"+NORM);
long_desc=
"A large rocky platform floating amidst a sea of lava, this area is most unusual\n"+
"in appearance. The rock has been molded at one end to simulate a throne room\n"+
"with a large, coal throne upon a wide dais. There is enough room upon the \n"+
"floating rock to hold a good number of individuals, making it seem that\n"+
"someone keeps court here.\n";

items=({
"throne","The rocky throne looks comfortable enough, for sitting on coal",
"rock","The platform of rock floats here amidst the lava, but never seems to melt",
"platform","The platform of rock floats here amidst the lava, but never seems to melt",
"dais","A large dais has been carved or molded from the rock, lifting the throne",
"coal","The throne is made up of pure coal... rather ugly",
"court","The throne makes the rock seem like a royal courtroom",
    });

    dest_dir=({
  ROOT+"lava5.c","east",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("There is nothing of interest about the coal throne.\n");
  say(tp +" tries to search the area.\n");
 return 1;
}

realm() {return "NT"; }
