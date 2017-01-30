inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("rat")){
  move_object(clone_object("players/persephone/monster/ratty"),TOB);
 }
 if (!arg) {
  set_light(0);
  short_desc="Town Square";
  long_desc="The darkness and evil foreboding of Stormhold grips you more deeply\n" +
            "the further you proceed in this town. Perhaps it is the all encompassing\n" +
            "evil feeling that the square seems to be emitting or it is the way\n" +
            "that the rubbish seems to fly around you. When you look down to the\n" +
            "your vision seems to be obscured by all sorts of creatures. When you\n" +
            "look to the West you notice that there is a very large and dark building\n" +
            "with a huge sign over the passage way while the square continues North\n" +
            "South and East\n";
items=({"town","The town from what you have seen is small but emits an evil aura",
        "square","You cannot see much of it because you are surrounded by a web of darkness.\n" +
                 "However it appears once to have been beautiful",
        "rubbish","It is mainly paper but you also see leaves and twigs blowing around",
        "paper","You know paper the stuff that is usually written upon however,\n" +
                "you cannot tell if there is anything on this paper because of\n" +
                "the wind",
        "ground","Yuk, there are all sorts of insects and creatures crawling around",
        "creatures","In the gloom they appear to be big rats but you may be wrong",
        "insects","There are many different types of insects most notably\n" +
                  "you see spiders and the largest ugliest looking cockroaches\n" +
                  "you could imagine",
        "spiders","Big black hairy Tarantulas, some of them are as big as dinner plates",
        "cockroaches","Black evil looking things yuk",
        "sign","There is some writing on it perhaps you should read it",
        "building","From this distance you think it is some sort of shop. Perhaps\n" +
                   "the sign will give you more information",
        "sky","The sky is obscured by the blackest clouds you have ever seen",
      });
  dest_dir=({"players/persephone/rooms/square1","north",
             "players/persephone/rooms/slavsh","west",
             "players/persephone/rooms/square4","south",
             "players/persephone/rooms/mid_square","east"
  });
 }
}
realm() { return "NT"; }
init(){
  ::init();
     add_action("read","read");
}
read(str){
  if(str=="sign"||str=="writing"){
     write("              Jaundice's Ye Olde Slave Shoppe\n" +
           "              purveyors of the finest slaves in\n" +
           "               Nirvana.\n");
     say(CAPTPLNM + " reads the important looking sign\n");
  return 1;
  }
   write("What are you trying to read a book or something?!?!?\n");
return 1;
}
