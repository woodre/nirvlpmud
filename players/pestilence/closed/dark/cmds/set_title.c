#include "/players/pestilence/ansi.h"


main(str) {
   string title;
   if(!str){ write("You must pick 1-9.\n"); return 1; }
   if(this_player()->query_guild_rank() >= 9 && (str == "9")){
   title = RED+"Destroyer of Everything"+WHT+" Good"+NORM;
      this_player()->set_title(title);
   write("Title set.\n");
   return 1;
   }
   else if(this_player()->query_guild_rank() >=  7 &&  (str == "8")){
   title = HIK+"Evil Lord of "+NORM+""+RED+"Destruction "+HIW+"<"+HIK+"DARKNESS"+HIW+">"+NORM;
      this_player()->set_title(title);
   write("Title set.\n");
   return 1;
   }
   else if(this_player()->query_guild_rank() >= 6 && (str == "7")){
   title = HIK+"Dark lord of "+HIR+"<"+HIK+"DARKNESS"+HIR+">"+NORM;
      this_player()->set_title(title);
   write("Title set.\n");
   return 1;
   } 
   else if(this_player()->query_guild_rank() >= 5 && (str == "6")){
   title = HIB+"Destroyer of light "+HIR+"<"+HIK+"DARKNESS"+HIR+">"+NORM; 
     this_player()->set_title(title);
   write("Title set.\n");
   return 1; 
   }
   else if(this_player()->query_guild_rank() >= 4 && (str == "5")){
   title = HIG+"Devastator of all that's Decent"+NORM;
      this_player()->set_title(title);
   write("Title set.\n");
   return 1;
   }
   else if(this_player()->query_guild_rank() >= 3 && (str == "4")){
   title = HIK+"Darkness "+HIR+"<"+HIK+"Incarnate"+HIR+">"+NORM;
      this_player()->set_title(title);
   write("Title set.\n");
   return 1;
   }
   else if(this_player()->query_guild_rank() >= 2 && (str == "3")){
   title = BOLD+"the wielder of "+HIK+"darkness"+NORM;
      this_player()->set_title(title);
   write("Title set.\n");
   return 1;
   }
   
   else if(this_player()->query_guild_rank() >= 1  && (str == "2")){
   title = BLU+"aspiring weaver of the Dark"+NORM;
      this_player()->set_title(title);
   write("Title set.\n");
   return 1;
   }
   else{  if(str == "1")
   title = HIK+"initiate of Darkness"+NORM;
      this_player()->set_title(title);
   write("Title set.\n");
   return 1;
   }
   write("You are not high enough guild rank to choose that title.");
}
