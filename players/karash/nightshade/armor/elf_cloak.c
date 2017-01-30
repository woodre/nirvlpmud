inherit "obj/armor";
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("cloak");
set_short("Grey cloak");
set_long("A ordinary grey cloak made from lambs wool.\n");
set_type("misc");
set_ac(1);
set_weight(1);
set_value(100);
set_alias("cloak");
}
