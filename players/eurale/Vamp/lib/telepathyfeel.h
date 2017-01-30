/*
  telepathyfeel.h
*/

#include "/players/eurale/defs.h"

/* -------- Telepathy feelings (emote) - tell all vampires ---------- */
telepathyfeel(str) {
  int i;
  object stuff, curse_obj;
  string who, msg, player_list, junk1, junk2;

if(!str) {
  write("What did you want to say?\n");
  return 1; }

sscanf(str, "%s==>%s", junk1, junk2);
if(junk1)
  str = RED+junk1+"==>"+NORM+junk2;
player_list = users();
for (i = 0; i < sizeof(player_list); i++) {
  stuff=present("vampire fangs", player_list[i]);
  if(stuff) {
    if(stuff->query_telepathy())
      if(TP->query_invis() > 0)
        if(query_verb()=="tf" || query_verb()=="telepathyfeel") {
          tell_object(player_list[i],
                BOLD+":[ "+NORM+"Someone "+str+"\n");
        }
        else {
          tell_object(player_list[i],
                BOLD+":["+NORM+" Someone . o O ("+str+")\n");
        }
      else
        if(query_verb()=="tf" || query_verb()=="telepathyfeel") {
          tell_object(player_list[i],
                BOLD+":[ "+NORM+capitalize(TPRN)+" "+str+"\n");
        }
        else {
          tell_object(player_list[i],
               BOLD+":[ "+NORM+capitalize(TPRN)+" . o O ("+str+")\n");
        }
  }
}
return 1;
}
