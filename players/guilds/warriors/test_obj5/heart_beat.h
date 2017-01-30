
query_xste(){ return xste; }
set_xste(int i){ xste = i; }


heart_beat(){
	int ha;
   int mon;
   if(!environment()) return;
	if(blocked_wimpy) blocked_wimpy -= 1;
   if(delay) delay -= 1;
   if(hdelay) hdelay -= 1;

   if(bcommand_delay) bcommand_delay -= 1;

if(glvl > 39){
if(!ATT && !random(10 - (USER->query_attrib("sta")/4))) add_end(3 + random(4));
if(!ATT && !random(2) && time) add_end(1 + random(4));
}
/*************** ASSASSIN ****************************************************************/
if(assassin){
	 "/players/guilds/warriors/test_obj5/heart_beat.c"->main(0, this_object(), USER);
}
/*************** BERSERKER ***************************************************************/

if(berserker && USER->query_wimpy()){
   tell_object(USER, "Your wimpy is on.  This hurts.\n");
   USER->hit_player(15+random(10));
   }

if(berserker){
if(rage){
  if(USER->query_hp() < 13) rage = 0;
  if(rage){
   rage -= 1;
   USER->add_hit_point(-(skills[120]*2));
   if(!rage){
     tell_object(USER, "Your rage subsides...\n");
     }
    }
   }
  }

if(skills[121]){
  if(random(100) < skills[121] * 4){
    if(skills[121] < 4)
    {
      USER->add_hit_point(1);
      if(!ATT) add_end(1);
    }
    else if(skills[121] < 5)
    {
      USER->add_hit_point(2);
      if(!ATT) add_end(1 + random(2));
    }
    else
    {
      USER->add_hit_point(3);
      if(!ATT) add_end(1 + random(2));
    }
  }
}
/*************** PALADINS ****************************************************************/
      if(paladin && USER->query_money() > 50000){
         mon = USER->query_money() - 50000;
         USER->add_money(- mon);
         tell_object(USER, "You sacrifice "+mon+" coins!\n");
         }
		if(regen_aura){
		if(endurance > 1 && random(100) < skills[92] * 4){
			USER->add_hit_point(1);
			tell_object(USER, BLU+"A warmth spreads throughout your body...\n"+NORM);
			add_end(-1);
		}
	}
	
/*************** MONKS *******************************************************************/
if(mind){
		if(random(100) < 15) USER->add_spell_point(1+random(skills[85]));
	}
if(meditate == 4 && ATT){ meditate = 3; write(HIB+"\n\n\nYou begin to revive!\n\n\n"+NORM); }
	if(meditate == 4){
		add_end(1+random(skills[85]));
		if(time) add_end(1+random(2));
		if(random(10) < skills[85]){
			tell_object(USER, HIW+"Through concentration, you mend your wounds..."+NORM+"\n");
			tell_object(USER,
				"        "+HIW+"HPS ["+USER->query_hp()+"/"+USER->query_mhp()+"]"+
			"    END ["+USER->query_sp()+"/"+USER->query_msp()+"]"+NORM+"\n");
			show_end();
                        tell_object(USER, "\n");
			USER->heal_self(1+random(skills[85]));
			if(skills[85] == 5 && !random(10)) meditate_vision();
		}
	}
	if(meditate > 0 && meditate < 4) meditate -= 1;
/******************************************************************************************/


	if(strength_bonus || xstr){
		if(USER->query_attrib("str") >= 30){
			if(USER->query_attrib("str") < 30 + strength_bonus + xstr){
				USER->set_attrib("str", 30 + strength_bonus + xstr);
				tell_object(USER, "You feel strength enter your body as you grow in experience.\n");
			}
		}
	}
       if(stamina_bonus || xsta){
		if(USER->query_attrib("sta") >= 30){
			if(USER->query_attrib("sta") < 30 + stamina_bonus + xsta){
				USER->set_attrib("sta", 30 + stamina_bonus + xsta);
				tell_object(USER, "You feel stamina enter your body as you grow in experience.\n");
			}
		}
	}
   if(!stealth_bonus && !xste && USER->query_attrib("ste") > 30){
      USER->set_attrib("ste", 30);
      }
   
	if(stealth_bonus || xste){
      if(USER->query_attrib("ste") > 30 + stealth_bonus + xste){
        	USER->set_attrib("ste", 30 + stealth_bonus + xste);
         }
		if(USER->query_attrib("ste") >= 30){
			if(USER->query_attrib("ste") < 30 + stealth_bonus + xste){
				USER->set_attrib("ste", 30 + stealth_bonus + xste);
				tell_object(USER, "You feel stealth enter your body as you grow in experience.\n");
			}
		}
	}
	
	if(healing && heal_room && ATT){
		healing = 0; heal_room = 0;
		tell_object(USER, "You cease to mend your wounds as you begin to fight!\n");
	}
	if(healing && !heal_room) healing = 0;
	if(!healing && heal_room) heal_room = 0;
	if(healing && heal_room && !random(3)){
		if(file_name(environment(USER)) != heal_room){
			tell_object(USER, "You stop mending your wounds...\n");
			healing = 0;
			heal_room = 0;
		}
		if(healing < 4){
			USER->add_hit_point(healing);
			healing = 0;
			heal_room = 0;
			tell_object(USER, "You finish mending your wounds...\n");
		}
		else{
			ha = random(3) + 1;
			healing -= ha;
			USER->add_hit_point(ha);
			tell_object(USER, "You work to mend your wounds...\n");
		}
	}
}
