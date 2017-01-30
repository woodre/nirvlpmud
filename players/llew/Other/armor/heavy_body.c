inherit "obj/armor";

reset(arg)
{
   if (arg) return;
   set_name("armor");
   set_short("Heavy Body Armor");
   set_value(1);
   set_weight(1);
   set_ac(5);
   set_type("armor");
}
