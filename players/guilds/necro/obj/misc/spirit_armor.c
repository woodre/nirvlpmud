#include "../../DEFS"

inherit "/obj/armor.c";

id(str){ return (str == "spirits" || str == "spirit_armor"); }
get(){ return 0; }
drop(){ return 1; }
query_type(){ return "spirit_armor"; }

extra_look(){
    write(BOLD+"Spirits fly and wail around "+environment()->query_name()+OFF);
}

call_armor_special(){
    object necro;
    string msg;
    necro = environment(this_object());
    switch(random(10)){
    case 0:  msg = "Spirits from the dead rise up to help catch the attack from your enemy.\n"; break;
    case 1:  msg = "spirit block.\n"; break;
    case 2:  msg = "spirit block.\n"; break;
    case 3:  msg = "spirit block.\n"; break;
    case 4..7: msg = "blocked by spirits.\n"; break;
    case 8..9: msg = ""; break;
    default: msg = ""; break;
    } 
    tell_room(environment(necro),msg);
    return (necro->query_guild_rank()+random(necro->query_guild_rank()));
}

init() {
    ::init();
    if(environment(this_object()))
	if(this_player() == environment(this_object())){
	    command("wear spirits", environment(this_object()));
	    call_out("wipe",1000);
	    return 1;
	} 
}

wipe() {
    if(!environment(this_object())) return 1;
    tell_object(environment(this_object()),"\nWraithform runs its course and you return to your solid form.\n\n");
    command(environment(this_object()), "remove spirits");
    destruct(this_object());
    return 1;
}

