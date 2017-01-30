inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()

int K;

reset(arg) {
  ::reset(arg);
    if (arg) return;

  MOCO("/players/jareel/weapons/chaos/woods2/demon_tail.c"),this_object());
    init_command("wield exotic");

  set_alias("human");
  set_alt_name("mage");
  set_name("cacodemon");
  set_race("olimite");
  set_al(-1000);
  set_level(27);
  set_aggressive(1);
  set_hp(3000);
  add_money(5000+random(10000));
  set_heal(1,1);
  set_wc(10);
  set_armor_params("other|light",0,0,0); 
  set_armor_params("other|dark",0,0,0); 
  set_armor_params("other|fire",0,0,0); 
  set_armor_params("other|ice",0,0,0); 
  set_armor_params("other|evil",0,100,"prot_from_evil"); 
  set_armor_params("other|wind",0,0,0); 
  set_armor_params("other|electric",0,0,0); 
  set_armor_params("other|good",0,-100,"prot_from_good"); 
  set_armor_params("other|water",0,0,0); 
  set_armor_params("other|earth",0,0,0); 
  set_armor_params("other|laser",0,0,0); 
  set_armor_params("other|poison",0,0,0); 
  set_armor_params("other|physical",0,100,0);
  set_armor_params("other|magical",0,100,"prot_from_magical");
  set_armor_params("other|sonic",0,100,"prot_from_sonic"); 
  set_armor_params("other|mental",0,0,0); 
  set_dead_ob(this_object());
  set_short(HIK+"Olimite - Greater Demon Avatar"+NORM);
  set_long(BOLD+RED+
    "One of the most feared and deadly creatures in this realm, even in its avatar form he is\n"+
    "one of the three greater Dark Demons.  It's skin is a black, whale-like, smooth, surface.\n"+
    "Unpleasant horns that curve into each other adorn the demons head.  Bat-like wings\n"+
    "that make no sound as they flap tower from the demons back.  Ugly prehensile paws, and\n"+
    "a barbed tail lash out needlessly and disquietingly. The Cacodemons's face, or where it's\n"+
    "face should be, only a suggestive blackness prevails.  With poisen dripping from its tail\n"+
    "and blood dripping from its claws, feath lingers in the air.\n"+NORM);

  add_spell(
    "dark blast","Missle1\n",
                 "missle1 #TN#!\n",
    10,20,"other|dark");

  add_spell(
    "evil",""+HIK+"missle2"+NORM+"\n",
                 ""+HIK+"missle2 #TN#!"+NORM+"\n",
    10,15,"other|evil");

  add_spell(
    "spirit","\n"+BOLD+"        An enraged Spirit slashes at you!\n"+NORM+"\n",
             "\n"+BOLD+"        An enraged Spirit slashes at #TN#.\n"+NORM+"\n",
    20,20,"other|spirit");

  add_spell(
    "tail slash",""+BOLD+GRN+"missle3"+NORM+"\n",
                 ""+BOLD+GRN+"missle3#TN#."+NORM+"\n",
    20,15,"other|poisen");

  add_spell(
    "claw shred",""+RED+"Meteor"+NORM+"\n",
                 ""+RED+"Meteror"+NORM+"\n",
    90,10,"other|physical");

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

prot_from_poisen(){   /* 100 resistance */
    write(HBGRN+"The Avatar shrugs off the Poisen.\n"+NORM);
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
  corpse_loop();
}

void corpse_loop()    {
  object ob;
  if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
    tell_room(environment(),
      "Olimite takes: "+(string)ob->short()+".\n");
    move_object(ob, this_object());
    this_object()->corpse_loop();
  }
}

monster_died() {
}

