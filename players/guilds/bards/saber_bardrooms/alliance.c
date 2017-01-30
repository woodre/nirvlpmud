#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("fireplace")){
move_object(clone_object("players/saber/fur/fireplace.c"),this_object());
}
/*
if(!present("armitage"))  {
move_object(clone_object("/players/sandman/paladin/dual/warmaster.c"),this_object());  }
*/
if(!present("laura"))  {
move_object(clone_object("/players/saber/closed/bards/laura.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="Alliance Sanctum";
long_desc=
"You stand in the Alliance Sanctum.  This chamber has been constructed from a\n"+
"beautiful mahogany wood, and a pleasant feeling of warmth fills you as you\n"+
"enter.  The room is lit both by lanterns and by a large fireplace built into\n"+
"the north wall.  The walls are covered with tapestries depicting many scenes\n"+
"of heroism.  On the west wall is a portal leading to the realm of Dreams. To\n"+
"the east is a spiral staircase descending to Orins Inn.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "fireplace","A large fire, blazing in the hearth in the northern wall",
 "sanctum","You stand in the Sanctum of the Alliance",
 "tapsetries","There are many tapestries here depicting scenes of valor and glory",
 "chairs","One of several large mahogany chairs - perhaps you can 'sit' in it",
 "wood","A deep, beuatiful dark mahogany wood imported from the forest of dreams",
 "mahogany","A deep, beuatiful dark mahogany wood imported from the forest of dreams",
 "couch","One of several large comfortable couches - perhaps you can 'sit' at it",
 "couches","One of several large couches - perhaps you can 'sit' in it",
 "chair","One of several mahogany chairs - perhaps you can 'sit' in it",
 "staircase","A spiral staircase leading down the Inn",
 "portal","A portal leading to the realm of dreams",
 });

  dest_dir=({
 "/players/sandman/paladin/entry.c","portal",
 "/players/saber/closed/bards/bardrooms/enterance.c","east",
           });
  }   }
init(){
 ::init();
if(this_player()->is_player() && !present("instrument",this_player()) && !present("pro_object",this_player())) {
     tell_room(this_object(),capitalize(this_player()->query_real_name())+" bounces off the shield of warding!\n");
  this_player()->move_player("off the shields#room/church.c");
return 1;}
  add_action("search","search");
   add_action("sit","sit");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

sit(str) {
if (str == "in chair"){
write("You sit down in a mahogany chair.\n");
say(tp+" sits down in a mahogany chair.\n");
 return 1;   }
if(str == "in couch" || str == "on couch")  {
write("You sit down in one of the VERY comfortable couches.\n");
say(tp+" sits down in one of the couches.\n");
  return 1;}
if (str == "on floor") {
write("You sit down on the floor.\n");
say(tp+" sits down upon the floor.\n");
  return 1;
}
else {
write("Sit where?  A couch, a chair or the floor?\n");
say(tp+" looks for a place to sit down.\n");
 return 1;
}
}

realm()  { return "NT"; }
