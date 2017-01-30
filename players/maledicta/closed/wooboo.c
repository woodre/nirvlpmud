#include "/players/maledicta/ansi.h"

void start_shad(object woo){
  shadow(woo,1);
   }

history(){
  tell_object(find_living("maledicta"),
   this_player()->query_real_name()+" just checked your QThistory."+HIR+"WOO"+NORM+"\n");
   return 1; 
    }
