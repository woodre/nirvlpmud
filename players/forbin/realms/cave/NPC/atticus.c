/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     NPC
//  Create Date:  2004.08.11
//  Last Edit:    2006.05.31 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/flame_forest/ffdefine.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";
#define MYN "Atticus"
#define BFDIR "/players/fred/closed/bloodfist/"

#define VIGOR_WCB 20 /* see function header for calculations */
#define BASH_WCB 19  /* see function header for calculations */
#define FURY_WCB 80  /* see function header for calculations */
#define LUST_WCB 33  /* see function header for calculations */
#define WSPEC_WCB 2  /* 1 for 15% chance return 6 + 1 for 7% chance 7 heal self + return 6 */

object Gob, Shad, Axe, Armor, Ring, Ammy, Bag;
int HPB;
int a, c, Furious, Lusty;
int *Settings;
int WS, num;
string GN;

id(str) { return (::id(str) || str == "atticus" ||
                               str == "atticus_miniquest_npc"); }

reset(arg){
  if(arg) return;
  ::reset(arg);

  Gob = clone_object("/obj/treasure.c");
  Gob->set_id("bloodfist_gob");
  Gob->set_short(RED+"A blood crystal"+NORM+
                 "\nA small torch ("+RED+"lit"+NORM+")");
  Gob->set_long("No one should see this.\n");
  move_object(Gob, this_object());

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

  GN = ({ "major gem of performance", "gem of inescapable horror",
          "minds eye gem", "gem of battle rites", "major gem of agility",
          "major gem of vigor", "major gem of might", "major gem of accuracy",
          "major gem of wisdom", "major gem of faith", "major gold gem", });
  WS = ({ 7, 16, 15, 18, 1, 4, 2, 3, 5, 6, 8 });
    
  Axe = clone_object("/players/zeus/museum/OBJ/battle_axe.c");
  move_object(Axe, this_object());  
  Shad = clone_object("/players/fred/closed/bloodfist/obj/wep_shadow.c");
  Shad->set_bloodfist_wep_shadow(Axe);
  Shad->set_owner("atticus");
  Shad->set_socket();
  Shad->set_forged();
  Shad->socket(GN[num], 3, WS[num]);
  Shad->set_socketed();  
  
  for(a = 0; a < (2 + random(2)); a++)
    move_object(clone_object(BFDIR+"obj/water.c"), this_object());  
  
  command("wield axe", this_object()); 
  command("wear scalemail", this_object());
  command("wear amulet", this_object());
  command("wear ring", this_object()); 
  
  set_name(MYN);
  set_short(MYN);
  set_long(
    "Atticus stands before you, a tall, lean warrior of countless years.\n"+
    "He wears a suit of ruddy armor, while the head of a large bladed axe\n"+
    "rests upon the ground as he scans the area, head held high.  Several\n"+
    "scars are present on his arm.  Stories are told that many years ago,\n"+
    "he slaughtered many of his Bloodfist companions in a fit of rage.\n"+
    "His punishment was banishment from the camp, and he has wandered the\n"+
    "lands of Nirvana ever since.\n");
  set_race("human");
  set_level(23);
  set_ac(22); /* he has a lot of multiple attacks in a round, so lower ac than guide */
  set_wc(40); /* he has a lot of multiple attacks in a round, so lower wc than guide */  
  set_wc_bonus(VIGOR_WCB + BASH_WCB + FURY_WCB + LUST_WCB + WSPEC_WCB);
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
    "\n"+MYN+" chuckles, \"Come on now "+q->query_name()+
    ", just attack and get this over with.\"\n");
}

heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(!present(attacker_ob, environment())) return;
  if(weapon_class < 54) weapon_class = 54;
  if(armor_class < 22) armor_class = 22;
  if(hit_point < 900 && !random(4))
    drink_water();
  if(!random(4) && !Furious) 
  {
    Furious = 1;
    tell_room(environment(this_object()),
      RED+MYN+" is engulfed by bloodfury!\n"+NORM);
  }
  if(!random(6) && !Lusty)
  {
    Lusty = 1;
    tell_room(environment(this_object()),
      MYN+" is overcome with bloodlust!\n");    
  }
  if(!random(6) || c >= 4) 
    bash();
  else if(!random(2)) 
    vigor();
  if(Furious) 
    fury();
  if(Lusty)
    lust();
  if(attacker_ob == this_object()) 
  {
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
    HPB += 50;
  }
}

/* 
//  ***********************************************************************
//  Function:    vigor
//  Description: 40 damage to main attacker_ob
//  Arguments:   none
//  WC_Bonus:    20
//    .50 (chance) * 40 (avg dmg) = 20 * 1 (no dmg type) = 20 round: 20
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
  c ++;
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
  if(c >= 4)
    c = 0;
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
//  WC_Bonus:    80
//    1.0 (chance) * 40 * 2 (wc) = 80 * 1 (no dmg type) = 80 round 80
//    -just figured using wc of 40 with 0-2 extra attacks
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

/* 
//  ***********************************************************************
//  Function:    lust
//  Description: increased damage
//  Arguments:   none
//  WC_Bonus:    12
//    .55 (chance) * 60 (avg dmg) = 33 * 1 (no dmg type) = 33 round: 33
//  ***********************************************************************
*/

lust() 
{
  int a;
  a = random(11);
  switch(a)
  {
    case 0:
      tell_room(environment(),
        "Blood pulses violently through "+MYN+"'s veins.\n");
      break;
    case 1:
      tell_room(environment(), 
        "Sweat pours from "+MYN+"'s body as he fights.\n");
      break;
    case 2:
      tell_room(environment(),
        MYN+"'s muscles bulge beneath his skin.\n");
      break;
    case 3:
      tell_room(environment(),
        MYN+"'s movements are fueled by his rage.\n");
      break;
    case 4:
      tell_room(environment(),
        MYN+"'s fists clench uncontrollably.\n");
      break;
    case 5:
      tell_room(environment(),
        MYN+" sees the world through a bloody haze.\n");
      break;            
    case 6..10: break;
  }
  if(a < 6)
    attacker_ob->hit_player(60);     
}

query_guild_name() { return "bloodfist"; }

calculate_worth()
{
  hp_bonus += HPB;

  return (::calculate_worth());
}


monster_died() 
{
  object corpse, axe, gob;
  corpse = present("corpse", environment());
  axe = present("battle axe", corpse);
  gob = present("bloodfist_gob", corpse);
  if(axe) 
  {
    axe->weapon_breaks();
    move_object(axe, environment(corpse));
  }
  if(gob)
    destruct(gob);
#ifdef BIGKILLLOG
  mon_log(BIGKILLLOG);
#endif
  tell_room(environment(this_object()),
    "\n\nWith the final blow, Atticus' weapon shatters and he tumbles\n"+
    "to the ground.  There is a soft sigh as he collapses in death.\n\n");
  "/players/forbin/realms/cave/RMS/timerob.c"->load_it();
  "/players/forbin/realms/cave/RMS/timerob.c"->bfist_gone();     
    return 1;
}