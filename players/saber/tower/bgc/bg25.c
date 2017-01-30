#define tp this_player()->query_name()

inherit "room/room";
int i;

reset(int arg){

if(!present("boomer"))  {
move_object(clone_object("/players/saber/monsters/boomer2.c"),this_object());
        }

  if(!arg){

  set_light(1);
  short_desc="BGC Tokyo";
  long_desc=
"You stand in a narrow alley lost among the maze of streets.  Towering\n"+
"above you to the south the majestic GENOM pyramid reigns sovereign over\n"+
"the skyline.  In the distance you hear screaming sirens and the echoes\n"+
"of a city in chaos.\n";

items=({
 "genom","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "GENOM","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "skyline","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "street","The streets are reflections of neon against the black of the\n"+
  "wet boulevards",
 "city","You recognize the city to be Tokyo",
 "riot","The streets here are empty, but you hear the sounds of\n"+
 "alley","You are in a dead end alley",
  "explosions occurring throughout the city",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg20.c","north",
 "/players/saber/tower/bgc/bg24.c","west",
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
