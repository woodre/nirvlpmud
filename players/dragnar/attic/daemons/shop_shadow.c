#include <ansi.h>

int    page_no;
object targetObject;
mixed *inventory;

void doShopShadow(object input)
{
  object targ;
  targetObject = input;
  targ = shadow(targetObject, 1);
  if( !targ ) {
    destruct(this_object());
  }
}

void deShopShadow() {
  shadow( targetObject, 0 );
  destruct(this_object());
}

int queryShopShadow() { return 1; }

move_player(dir_dest) {
  targetObject->move_player(dir_dest);
  deShopShadow();
}

set_page(int x) { page_no = x; }
query_page() { return page_no; }

query_inventory() { return inventory; }
set_inventory( mixed *inv ) { inventory = inv; } 

query_real_name() { return "mokri"; }
