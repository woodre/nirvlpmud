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
"You stand lost among the maze of streets which together make up the city of\n"+
"Tokyo.  Towering above you is the majestic GENOM pyramid.  Looking up, you\n"+
"believe that you can see some sort of movement at the top of the pyramid.\n"+
"In the distance you hear screaming sirens and the echoes of a city in chaos.\n"+
"There appears to be some sort of riot going on!\n";

items=({
 "genom","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "GENOM","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "skyline","The majestic GENOM pyramid reigns sovereign over the skyline of Tokyo",
 "skyscraper","Towering skyscrapers line the skyline of Tokyo.",
 "street","The streets are reflections of neon against the black of the\n"+
  "wet boulevards, alive with faceless masses of humanity and clogged by a\n"+
  "multitude of dark rubber tires.",
 "city","You recognize the city to be Tokyo",
 "movement","It looks like there is a fight in progress at the top\n"+
  "of the GENOM pyramid",
 "riot","The streets here are empty, but you hear the sounds of\n"+
  "explosions occurring throughout the city",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg18.c","north",
 "/players/saber/tower/bgc/bg24.c","east",
 "/players/saber/tower/bgc/bg26.c","up",
           });
    }    }


init(){
 ::init();
  add_action("search","search");
  add_action("up","up");
        }

search() {
 write("You find nothing\n");
 say (tp +" searches the area\n");
 return 1;  }

up()  {
if(!present("boomer"))  {
call_other(this_player(),"move_player","up#players/saber/tower/bgc/bg26.c");
  return 1;
        }
write("The boomer blocks your way.\n");
return 1;
        }
