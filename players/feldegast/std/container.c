
inherit "obj/treasure";

int max_items;

int reset(int arg) {
  set_id("container");
  set_short("A container");
  set_weight(1);
  set_long("You see nothing special.\n");
}
can_put_and_get() {
  if(query_verb() &&
     query_verb()=="put" &&
     sizeof(all_inventory(this_object())) > max_items)
    return 0;
  return 1;
}
prevent_insert() {
  if(first_inventory(this_object())) {
    write("You can't when there are things in the backpack.\n");
    return 1;
  }
}
add_weight(w) {
  return 1;
}
