#include "/players/fred/mages/defs.h"

cmd_title(){
 string title;
 int x;
 x = USER->query_guild_rank();
 switch(x){
   case 0: title = "the Child of Omens"; break;
   case 1: title = "the Traveller of the Mists"; break;
   case 2: title = "the Student of Sidhe"; break;
   case 3: title = "the Initiate of Dark Magic"; break;
   case 4: title = "the Black Circle Archmage"; break;
   case 5: title = "the Black Circle High Adept"; break;}    
  TP->set_title(BOLD+BLK+title+NORM);
  write("Venture forth, "+TP->short()+", and conquer life and death!\n");
  return 1;
}
