/*  10/08/06 - Rumplemintz
      Moved inherit above #include statement
      Changed broke to broken to not conflict with inherited object
*/

inherit "/players/jaraxle/closed/weapon/weapon2.c";
#include "/players/jaraxle/define.h"
int broken, wear;

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_name("krakin");
    set_alias("dualaxe");
    set_short("Kra"+HIR+"K"+NORM+"in, the DualAxe");
    set_long("Kra"+HIR+"K"+NORM+"in is the mighty DualAxe of the Firethrower.\n"+
      "It has a long, quartz shaft.  On each end of the\n"+
      "shaft a massive double-edged blade is fastened by\n"+
      "hardened lava rock.  The blades are extremely sharp\n"+
      "and give off a red, hazy glow and seem to hum\n"+
      "softly from the edge.\n");   
    set_type("axe");  /*  sword/knife/club/axe/bow/polearm  */
    set_class(20);
    set_two_handed_wep(1);
    set_weight(4);
    set_no_break(1);
    set_value(30000);
    set_hit_func(this_object());
}

/*
short(){
  if(query_wear() >= 300){ return "Kra"+HIR+"K"+NORM+"in, the DualAxe "+HIW+"["+BLK+"BROKEN"+HIW+"]"+NORM+""+(wielded?" "+HIR+"("+NORM+"dual"+HIR+"-"+NORM+"wielded"+HIR+")"+NORM+"":""); 
broken = 1; }
   return "Kra"+HIR+"K"+NORM+"in, the DualAxe"+(wielded?" "+HIR+"("+NORM+"dual"+HIR+"-"+NORM+"wielded"+HIR+")"+NORM+"":""); }

query_broke(){ return broke; }
*/
/*
query_save_flag(){ return 1; }
made storable 2005.05.22 Forbin */


