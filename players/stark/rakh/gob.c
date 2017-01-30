/*
   Rakh Guild Object Alpha
*/
#include "/players/stark/defs.h"
#include "/players/stark/rakh/cmd/_talk.h"
#include "/players/stark/rakh/cmd/_lead.h"
#include "/players/stark/rakh/cmd/_know.h"
#include "/players/stark/rakh/cmd/_wield.h"
#include "/players/stark/rakh/cmd/_wear.h"


int gexp;
int fae; /* fae stat */
int fps; /* current amt of fae points */
int fps_max;  /* max amt of fae points */
int meditate_state; /* Are they meding? */
int hunting_lvl;  /* lvl of hunting skills */
int hunting_amt;  /* # hunting has been used */
int hunting1_lvl; /* lvl of this hunting skill */
int hunting1_amt; /* # this skill has been used */
int hunting2_lvl;
int hunting2_amt;
int hunting3_lvl;
int hunting3_amt;
int aura_lvl;
int aura_amt;
int aura1_lvl;
int aura1_amt;
int aura1_state; /* is this aura on? */
int aura2_lvl;
int aura2_amt;
int aura2_state;
int aura3_lvl;
int aura3_amt;
int aura3_state;
int aura4_lvl;
int aura4_amt;
int body_lvl;
int body_amt;
int body1_lvl;
int body1_amt;
int body2_lvl;
int body2_amt;
int body3_lvl;
int body3_amt;
int body4_lvl;
int body4_amt;
int body4_state;
int life_lvl;
int life_amt;
int life1_lvl;
int life1_amt;
int life2_lvl;
int life2_amt;
int life3_lvl;
int life3_amt;
int storedwc; /* WC of last wielded weapon */
object storedwepobj; /* Name of short of weapon stored */

extra_look(){ return capitalize(TPRN)+" is covered in an aura"; }
long(){ return write("Rakh\n  rhelp"); }
id(string str) { return str == "aura" || str == "rakh_guild"; }
get() { return 1; }

reset(arg){
    if(arg) return;
}
init(){
restore_object("players/stark/rakh/mem/"+TPRN);

fps_max=100+fae*200;
storedwepobj = TO;
storedwc = 0;
aura1_state=0;
aura2_state=0;
set_heart_beat(1);

add_action("rhelp","rhelp");
add_action("rakh_talk","rgt");
add_action("rakh_talk_history","rgh");
add_action("rakh_talk_emote","rge");
add_action("guild_title","guild_title");

add_action("meditate","meditate");
add_action("aura1_clone","healing_aura");
add_action("aura2_clone","armor_aura");
add_action("aura3_clone","reflect_aura");
add_action("lead","lead");
add_action("leave_scent","scent");

add_action("drop","drop");
add_action("wear","wear");
add_action("starkwield","starkwield");
add_action("starkunwield","starkunwield");
/*add_action("wield","wield");
add_action("unwield","unwield");*/
add_action("add_fps","add_fps");
add_action("var_list","var_list");
add_action("quit","quit");
add_action("save","save");
add_action("update_gob","update_gob");
}

/* Base Guild Stuff*/
rhelp(string str){
if(!str){ cat("/players/stark/rakh/help/guild"); }
cat("/players/stark/rakh/help/"+str);
return 1;}

/* querys, add, switches */
query_fps(){ return fps; }
query_fps_max(){ return fps_max; }
query_aura1_lvl(){ return aura1_lvl; }
query_life1_lvl(){ return life1_lvl; }

/* HB */

heart_beat(){
int damage;
int damage2;
string msg;
object attacker;
if(ETO->query_attack()){
    damage=ETO->query_dam_taken_this_round();
    attacker=ETO->query_attack();
    /* ability to take less amt of dmg even after armor */
    if(random(80)<random(body1_lvl)){
        damage=ETO->query_dam_taken_this_round();
	damage=damage*(body2_lvl/10);
	msg="You dodge the attack";
	ETO->add_hp(damage);
	tell_object(ETO,msg+"\n");
    }
    /* Reflects damage back to attacker */
    if(aura3_state){
        damage2=damage*(aura3_lvl/10);
        attacker->add_hp(damage*(aura3_lvl/10));
	tell_object(ETO,"You reflect some damage back at "+attacker+"!\n");
	tell_object(attacker,"You feel some of the attack reflected!\n");
    }
    /* rage attack */
    if(body4_state){
        if(random(30-body4_state){
	    damage2=damage2+random(body4_lvl*2);
	    tell_object(ETO,"You attack "+attacker+" with all of your hatred!\n");
	}
    }
    attacker->add_hp(damage2);
}
}


/* cmds */
guild_title(){
string gtitle;
if(life3_lvl==6){
    gtitle = "the Rakhene Chieftan";
}
if(life3_lvl==5){
    gtitle = "of the Rakhene Clans";
}
if(life3_lvl==4){
    gtitle = "the Elder Warrior";
}
if(life3_lvl==3){
    gtitle = "the Defender of the Plains";
}
if(life3_lvl==2){
    gtitle = "the Rakhene Warrior";
}
if(life3_lvl==1){
    gtitle = "the younger Rakh";
}
gtitle = "of the plains";
TP->set_title(gtitle+NORM);
write("Title fixed!\n);
}




aura1_clone(){
if(aura1_state){
    destruct(present("healing_aura",TP));
    write("You lower your healing aura.\n");
    aura1_state=0;
    return 1;}
MOCO("/players/stark/rakh/obj/ha"),TP);
write("You slowly bring up a healing aura.\n");
aura1_state=1;
return 1;}

aura2_clone(){
if(aura2_state){
    destruct(present("armor_aura",TP));
    write("You lower your shielding aura.\n");
    aura2_state=0;
    return 1;}
MOCO("/players/stark/rakh/obj/sa"),TP);
write("You slowly bring up a shielding aura.\n");
present("armor_aura",TP)->set_strength(aura2_lvl);
aura2_state=1;
return 1;}

