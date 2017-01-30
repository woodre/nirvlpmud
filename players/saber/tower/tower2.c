#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!present("torch")){
  move_object(clone_object("/players/saber/effects/torch.c"),this_object());
}
 if(!arg){
  set_light(1);
 short_desc="Tower Foyer";
long_desc=
 "The echo of silence pervades your senses and creeps through\n"+
 "your consciousness as you glance in wonder about the chamber.\n"+
 "You stand in a cold, damp room of worked stone.  It is dimly\n"+
 "illuminated by flickering torches which cast strange shadows\n"+
 "across the chamber walls.  A sign hangs upon the wall, and a\n"+
 "staircase ascends into the darkness above.\n";

items=({
 "sign","        Welcome to the tower of portals. This tower was originally\n"+
 "constructed by the arch magi Cet Cian ap un Hanbadarn, wizard of the\n"+
 "Way of the Stone.  The portals within were built to give easy access\n"+
 "to the many dimensions through which Cian frequently traveled.  With\n"+
 "his untimely death, I, Saber, Keeper of the Secrets of the Vampire\n"+
 "Cult, Master Doppleganger, Spellsinger of the Bardic tradition and\n"+
 "wizard of the Realm of Ryllian have opened this tower for general use\n"+
 "to those bold enough to travel through.  These portals lead to many\n"+
 "alternate and parallel dimensions, so caution is advised until the\n"+
 "local customs have been mastered.  Due to the unstable nature of the\n"+
 "portals, you will be unable to journey any great distance from them.\n"+
 "        For your convience, there is a shop located to the north, and\n"+
 "a pub to the south.  Please note that the management takes no\n"+
 "responsibility for the actions of the inhabitants of the portals.\n"+
 "        **  Enter at your own risk  **\n",
 "torch","A blazing torch.\n"+
   "It is secured to the wall",
  "door","A solid archway of worked stone",
 "chamber","The chamber has been constructed from worked stone",
 "room","The room has been constructed from worked stone",
 "ground","The chamber floor has been constructed from worked stone",
 "staircase","A solid stone stairway asending up into the darkness",
  "torches","One of many blazing torches.\n",
     "It is secured to the wall",
 });

  dest_dir=({
 "/players/saber/tower/tower3.c","north",
 "/players/saber/tower/tower5.c","east",
 "/players/saber/tower/tower4.c","south",
 "/players/saber/tower/tower1.c","west",
 "/players/saber/tower/tower6.c","up",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
