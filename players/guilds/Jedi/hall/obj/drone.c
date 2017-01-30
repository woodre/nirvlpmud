#include "../defs.h"
#define THIS_WEIGHT 1

object where;
string clanName;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("drone");
   set_short("A drone");
   set_long("A drone. It can 'ship_item' from your inventory to its home.\nOne shipment per drone.\n");
   set_weight(THIS_WEIGHT);
}

init() {
   ::init();
   
   add_action("ship_item","ship_item");
   
}

set_where(object obj) { where = obj; }
set_clan_name(string str) { clanName = str; }

int ship_item(string str) {
   object item;
   int weight;
   
   if(!str) {
      write("What would you like to ship?\n");
      return 1;
   }
   
   if(!present(this_object(),this_player()))
      return 0;
   
   if(!where) {
      write("Error! Missing home.\n");
      return 1; }
   
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if((string)TP->query_clan_name() != clanName) {
      write("This drone does not belong to your clan.\n");
      return 1;
   }
   
   if(TP->query_ghost())
      {
      write("You're dead. Please lie still.\n");
      return 1;
   }
   
   item = present(str,this_player());
   
   if (!item) {
      write("No such item '" + str + "' in your inventory.\n");
      return 1;
      
   }
   
   if (item == this_object()) {
      write("Drones cannot be shipped.\n");
      return 1;
   }
   
   
   if(item->drop()) {
      write("You cannot ship that item.\n");
      return 1;
   }
   
   weight = (int)item->query_weight();
   TP->add_weight(-weight);
   move_object(item,where);
   TP->add_weight(-THIS_WEIGHT);
   write("The drone delivers your '" + str + "' to its home.\n");
   destruct(this_object());
   
   return 1;
}
