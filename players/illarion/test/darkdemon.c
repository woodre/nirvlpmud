/* Basic Example of using monster spells */

inherit "/players/illarion/test/monster";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Demon of Darkness");
  set_alt_name("demon");
  set_alias("darkness");
  set_race("demon");
  set_short("The Demon of Darkness");
  set_long("A fearsome, 8 foot figure, the Demon of Darkness is mostly\n"+
           "shadow, with the occasional flash of fire from within which\n"+
           "illuminates features not suited to the retention of sanity.\n");
  set_hp(1500);
  set_ac(30);
  set_wc(15);
  set_weapon_params("other|evil",15,0);
  set_armor_params("other|evil",-30,0,0);
  
  RegisterWeaponBonus(this_object(),({"other|evil",10,"bonus_extra_fun"}));

  
/* multi_cast is actually 0 by default.  This means the demon will */
/* cast at most one spell per round, but has a 25% chance of casting */
/* a spell (8 for hellfire +12 for fire claws + 5 for darkness drain) */

/*
  set_multi_cast(1);

  add_spell("all_players",
"#MN# attacks you with a spell.\n",
"#MN# attacks #TN# a spell.\n",
50,20,"other|fire",0,"extra_fun");
*/
}

extra_fun(target,room,dam) {
  tell_room(room,"dam= "+dam+"\n");
}

bonus_extra_fun(object ob) {
  tell_room(environment(),"bonus_extra_fun called for "+ob->query_name()+"\n");
}
