/*
  Show inventory and help info
*/

#include "/players/eurale/defs.h"

show_inven() {
  int weight_carried, player_max;
  object obj;
obj = first_inventory(TP);

if(!obj) {
  write("You are carrying nothing.\n");
  return 1; }

while (obj) {
  if(obj->short()) write(obj->short()+".\n");
  else if(obj->query_name()) write(obj->query_name()+".\n");
  else if(obj->query_real_name()) write(obj->query_real_name()+".\n");
  weight_carried = weight_carried + obj->query_weight();
  obj = next_inventory(obj);
}

  player_max = TPL + 6 + TPSTR / 5;
  if (TPL==1) player_max = TPL + 6 + TPSTR / 2;
  if (TP->query_frog()) player_max = player_max / 2;
  write("You are carrying "+100*weight_carried / player_max+
        "% of your maximum capacity.\n\n");
write("Type '"+BOLD+"vhelp cult"+NORM+"' for Vampire information.\n");
return 1;
}
