#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(arg){
if(!present("fireplace")) {
move_object(clone_object("/players/saber/fur/fireplace.c"),this_object());
}
 if(!arg){
  set_light(1);
 short_desc="Orin's Hearth";
long_desc=
 "This eastern corner of the bar is quieter than the common room, and seems to\n"+
 "give forth an almost melancholy air.  It is lit entirely by the warm, dancing\n"+
 "light of the fire which blazes in the hearth.  The heat from the fire fills\n"+
 "the chamber, giving you a deliciously drowsy feeling.  There are a few large,\n"+
"comfortable looking mahogany chairs set here, facing towards the hearth.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "fire","A large hearth of dark stone filled with blazing logs",
 "hearth","A large fireplace of dark stone filled with blazing logs.\n"+
   "You could probably add a log to the 'fire'",
 "light","This chamber is lit by the dacning flames in the hearth",
 "chamber","A quite section of Orin's Inn",
 "chair","A comfortable looking chair that you can 'sit' in",
 "chairs","Many comfortable looking chairs that you could 'sit' in",
 });

  dest_dir=({
 "/players/guilds/bards/orin/orin2.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("sit","sit");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

sit(str) {
if (str == "chair") {
write("You sit down in a chair, facing the fire.\n");
say(tp+" sits down in a chair.\n");
 return 1;
}
if (str == "floor") {
write("You sit down on the floor, facing the fire.\n");
say(tp+" sits down upon the floor, facing the fire.\n");
  return 1;
}
else {
write("Sit where?\n");
say(tp+" looks for a place to sit.\n");
return 1;
}
}
