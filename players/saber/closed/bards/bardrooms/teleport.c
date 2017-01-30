#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("circle"))  {
move_object(clone_object("/players/saber/closed/bards/pet_thing.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="Bard Teleport Chamber";
long_desc=
 "You have entered the bardic teleport room, a chamber constructed entirely\n"+
 "from polished mahogany wood.  The room is bare.  The only object of interest\n"+
 "is the circle of blue power floating seven inches off the floor, just large\n"+
 "enough for one person to sit in.  The room is illuminated dimly by the aura\n"+
 "from the blue circle.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "room","You are in the teleport chamber of the Bards",
 "chamber","You are in the teleport chamber of the Bards",
 "aura","The blue circle of power glows faintly",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/shield.c","east",
 "/players/saber/closed/bards/bardrooms/common.c","south",
 "/players/saber/closed/bards/bardrooms/advance.c","west",
 "/players/saber/ryllian/portal.c","portal",
 "/room/church","church",
           });
  }   }
init(){
 ::init();
if(!present("instrument",this_player()) &&
   this_player()->is_player())  {
  write("You get the brief image of a blue circle before\n"+
     "\n"+
    " * * * * *  B O O M  * * * * *\n"+
    "\nYour body flies through space.\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the Circle of Warding.\n");
  move_object(this_player(),"/room/void");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\n"+
      "THUD.\n");
  return 1;
        }
  add_action("search","search");
   add_action("sit","sit");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

sit(str) {
if (str == "circle"){
write("You sit down in the circle of blue power.\n"+
   "Try later.  Circle powers not yet at full potential.\n");
say(tp+" sits in the blue circle of power.\n");
 return 1;   }
if (str == "floor") {
write("You sit down on the floor.\n");
say(tp+" sits down upon the floor.\n");
  return 1;
}
else {
write("Sit where?\n");
say(tp+" looks for a place to sit down.\n");
 return 1;
}
}

