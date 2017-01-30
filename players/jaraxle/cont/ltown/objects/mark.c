inherit "obj/treasure";

#include "/players/jaraxle/ansi.h"



reset (arg) {

if(!arg){

  set_id("mark");

  set_alias("chalk_markings");

  set_short("a "+HIR+"C"+NORM+BLU+"o"+HIY+"l"+NORM+YEL+"o"+HIB+"r"+NORM+RED+"e"+HIM+"d"+NORM+" mark");

  set_long(

  "It looks as though someone has marked this area with chalk.\n");

  set_weight(10000);

  set_value(0);

  call_out("destroy_it", 1200);

    }

  }



destroy_it(){

tell_room(environment(),

"The marking disappears...\n");

destruct(this_object());

return 1;

}