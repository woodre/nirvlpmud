/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     NPC
//  Create Date:  2004.08.11
//  Last Edit:    2004.08.24 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/flame_forest/ffdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";
#define MYN "Atticus"
#define BFDIR "/players/fred/closed/bloodfist/"

#define VIGOR_WCB 12 /* see function header for calculations */
#define BASH_WCB 19 /* see function header for calculations */
#define FURY_WCB 27 /* see function header for calculations */

object Axe, Armor, Ring, Ammy, Bag;
int a, Furious;
int *Settings;

id(str) { return (::id(str) || str == "atticus"); }

reset(arg){
  if(arg) return;
  ::reset(arg);

  Bag = clone_object("/players/forbin/realms/misc/OBJ/saddlebag.c");
  move_object(clone_object(BFDIR+"obj/water.c"), Bag);
  move_object(Bag, this_object());  
  
  Ring = clone_object(BFDIR+"eq/bloodfist_ring.c");  
  move_object(Ring, this_object());
  
  Ammy = clone_object(BFDIR+"eq/blood_amulet.c");
  switch(random(6))
  {
  	case 0: Ammy->set_bf_type("agl"); break;
    case 1: Ammy->set_bf_type("mit"); break;
    case 2: Ammy->set_bf_type("acc"); break;
    case 3: Ammy->set_bf_type("vig"); break;
    case 4: Ammy->set_bf_type("wis"); break;
    case 5: Ammy->set_bf_type("fai"); break;
    default: Ammy->set_bf_type("agl"); break;
  }
  move_object(Ammy, this_object());
  
  Armor = clone_object(OBJ+"ssmail.c");
  move_object(Armor, this_object());  
  
  Axe = clone_object(OBJ+"battleaxe.c");
  move_object(Axe, this_object());    
  
  for(a = 0; a < (2 + random(2)); a++)
    move_object(clone_object(BFDIR+"obj/water.c"), this_object());  
  
  command("wield axe", this_object()); 
  Axe->set_mobwield(1);
  Axe->set_gemtype(random(10));
  command("wear scalemail", this_object());
  command("wear amulet", this_object());
  command("wear ring", this_object()); 
  
  set_name(MYN);
  set_short(MYN);
  set_long(
    "Atticus stands before you, a tall, lean warrior of countless years.\n"+
    "He wears a suit of ruddy armor, while the head of a large bladed axe\n"+
    "resets upon the ground as he scans the area, head held high.  Several\n"+
    "scars are present on his arm.  Stories are told that many years ago,\n"+
    "he slaughtered many of his Bloodfist companions in a fit of rage.\n"+
    "His punishment was banishment from the camp, and he has wandered the\n"+
    "lands of Nirvana ever since.\n");
  set_race("human");
  set_level(23);
  set_ac(20); /* he has a lot of multiple attacks in a round, so lower ac than guide */
  set_wc(54);  
  set_wc_bonus(VIGOR_WCB + BASH_WCB + FURY_WCB);
  set_hp(850);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(6);
  load_chat(MYN+" scans the surrounding area, eyes darting back and forth.\n");
  load_chat(MYN+" eyes you up and down.\n");  
  load_a_chat(MYN+" ducks quickly.\n");
  load_a_chat(MYN+" feints to his right.\n");  
  load_a_chat(MYN+" feints to his left.\n");  
  set_dead_ob(this_object());
  Settings = ({ random(1500), random(18), random(3), });
  Furious = 0;
}

short() { return MYN+" "+get_title()+" ("+get_htitle()+")"; }

get_title() {
  string title;
  switch(Settings[1]) {
    case 0:  title = "the Masterful Desert Nomad"; break;
    case 1:  title = "the Desert Wolf"; break;
    case 2:  title = "the Bloodfist Hunter"; break;
    case 3:  title = "the Nomadic Hunter"; break;
    case 4:  title = "the Scorpion Hunter"; break;
    case 5:  title = "the Skilled Nomadic Hunter"; break;
    case 6:  title = "the Skilled Bloodfist Hunter"; break;
    case 7:  title = "the Desert Warrior"; break;
    case 8:  title = "the Bloodfist Warrior"; break;
    case 9:  title = "the Nomadic Warrior"; break;
    case 10: title = "the Desert Scorpion"; break;
    case 11: title = "the Seasoned Mercenary"; break;
    case 12: title = "the Nomadic Mercenary"; break;
    case 13: title = "the Master Bloodfist Warrior"; break;
    case 14: title = "the Desert Predator"; break;
    case 15: title = "the Bloodstained Predator"; break;
    case 16: title = "the Nomadic Predator"; break;    
    case 17: title = "the Legendary Bloodfist Warrior"; break;
  }
  if(Settings[2] == 2) return RED+title+NORM;
  else if(Settings[2] == 1) return HIK+title+NORM;
  else return YEL+title+NORM;
}

