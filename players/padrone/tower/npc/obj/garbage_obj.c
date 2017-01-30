/*
 * garbage_obj.c
 * garbage object, use set_type to change
 */

inherit "obj/treasure";

string name, alias, shortdes, longdes;

void
reset(status arg)
{
  treasure::reset(arg);
  if (arg)
    return;
  set_value(10);
  set_weight(1);
}

void
set_type(string str)
{
  if (!str)
    return;
  switch (str)
  {
    case "small non-magical amulet":
      name = "small non-magical amulet";
      alias = "amulet";
      shortdes = "A small non-magical amulet";
      longdes = "A small non-magical amulet";
      break;
    case "large non-magical amulet":
      name = "large non-magical amulet";
      alias = "amulet";
      shortdes = "A large non-magical amulet";
      longdes = "A large non-magical amulet";
      break;
  }
  set_name(name);
  set_alias(alias);
  set_short(shortdes);
  set_long(longdes);
}
