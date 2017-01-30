 
inherit "obj/armor";
 
reset(arg)
{
::reset(arg) ;
set_short("Boots of the SS Officer");
set_long("Black leather boots of extraordinary style.\n");
set_ac(1);
set_weight(1);
set_value(5000);
set_alias("boots");
set_name("boots");
set_type("boots");
}
 
query_save_flag() { return 0; }
 
        
