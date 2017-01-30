#include "../scar.h"

main(str) {
   int muffled;

   muffled = SCAR->query_muffled();
    if(!str) {
        if ( muffled ) {
            previous_object()->set_muffled(0);
            write("You are now on the MK channel.\n");
            return 1;
        }
        else {
            previous_object()->set_muffled(1);
            write("You are now muffled.\n");
            return 1;
        }
    }
   if (str == "on") {
      write("You are now muffled.\n");
      return 1;
   }
   if (str == "off") {
      previous_object()->set_muffled(0);
      write("You are now on the blood channel.\n");
      return 1;
   }
   write("Usage: bts <on/off>\n");
   return 1;
}
