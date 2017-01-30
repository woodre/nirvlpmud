#include "defs.h"

int items;

sell_contents( object bag) {
  object ob, next;

  ob= first_inventory( bag);
  if (!ob)
    write( "The "+bag->short()+" is empty.\n");

  for (; ob; ob= next) {
    next= next_inventory( ob);
    move_object(ob, this_player());
    write(ob->short()+":\t");
    do_sell(ob, 0);
    if(present(ob,this_player())) move_object(ob, bag);
  }
}

do_sell( object ob, int lock_check ) {

  if( lock_check ) {
    if( query_lock( ob ) ) {
      write(ob->short()+" is locked.\n");
      return;
    }
    if (ob->query_worn() || ob == this_player()->query_weapon()) {
      write(ob->short()+" is equiped.\n");
      return;
    }
  }

  if (ob->can_put_and_get())
    sell_contents(ob);

  if(query_lock(ob)) delete_attribute( "[Locked]", ob);
  if(items) write(ob->short()+":\t");
  environment(this_player())->sell(ob);

  items++;
}

sell_all( object who, int check_lock, string type ) {
  object ob, next;

  for(ob=first_inventory(who); ob; ob = next ) {
    next = next_inventory( ob );
      if(ob->short() && ob->query_value() > 0 && ( !type || ob->id( type )) ) {
        do_sell(ob, check_lock);
      }
  }
}

main( string what) {
  object ob, the_bag;
  int do_lock_check;
  string all, type, bagname;

  items = 1;
  do_lock_check = 1;

  if(!function_exists("sell", environment(USER))) {
    write("You can't do that here.\n");
	return 1;
  }
  if (!what) {
    write("Sell what?\n");
    return 1;
  }
  if(sscanf(what, "%s from %s",all,bagname)) {
    the_bag = present(bagname, this_player());
    if(!the_bag) {
      write("You don't have a "+bagname+".\n");
      return 1;
    }
	if(!the_bag->can_put_and_get()) {
	  write("You can't do that.\n");
	  return 1;
	}
    if( first_inventory(the_bag) == 0 ) {
      write( "The "+bagname+" is empty.\n");
      return 1;
    }
    if( all == "ALL")
      do_lock_check = 0;
    else {
      do_lock_check = 1;
    }
    sell_contents(the_bag);
    return 1;
  }

  if( what == "all" || what == "ALL" )
    all = what;
  sscanf(what, "%s %s",all,type );
  if( all == "all" || all == "ALL" ) {
        if( all =="all" ) {
      sell_all( this_player(), do_lock_check, type );
    }
    else if( all=="ALL" ) {
      do_lock_check = 0;
      sell_all( this_player(), do_lock_check, type );
    }
    return 1;
  }
  items = 0;
  ob= present( what, this_player());
  if (!ob) {
    write( "You do not have that.\n");
    return 1;
  }
  else {
    do_sell(ob, do_lock_check );
    return 1;
  }

  /* say something */
  write("OK, Sell completed.\n");
  return 1;
}

query_lock(object obj) {
  return query_attribute( "[Locked]", obj);
}
