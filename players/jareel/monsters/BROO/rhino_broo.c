inherit "/obj/monster";
#include "/players/jareel/define.h"

int K;

reset(arg) {
  
  ::reset(arg);
  if (arg) return;

  set_alias("broo");
  set_alt_name("rhino");
  set_name(BOLD+MAG+"Rhino Broo"+NORM);
  set_race("chaos");
  set_al(-1000);
  set_level(21);
  set_aggressive(1);
  set_hp(600);
  add_money(500+random(7000));
  set_ac(11);
  set_heal(15,1);
  set_wc(45);
  set_armor_params("other|evil",0,50,"prot_from_evil");  
  set_armor_params("other|electric",0,-100,"prot_from_electric"); 
  set_armor_params("other|good",0,-100,"prot_from_good"); 
  set_armor_params("other|earth",0,100,"prot_from_earth"); 
  set_armor_params("other|poison",0,100,"prot_from_poisen"); 
  set_dead_ob(this_object());
  set_short(BOLD+MAG+"Rhino Broo"+NORM);
  set_long(BOLD+RED+
    "This creature embodies the very essence of chaos, with a human body and \n"+
    "the head of a rhino.  Putrid green bile pusses from open sores, covering \n"+
    "the creature with a mucus.  Your stomach starts to turn as you gaze upon\n"+
    "vile creature.\n"+
    "\n"+NORM);
  add_spell(
    "poisen hit",""+BOLD+GRN+"The broo pierces your skin infecting you with a deadly poisen!\n"+NORM+"",
                 "The broo scratches #TN# skin!\n",
    60,60,"other|poisen");

  add_spell(
    "rhino charge",""+BOLD+"The broo lowers it head and rams you with its horn!\n"+NORM+"",
                 "The broo smashes #TN# with its horn!\n",
    20,60,"other|physical");
}

prot_from_evil(){   /* 50 resistance */
    write(HIK+"Evil flows over the broos body.\n"+NORM);
  return 1;
}

prot_from_electric(){   /* -100 resistance */
    write(HBBLU+"Electric currents surge into the broo\n"+NORM);
  return 1;
}

prot_from_good(){   /* -100 resistance */
    write(BOLD+"Righteousness slices into the demon, causing the Avatar to writhe in pain.\n"+NORM);
  return 1;
}

prot_from_poisen(){   /* 100 resistance */
    write(HBGRN+"The Broo shrugs off the Poisen.\n"+NORM);
  return 1;
}

prot_from_earth(){   /* 100 resistance */
    write(YEL+"The earth has no effect on the earth bound creature\n"+NORM);
  return 1;
}

monster_died() {
}

heart_beat(){
  object ob;
  object att;
  object next;
    if(!environment()) return;
    if(ob = present("broo", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
  ::heart_beat();
}

query_mhp() { return query_hp(); }
