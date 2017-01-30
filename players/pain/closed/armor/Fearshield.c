inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
    set_short("Fear's Aura");
	set_long("This is Fear's Aura, you feal it surround and protect you.\n");
     set_ac(2);
     set_weight(2);
	set_value(100000000);
	set_alias("aura");
	set_name("aura");
set_save_flag(1);
	set_type("shield");
  }
