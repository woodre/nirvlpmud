inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
    set_short("A Black Hooded Cloak");
    set_long("A dark black cloak which hides your eyes when you\n"+
	"wear it. You think the material is some course wool.\n");
     set_ac(1);
     set_weight(1);
	set_value(1000);
	set_alias("cloak");
	set_name("cloak");
	set_type("cloak");
  }
