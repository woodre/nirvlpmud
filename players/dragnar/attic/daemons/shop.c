#include <ansi.h>

#define PAGESIZE 20

/******************************************************************************
 * Program: shop.c
 * Path: /players/dragnar/daemons/shop
 * Type: Daemon
 * Created: July 22nd, 2013 by Dragnar
 *
 * Purpose: Shop Daemon that has all shop functions built into it. Will use
 *          previous_object to query for messages from the shop object that
 *          is calling this daemon. Has the following improvements over
 *          standard shops:
 *          1. Does not limit number of items to 1 per item.
 *          2. Has functions to do checks for equipped/kept items.
 *          3. Allows player to sell all items of a specific type such as
 *             'sell all shakes'
 *          4. Bags are handled nicely in the following ways:
 *             A. When doing sell all, contents of bags are sold automatically
 *             B. Player can do 'sell all from <bag_name>'
 *             C. Items that can not be sold are dumped from the bag when sold
 *                so things like gold coins are not sold in the bag.
 *          5. Players can use 'sell ALL' to override items that are kept
 *             or equipped.
 *          6. List functions can use item types such as armors, weapons, heals
 *             or misc.  Can also list by <item_name>.
 *          7. Players can't identify AC 0 items like they can with /room/shop
 *          8. Issues with listing are resolved by using a shadow object.
 *          9. List functions can be used by bag type objects.
 ******************************************************************************/
int total;       /* total price */
int items;       /* number of items sold */

annoy() {
  say_msg( previous_object(), "query_annoy2" );
}

write_msg( object ob, string func_name, int items, int total ) {
  string str;
  
  str = call_other( ob, func_name, items, total );
  
  if( !str )
    return 0;
  else
    write( str + "\n" );
  
  return 1;
}

say_msg( object ob, string func_name ) {
  string str;
  
  str = call_other( ob, func_name );
  
  if( !str )
    return 0;
  else
    say( str + "\n" );
  
  return 1;
}

int
adjust_value( int value) {
  if( previous_object() )
    return (object) previous_object()->query_backshop() == previous_object() ? value : value * 11/5;
  else
    return value * 11/5;
}

transfer_inventory(object obj1, object obj2 ) {
  int i, size;
  object *inv;
  
  inv = all_inventory( obj1 );
  for( i=0, size = sizeof(inv); i < size; i++ ) {
    move_object(inv[i], obj2 );
  }
}

destroy_inventory( object obj ) {
  int i, size;
  object *inv;
  
  inv = all_inventory( obj );
  for( i=0, size = sizeof(inv); i < size; i++ ) {
    destruct( inv[i] );
  }
}

int
get_container_size( object bag ) {
  return sizeof( all_inventory( bag ) );
}

sell_contents( object bag ) {
  object ob, next;

  ob= first_inventory( bag );
  if (!ob)
    write_msg( previous_object(), "query_empty" );

  for (; ob; ob = next) {
    next= next_inventory( ob);
    do_sell(ob, 0);
  }
}

