/* This armor is used to help carry by having a 0 weight. It has an ac of 3, but is
   offset by a high cost: 50000 coins.                                                */
/*  This armor wears out, and has been setup to store the
amount when lockered.  */

#include "/players/maledicta/ansi.h"
#define USER environment(this_object())
#define NAME USER->query_real_name()
#define LIVING USER->is_living()
inherit "obj/armor";
int armor_wear;
string wear_mess;
reset(arg) {
set_name("armor");
set_alias("power_armor_derellia");
set_short("["+HIM+"Powered Battle Armor"+NORM+"]");
set_ac(3);
set_type("armor");
set_weight(0);
set_value(3000);
armor_wear = 6000;  
}

query_hits(){ return armor_wear; }
query_misses(){ return 0; }
set_hits(int i){ 
	write_file("/players/maledicta/log/parmor_log",
                "hits: "+ctime(time())+" Armor Wear: "+armor_wear+"\n");
	armor_wear = i; }
set_misses(int i){ 
	write_file("/players/maledicta/log/parmor_log",
                "Miss: "+ctime(time())+" Armor Wear: "+armor_wear+"\n");
	return 1; }

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

init(){
	::init();
	if(!environment()) return;
	write_file("/players/maledicta/log/parmor_log",
                ctime(time())+"  "+NAME+
                " Armor Wear: "+armor_wear+"\n");
}

do_special(owner){
armor_wear --;
if(armor_wear <= 0){
this_object()->set_ac(0);
this_object()->drop(1);	
tell_object(environment(this_object()), "You armor becomes useless as it absorbs too much damage!\n"+
      "It falls from your body into a useless lump of scrap.\n");
destruct(this_object());	 
return 0;
   }
if(random(100) < 10){
tell_object(environment(),
"Your power armor whines as its servo-motors force you into a quick dodge!\n");
return 2; }
else if(random(100) < 20){
tell_object(environment(),
"You hear a sharp clang as your armor resists your opponents strike!\n");
return 1;
}
else{
return 0;
}
return 0;
}	
	
fix_armor(){
armor_wear = 6000;
return 1;
}	
