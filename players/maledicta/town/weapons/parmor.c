/* This armor is used to lower carry by having a -2 weight. It has an ac of 4, but is
   offset by a high cost: 50000 coins.                                                */

#include "/players/maledicta/include/setac.h"
#include "/players/maledicta/ansi.h"
#define USER environment(this_object())
#define LIVING USER->is_living()
inherit "obj/armor";
int armor_wear;
string wear_mess;
reset(arg) {
set_name("armor");
set_alt_name("power_armor_derellia");
set_alias("power");
set_short("["+HIM+"Powered Battle Armor"+NORM+"]");
set_ac(3);
set_type("armor");
set_weight(0);
set_value(3000);
armor_wear = 6000;  
}
long(){
armor_mess(armor_wear);	
write( 
"  A large suit of metallic armor. Its covers the wearers torso protecting it\n"+
"from almost any offensive weapon. Its heavy weight is offset by huge servo\n"+
"motors that actually overcome its own burden and add additional strength to\n"+
"the wearer. It hums with barely restrained power.\n"+
"It is "+wear_mess+"\n");
return 1;
}

armor_mess(int i){
if(i >= 5000){
    wear_mess = "like new.";
    }		
else if(i >= 2000){
    wear_mess = "a little worn.";
}
else if(i >= 801){
    wear_mess = "is somewhat worn.";
}
else if(i >= 300){
    wear_mess = "worn.";
}
else if(i >= 1){
    wear_mess = "very worn.";
}
else{
wear_mess = "Useless.";
   }
}		    	    	    	


do_special(owner){
armor_wear --;
if(armor_wear <= 0){
this_object()->set_ac(0);
recalc_ac();	
tell_object(environment(this_object()), "You armor becomes useless as it absorbs too much damage!\n"+
      "It falls from your body into a useless lump of scrap.\n");
destruct(this_object());	 
return 0;
   }
return 0;
}	
	
fix_armor(){
armor_wear = 6000;
return 1;
}	