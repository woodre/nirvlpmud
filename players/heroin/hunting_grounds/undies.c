inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
set_short("Bat undies");
set_long("You are now in possession of Batman's underwear.  They are\n"+
"good protection from drafts, and flying debris.  However, they are\n"+
"also soiled.  Wear them at your own peril.\n");
     set_ac(1);
     set_weight(1);
	set_value(1000);
	set_alias("undies");
	set_name("undies");
        set_type("underwear");
  }
