#define tp this_player()->query_name()
inherit "room/room";
int t;
int PAPER;
reset(int arg){
 if(!present("torch")){
  move_object(clone_object("/players/saber/effects/torch.c"),this_object());
}
 if(!present("saber_swamp_door"))  {
  move_object(clone_object("/players/saber/stuff/dardoor.c"),this_object());  }
 if(!arg){
PAPER = 1;
  set_light(1);
 short_desc="Tower Landing 4";
long_desc=
 "A cold, damp stone room.  It is dimly lit by flickering torches.\n"+
 "The staircase continues up into the darkenss.  There is a sign on\n"+
 "the wall.\n";

items=({
  "sign","These portals lead to powerful demi planes",
 "torch","A blazing torch.\n"+
   "It is secured to the wall",
  "door","A solid archway of worked stone",
 "staircase","A solid stone stairway asending up into the darkness",
 "portal","A dark stone portal filled with a hazy blue aura",
  "torches","One of many blazing torches.\n",
     "It is secured to the wall",
 });

  dest_dir=({
 "/players/saber/tower/tower16.c","down",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
if(PAPER == 1) {
  write("You find a scrap of water soaked paper.\n");
  move_object(clone_object("/players/saber/stuff/darnote.c"),this_player());
say (tp +" searches the area\n");
  PAPER = 0;
 return 1;  }
write("You search and find nothing.\n");
return 1;
}
