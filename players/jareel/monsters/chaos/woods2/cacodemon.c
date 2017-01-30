inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()

int K;

reset(arg) {
  ::reset(arg);
    if (arg) return;

  MOCO("/players/jareel/weapons/chaos/woods2/demon_tail.c"),this_object());
    init_command("wield exotic");

  set_alias("demon");
  set_alt_name("greater demon");
  set_name("cacodemon");
  set_race("chaos");
  set_al(-1000);
  set_level(27);
  set_aggressive(1);
  set_hp(3000+random(4000));
  add_money(5000+random(15000));
  set_ac(1);
  set_heal(5,1);
  set_wc(66);
  set_res(60);
  set_ac_bonus(30); /* for having 60 res */
  set_armor_params("other|light",0,-100,"prot_from_light"); 
  set_armor_params("other|dark",0,100,"prot_from_dark"); 
  set_armor_params("other|fire",0,90,"prot_from_fire"); 
  set_armor_params("other|ice",0,10,"prot_from_ice"); 
  set_armor_params("other|evil",0,100,"prot_from_evil"); 
  set_armor_params("other|wind",0,-30,"prot_from_wind"); 
  set_armor_params("other|electric",0,-50,"prot_from_electric"); 
  set_armor_params("other|good",0,-100,"prot_from_good"); 
  set_armor_params("other|water",0,50,"prot_from_water"); 
  set_armor_params("other|earth",0,60,"prot_from_earth"); 
  set_armor_params("other|laser",0,100,"prot_from_laser"); 
  set_armor_params("other|poison",0,100,"prot_from_poisen"); 
  set_armor_params("magical",0,60,"prot_from_magical");
  set_armor_params("other|sonic",0,40,"prot_from_sonic"); 
  set_armor_params("other|mental",0,60,0); 
  set_dead_ob(this_object());
  set_short(HIK+"Cacodemon - Greater Demon Avatar"+NORM);
  set_long(BOLD+RED+
    "One of the most feared and deadly creatures in this realm, even in its avatar form he is\n"+
    "one of the three greater Dark Demons.  It's skin is a black, whale-like, smooth, surface.\n"+
    "Unpleasant horns that curve into each other adorn the demons head.  Bat-like wings\n"+
    "that make no sound as they flap tower from the demons back.  Ugly prehensile paws, and\n"+
    "a barbed tail lash out needlessly and disquietingly. The Cacodemons's face, or where it's\n"+
    "face should be, only a suggestive blackness prevails.  With poison dripping from its tail\n"+
    "and blood dripping from its claws, feath lingers in the air.\n"+NORM);

  add_spell(
    "dark blast","A beam of "+HIK+BLINK+"darkness"+NORM+" beams from the demon's eyes smashing into you!\n",
                 "A beam of "+HIK+BLINK+"darkness"+NORM+" beams from the demon's eyes smashing into #TN#!\n",
    10,180,"other|dark");

  add_spell(
    "evil",""+HIK+"Dark waves of energy infect your soul!"+NORM+"\n",
                 ""+HIK+"Dark waves of energy flow into #TN#!"+NORM+"\n",
    10,100,"other|evil");

  add_spell(
    "spirit","\n"+BOLD+"        An enraged Spirit slashes at you!\n"+NORM+"\n",
             "\n"+BOLD+"        An enraged Spirit slashes at #TN#.\n"+NORM+"\n",
    20,200,"other|spirit");

  add_spell(
    "tail slash",""+BOLD+GRN+"The demon's tail slashes into you."+NORM+"\n",
                 ""+BOLD+GRN+"The demon's tail slashes into #TN#."+NORM+"\n",
    20,90,"other|poison");

  add_spell(
    "claw shred",""+RED+"Cacodemon's claws slash and tear at your skin!"+NORM+"\n",
                 ""+RED+"The demon claws at #TN#'s flesh!"+NORM+"\n",
    90,120,"other|physical");

  set_chat_chance(10);
    load_chat(HIK+"Cacodemon growls:"+NORM+" 'Meat for the void!'\n");
    load_chat(HIK+"Cacodemon growls:"+NORM+" 'Your soul will be a nice addition to my collection!'\n");
}

prot_from_light(){  /* -100 resistance */
    write(BYEL+"Intense light sears the demons flesh.\n"+NORM);
  return 1;
}

prot_from_dark(){   /* 100 resistance */
    write(HIK+"Darkness has no effect against this powerful avatar.\n"+NORM);
  return 1;
}

prot_from_fire(){   /* 90 resistance */
    write(BRED+"Flames glance off the demons skin haveing no effect.\n"+NORM);
  return 1;
}

prot_from_ice(){   /* 10 resistance */
    write(BCYN+"Ice freezes to the demons skin.\n"+NORM);
  return 1;
}

prot_from_evil(){   /* 100 resistance */
    write(HIK+"Cacodemon says: "+NORM+"'Join me with your evil ways!'\n"+NORM);
  return 1;
}

prot_from_wind(){   /* -30 resistance */
    write(BBLU+"Air rends at the demons flesh.\n"+NORM);
  return 1;
}

prot_from_electric(){   /* -50 resistance */
    write(BBLU+CYN+"Energy arcs through the Avatars body.\n"+NORM);
  return 1;
}

prot_from_good(){   /* -100 resistance */
    write(BOLD+"Righteousness slices into the demon, causing the Avatar to writhe in pain.\n"+NORM);
  return 1;
}

prot_from_water(){   /* 50 resistance */
    write(BBLU+"Water washes over the demons body.\n"+NORM);
  return 1;
}

prot_from_earth(){   /* 60 resistance */
    write(BYEL+"Stones reflect off the demons hide\n"+NORM);
  return 1;
}

prot_from_laser(){   /* 100 resistance */
    write(HBRED+"Lasers reflect off the Avatars skin.\n"+NORM);
  return 1;
}

prot_from_poison(){   /* 100 resistance */
    write(HBGRN+"The Avatar shrugs off the Poison.\n"+NORM);
  return 1;
}

prot_from_magical(){   /* 60 resistance */
    write(HBMAG+"The Avatar absorbs some of the magical attack.\n"+NORM);
  return 1;
}

prot_from_sonic(){   /* 40 resistance */
    write("Sound resonates over the avatar skin.\n"+NORM);
  return 1;
}

heart_beat(){
  object ob;
  object att;
  object next;
    if(!environment()) return;
    if(ob = present("chaos", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
  ::heart_beat();
}

monster_died() {
}
