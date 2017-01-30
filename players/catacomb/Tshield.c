inherit "/obj/armor";

reset(arg) 
{
  ::reset(arg);
  if(arg) return;
  set_name("shield");
  set_short("A large tower shield");
  set_long(" A large shield that stands four feet tall.\n");
  set_type("shield");
  set_ac(1);
  set_weight(3);
  set_value(500);
}
