inherit "obj/armor";
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("boots");
set_short("Carpathian boots");
set_long("Ancient boots of a Carpathian warrior.\n");
set_type("boots");
set_ac(1);
set_weight(1);
set_value(100);
set_alias("boot");
}
