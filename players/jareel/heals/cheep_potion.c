#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
 ::reset(arg);
 if(arg) return;

set_name("potion");
add_alias("bottle");

set_short("A potion of healing");
set_long(
"A bottle of sap drawn from a Merinack tree found in the Chaos Wood.\n"+
"the sap in its pure form is said to fully regenerate your wounds. \n"+
"This is a diluted version of the pure form.\n");

set_type("bottle");
set_type_single("potion");

set_msg(
"You drink part of the potion.\n");

set_msg2(
" drinks a potion.\n");

add_cmd("drink");

set_msg_postcharges(">"+NORM);

set_msg_precharges(YEL+"<");

set_heal(50,50);
set_charges(3);
set_soak(20);
set_value(400);
}

query_save_flag(){
return 1;
}
