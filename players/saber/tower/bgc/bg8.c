#define tp this_player()->query_name()

inherit "room/room";
int i;

reset(int arg){

  if(!arg){

  set_light(1);
  short_desc="BGC Tokyo";
  long_desc=
"You stand on the neon streets of midnight Tokyo,\n"+
"an ant among the colossal megacorporation arcologies\n"+
"and towering skyscraper fortresseses.  The city\n"+
"breathes the restless breath of the masses, alive\n"+
"with the sounds of voices, machinery, vehicles and\n"+
"music.  In the distance echoes the sharp crack of a\n"+
"gun.  Welcome to Tokyo, BGC style.\n";

items=({
 "megacorporation","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo.",
 "arcologies","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo.",
 "archlogy","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo.",
 "skyscraper","Towering skyscrapers line the skyline of Tokyo.",
 "fortress","Towering skyscrapers line the skyline of Tokyo.",
 "fortresses","Towering skyscrapers line the skyline of Tokyo.",
 "street","The streets are reflections of neon against the black of the\n"+
  "wet boulevards, alive with faceless masses of humanity and clogged by a\n"+
  "multitude of dark rubber tires.",
 "city","You recognize the city to be Tokyo",
 "portal","A portal leading to another realm",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg3.c","north",
 "/players/saber/tower/bgc/bg13.c","south",
 "/players/saber/tower/tower11.c","portal",
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
