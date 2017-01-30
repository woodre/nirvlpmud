inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(1);
  short_desc="Hotel Room";
  long_desc="You are in a rather glorious hotel room by all appearances this room\n" +
            "room must be one of the cheaper rooms as it only has one Queen Sized\n" +
            "Bed in it. Against the west wall you see a large wardrobe and chest\n" +
            "of drawers. In the north wall of the room is a large window and there\n" +
            "is a bathroom ensuite to the east. The only apparent exit however is\n" +
            "to the south.\n" +
            "\n";
  items=({"bed","This bed looks really comfortable, however you find it strange\n" +
                "that there is no linen on the bed",
          "wardrobe","A big built in wardrobe it looks as it is quite well made\n" +
                     "but totally empty",
          "chest","This chest looks to be a fine piece of craftsmanship and by the\n" +
                  "grain of the wood you think it must be Mahogony",
          "window","It appears to be painted white and jammed shut",
          "bathroom","The bathroom looks to be quite large and it seems to have\n" +
                     "both a shower and a bath",
           });
  dest_dir=({"players/persephone/rooms/hcorr1b","south",
  });
 }
}
realm() { return "NT"; }
