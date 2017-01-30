int digcount;
id(str) { return str == "office"; }
init() {
if(set_light(0)==0)
       set_light( 1);
      add_action("south","south");
      add_action("sell","sell");
}
 short() { return "Legion of the dead benifit office."; }
long() {
  write("As one of the benifits of the legion you may now sell the corpses\n"+
    "of anything that you kill. You can recieve up to 50 gold coins for each\n"+
   "corpse that you bring in.  To this just type 'sell corpse' however, you\n"+
  "must be a member to do so.\n");
write("There is only one exit to the south.\n");
}
 south() {
  digcount = 0;
 call_other(this_player(), "move_player", "south#players/boltar/sprooms/dead_office.c");
   return 1;
}
 up() {
     call_other(this_player(), "move_player", "into up#players/boltar/lv2/gamblerroom.c");
  return 1;
}
sell(item) {
  int amount;
  object ob;
  string name_of_item;
   if(item != "corpse") { 
    return 1;
}
    if(call_other(this_player(), "query_title", 0) != "of the legion of the dead.") {
write("You are not a member!\n");
return 1;
}

    if (!item)
	return 0;
    name_of_item = present(item, this_player());
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
   write("You don't have a corpse to sell!!\n");
	return 1;
    }
    if (environment(name_of_item) == this_player()) {
        int weight;
	if (call_other(name_of_item, "drop", 0)) {
	    write("I can't take it from you!\n");
	    return 1;
	}
        weight = call_other(name_of_item, "query_weight", 0);
	call_other(this_player(), "add_weight", - weight);
 }
    say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(name_of_item, "short", 0) + ".\n");

   amount = 1 + random(49);
    call_other(this_player(), "add_money", amount);
   write("You get " + amount + " gold coins for the corpse.\n");
  destruct(name_of_item);
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
