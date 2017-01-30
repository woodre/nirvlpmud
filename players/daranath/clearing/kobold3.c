inherit "room/room";
#include <ansi.h>
#define tp this_player()->query_name()

reset(arg){
 if(!present("kobold")) {
   int a;
   a = 0;
   while(a<5){
   int b;
   b = random(7);
if(b == 0) move_object(clone_object("/players/daranath/mons/kobold0.c"),this_object());
if(b == 1) move_object(clone_object("/players/daranath/mons/kobold1.c"),this_object());
if(b == 2) move_object(clone_object("/players/daranath/mons/kobold2.c"),this_object());
if(b == 3) move_object(clone_object("/players/daranath/mons/kobold3.c"),this_object());
if(b == 4) move_object(clone_object("/players/daranath/mons/kobold4.c"),this_object());
if(b == 5) move_object(clone_object("/players/daranath/mons/kobold5.c"),this_object());
if(b == 6) move_object(clone_object("/players/daranath/mons/kobold6.c"),this_object());
   a++;
   }
}

    if(!arg){

    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Kobold Village)");
    long_desc=
  "The darkness of the surrounding forest lessens as you step into an\n"+
  "opening within the woods. The dirt pathway leads into a small village,\n"+
  "spreading out before you. On the far side of the village a stockade fence\n"+
  "rises up to block any further passage. A large wooden gate rests in the\n"+
  "front of the stockade wall.\n";

items=({
  "shadows", "The shadows move as the wind moves the trees.\n",
  "stockade", "The stockade fence surrounds the fortress of the kobold king",
  "wall", "The stockade fence surrounds the fortress of the kobold king",
  "village", "The village belongs to the kobold tribe which has taken\n"+
             "control of the clearing here within the DarkenWood",
 });


dest_dir=({
 "/players/daranath/clearing/kobold4.c","north",
 "/players/daranath/clearing/kobold5.c","south",
 "/players/daranath/clearing/kobold2.c","east",
 "/players/daranath/clearing/kobold6.c","west",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the Kobold Village.\n");
say (tp +" searches the area.\n");
  return 1;
}

