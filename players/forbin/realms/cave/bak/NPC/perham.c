/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qualtor Miniquest
//  Function:     NPC
//  Create Date:  2005.07.16
//  Last Edit:    2005.07.16 -Forbin
//  Notable Changes:            
*/ 

#include "/players/forbin/realms/cave/cavedefine.h"
#include "/players/forbin/logging.h"
#include "/players/forbin/closed/wiztool/cmds/date_time.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

int Busy;

id(str) { 
  return (::id(str) || str == "perham" || str == "faris"  
                    || str == "faris perham" || str == "sir faris perham"  
                    || str == "man" || str == "paladin" || str == "knight"
                    || str == "sfp_miniquest_npc"); 
}

reset(arg) {
  object armor1, armor2;
  ::reset(arg);
  if(arg) return;
  armor1 = clone_object(OBJ+"breastplate.c"); 
  move_object(armor1, this_object());
  armor2 = clone_object(OBJ+"shield.c");  
  move_object(armor2, this_object());
  move_object(clone_object(OBJ+"tunic.c"), this_object()); 
  move_object(clone_object(OBJ+"dmace.c"), this_object());       
  if(!random(3)) {
    switch(random(2)) {
      case 0: armor1->set_bonus(); break;
      case 1: armor2->set_bonus(); break;
    }
  }
  command("wear breastplate", this_object());   
  command("wear tunic", this_object());   
  command("wear shield", this_object());   
  command("wield mace", this_object());         
  set_name("Sir Faris Perham");
  set_race("human");
  set_gender("male");
  set_short("A man paces about the fire");
  set_long(
    "Pacing around the fire and gazing at its smoldering light is Sir Faris\n"+
    "Perham.  Once a Qual'tor Crusader, he is a tall and broad-chested\n"+
    "man.  Even in the dim light of the fire, his dark skin creates a bold\n"+
    "contrast against the soiled white tunic he wears.  A bulky, round\n"+
    "shield is strapped to his right arm and he holds a large mace in that\n"+
    "hand, balanced upon his shoulder.  A sparkling white breastplate peeks\n"+
    "through the tunic at the neck and arms, adding bulk to an already\n"+
    "considerable man.  He looks to be lost in reflection, but might be more\n"+
    "talkative if one where to ask about his story.\n");  
  set_level(24);
  set_hp(1200);
  set_al(0);
  set_wc(45);
  set_ac(25);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("The man scratches his chin.\n");
    load_chat("The man spits into the fire\n");
    load_chat("Sir Perham lowers his head into his hand.\n");
    load_chat("The man ignores your presence.\n");
    load_chat("Sir Perham rubs his cheek.\n");
    load_chat("Sir Perham eyes you over.\n");
    load_chat("Sparks fly up as the man pokes at the fire with a stick.\n");
    load_chat("The man rubs his eyes as if he is tired.\n");
    load_chat("Perham sighs, \"I would greatly like to return to Qual'tor.\"\n");              
  set_a_chat_chance(20);
    load_a_chat("Sir Perham dodges your attack.\n");
  add_spell("light1",
    "Sir Perham holds the "+HIW+"Mace of Disruption"+NORM+
    " high in the air.  There is\n"+
    "a bright flash as $HY$light$N$ streams out and strikes you!\n",
    "Sir Perham holds the "+HIW+"Mace of Disruption"+NORM+
    " high in the air.  There is\n"+
    "a bright flash as $HY$light$N$ streams out and strikes #CTN#!\n",
    7, "25-60", "other|light");     
  add_spell("light2",
    "Sir Perham holds the "+HIW+"Disruption Mace"+NORM+
    " high in the air.  There is\n"+
    "a bright flash as $HY$light$N$ streams out and strikes you!\n",
    "Sir Perham holds the "+HIW+"Disruption Mace"+NORM+
    " high in the air.  There is\n"+
    "a bright flash as $HY$light$N$ streams out and strikes #CTN#!\n",
    7, "25-60", "other|light"); 
  add_spell("trip",
    "Sir Perham sticks out his foot and trips you.\n"+
    "$HM$SPLAT!!!$N$  You land flat on your face!\n",
    "Sir Perham sticks out his foot and trips his opponent.\n"+
    "$HM$SPLAT!!!$N$  #CTN# lands flat on #TP# face!\n",
    6, "10-20", "physical");    
  add_spell("shieldbash",
    "Sir Perham rares back and smashes you in the face with his shield!\n",
    "Sir Perham rares back and smashes #CTN# in the face with his shield!\n",
    15, "30-40", "physical");   
  add_spell("prayertotarkos",
    "Sir Perhams mutters a prayer to Tarkos, before speaking...\n"+
    "\n          $HR$++ $HW$H $HR$+ $HW$O $HR$+ $HW$L $HR$+ $HW$Y $HR$++ $HW$W $HR$+ $HW$O $HR$+ $HW$R $HR$+ $HW$D $HR$++\n\n"+
    "        Heavenly enery wracks your body with pain!\n",
    "Sir Perhams mutters a prayer to Tarkos, before speaking...\n"+
    "\n          $HR$++ $HW$H $HR$+ $HW$O $HR$+ $HW$L $HR$+ $HW$Y $HR$++ $HW$W $HR$+ $HW$O $HR$+ $HW$R $HR$+ $HW$D $HR$++\n\n"+
    "        Heavenly enery wracks #CTN#'s body with pain!\n",
    5, "50-100", "other|good");    
}

