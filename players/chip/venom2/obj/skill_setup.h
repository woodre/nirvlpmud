/*******************************************************************
**                     Skill setup and querying                   **
*******************************************************************/
add_skill(str){
	if(!skills) skills = ({ str });
	else skills += ({ str });
}
query_skill(){ return skills; }
remove_skill(str){ skills -= str; }
set_skill(str){ skills = str; }

add_creation(int i){ creation += i; }
add_control(int i){ control += i; }
add_combat(int i){ combat += i; }
query_creation(){ return creation; }
query_control(){ return control; }
query_combat(){ return combat; }

add_sphere_delay(int i){ sphere_delay += i; }
query_sphere_delay(){ return sphere_delay; }

spend_pts(str){
	if(!skill_pts){ write("You have no skill points to spend.\n"); return 1; }
	if(!str){ write("raise which skill: combat, control, or creation?\n"); return 1; }
	if(str == "creation"){
		if(creation < 6){
			tell_object(USER, query_color()+"You raise Creation. For a list of new abilities type: skills"+NORM+"\n");
			skill_pts -= 1;
			creation += 1;
		}
		else{ tell_object(USER, query_color()+"You cannot raise Creation further."+NORM+"\n"); return 1; }
		return 1;
	}
	else if(str == "control"){
		if(control < 6){
			tell_object(USER, query_color()+"You raise Control. For a list of new abilities type: skills"+NORM+"\n");
			skill_pts -= 1;
			control += 1;
		}
		else{ tell_object(USER, query_color()+"You cannot raise Control further."+NORM+"\n"); return 1; }
		return 1;
	}
	else if(str == "combat"){
		if(combat < 6){
			tell_object(USER, query_color()+"You raise Combat. For a list of new abilities type: skills"+NORM+"\n");
			skill_pts -= 1;
			combat += 1;
		}
		else{ tell_object(USER, query_color()+"You cannot raise Combat further."+NORM+"\n"); return 1; }
		return 1;
	}
	else{ tell_object(USER, "raise_skill <creation, combat, control>\n"); return 1; }
	return 1;
}




/****************************************************************
**   Advancement system for New Symbs -- 19.75 Million to max  **
****************************************************************/
convert_xp(int i){
	int expcost,minexp,woo;
	
	if(glvl > 15){ write("You are maxed.\n"); return 1; }
	if(!i){ write("convert how many experience points?\n"); return 1; }
	sscanf(i, "%d", woo);
	if(USER->query_level() > 19) return 1;
	
	if(woo < 1){
		write("You must convert a positive number of experience points.\n");
	return 1; }
	
	expcost = woo;
	
	if(USER->query_extra_level() < 1 && USER->query_level() < 21)
	minexp = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",
	(this_player()->query_level()) - 1);
	
	if(USER->query_extra_level() > 0 && USER->query_level() < 21)
	minexp = USER->query_exp() - call_other("room/exlv_guild", "get_next_exp",
	USER->query_extra_level() - 1);
	
	if(expcost > minexp) {
		write("You do not have enough available experience to convert.\n");
		return 1;
	}
	
	USER->add_exp(-woo);
	write("You convert "+i+" experience towards your Symbiotic Control.\n");
	
        write_file("/players/chip/venom2/log/gexp",
          USER->query_name()+" converted "+woo+" to guild exp on "+ctime()+".\n");

	check_advance(woo);
	return 1;
}

check_advance(exp){
  int x, amt;
	
	if(glvl > 15) return;
	
       x = query_glvl();
	  switch(x){
		  case 0:  amt = 250000; break;
		  case 1:  amt = 500000; break;
		  case 2:  amt = 500000; break;
		  case 3:  amt = 750000; break;
		  case 4:  amt = 750000; break;
		  case 5:  amt = 750000; break;
		  case 6:  amt = 1000000; break;
		  case 7:  amt = 1000000; break;
		  case 8:  amt = 1000000; break;
		  case 9:  amt = 1500000; break;
		  case 10:  amt = 1500000; break;
		  case 11:  amt = 1500000; break;
		  case 12:  amt = 2000000; break;
		  case 13:  amt = 2000000; break;
		  case 14:  amt = 2000000; break;
		  case 15:  amt = 3000000; break;
	  }
	
	
	gxp += exp;
	
	if(amt <= gxp){
		gxp = gxp - amt;
		glvl += 1;
		skill_pts += 1;
		
		tell_object(USER,
			"\n"+query_color()+"                  !!! You Gain a Level !!! "+NORM+"\n"+
		"               You are now "+BOLD+"NeoSymbiote"+NORM+" Level "+glvl+".\n");
		if(amt <= gxp) check_advance(0);
		save_venom(1);
		return 1;
	}
	return 1;
}
