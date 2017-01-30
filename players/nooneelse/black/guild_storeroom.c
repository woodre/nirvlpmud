/*
  guild_shop_storeroom.c
*/

#define MAX_LIST 15

inherit "players/nooneelse/black/guild_rooms";

int item_value, times_more, we_are_ok, i, j, x;
int nbr_inventory_items, save_list_ptr;
object obj, item_obj, inventory_obj_array;
string save_str, item_name;

init() {
  add_action("north", "north");
  check_membership(this_player());
}

north() {
  this_player()->move_player("north#players/nooneelse/black/guild_shop");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  inventory_obj_array = allocate(500);
  if(!we_are_ok) inventory("all");
}

short() { return "Storeroom for the Vampire Guild's Shop"; }

long() { write("All things from the Vampire Guild's Shop are stored here.\n"); }

inventory(str) {
  int line_ctr, list_ptr;
  object rope_obj;
  if (!present("rope")) {
    rope_obj=clone_object("/obj/rope");
    store(rope_obj);
  }
  if (!str) str = "all";
  if (str=="cont") {
    str=save_str;
    list_ptr=save_list_ptr;
  }
  else {
    fill_inventory();
    list_ptr=0;
  }
  if (!nbr_inventory_items) {
    write("Sorry, the shop is empty right now.\n");
    return 1;
  }
  line_ctr=0;
  while (line_ctr < MAX_LIST) {
    obj = inventory_obj_array[list_ptr];
    if (obj) {
      if (str=="all") list(obj, list_ptr+1);
      if (str=="weapons" && obj->weapon_class()) list(obj, list_ptr+1);
      if (str=="armors" && obj->armor_class()) list(obj, list_ptr+1);
      if (str=="armours" && obj->armor_class()) list(obj, list_ptr+1);
      if (str=="misc" && !obj->armor_class() && !obj->weapon_class())
        list(obj, list_ptr+1);
    }
    line_ctr++;
    list_ptr++;
  }
  save_str=str;
  save_list_ptr=list_ptr;
  if (list_ptr < nbr_inventory_items) {
    write("Continue listing? [y]: ");
    input_to("list_more");
    return;
  }
}

list(obj, arg) {
  int item_value;
  item_value = obj->query_value();
  if (item_value)
    write("["+arg+"]"+"\t"+item_value+"\t: "+obj->short()+".\n");
}

static list_more(str) {
  write("\n");
  if (str=="y" || str=="") inventory("cont");
  return;
}

value(item_name) {
  item_obj = present(item_name);
  if (!item_obj) return;
  item_value = item_obj->query_value();
  if (!item_value) return;
  write("The "+item_name+" would cost you "+item_value+" gold coins.\n");
  return 1;
}

buy(item_name) {
  sscanf(item_name, "%d", j);
  i=j-1;
  fill_inventory(item_name);
  /* item_name came in as the name of an item */
  if (x >= 0) {
    i=x;
    do_buy_it(item_name);
    return 1;
  }
  if (i >= nbr_inventory_items) {
    i=i+1;
    write("But, there is no item # '"+i+"'.\n");
    return 1;
  }
  if (x < 0 && item_name > "9") {
   write("But, there is no '"+item_name+"'.\n");
   return 1;
  }
  /* item_name came in as numeric */
  item_name = inventory_obj_array[i]->short();
  do_buy_it(item_name);
  return 1;
}

do_buy_it(item_name) {
  if (!item_name) {
    write("There are no '"+item_name+"'s in the store.\n");
    return;
  }
  item_obj = inventory_obj_array[i];
  item_value = item_obj->query_value();
  if (!item_value) {
    write(capitalize(item_name)+" has no value.\n");
    return;
  }
  if (this_player()->query_money() < item_value) {
    write("It would cost you "+item_value+
          " gold coins, which you don't have.\n");
    return;
  }
  if (!this_player()->add_weight(item_obj->query_weight())) {
    write("You can't carry that much.\n");
    return;
  }
  this_player()->add_money(- item_value);
  move_object(item_obj, this_player());
  write("Ok.\n");
  say(capitalize(this_player()->query_name())+" buys "+item_obj->short()+".\n");
}

store(item_obj) {
  string short_desc;
  short_desc = item_obj->short();
  obj = first_inventory(this_object());
  while(obj) {
    /* is it a duplicate item?  if so, destruct it */
    if (obj->short()==short_desc) {
      /* Move it before destruct,
         because the weight has already been compensated for. */
      move_object(item_obj, this_object());
      destruct(item_obj);
      return;
    }
    obj = next_inventory(obj);
  }
  move_object(item_obj, this_object());
}

fill_inventory(item_name) {
  for (j=0; j<500; j++) inventory_obj_array[j]=0;
  obj = first_inventory(this_object());
  j=0;
  x=-666;
  while(obj) {
    if (item_name && obj->id(item_name)) x=j;
    inventory_obj_array[j] = obj;
    j++;
    obj = next_inventory(obj);
  }
  nbr_inventory_items = j;
}

is_castle() { return 1; }

realm() { return "NT"; }
