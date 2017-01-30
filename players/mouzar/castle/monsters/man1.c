 
inherit"/obj/monster";
 
reset(arg) {
::reset(arg);
if(!arg) 
 
            set_name("man");
	   set_long("He looks like he has seen man horrors in his life.\n");
            set_level(13);
            set_hp(135);
            set_wc(13);
            set_ac(7);
	    set_aggressive(1);
	set_chat_chance(20);
	load_chat("Man screams:  Why have you killed my pet!\n");
            }
         
 
