/*
 *      File:                   beast.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 06/28/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
int heal, heal1;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("Neuron Beast");
  set_alt_name("beast");
  set_short(HIB+"Neuron Beast"+NORM);
  set_gender("male");
  set_race("demon");
  set_long("At fifteen feet this demon towers over the room.  Large tentacles\n"+
           "dangle from his torso where legs would normally be.  A dark demonic\n"+
           "surrounds it as hovers here guarding it's lair.\n");
  set_level(23);
  set_ac(23);
  set_wc(30);
  set_hp(2000);
  set_heal(1,6);
  set_hp_bonus(1400);
  set_al(-1000);
  set_chat_chance(5);
  load_chat(HIB+""+ton+""+NORM+" floats around the room.\n");
  set_a_chat_chance(3);
  load_a_chat(HIB+""+ton+NORM+" "+BLU+"SCREAMS:"+HIR+" I WILL BE THE END OF YOU MORTAL!\n"+NORM);
  load_a_chat(HIB+""+ton+NORM+" "+BLU+"concentrates and "+top+" wounds close.\n"+NORM);
  set_armor_params("other|evil", 10,30, "aura_evil");
  set_armor_params("other|holy", -10,-30,"aura_holy");
  add_money(7000+random(5000));
  add_spell("fireball",
            "#MN# intones: xar kun nop\n\n"+
            BLINK+HIR+"\tF L A M E S"+NORM+" envelop you!\n\n",
            "#MN# intones: xar kun nop\n\n"+
            BLINK+HIR+"\tF L A M E S"+NORM+" envelop #TN#!\n\n",
            15,120,"other|fire");
  add_spell("iceball",
            "#MN# intones kun nep sal\n\n"+
            BLINK+HIC+"\tI C E  S H A R D S"+NORM+" stab you!\n\n",
            "#MN# intones kun nep sal\n\n"+
            BLINK+HIC+"\tI C E  S H A R D S"+NORM+" pummel #TN#.\n\n",
            15,150,"other|ice");
  
  add_spell("mindblast",
            "#MN# concentrates briefly\n\n"+
            BLINK+WHT+BBLU+"M E N T A L  F O R C E"+NORM+" slams into you.\n\n",
            "#MN# concentrats briefly\n\n"+
            BLINK+WHT+BBLU+"M E N T A L  F O R C E"+NORM+" #TN# staggers under the strain.\n\n",
            20,100,"other|mental");

heal = 0;               
heal1 = 1;
set_dead_ob(this_object()); 
            }
id(str){return (::id(str) || str == "demon" || str == "neuron beast" || str == "beast" || str == "Beast");}

init(){
 ::init();
  add_action("stop","back");
}
monster_died(ob){
    object amulet;   
    tell_room(environment(),
    "A small amulet falls to the ground as the demon dies.\n");
    amulet = clone_object("/players/hogath/area/items/armors/angelam.c");
    move_object(amulet,environment(ob));
    }
stop(){
  write("The demon blocks your passage back.\n");
  return 1;
}

heart_beat(){
  object attacker;
  attacker = this_object()->query_attack();
  ::heart_beat();
  if(!attacker) return;
  if (this_object()->query_hp() < 1000 && heal < 1){
    tell_room(environment(this_object()),HIK+"A dark aura surrounds the Neuron Beast\n"+
                              "as it's wounds close."+NORM);
    heal_self(1000); heal++;}
  if (this_object()->query_hp() < 200  && heal1 > 0){
    tell_room(environment(this_object()),HIR+"Neuron Beast draw upon unholy might to\n"+
                                "heal itself.\n"+NORM);
    heal_self(400);
    heal1--;
    }
  if(!random(20) && !attacker_ob->query_dead())
    { tell_room(this_object(),"Neuron beast rushes forward and slams "+attacker->query_name()+".\n");
      already_fight=0;
      attack();
      already_fight=0;
      attack();
      }
    }


int aura_evil(){
  if(!random(4)){
    tell_room(environment(),
    HIK+"Stalagmite glow dark as they draw away the attack!\n"+NORM); 
    heal_self(25);
    return 1002;
  }
}

int aura_holy(){
  if(!random(4)){
    tell_room(environment(),
    HIW+"Demon Beast screams as holy energy cuts through it!\n"+NORM);
    return -1000;
  }
}
