#include <ansi.h>
#define LEV 90

object chan;

id(str) { return str == "healerchanneldaem"; }

reset(arg) {
    if(arg) return;
    if(environment()) { destruct(this_object()); return 1; }
    chan = ({this_object()});
}

add_channel(object targ) {
    if(!targ) return 1;
    if(member_array(targ,chan) == -1) chan += ({targ});
}

speak_channel(string msg) {
    int h, j;
    object ob;
    string mssg;
    j = 0;
    clear();
    if(!msg || msg == "") {
	msg = "";
	j = 1;
	mssg = GRN;
	mssg += "........................................................................\n";
	mssg += NORM;
	mssg += "      Name\t\tLevel\thp   sp\n";
	mssg += GRN;
	mssg += "........................................................................\n";
	mssg += NORM;

	tell_object(this_player(),mssg);
	mssg = "";
    }
    for(h=0;h<sizeof(chan);h++) {
	ob = chan[h];
	if(chan[h]) {
#ifdef __LDMUD__
if(msg !="") tell_object(chan[h],msg+"\n");
#else
            if(msg != "") tell_object(chan[h],msg);
#endif
	    else {
		if(living(ob)) {
		    if(!ob->query_invis() || this_player()->query_level() > LEV) {
			if(!interactive(ob)) mssg += "x";
			if(ob->is_ghost()) mssg += "*";
			if(interactive(ob))
			    if(query_idle(ob) > 120) mssg += "i";
			if(ob->query_attack()) mssg += "C";
			if(ob->query_invis()) mssg += "#";
			while(strlen(mssg) < 6) mssg += " ";
			mssg += capitalize(ob->query_real_name());
			if(strlen(ob->query_real_name()) < 2) mssg += "\t";
			if(strlen(ob->query_real_name()) < 10) mssg += "\t";
			mssg += "\t";
			if(ob->query_level() < 20)
			    mssg += (ob->query_level() + ob->query_extra_level());
			else mssg += "WIZ";
			mssg += "\t";
			mssg += (10 * ob->query_hp()) / ob->query_mhp()  * 10;
			mssg += "%  ";
			mssg += (10 * ob->query_sp()) / ob->query_msp()  * 10;
			mssg += "%";
			if(this_player()->query_level() > 200) mssg += "     "+ob->query_exp();
			mssg += "\n";
			tell_object(this_player(),mssg);
			mssg = "";
		    }
		}
	    }
	} 
    }
    if(j) {
	mssg = "\nx = Disconnected, * = ghost, i = idle, C = Combat";
	if(this_player()->query_level() > LEV) mssg += "# = invis";
	mssg += "\n"+GRN;
	mssg += "........................................................................\n";
	mssg += NORM;

	tell_object(this_player(),mssg);
    }
    return 1; }

clear() {  
    int i;
    for(i=0;i<sizeof(chan);i++) {
	if(!chan[i]) chan -= ({chan[i]});
    }
}
