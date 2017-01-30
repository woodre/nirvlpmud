/* gives a player a device to communicate with an invisible me */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"
#define FTELL "/players/forbin/closed/ftell"

status main(string who) {
  object player, teller;
  if(!who) {
    FAIL("Usage: ftell <who>\n");
      return 0; 
  }
  player = find_player(who);
  teller = CO(FTELL);
  MO(teller,player);
  write("You give "+player->query_name()+" a ftell.\n");
  tell_object(player, WTC+"\t\t=~=~=~= "+HIW+"you have been given a ftell"+WTC+" =~=~=~=\n"+NORM);
  player->recalc_carry();
    return 1; 
}
