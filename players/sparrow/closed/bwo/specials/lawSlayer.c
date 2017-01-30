
#include <ansi.h>

int main(object atk){
  int sps;
  /* uncomment for guild rank check
  if(this_player()->query_guild_rank() < 2) {
    return 0;
  } */
  if(atk->query_alignment() < 500) {
    return 0;
  }
  sps = random(5)+5;
  if(this_player()->query_sp() < sps) {
    return 0;
  }
  tell_room(environment(this_player()),
  HIY+"Good"+NORM+" is destroyed by "+HIC+"||"+HIK+"Dark Retribution"+HIC+"||\n"+NORM);
  return sps;
}
