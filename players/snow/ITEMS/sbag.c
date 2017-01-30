inherit "/players/snow/ITEMS/bag.c";

init() {
  add_action("bag_scoop","bagscoop");
}

bag_scoop(string str) {
  object ob;
  if(!str) { write("Usage: bagscoop <object>\n"); return 1; }
  ob = present(str, environment(this_player()));
  if(!ob) {
    write(capitalize(str)+" is not here!\n");
    return 1; }
  if(!ob->query_value()) {
    write("Your bag will not deign to scoop such a worthless item.\n");
    return 1; }
  if(!ob->get()) {
    write("Your bag cannot scoop that!\n");
    return 1; }
  if(!add_weight(ob->query_weight())) {
    write("Your bag is too full to carry more!\n");
    return 1; }
  move_object(ob, this_object());
  write("Your bag has scooped the "+str+"!\n");
  say(this_player()->query_name()+"'s bag scoops up "+str+"!\n");
  return 1; }
