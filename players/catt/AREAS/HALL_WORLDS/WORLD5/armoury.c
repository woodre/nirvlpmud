#include "std.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_INIT
#define EXTRA_INIT\
   add_action("read","read");\
add_action("buy","buy");
ONE_EXIT("players/catt/workroom.c","portal",
        "catts- armoury",
    "This is the famous armoury of Yiquanuc. It has many\n"+
   "items that have never been held by mortal hands in all of their\n"+
   "long history. Take precious care of them. They are also not \n"+
   "cheap. Their is a sign on the wall, try reading it.\n", 1)

read(arg) {
   if(!arg || arg != "sign") {
      write("Qual says: What are you trying to read?\n");
   }
   if(arg == "sign") {
      cat(WORLD5_LIB+"armlist");
      return 1;
   }
   return 1;
}
buy(arg) {
  int value, i;
  object ob;
  if(!arg) {
   write("Old Dwarf says: Did you want to buy something?");
     return 0;
       }
  i = arg;
  if(i == 1) {
   value = 10000;
   if(call_other(this_player(), "query_money", 0) < value) {
     write("Old Dwarf says: you don't have enough cash!\n");
     return 0;
    }
    call_other(this_player(), "add_money", 0 - value);
    ob = clone_object("players/catt/ARMOURY/balmung");
    write("Old Dwarf says: alright! Its yours, watch out for snow!\n");
     return 1;
  }}
