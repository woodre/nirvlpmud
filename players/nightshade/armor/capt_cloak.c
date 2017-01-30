inherit "obj/armor";
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("cloak");
set_short("Chainmail cloak");
set_long("A beautiful cloak woven from links of very light but strong steel.\n");
set_type("cloak");
set_ac(1);
set_weight(1);
set_value(500);
set_alias("cloak");
}