do_sell( object ob, int lock_check ) {
  int value, value2, weight;
  status dest_flag;
  object store;
  string alt_value_func;
  
  value = ob->query_value();
  weight = ob->query_weight();
  previous_object()->set_obj_short( ob->short() );
  previous_object()->set_obj_value( value );
  
  if (value == 0) {
    write_msg( previous_object(), "query_no_value" );
    return 1;
  }
  
  if( lock_check ) {
    if( ob->queryKept() ) {
      write_msg( previous_object(), "query_is_kept" );
      return 1;
    }
    if( ob->query_worn() || ob == this_player()->query_weapon() ) {
      write_msg( previous_object(), "query_is_eq" );
      return 1;
    }
  }
  else {
    if( ob->queryKept() ) 
      ob->deShadow();
  }
  
  if( ob->short() && ob->drop() ) {
    write_msg( previous_object(), "query_no_drop" );
    return 1;
  }

  if( ob->can_put_and_get() ) {
    sell_contents( ob );
    /** Reset obj short and value for the bag **/
    previous_object()->set_obj_short( ob->short() );
    previous_object()->set_obj_value( value );
    if( get_container_size( ob ) > 0 ) {
      transfer_inventory( ob, environment( this_player() ) );
      write_msg( previous_object(), "query_dump_worthless_bag_items" );
    }
  }
  
  if( value > 60000 || ob->query_dest_flag() ) {
    dest_flag = 1;
  }
  else {
    store = previous_object()->query_backshop();
    if( !( store ) ) {
      store->reset();
    }
    if( move_store( ob ) ) {
      if (!ob)
        write_msg( previous_object(), "query_error" );
      else
        write_msg( previous_object(), "query_no_move" );
      return 1;
    }
  }

  alt_value_func = previous_object()->query_value_func();
  if( alt_value_func )
    value2 = call_other( ob, alt_value_func );
    
  if( value2 > 0 ) {
    value = value2;
    previous_object()->set_obj_value( value );
    /** Special pricing means we must destroy object **/
    dest_flag = 1;
    write_msg( previous_object(), "query_sold" );
  }
  else if (value > 1000) {
    value2 = 1000 + random(500);
    if( value > value2 ) value = value2;
    previous_object()->set_obj_value( value );
    write_msg( previous_object(), "query_sold2" );
  }
  else
    write_msg( previous_object(), "query_sold" );
  
  this_player()->add_money( value );
  
  this_player()->add_weight( - weight);
  say_msg( previous_object(), "query_sold_msg" );
  
  if( dest_flag ) {
    write_msg( previous_object(), "query_dest_msg" );
    destruct( ob );
  }

  items++;
  total += value;
}

sell_all( object who, int check_lock, string type ) {
  object ob, next;

  for(ob=first_inventory(who); ob; ob = next ) {
    next = next_inventory( ob );
    if( ob->short() && ( !type || ob->id( type )) ) {
	    if(ob->query_worn() || ob == who->query_weapon() || ob->queryKept() ) {
		     do_sell(ob, check_lock);
		  }
		  else if(!ob->drop()) {
        do_sell(ob, check_lock);
		  }
    }
  }
  if( items > 1 ) {
    write_msg( previous_object(), "query_total", items, total );
  }
    
}

sell( string what ) {
  object ob, the_bag;
  int do_lock_check;
  string all, type, bagname;

  items= total= 0;
  do_lock_check = 0;

  if (!what) {
    write_msg( previous_object(), "query_annoy" );
    annoy();
    return 1;
  }
  if( sscanf(what, "%s %s",all,type ) == 2 ) {
    if( lower_case(all) == "all" ) {
      if( all == "all" ) {
        do_lock_check = 1;
      }
      if( all == "ALL" ) {
        do_lock_check = 0;
      }
      if( sscanf( type, "from %s", bagname ) ) {
        the_bag = present(bagname, this_player());
        if(!the_bag) {
          previous_object()->set_obj_short( bagname );
          write_msg( previous_object(), "query_no_bag" );
          return 1;
        }
        previous_object()->set_obj_short( the_bag->short() );
        ob= first_inventory(the_bag);
        if (!ob) {
          write_msg( previous_object(), "query_empty" );
          return 1;
        }
        if( lower_case(all) == "all" ) {
          sell_all(the_bag,do_lock_check);
          return 1;
        }
      }
      sell_all( this_player(), do_lock_check, type );
      return 1;
    }
  }
  else {
    if( what == "all" ) {
      sell_all( this_player(), 1 );
		  return 1;
	  }
    else if( what == "ALL" ) {
	    sell_all( this_player(), 0 );
		  return 1;
	  }
    ob = present( what, this_player());
    if (!ob) {
      previous_object()->set_obj_short( what );
      write_msg( previous_object(), "query_no_item" );
      annoy();
      return 1;
    }
    else {
      do_lock_check = 1;
      do_sell(ob, do_lock_check );
		  return 1;
    }
    
    write_msg( previous_object(), "query_error" );
    return 1;
  }
}