get_htitle() {
  string al_title;
    if(Settings[0] < 200)       al_title = "BloodInitiate";
    else if(Settings[0] < 400)  al_title = "BloodApprentice";
    else if(Settings[0] < 650)  al_title = "BloodRogue";
    else if(Settings[0] < 1100) al_title = "BloodWarrior";
    else if(Settings[0] < 1350) al_title = "BloodLord";
    else                        al_title = "BloodMaster";
    return RED+al_title+NORM;
}

study_response(object q) {
  if(!environment()) return;
  if(!q) return;
  tell_room(environment(),
    "\n"+MYN+" chuckles, \"Come on now "+q->query_name()+", just attack and get this over with.\"\n");
}

heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(!present(attacker_ob, environment())) return;
  if(weapon_class < 52) weapon_class = 52;
  if(armor_class < 22) armor_class = 22;
  if(hit_point < 900 && !random(4))
    drink_water();
  if(!random(4) && !Furious) {
    Furious = 1;
    tell_room(environment(this_object()),
      RED+"Atticus is engulfed by bloodfury!\n"+NORM);
  }
  if(!random(8)) 
    vigor();
  if(!random(5)) 
    bash();
  if(Furious) 
    fury();
  if(attacker_ob == this_object()) {
    stop_fight();
    stop_fight();
  }
}
/*
arrival(object you) {
  object gob;
  string yn;
  int c;
  if(!you) return;
  yn = you->query_name();
  if(!present(you, environment())) return;
  if((gob = present("bloodfist_gob", you))) {
    tell_object(you,"  -\n"+
      MYN+" says: \"Well looka here, looks like we gots a bloodfist punk.\"\n"+
      "Laughing at you, "+MYN+" says: \"Prepare to meet your maker!\n  -\n");
    tell_room(environment(),"  -\n"+
      MYN+" says: \"Well looka here, looks like we gots a bloodfist punk.\"\n"+
      "Laughing at "+yn+", "+MYN+" says: \"Prepare to meet your maker!\n  -\n", ({you}));
    call_out("slaughter", 10, find_player(you));
    return;
  }
}

slaughter(object you) {
  
}

void catch_tell(string str)
{
  string t1, t2, t3;
  object me;
  if(fighting) return;
*/
drink_water() {
  object tmp;
  if((tmp = present("zbf_water", this_object()))) {
    tell_room(environment(),
      MYN+" drinks from a canteen of water.\n");
    hit_point += 50;
    tmp->use_charge();
  }
}

/* 
//  ***********************************************************************
//  Function:    vigor
//  Description: 45 damage to main attacker_ob
//  Arguments:   none
//  WC_Bonus:    12
//    .30 (chance) * 40 (avg dmg) = 12 * 1 (no dmg type) = 12 round: 12
//  ***********************************************************************
*/

