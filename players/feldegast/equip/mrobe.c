#define MAX_ITEMS 2
inherit "obj/armor";

reset(arg) {
  set_name("robe");
  set_alias("robes");
  set_short("Magician's Robes");
  set_ac(3);
  set_type("armor");
  set_weight(2);
  set_value(2500);
  set_long(
"This voluminous hooded robe is embossed with powerful runes of\n"+
"protection, making it a formidable armor, as well as an excellent\n"+
"place for hiding objects in its hidden folds.\n");
}
can_put_and_get() {
  if(query_verb() &&
     query_verb()=="put" &&
     sizeof(all_inventory(this_object())) > MAX_ITEMS)
    return 0;
  return 1;
}
prevent_insert() {
  if(first_inventory(this_object())) {
    write("You can't when there are things in the bag.\n");
    return 1;
  }
}
add_weight(w) {
  return 1;
}
