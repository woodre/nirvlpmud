#include "../../DEFS"

inherit "/obj/armor.c";

int numof;
int activated;

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_ac_flag = 2; 
    set_type(GHOULSHIELD);
    set_silently(1);
    set_id(GHOULSHIELD);
    set_long("How are you looking at this?  Contact Rumplemintz.\n");
    numof = 3;
    activated = 0;
}

extra_look(){
    if(activated){
	return BOLD+environment(this_object())->query_name()+" is surrounded by "+numof+" flying ghouls"+OFF;
    }
}

set_numof(i){ numof = i; }
set_time(t){ call_out("destructme",t); }

do_special(owner){
    if(owner->query_attack()) /* added 6.2.01 by Vertebraker */
	if(random(10) < numof){
	    tell_object(owner,"A "+BOLD+"ghoul"+OFF+" swoops around you and helps deflect an attack.\n");
	    tell_object(owner->query_attack(),"A "+BOLD+"ghoul"+OFF+" swooped around "+owner->query_name()+" and blocked your attack.\n");
	    owner->remote_say("A "+BOLD+"ghoul"+OFF+" swooped around "+owner->query_name()+" and helped block "+owner->query_attack()->query_name()+"'s attack.\n",owner->query_attack()); 
	    return random(owner->query_guild_rank());
	}
}

do_emote(){
    object owner;
    object room;
    string msg,room_msg;
    owner = environment(this_object());
    room = environment(owner);
    if(!owner){
	destruct(this_object());
    }
    if(!room){
	destruct(this_object());
    } 
    switch(random(10)){
    case 0:  msg = "A ghoul wails.\n"; 
	room_msg = "A ghoul wails.\n"; 
	break;
    case 1:  msg = "You feel a ghoul fly past your left ear.\n";
	room_msg = "A ghoul flies past "+owner->query_name()+"'s left ear.\n";
	break;
    case 2:  msg = "A ghoul flays about in midair.\n";
	room_msg = "A ghouls flays about in midair.\n";
	break;
    case 3:  msg = "You can hear the screams of the ghouls as they fly around.\n";
	room_msg = "You can hear the screams of the ghouls as they fly around.\n";
	break;
    default: msg = "A ghoul swoops around you.\n"; 
	room_msg = "A ghoul swoops around "+owner->query_name()+".\n"; 
	break;
    }
    tell_object(owner,msg);
    owner->remote_say(room_msg);
    call_out("do_emote",random(50));
}

destructme(){
    if(environment(this_object())){
	if(environment(environment(this_object())))
	    tell_room(environment(environment(this_object())),BOLD+"The ghouls fly down back into the earth from whence they came.\n"+OFF);
	else
	    tell_room(environment(this_object()),BOLD+"The ghouls fly down back into the earth from whence they came.\n"+OFF);
    }
    remove("necro_spirit_armor");
    destruct(this_object());
}

init(){
    if(environment()){
	if(!environment(this_object())->is_player()){ destructme(); return; }
	::init();
	if(!present(GUILD_ID, this_player())){ destruct(this_object()); return 1; }
    }
}

activate(){
    activated = 1;
    say(BOLD+"A series of "+numof+" ghouls fly up through the earth and start circling "+environment()->query_name()+".\n"+OFF);
    write(BOLD+"A series of "+numof+" ghouls fly up through the earth and start circling you.\n"+OFF);
    wear("necro_spirit_armor");
    call_out("do_emote",10);
}

drop(){ return 1; }