/** Store room functions **/
value( string item_name ) {
  int value, value2;
  object item;
  string alt_value_func;

  if (!item_name) {
    write_msg( previous_object(), "query_annoy" );
    return 1;
  }
  
  previous_object()->set_obj_short( item_name );
  item = find_item_in_object( this_player(), item_name );
  
  if ( !item ) {
    if ( store_value( item_name ) )
      return 1;
    write_msg( previous_object(), "query_no_item" );
    annoy();
    return 1;
  }
  
  previous_object()->set_obj_short( item->short() );
  
  value = item->query_value(1);
  if(!value)
    value = value = item->query_value(0);
  if (!value) {
    write_msg( previous_object(), "query_no_value");
    return 1;
  }
  
  alt_value_func = previous_object()->query_value_func();
  if( alt_value_func )
    value2 = call_other( item, alt_value_func );
    
  if( value2 > 0 )
    value = value2;

  previous_object()->set_obj_value( value );
  write_msg( previous_object(), "query_value_msg" );
  return 1;
}

store_value( string item_name ) {
  int value;
  string item;
  object store;
  
  store = previous_object()->query_backshop();
  /*
  store = find_object( previous_object()->query_backshop() );
  if( !store ) {
    store = previous_object()->query_backshop();
    store->reset();
    store = find_object( previous_object()->query_backshop() );
  }
  */
  
  /* item = present( item_name, store ); */
  item = find_item_in_object( store, item_name );
  if ( !item ) {
    return 0;
  }
  value = item->query_value();
  
  if(!value)
    value = call_other(item, "query_value", 0);
  
  if (!value) {
    return 0;
  }
  
  previous_object()->set_obj_short( item->short() );
  previous_object()->set_obj_value( adjust_value(value) );
  
  write_msg( previous_object(), "query_value_msg" );

  return 1;
}


find_item_in_object( object target, string str ) {
  object ob;

  ob = first_inventory( target );
  while(ob) {
    if (call_other(ob, "id", str) || ob->short() == str)
      return ob;
    ob = next_inventory(ob);
  }
  
  return 0;
}

move_store(item) {
  string short_desc;
  object ob, store;
   
  short_desc = call_other(item, "short");
  store = previous_object()->query_backshop();
  
  /* Dups allowed for now
  ob = first_inventory( store );
   while(ob) {
      if (call_other(ob, "short") == short_desc) {
         move_object(item, store );
         destruct(item);
         return;
         }
      ob = next_inventory(ob);
   } */
   item->drop();
   move_object(item, store );
   return 0;
}

status filter_inv( object ob, mixed type ) {
  if( type == "armor" || type == "armors" )
    return (status) ob->query_armor();
  else if( type  == "weapon" || type == "weapons" || type == "weap" )
    return (status) ob->query_weapon();
  else if( type == "heal" || type == "heals" )
    return (status) ob->is_heal();
  else if( type == "misc" )
    return !ob->is_heal() && !ob->query_armor() && !ob->query_weapon();
  else if( type == "all" )
    return 1;
  else
    return (status) ob->id( (string) type );
}

int short_sort(mixed *a, mixed *b) {
  return ( capitalize( (string) a[0]->short() ) > capitalize( (string) b[0]->short() ) );
}

print_inv_item( object ob, int idx, int item_count ) {
  string type;
  
  if( ob->query_weapon() )
    type = "Weap";
  else if( ob->query_armor() )
    type = "Armor";
  else if( ob->is_heal() )
    type = "Heal";
  else
    type = "Misc";  
  
  write(pad("["+idx+"]",5)+pad(adjust_value(ob->query_value()), 6)+pad(type, 6)+pad(item_count,4)+ob->short()+NORM+"\n");
}

set_shop_shadow( object player ) {
  object shadowObj;
  
  if( player && !player->queryShopShadow() ) {
    shadowObj = clone_object("players/dragnar/daemons/shop_shadow");
    shadowObj->doShopShadow( this_player() );
  }
}

