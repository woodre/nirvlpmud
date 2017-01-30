#include "std_old.h"
 string long_dsc;
init() {
  add_action("add_to_long","add*");
  add_action("wipe_long","wipe");
}

 short() {
 return "happy room";
  }

 long() {
    if (!long_dsc)
   {
   write ("Use 'wipe' to clean room description.\n");
   write ("Use 'add* (descrip)' to add a line to room description.\n");
   }
    if(long_dsc) write (long_dsc);
 write("The only exit is south.\n");
  }

  add_to_long(str){
if (!long_dsc) long_dsc = "";
  long_dsc = long_dsc + str;
  long_dsc = format(long_dsc, 78);
  return 1;
}

wipe_long(){
   long_dsc = "";
   return 1;
   }