weapon_hit(attacker){
    int WEP_MSG, BODY_PART, COLOR, A, B;
    A = (int)environment()->query_attrib("sta");
    B = (int)environment()->query_attrib("str");

    /* This is the switch for the different colors of the emote */
    switch(random(6)){
    case 0: COLOR = HIR; break; 
    case 1: COLOR = HIC; break; 
    case 2: COLOR = HIB; break;
    case 3: COLOR = HIM; break;
    case 4: COLOR = HIG; break; 
    case 5: COLOR = HIY; break;
    }

    /* This is the switch for the different emote on the attack */
    switch(random(7)){
    case 0: WEP_MSG = "smashing"; break; 
    case 1: WEP_MSG = "obliterating"; break; 
    case 2: WEP_MSG = "slicing"; break;
    case 3: WEP_MSG = "gouging"; break; 
    case 4: WEP_MSG = "hacking"; break; 
    case 5: WEP_MSG = "tearing into"; break;
    case 6: WEP_MSG = "slaughtering"; break; 
    }

    /* This is the switch for the different body part hit on the attack */
    switch(random(7)){
    case 0: BODY_PART = "chest"; break; 
    case 1: BODY_PART = "leg"; break;
    case 2: BODY_PART = "arm"; break; 
    case 3: BODY_PART = "neck"; break; 
    case 4: BODY_PART = "ribs"; break; 
    case 5: BODY_PART = "chest"; break; 
    case 6: BODY_PART = "stomach"; break;
    }

    /* This is the switch for the different emotes, special attacks */
    switch(random(21)){

    case 0..7:
	if(A+B > 39){
	    write("You spin around madly "+COLOR+""+WEP_MSG+""+NORM+" "+attacker->query_name()+"'s "+BODY_PART+"!\n");
	    say(TPN+" spins around madly "+COLOR+""+WEP_MSG+""+NORM+" "+attacker->query_name()+"'s "+BODY_PART+"!\n");
	    return(1+random(5));
	}
	return 0;
	break;

    case 8..12: return 0; break;

    case 13:
	write("You slide sideways and swing Kra"+HIR+"K"+NORM+"in in a mighty upwards arch...\n\n"+
	  "\t"+HIW+"                 .\n"+
	  "\t       .          "+HIR+"::\n"+
	  "\t     ::          :"+HIY+":"+HIR+":\n"+
	  "\t    :"+HIY+":"+HIR+":        ::"+HIY+":"+HIR+"::\n"+
	  "\t  .:"+HIY+":::"+HIR+"::. .::"+HIY+"::::"+HIR+"::\n"+
	  "\t :::"+HIY+":::::::::::"+HIR+":::.' \n"+
	  "\t ':::"+HIY+"::::::::"+HIR+"::::'\n"+
	  "\t  "+HIY+"~"+HIR+"F  L  A  M  E"+HIY+"~\n"+
	  "\n"+NORM+"Billows from the edge of Kra"+HIR+"K"+NORM+"in's blade!\n");
	say(TPN+" slides sideways and swings Kra"+HIR+"K"+NORM+"in in a mighty upwards arch...\n\n"+
	  "\t"+HIW+"                 .\n"+
	  "\t       .          "+HIR+"::\n"+
	  "\t     ::          :"+HIY+":"+HIR+":\n");
	say("\t    :"+HIY+":"+HIR+":        ::"+HIY+":"+HIR+"::\n"+
	  "\t  .:"+HIY+":::"+HIR+"::. .::"+HIY+"::::"+HIR+"::\n"+
	  "\t :::"+HIY+":::::::::::"+HIR+":::.' \n");
	say("\t ':::"+HIY+"::::::::"+HIR+"::::'"+HIY+"\n"+
	  "\t  "+HIY+"~"+HIR+"F  L  A  M  E"+HIY+"~\n"+
	  "\n"+NORM+"Billows from the edge of "+TPN+"'s Kra"+HIR+"K"+NORM+"in!\n\n");
	return(3+random(5));
	break;

    case 14:

	write("You slide sideways and swing Kra"+HIR+"K"+NORM+"in in a mighty upwards arch...\n\n"+
	  "\t"+HIR+"                 .           .      .  \n"+
	  "\t       .          ::       ::        :.     \n"+
	  "\t     ::          :::       ::::     :::.    \n");
	write("\t    :::        :::::        ':::   ::::::   \n"+
	  "\t  .::::::. .::::::::       ::::::: ::::'    \n"+
	  "\t :::::::::::::::::.'    .:::::::::::::      \n");
	write("\t '::::::::::::::::::'..'::::::::::::::'     \n"+
	  "\t   ::::::::::::::::::::::::::::::::.'       \n"+
	  "\t  "+HIY+"~"+HIR+" F  L  A  M  E  S  T  R  I  K  E "+HIY+"~"+NORM+"       \n"+
	  "\n"+NORM+"Erupts from the edge of Kra"+HIR+"K"+NORM+"in's blade!\n");

	say(TPN+" slides sideways and swings Kra"+HIR+"K"+NORM+"in in a mighty upwards arch...\n\n"+
	  "\t"+HIR+"                 .           .      .  \n"+
	  "\t       .          ::       ::        :.     \n"+
	  "\t     ::          :::       ::::     :::.    \n");
	say("\t    :::        :::::        ':::   ::::::   \n"+
	  "\t  .::::::. .::::::::       ::::::: ::::'    \n"+
	  "\t :::::::::::::::::.'    .:::::::::::::      \n");
	say("\t '::::::::::::::::::'..'::::::::::::::'     \n"+
	  "\t   ::::::::::::::::::::::::::::::::.'       \n"+
	  "\t  "+HIY+"~"+HIR+" F  L  A  M  E  S  T  R  I  K  E "+HIY+"~"+NORM+"       \n"+
	  "\n"+NORM+"Erupts from the edge of "+TPN+"'s Kra"+HIR+"K"+NORM+"in!\n\n");
	return(7+random(4));
	break;
    case 15..20: return 2; break;
    }
}
