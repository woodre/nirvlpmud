/***************************************************************
**       Mp queries, sets                                     **
***************************************************************/
tell_mp(){
	tell_object(USER,
	"You currently have "+mp+" MP.\n");
	return 1;
}

mp_mon(){  write(BOLD+"MP ["+mp+"/"+query_max_mp()+"]"+NORM+"\n"); return 1; }





/****************************************************************
**      Special Scores, Inventory, etc.                        **
****************************************************************/
new_score2(){
	int x,amt;
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
	write(" Name: ");
	if(USER->query_pretitle()) write(""+USER->query_pretitle()+" ");
	write(""+capitalize(USER->query_name())+" ");
	if(USER->query_title())write(""+USER->query_title()+" ");
	write("("+USER->query_al_title()+")  [L: "+USER->query_level()+"");
	if(USER->query_extra_level()){
		write("+"+USER->query_extra_level()+"]  [GLVL: "+HIM+glvl+NORM+"]  ");
	}
	else{
		write("]  [GLVL: "+HIM+glvl+NORM+"] ");
	}
	if(USER->query_invis()) write(GRN+" - "+BOLD+"Camouflaged"+NORM+GRN+" - "+NORM+"\n\n");
	else write("\n\n");
	write(
		" Strength ["+USER->query_attrib("str")+"]\t\t\tIntelligence ["+USER->query_attrib("int")+"]\n"+
		" Stamina  ["+USER->query_attrib("sta")+"]\t\t\tWillpower    ["+USER->query_attrib("wil")+"]\n"+
		" Stealth  ["+USER->query_attrib("ste")+"]\t\t\tPiety        ["+USER->query_attrib("pie")+"]\n"+
        " Charisma  ["+USER->query_attrib("cha")+"]\t\t\tDexterity        ["+USER->query_attrib("dex")+"]\n"+
		" Luck     ["+USER->query_attrib("luc")+"]\t\t\tMagic        ["+USER->query_attrib("mag")+"]\n\n");
	write(BLU+" HP"+NORM+" "+BOLD+"("+NORM+HIB+USER->query_hp()+NORM+BOLD+"/"+NORM+HIB+USER->query_mhp()+NORM+BOLD+")"+NORM+"\t\t");
	if(glvl > 15){
		write("Guild Exp ["+COLOR+"Maxed"+NORM+"]\n");
	}
	else{
		write("Guild Exp ["+COLOR+gxp+NORM+"/"+COLOR+amt+NORM+"]\n");
	}
	write(RED+" SP"+NORM+BOLD+" ("+NORM+HIR+USER->query_sp()+NORM+BOLD+"/"+NORM+HIR+USER->query_msp()+NORM+BOLD+")"+NORM+"\t\t");
	write("Guild Lvl ["+COLOR+glvl+NORM+"]\n");
	write(
		" Food["+BOLD+USER->query_stuffed()*100/(USER->query_max_stuff())+NORM+"%] "+
		" Soak["+BOLD+USER->query_soaked()*100/(USER->query_max_soak())+NORM+"%] "+
	" Intox["+BOLD+USER->query_intoxination()*100/(USER->query_max_intox())+NORM+"%]\n");
	write(" ___________________________________________________\n");
	write("Experience ["+USER->query_exp()+"]     Coins ["+USER->query_money()+"]  \n\n");
	if(USER->query_quest_point())
	write("QPS        ["+USER->query_quest_point()+"]\n");
	write("\n");
	USER->show_age();
	write("\n");
        write("Carrying: "+USER->query_pct_weight()+"% of max.\n\n");
	USER->check_fight_area();
	if(USER->query_fight_area()){
		write(""+HIR+"PK Area"+NORM+"       ");
	}
	else{
		write(""+HIB+"NON-PK Area"+NORM+"   ");
	}
	write("         MP: "+BOLD+mp+NORM+"\\"+BOLD+query_max_mp()+NORM+"\n");
	write("Stored Coins/Matter/Sps: "+stored_mon+", "+stored_mp+", "+stored_sp+"\n");
	write("Skill Points: "+skill_pts+"\n"+
	"For a list of abilities type '"+HIM+"skills"+NORM+"' & '"+HIM+"link"+NORM+"' for help.\n");
	return 1;
}
new_score3(){
	int x,amt;
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
	write(" Name: ");
	if(USER->query_pretitle()) write(""+USER->query_pretitle()+" ");
	write(""+capitalize(USER->query_name())+" ");
	if(USER->query_title())write(""+USER->query_title()+" ");
	write("("+USER->query_al_title()+")  [L: "+USER->query_level()+"");
	if(USER->query_extra_level()){
		write("+"+USER->query_extra_level()+"]  [GLVL: "+HIM+glvl+NORM+"]  ");
	}
	else{
		write("]  [GLVL: "+HIM+glvl+NORM+"] ");
	}
	if(USER->query_invis()) write(GRN+" - "+BOLD+"Camouflaged"+NORM+GRN+" - "+NORM+"\n\n");
	else write("\n\n");
	write(BLU+" HP"+NORM+" "+BOLD+"("+NORM+HIB+USER->query_hp()+NORM+BOLD+"/"+NORM+HIB+USER->query_mhp()+NORM+BOLD+")"+NORM+"\t\t");
	if(glvl > 15){
		write("Guild Exp ["+COLOR+"Maxed"+NORM+"]\n");
	}
	else{
		write("Guild Exp ["+COLOR+gxp+NORM+"/"+COLOR+amt+NORM+"]\n");
	}
	write(RED+" SP"+NORM+BOLD+" ("+NORM+HIR+USER->query_sp()+NORM+BOLD+"/"+NORM+HIR+USER->query_msp()+NORM+BOLD+")"+NORM+"\t\t");
	write("Guild Lvl ["+COLOR+glvl+NORM+"]\n");
	write(
		" Food["+BOLD+USER->query_stuffed()*100/(USER->query_max_stuff())+NORM+"%] "+
		" Soak["+BOLD+USER->query_soaked()*100/(USER->query_max_soak())+NORM+"%] "+
	" Intox["+BOLD+USER->query_intoxination()*100/(USER->query_max_intox())+NORM+"%]\n");
	write(" ___________________________________________________\n");
	write("Experience ["+USER->query_exp()+"]     Coins ["+USER->query_money()+"]  \n\n");
	if(USER->query_quest_point())
	write("QPS        ["+USER->query_quest_point()+"]\n");
	write("\n");
	USER->show_age();
	write("\n");
        write("Carrying: "+USER->query_pct_weight()+"% of max.\n\n");
	USER->check_fight_area();
	if(USER->query_fight_area()){
		write(""+HIR+"PK Area"+NORM+"       ");
	}
	else{
		write(""+HIB+"NON-PK Area"+NORM+"   ");
	}
	write("         MP: "+BOLD+mp+NORM+"\\"+BOLD+query_max_mp()+NORM+"\n");
	write("Stored Coins/Matter/Sps: "+stored_mon+", "+stored_mp+", "+stored_sp+"\n");
	write("Skill Points: "+skill_pts+"\n"+
	"For a list of abilities type '"+HIM+"skills"+NORM+"' & '"+HIM+"link"+NORM+"' for help.\n");
	return 1;
}

inventory_cmd(){
	object woo,woo2;
	int i;
	i = 1;
	woo = first_inventory(environment());
	
	write(
		BOLD+"   ________________ [ Inventory ] ________________"+NORM+"\n"+
	"   Item: \n");
	
	while(woo){
		woo2 = next_inventory(woo);
		if(woo->short()){
			if(i < 10){ write("["+HIR+"0"+i+NORM+"] "+woo->short()+" "); }
			else{ write("["+HIR+i+NORM+"] "+woo->short()+"  ");  }
			if(woo->armor_class()){  write(HIR+"["+woo->query_type()+"]"+NORM+"\n"); }
			else if(woo->weapon_class()){ write(HIR+"[Weapon]"+NORM+"\n"); }
			else{ write("\n"); }
			i++;
		}
		
		woo = woo2;
	}

        write("\nCarrying: "+USER->query_pct_weight()+"% of max.\n");
	return 1;
}

