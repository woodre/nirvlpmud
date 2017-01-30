#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!present("torch")){
  move_object(clone_object("/players/saber/effects/torch.c"),this_object());
}
 if(!present("pool"))  {
  move_object(clone_object("/players/saber/stuff/darpool.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Tower Landing 3";
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
 "/players/saber/tower/tower11.c","down",
 "/players/saber/tower/tower21.c","up",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("take_key","get");
}

search() {
  if(t) { write("You find nothing.\n"); return 1;}
  write("You see something shining within the pool of water.\n");
say (tp +" searches the area\n");
 return 1;  }

take_key(str)  {
  if(t) return 0;
  if(str == "key" || str=="key from puddle" || str=="key from water") {
  t=1;
write("You reach into the muck and pull out the silver key.\n");
say(tp+" reaches into the filth...\n");
move_object(clone_object("/players/saber/stuff/darkey.c"),this_player());
  return 1;
        }
        }
