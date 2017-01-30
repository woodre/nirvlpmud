/*************************************************************
***********  HeartBeat    ************************************
*************************************************************/
int deadbeat;
heart_beat(){
	
	object symbiote;
	object wshadow,wep;
	
if(!environment()){ return ; }
if(USER->query_level() > 19) return;
if(sphere_delay) sphere_delay--;

   if(!USER->query_ghost() && deadbeat){ deadbeat = 0; }

	if(USER->query_ghost()){
		pet = 0;
		if(sh_armors && !deadbeat){ tell_object(USER, "Your shaped armors disappear as you die...\n"); 
                           sh_armors = 0;
                           sh_armors = allocate(8);
                           deadbeat = 1;
                           }
		hypermode = 0;
		burnoff = 0;
		regen = 0;
		return;
	}
	
		if(!USER->query_weapon() && !USER->query_ghost()){
		wielded_by = this_player();
		call_other(USER, "wield", this_object(), 1);
		wielded = 1;
		tell_object(USER, BOLD+"Tentacles lash out and surround you offensively and defensively."+NORM+"\n");
	}
      if(current_wep && USER->query_weapon() != current_wep){
         current_wep = 0;
         }
      if(!current_wep && USER->query_weapon() && USER->query_weapon() != this_object()){
         tell_object(USER,
         BOLD+"\n"+HIK+"Dark Matter"+NORM+" lashes out and surrounds your weapon..."+NORM+"\n\n");
         current_wep = USER->query_weapon();
         }
		

	if(spell_delay) spell_delay = 0;
	if(mp > query_max_mp()) mp = query_max_mp();
	if(mp < 1) mp = 1;
	
	if(burnoff && total_tentacles("burnoff") > 0){
		if(USER->query_hp() < 50){
			tell_object(USER, query_color()+"Health too low -"+NORM+" stopping the burnoff process.\n");
			burnoff = 0;
		}
		else if(burnoff && !USER->query_intoxination() && !USER->query_stuffed() &&
			!USER->query_soaked()){
			tell_object(USER,
			query_color()+"Your body no longer has toxins to reduce, stopping the burnoff process."+NORM+"\n");
			burnoff = 0;
		}
		else{
			if(USER->query_hp() > 50 && random(100) < total_tentacles("burnoff") * 8){
				if(USER->query_intoxination()){
					USER->add_intoxination(-10);
					USER->add_hit_point(-1);
				}
				if(USER->query_stuffed()){
					USER->add_stuffed(-10);
				}
				if(USER->query_soaked()){
					USER->add_soaked(-10);
				}
				USER->add_hit_point(-1);
     			tell_object(USER, "You feel the waste in your body begin to dissipate...\n");
   		}
		}
	}
	
	if(USER->query_attack() && (USER->query_hp()*10)/(USER->query_mhp()) < 2){
		if(((USER->query_intoxination() * 2) + random(100)) >
			((USER->query_attrib("wil")*3)+ random(100)) && !USER->query_attack()->is_player()){
			tell_object(USER,
			HIR+"\n\n\nAs you grow weaker your Symbiote takes revenge on you for it's enslavement!"+NORM+"\n\n\n");
			symbiote = clone_object("/obj/monster.c");
			symbiote->set_name(HIR+symb_name+NORM);
			USER->stop_fight();
			USER->stop_fight();
			USER->attacked_by(symbiote);
			USER->add_hit_point(-350);
			USER->hit_player(20000000);
         write_file("/players/chip/venom2/log/symb_kill",
         USER->query_real_name()+" was killed by their own Symbiote. "+ctime(time())+".\n");
		}
	}
	
	
	if(mp < 10){
		tell_object(USER,
		"Your body requires "+HIK+"Dark Matter"+NORM+" to survive!\n");
		USER->hit_player(150);
		mp += 10;
	}
	
	if(USER->query_infuse() && !random(4)){
		tell_object(USER,
		""+HIR+"The infusion within your body eats at you!"+NORM+"\n");
		USER->heal_self(-(5 + random(5)));
		if(USER->query_hp() <= 0){
			USER->hit_player(1000);
		}
	}
	
	if(glvl > 10 && USER->query_hp() < USER->query_mhp() && random(100) < glvl/2 ){
		USER->add_hit_point(1);
	}
	
	if(hypermode && USER->query_attack()) hypermode -= 1;
	
	if(hypermode && !random(40) && !USER->query_attack()){
		switch(random(5) + 1){
			case 5:
			tell_room(environment(USER),
				USER->query_name()+"'s eyes blaze with an Inner "+COLOR+"Light"+NORM+".\n",
			({ USER }));
			break;
			case 4:
			tell_room(environment(USER),
				"You blink back a dizziness as "+USER->query_name()+"'s form blurs slightly.\n",
			({ USER }));
			break;
			case 3:
			tell_room(environment(USER),
			USER->query_name()+" tenses and relaxes over and over.\n", ({ USER }));
			break;
			case 2:
			tell_room(environment(USER),
			USER->query_name()+" breathes heavily as veins of "+HIK+"Dark Matter"+NORM+" pulse over "+USER->POS+" body.\n", ({ USER }));
			break;
			case 1:
			tell_room(environment(USER),
			USER->query_name()+" paces the ground as his form blurs.\n", ({ USER }));
			break;
		}
	}

	/****** Set magic to 8 if higher *****************/
	if(USER->query_level() < 20){
		if(USER->query_attrib("mag") > 8){
			tell_object(USER,
			"Your body feeds on your magical life! Magic drops to 8.\n");
			USER->set_attrib("mag", 8);
			USER->save();
			call_other(USER, "reset", 1);
		}
	}
	/************************************************/
	
   
	
	/******** Bonus Luck - 38 max based on Combat ******/
	if(USER->query_attrib("luc") == 30 )
        {
		tell_object(USER,
		BOLD+"Dark Matter"+NORM+" reinforces your senses...\n");
		USER->set_attrib("luc", 30 + (combat + 2));
		USER->reset(1);
		USER->save();
	}
        if(USER->query_attrib("luc") > 30 &&
           USER->query_attrib("luc") < (30 + (combat + 2)))
        {
		tell_object(USER,
		BOLD+"Dark Matter"+NORM+" reinforces your senses...\n");
		USER->set_attrib("luc", 30 + (combat + 2));
		USER->reset(1);
		USER->save();
        }

    /******** Bonus Strength - 38 max based on Control ******/
	if(USER->query_attrib("str") == 30 )
        {
		tell_object(USER,
		BOLD+"Dark Matter"+NORM+" reinforces your musculature...\n");
		USER->set_attrib("str", 30 + (control + 2));
		USER->reset(1);
		USER->save();
	}
        if(USER->query_attrib("str") > 30 &&
           USER->query_attrib("str") < (30 + (control + 2)))
        {
		tell_object(USER,
		BOLD+"Dark Matter"+NORM+" reinforces your musculature...\n");
		USER->set_attrib("str", 30 + (control + 2));
		USER->reset(1);
		USER->save();
        }
        
	/*************************************************/
	
	/******** Bonus Will Power - 38 max based on Creation ******/
	if(USER->query_attrib("wil") == 30 )
        {
		tell_object(USER,
		BOLD+"Dark Matter"+NORM+" reinforces your psyche...\n");
		USER->set_attrib("wil", 30 + (creation + 2));
		USER->reset(1);
		USER->save();
	}
        if(USER->query_attrib("wil") > 30 &&
           USER->query_attrib("wil") < (30 + (creation + 2)))
        {
		tell_object(USER,
		BOLD+"Dark Matter"+NORM+" reinforces your psyche...\n");
		USER->set_attrib("wil", 30 + (creation + 2));
		USER->reset(1);
		USER->save();
        }

	/***********************************************************/
	
   if(environment(USER)->query_symb_cave()) USER->heal_self(random(6) + 3);
	
	if(delay_bad) delay_bad -= 1;

if(USER->query_invis() && !random(4)) mp -= 1;
if(USER->query_invis() && mp < 50){
  tell_object(USER, gcolor+"\nYou run out of enough matter to sustain Camouflage."+NORM+"\n\n");
  USER->visible();
  }
if(USER->query_invis() && USER->query_level() < 20 && mp > 49) USER->set_invs_sp();
	
	if(regen){
		if(USER->query_sp() < 50){
			tell_object(USER,
			query_color()+"-- -- "+NORM+"Unable to maintain regeneration.  Stopping the process.\n");
			regen = 0;
		}
                if(USER->query_hp() == USER->query_mhp())
                {
                        tell_object(USER,
                        query_color()+"-- -- "+NORM+"Regeneration halted. You are now completely healthy.\n");
                        regen = 0;
                }
	}

	
	if(regen && total_tentacles("regeneration") > 0){
		if(random(100) < total_tentacles("regeneration") * 8){
			USER->add_hit_point(12);
			if(random(2)) USER->add_spell_point(-3);
			tell_object(USER,
			""+capitalize(symb_name)+" slowly mends your wounds...\n");
		}
	}
  
	
   if(environment()->query_real_name() == "chip")
   {
     if(!random(1))
       { USER->add_hit_point(999999); }
   }
}
