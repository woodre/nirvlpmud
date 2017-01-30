inherit "obj/armor";
reset(arg){
  if(arg) return;
::reset(arg);
	set_short("A Spucksuit");
	set_long("  Made of some strange transparent material, the suit seems to be really\n"+
"slick armor, but it's kinda heavy.\n");
	set_ac(3);
	set_weight(3);
	set_name("spucksuit");
	set_value(1000);
	set_alias("suit");
	set_type("armor");
	}
