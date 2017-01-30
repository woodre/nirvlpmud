inherit "obj/weapon.c";


id(str)
{
  return str == "mace" || str == "sparkling mace";
}


drop()
{
  write("You like the mace too much to drop it!\n");
  return 1;
}


reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("Sparkling mace");
  set_alias("mace");
  set_short("A sparkling mace");
  set_long(
"      The mace sparkles furiously with white light. Its handle is\n"+
"made of smooth ivory. The head made of a lusterous metal, similar\n"+
"to steel.\n");
  set_class(5);
  set_weight(10);
  set_value(0);
}
