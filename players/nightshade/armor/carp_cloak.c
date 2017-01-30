inherit "obj/armor";
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("cloak");
set_short("Carpathian cloak");
set_long("An old cloak from an even older Carpathian warrior.\n");
set_type("misc");
set_ac(1);
set_weight(1);
set_value(100);
set_alias("cloak");
}
