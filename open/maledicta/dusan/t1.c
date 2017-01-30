#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define guard1 "/players/maledicta/town/mobs/guard.c"
#define guard2 "/players/maledicta/town/mobs/guard2.c"
inherit "room/room";
int i;

reset(arg) {
  if(!present("civilian", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }
  }	
if(!find_object(guard1)){
move_object(guard1, this_object());
}
if(!find_object(guard2)){
move_object(guard2, this_object());
}		
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  This is the town of Derellia IV. Lining the walls to either side of you\n"+
"are numerous tall trees, their huge leaved canopies blocking the sight of\n"+
"the defense wall and turrets, almost leaving a sense of nature to this small\n"+
"bustling town. Looking out into the town you see small buildings and houses\n"+
"stretching out within the confines of the walls.  Ahead to the north can be\n"+
"seen a huge structure of white and shining steel. To the east and west are\n"+
"small roads that circle the towns perimeter. Behind you to the south is a\n"+
"large gate.\n";

items = ({
  "walls",
  " Barely seen through the trees lining them, they are made of thick plates\n"+
  "of steel and enshrouded with a field of energy",
  "energy",
  " Created to keep out intruders and strengthen the towns defenses, it glimmers\n"+
  "in the light of day",
  "trees",
  "Tall and healthy, they stand like guardians over the towns small houses and\n"+
  "buildings",
  "wall", 
  "Made of steel, it surrounds the entire town protectively",
  "walls",
  "Made of steel, they surround the entire town protectively",
  "turrets",
  "Defense turrets designed to ward off attacks from land or air. They are\n"+
  "very large and most likely powerful",
  "buildings",
  "Made from some type of white stone, they are all small to medium in size\n"+
  "with gardens and grass surrounding them",
  "houses",
  "You look at the houses and see that most are small in size, with small gardens\n"+
  "and yards surrounding them. They leave you with a quaint and warm feeling",
  "structure",
  "Towering high overhead, this single structure is the one most remarkable sight\n"+
  "in all the land. Its impressive battlements are topped with statues and fine\n"+
  "golden decorations. The entire height of its being is embedded with small and\n"+
  "medium sized windows of beautiful colored glass. A path lined with several\n"+
  "statues of men and women leads up to a huge oak door. A tall glass dome can be\n"+
  "seen from here at its top",
  "roads",
  "Clean and perfectly kept, these roads are made of stone and seem to circle\n"+
  "the entire town",
  "gate",
  "It is made of steel and reinforced with a shining field of energy. Perhaps\n"+
  "you could 'exit' there?"
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t4.c","north",
  "/players/maledicta/town/rooms/t2.c","east",
  "/players/maledicta/town/rooms/t3.c","west"
  
});

}

init(){
  ::init();
  add_action("exit_area", "exit");
  this_player()->set_fight_area();
}

exit_area(){
move_object(this_player(), "/players/maledicta/castle/rooms/m5.c");
tell_room(environment(tp), tpn+" arrives.\n", ({tp}));
command("look", this_player());
return 1;
}	

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	
