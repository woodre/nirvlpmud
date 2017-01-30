#include "../../DEFS"

int fuel,is_lit;
int lightamount,held;
string name,obname,bodypart,whichbodypart;

id(str) {
    return (str == whichbodypart || str == "zombie_part" || str == bodypart); 
}

short() { 
    string msg; 
    msg = "The "+whichbodypart+" of "+name; 
    if(is_lit)
	msg+= " ("+HIR+"flaming"+OFF+")";
    if(held)
	msg += " (held)";
    return msg;
}

long() { 
    write("This is the bloody "+whichbodypart+" of a corpse.  It looks like it was\n"+
      "violently ripped off of its pervious owner as the skin has been\n"+
      "torn and shreaded.  The skin has begun to decay and is starting\n"+
      "to give off a horrific stench.  If one was so inclined they could \n"+
      "easily 'light' this "+bodypart+" on fire and, perhaps, 'hold' it up to\n"+
      "get a brighter light cast.\n"); 
}

reset(arg) { 
    if(arg) return;
    name = "an unknown victim";
    bodypart = "arm";
    whichbodypart = "left arm";
    obname = "the "+whichbodypart+" of "+name;
    fuel = 1500;
}

set_name(n){ name = n; obname = "the "+whichbodypart+" of "+name; }
set_part(n){ bodypart = n; }
set_whichpart(n){ whichbodypart = n; }

init(){
    add_action("light","light");
    add_action("extinguish","extinguish");
    add_action("hold","hold");
    add_action("unhold","unhold");
}

hold(str){
    int i,s,inv;
    if(!str){
	notify_fail("What would you like to hold?\n");
	return 0;
    }
    if(!id(str)){
	notify_fail("That is something you can hold.\n");
	return 0;
    }
    if(held){
	notify_fail("You are already holding the torch.\n");
	return 0;
    }
    inv=all_inventory(this_player());
    s=sizeof(inv);
    for(i=0;i<s;i++) {
	if((string)inv[i]->query_type() == "shield" && inv[i]->query_worn()) {
	    write("You can not hold a shield and a torch at the same time.\n");
	    return 1;
	}
	if(inv[i]->query_offwielded()){
	    write("You can not hold your "+bodypart+" and an offwielded weapon at the same time.\n");
	    return 1;
	}
    }
    write("You hold the "+bodypart+" high in her hand to increase its potential brightness.\n");
    held = 1;
    lightamount++;
    if(is_lit)
	set_light(1);
    return 1;
}

unhold(str){
    if(!str){
	notify_fail("What would you like to unhold?\n");
	return 0;
    }
    if(!id(str)){
	notify_fail("That is not something you can let go of.\n");
	return 0;
    }
    if(!held){
	notify_fail("You are not holding the "+bodypart+".\n");
	return 0;
    }
    held = 0;
    lightamount--;
    if(is_lit){
	write("You tuck your "+HIR+"flaming "+OFF+bodypart+" into your belt.\n");
	set_light(-1);
    }
    else{
	write("You tuck "+obname+" into your belt.\n");
    }
    return 1;
}

light(str){
    if(!str){
	notify_fail("What would you like to light?\n");
	return 0;
    }
    if(!id(str)){
	notify_fail("That is not something you can light.\n");
	return 0;
    }
    if(is_lit){
	notify_fail("The "+bodypart+" is already lit.\n");
	return 0;
    }
    is_lit = 1;
    lightamount++;
    write("You light up "+obname+".\n"+HIR+"The flame begins to glow brightly.\n"+OFF);
    set_light(lightamount);
    set_heart_beat(1);
    return 1;
}

extinguish(str){
    if(!str){
	notify_fail("What would you like to extinguish?\n");
	return 0;
    }
    if(!id(str)){
	notify_fail("That is not here for you to extinguish.\n");
	return 0;
    }
    if(!is_lit){
	notify_fail("The arm is not lit.\n");
	return 0;
    }
    write("You quickly shove the "+bodypart+" into some dirt extinguishing the flame.\n");
    is_lit = 0;

    set_light(-lightamount);
    lightamount --;
    set_heart_beat(0);
    return 1;
}

heart_beat() {
    if (!is_lit)
	return;
    fuel -= 1;
    if (fuel > 0){
	if(!random(20)){
	    switch(random(4)){
	    case 0:  say("The "+HIR+"flame"+OFF+" of the "+bodypart+" begins to flare violently.\n"+OFF);
		break;
	    case 1:  say("Sparks fly off of the "+HIR+"flaming "+OFF+bodypart+".\n"+OFF);  
		break;
	    case 2:  say("The smell of rotten flesh eminates from the "+HIR+"flaming "+OFF+bodypart+".\n"+OFF);
		break;
	    case 3:  say("The "+HIR+"flaming "+OFF+bodypart+" flickers, casting shadows everywhere.\n"+OFF);
		break;
	    }
	}
	return;
    }
    say("The flame of the makeshift torch begins to dwindle down.\n"); 
    say(BOLD+BLK+"Suddenly "+obname+" goes dark.\n"+OFF);

    set_heart_beat(0);
    call_out("destructme",2);
}

destructme(){
    object ob;
    is_lit = 0;
    set_light(-1);
    ob = environment();
    tell_object(ob,"The ash of "+obname+" is caught by the wind and soon discintergrates.\n");
    destruct(this_object());
    ob->recalc_carry();   
}

drop(){ if(held){ write("You are holding the "+obname+".\n"); return 1; }else{ return 0; } }
get() { return 1; }
query_weight(){ return 1; }
query_value(){ return 10; }
query_zombie_part(){ return whichbodypart; }
query_offwielded() { return held; }
