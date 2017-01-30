inherit "obj/weapon.c";


id(str)
{
  return str == "voulge" || str == "weapon";
}


reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("Purple tinted voulge");
  set_alias("purple tinted voulge");
  set_short("A Purple tinted voulge");
  set_long(
"      Wrapped around the vouge is purple sheets of metal. These sheets\n"+
"are decorated with small runes. The whole shaft of the voulge is\n"+
"twisted, yet strong and very sturdy. The blade of the voulge is very\n"+
"sharp, and gleems in dark light.\n");
  set_class(14);
  set_weight(3);
  set_value(6000);
  set_hit_func(this_object());
}


weapon_hit(object attacker)
{
  int n;
  object putz;
  if (random(100) <=40)
  {
    putz = capitalize(attacker->query_name());
    n = random(100);
    if (n <= 20)
    {
      tell_object(this_player(), 
        "The voulge gleems purple and ---slices--- away.\n");
      tell_room(environment(this_player()), capitalize(this_player()->
        query_name())+"'s voulge gleems purple and ---slices--- away.\n");
      return 4;
    }
    else
    {
      tell_object(this_player(), 
        "The voulge's pseudomotion strikes its target.\n");
      tell_room(environment(this_player()),
        capitalize(this_player()->query_name())+
        "'s voulge strikes its target with pseudomotion.\n");
      return 2;
    }
  }
}
