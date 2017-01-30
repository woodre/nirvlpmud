inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
object hol;
reset (int arg){
 if(!present("pirate")) {
  move_object(clone_object("players/persephone/monster/pscout"), TOB);
 }
 if(!arg){
  set_light(0);
  short_desc="Jungle Path";
  long_desc="You are in the middle of a dark and ominous jungle. All around\n" +
            "you grow many varieties of trees and many different types\n" +
            "of creeper. The path continues to the north while at your\n" +
            "feet you see a small hole\n" +
            "\n";
  items=({"path","You suppose you can probably call it a path but it looks\n" +
                 "disused and treacherous",
          "trees","They are trees and look to be sort of tropical but\n" +
                  "you cannot detect what types they are",
          "creepers","Mainly vines and oportunistic plants but you can identify\n" +
                     "some jungle orchids",
          "orchids","They are in bloom and the flowers look extremely\n" +
                    "pretty",
          "hole","There is something strange about the hole perhaps you should\n" +
                 "check it out",
        });
  dest_dir=({"players/persephone/rooms/junpat2","north",
           });
 }
}
init(){
 ::init();
  add_action("check1","check");
  add_action("check1","search");
  add_action("enter","enter");
  add_action("enter","in");
  add_action("enter","down");
}
check1(str){
 if (str=="hole"){
  write("You think that you might be able to enter the small hole\n" +
        "but you are uncertain where it leads.\n");
  say(CAPTPLNM + " is kneeling down and checking out the hole\n\n");
  hol = TPL;
  return 1;
 }
}
enter(){
 if(hol==TPL){
  write("You start to climb down into the the darkness below wondering\n" +
       "what awaits you.  \n");
  TPL->move_player("descending down a hole#"+"players/persephone/rooms/pit1");
  return 1;
 }
 write ("You could not begin to climb down the hole you have not examined\n" +
        "it.\n");
 say (CAPTPLNM + " this name looks foolish trying to fit in hole that is to\n" +
                 "tight for him\n");
 return 1;
}
