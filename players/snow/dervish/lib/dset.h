#include "/players/snow/dervish/def.h"

dervish_set_percent(str){
  object me, myob;
  me = this_player();
  myob = present(GID, me);
   if(!str){ write("What did you want to set it to?\n"); return 1; }
    if(str == "low"){
      write("You have chosen the low setting.\n");
      myob->set_mystic_percent(25);
      myob->dervish_resett();
      return 1;}
    if(str == "med" || str == "medium"){
      write("You have chosen the medium setting.\n");
      myob->set_mystic_percent(50);
      myob->dervish_resett();
      return 1; }
    if(str == "high"){
      write("You have chosen the high setting.\n");
      myob->set_mystic_percent(75);
      myob->dervish_resett();
      return 1; }
  }
