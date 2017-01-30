inherit "obj/armor";

reset(arg)
{
   if (arg) return;
   set_name("cloak");
   set_short("Heavy Cloak");
   set_value(1);
   set_weight(1);
   set_ac(2);
   set_type("misc");
}
