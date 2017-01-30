inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
set_short("Trench coat");
set_long("A grayish trench-coat..The coat provides good \n"+
"protection from the gloomy weather of London. One could\n"+
"probably wear this coat for all types of weather however\n");
     set_ac(2);
     set_weight(1);
	set_value(250);
	set_alias("coat");
	set_name("coat");
	set_type("shield");
  }