init(){
  ::init();
}

void story_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\nSir Perham tells you:\n"+
    "  \"Many ages ago, I was a Crusader in the City of Qual'tor.  I helped\n"+
    "  to defend that city for two decades against the evil scourge of the\n"+
    "  undead that plagued it after its first fall.  With an army in the\n"+
    "  hundreds, we finally ended the reign of ghostly spirits, until their\n"+
    "  presence was all together forgotten.\"\n");
  tell_room(environment(), 
    "Sir Perham says something to "+(string)who->query_name()+".\n", ({who}) );
  call_out("story2_info", 13, who);
}

void story2_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\nSir Perham continues:\n"+
    "  \"But the City's golden age did not last.  Though we thought that we\n"+
    "  had defeated the undead, we had merely pushed them back from the\n"+
    "  the city itself and forced them to regroup their numbers.  Their\n"+
    "  Master, and evil Wizard from a distant land, gathered his unliving\n"+
    "  forces and laid a great siege upon the city.  We were overwhelmed\n"+
    "  and the City fell.\"\n");
  call_out("story3_info", 14, who);
}

void story3_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\nSir Perham says:\n"+
    "  \"Many of my fellow warriors died during this war, but I was captured\n"+
    "  and brought before this evil sorcerer, who deemed the insolence of\n"+
    "  fighting against him was to be punished by banished from my world.\n"+
    "  He conjured open a fearsome portal, and I was cast into it.\"\n");
  call_out("story4_info", 10, who);
}

void story4_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_room(environment(),
    "Sir Perham points toward the ivory portal.\n");
  call_out("story5_info", 2, who);
}

void story5_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\nSir Perham finishes you:\n"+
    "  \"I want to return to my land and defeat this evil wizard, but the\n"+
    "  only way back is through that portal.  Having heard tales of a\n"+
    "  holy warrior in this region that might know how to re-open the\n"+
    "  portal, I've been searching the area.  But so far I've had no\n"+
    "  luck in finding him.\"\n");
  call_out("story6_info", 14, who);    
}

void story6_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\nSir Perham asks:\n"+
    "  \"Could you help in my search?\".\n");
}

void helping_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\nSir Perham tells you:\n"+
    "  \"See if you can find the holy warrior.  If you should, waste no\n"+
    "  time returning to tell me, ask what he knows about the portal\n"+
    "  spell.  Please hurry.\"\n");
  tell_room(environment(), 
    "Sir Perham says something to "+(string)who->query_name()+".\n", ({who}) );    
}

void warrior_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\nSir Perham tells you:\n"+
    "  \"I do not know much about this man, except I was told that he is a\n"+
    "  fierce slayer of demonkind and was travelling to this region with the\n"+
    "  purpose of ridding a demon infestation of a nearby holy site.\"\n");
  tell_room(environment(), 
    "Sir Perham says something to "+(string)who->query_name()+".\n", ({who}) );
  call_out("warrior2_info", 6, who);    
}

void warrior2_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\nSir Perham leans close and then whispers:  \"I believe he is called\n"+
    "The Hunter.\"\n");
  tell_room(environment(), 
    "Sir Perham whispers to "+(string)who->query_name()+".\n", ({who}) );
}

void qualtor_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\n");
  tell_room(environment(), 
    "\n", ({who}) );
}

void portal_info(object who) {
  if(!who || !present(who, environment())) return;
  tell_object(who,
    "\n");
  tell_room(environment(), 
    "\n", ({who}) );
}


void bow_back(object who) {
  if(who && present(who, environment())) {
    if(random(4)) {
      tell_object(who, "Sir Perham bows to you.\n");
      tell_room(environment(), "Sir Perham bows to "+who->query_name()+".\n", ({ who }));
    }
    else {
      tell_object(who, "Sir Perham glances at you.\n");
      tell_room(environment(), "Sir Perham glances at "+who->query_name()+".\n", ({ who }));
    }
  }
}

void arrives(object who) {
  int g;
  if(who && present(who, environment())) {
    g = random(11);
    switch(g) {
      case 0..4:
        tell_object(who, "Sir Perham glances at you.\n");
        tell_room(environment(), "Sir Perham glances at "+who->query_name()+".\n", ({ who }));
        break;
      case 5:
        tell_room(environment(), "Sir Perham says, \"Greetings "+who->query_name()+".\"\n");
        break;
      case 6:
        tell_room(environment(), "Sir Perham says, \"Hello "+who->query_name()+".\"\n");
        break;
      case 7:
        tell_object(who, "Sir Perham smiles at you.\n");
        tell_room(environment(), "Sir Perham smiles at "+who->query_name()+".\n", ({ who }));
        break;
      case 8..10:
        break;
    }
  }
}

