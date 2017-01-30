/*
 trasher.c - destroy selected items in a player/object
             (for when the short() is screwed up & you can't get rid
              of the item any other way)
*/

inherit "/obj/treasure";

string where_str, str, str2, item_name;
object item, where_obj, item_obj;
int item_counter, how_many, delete_item;

init() {
  add_action("trash_the_crap", "clean");
}

trash_the_crap(where_str) {
  if (where_str)
    where_obj=find_player(where_str);
  else
    where_obj=environment(this_player());
  if (!where_obj) {
    write("I can't find it. ("+where_str+")\n");
    return 1;
  }

/* build a table of what's there */
  for (item_counter=0; item_counter < sizeof(item_name); item_counter++) {
    item_name[item_counter]=0;
    item_obj[item_counter]=0;
  }
  item = first_inventory(where_obj);
  item_counter=0;
  while(item) {
    item_counter++;
    how_many=item_counter;
    item_obj[item_counter]=item;
    if (item->query_short()) item_name[item_counter]=item->query_short();
    if (!item_name[item_counter]) item_name[item_counter]=item->short();
    if (!item_name[item_counter]) item_name[item_counter]="no short";
    item = next_inventory(item);
  }
  if (!item_name) {
    write("I can't find any items there.\n");
    return 1;
  }

/* cycle through the table & show the items */
  write("These are the items:\n");
  item_counter=0;
  while (item_counter < how_many) {
    item_counter++;
    if (item_obj[item_counter]) {
      write("["+item_counter+"]  ");
      if (item_name[item_counter]=="no short") {
        write("no short.  obj=");
        write(item_obj[item_counter]);
        write("\n");
      }
      else {
        write(item_name[item_counter]+"\n");
      }
    }
  }
  str=0;
  delete_item=0;
  input_to("yes_do_it");
  write("\nEnter the # of the item to delete (0 if none)\n");
  return 1;
}

/* enter this from input_to only */
yes_do_it(str) {
  sscanf(str, "%d", delete_item);
  if (!intp(delete_item)) {
    write("Ok.  Not trashing anything.\n");
    return 1;
  }
  if (!delete_item) {
    write("No items destructed.\n");
    return 1;
  }
  for (item_counter=0; item_counter < sizeof(item_name); item_counter++) {
    if (item_counter == delete_item) {
      destruct(item_obj[item_counter]);
      write("Item destructed.\n");
    }
  }
  return 1;
}

reset(arg) {
  if (arg) return;

  set_short(
    "A device to destroy objects in rooms/players that can't be referenced.\n"+
    "Use: 'clean <object>'");
  set_long(
    "A device to destroy objects in rooms/players that can't be referenced.\n"+
    "Use: 'clean <object>'\n");
  set_value(0);
  set_weight(0);
  item_obj=allocate(30);
  item_name=allocate(30);
}

id(str) { return (str=="trasher"); }
