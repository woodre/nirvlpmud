/*
	This is the function that is called when a monk wants to
	heal either another player or him/herself.

	the c_mod is the level of training that the monk as obtained
	in the healing arts.
*/

cure_f(str) {
        string how;
        string who;
        object target;
 
if(!str){
        write("You may either cure light, cure medium, "+
              "cure serious or cure critical. \n");
        }
sscanf(str, "%s %s", how, who);
        if(!who) {
                if(how == "light" && c_mod < 5) {
                   write(train_fail);
                   return 1;
                }
		if(how == "light" && c_mod > 4) {
		   if(tps < 4) {
			write(spirit_fail);
			return 1;
		   }
		   if(tps >3) {
			write(init_chant);
			write(cure);
			write(g_msg);
			this_player()->add_sp(-4);
			this_player()->add_hps(2+random(8));
			return 1;
		   }
		}
		if(how == "medium" && c_mod < 10) {
		   write(train_fail);
		   return 1;
		}
		if(how == "medium" && c_mod > 9) {
		   if(tps < 16) {
			write(spirit_fail);
			return 1;
		   }
		   if(tps > 15) {
			write(init_chant);
			write(cure);
			write(g_msg);
			this_player()->add_sp(-15);
			this_player()->add_hp(12+random(8));
			return 1;
		   }
		}
		if(how == "serious" && c_mod < 15) {
		   write(train_fail);
		   return 1;
		}
		if(how == "serious" && c_mod > 14) {
		   if(tps < 28) {
			write(spirit_fail);
			return 1;
		   }
		   if(tps > 27) {
			write(init_chant);
			write(cure);
			write(g_msg);
			this_player()->add_sp(-50-random(c_mod));
			this_player()->add_hp(20+random(c_mod));
			return 1;
		   }
		}
		if(how == "critical" && c_mod < 20) {
		   write(train_fail);
		   return 1;
		}	
		if(how == "critical" && c_mod > 19) {
		   if(tps < 40) {
			write(spirit_fail);
			return 1;
		   }
		   if(tps > 39) {
			write(init_chant);
			write(cure);
			write(g_msg);
			this_player()->add_sp(-70-random(c_mod));
			this_player()->add_hp(30+2*random(c_mod));
			return 1;
		   }
		}
	}
	target = present(who,environment(this_player()));
	if(!target) {
		write("The player must be present in order for "+
		      "your cure to take effect.\n");
		return 1;
	}
	if(how == "light" && c_mod < 5) {
                   write(train_fail);
                   return 1;
                }
                if(how == "light" && c_mod > 4) {
                   if(tps < 4) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps >3) {
                        write(init_chant);
                        write(ucure);
			tell_object(target,p_cure);
                        tell_object(target,g_msg);
                        this_player()->add_sp(-4);
                        target->add_hps(2+random(8));
                        return 1;
                   }
                }
                if(how == "medium" && c_mod < 10) {
                   write(train_fail);
                   return 1;
                }
                if(how == "medium" && c_mod > 9) {
                   if(tps < 16) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 15) {
                        write(init_chant);
                        write(ucure);
			tell_object(target,p_cure);
                        tell_object(target,g_msg);
                        this_player()->add_sp(-15);
                        target->add_hp(12+random(8));
                        return 1;
                   }
                }
                if(how == "serious" && c_mod < 15) {
                   write(train_fail);
                   return 1;
                }
		if(how == "serious" && c_mod > 14) {
                   if(tps < 28) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 27) {
                        write(init_chant);
                        write(ucure);
			tell_object(target,p_cure);
                        tell_object(target,g_msg);
                        this_player()->add_sp(-50-random(c_mod));
                        targer->add_hp(20+random(c_mod));
                        return 1;
                   }
                }
                if(how == "critical" && c_mod < 20) {
                   write(train_fail);
                   return 1;
                }
                if(how == "critical" && c_mod > 19) {
                   if(tps < 40) {
                        write(spirit_fail);
                        return 1;
                   }
                   if(tps > 39) {
                        write(init_chant);
                        write(cure);
			tell_object(target,p_cure);
                        tell_object(target,g_msg);
                        this_player()->add_sp(-70-random(c_mod));
                        target->add_hp(30+2*random(c_mod));
                        return 1;
                   }
                }
	}
	else 
	   write("You can only cure light, medium, serious and critical.\n");
	   return 1;
	}
write("Oh crap.. tell Pain you got message mcure1.0\n");
return 1;
}


