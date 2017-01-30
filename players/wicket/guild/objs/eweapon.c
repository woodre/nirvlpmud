#include <ansi.h>
inherit "/obj/weapon.c";

int dtype;									/* We'll use this for seeing what type of dtype we're gonna do */

reset(arg) {
	::reset(arg);
	
	if(arg) return;
	set_id("staff");
	set_alias("wicket_elementalist_staff");
	set_short("An "+RED+"Ancient "+NORM+"Staff of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" ("+HIY+"pulsating"+NORM+")");     /* Fix this if you'd like! */
	set_long(
	"A solid wooden staff that has been weathered and beaten. Down the\n"+							/* Fix this, obviously ;) */
	"long wooden shaft of the staff are tattered and well worn. A glowing\n"+
	"orb rests at the top of the staff between some piece of the staff\n"+
	"that seem to wrap around the orb holding onto the orbs life essence.\n"+
	"Ancient Symbols are carved down the side of the staff and hum with\n"+
	"amazing power.\n"+
	"                   "+RED+"        00000                                   \n"+
	"                          0     0                                  \n"+
	"                          0     0                                  \n"+
	"                          0     0                                  \n"+
	"                           00000                                   \n"+
	"                            Fire                                   \n"+
	"                                                                   \n"+
	"                   "+YEL+"        00000                                   \n"+
	"                          0     0                                  \n"+
	"                          0  0  0                                  \n"+
	"                          0     0                                  \n"+
	"                           00000                                   \n"+
	"                            Air                                    \n"+
	"                                                                   \n"+
	"                   "+GRN+"        00000                                   \n"+
	"                          0  |  0                                  \n"+
	"                          0--+--0                                  \n"+
	"                          0  |  0                                  \n"+
	"                           00000                                   \n"+
	"                           Earth                                   \n"+
	"                                                                   \n"+
	"                   "+CYN+"        00000                                   \n"+
	"                          0     0                                  \n"+
	"                          0-----0                                  \n"+
	"                          0     0                                  \n"+
	"                           00000                                   \n"+
	"                           Water"+NORM+"                                   \n");
	set_weight(2);
 set_class(10); 
	set_value(0);							/* Worthless since they can conjure it */
	set_type("staff");
	set_hit_func(this_object());
	message_hit = ({
		HIR+"A N N I H I L A T E S"+NORM, " causing bones to break and shatter",
		HIR+"A N N I H I L A T E S"+NORM, " through the torso",
		HIY+"crushes"+NORM, " in the ribcage",
		HIG+"busts"+NORM, " in the jaw",
		HIG+"bonks"+NORM, " on the head",
		HIC+"whacks"+NORM, " across the knuckles",
		HIC+"cracks"+NORM, " in the arm"
		
	});
}

drop()
{
	write("The "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" reclaim the staff of their ancestors!\n");
	destruct(this_object());
	return 1;
}
	

is_elementalist_weapon() { return 1; }

weapon_hit(attacker)
{
	object gob;
	int air, earth, fire, water;
	int rand;
	
	gob = present("wicket_element_orb", environment(this_object()));
	rand = random(4);
	
	air = (int)gob->query_AIR();
	earth = (int)gob->query_EARTH();
	fire = (int)gob->query_FIRE();
	water = (int)gob->query_WATER();
	
	if(rand == 0)
	{
		say(this_player()->query_name()+"'s weapon "+HIY+"flashes"+NORM+" as "+RED+"fire"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		  write("Your weapon "+HIY+"flashes"+NORM+" as "+RED+"fire"+NORM+" glides from the staff ripping through "+attacker->query_name()+"\n"+NORM+ 
RED+"                                                                 \n"+NORM+    
RED+"                     (     (    (                                \n"+NORM+ 
RED+"                     )\\ )  )\\ ) )\\ )                             \n"+NORM+    		
RED+"                    (()/( (()/((()/( (                           \n"+NORM+ 
RED+"                    /(_)) /(_))/(_)))\\                           \n"+NORM+   
RED+"                   (_))"+HIR+"_|"+NORM+RED+"("+HIR+"_"+NORM+RED+")) ("+HIR+"_"+NORM+RED+")) (("+HIR+"_"+NORM+RED+")                             \n"+NORM+ 
HIR+"                   | |_  |_ _|| _ \| ___|                         \n"+NORM+     
HIR+"                   | __|  | | |   /| _|                          \n"+NORM+     
HIR+"                   |_|   |___||_|_\\|____|                         \n"+NORM+                            
RED+"                     )\\ )  )\\ ) )\\ )                             \n"+NORM+                     
RED+"                    (()/( (()/((()/( (                           \n"+NORM+                         
RED+"                    /(_)) /(_))'/(_)))\\                          \n"+NORM+                            
RED+"                   ( )) |( )) ( )) (( )                          \n"+NORM+
RED+"                                                                 \n"+NORM+
RED+"             Fire"+NORM+" burns into your opponent.                  \n"+NORM+  
  "\n");
		return 3 + random(3);
	}
	
	if(rand == 1)
	{
		say(this_player()->query_name()+"'s weapon flashes as "+CYN+"water"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		  write("Your weapon "+HIY+"flashes"+NORM+" as "+CYN+"water"+NORM+" glides from the staff ripping through "+attacker->query_name()+"\n"+NORM+
"                                                                                    \n"+NORM+
CYN+"		                                                                         \n"+NORM+
CYN+"		           .HI                                                           \n"+NORM+ 
CYN+"                          .MHMH                 X:                              \n"+NORM+ 
CYN+"                          :HMMH.            .X!HMM.                             \n"+NORM+
CYN+"                          `HMHM!            !MHMMX                              \n"+NORM+      
CYN+"                           HMHHH.            IMM!                               \n"+NORM+
CYN+"                           XHHHHM!                                              \n"+NORM+
CYN+"     XMMM!.                IMHXHMM.                        :I.                  \n"+NORM+
CYN+"     `HMHMMI.              :HHXXHH'                      .AMH'                  \n"+NORM+ 
CYN+"       `VMHHM!              HHXIHH                      :MHH'                   \n"+NORM+
CYN+"        `!HHHA.            XHIIIX.    .MX     .:HD    AHHV                      \n"+NORM+
CYN+"            `HHHA.          !HI!IXI    AM:    AMHH'. :HHM!                      \n"+NORM+  
CYN+"              `XXHA.     .  `HI!:IX   :HH    AHHMV .IXHH'                       \n"+NORM+
CYN+"               `!XIX:.  AMA:.H!::IX.  !HX   AHHHV :IIHX                         \n"+NORM+
CYN+"                `XIXX: :HHHHHI. .HMMMXXH: !XIHHHIIHV'                           \n"+NORM+ 
CYN+"                  `X!:IXIMHHXHI.  IHHH!HX.!IIXH!.IHV                            \n"+NORM+
CYN+"                   `H:.:!IHHXII:  .XH!!HMI::X! :XHI                             \n"+NORM+
CYN+"                    :MI. .!!II!:  :II.!H!.:I:.IHV:                              \n"+NORM+    
CYN+"               :AMMHHII!:. :::::   ::.I: .: :IHV.                           .!!:\n"+NORM+
CYN+"                   `:VMHII:. .       ..   .IHHMI                    .:IHHMMMHMM!\n"+NORM+
CYN+"      ..::::.....      HHXI:.            :IXXHHMH.          .:!IXHHHHHMHHHX!'   \n"+NORM+ 
CYN+"AMMMMMMMMHHHHHHHXIIIII!!!:::.            :!!IXHHHHH:..:!!XXXHHXI!:'             \n"+NORM+
CYN+"              ``::!XHX:....                     .!XHHHI:'                       \n"+NORM+  
CYN+"                       II!:..           .::!IIHHI'                              \n"+NORM+
CYN+"                  .:II::  .::        ::. .:!IHM:                                \n"+NORM+ 
CYN+"            :IXXIIIIIIXHMH::!: .::  .::!II!: :H!                                \n"+NORM+  
CYN+"     .!XHHHHXHHHX!:'  .XXIXH: :III:  !XHHHHHHI!IA:.      !MA                    \n"+NORM+
CYN+" AHMMHMMMHI!:'      :HHHHHH:.!HHHHI: :HM:    `!XXXX::.   XMMI     .HM!          \n"+NORM+  
CYN+" `VI!'             !MV'  :!!IHMMMHHI. XX          `!XHHA. ..      :HMM:         \n"+NORM+
CYN+"                        AIIHI'   VMH: :I             `VHMMH:.      `!!          \n"+NORM+ 
CYN+"             .MMMV'    AHHH:      `HH::!    .HM:        `VMMMA                  \n"+NORM+  
CYN+"           .HV'      :MHHHI        `HI!!.                 `:HMD                 \n"+NORM+        
CYN+"          :'         IMHV'          `XII!                                       \n"+NORM+
CYN+"                      `'             :XIX.                                      \n"+NORM+ 
CYN+"                                      !HHI          IMMI                        \n"+NORM+ 
CYN+"                                      `XHH!         IMMM:                       \n"+NORM+  
CYN+"                                       XHHH.         :I:                        \n"+NORM+
CYN+"                                       !MHMI                                    \n"+NORM+
CYN+"  VK                                   :MHHH:                                   \n"+NORM+  
CYN+"                                       `VMMV'                                   \n"+NORM+ 
CYN+"                                                                                \n"+NORM+
CYN+"                  Water"+NORM+" explodes into your opponent!                    \n"+NORM+
   "\n");		return 3 + random(3);
	}
	
	if(rand == 2)
	{
		say(this_player()->query_name()+"'s weapon "+HIY+"flashes"+NORM+" as "+YEL+"air"+NORM+" glides from the staff ripping through "+attacker->query_name()+".\n");
		  write("Your weapon "+HIY+"flashes"+NORM+" as "+YEL+"air"+NORM+" glides from the staff ripping through "+attacker->query_name()+"\n"+NORM+
"                                                                \n"+NORM+
HIW+"	           .-~*~--,.   .-.                            \n"+NORM+ 
HIW+"          .-~-. ./OOOOOOOOO\.'OOO`9~~-.                     \n"+NORM+ 
HIW+"        .`OOOOOO.OOM.OLSONOOOOO@@OOOOOO\                    \n"+NORM+ 
HIW+"       /OOOO@@@OO@@@OO@@@OOO@@@@@@@@OOOO`.                  \n"+NORM+
HIW+"    .-'OO@@@@WW@@@W@WWWWWWWWOOWW@@@@@OOOOOO}                \n"+NORM+
HIW+"    /OOO@@O@@@@W@@@@@OOWWWWWOOWOO@@@OOO@@@OO|               \n"+NORM+
HIW+"   lOOO@@@OO@@@WWWWWW"+HIY+"\\"+HIW+"OWWWWO"+HIY+"\\"+HIW+"WWWOOOOOO@@@O.'                \n"+NORM+
HIW+"    \OOO@@@OOO@@@@@@OOW"+HIY+"\\      \\"+HIW+"WWWW@@@@@@@O'.                \n"+NORM+
HIW+"    `,OO@@@OOOOOOOOOOWW"+HIY+"\\      \\"+HIW+"WWWW@@@@@@OOO)                \n"+NORM+
HIW+"      \,O@@@@@OOOOOOWWWWW"+HIY+"\\      \\"+HIW+"WW@@@@@OOOO.'               \n"+NORM+
HIW+"        `~c~8~@@@@WWW@@"+HIY+"\\       \\"+HIW+"WOO|\UO-~'                 \n"+NORM+
HIW+"             (OWWWWWW@@0"+HIY+"\\    ___\\"+HIW+"WO)                       \n"+NORM+
HIW+"               `~-~''    "+HIY+"\\   \\"+HIW+"WW=*'                        \n"+NORM+
HIY+"                         _\\   \\                            \n"+NORM+  
HIY+"                        \\      \\                           \n"+NORM+ 
HIY+"                         \\     _\\                          \n"+NORM+      
HIY+"                          \\   \\                             \n"+NORM+               
HIY+"                           \\  \\                             \n"+NORM+
HIY+"                            \\  \\                            \n"+NORM+
HIY+"                             \\ \\                            \n"+NORM+
HIY+"                              \\ \\                           \n"+NORM+
HIY+"                               \\\\                           \n"+NORM+
HIY+"                                \\\                          \n"+NORM+ 
HIY+"                                                           \n"+NORM+
HIY+"                                                           \n\n"+NORM+ 
BOLD+"             "+HIY+"Lightning"+NORM+" strikes it's target!!!      \n"+NORM+
  "\n");
		return 3 + random(3);
	}
	
	if(rand == 3)
	{
		say(this_player()->query_name()+"'s weapon "+HIY+"flashes"+NORM+" as "+GRN+"stone shards"+NORM+" glide from the staff ripping through "+attacker->query_name()+".\n");
				  write("Your weapon "+HIY+"flashes"+NORM+" as "+GRN+"rocks"+NORM+" glide from the staff ripping through "+attacker->query_name()+"\n"+NORM+ 
YEL+"                                                                   \n"+NORM+
YEL+"                         _,.---._     _,.----.    ,--.-.,-.        \n"+NORM+
YEL+"         .-.,.---.    ,-.' , -  `.   .' .' -   \\  /==/- |\\  \\   \n"+NORM+ 
YEL+"        /==/  `   \\  /==/_,  ,  - \\ /==/  ,  ,-' |==|_ `/_ /     \n"+NORM+
YEL+"        |==|-, .=., ||==|   .=.     ||==|-   |  . |==| ,   /        \n"+NORM+ 
YEL+"        |==|   '='  /|==|_ : ;=:  - ||==|_   `-' \|==|-  .|         \n"+NORM+
YEL+"        |==|- ,   .' |==| , '='     ||==|   _  , ||==| _ , \\       \n"+NORM+ 
YEL+"        |==|_  . ,'.  \==\ -    ,_  / \\==\\.       //==/  '\\  |   \n"+NORM+
YEL+"        /==/  /\\ ,  )  '.='. -   .'   `-.`.___.-' \\==\\ /\\=\\.'  \n"+NORM+
YEL+"         `--`-`--`--'     `--`--''                 `--`             \n"+NORM+
YEL+"          ,-,--.              .=-.-.                 ,----.        \n"+NORM+
YEL+"         ,-.'-  _\\   _.-.     /==/_ / _,..---._     ,-.--` , \\    \n"+NORM+
YEL+"        /==/_ ,_.' .-,.'|    |==|, |/==/,   -  \\   |==|-  _.-`     \n"+NORM+
YEL+"        \\==\\  \\   |==|, |    |==|  ||==|   _    \\  |==|   `.-.  \n"+NORM+
YEL+"         \\==\\ -\\  |==|- |    |==|- ||==|  .=.   | /==/_ ,    /   \n"+NORM+
YEL+"         _\\==\\ ,\\ |==|, |    |==| ,| |==|,|   | -||==|    .-'    \n"+NORM+  
YEL+"        /==/\\/ _ ||==|- `-._ |==|- || ==|  '='   /|==|_  ,`-._     \n"+NORM+
YEL+"        \\==\\ - ,/ /==/ - , , //==/. /|==|-,   _`/ /==/ ,     /    \n"+NORM+
YEL+"         `--`---'  `--`-----'  `--`-` `-.`.____.'  `--`-----``      \n"+NORM+ 
YEL+"                                                                    \n"+NORM+  
GRN+"          Rocks"+NORM+" roll over you Opponent crushing them!      \n"+NORM+
  "\n");  
		return 3 + random(3);
	}
}
