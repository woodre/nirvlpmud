
#include "/players/jaraxle/define.h"
object room;

void start(object ob)
{
   room = ob;
   shadow(room, 1);
   tell_room(room, "A glowing aura silhouettes your view.\n");  
   call_out("stop", 30+random(30));
}

void stop()
{
   if(room)
      {
      tell_room(room, "The glowing aura fades.\n");
      shadow(room, 0);
   }
   destruct(this_object());
}

query_NM(){
   return 1;
}

int query_property(string str)
{
   int nStatus;
   if(!room) stop();
   if(str == "no_magic" || str == "NM")
      nStatus = 1;
   else
      nStatus = (int)room->query_NM();
   return nStatus;
}
short(){
   switch(random(3)){
      case 0: return room->short() + HIW+" *"+HIC+"Sanctified"+HIW+"*"+NORM;
      break;
      case 1: return room->short() + HIW+" ["+HIY+"Sanctified"+HIW+"]"+NORM;
      break;
      case 2: return room->short() + HIC+" }"+HIB+"Sanctified"+HIC+"{"+NORM;
      break;
   }
}


id(str){ return str == "holy@ground"; }
