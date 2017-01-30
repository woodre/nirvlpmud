#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("fireplace")){
move_object(clone_object("players/saber/fur/fireplace.c"),this_object());
}
if(!present("book"))  {
move_object(clone_object("/players/saber/closed/bards/bard_news.c"),this_object());  }
if(!present("journal"))  {
move_object(clone_object("/players/saber/closed/bards/bard_poetry.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="Bard Common Room";
long_desc=
 "The common room of the Bards Guild is a pleasant chamber constructed entirely\n"+
 "from mahogany wood.  It is filled with large chairs and comfortable couches.\n"+
 "A large fireplace is built into the northern wall, while a spiral staircase\n"+
 "is set against the southern one.  To the east is the charity room, while the\n"+
 "door to the west leads to the lore and equipment chamber.  A beautiful wooden\n"+
 "sign hangs against the west wall amidst various paintings.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "fireplace","A large fire, blazing in the hearth in the northern wall",
 "room","The common room of the Bardic guild.  A good place to hang out",
 "chairs","One of several large mahogany chairs - perhaps you can 'sit' in it",
 "wood","A deep, beuatiful dark mahogany wood imported from the forest of dreams",
 "mahogany","A deep, beuatiful dark mahogany wood imported from the forest of dreams",
 "couch","One of several large comfortable couches - perhaps you can 'sit' at it",
 "couches","One of several large couches - perhaps you can 'sit' in it",
 "chair","One of several mahogany chairs - perhaps you can 'sit' in it",
 "staircase","A spiral staircase leading up the guardens",
 "door","The door to the west leads to the lore and equipment chamber",
 "sign","The sign reads:\n"+
    "The Common Room - more to come later",
 "painting","Many large and exquisit paintings cover the west wall",
 "painting","Many large and exquisit paintings cover the west wall",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/teleport.c","north",
 "/players/saber/closed/bards/bardrooms/charity.c","east",
 "/players/saber/closed/bards/bardrooms/enterance.c","south",
 "/players/saber/closed/bards/bardrooms/lore.c","west",
 "/players/saber/closed/bards/bardrooms/alliance.c","up",
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
if (str == "chair"){
write("You sit down in a mahogany chair.\n");
say(tp+" sits down in a mahogany chair.\n");
 return 1;   }
if (str == "couch") {
write("You sit down in one of the VERY comfortable couches.\n");
say(tp+" sits down in one of the couches.\n");
  return 1;}
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

realm()  { return "NT"; }
