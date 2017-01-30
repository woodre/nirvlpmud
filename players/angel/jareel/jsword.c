#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"
	inherit "/obj/weapon.c";
	
	int wind;
	int bladesharp;
	int energize;
	int moonglow;
	int MAGIC;
	
	reset(arg){
	  ::reset(arg);
	    if(arg) return 1;
		
	set_alt_name("sword");
	get_short();
	set_class(16);
	set_type("sword");
	set_weight(2);
	set_value(1200);
	set_long(
	  "This finely crafted iron sword bares the markings of a dwarven\n"+
	  "master.  Its dull gray sheen absorbs the surrounding light, with\n"+
	  "light only gleaming off the weapons edge.\n");
	set_read("\n"+
	  "   "+BOLD+BLU+"wind"+NORM+"           25sp\n"+
	  ""+BOLD+MAG+"bladesharp"+NORM+"         25sp\n"+
	    	"\n");
		
		
	set_hit_func(this_object());
	}
	
	weapon_hit(attacker){
	  int i;
          int l;
	    if(energize != 1){
	      return 0;	}
	    i = random(24);
	      if(i<5){
	        tell_room(environment(this_player()),
                  HIC+BLINK+"E   N   E   R   G   Y"+NORM+" flows from "+NORM+environment()->query_name()+"'s blade.\n");
	        return 5;
	       }
            if(wind != 1){
	      return 0;	}
	    l = random(9);
	      if(l<5){
	        tell_room(environment(this_player()),
	          ""+HIC+"W I N D"+NORM+" slashes off of "+NORM+environment()->query_name()+"'s blade...\n");
	        attacker->hit_player(5+random(3), "other|Jareel");
	       }
            
		
	}
	init(){
	  ::init();
	    add_action("WIND","wind");
	    add_action("BLADESHARP","bladesharp");
	}
	
	check_wielded(){
	  if(this_player()->query_weapon() == this_object()){
	    return 1;
	}
	  else {
	    notify_fail(BOLD+"You must be wielding the sword to use its powers.\n"+NORM);
	      return 0;
	}}
	
	check_magic(){
	  int i;
	    i = this_player()->query_attrib("int");
	      if(i > 20) i = 20;
		if(i < 0) i = 0;
		  return i;
	}
	
	BLADESHARP(){
	  int time;
	    MAGIC = check_magic();
	      if(check_wielded() == 0) return 0;
		if(this_player()->query_spell_point() < 25){
		  notify_fail(BOLD+"You lack the energy to charge the sword.\n"+NORM);
		    return 0;
		}
		
	   this_player()->add_spell_point(-25);
	     energize = 1;
	       get_short();
                 this_object()->set_class(20);
		   time = ((1000+random(500))*MAGIC)/20;
		     call_out("remove_energy",time);
	               write("\nYou invoke the bladesharp matrix.\n\n"+
		         "   "+HIC+BLINK+"E N E R G Y "+NORM+"flows over your blade.\n\n");
                           return 1;
	}
	
	remove_energy(){
	  write("The sword's glow fades.\n");
	    say("The glow from the sword fades.\n");
	      energize = 0;
                this_object()->set_class(16);
	          get_short();
		    return 1;
	}
	
	
	WIND(){
	  int time;
	    MAGIC = check_magic();
	      if(check_wielded() == 0) return 0;
		if(this_player()->query_sp() < 25){
		  notify_fail("You lack energy to use this power.\n");
			return 0;
		}
		
		this_player()->add_spell_point(-25);
		  write(HIC+"Swiriling Wind wraps over your blade\n"+NORM);
		    say(HIC+"Swirling Wind wraps around "+environment()->query_name()+"'s blade.\n"+NORM);
		      time = (1200*MAGIC)/20;
		        call_out("wind_stop",time);
	                  wind = 1;
                            get_short();
		                return 1;
	}
	
	wind_stop(){
	  write("The "+BOLD+BLU+BLINK+"W I N D"+NORM+" dissipates from the blade.\n");
	  say("The "+BOLD+BLU+BLINK+"W I N D"+NORM+" blows off of "+NORM+environment()->query_name()+"'s blade.\n");
	    wind = 0;
	      get_short();
	}
	
	get_short(){
	  string str;
	    str = ""+HIK+"Wind Sword"+NORM+"";
              if(wind == 1){
		str += ""+NORM+BOLD+"  ("+BOLD+BLU+" Swirling Wind "+NORM+BOLD+")"+NORM+"";
		}
	      if(energize == 1){
		str += ""+BOLD+" ["+NORM+RED+" Bladesharp "+NORM+BOLD+"]"+NORM+"";
		}
	      set_short(str);
	}

