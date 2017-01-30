#define tp this_player()->query_name()

inherit "room/room";
int i;

reset(int arg){

if(!present("nene"))  {
move_object(clone_object("/players/saber/monsters/nene.c"),this_object());
        }

  if(!arg){

  set_light(1);
  short_desc="BGC Tokyo";
  long_desc=
"You stand lost among the maze of streets which together make up the\n"+
"city of Tokyo.  Towering above you to the south the majestic GENOM\n"+
"pyramid reigns sovereign over the skyline.  The city is alive with\n"+
"the sound of sirens and the screams of people.  There appears to be\n"+
"some sort of riot going on!\n";

items=({
 "genom","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "GENOM","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "skyline","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "skyscraper","Towering skyscrapers line the skyline of Tokyo.",
 "street","The streets are reflections of neon against the black of the\n"+
  "wet boulevards, alive with faceless masses of humanity and clogged by a\n"+
  "multitude of dark rubber tires.",
 "city","You recognize the city to be Tokyo",
 "riot","The streets here are empty, but you hear the sounds of\n"+
  "explosions occurring throughout the city",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg13.c","north",
 "/players/saber/tower/bgc/bg17.c","west",
 "/players/saber/tower/bgc/bg23.c","south",
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
