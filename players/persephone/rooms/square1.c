inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
object crack;
reset (int arg){
 if(!present("mayor")){
  move_object(clone_object("players/persephone/monster/mayo"), TOB);
 }
 if(!arg){
  set_light(0);
  short_desc="Town Square";
  long_desc="You have entered the main square of Stormhold and is it dark. Perhaps\n" +
            "the rumours you heard that evil had taken over this once idyllic seaside\n" +
            "town are true. There appears to be buildings to the West and North\n" +
            "but they now appear vacant. The Square continues South and East.\n";
  items=({"buildings","These once grand buildings are now completely boarded up\n" +
                      "and completely run down",
           "boards","You know wooden boards. Wait a second as you look at the boards\n" +
                    "you think you might be able to find a crack. Perhaps you should\n" +
                    "search them",
          "stormhold","You can only see part of Stormhold at the moment but from what\n" +
                      "you see it is evil and menacing",
          "square","The town square it is almost pitchblack",
          "sky","They sky is filled with big black storm clouds maybe that is where the\n" +
                "town got its name",
          "ground","The ground is completely covered in trash you guess there has not\n" +
                   "been a garbage service recently",
          "trash","The trash is mainly paper which is soaked with water",
          "water","That clear liquid there is not much of it here",
          "seaside","You cannot see the sea from here but you smell salt water\n" +
                    "in the air",
          "clouds","the clouds are big and black and definately mean buisness",
  });
  dest_dir=({"players/persephone/rooms/road1b","north",
             "players/persephone/rooms/square2","south",
             "players/persephone/rooms/square3","east",
             "players/persephone/rooms/mid_square","southeast"
  });
 }
}
realm() { return "NT"; }
init(){
 ::init();
 add_action("search1","search");
 add_action("squeeze","squeeze");
 add_action("squeeze","enter");
 add_action("squeeze","in");
}
search1(str) {
 if(str=="boards"){
  write("You find a crack in the boards which you might be able to squeeze through\n");
  say(capitalize(this_player()->query_name())+" taps the boards searching for something\n");
  crack = this_player();
  return 1;
  }
}
squeeze(){
 if(crack==this_player()){
  write("You squeeze through a very tight crack you found in the boards\n");
  this_player()->move_player("crack#"+"players/persephone/rooms/whousev1");
  return 1;
 write ("You cannot find the crack right now\n");
 return 1;
}
}
