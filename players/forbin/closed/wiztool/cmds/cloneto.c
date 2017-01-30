/* clone to player command */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"

main(str) {
  string who, path; object player, thing;
  if(!str || sscanf(str,"%s %s",who,path) != 2) {
    FAIL("Syntax: 'cloneto <player> <path>'\n");
      return 0; 
  }
  player = find_player(who);
  if(!player) {
    FAIL("Player not logged on.\n");
      return 0; 
  }
  thing = CO(path);
  MO(thing,player);
  write("You send the object to "+player->QN+".\n");
  tell_object(player, WTC+"\t\t=~=~=~= something has been placed in your inventory =~=~=~=\n"+NORM);
  player->recalc_carry();
    return 1; 
}
