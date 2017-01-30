inherit "/players/persephone/closed/thingys";
#include "/players/persephone/rooms.h"
int t;
reset (arg){
    for(t=0;t<3;t++){
  if(!present("pirate")){
    move_object(clone_object("players/persephone/monster/pirade"), TOB);
    }
  }
if(!arg){
  set_light(1);
  short_desc="Top of Staircase";
  long_desc="You finally reached the top of the dark steep staircase all around you\n" +
            "are pools of a dark looking liquid and something appears to be scrawled\n" +
            "onto the wall. The staircase goes down and you see passages or corridors\n" +
            "heading both east and west.\n" +
            "\n";
  items=({"staircase","This thing is extremely steep and you see sinister figures\n" +
                      "climbing up and down the staircase",
         "figures","These are some of the meanest looking pirates you have ever seen\n" +
                   "in fact mean is not the word",
          "liquid","This stuff is not just liquid it is pools of drying blood. You\n" +
                   "have to wonder if the pirates had anything to do with this",
           "floor","The floors are absolutely covered in pools of blood",
           "blood","This is definitely human blood",
           "walls","These walls look extremely thin and some sort of writing appears\n" +
                   "to be scrawled on them",
           "writing","It appears to be in blood and seems as if however wrote it\n" +
                     "was in anquish because you cannot make out any of the words",
           "ceiling","The ceiling was once painted white but now seems to be discoloured\n" +
                     "with blood stains",
           });
  dest_dir=({"players/persephone/rooms/paphot1d","west",
              "players/persephone/rooms/paphot1c","east",
             "players/persephone/rooms/stairsa1","down",
  });
 }
}
realm() { return "NT";}
