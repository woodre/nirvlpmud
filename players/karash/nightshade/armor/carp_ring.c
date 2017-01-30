inherit "obj/armor";
reset(arg)
{
::reset(arg);
if(arg) return;
set_type("ring");
set_name("ring");
set_short("Carpathian ring");
set_long("A ring of the Carpathian soldier. It bears the standard of\n"+
"Carpathian empire.\n");
set_ac(1);
set_weight(1);
set_value(100);
set_alias("gloves");
}
