#define tp this_player()->query_name()

inherit "room/room";
int i;

reset(int arg){

  if(!arg){

  set_light(1);
  short_desc="BGC Tokyo";
  long_desc=
"You stand lost among the maze of streets which together make up the city\n"+
"of Tokyo.  Towering above you the majestic GENOM pyramid reigns sovereign\n"+
"over the skyline, while to the west you see the entrance to the famed\n"+
"'Hot Legs' dance club.  The city is alive with the sound of sirens and\n"+
"the screams of people.  Thundering from the club is the sound of heavy\n"+
"rock/techno music.\n";

items=({
 "genom","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "GENOM","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "skyline","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "street","The streets are reflections of neon against the black of the\n"+
  "wet boulevards, alive with faceless masses of humanity and clogged by a\n"+
  "multitude of dark rubber tires.",
 "city","You recognize the city to be Tokyo",
 "riot","The streets here are empty, but you hear the sounds of\n"+
  "explosions occurring throughout the city",
 "people","People are entering the club",
 "club","The 'Hot Legs' dance club",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg1.c","west",
 "/players/saber/tower/bgc/bg3.c","east",
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
