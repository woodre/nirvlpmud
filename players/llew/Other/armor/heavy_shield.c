inherit "obj/armor";

reset(arg)
{
   if (arg) return;
   set_name("shield");
   set_short("Heavy Shield");
   set_value(1);
   set_weight(1);
   set_ac(2);
   set_type("shield");
}
