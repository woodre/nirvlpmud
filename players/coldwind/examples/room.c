#include "/players/coldwind/define.h"
inherit "room/room";

reset(arg) {
if(!present("giant", this_object())){
move_object(clone_object("/players/coldwind/examples/giant.c"), this_object());
move_object(clone_object("/players/coldwind/examples/giant.c"), this_object());        
	}
  
  if(arg) return;  
set_light(1);

short_desc = "Arabian Desert";
long_desc =
"     Before you is a graveyard. Thousands of signs mark\n"+
"the graves, spreading fear and despair in the atmosphere.\n"+
"The path continues south into the endless desert and north\n"+
"into the graveyard. Footprints of different sizes mark \n"+
"the sandy path while few cacti grow randomly around. \n"+
"Great mountain towers west, stopping anyone from proceeding.\n";

items = ({
  "signs",
  "Thousands of white stones have been cut and smoothed carefully.\n"+
  "Black inscriptions carved on the signs",
  "graves",
  "Very simple graves stretches in front of you like piles of sand.\n"+
  "White signs mark the graves spreading fear and despair in the atmosphere",
  "path",
  "A narrow sandy path cuts through the desert. You notice some footprints\n"+
  "marking the path",
  "footprints",
  "Footprints of different sizes marks the sandy path. Some don't appear to\n"+
  " be human marks",
  "cacti",
  "Green cacti grow around the path randomly like hands reaching out from\n"+
  " the ground",
  "mountain",
  "A big brown mountain stands proud to your west",
  "stones",
  "Thousands of white stones have been cut and smoothed carefully.\n"+
  "Black inscriptions carved on them",
  "inscriptions",
  "Black writings stamped on the white stones to specify the name\n"+
  " and the date of the buried",
  });

dest_dir = ({
  "/players/coldwind/workroom.c","west",
});
}          	