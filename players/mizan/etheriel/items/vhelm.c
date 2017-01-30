inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("vapor helm");
	set_short("Vapor Helm");
	set_long("Almost translucent, and featherweight, this thing really makes\n"+
	"the grade in terms of protecting your skull (although some people\n"+
	"don't really need it).\n");
	set_value(2000);
	set_ac(1);
	set_type("helmet");
	set_alias("helm");
	}
