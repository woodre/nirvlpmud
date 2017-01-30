inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
 set_light(1);
 short_desc="The Honeymoon Suite";
  long_desc="This is one of the most stunning honeymoon suites you have ever seen\n" +
            "not only is there a king sized waterbed but there is a large chandelier\n" +
            "and a large walk-in wardrobe against the east wall as well as the other\n" +
            "furnishings you would expect in an international hotel. To the west you\n" +
            "see the ensuite and to the north is the corridor.\n" +
             "\n";
  items=({"waterbed","The waterbed looks extremely comfortable and recently made\n" +
                     "on it is a lovely Doona",
          "Doona","This doona looks so soft and fluffy and also warm",
           "chandelier","It is a crystal chandelier and has little figures on it",
          "figures","You think that they must be cupids, very fitting for the honeymoon\n" +
                    "suite",
          "wardrobe","The wardrobe is full of clothes you guess someone must be staying\n" +
                     "in the room",
          "ensuite","This ensuite has everything a spa, a sauna, a shower, who could\n" +
                    "ask for more",
           "furniture","Come on you know what furniture is! Alright there is a bar,\n" +
                      "a table with chairs, a lounge suite, a television and a phone",
          "table","The table is made of Mahogany and is French Polished",
          "chairs","That's right, they are made of Mahogany too",
          "suite","The suite is extremely attractive and looks very comfortable but\n" +
                  "you dare not sit in it",
          "Television","Just a 26 inch colour television that is firmly attached to the\n" +
                       "desk",
          "desk","This is a wall mounted walnut desk",
          "phone","A push button cordless phone",
          "Bar","Well actually it is a bar fridge and no you cannot open it this is not\n" +
                "it is not your room",
          });
  dest_dir=({"players/persephone/rooms/hcorr2c","north",
          });
 }
}
realm() { return "NT"; }
