#define MAX_ITEMS 16
#define MAX_WEIGHT 29
inherit "obj/treasure";

int local_weight;

reset(arg) {
  set_id("backpack");
  set_alias("pack");
  set_short("Leather Backpack");
  set_weight(2);
  set_value(500);
  set_long(
"This is a good-sized leather backpack with straps on it for affixing\n"+
"numerous objects.\n");
}
can_put_and_get() {
  if(query_verb() &&
     query_verb()=="put" &&
    (sizeof(all_inventory(this_object())) > MAX_ITEMS ||
    local_weight > MAX_WEIGHT))
    return 0;
  return 1;
}
prevent_insert() {
  if(first_inventory(this_object())) {
    write("You can't when there are things in the backpack.\n");
    return 1;
  }
}
add_weight(int w) {
  local_weight+=w;
  return 1;
}
