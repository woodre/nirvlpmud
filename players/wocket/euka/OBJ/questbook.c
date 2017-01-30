#include "/players/wocket/closed/ansi.h"
#include "../Def.h"
inherit "obj/treasure.c";

id(str){ return (str == "guide" || str == "translator" || str == "book" || str == "euka_quest_translator"); }
reset(arg){
   if(arg) return;
  set_short("An Eukian translation guide");
   set_weight(1);
   set_value(100);
}

init(){
   add_action("read","read");
}

read(str){
   if(!str){
      notify_fail("What would you like to read?\n");
      return 0;
   }
    if(str == "guide"){
    cat(EPATH+"OBJ/eukalanguage.txt");
      return 1;
   }
  notify_fail("What is not here to read.\n");
  return 0;
}
