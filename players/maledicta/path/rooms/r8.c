#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
/*
if(!present("berserker_book")){
move_object(clone_object("/players/maledicta/closed/w/OBJ/trainer_berserker"), this_object());
}
*/
  if(arg) return;
set_light(1);

short_desc = "the southern hills";
long_desc =
"  The hills begin to grow smaller the further south they\n"+
"stretch. A path cuts through the center of them and \n"+
"continues to the south and north. The trees begin to grow\n"+
"thicker to the south as the land flattens out.\n";  

items = ({
  "hills",
  "The hills here are lower than those to the north and are\n"+
  "covered with thicker vegetation and trees",
  "vegetation",
  "Thick grasses and shrubs",
  "trees",
  "Tall trees with thick green canopies",
  "path",
  "A straight path that continues south to the forest and north\n"+
  "back into the tall hills",
  "land",
  "The forests of the south", 
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r7.c","north",
  "/players/maledicta/path/rooms/r9.c","south",
});

}


