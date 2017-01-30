heart_beat(){
	int ha;
   if(!environment()) return;
	if(blocked_wimpy) blocked_wimpy -= 1;
	if(strength_bonus){
		if(USER->query_attrib("str") >= 20){
			if(USER->query_attrib("str") < USER->query_attrib_max("str") + strength_bonus){
				USER->set_attrib("str", USER->query_attrib("str") + strength_bonus);
				tell_object(USER, "You feel strength enter your body as you grow in experience.\n");
			}
		}
	}
	if(stamina_bonus){
		if(USER->query_attrib("sta") >= 20){
			if(USER->query_attrib("sta") < USER->query_attrib_max("sta") + stamina_bonus){
				USER->set_attrib("sta", USER->query_attrib("sta") + stamina_bonus);
				tell_object(USER, "You feel stamina enter your body as you grow in experience.\n");
			}
		}
	}
   if(!stealth_bonus && USER->query_attrib("ste") > USER->query_attrib_max("ste")){
      USER->set_attrib("ste", USER->query_attrib_max("ste"));
      }
   
	if(stealth_bonus){
      if(USER->query_attrib("ste") > USER->query_attrib_max("ste") + stealth_bonus){
        	USER->set_attrib("ste", USER->query_attrib_max("ste") + stealth_bonus);
         }
		if(USER->query_attrib("ste") >= 20){
			if(USER->query_attrib("ste") < USER->query_attrib_max("ste") + stealth_bonus){
				USER->set_attrib("ste", USER->query_attrib_max("ste") + stealth_bonus);
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
