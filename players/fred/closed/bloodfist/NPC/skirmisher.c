inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
object morningstar,breastplate,boots,gd,gda, *all,nmy,wa;
int a, sa;

reset(arg){
  if(arg) return;
  ::reset(arg);

  if(random(3))
  {
    wa = clone_object(DIR+"obj/water.c");
    move_object(wa, this_object());
  }

  boots = clone_object("/obj/armor.c");
  boots->set_weight(2);
  boots->set_value(300);
  boots->set_type("boots");
  boots->set_name("black leather boots");
  boots->set_short("Leather boots");
  boots->set_long(
    "This pair of leather boots is caked in dry sand and dirt.\n");
  boots->set_ac(1);
  move_object(boots, this_object());
  init_command("wear boots");

  breastplate = clone_object("/obj/armor.c");
  breastplate->set_weight(2);
  breastplate->set_value(500);
  breastplate->set_type("armor");
  breastplate->set_name("hooded robe");
  breastplate->set_alias("robe");
  breastplate->set_short("A light hooded robe");
  breastplate->set_long(
    "This light hooded robe is caked in sand and dirt.  It provides\n"+
    "adequare protection from the desert winds.\n");
  breastplate->set_ac(3);
  move_object(breastplate, this_object());
  init_command("wear armor");

  set_name("desert skirmisher");
  set_alias("skirmisher");
  set_short(YEL+"A desert skirmisher"+NORM);
  set_long(
"This tough fellow is a criminal, a thief, and a dangerous person in\n"+
"general to be around.  He is draped in a baggy robe that protects\n"+
"him from the desert winds.  It looks as though at the drop of a hat\n"+
"he would stab you in the back and pick your corpse clean.\n");
  set_race("human");
  set_level(20);
  set_wc_bonus(42);  /* must fight 3 at once w/ chance of double hit */
  set_ac(17);
  set_heal(1,3);
  set_wc(35+random(13));
  set_hp(600+random(100));
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(1);
  load_chat("The skirmisher stares at you.\n");
  load_a_chat("The skirmisher cuts you with his hooked dagger.\n");
  set_chance(10);
  set_spell_dam(25);
  set_spell_mess1("The skirmisher gets a lucky blow.\n");
  set_spell_mess2("The skirmisher hits you with a lucky blow.\n");
  add_money(700+random(2000));
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  all = all_inventory(environment());
  sa = sizeof(all);
  for(a = 0; a < sa; a++)
  {
    gd = all[a];
    if(gd->id("desert skirmisher") && (this_object() != gd)
      && (gda = gd->query_attack()))
      attack_object(gda);
  }
  if(!attacker_ob && nmy && present(nmy, environment()) && !random(6))
    attack_object(nmy);
  if(!attacker_ob) return;
  nmy = attacker_ob;
  if(!random(3) && !attacker_ob->query_ghost()
    && present(attacker_ob, environment()))
  {
    already_fight = 0;
    ::attack();
  }
}
