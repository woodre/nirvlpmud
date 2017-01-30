inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
  if(!present("swashbuckler")){
    move_object(clone_object("players/persephone/monster/piradf"),TOB);
  }
 if(!arg){
  set_light(1);
  short_desc="Hotel Corridor";
  long_desc="You are standing in the corridor of the first floor of the Chelsea\n" +
            "Hotel. The corridor continues both east and west while to the north\n" +
            "you see a staircase. The carpet you are standing on feels very\n" +
            "comfortable and the walls and the ceiling are painted exquisitely\n" +
            "on the wall to your south you see an exquisite painting.\n" +
            "\n";
  items=({"corridor","This is just a hotel corridor of an extremely grand hotel",
          "staircase","It appears to be made of the finest white marble",
          "walls","They are painted in lovely shades of light blues with stunning" +
                  "borders",
          "ceiling","The ceiling is painted in a dark shade of blue perhaps royal\n" +
                    "but it is difficult to tell because of the lighting",
           "painting","You fool it is actually a mirror",
          "borders","They are actually quite beautiful but you must ask yourself\n" +
                    "why they are a reddish colour. You think however that the pattern \n" +
                   "on the border which is of dragons is exquisite.",
           "mirror","The mirror appears to be cracked but it has a lovely gold frame",
           "frame","An exquisitely worked gold frame with a cherubian design",
           "cherubian","The figures in the frame look like Roman Cherubs.",
           });
  dest_dir=({"players/persephone/rooms/hotst1","north",
             "players/persephone/rooms/hcorr1b","west",
             "players/persephone/rooms/hotcor1","east",
  });
 }
}
realm(){ return "NT"; }
