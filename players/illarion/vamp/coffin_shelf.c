/*
  guild_coffin_shelf.c
*/

#include "/players/eurale/defs.h"
int value_on_shelf;

init() {
  int save_value_on_shelf;
  save_value_on_shelf = value_on_shelf;
  restore_object("players/eurale/VAMPIRES/OBJ/shelves/"+
                 environment(this_object())->query_coffin_owner_name());
  if (!save_value_on_shelf == 0 && value_on_shelf == 0)
    value_on_shelf = save_value_on_shelf;
  save_object("players/eurale/VAMPIRES/OBJ/shelves/"+
              environment(this_object())->query_coffin_owner_name());
  add_action("place",         "place");
  add_action("recover",      "recover");
  add_action("value_shelf",   "value");
  add_action("restore_value", "restore");
  add_action("put",           "put");
  add_action("get",           "get");
  add_action("get",           "take");
}

id(str) { return str == "shelf"; }

long() { write(
  "A narrow shelf encircling your coffin for storing items. You can\n"+
  "use the shelf with the following commands:\n\n"+
  "  'place <item> on shelf'\n"+
  "  'recover <item> from shelf'\n"+
  "  'value shelf' (gives you coin equivalent of items on shelf)\n"+
  "  'restore value from shelf' (gives you $ equivalent from shelf)\n\n"+
  "NOTE: The value of the items on the shelf will be saved in case of\n"+
  "a crash or reboot and restored to you.  Using 'restore value' will\n"+
  "destroy all items on your shelf and return their $ amount to you.\n");
}

can_put_and_get() { return 1; }

place(str) {
  int item_value;
  string item;
  object item_obj, item_on_shelf_obj;

if(!str) { write("Place what?\n"); return 1; }

if(sscanf(str, "%s on shelf", item) != 1) {
  write("Place what 'on shelf'?\n");
  return 1; }

if(item == "all") {
  write("No!  You must place each item on individually.\n");
  return 1; }

if(item == "shelf") {
  write("Huh?  You want to place the shelf on the shelf?\n");
  return 1; }

item = lower_case(item);
item_obj = present(item, this_player());
if(!item_obj) {
  write("You have no "+item+"!\n");
  return 1; }

if(call_other(item_obj, "prevent_insert")) return 1;
if(call_other(item_obj, "drop")) return 1;
item_value = item_obj->query_value();
if(item_value > 1000) item_value=1000;
if(item_value <= 0) {
  write("That item has no value.  "+
        "There's no sense in storing it on the shelf.\n");
  return 1; }

restore_object("players/eurale/VAMPIRES/OBJ/shelves/"+
               environment(this_object())->query_coffin_owner_name());
item_on_shelf_obj=first_inventory(this_object());
if(!item_on_shelf_obj && value_on_shelf) {
  write("You take the "+value_on_shelf+
        " coins from the shelf to make room or the new items.\n");
  this_player()->add_money(value_on_shelf);
  value_on_shelf = 0;
  save_object("players/eurale/VAMPIRES/OBJ/shelves/"+
              environment(this_object())->query_coffin_owner_name());
  }
this_player()->add_weight(- item_obj->query_weight());
move_object(item_obj, this_object());
value_on_shelf += item_value;
save_object("players/eurale/VAMPIRES/OBJ/shelves/"+
            environment(this_object())->query_coffin_owner_name());
say(this_player()->query_name()+" places the "+item+" on the shelf.\n");
write("You put a "+item+" on the shelf.\n");
return 1;
}

recover(str) {
  int item_value;
  string item;
  object item_obj;

if(!str) { write("Recover what?\n"); return 1; }

if(sscanf(str, "%s from shelf", item) != 1) {
  write("Recover what 'from shelf'?\n");
  return 1; }

if(item == "all") {
  write("No!  You must recover each item individually.\n");
  return 1; }

if(item == "shelf") {
  write("Huh?  You want to recover the shelf from the shelf?\n");
  return 1; }

item = lower_case(item);
item_obj = present(item, this_object());
if(!item_obj) {
  write("There is no "+item+" on the shelf!\n");
  return 1; }

item_value = item_obj->query_value();
if(item_value > 1000) item_value = 1000;
restore_object("players/eurale/VAMPIRES/OBJ/shelves/"+
               environment(this_object())->query_coffin_owner_name());
  this_player()->add_weight(item_obj->query_weight());
move_object(item_obj, this_player());
value_on_shelf -= item_value;
if (value_on_shelf < 0) value_on_shelf = 0;
save_object("players/eurale/VAMPIRES/OBJ/shelves/"+
            environment(this_object())->query_coffin_owner_name());
say(this_player()->query_name()+" recovers the "+item+" from the shelf.\n");
write("Ok.\n");
return 1;
}

value_shelf(str) {
  if (!id(str)) return;
  restore_object("players/eurale/VAMPIRES/OBJ/shelves/"+
                 environment(this_object())->query_coffin_owner_name());
  write("The value of the items on the shelf is "+value_on_shelf+" coins.\n");
  return 1;
}

restore_value(str) {
  object item_obj, save_item_obj;
  int difference;

  if ( !str || !(str=="value from shelf"))
  {
    notify_fail("What are you trying to restore?\n");
    return 0;
  }
/*  Added parenthesis around expression for correct evaluation */
/*  Previously, it didn't check if a str existed. Vital        */
  restore_object("players/eurale/VAMPIRES/OBJ/shelves/"+
                 environment(this_object())->query_coffin_owner_name());
  item_obj=first_inventory(this_object());
  while (item_obj) {
    save_item_obj=item_obj;
    item_obj=next_inventory(item_obj);
    destruct(save_item_obj);
  }
  write("You take the "+value_on_shelf+" coins from the shelf.\n");

  if(this_player()->query_money() > 79999)
  {
    write("You have the maximum amount of coins.\n");
    write("The restored coins are placed in your inventory.\n");
    call_other(this_player(), "add_money", value_on_shelf);
  }
  if(this_player()->query_money() + value_on_shelf > 80000)
  {
    difference = 80000 - this_player()->query_money();
    call_other(this_player(), "add_money", difference);
    write("You max your coins and the remaining restored coins are placed in \nyour inventory.\n");
    value_on_shelf=value_on_shelf-difference;
  }
  call_other(this_player(), "add_money", value_on_shelf);
  value_on_shelf=0;
  save_object("players/eurale/VAMPIRES/OBJ/shelves/"+
              environment(this_object())->query_coffin_owner_name());
  return 1;
}

put(str) {
  string str2;
  if (!str) return;
  if (sscanf(str, "%s on shelf", str2)==1) {
    write("You must use 'place <item> on shelf'\n");
    return 1;
  }
}

get(str) {
  string str2;
  if (!str) return;
  if (sscanf(str, "%s from shelf", str2)==1) {
    write("You must use 'recover <item> from shelf'\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;
}
clean_up() { return 0; }
