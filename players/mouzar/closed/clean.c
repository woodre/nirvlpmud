id(str) {return str == "cleaner";  }
short() {return "A Cleaner";}
long() {write("Made to get rid of shit I don't want in my inv.\n"); return 1; }
get() {return 1;}
init() {
 add_action("clean1","clean");
}
clean1(where) {
  if (where)
    where_obj=find_player(where);
  else
    where_obj=environment(this_player());
  if (!where_obj) {
    write("I can't find it. ("+where+")\n");
    return 1;
  }
   /* build a table of what's there */
  for (item_counter=0; item_counter < sizeof(item_name_array); item_counter++) {
    item_name_array[item_counter]=0;
    item_obj_array[item_counter]=0;
  }
  item = first_inventory(where_obj);
  item_counter=0;
  while(item) {
    item_counter++;
    how_many=item_counter;
    item_obj_array[item_counter]=item;
    if (item->query_short()) item_name_array[item_counter]=item->query_short();
    if (!item_name_array[item_counter])
      item_name_array[item_counter]=item->short();
    if (!item_name_array[item_counter])
      item_name_array[item_counter]="no short";
    item = next_inventory(item);
  }
  if (!item_name_array) {
    write("I can't find any items there.\n");
    return 1;
  }
  /* cycle through the table & show the items */
  write("These are the items:\n");
  item_counter=0;
  while (item_counter < how_many) {
    item_counter++;
    if (item_obj_array[item_counter]) {
      write("["+item_counter+"]  ");
      if (item_name_array[item_counter]=="no short") {
        write("no short.  obj=");
        write(item_obj_array[item_counter]);
        write("\n");
      }
      else {
        write(item_name_array[item_counter]+"\n");
      }
    }
  }
  str=0;
  delete_item=0;
  input_to("yes_trash_it");
  write("\nEnter the # of the item to delete (0 if none)\n");
  return 1;
}

/* enter this from input_to in rclean() only */
yes_trash_it(str) {
  sscanf(str, "%d", delete_item);
  if (!intp(delete_item)) {
    write("Ok.  Not trashing anything.\n");
    return 1;
  }
  if (!delete_item) {
    write("No items destructed.\n");
    return 1;
  }
  for (item_counter=0; item_counter < sizeof(item_name_array); item_counter++) {
    if (item_counter == delete_item) {
      destruct(item_obj_array[item_counter]);
      write("Item destructed.\n");
    }
  }
  return 1;
 }
