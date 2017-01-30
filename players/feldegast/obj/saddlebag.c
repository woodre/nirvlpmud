
#define MAX_ITEMS 30
inherit "obj/treasure";

reset(arg) {
  set_id("saddlebag");
  set_alias("bag");
  set_short("Leather saddlebag");
  set_weight(2);
  set_value(500);
  set_long(
"This is a large leather saddlebag.\n");
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
    write("You can't when there are things in the backpack.\n");
    return 1;
  }
}
add_weight(w) {
  return 1;
}
init()
{
  add_action("cmd_pack","pack");
  add_action("cmd_unpack","unpack");
}
int cmd_pack(string str)
{
  if(!str)
  {
    notify_fail("Pack what?\n");
    return 0;
  }
  command("put "+str+" in pack",this_player());
  return 1;
}
int cmd_unpack(string str)
{
  if(!str)
  {
    notify_fail("Unpack what?\n");
    return 0;
  }
  return command("get "+str+" from pack",this_player());
}
