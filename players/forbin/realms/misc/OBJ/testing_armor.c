#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "obj/armor";

drop() {
  ::drop();
  move_object(this_object(), "room/void");
  destruct(this_object()); 
}