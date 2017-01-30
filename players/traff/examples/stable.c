 inherit "room/room";
  reset(arg){
    while( !present("charger 2") ) {
 move_object(clone_object("/players/arrina/monsters/charger"),this_object());  }
   if(!arg){
   set_light(0);
   short_desc="Stables";
  long_desc=
    "The stables are eerie and dark.  It appears that nothing\n"+
    "is truly right here.  There is a small door to the west and \n"+
    "the many stalls must once have housed beautiful horses.\n";
   items=({
   "stalls", "All the stalls are open, and anything could be in them",
  "door","The door leads to the tackroom.  You might be \n"+
  "able to 'enter tackroom' but be careful in there",
   });
    dest_dir=({
    "/players/arrina/newbie/newbie1.c","east",
 });
 call_out("trot",10);
   }   }
  trot() {
   if(!present("charger",this_object())) {
     tell_room(this_object(),"A charger trots into the room!\n");
 move_object(clone_object("/players/arrina/monsters/charger"),this_object());
 call_out("trot",40);
 return 1;
   }
     else
 call_out("trot",40);
 return 1;
 }
  init() {
   ::init();
   add_action("enter_tackroom","enter");
 }
  enter_tackroom() {
   if(present("charger",this_object())) {
     write("The charger blocks your way!\n");
 return 1;
   }
 else
 call_other(this_player(),"move_player",
            "into the tackroom#/players/arrina/grounds/tackroom.c");
 return 1;
 }
