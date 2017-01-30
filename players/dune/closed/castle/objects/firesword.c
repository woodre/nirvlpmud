inherit "obj/weapon.c";


id(str)
{
  return str == "core" || str == "sword" || str == "firesword";
}


reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("Core");
  set_alias("core");
  set_short("Core, the firesword");
  set_long(
"     Core is the greatest of fireswords. Its blade glows\n"+
"a brilliant white. Blue and red flames swirl around it.\n"+
"Core's hilt is made of carved firediamond.\n");
  set_class(17);
  set_weight(6);
  set_value(10000);
  set_hit_func(this_object());
}


weapon_hit(attacker)
{
  object ob;
  string name;
  ob = this_player()->query_attack();
  name = capitalize(ob->query_name());
  picture(this_player(), name);
  return 5;
}


picture(object ob, string name)
{
  tell_room(environment(this_player()),
"   ff        f        f          ff        f     ff     \n"+
"   fffff    fff      ff       ffffff     ffff    ffffff \n"+
"          Core singes "+name+" in a burst of fire!      \n"+
"   ffff     ffffff   fff ffff     fffffff    fffffff    \n"+
"\n");
  return 1;
}
