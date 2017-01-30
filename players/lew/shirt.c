 

inherit"obj/armor";
inherit"/players/lew/things/me.c";

reset(arg) {

::reset(arg);

if(arg) return;

set_name("shirt");

set_alias("tshirt");

set_short("A T-shirt");

set_long(

"A tie-die t-shirt with Jim Morrison's face on the front.\n");

set_weight(1);

set_value(2000);

set_ac(4);

set_type("armor");

}

 

