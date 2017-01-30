#define tp this_player()->query_name()

inherit "room/room";
int i;

reset(int arg){

if(!present("celia"))  {
move_object(clone_object("/players/saber/monsters/celia.c"),this_object());
        }

  if(!arg){

  set_light(1);
  short_desc="BGC Tokyo";
  long_desc=
"You stand atop the majestic GENOM pyramid.  Below you the maze\n"+
"of streets which together make up the city of Tokyo stretch off\n"+
"to the horizon.  In the distance you hear screaming sirens and\n"+
"the echoes of a city in chaos.\n";

items=({
 "genom","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "GENOM","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "street","The streets are reflections of neon against the black of the\n"+
  "wet boulevards, alive with faceless masses of humanity and clogged by a\n"+
  "multitude of dark rubber tires.",
 "city","You recognize the city to be Tokyo",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg26.c","north",
 "/players/saber/tower/bgc/bg28.c","east",
           });
    }    }


init(){
 ::init();
  add_action("search","search");
        }

search() {
 write("You find nothing\n");
 say (tp +" searches the area\n");
 return 1;  }
