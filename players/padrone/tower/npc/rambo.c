/*
 * rambo.c
 * Rambo I, II, and III - guarding Padrone's vault
 */

inherit "obj/monster";

string rest_of_long;

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_aggressive(1);
  set_gender("male");
  rest_of_long = "Wow! What bulging muscles!\n"+
                 "He is employed by Padrone to guard the treasury. Which he does.\n";
}

status
set_movie(int num)
{
  object weapon;
  string name, alias, short, long;
  int level, hp, ac, wc;

  switch (num)
  {
    case 3:
      weapon = clone_object("/players/padrone/obj/machinegun");
      level = 17;
      hp = 350;
      wc = 24;
      ac = 14;
      name = "Rambo III";
      alias = "rambo iii";
      short = "Rambo III";
      long = "This is Rambo III.\n"+
             "Wow! What bulging muscles!\n"+
             "He is employed by Padrone to guard the treasury. Which he does.\n";
      break;
    case 2:
      weapon = clone_object("/players/padrone/obj/m16");
      level = 16;
      hp = 300;
      wc = 22;
      ac = 13;
      name = "Rambo II";
      alias = "rambo ii";
      short = "Rambo II";
      long = "This is Rambo II.\n" + rest_of_long;
      break;
    case 1:
      weapon = clone_object("/players/padrone/obj/m16");
      level = 15;
      hp = 250;
      wc = 20;
      ac = 12;
      name = "Rambo I";
      alias = "rambo i";
      short = "Rambo I";
      long = "This is Rambo I.\n" + rest_of_long;
      break;
    default:
      weapon = clone_object("/players/padrone/obj/m16");
      level = 14;
      hp = 220;
      wc = 18;
      ac = 11;
      name = "Rambo";
      alias = "rambo";
      short = "Rambo";
      long = "This is Rambo.\n"+ rest_of_long;
      break;
  }
  move_object(weapon, this_object());
  init_command("wield "+weapon->query_name());
  set_level(level);
  set_hp(hp);
  set_wc(wc);
  set_ac(ac);
  set_name(name);
  set_alias(alias);
  set_short(short);
  set_long(long);
}
