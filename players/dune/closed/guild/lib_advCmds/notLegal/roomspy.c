#include "../DEFS.h"
#define LEVEL  6
#define DRAIN  25


status main(string str) {
  /* Shows environment of a player and what players are wielding */
  object player, room, tmp;
  object * allroom;
  int i;

  if(!gotrank(TP, LEVEL)) return 0;
  if(!gotsp(TP,   DRAIN)) return 1;
  if(!str || !find_player(str)) {
    write("Usage: roomspy <player>.\n"); 
    return 1; }
  player = find_player(str);
  if((int)player->query_invis()) {
    write("Player ["+capitalize(str)+"] not found.\n");
    return 1; }
  if((int)player->query_level() > 19) {
    write("You aim the spy satellite to spy on a wizard, \n"+
          "but the wizard somehow remains unseen.\n");
    return 1; }
  room    = environment(player);
  allroom = all_inventory(room);
  write(BOLD+"~~~ SPY SATELLITE DOWNLOAD ~~~"+OFF+"\n");
  write("\n\n"+GREEN+"--["+(string)room->short()+"]--"+OFF+"\n");
  write((string)room->long());
  return 1;
  for(i = 0; i < sizeof(allroom); i++) {
    if( allroom[i]->is_player() && allroom[i]->query_invis() ) continue;
    if(allroom[i]->query_short() && strlen((string)allroom[i]->query_short()) < 3) 
      continue;
    else {
      write(allroom[i]->short());
      if((tmp = (object)allroom[i]->query_weapon()) && (string)tmp->short()) {
        write("\n  "+BOLD+"Using:"+OFF+":  "+(string)tmp->short()+"\n");
      }
    }
  }
  write("\n\n");
  TP->add_spell_point(-DRAIN);
  return 1;
}