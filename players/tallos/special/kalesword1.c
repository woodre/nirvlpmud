#include "/players/tallos/ansi.h"
inherit "players/vertebraker/closed/std/weapon.c";
#define tp this_player()->query_name()

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
    "your hand showing it's "+HIR+"AWESOME"+NORM+" power. You are somehow "+HIM+"mesmerized"+NORM+" by it.\n"+
    " \n"+
    ""+HIC+"           ###  \n"+
    ""+HIC+"=="+HIC+"         ###  "+HIR+"@@@@@@"+HIY+"@@@@@@"+HIG+"@@@@@@"+HIB+"@@@@@@"+HIM+"@@@@@@"+HIW+"@@@@@@"+HIR+"@@@@@@"+HIY+"@@@@@@@@@@@@\\  \n"+
    ""+HIC+"||"+HIR+"/\\"+HIY+"/\\"+HIG+"/\\"+HIB+"/\\"+HIM+"/"+HIC+"###"+HIG+"@@@@@@"+HIB+"@@@@@@"+HIM+"@@@@@@@"+HIW+"@@@@@@"+HIR+"@@@@@@"+HIY+"@@@@@@"+HIG+"@@@@@@"+HIB+"@@@@@@"+HIM+"@@@@@@@@\\ \n"+
    ""+HIC+"||"+HIR+"\\/"+HIY+"\\/"+HIG+"\\/"+HIB+"\\/"+HIM+"\\"+HIC+"###"+HIW+"@@@@@@"+HIR+"@@@@@@"+HIY+"@@@@@@"+HIG+"@@@@@@"+HIB+"@@@@@@"+HIM+"@@@@@@"+HIW+"@@@@@@"+HIR+"@@@@@@"+HIY+"@@@@@@@@@/ \n"+
    ""+HIC+"=="+HIC+"         ###"+HIG+"  @@@@@@"+HIB+"@@@@@@"+HIM+"@@@@@@"+HIW+"@@@@@@"+HIR+"@@@@@@"+HIY+"@@@@@@"+HIG+"@@@@@@"+HIB+"@@@@@@@@@@@@/  \n"+
    ""+HIC+"           ###  \n"+
    " "+NORM+"                \n");
set_class(21);
set_two_handed(1);
    set_weight(5);
    set_type("sword");
    set_value(100000);
    
    set_hit_func(this_object());
    set_params("other|sonic",0,"kale_hit");   
}

weapon_hit(attacker){
int kal;
kal = random(6);
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
if(kal==4){
write(HIM+				   "@@@@@@@\n"+
         		           "@@@@@@@\n"+
         		           "@@@@@@@\n"+
     	 		           "@@@@@@@\n"+
         		           "@@@@@@@\n"+
         		           "@@@@@@@"+NORM+"\n");
say(HIM+				   "@@@@@@@\n"+
         		           "@@@@@@@\n"+
         		           "@@@@@@@\n"+
     	 		           "@@@@@@@\n"+
         		           "@@@@@@@\n"+
         		           "@@@@@@@"+NORM+"\n");
}
if(kal==5){
write(HIC+				 "    @\n"+
         		         "   @@@\n"+
         		         "  @@@@@\n"+
     	 		         "  @@@@@\n"+
         		         "   @@@\n"+
         		         "    @      "+NORM+"\n");
say(HIC+			     "    @\n"+
         		         "   @@@\n"+
         		         "  @@@@@\n"+
     	 		         "  @@@@@\n"+
         		         "   @@@\n"+
         		         "    @      "+NORM+"\n");
}
if(kal==6){
write(HIG+			   "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@\n"+
     	 		       "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@"+NORM+"\n");
say(HIG+			   "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@\n"+
     	 		       "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@\n"+
         		       "@@@@@@@@@@@@"+NORM+"\n");
}
return random(6);
}
int kale_hit(object attacker){
 if(this_player())
if(call_other(this_player(),"query_attrib","wil") > random(80))
  {
  int a;
  a=random(10);
  if(a >= 8) {
    write(" In a blaze of kaledoscopic light the sword glows with intense color and...\n"+
          "                      \n"+
          ""+HIR+" @@@@@@@@@@@@@@"+HIY+"          @    "+HIG+"       @     "+HIB+"   @@"+HIM+"      @@@@@@@@"+HIR+"  @@@@@@"+NORM+"                     \n"+
          ""+HIR+" @@@@@@@@@@@@@@"+HIY+"        @@@@@  "+HIG+"      @@@    "+HIB+"   @@@@"+HIM+"    @@@@@@@"+HIY+"   @@@@@@"+NORM+"                           \n"+
          ""+HIR+" @@@@@@@@@@@@@@"+HIY+"       @@@@@@@ "+HIG+"     @@@@@   "+HIB+"   @@@@@"+HIM+"   @@@@@@"+HIG+"    @@@@@@"+NORM+"                     \n"+
          ""+HIR+" @@@@@@@@@@@@@@"+HIY+"      @@@@@@@@@"+HIG+"    @@@@@@@  "+HIB+"   @@@@@@"+HIM+"  @@@@@"+HIB+"     @@@@@@"+NORM+"                     \n"+
          ""+HIR+" @@@@@@@@@@@@@@"+HIY+"       @@@@@@@ "+HIG+"   @@@@@@@@@ "+HIB+"   @@@@@"+HIM+"   @@@@"+HIM+"      @@@@@@"+NORM+"                     \n"+
          ""+HIR+" @@@@@@@@@@@@@@"+HIY+"        @@@@@  "+HIG+"  @@@@@@@@@@@"+HIB+"   @@@@"+HIM+"    @@@"+HIC+"       @@@@@@"+NORM+"                     \n"+
          ""+HIR+" @@@@@@@@@@@@@@"+HIY+"          @    "+HIG+" @@@@@@@@@@@@@"+HIB+"   @@"+HIM+"      @"+HIW+"        @@@@@@"+NORM+" \n"+
          " \n"+
          "                 Shoots out a:  R A I N B O W!!!!!!!!                     \n");
    say("                        \n"+
        ""+tp+"'s sword glows brighly as it produces and incredible R A I N B O W  OF  C O L O R!!!!\n"+
        "                        \n");    
    return (15 + random (50)); 
  }
  return 0;
} 
}