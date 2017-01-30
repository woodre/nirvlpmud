#include "../../DEFS"

int hb, count;

id(str) { return str == "bloodmoon"; }

reset(arg) {
    if(arg) return;
    hb = count = 0;
    set_heart_beat(1);
}

heart_beat() {
    int h;
    object inv;
    if(!environment(this_object())) return;
    if(count > 50) { 
	tell_room(environment(this_object()),"The BloodMoon disappears....\n");
	destruct(this_object());
	return; 
    }
    if(!random(30)){
	inv = all_inventory(environment(this_object()));
	for(h=0;h<sizeof(inv);h++) {
	    if(inv[h]) if(living(inv[h])) if(inv[h]->is_player()) if(present(GUILD_ID,inv[h]))
			    do_psych(inv[h]);
	}
    }
    count++;
} 

do_psych(object trg) {
    string msg;
    if(!trg) return 1;
    switch(random(4)) {
    case 0: msg = HIR+"The Bloodmoon casts a pall over the area."+OFF; break;
    case 1: msg = HIR+"The Bloodmoon strengthens your dark powers."+OFF; break;
    case 2: msg = HIR+"The Bloodmoon pulses with a life all its own."+OFF; break;
    case 3: msg = HIR+"You find comfort within the embrace of the Bloodmoon."+OFF; break;
    }
    tell_object(trg,msg+"\n");
    return 1; 
}

