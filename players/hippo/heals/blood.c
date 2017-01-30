/*  Changed to new heals format 8/15/02 - Eurale  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("blood");
add_alias("drops");
set_short(HIR+"drops of blood"+NORM);
set_long(
  "Sickly sweet drops of red blood.\n");

add_cmd("drink");
set_type("drops");
set_type_single("drop");
set_msg(
  HIR+"You drink a sweet drop of red blood.\n"+NORM);
set_msg2(
  " drinks a drop of red blood.\n");
set_heal(35,35);
set_charges(5);
  set_msg_precharges(HIR+"{"+NORM);
  set_msg_postcharges(HIR+"}"+NORM);
set_intox(13);  /*  intox  soak  stuff  */
set_value(500);
set_msg_intoxed(
  "You are too drunk for any more blood.\n");
set_empty_msg(
  HIR+"You finish off the last drop of blood.\n"+NORM);
}
