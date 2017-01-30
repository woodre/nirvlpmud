/*Emohawk*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg){ 
   if(arg) return;
     ::reset(arg);
	change_shape();
set_name("emohawk");
set_alias("polymorph");
set_short("A small hunting emohawk");
set_race("gelf");
set_long("This is a genetically engineered killing machine. Built for war  \n"+
         "these beast were to be tough, mobil, and efficient. This small    \n"+
	 "version is created by other gelfs capturing a polymorph spaying   \n"+
	 "and partially domesticating it. Like its larger cousins it feeds  \n"+
	 "on emotions which have become a valuable commodity in deep space. \n"+
	 "They are mostly keep as pets, much like falcons were to medeival  \n"+
	 "earth royalty. Despite its small size, its shapechanging ability  \n"+
         "and psionic ability make it a dangerous hunter. Beware.           \n");
set_level(15);
set_ac(13);
set_wc(21);
set_hp(random(100)+220);
set_al(-1000); 			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chance(10);
set_spell_dam(20);
set_spell_mess1("The Emohawk changes into a grenade and explodes >>>BOOM<<<. \n");    /*others*/
set_spell_mess2("The Emohawk changes into a grenade and explodes...\n"+
	        "   \n"+
                "                 >>>BOOM!<<<   \n");    /*attacker*/
}

heart_beat(){
 ::heart_beat();
	if(!random(5) && attacker_ob) big_special();
   if(!random(20)) change_shape();  
            }

change_shape() {
    switch(random(10)) {
	case 9:
	   set_short("a bouncing rubber ball");
	   set_long("This looks like a normal beach ball caught in the air flow\n");
	   set_alt_name("ball");
	   break;
		
	case 8:
	   set_short("a remote controlled race car");
	   set_long("This is a sharp looking RC car rolling around the room.\n"+
	            "You don't see anyone around operating it though. Thats \n"+
		    "kind of odd. Ah well, this ship is full of odd.\n");
	   set_alt_name("car");
	   break;
		
	case 7:
	   set_short("a paper airplane gliding by");
	   set_long("A piece of typing paper folded into a nice paper airplane. \n"+
		    "Its in the traditional triangular jet. Its getting nice \n"+
		    "distance right now. Who threw it? \n");
	   set_alt_name("airplane");
	   break;
		
	case 6:
	   set_short("a slinky rolling down the stairs");
	   set_long("A standard metal slinky. You know the toy that is made of \n"+
		    "a long metal coil that can 'walk' down stairs when tipped.\n"+
		    "Doesn't look to threatening.\n");
	   set_alt_name("slinky");
	   break;
		
	case 5:
	   set_short("a pair of boxer shorts");
	   set_long("A pair of pokka dotted boxer shorts. These have the rough look\n"+
	            "of something that escaped from Lister's locker. Probably \n"+
		    "shouldn't touch them without a hazardous materials suit.\n");
	   set_alt_name("shorts");
	   break;
		
	case 4: 
           set_short("a spicey kabob on a lettuce leaf");
	   set_long("A spicey kabob the way Lister likes them. Perhaps a bit too \n"+
	 	    "spicey. You almost could swear you saw it twitch. Thats gross\n");
	   set_alt_name("kabob");
	   break;
		
	case 3:
	   set_short("a cute little bunny");
	   set_long("A long earred bunny rabbit. Sits twitching its nose and \n"+
		    "looking all nervous at the big people clomping around.\n"+
		    "It seems to be the cutest thing you've seen on this ship.\n");
	   set_alt_name("bunny");
	   break;

	case 2:
	   set_short("a tin of baked beans");
	   set_long("This is a can of baked beans that someone opened \n"+
		    "and forgot about. Better becareful that lid looks  \n"+
		    "a little sharp. Something is kinda odd about it too.\n");
	   set_alt_name("tin");
           set_alias("beans");
	   break;

	case 1:
  	   set_short("Lister's crusty deerstalker with dreds.");
	   set_long("This is Lister's favorite hat. He goes almost nowhere \n"+
                    "without it. After Rimmer took control of his body\n"+
                     "and made him cut off his dreds, he attached them to\n"+
                     "to the cap. It also has some pins and patches from \n"+
                     "places Lister has seen. It could use a good scrub.\n");
	   set_alt_name("dreds");
           set_alias("deerstalker");
	   break;

	case 0:
	   set_short("a thermos");
	   set_long("This is Dwayne Dibbly's thermos. He always makes sure\n"+
                    "to carry this, his lunchbox and a triple thick condom.\n"+
                    "Cause you never know.   \n");
	   set_alt_name("thermos");
	   break;
	}
	if(environment())
	tell_room(environment(),"Emohawk changes into "+alt_name+".\n");
}


big_special() {
	if(environment())
	tell_room(environment(),
       "The Emohawk rears up in its true form. It's double jaws \n"+
	   "          open revealing a probiscus which slimily attaches to \n"+
	   "               your forehead with a wet slap!\n");
	
	switch(random(5))  {
		
		case 4:
		tell_room(environment(),"The Emohawk slurps noisily on "+attacker_ob->query_name()+"'s "+RED+"ANGER"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(20,"other|mental");
		break;
		
		case 3:
		tell_room(environment(),"The Emohawk slurps noisily on "+attacker_ob->query_name()+"'s "+CYN+"COOL"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(20,"other|mental");
		break;
		
		case 2:
		tell_room(environment(),"The Emohawk slurps noisily on "+attacker_ob->query_name()+"'s "+BLU+"GUILT"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(20,"other|mental");
		break;
		
		case 1:
		tell_room(environment(),"The Emohawk slurps noisily on "+attacker_ob->query_name()+"'s "+YEL+"FEAR"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(20,"other|mental");
		break;
		
		case 0:
		tell_room(environment(),"The Emohawk slurps noisily on "+attacker_ob->query_name()+"'s "+MAG+"LUST"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(20,"other|mental");
		break;
		
	}
}
