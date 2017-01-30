/* pcdrop - Drop (and dest) the Player Channel object */

#include <ansi.h>

int pcdrop(){
   object *list;
   int i;
   string name;
   list = users();
   name = (string)this_player()->query_name();
   destruct(present("player_channel", this_player()));
   for(i=0; i<sizeof(list); i++){
      object pobj;
      pobj = present("player_channel", list[i]);
      if(pobj && !pobj->query_shush()){
         tell_object(list[i], HIW+this_player()->query_name()+" has left the Player Channel."+NORM+"\n");
       }
   }
   write(HIW+"You have left the Player Channel."+NORM+"\n");
   return 1;
}
