#define tp this_player()->query_name()
inherit "room/room";
object bed;
int t, shield, notin;
reset(int arg){
if(!present("bed")) {
move_object(clone_object("players/saber/fur/bed.c"), this_object());
}
if(!arg){
  set_light(1);
   short_desc="Saber's Room of Meditation";
long_desc=
 "You are in a small, shadowy chamber lit entirely by the warm light of\n"+
 "flickering candles and smoking incense.  In the middle of the room is a\n"+
 "large, comfortable looking bed with several inviting looking chairs\n"+
 "scattered around it.  The floor is covered by a softly woven rug, which\n"+
 "itself is buried under an incredible selection of multi-colored satin\n"+
 "pillows\n";

items=({
 "chamber","Saber's room of Meditation",
 "light","The chamber is lit by many flickering candles",
 "chair","There are many comfortable looking chairs scattered around the room\n"+
   "You could probably 'sit' in one.",
 "chairs","There are many comfortable looking chairs scattered around the room\n"+
   "You could probably 'sit' in one.",
 "candles","Many flickering candles light the chamber",
 "candle","One of many flickering candles which lights the chamber",
 "incense","One of many sticks of incense that burns softly within the chamber",
 "rug","A softly woven rug",
 "pillows","There are hundreds of pillows scattered across the room.\n"+
   "You could probably 'pick' a pillow",
 "pillow","One of hundreds of pillows scattered across the room.\n"+
    "You could probably 'pick' a pillow",
 });

  dest_dir=({
 "/players/saber/workroom.c","out",
           });
} }
init(){
 ::init();
  add_action("search","search");
 add_action("pick_pillow","pick");
 add_action("sit_chair","sit");
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
 write("You find tons of pillows!\n");
 say(tp+" searches the area\n");
 return 1;  }
pick_pillow() {
move_object(clone_object("players/saber/stuff/pillow.c"), this_player());
 write("You pick up a pillow\n");
say(tp+" picks up a pillow\n");
 return 1;  }
sit_chair() {
write("You sit down in a chair.\n"+
       "It is very comfortable.\n");
 say(tp+" sits down in a chair.\n");
return 1;   }
