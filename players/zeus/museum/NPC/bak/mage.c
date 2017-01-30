
/*
1:12 heal    hp 160
healing in hb hp 20
1:11 shards  wc 3
1:10 shower  wc 10
1:9  ball    wc 15 (9/4)
1:8  monger  wc 10
1:5  flash   wc 8
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

object robe;

reset(arg) {
   ::reset(arg);
   if (!arg) {

    robe = CO("/players/zeus/museum/OBJ/mage_robe.c");
	MO(robe, TO);
	command("wear robe", TO);

  set_name("heldurabhoricka");
  set_alias("mage");
  set_short("Heldurabhoricka the Mage");
  set_race("human");
  set_gender("female");
  set_long(
"Heldurabhoricka the Mage is a legendary spell caster.  She is wearing a\n"+
"long red robe with black lining that drags along the ground.  A book\n"+
"of spells is visible beneath her robe.  She has long flowing auburn hair\n"+
"that tumbles over her shoulders.\n");
  set_level(21);
  set_ac(17+random(4));
  set_hp(1400);
  set_hp_bonus(180);
  add_money(100+random(1000));
  set_heal(2,1);
  set_wc(20+random(4));
  set_wc_bonus(47);
  set_aggressive(0);
  set_al(100);
  set_chat_chance(4);
  set_a_chat_chance(1);
  load_chat("Heldurabhoricka watches you closely.\n");
  load_chat("Heldurabhoricka glances at you.\n");
  load_chat("Heldurabhoricka closes her eyes and meditates.\n");
  load_chat("Heldurabhoricka seems at peace.\n");
  load_chat("Heldurabhoricka eminates a soft glow.\n");
  load_a_chat("Heldurabhoricka meditates quietly.\n");
  set_dead_ob(TO);
   }
}

monster_died(){
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
	  capitalize((string)TP->QRN)+" defeated Heldurabhoricka.\n");
   "/players/zeus/museum/lounge.c"->npc3();
}

heal_spell(){
	TR(environment(),
		"Heldurabhoricka touches a small stone in her hand...\n"+
		"A blue aura wraps around her delicate body...\n");
	hit_point += 70+random(31);
	weapon_class += 1;
	return 1;
}

ice_shards(){
  if(!present(AO, environment())) return 0;
   TR(environment(TO),
 "Heldurabhoricka holds her hands out in front of her...\n"+
 "\nA stream of "+BLU+" ice shards "+NORM+" pummels "+AO->QN+"...\n\n"+
 AO->QN+" shivers from the intense cold, barely able to move...\n",
     ({ AO }));
   tell_object(AO,
 "Heldurabhoricka holds her hands out in front of her...\n"+
 "\nA stream of "+BLU+" ice shards "+NORM+" pummels you...\n\n"+
 "You shiver from the intense cold, barely able to move...\n");
   AO->hit_player(30+random(20), "other|ice");
   return 1;
}

ice_shower(){
  int i;
  object all_opp;
  all_opp = all_inventory(environment());
  if(!present(AO, environment())) return 0;
  for(i=0; i<sizeof(all_opp); i++)
  {
    if(all_opp[i]->is_player())
    {
      TR(environment(),
        "Heldurabhoricka raises her hands towards the sky...\n\n"+
        BLU+"\t|\t |         |\t       |\n"+
        "\t   | \t |     |  \t  |\n"+
        "\t       |\t|      |   \t|    |\n"+
        "\t|        |\t    |     |         |\n\n"+NORM+
        "Huge spikes of ice rain down on you!\n");
      all_opp[i]->hit_player(40+random(55), "other|ice");
    }
  }
}

ice_ball(){
  if(!present(AO, environment())) return 0;
  if(present("ice_ball_spell", AO)) return 0;
  TR(environment(),
    "Heldurabhoricka whispers a soft spell under her breath...\n"+
    AO->QN+" suddenly begins to shake and look very pale...\n", ({ AO }));
  tell_object(AO,
    "Heldurabhoricka whispers a soft spell under her breath...\n"+
    "You suddenly begin to shake and look very pale...\n");
  MO(CO("/players/zeus/museum/OBJ/ice_ball_spell.c"), AO);
  return 1;
}


ice_monger(){
  object ice_monger;
  if(!present(AO, environment())) return 0;
  if(present("ice horror", environment())) return 0;
  TR(environment(),
    "Heldurabhoricka pulls in the cold around her...\n"+
    "\tBalls of ice begin to form around her hands...\n"+
    "\t\tA sudden flash of ice erupts from Heldurabhoricka...\n"+
    "\t\t\tA gigantic "+HIB+"ice horror"+NORM+" stands before you...\n");
  ice_monger = CO("/players/zeus/museum/NPC/ice_monger.c");
  MO(ice_monger, environment());
  ice_monger->attack_object(AO);
  return 1;
}


ice_flash(){
  if(!present(AO, environment())) return 0;
   TR(environment(),
     "Heldurabhoricka fires a blast of cold air at "+AO->QN+"...\n",({ AO }));
   tell_object(AO, "Heldurabhoricka fires a blast of cold air at you...\n");
   AO->hit_player(25+random(20), "other|ice");
   return 1;
}

heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return ;
  if(hit_point < 100)
    hit_point += 4;
  if(!attacker_ob) 
    return ;
  if(!random(12)){   heal_spell();  return ;  }
  if(!random(11)){   ice_shards();  return ;  }
  if(!random(10)){   ice_shower();  return ;  }
  if(!random(9)){    ice_ball();    return ;  }
  if(!random(8)){    ice_monger();  return ;  }
  if(!random(5)){    ice_flash();   return ;  }
}
