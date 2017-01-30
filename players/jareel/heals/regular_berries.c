#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
 ::reset(arg);
 if(arg) return;

set_name("berries");
add_alias("berry");

set_short("A bunch of berries");
set_long(
"A stem of berries picked from the Chaos Wood, the berries are said\n"+
"to provide one with great health.  Eating them seems like the only\n"+
"logical option.\n");

set_type("berries");
set_type_single("berry");

set_msg(
"You eat a berry.\n");

set_msg2(
" eats a berry.\n");

add_cmd("eat");

set_msg_postcharges(">"+NORM);

set_msg_precharges(GRN+"<");

set_heal(50,50);
set_charges(3);
set_stuff(17);
set_value(500);
}

query_save_flag(){
return 1;
}
