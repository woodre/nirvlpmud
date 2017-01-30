inherit "obj/monster";

realm() { return "NT"; }

reset(arg) {
	::reset(arg);
	if (arg)
           return;
	set_name("smithers");
	set_alias("wayland");
	set_short("Wayland Smithers");
	set_long("Wayland Smithers, Mr. Burns assistant....\n");
	set_hp(350);
	set_wc(19+random(5));
	set_al(-500);
	set_ac(10);
	set_level(15);
	set_heart_beat(1);
}

#define THIS this_object()
#define A_MSG "Smithers skillfully avoids your attack.\n"
#define B_MSG "Smithers avoids the lame attacks\n"
#define C_MSG "Smithers releases his fearsome rage upon "
#define D_MSG "You are slaughtered by smithers' fearsome rage\n"
#define H_MSG "Smithers heals the wounds you inflicted upon him\n"
#define S_MSG "Smithers' stealth causes you to start attacking Burns\n"

object atk, burns;
status wc_double;

heart_beat() {
	::heart_beat();
	if (atk=query_attack()) {
	   object ai;
	   int i,so;
	   ::attack();

	   ai = all_inventory(environment());
	   for (i=0,so=sizeof(ai);i<so;i++) {
	       if ((living(ai[i])) && (ai[i]->query_attack() == THIS)) {
		  tell_object(ai[i], A_MSG);
	          burns = present("burns", environment());
		  if (ai[i]->query_alt_attack() != burns) { 
                     stop_fight();
		     tell_object(ai[i], S_MSG);
		     heal_self(50);
		     tell_object(ai[i], H_MSG);
		  }		  	             
		  ai[i]->attack_object(burns);
	       }   
	       else
	          tell_object(ai[i], B_MSG);
           }
	}
	if (burns = present("burns", environment())) {
           if (atk = burns->query_attack()) {
              if (!wc_double) {
                 set_wc(40);
                 wc_double = 1;
	      }
	      if (query_attack() != atk) {
                 attack_object(atk);
		 say(C_MSG+atk->query_name()+"\n");
                 tell_object(atk, D_MSG);      
	      }	
           }
	}
}
