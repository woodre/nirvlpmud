inherit "obj/weapon.c";


id(str)
{
  return str == "knife" || str == "bloody knife";
}


reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("Bloody knife");
  set_alias("weapon");
  set_short("A bloody knife");
  set_long(
"     The bloody knife is very finely crafted. Perhaps to cut skin\n"+
"better. It would serve as a fine weapon.\n");
  set_class(12);
  set_weight(1);
  set_value(1000);
}
