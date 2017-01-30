#include "/players/feldegast/defines.h"

int do_cmd(string str) {
  object ob,nob;
  ob=first_inventory(environment(TP));
  while(ob) {
    nob=next_inventory(ob);
    if(!(ob->is_player())) destruct(ob);
    ob=nob;
  }
  write("Room cleaned.\n");
  say(TPN+" clears the room with a wave of "+TP->query_possessive()+" hand.\n");
  return 1;
}