void catch_tell(string str) {
  string str1, str2, str3;
  string tmp1, tmp2, tmp3;
  object who, ps, pt, pd, cs, ct, cd;
  if(sscanf(str, "%s gives %s to Perham%s\n", tmp1, tmp2, tmp3) || 
     sscanf(str, "%s gives %s to Knight%s\n", tmp1, tmp2, tmp3)) {
     if(find_player(lower_case(tmp1))) 
       who = find_player(lower_case(tmp1));
    ps = present("scroll", this_object());
    if(ps) {
      str1 = file_name(ps);
      sscanf(str1, "%s#%s", str2, str3);
      if(str2 == "players/forbin/realms/cave/scroll")
        cs = ps;
    }
    pt = present("talisman", this_object());
    if(pt) {
      str1 = file_name(pt);
      sscanf(str1, "%s#%s", str2, str3);
      if(str2 == "players/zeus/realm/OBJ/talisman")
        ct = pt;
    }
    pd = present("diamond", this_object());
    if(pd) {
      str1 = file_name(pd);
      sscanf(str1, "%s#%s", str2, str3);
      if(str2 == "players/forbin/realms/cave/scroll")
        cd = pd;
    }        
    
    if(cs && ct && cd) {
      call_out("open_portal", 1, who);
    }
      
    if((ps && !cs) || (pt && !ct) || (pd && !cd)) {
      tell_room(environment(), 
        "\nSir Perham smiles: \"Thank you for the "+tmp2+", "+
        (string)who->query_name()+", but I do not need it.\"\n");
      command("drop "+tmp2, this_object());
    }
    if(ct && !cs) {
      tell_room(environment(), 
        "\nSir Perham smiles: \"Thank you for the "+tmp2+", "+
        (string)who->query_name()+", but I do not need it.\"\n");
      command("drop "+tmp2, this_object());
    }
    if(cs && (!ct && !cd)) {
      call_out("scroll_notalisman_nodiamond", 1, who);  
    }
            
    if(gsword || csword) {
      str1 = file_name((gsword ? gsword : csword));
      sscanf(str1, "%s#%s", str2, str3);
      if(str2 == "players/snow/WEAPONS/glow_sword" ||
         str2 == "players/llew/closed/crystal/crystal_sword") {
        command("unwield broadsword", this_object());
        command("wield sword", this_object());
        if(gsword) {
        	Busy = 1;
          call_out("gave_gsword", 1, who);
          write_file(
            "/players/forbin/logs/sfp_miniquest.log",
            "["+date_time()+"] "+
            capitalize((string)who->query_real_name())+" ("+
            (string)who->query_level()+"+"+(string)who->query_extra_level()+
            ") gave Eghyron: Glowing Sword\n");
        }
        else {
        	Busy = 1;
          call_out("gave_csword", 1, who);        
          write_file(
            "/players/forbin/logs/sfp_miniquest.log",
            "["+date_time()+"] "+
            capitalize((string)who->query_real_name())+" ("+
            (string)who->query_level()+"+"+(string)who->query_extra_level()+
            ") gave Eghyron: Crystal Longsword\n");
        }
      }
    }
    else if(bountyob) {
    	Busy = 1;
      call_out("collect_bounty", 1, who);        
      write_file(
        "/players/forbin/logs/ruinbounty.log",
        "["+date_time()+"] "+
        capitalize((string)who->query_real_name())+" ("+
        (string)who->query_level()+"+"+(string)who->query_extra_level()+
        ") was rewarded by Eghyron for :"+(string)bountyob->query_name()+"\n");
    }    
    else {
      tell_room(environment(), 
        "Eghyron says: \"Thank you for the "+tmp2+", "+
        (string)who->query_name()+", but I do not need it.\"\n");
      command("drop "+tmp2, this_object());
    }      
  }
  
    
  
  if(sscanf(str, "%sbows%syou.", tmp1, tmp2) == 2) {
    who = this_player();
    if(who->is_player() && !who->query_attack())
      call_out("bow_back", 1, who);
  }
  else if(sscanf(str, "%s arrives.%s\n", tmp1, tmp2) == 2) {
     call_out("arrives", 2, find_player(lower_case(t1)));
  }
  else if(sscanf(str, "%sstory%s", tmp1, tmp2) == 2) {
    who = this_player();
    if(who->is_player() && !who->query_attack())
      call_out("story_info", 1, who);
  }    
  else if(sscanf(str, "%shelp%s", tmp1, tmp2) == 2) {
    who = this_player();
    if(who->is_player() && !who->query_attack())
      call_out("helping_info", 1, who);
  }    
}


monster_died() {
#ifdef BIGKILL
  mon_log(BIGKILL);
#endif
  tell_room(environment(this_object()),
    "");
  "/players/forbin/realms/cave/RMS/timerob.c"->load_it();
  "/players/forbin/realms/cave/RMS/timerob.c"->knight_gone();  
  return 1;
}

