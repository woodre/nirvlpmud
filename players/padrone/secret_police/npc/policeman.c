/*
 * policeman.c
 * Secret Policeman
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, membership;
  monster::reset(arg);
  if (arg)
    return;
  set_name("policeman");
  set_alias("secret policeman");
  set_short("A policeman from the Secret Police");
  set_long("This is a policeman from the Secret Police.\n"+
           "What can he be doing in this shop?\n");
  set_gender("male");
  set_chance(10);
  set_spell_dam(10);
  set_spell_mess1("The secret policeman kicks his opponent very hard.");
  set_spell_mess2("The secret policeman kicks you very hard. You are hurt!");

  wep = clone_object("/players/padrone/secret_police/npc/obj/sp_dagger");
  move_object(wep, this_object());
  init_command("wield dagger");

  membership = clone_object("/players/padrone/secret_police/membership");
  move_object(membership, this_object());
}

void
setup_mob(int level)
{
  if (!level)
    level = 1;
  if (level == 2)
  {
    set_level(2);
    set_wc(6);
    set_ac(3);
    set_hp(30);
    set_al(80);
  }
  else
  {
    set_level(1);
    set_wc(5);
    set_ac(3);
    set_hp(15);
    set_al(60);
  }
}
