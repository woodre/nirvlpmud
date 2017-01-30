#include "/players/tallos/ansi.h"
inherit "/obj/weapon";

string RANCOL;
	switch(random(7)) {
   		case 0: RANCOL == ""+NORM+"";
   		break;
   		case 1: RANCOL == ""+HIM+"";
   		break;
   		case 2: RANCOL == ""+HIY+"";
   		break;
   		case 3: RANCOL == ""+HIR+"";
   		break;
   		case 4: RANCOL == ""+HIB+"";
   		break;
   		case 5: RANCOL == ""+HIC+"";
   		break;
   		case 6: RANCOL == ""+HIG+"";
   		break;
					}
reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("Kaleidoscopic Sword");
    set_alias("sword");
set_name("A Kaleidoscopic Sword");
    set_short("A "+HIR+"K"+HIY+"a"+HIG+"l"+HIB+"e"+HIM+"i"+HIR+"d"+HIY+"o"+HIG+"s"+HIB+"c"+HIM+"o"+HIR+"p"+HIY+"i"+HIG+"c"+NORM+""+HIC+" Sword"+NORM+"");
    set_long("Behold the "+HIR+"K "+HIY+"A "+HIG+"L "+HIB+"E "+HIM+"I "+NORM+""+NORM+"D "+HIR+"O "+HIY+"S "+HIG+"C "+HIB+"O "+HIM+"P "+NORM+""+NORM+"I "+HIR+"C  "+HIY+"S "+HIG+"W "+HIB+"O "+HIM+"R"+HIR+" D "+NORM+"!\n"+ 
    " \n"+
    "This beautifully crafted "+HIR+"s"+HIY+"w"+HIG+"o"+HIB+"r"+HIM+"d "+NORM+"has a multitude of "+HIR+"c"+HIY+"o"+HIG+"l"+HIB+"o"+HIM+"r"+HIR+"s"+NORM+"\n"+
    ""+HIW+"shining"+NORM+" along the "+HIC+"blade"+NORM+". As you move the sword in the light you see it \n"+
    "shift before you displaying all the wonderful "+HIR+"c"+HIY+"o"+HIG+"l"+HIB+"o"+HIM+"r"+HIR+"s"+NORM+" of the "+HIR+"r"+HIR+"a"+HIY+"i"+HIG+"n"+HIB+"b"+HIM+"o"+HIR+"w"+NORM+". It vibrates in\n"+
    "your hand showing it's "+HIR+"AWESOME"+NORM+" power. You are somehow "+HIM+"mesmerized"+NORM+" by it.\n");
set_class(19);
    set_weight(4);
    set_type("sword");
    set_value(0);
    set_hit_func(this_object());
}

weapon_hit(attacker){
int kal;
kal = random(4);
if(kal==0){
write(RANCOL+			"@\n"+
         				"@@@@\n"+
         				"@@@@@@@\n"+
        				"@@@@@@@@@@\n"+
     					"@@@@@@@\n"+
         				"@@@@\n"+
         				"@"+NORM+"\n");

say(RANCOL+				"@\n"+
         				"@@@@\n"+
         				"@@@@@@@\n"+
        				"@@@@@@@@@@\n"+
     					"@@@@@@@\n"+
         				"@@@@\n"+
         				"@"+NORM+"\n");
}
if(kal==1){
write(RANCOL+		  "@@@@@@@@@@@@@\n"+
         			   "@@@@@@@@@@@\n"+
         				"@@@@@@@@@\n"+
         				 "@@@@@@@\n"+
     					  "@@@@@\n"+
         				   "@@@\n"+
         					"@"+NORM+"\n");
say(RANCOL+			  "@@@@@@@@@@@@@\n"+
         			   "@@@@@@@@@@@\n"+
         				"@@@@@@@@@\n"+
         				 "@@@@@@@\n"+
     					  "@@@@@\n"+
         				   "@@@\n"+
         					"@"+NORM+"\n");
}
if(kal==2){
write(RANCOL+					 "@\n"+
         					  "@@@@\n"+
         				   "@@@@@@@\n"+
         				"@@@@@@@@@@\n"+
     					   "@@@@@@@\n"+
         		      		  "@@@@\n"+
         						 "@"+NORM+"\n");
say(RANCOL+						 "@\n"+
         					  "@@@@\n"+
         				   "@@@@@@@\n"+
         				"@@@@@@@@@@\n"+
     					   "@@@@@@@\n"+
         		      		  "@@@@\n"+
         						 "@"+NORM+"\n");
}
if(kal==3){
write(RANCOL+				"@\n"+
         		           "@@@\n"+
         		          "@@@@@\n"+
         		         "@@@@@@@\n"+
     	 		        "@@@@@@@@@\n"+
         		       "@@@@@@@@@@@\n"+
         		      "@@@@@@@@@@@@@"+NORM+"\n");
say(RANCOL+					"@\n"+
         		           "@@@\n"+
         		          "@@@@@\n"+
         		         "@@@@@@@\n"+
     	 		        "@@@@@@@@@\n"+
         		       "@@@@@@@@@@@\n"+
         		      "@@@@@@@@@@@@@"+NORM+"\n");
}
string RANCOL;
switch(random(7)) {
   case 0: RANCOL == ""+NORM+"";
   break;
   case 1: RANCOL == ""+HIM+"";
   break;
   case 2: RANCOL == ""+HIY+"";
   break;
   case 3: RANCOL == ""+HIR+"";
   break;
   case 4: RANCOL == ""+HIB+"";
   break;
   case 5: RANCOL == ""+HIC+"";
   break;
   case 6: RANCOL == ""+HIG+"";
   break;
}
return 8;
}