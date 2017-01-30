inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("pirate")){
  move_object(clone_object("/players/persephone/monster/bulls") ,TOB);
 }
 if (!arg) {
  set_light(0);
  short_desc="Strange Alcove";
  long_desc="You are standing in a small alcove that is filled with many different\n" +
            "types of torture equipment. Perhaps the most noticeable is the rack\n" +
            "as there appears to be someone hooked up to this barbaric looking piece\n" +
            "of equipment. The only exit is north into the bunkroom\n" +
            "\n";
  items=({"alcove","This is just a normal alcove however, you think it quite\n" +
                   "strange thast it is filled with torture equipment",
          "floor","The floor appears to be made of some sort of hardwood\n" +
                  "however with all the blood around here you cannot tell\n" +
                  "what type",
          "blood","The stuff that usually flows through you veins",
          "equipment","Well there is a rack, thumb screws, stocks and wait a second\n" +
                      "is that thing against the south wall a bed of nails",
          "rack","Come on you know what a rack looks like. This is just\n" +
                 "a garden variety rack however it does look in good condition\n" +
                 "and you can tell it has been used recently by the body\n" +
                 "strung up on it",
          "thumbscrews","These thumbscrews look exquisite perhaps if you\n" +
                        "search the room you might find a pair of them that\n" +
                        "will not be missed",
          "bed","You definitely would not like to sleep on this bed, those\n" +
                "nails look very sharp",
          "nails","These things are huge you guess they must be at least ten\n" +
                  "inches long",
          "stock","Just an ordinary wooden stock is does not look all that\n" +
                  "comfortable",
          "walls","You should have known the walls have chains fastened to\n" +
                  "them you guess someone is into bondage after all hanging\n" +
                  "next to some of the chains is a kinky looking whip",
          "whip","Just a cat o' nine tails. You think who ever used this\n" +
                 "area was extremely kinky",
          "ceiling","It looks rather low and is covered with that mold again",
          "mold","The mold is green and that is all you can tell",
         });
  dest_dir=({"players/persephone/rooms/paphot1a","north"
           });
  }
}
realm(){ return "NT";}
