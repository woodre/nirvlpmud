inherit "room/room";
#include "/players/persephone/rooms.h"
reset(int arg){
 object boa;
 if(arg) return;
  boa=clone_object("players/persephone/obj/board");
  move_object(boa,this_object());
  set_light(1);
  short_desc="A Shadowy Room";
  long_desc="You are in a room of shadows that seem to promise great\n" +
            "and far flung adventures through all corners of Nirvana.\n" +
            "In the middle of the room is a large and important looking\n" +
            "sign. and a huge rift in the south wall with a plaque\n" +
            "over it.\n\n";
  items=({"shadows","The shadows seem to shift and sway around the room\n" +
                    "as you examine them you notice that they look like\n" +
                    "hero's of the past",
          "floor","The floor is completely smooth and light seems to\n" +
                  "shimmer up from it",
          "ceiling","The ceiling stretches out of site upwards as if\n" +
                    "you are in a strange void",
          "rift","The rift looks dark and foreboding",
          "sign","A glorious sign proclaiming the wonders of this area\n" +
                 "perhaps you should read it",
          "plaque","A plaque that requires careful reading it seems to\n" +
                   "warn of danger",
         });
  dest_dir=({"room/hump","out",
             "players/persephone/rooms/dpath3","rift",
            "players/persephone/rooms/stream2","north",
          });
}
init(){
 ::init();
  add_action("read1","read");
  add_action("north","north");
}
read1(str){
 if(str=="sign"){
  write("\n"+
        "       Welcome to the wonders of Persephone's\n"+
        "       Castle. It is still under development\n"+
        "       but soon there will be areas for newbies,\n"+
        "       and mid level adventurers and eventually\n"+
        "       the complete land of stormhold. All of these\n" +
        "       areas will require adventuring in full mode \n" +
        "       and examination of items. If you find any bugs\n" +
        "       or have suggestions please mail me.\n" +
        "       Have fun and love from Persephone!!!\n\n");
  say(CAPTPLNM +" reads a large and important sign\n");
 return 1;
 }
 if(str=="plaque"){
  write("\n" +
        "         This area should be treated with caution\n" +
        "         it is suggested that players be of at least\n" +
        "         fifteenth level and have good armour. Lower\n" +
        "         level players should not enter this area\n" +
        "         unless they are in large parties and even\n" +
        "         level characters must be careful.  Please\n" +
        "         explore all the rooms as there are some\n" +
        "         and hidden clues but most of all have fun\n" +
        "         and please feel free to mail me suggestions\n" +
        "         You have been warned!!!   Persephone\n\n");
  say(CAPTPLNM +" reads a plague over the rift\n");
 return 1;
 }
 write("What do you want to read the plaque or the sign\n");
 return 1;
}
north(){
 if(TPL->query_level()>6){
  write ("You have foolishly tried to enter where you were not allowed\n" +
         "you must pay for that foolishness.\n");
TPL->move_player(" being sucked into a hole in the space time continuum#"+"players/persephone/rooms/junpat3");
 return 1;
 }
}
