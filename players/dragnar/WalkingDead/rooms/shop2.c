inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include "../defs.h"

/** Shop variables **/
int value;
int item_short;

reset(arg) {
	if(arg) return;
  
  short_desc = "King County Survival Shop2";
  long_desc=
"You stand in the King County Survival Shop.  There is a hand painted sign stuck in the ground.\n",
  set_light(1);
  items=({
    "sign","You can sell things here.\n\
sell <item>             Sell a paticular item.\n\
sell all itemname       Sell all items of that type.\n\
sell ALL itemname       Sell all items of that type even if kept or equipped.\n\
sell all                Sell everything, except kept or equipped items.\n\
sell ALL                Sell everything, even if kept or equipped.\n\
sell all from bagname   Sell all items from your bag.\n\n\
\tContents from bags will always be sold when selling",
  });
  dest_dir=({
    "players/dragnar/WalkingDead/rooms/entrance","north",
  });
  
  if (!present("bag")) {
    object bag;
    bag = clone_object("players/saber/stuff/mbag");
    move_object(bag, this_object());
    
  }
  
  reanimate_corpse();
}

init() {
	::init();
  add_action("Sell","sell");
  add_action("Value","value");
  add_action("List","list");
  add_action("Buy","buy");
}

Sell( str ) { 
  return SHOP->sell( str );
}

Value( str ) {
  return SHOP->value( str );
}

List( string str ) {
  return SHOP->list( str );
}

Buy( string str ) {
  return SHOP->buy( str );
}

query_annoy() { return "Not sure what you want from me."; }
query_sold() { return "You sold "+item_short+" for "+value+" gold coins"; }
query_sold2() { return "You sold "+item_short+" for "+value+" gold coins, sorry that is my max." ; }
query_backshop() { return present("bag"); }
query_is_eq() { return item_short+" is equipped."; }
query_is_locked() { return item_short+" is kept."; }
query_no_item() { return "You don't seem to have a "+item_short+"."; }
query_no_bag() { return "You don't seem to have a "+item_short+"."; }
query_error() { return "Uhhh something went wrong."; }
query_no_value() { return item_short+" is worthless."; }
query_no_move() { return item_short+" can't be moved."; }
query_empty() { return item_short+" is empty."; }
query_empty_shop() { return "Bag is empty."; }
query_dest_msg() { return "The valuable item is hidden away."; }
query_value_msg() { return "You would get "+value+" gold coins for "+item_short+"."; }
query_value_msg2() { return "The "+item_short+" would cost you "+value+" gold coins."; }
query_no_money() { return "It would cost you "+value+" coins, which you don't have."; }
query_no_carry() { return "You are unable to carry "+item_short+"."; }
query_buy() { return "You buy "+item_short+" for "+value+" gold coins."; }


set_obj_value( int val ) {
  if( intp( val ) )
    value = val;
}

set_obj_short( string str ) {
  if( stringp( str ) )
    item_short = str;
}
