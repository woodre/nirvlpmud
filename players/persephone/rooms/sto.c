inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
string tr;
reset (int arg){
 if(!arg){
  tr="closed";
  set_light(0);
  short_desc="Storage Room";
  long_desc="A small non descript storage room with a trap door\n" +
            "in the floor and a opening to the south. Around the\n" +
            "wall is a shelf. The air in the room is extremely\n" +
            "musty and damp.\n\n";
  items=({"floor","The floor is extremely damp and you can make out\n" +
                  "some sort of strange pattern",
          "pattern","The footprints of many different types of creatures\n" +
                    "that has been left in a brownish patch",
          "door","Just a steel trapdoor that looks extremely heavy",
          "ceiling","Large pieces of shredded fabric hang down\n" +
                    "from the ceiling which has large wooden rafters",
          "fabric","The fabric is flax and actually looks like rope",
          "shelf","Just an ordinary looking wooden shelf",
          "walls","The walls are sheet metal and covered in blood",
        });
dest_dir=({"players/persephone/rooms/maze1","south",
         });
 }
}
realm() { return "NT"; }
init(){
 ::init();
  add_action("open1","open");
  add_action("down","down");
  add_action("down","d");
}
open1(str){
 if(str=="trapdoor"||str=="door"||str=="trap"){
  if(tr=="closed"){
   write("After much exertion and struggling you manage to open\n" +
         "the trapdoor\n\n");
   say(CAPTPLNM + " struggles and finally with a great heave opens\n" +
       "the trapdoor\n\n");
   tr="open";
   return 1;
  }
  write("You struggle to open the already open trapdoor\n");
  say(CAPTPLNM + " tries to open the already open trapdoor\n");
  return 1;
 }
 write ("What do you want to open\n\n");
 return 1;
}
down(){
 if (tr=="open"){
  write("You jump down into the depths below landing with a sudden\n" +
       "splash\n\n");
  TPL->move_player("Jumping down into the darkness#" + "players/persephone/rooms/und_gr1");
  return 1;
 }
 write("You try and jump down but land hard on the trapdoor. OUCH!!!\n");
 say(CAPTPLNM + " tries to jump through the closed trapdoor\n");
 return 1;
} 
