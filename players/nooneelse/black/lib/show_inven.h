/*
  show_inven.h
*/

#include "defs.h"

/* --------- Display the inventory & help info for the fangs -------- */
show_inven() {
  int weight_carried, player_max;
  object obj;
  obj = first_inventory(MY_PLAYER);
  if(!obj) {
    write("You are carrying nothing.\n");
    return 1;
  }
  while (obj) {
    if(obj->short()) write(obj->short()+".\n");
    else
    if(obj->query_name()) write(obj->query_name()+".\n");
    else
    if(obj->query_real_name()) write(obj->query_real_name()+".\n");
    weight_carried = weight_carried + obj->query_weight();
    obj = next_inventory(obj);
  }
  player_max = MY_LEVEL + 6 + MY_STR / 5;
  if (MY_LEVEL==1) player_max = MY_LEVEL + 6 + MY_STR / 2;
  if (MY_PLAYER->query_frog()) player_max = player_max / 2;
  write("You are carrying "+100*weight_carried / player_max+
        "% of your maximum capacity.\n\n");
  MY_FANGS->show_guild_stuff();
  return 1;
}
