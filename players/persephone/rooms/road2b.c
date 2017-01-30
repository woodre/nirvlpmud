inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
object hotel, sign;
reset (int arg){
 if(!present("citizen")){
  move_object(clone_object("players/persephone/monster/cit"),TOB);
 }
 if (!arg) {
  set_light(1);
  short_desc="The Boardwalk";
  long_desc="This is the once famed Boardwalk of Stormhold but now it is nothing\n" +
            "but a relic of its former glory. As you walk along this once beautiful\n" +
            "boardwalk you notice all the grand buildings that have fallen into\n" +
            "disrepair. Perhaps the most stunning of these is the one directly to\n" +
            "the North upon which you can see a large sign. Further on to the East\n" + 
            "is what looks to be an intersection while back to the West you can see\n" +
            "another road.\n";
  items=({"boardwalk","This is much like most boardwalks excepting that the once\n" +
                      "beautiful boards have fallen into disrepair",
          "buildings","Well these buildings all have seen better days but by all\n" +
                      "appearances they were once extremely grand not to say even\n" +
                      "palatial. One of the buildings however seems to be out of place\n" +
                      "as it is nowhere near as grand as the others and looks in\n" +
                      "reasonable condition with a sign still hanging from it",
          "sign","It looks like a hotel sign and you can just make out what the sign\n" +
                 "says, perhaps you should read it.",
          "building","It looks like a flop house or a very poor quality and dingy\n" +
                     "hotel there is a sign on it",
          "intersection","Come on you know what an intersection is",
          "road","Come on a road is just a road",
  });
  dest_dir=({"players/persephone/rooms/road1a","west",
             "players/persephone/rooms/road3b","east"
  });
 }
}
realm() { return "NT"; }
init(){
 ::init();
 add_action("read1","read");
 add_action("climb1","climb");
 add_action("climb1","enter");
 add_action("climb1","in");
}
read1(str) {
 if(str=="sign"){
  write("\n"+
        "                     The Hotel Flea Bag\n" +
        "                     We accept all vagabonds\n" +
        "                     and adventurers voted\n" +
        "                     ten times worst lodgings\n" +
        "                     in all of Nirvana\n" +
         "\n");
  say(capitalize(this_player()->query_name())+" reads the sign\n");
  return 1;
 }
}
climb1(str){
 if (str=="stairs"){
  write("Reluctantly you start to climb the stairs into the hotel not knowing\n" +
        "what awaits you.\n");
  say(capitalize(this_player()->query_name())+" wearily makes his way up the stairs into the hotel\n");
  this_player()->move_player("up the stairs#"+"players/persephone/rooms/hot1");
  return 1;
 }
}