vigor() {
  string *mh;
  int z;
  mh = ({ "massacre", " to small fragments", 
          "smashed", " with a bone crushing sound",
          "hit", " very hard",
          "hit", " hard",
          "hit", "",
          "grazed", "",
          "tickled", " in the stomach" });
  if(present(attacker_ob, environment()) && !attacker_ob->query_ghost()) {            
    switch(random(7)) {
      case 0: z = 0; break;
      case 1: z = 2; break;
      case 2: z = 4; break;
      case 3: z = 6; break;
      case 4: z = 8; break;
      case 5: z = 10; break;
      case 6: z = 12; break;                       
    }
    tell_object(attacker_ob,
      MYN+" "+mh[z]+" you "+mh[z+1]+".\n");
    tell_room(environment(this_object()),
      MYN+" "+mh[z]+" "+attacker_ob->query_name()+" "+mh[z+1]+".\n", ({ attacker_ob }));
    attacker_ob->hit_player(20);        
    if(random(2)) {
      switch(random(7)) {
        case 0: z = 0; break;
        case 1: z = 2; break;
        case 2: z = 4; break;
        case 3: z = 6; break;
        case 4: z = 8; break;
        case 5: z = 10; break;
        case 6: z = 12; break;                       
      }
      tell_object(attacker_ob,
        MYN+" "+mh[z]+" you "+mh[z+1]+".\n");
      tell_room(environment(this_object()),
        MYN+" "+mh[z]+" "+attacker_ob->query_name()+" "+mh[z+1]+".\n", ({ attacker_ob }));      
      attacker_ob->hit_player(20);         
    }
    if(random(2)) {
      switch(random(7)) {
        case 0: z = 0; break;
        case 1: z = 2; break;
        case 2: z = 4; break;
        case 3: z = 6; break;
        case 4: z = 8; break;
        case 5: z = 10; break;
        case 6: z = 12; break;                       
      }
      tell_object(attacker_ob,
        MYN+" "+mh[z]+" you "+mh[z+1]+".\n");
      tell_room(environment(this_object()),
        MYN+" "+mh[z]+" "+attacker_ob->query_name()+" "+mh[z+1]+".\n", ({ attacker_ob })); 
      attacker_ob->hit_player(20);              
    }    
  }
}

/* 
//  ***********************************************************************
//  Function:    bash
//  Description: 75 physical damage to main attacker_ob
//  Arguments:   none
//  WC_Bonus:    19
//    .25 (chance) * 75 (avg dmg) = 18.75 * 1 (no dmg type) = 18.75 round 19
//  ***********************************************************************
*/

bash() {
  if(present(attacker_ob, environment()) && !attacker_ob->query_ghost()) {  
    tell_object(attacker_ob,
      MYN+" crushes you with his "+BOLD+"Tol'kor's Battle Axe"+NORM+"!\n");
    tell_room(environment(this_object()),
      MYN+" crushes "+attacker_ob->query_name()+" with his "+BOLD+"Tol'kor's Battle Axe"+NORM+"!\n", ({ attacker_ob }));
    attacker_ob->hit_player(75);
  }
}

/* 
//  ***********************************************************************
//  Function:    fury
//  Description: gives mob second attacks
//  Arguments:   none
//  WC_Bonus:    27
//    1.0 (chance) * 26.6 (avg wc) = 26.6 * 1 (no dmg type) = 26.6 round 27
//    -just figured using wc of 52 * 0 to 2 extra attacks so,
//     0 attacks 0 avg, 1 attack 26 avg, 2 attacks 54 avg, so total avg
//     of 26.6 avg damage
//  ***********************************************************************
*/

fury() {
  int a, b;
  if(present(attacker_ob, environment()) && !attacker_ob->query_ghost()) {
    for(a = 0; a < random(3); a++) {
      b = random(9);
      switch(b) {
        case 0:
          tell_room(environment(),
            RED+"A red haze blurs behind "+MYN+"!\n"+NORM);
          break;
        case 1:
          tell_room(environment(), 
            RED+MYN+"'s motions blur as he strikes!\n"+NORM);
          break;
        case 2:
          tell_room(environment(),
            RED+MYN+" moves as if through a blood cloud!\n"+NORM);
          break;
        case 3:
          tell_room(environment(),
            RED+"A red streak extends behind "+MYN+"!\n"+NORM);
          break;
        case 4..8: break;
      }
      already_fight = 0; 
      ::attack();
    }
  }  
}

query_guild_name() { return "bloodfist"; }

monster_died() {
  object corpse;
  object axe;
  corpse = present("corpse", environment());
  axe = present("battle axe", corpse);
  if(axe) {
    axe->weapon_breaks();
    axe->set_value(1);
    axe->set_mobwield(0);
    axe->set_brokethis(1);
    move_object(axe, environment(corpse));
  }
  tell_room(environment(this_object()),
    "\n\nWith the final blow, Atticus' weapon shatters and he tumbles\n"+
    "to the ground.  There is a soft sigh as he collapses in death.\n\n");
    return 1;
}
