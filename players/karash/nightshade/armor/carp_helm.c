inherit "obj/armor";
reset(arg)
{
::reset(arg);
if(arg) return;
set_type("helmet");
set_name("helmet");
set_short("Carpathian helm");
set_long("The helmet of yes, a dead Carpathian soldier.\n");
set_ac(1);
set_weight(1);
set_value(100);
set_alias("helmet");
}
