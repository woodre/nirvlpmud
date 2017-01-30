
inherit "obj/armor";

reset(arg) {

::reset(arg);

if(arg) return;

	set_name("spectraplate");

	set_short("Spectraplate");

	set_long("Made of the same 'reality-defying' material that the Plane\n"+

	"of Etheriel is composed of, this armor seems to offer excellent\n"+

	"protection despite it's apparent flimsiness.\n");

	set_value(10000);

	set_ac(3);

	set_type("armor");

	set_alias("plate");

	}

