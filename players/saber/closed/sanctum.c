#define tp this_player()->query_name()
inherit "room/room";
object light;
int t, shield, notin;
reset(int arg){
if(!present("coffin"))  {
move_object(clone_object("/players/saber/fur/coffin.c"),this_object());  }
if(!present("couch"))  {
move_object(clone_object("/players/saber/fur/couch.c"),this_object());  }

 if(!arg){
  set_light(1);
 short_desc="Saber's Sanctum";
long_desc=
 "This is the sanctum of Saber.  Cloaked in a gentle tranquility, there is an\n"+
 "almost melancholy air persuasive throughout the room.  The chamber appears\n"+
 "quite spacious, yet is shrouded in the folds of many dark tapestries which\n"+
 "hang from the ceiling and walls. The dancing light of the fire blazing in\n"+
 "the hearth provides both illumination to the chamber and gives you the\n"+
 "deliciously drowsy sensation of warmth.  Assorted pieces of comfortable yet\n"+
 "stylish furniture are arranged about the room, all facing towards the\n"+
 "hearth.\n";

items=({
 "tapestries","There are many tapestries of dark hues hung off of the\n"+
     "the walls and from the ceiling.  The tapestries depict many\n"+
     "scenes of valor and glory",
 "furniture","Two large chairs and a couch are arranged to face the hearth",
 "chamber","This is the Sanctum of Saber",
 "light","The light in this room is provided by the flames which dance within\n"+
      "the hearth",
 "illumination","The light in this room is provided by the flames which dance within\n"+
    "the hearth",
 });

  dest_dir=({
 "/players/saber/workroom.c","out",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("on","on");
   add_action("off","off");
if(this_player()->query_real_name() !="saber" && shield == 1) {
 write("You get a faint image of a blue circle of light as\n");
 write("you rebound off of a circle of warding.\n");
if (notin == 1) {
 write("Saber is available at the moment.  Please leave a message\n");
 write("at the post office.  Thank you.\n");
}
 this_player()->move_player("off the shields#room/church");
}
}

static on() {
   shield = 1;
   write("Circle of warding activated.\n");
   return 1;
}
static off() {
   if (call_other(this_player(), "query_real_name", 0) !="saber") {
   write("You have not yet aquired the power to raise the circle of warding.\n");
   return 1;
   }
  shield = 0;
  notin = 0;
  write("Circle of Warding removed.\n");
  return 1;
   }
out() {
   shield = 1;
   notin = 1;
   write("Circle on, out message on.\n");
   return 1;
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

realm()  { "NT"; }
