#include <ansi.h>

tell_all(str) {
  object o; int i;
  o = users(); for(i = 0; i < sizeof(o); i++) {
  if(o[i]->query_real_name() != "boltar" && 
     o[i]->query_real_name() != find_player(str))
    tell_object(o[i], "Vital whispers to everyone: "+
"OK everyone, it is "+str+"'s birthday, so sing happy birthday to "+
"him on gossip with me when i start...:)\n");
  }
}
