inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
  set_light(1);
  short_desc="Collapsed Corridor";
   long_desc="This room has been totally decimated by the passing of time and there\n" +
             "is nothing but rubble around you. The best way continue would be to \n" +
             "retreat the way you came which was south as you can go no further\n" +
             "North.\n";
  items=({"room","What room it looks like a bomb hit it this is probably more\n" +
                "likely than just age",
         "ceiling","The ceiling is non existant all that you can see above you is sky",
         "floor","The floor is cover in rubble",
         "rubble","Mainly concrete but you can see some iron bars and lots of dust.\n" +
                  "Perhaps if you move the rubble you might find something",
         "dust","Cement dust what did you expect magic dust",
         "concrete","Large blocks of broken concrete",
         "bars","They are twisted all out shape",
          });
  dest_dir=({"players/persephone/rooms/pol_stat2","south",
  });
 }
}
realm() { return "NT"; }
