inherit "obj/armor";

reset(arg) {

::reset(arg);

if(arg) return;

	set_name("bunny slippers");

	set_short("Pink Bunny Slippers");

	set_long("Ahh... warm, comfortable, and cute, would you believe that\n"+

	"these slippers are among the best footgear in Nirvana?\n");

	set_value(1200);

	set_ac(2);

	set_type("boots");

	set_alias("slippers");

set_weight(1);

	}

/* make save -Bp
query_save_flag() { return 1; }
*/

