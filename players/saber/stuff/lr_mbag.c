/* 07/04/06 Earwax: Changed max weight from 100k to 250, will lower
 * further, but don't want to get too nasty right away.
 */
inherit "obj/container.c";
#include <ansi.h>

 
#define SHOP "obj/daemons/shop_daemon"
 
 reset(arg) {
  ::reset(arg); /* changed from reset() */
    if (arg) return;
    set_name("bag");
    set_short("A "+HIW+"bag of holding"+NORM);
    set_long("A magical (savable) bag of holding. Type baginv to see whats in it.\n");
    set_weight(1);
    set_value(250);
/* fucking earwax.  up to 1000.  - ill Aug 2011 */
    set_max_weight(1000);
}

init() {
  ::init();
  add_action("baginv","baginv");
}

baginv( string str ) {
  if( this_player() && environment(this_object()) == this_player() )
    return SHOP->list( str );
  else
    return 0;
}

query_empty_shop() { return short_desc+" is empty."; }
query_backshop() { return this_object(); }

query_save_flag() { return 0; }