print_inv( mixed *inv, int page_no ) {
  int i, size1, j, size2;
  string type;
  
  size1 = sizeof(inv);

  write(pad("[#]", 5)+pad("Value", 6)+pad("Type",6)+"#   Name\n");
  write("-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==--==--==--==--\n");
  
  if( size1 > 0 ) {

    set_shop_shadow( this_player() );
    
    this_player()->set_inventory( inv );
    this_player()->set_page( page_no );
    
    for( i = 0; i < size1 && i/PAGESIZE + 1 <= page_no; i++ ) {
      if( i/PAGESIZE + 1 == page_no ) {
        size2 = sizeof(inv[i]);
        print_inv_item( inv[i][0], i + 1, size2 );
      }
    }
    if( i < size1 ) {
      write("Continue listing? [y]: ");
      input_to("continue_list");
      return;
    }
  }
  else {
    if( previous_object() )
      write_msg( previous_object(), "query_empty_shop");
    else
      write( "Hrmmm empty shop.\n");
  }
}

list( string args, int page_no ) {
  object *inv;
  mixed *inventory;
  object store;
  
  if( !args )
    args = "all";
    
  set_shop_shadow( this_player() );
  
  if( !page_no || page_no < 1 ) {
    page_no = 1;
    this_player()->set_page( page_no );
  }
  
  store = previous_object()->query_backshop();
    
#ifndef __LDMUD__ 
  inv = filter_array(all_inventory( store ), "filter_inv", this_object(), args );
#else
  inv = filter(all_inventory( store ), "filter_inv", args );
#endif  

  inventory = unique_array(inv, "short" );

  /** Sorting seems to be too expensive to be able to handle a large number of objects
  inventory = sort_array(inventory , "short_sort" );
  **/
  
  print_inv( inventory, page_no  );
  
  return 1;
}

static continue_list( string str ) {
   int page_no;
   mixed *inv;
   
   page_no = this_player()->query_page();
   inv = this_player()->query_inventory();
   
   if( str == "n" || str == "N" ) {
      page_no = 1;
      this_player()->set_page( page_no );
      return;
   }
   if ( str == "y" || str == "Y" || str == "" ) {
     this_player()->set_page( ++page_no );
     print_inv( inv, page_no );
   }
   return;
}

buy( string item_name ) {
  int value, idx;
  string item;
  object store;
  mixed *inv;
  
  if (!item_name) {
    write_msg( previous_object(), "query_annoy" );
    annoy();
    return 1;
  }
  store = previous_object()->query_backshop();
  /*
  store = find_object( previous_object()->query_backshop() );
  if( !store ) {
    store = previous_object()->query_backshop();
    store->reset();
    store = find_object( previous_object()->query_backshop() );
  }
  */
  
  /** Need to scan for index, and somehow re-create array
      based on the args from the list command.  Shadow object?
  if( !item && sscanf(item_name, "%d", idx) == 1) {
  **/
  if( this_player()->queryShopShadow() ) {

    if( sscanf( item_name, "%d", idx ) == 1 ) {

      inv = this_player()->query_inventory();
      idx -= 1;
      if( sizeof(inv) > idx && idx >= 0 ) {
        item_name = inv[idx][0]->short();
      }
    }
  }
        
  /* item = present( item_name, store ); */
  item = find_item_in_object( store, item_name );
  
  if( !item ) {
    previous_object()->set_obj_short( item_name );
    write_msg( previous_object(), "query_no_item2" );
    return 1;
  }
  
  value = item->query_value();
  
  if(!value)
    value = call_other(item, "query_value", 0);
  
  value = adjust_value(value);
  
  previous_object()->set_obj_short( item->short() );
  previous_object()->set_obj_value( value );
  
  if (!value) {
    write_msg( previous_object(), "query_no_value" );
    return 1;
  }
  
  if (call_other(this_player(), "query_money", 0) < value) {
    write_msg( previous_object(), "query_no_money"  );
    return 1;
  }
  if (!call_other(this_player(), "add_weight", call_other(item, "query_weight"))) {
    write_msg( previous_object(), "query_no_carry"  );
    return 1;
  }
  
  call_other(this_player(), "add_money", 0 - value);
  move_object(item, this_player());
  write_msg( previous_object(), "query_buy"  );
  say_msg( previous_object(), "query_buy_msg" );
  
  return 1;
}