aura3_clone(){
if(aura2_state){
    write("You lower your reflecting aura.\n");
    aura3_state=0;
    return 1;}
aura3_state=1;
write("You slowly bring up a relecting aura.\n");
return 1;}


leave_scent(){
if(present("rakh_scent",ETP)){
    destruct(present("rakh_scent",ETP));
    write("You remove the previous scent and...\n");
    }
MOCO("/players/stark/rakh/obj/scent"),ETP);
write("You rub against your surroundings gently.\n");
return 1;}


meditate(){
if(meditate_state){
    write("You rise from your meditative state.\n");
    destruct(present("meditate_lock",TP));
    meditate_state=0;
    return 1;}
MOCO("/players/stark/rakh/obj/med"),TP);
write("You drop into a meditative state.\n");
meditate_state=1;
return 1;}


drop(string str){
object ob;
if(!str){return 1;}
ob = present(str,TP);
if(ob==storedwepobj || str=="all"){
    starkunwield();
}
if(ob==TO){
    return 1;}
return 0;
}

/* GC and GW cmds */

add_fps(fpsadd){fps=fps+fpsadd;}

var_list(){
/*
  Gives printout of all vars.  will make sc/score cmd later on
*/
write("\ngexp:"+gexp+" fae:"+fae+
"\n fps:"+fps+" fps_max:"+fps_max+" meditate_state:"+meditate_state+
"\n hunting_lvl:"+hunting_lvl+" hunting_amt:"+hunting_amt+
"\n hunting1_lvl:"+hunting1_lvl+" hunting1_amt:"+hunting1_amt+
"\n hunting2_lvl:"+hunting2_lvl+" hunting2_amt:"+hunting2_amt+
"\n hunting3_lvl:"+hunting3_lvl+" hunting3_amt:"+hunting3_amt+
"\n aura_lvl:"+aura_lvl+" aura_amt:"+aura_amt+
"\n aura1_lvl:"+aura1_lvl+" aura1_amt:"+aura1_amt+
"\n aura2_lvl:"+aura2_lvl+" aura2_amt:"+aura2_amt+
"\n aura3_lvl:"+aura3_lvl+" aura3_amt:"+aura3_amt+
"\n aura4_lvl:"+aura4_lvl+" aura4_amt:"+aura4_amt+
"\n body_lvl:"+body_lvl+" body_amt:"+body_amt+
"\n body1_lvl:"+body1_lvl+" body1_amt:"+body1_amt+
"\n body2_lvl:"+body2_lvl+" body2_amt:"+body2_amt+
"\n body3_lvl:"+body3_lvl+" body3_amt:"+body3_amt+
"\n life_lvl:"+life_lvl+" life_amt:"+life_amt+
"\n life1_lvl:"+life1_lvl+" life1_amt:"+life1_amt+
"\n life2_lvl:"+life2_lvl+" life2_amt:"+life2_amt+
"\n life3_lvl:"+life3_lvl+" life3_amt:"+life3_amt);return 1;}


/* load and save */
query_auto_load(){
	save_object("players/stark/rakh/mem/"+TPRN);
	return "/players/stark/rakh/gob:";
}
update_gob(){
    save();
    MOCO("/players/stark/rakh/gob.c"),TP);
    destruct(TO);
    write("New obj!\n");
    return 1;
}
quit(){
write("Have a nice day.\n");
    if(present("armor_aura",TP)){
        destruct(present("armor_aura",TP));
	aura1_state=0;
    }
    if(present("healing_aura",TP)){
        destruct(present("armor_aura",TP));
	aura2_state=0;
    }
aura3_state=0;
save();
}


save(){
	save_object("players/stark/rakh/mem/"+TPRN);
	write("Saving gob\n");
}
