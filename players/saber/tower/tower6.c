#define tp this_player()->query_name()
inherit "room/room";
int t;
status flag;
reset(int arg){
 if(!present("torch")){
  move_object(clone_object("/players/saber/effects/torch.c"),this_object());
}
 if(!arg){
  set_light(1);
 short_desc="Tower Landing";
long_desc=
 "The echo of silence pervades your senses and creeps through\n"+
 "your consciousness as you glance in wonder about the chamber.\n"+
 "You stand in a cold, damp room of worked stone.  It is dimly\n"+
 "illuminated by flickering torches which cast strange shadows\n"+
 "across the chamber walls.  A sign hangs upon the wall, and a\n"+
 "staircase ascends into the darkness above.\n";

items=({
 "sign","These portals lead to demi planes.\n"+
    "The portals to the north and south lead to low powered demi planes.\n"+
  "The portal to the east leads to a medium powered demi plane.\n"+
    "The portal to the west leads to a high powered demi plane.",
 "torch","A blazing torch.\n"+
   "It is secured to the wall",
  "door","A solid archway of worked stone",
 "staircase","A solid stone stairway asending up into the darkness",
 "portal","A dark stone portal filled with a hazy blue aura",
  "torches","One of many blazing torches.\n",
     "It is secured to the wall",
 });

  dest_dir=({
 "/players/saber/tower/tower9.c","north",
 "/players/saber/tower/tower14.c","east",
 "/players/saber/tower/tower10+01.c","south",
 "/players/saber/tower/tower20.c","west",
 "/players/saber/tower/tower11.c","up",
 "/players/saber/tower/tower2.c","down",
           });
  }   }
init(){
 ::init();
  add_action("go_east", "east");
  add_action("search","search");
}

go_east() { write("\
That room has been blocked off.  If you were looking for something\n\
in particular, try searching for it elsewhere.\nSorry for the inconvenience,\n\
-Earwax 08/17/06\n");
  return 1;
}

/* 08/17/06 Earwax: Yanked the bar fight, this is consolation prize */
search() {
say (tp +" searches the area\n");
  if (flag) {
 write("You find nothing\n");
  return 1;
  }
  write("You find a gem!\n");
  move_object(clone_object("/players/saber/gems/amber.c"), this_player());
  flag = 1;
 return 1;  }
