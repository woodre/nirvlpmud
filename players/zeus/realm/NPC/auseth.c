/*  Approved by: Snow   3/21/00  */

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int *acs, *wcs, *hps, evil;

reset(arg){
  ::reset(arg);
  if(!arg){

  if(!present("aura"))
  {
    object aura;
    aura = clone_object("/players/zeus/realm/OBJ/evil_aura.c");
    move_object(aura, this_object());
    init_command("wield aura");
  }

  if(!present("stone"))
    MO(CO("/players/zeus/realm/OBJ/siphon_stone.c"), TO);

  acs =({ 30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15 }); /* 16 */
  wcs =({ 20,23,26,29,32,35,38,41,44,47,50,53,56,59,62,65 });
  hps =({ 1450,1375,1300,1225,1150,1075,1000,915,850,775,700,625,
    550,475,400,325 });
  evil = 0;

  set_name("auseth");
  set_alias("wizard");
  set_short("Auseth the Wizard");
  set_race("human");
  set_gender("male");
  set_long(
"This is Auseth the wizard.  He is a strong looking man, wearing rather\n"+
"tattered clothing.  He has long brown hair and a rather long face with\n"+
"a very full beard.  On his right hand is a strange dark cloud of evil\n"+
"energy.  His face is rather dirty and seems very lined and wrinkled, as\n"+
"though he has been here for a very long time.\n");
  set_level(21);
  set_ac(32);
  set_wc(18);
  set_wc_bonus(34);
  set_hp(1525);
  set_chat_chance(4);
  set_a_chat_chance(1);
  load_chat("Auseth gets a crazed look in his eyes.\n");
  load_chat("Auseth cackles gleefully.\n");
  load_chat("Auseth glares at you.\n");
  load_chat("Auseth says: Leave now!\n");
  load_chat("Auseth looks you up and down.\n");
  load_chat("Auseth has an unpleasant look on his face.\n");
  load_a_chat("Auseth steps to the side.\n");
  set_dead_ob(this_object());
   }
}

monster_died()
{
  write_file("/players/zeus/log/bigmon",
  ctime(time())+" - "+AO->QN+" [L "+AO->query_level()+
  "+"+AO->query_extra_level()+"] killed Auseth.\n");
  tell_room(environment(),
    "\nThe room crackles with an aura of dark energy.\n\n");
  return 1; 
}

evil_attack(){
  int i;
  object all_opp;
  if(!environment()) return;
  all_opp = all_inventory(environment());
  if(!present(attacker_ob, environment())) return;
  for(i = 0; i < sizeof(all_opp); i++)
  {
    if(all_opp[i]->is_player() || all_opp[i]->is_pet())
    { 
      tell_object(all_opp[i],
        "Auseth explodes in a violent storm of dark energy...\n"+
        "\n\t"+BOLD+BLK+"DARK ENERGY"+NORM+"   lashes into you!\n\n");
      all_opp[i]->hit_player(55+random(25), "other|dark");
      if(all_opp[i])
      if(hit_point < 400 && all_opp[i]->is_player())
      {
        if(all_opp[i]->query_hp() > 0 && !all_opp[i]->query_ghost())
          all_opp[i]->add_spell_point(-random(50));
        if(all_opp[i]->query_sp() < 0)
        {
          int e;
          e = all_opp[i]->query_sp() * -1;
          all_opp[i]->add_spell_point(e);
        }
      }
    }
  }
}

pillar(){
  if(!present(attacker_ob, environment())) return;
  tell_room(environment(), BOLD+BLK+
    "\nA pillar of dark energy erupts around "+attacker_ob->query_name()+"!"+
    NORM+"\n   "+attacker_ob->query_name()+
    " is torn apart by the pillar!\n\n", ({ attacker_ob }));
  tell_object(attacker_ob, BOLD+BLK+
    "\n |   |   |   |  |    |    |  |    | |   |    |\n"+
    "  |    |     |     |  |    |   |      |   |\n"+
    "\nA pillar of dark energy erupts around you!\n"+NORM+
    "     You are torn apart by the pillar!\n\n"+BOLD+BLK+
    "     |  |   |    | |    |  | | |    |\n"+
    "      |  |   |  | |  |    |   |   |\n\n"+NORM);
  attacker_ob->hit_player(50+random(40), "other|dark");
}

doom(){
  if(!random(3))
  {
    tell_room(environment(),
      "Lashes of dark energy swirl around Auseth!\n");
  }
  else if(!random(2))
  {
    tell_room(environment(),
      "Bands of dark energy flow around Auseth!\n");
  }
  else
  {
    tell_room(environment(),
      "Waves of dark energy radiate from Auseth!\n");
  }
}

aura(){
  tell_room(environment(), BOLD+BLK+
    "\n\tAn aura of dark energy crackles around Auseth!\n\n"+NORM);
}

lash(){
  if(!present(attacker_ob, environment())) return;
  tell_room(environment(),
   "Auseth lashes a band of dark energy into "+attacker_ob->query_name()+"!\n",
    ({ attacker_ob }));
  tell_object(attacker_ob,
    "Auseth lashes a band of dark energy into you!\n");
  attacker_ob->hit_player(45, "other|dark");
  if(alt_attacker_ob && (alt_attacker_ob != attacker_ob) && !random(4))
  {
    tell_object(alt_attacker_ob,
      "Auseth lashes a band of dark energy into you!\n");
    alt_attacker_ob->hit_player(20, "other|dark");
  }
}

heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return ;
  if(!attacker_ob) 
    return ;
  if(evil < 16)
  {
    if(hit_point < hps[evil])
    {
      weapon_class = wcs[evil];
      armor_class = acs[evil];
      evil++;
    }
  }
  if(!random(10))
    doom();
  else if(!random(9))
    lash();
  else if(!random(16))
    evil_attack();
  else if(!random(15))
    pillar();
  else if(!random(25))
    aura();
}
