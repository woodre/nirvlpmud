inherit "room/room";

#include "../../defs.h"

#include <ansi.h>

string room_name;


reset() {

  if(arg) return;

  set_light(1);
  set_short("The Forest of Fear");
}

init() {
  ::init();

  add_action("Key","key");
  add_action("Zoom","zoom");
  add_action("Map","map");

  /** Make sure the long has been properly set **/
  if( !long_desc )
    set_long( MAPDM->get_map( basename( this_object() ) ));
}

Key() {
  write("Key to the :\n\n"+ MAPDM->get_key( basename( this_object() ))+"\n\n");
  return 1;

}

Map() {
  MAPDM->get_map( basename( this_object() ) );
  return 1;
}

Zoom() {
  return 1;
}
