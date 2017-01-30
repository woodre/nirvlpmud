/* Shardak guild, (tm) Dragnar/John
 * Portable shop/Demon merchant is (c) Balowski/Rasmus, 950201
 *   "Mowing down mc's like I'm mowing the lawn"
 */
#define BACKSHOP "players/dragnar/guild/rooms/backshop"

int total;       /* total price */
int items;       /* number of items sold */

annoy() {
  say( "The demon seems slightly annoyed with " + this_player()->query_name());
}

sell_contents( object bag) {
  object ob, next;

  ob= first_inventory( bag);
  if (!ob)
    write( "The demon mumbles, \"Hmm... empty.\"\n");

  for (; ob; ob= next) {
    next= next_inventory( ob);
    do_sell( ob);
  }
}

do_sell( object ob) {
  int value;

  value= ob->query_value();
  if (value == 0) {
        if( ob->query_short() != 0 ) {
    	write( "The demon shakes its head in refusal, \"Worthless.\"\n");
    	return;
	}
  }

  if (query_attribute( "*", ob)) {
    write( "The demon says, \"" + ob->short() + " is tagged.\"\n");
    return;
  }

  if (ob->query_worn() || ob == this_player()->query_weapon()) {
    write( "The demon says, \"" + ob->short() + " is equipped.\"\n");
    return;
  }

  if (ob->can_put_and_get())
    sell_contents( ob);

  if (transfer( ob, BACKSHOP)) {
    if (!ob)
      write( "The demon throws back its head and cackles with glee.\n");
    else
      write( "The demon shrugs and says, \"" + ob->short() +
          " will not move into my sack.\"\n");
    return;
  }

  if (value > 1000) {
    value= value + random(100);
    print( "The demon says, \"Principles prevent me from paying you \
more than " + value + " gold coins for " + ob->short() + ".\"\n");
  }
  else
    print( "The demon says, \"For " + ob->short() + " I shall pay you " +
        value + " gold coins.\"\n");

  items++;
  total+= value;
}

sell_all() {
  object ob, next;

  for (ob= first_inventory( this_player()); ob; ob= next) {
    next= next_inventory( ob);
    /* only sell invisible object is player explicitly says so */
    if (ob->short())
      do_sell( ob);
  }
}

sell( string what) {
  object ob;

  items= total= 0;

  if (!what) {
    write( "The demon asks you slightly annoyed, \"Sell what?\"\n");
    annoy();
    return 1;
  }

  if (what == "all")
    sell_all();
  else {
    ob= present( what, this_player());
    if (!ob) {
      write( "The demon hisses, \"Such an Item hast thou not.\"\n");
      annoy();
    }
    else
      do_sell( ob);
  }

  /* say something */
  return 1;
}
