#define tp this_player()->query_name()
inherit "room/room";
int i;
int t;
reset(int arg){
if(!present("hades")) {
 move_object(clone_object("/players/saber/effects/hades.c"),this_object());
 }
if(!present("manes")) {
  for(i=0;i<6;i++){
move_object(clone_object("/players/saber/monsters/manes.c"),this_object());
}
 if(!arg){
  set_light(1);
 short_desc="Hades Rift";
long_desc=
 "You stand in a blazing chamber constructed of fiery walls.  Through\n"+
 "the smoke and flames of hazy crimson illumination you think you see\n"+
 "the flicker of movement.\n";

items=({
 "illumination","A crimson red light shed by the flames",
 "movement","You believe you see movement from within the flames",
 "flames","Deep crimson flames which dance in chaotic patterns.\n"+
   "You believe that you see the hazy images of people screaming within",
 "room","Walls of blazing fire form this room.\n"+
   "You see hazy images of people screaming within",
 "portal","A dark stone portal filled with a hazy blue aura",
 "floor","The floor is covered with crimson flames",
 });

  dest_dir=({
 "/players/saber/tower/tower6.c","portal",
 "/players/saber/tower/tower9+1.c","north",
           });
  }   }
}
init(){
 ::init();
  add_action("search","search");
add_action("hellfire","hellfire");
add_action("demon","demon");
add_action("chain","chain");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

hellfire() {
  write("You cannot do that here.\n");
return 1;  }
chain() {
  write("You cannot do that here.\n");
   return 1;  }
demon (str) {
   write("You cannot do that here.\n");
   return 1;   }
