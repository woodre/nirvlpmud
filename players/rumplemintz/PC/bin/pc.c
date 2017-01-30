/* pc - the chat command for the Player Channel */

#include <ansi.h>

int pc(string str){
   object *list;
   int i;
   string name;
   list = users();
   name = (string)this_player()->query_name();
   if(!str){
      notify_fail("Usage: pc <message>\n");
      return 0;
   }
   if( (int)this_player()->query_level() > 20
         && (string)this_player()->query_real_name() != "rumplemintz"){
      notify_fail("This channel can only be used by players.\n");
      return 0;
   }
   if(present("player_channel", this_player())->query_shush()){
      notify_fail("You cannot use this channel while it is shushed!\n");
      return 0;
   }
   for(i=0; i<sizeof(list); i++){
      object pobj;
      pobj = present("player_channel", list[i]);
      if(pobj && !pobj->query_shush()){
         tell_object(list[i], HIW+"[ Plyr "+name+" > "+NORM+str+"\n");
         return 1;
       }
   }
}
