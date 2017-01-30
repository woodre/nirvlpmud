#include "std_old.h"
inherit "/room/room";
#define tpn this_player()->query_name()

int open;
int X;
int unlock;

reset(arg) {
open = 0;
   if(arg) return;

 long_desc =
 "     You are in a merchant shop.  When the galleys port, the traders\n"+  
   "come here to buy or sell goods.  Behind the counter, the shelves made\n"+
   "into the stone wall are stocked with different items to buy or sell.\n"+
   "Commands are: 'buy item', 'sell item', 'sell all', 'list', 'list weapons'\n"+
   "'list armors' and 'value item'.\n" +
   "To the east leads back to the town street.\n"+
   "A door is south of here.\n";
 
   items = ({
         "counter","The counter is long and curved in the middle of the room",
         "wall","Some shelves are made into the stone wall",
         "door","The door leads to a small room, maybe you could enter",
          });
 
dest_dir = ({
 
         "/players/brittany/kadath/k23.c","east",
      "/players/brittany/kadath/k25.c","south",
          });
 
    set_light( 1);
}
short() {
    return  "The Merchants shop";
}
init() {
::init();
add_action("open_door"); add_verb("open");
add_action("unlock_door"); add_verb("unlock");
add_action("sell"); add_verb("sell");
add_action("value"); add_verb("value");
add_action("buy"); add_verb("buy");
add_action("east"); add_verb("east");
add_action("south"); add_verb("south");
add_action("list"); add_verb("list");
add_action("search"); add_verb("search");
}


east() {
this_player()->move_player("east#/players/brittany/kadath/k23.c"); 
return 1; }

sell(item) {
   object ob;
   
   if (!item)
      return 0;
   if (item == "all") {
      object next;
      ob = first_inventory(this_player());
      while(ob) {
         next = next_inventory(ob);
         if (!ob->drop() && ob->query_value()) {
            write(ob->short() + ":\t");
            do_sell(ob);
            }
         ob = next;
       }
      write("Ok.\n");
      return 1;
   }
   ob = present(item, this_player());
   if (!ob)
      ob = present(item, this_object());
   if (!ob) {
      write("No such item ("); write(item); write(") here.\n");
      return 1;
   }
do_sell(ob);
return 1;
}

do_sell(ob) {
   int value, do_destroy;
   value = ob->query_value();
   if (!value) {
      write(ob->short() + " has no value.\n");
      return 1;
   }
   if (environment(ob) == this_player()) {
      int weight;
      if (call_other(ob, "drop", 0)) {
         write("I can't take it from you!\n");
         return 1;
       }
      weight = call_other(ob, "query_weight", 0);
      call_other(this_player(), "add_weight", - weight);
   }
   if (value > 6000)
      do_destroy = 1;
   if(ob->query_dest_flag()) do_destroy = 1;
   if (value > 1000) {
      write("The shop is low on money...\n");
      value = 1000;
   }
   write("You get "); write(value); write(" gold coins.\n");
   say(call_other(this_player(), "query_name", 0) + " sells " +
      call_other(ob, "short", 0) + ".\n");
   call_other(this_player(), "add_money", value);
   if (do_destroy) {
      write("The valuable item is hidden away.\n");
      destruct(ob);
      return 1;
   }
     call_other("/players/brittany/kadath/OBJ/britstore.c", "store", ob);
   return 1;
}

value(item) {
   int value;
   string name_of_item;
   
   if (!item)
      return 0;
   name_of_item = present(item);
   if (!name_of_item)
      name_of_item = find_item_in_player(item);
   if (!name_of_item) {
   if  (call_other("/players/brittany/kadath/OBJ/britstore.c", "value", item))
         return 1;
      write("No such item ("); write(item); write(") here\n");
      write("or in the store.\n");
      return 1;
   }
   value = call_other(name_of_item, "query_value", 0);
   if (!value) {
      write(item); write(" has no value.\n");
      return 1;
   }
   write("You would get "); write(value); write(" gold coins.\n");
   return 1;
}

buy(item) {
   if (!item)
      return 0;
   call_other("/players/brittany/kadath/OBJ/britstore.c", "buy", item);
   return 1;
}
list(obj) {
   call_other("/players/brittany/kadath/OBJ/britstore.c", "inventory", obj);
   return 1;
}

find_item_in_player(i)
{
   object ob;
   
   ob = first_inventory(this_player());
   while(ob) {
      if (call_other(ob, "id", i))
         return ob;
      ob = next_inventory(ob);
   }
   return 0;
}
south(str) {
if(!open){
write("The door is closed.\n");
return 1;
}
   write("You walk through the door.\n\n");
   say(tpn+"  walks through the door.\n");
   this_player()->move_player("south#/players/brittany/kadath/k25.c");
return 1; }
 
unlock_door(str) {
   if(!present("merchant_key",this_player())) {
      notify_fail("You need a key to unlock it.\n");
      return 0; }
 
   if(!str || str != "door") {
      notify_fail("Unlock what?\n");
      return 0; }
      if(X==0) {
         write("The door clicks as it unlocks.\n");
         X ++;
         return 1; }
   }
 
open_door(str) {
if(!str || str != "door") {
         notify_fail("Open what?\n");
         return 0; }
 
      if(X==0) {
         notify_fail("The door is locked.\n");
         return 0; }
 
      if(X==1) {
         write("The door opens.\n");
         open = 1;
         X ++;
         return 1; }
 
      if(X==2) {
         notify_fail("The door is already open.\n");
         return 0; }
   }
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

query_drop_castle() {
return 1;
}
