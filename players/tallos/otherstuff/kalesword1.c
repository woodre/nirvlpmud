#include "/players/tallos/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("Kaleidoscopic Sword");
    set_alias("sword");
set_name("A Kaleidoscopic Sword");
    set_short("A "+HIR+"K"+HIY+"a"+HIG+"l"+HIB+"e"+HIM+"i"+HIR+"d"+HIY+"o"+HIG+"s"+HIB+"c"+HIM+"o"+HIR+"p"+HIY+"i"+HIG+"c"+NORM+""+HIC+" Sword"+NORM+"");
    set_long("Behold the "+HIR+"K "+HIY+"A "+HIG+"L "+HIB+"E "+HIM+"I "+NORM+""+NORM+"D "+HIR+"O "+HIY+"S "+HIG+"C "+HIB+"O "+HIM+"P "+NORM+""+NORM+"I "+HIR+"C  "+HIY+"S "+HIG+"W "+HIB+"O "+HIM+"R"+HIR+" D "+NORM+"!\n"+ 
    " \n"+
    "This beautifully crafted "+HIR+"s"+HIY+"w"+HIG+"o"+HIB+"r"+HIM+"d "+NORM+"has a multitude of "+HIR+"c"+HIY+"o"+HIG+"l"+HIB+"o"+HIM+"r"+HIR+"s"+NORM+""+HIW+" shining"+NORM+" along\n"+
    "the "+HIC+"blade"+NORM+".  As you move the sword in the light you see it shift before\n"+
    "you displaying all the wonderful "+HIR+"c"+HIY+"o"+HIG+"l"+HIB+"o"+HIM+"r"+HIR+"s"+NORM+" of the "+HIR+"r"+HIR+"a"+HIY+"i"+HIG+"n"+HIB+"b"+HIM+"o"+HIR+"w"+NORM+". It vibrates in\n"+
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
write(HIB+				"@\n"+
         				"@@@@\n"+
         				"@@@@@@@\n"+
        				"@@@@@@@@@@\n"+
     					"@@@@@@@\n"+
         				"@@@@\n"+
         				"@"+NORM+"\n");

say(HIB+				"@\n"+
         				"@@@@\n"+
         				"@@@@@@@\n"+
        				"@@@@@@@@@@\n"+
     					"@@@@@@@\n"+
         				"@@@@\n"+
         				"@"+NORM+"\n");
}
if(kal==1){
write(HIW+		  "@@@@@@@@@@@@@\n"+
         			   "@@@@@@@@@@@\n"+
         				"@@@@@@@@@\n"+
         				 "@@@@@@@\n"+
     					  "@@@@@\n"+
         				   "@@@\n"+
         					"@"+NORM+"\n");
say(HIW+			  "@@@@@@@@@@@@@\n"+
         			   "@@@@@@@@@@@\n"+
         				"@@@@@@@@@\n"+
         				 "@@@@@@@\n"+
     					  "@@@@@\n"+
         				   "@@@\n"+
         					"@"+NORM+"\n");
}
if(kal==2){
write(HIY+					 "@\n"+
         					  "@@@@\n"+
         				   "@@@@@@@\n"+
         				"@@@@@@@@@@\n"+
     					   "@@@@@@@\n"+
         		      		  "@@@@\n"+
         						 "@"+NORM+"\n");
say(HIY+						 "@\n"+
         					  "@@@@\n"+
         				   "@@@@@@@\n"+
         				"@@@@@@@@@@\n"+
     					   "@@@@@@@\n"+
         		      		  "@@@@\n"+
         						 "@"+NORM+"\n");
}
if(kal==3){
write(HIG+				"@\n"+
         		           "@@@\n"+
         		          "@@@@@\n"+
         		         "@@@@@@@\n"+
     	 		        "@@@@@@@@@\n"+
         		       "@@@@@@@@@@@\n"+
         		      "@@@@@@@@@@@@@"+NORM+"\n");
say(HIG+					"@\n"+
         		           "@@@\n"+
         		          "@@@@@\n"+
         		         "@@@@@@@\n"+
     	 		        "@@@@@@@@@\n"+
         		       "@@@@@@@@@@@\n"+
         		      "@@@@@@@@@@@@@"+NORM+"\n");
}

return 6;
}