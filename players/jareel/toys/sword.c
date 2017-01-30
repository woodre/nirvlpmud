#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"
	inherit "/obj/weapon.c";
	
	int light;
	int bladesharp;
	int energize;
	int moonglow;
	int MAGIC;
	
	reset(arg){
		::reset(arg);
		if(arg) return 1;
		
		set_alt_name("sword");
		get_short();
		set_class(18);
		set_type("sword");
		set_weight(2);
		set_value(1200);
		set_long(
			"This finely crafted iron sword bares the markings of a dwarven\n"+
			"master.  Its dull gray sheen absorbs the surrounding light, with\n"+
	    	"light only gleaming of the weapons edge.\n");
		
		set_read("\n"+
			"   "+BOLD+BLU+"lightning"+NORM+"           10sp\n"+
			""+BOLD+MAG+"bladesharp"+NORM+"         50sp\n"+
	    	"\n");
		
		
		set_hit_func(this_object());
	}
	
	weapon_hit(attacker){
		int i;
		if(energize != 1){
			return 0;
		}
		
		i = random(14);
		if(i<5){
			tell_room(environment(this_player()),
				"\n\n"+
			CYN+BLINK+" E N E R G Y"+NORM+" flows over the blade.\n\n");
			return 2;
		}
		
	}
	init(){
		::init();
		add_action("LIGHTNING","lightning");
		add_action("bladesharp","bladesharp");
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
	
	bladesharp(){
		int time;
		MAGIC = check_magic();
		if(check_wielded() == 0) return 0;
		if(this_player()->query_spell_point() < 50){
			notify_fail(BOLD+"You lack the energy to charge the sword.\n"+NORM);
			return 0;
		}
		
		this_player()->add_spell_point(-50);
		energize = 1;
		get_short();
		time = ((500+random(500))*MAGIC)/20;
		call_out("remove_energy",time);
		write("\nYou invoke the bladesharp matrix.\n\n"+
		"        "+CYN+BLINK+"E N E R G Y "+NORM+"flows over your blade.\n\n");
		return 1;
	}
	
	remove_energy(){
		write("The sword's glow fades.\n");
		say("The glow from the sword fades.\n");
		energize = 0;
		get_short();
		return 1;
	}
	
	
	LIGHTNING(){
		int time;
		MAGIC = check_magic();
		if(check_wielded() == 0) return 0;
		if(this_player()->query_sp() < 10){
			notify_fail("You lack energy to use this power.\n");
			return 0;
		}
		
		this_player()->add_spell_point(-10);
		write("Lightning flows over the bastard sword\n");
		say("Lightning leaps over the blade.\n");
		time = (1200*MAGIC)/20;
		call_out("light_stop",time);
		light = 1;
		get_short();
		return 1;
	}
	
	light_stop(){
		write("The "+BOLD+BLU+BLINK+"Lightning"+NORM+" dissipates from the blade.\n");
		say("The "+BOLD+BLU+BLINK+"Lightning"+NORM+" disapates of the blade.\n");
		light = 0;
		get_short();
	}
	
	get_short(){
		string str;
		str = ""+HIK+"Bastard Sword"+NORM+"";
		
		if(light == 1){
			str += ""+NORM+BOLD+"  ("+BOLD+BLU+" Lightning Charged "+NORM+BOLD+")"+NORM+"";
		}
		
		if(energize == 1){
			str += ""+RED+" [ "+CYN+" Energized "+RED+" ]"+NORM+"";
			
		}
		set_short(str);
	}

