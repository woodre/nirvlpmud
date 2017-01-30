/*
 * garbage_wep.c
 * weapon for garbage room, use set_type to change
 */

inherit "obj/weapon";

string name, alias, shortdes, longdes;

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_class(2);
  set_value(20);
  set_weight(2);
}

void
set_type(string str)
{
  if (!str)
    return;
  switch (str)
  {
    case "boomsgiver":
      name = "boomsgiver";
      alias = "sword";
      shortdes = "Boomsgiver";
      longdes = "This is not a very powerful sword. You feel no magic aura surrounding it.\n"+
                "There is nothing written on it.\n";
      break;
    case "guttripper":
      name = "guttripper";
      alias = "Guttripper";
      shortdes = "Guttripper";
      longdes = "You can only guess what strange deeds this nice tool was used for.\n"+
                "It should serve very badly as a weapon though.\n";
      break;
    case "excalibor":
      name = "excalibor";
      alias = "sword";
      shortdes = "Excalibor";
      longdes = "How strange, to make a sword of rubber!\n";
      break;
  }
  set_name(name);
  set_alias(alias);
  set_short(shortdes);
  set_long(longdes);
}
