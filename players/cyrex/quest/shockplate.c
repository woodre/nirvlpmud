inherit "obj/armor";
object shockarmor;
reset(arg) {
::reset(arg);

set_name("shockplate");
set_alias("plate");
set_short("Shockplate");
set_long("This armor is seems to be the natural protection of the trooper.\n"+
	 "It would provide an adequate disguise when worn.\n");
set_ac(4);
set_weight(3);
set_value(2000);
set_type("armor");
}

