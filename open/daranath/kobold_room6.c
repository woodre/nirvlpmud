inherit "room/room";
#include "/players/daranath/closed/ansi.h";
#define tp this_player()->query_name()

reset(arg){
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Village)");
    long_desc=
  "The clearing spreads about the opening within the DarkenWood all about\n"+
  "your current position. The dirt pathway leads into a small village,\n"+
  "mud huts set in a defensive manner. On the far side of the village\n"+
  "a stockade fence rises up to block any further passage. A large wooden\n"+
  "gate rests in the front of the stockade wall.\n";

items=({
  "shadows", "The shadows move as the wind moves the trees.\n",
  "fence", "The stockade fence surrounds the kobold keep to the west",
  "village", "The kobold village is used as a staging point for all the\n"+
             "kobold attacks of Nirvana",
  "huts", "The mud and straw huts are too small for you to enter",
 });


dest_dir=({
 "/players/daranath/clearing/kobold3.c","east",
 "/players/daranath/clearing/kobold7.c","west",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
  add_action("dar_west","west");
}

search() {
write("You find nothing about the kobold village.\n");
say (tp +" searches the area.\n");
  return 1;
}

dar_west() {
  if(present("berzerker")) {
  write("The berzerker's rage prevents you from leaving west.\n");
  return 1; }
return 0;
}
