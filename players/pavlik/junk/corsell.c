int digcount;
sell(item) {
  int amount;
  object ob;
  string name_of_item;
   if(item != "corpse") { 
    return 1;
}
    if (!item)
	return 0;
    name_of_item = present(item, this_player());
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
 write("You gotta have a corpse to sell...here, take this organ\n"+
  "donors card and go find you a corpse!\n");
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

   amount = 50 + random(50);
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
