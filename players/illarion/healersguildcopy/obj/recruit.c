#include "../def.h"
#define SAVE "players/guilds/healers/obj/recruitment"
#define AMOUNT 500
int level;
string refr;
string who;
int store_xp;

drop() { return 0;}
get() { return 1;}

query_weight() { return 1000000; }

id(str) { return str == "recruitment" || str == "recruit" || str == "refer" || str == "reference" || str == "tablet"; }

reset(arg) {
    if(arg) return;
    who = ({});
    refr = ({});
    level = ({});
    store_xp = ({});
    restore_object(SAVE);
}

short() {
    if(check(tp)) return "A Reference Tablet";
}

long() { if(check(tp)) {
	write("You see a small marble tablet before you.\n"+
	  "On it are the words:\n\n"+
	  "         Refer she who has helped you\n\n"+
	  "This Tablet is here so you can refer or be \n"+
	  "refered by another Healer as Mentor.\n"+
	  "Usually the Mentor is the Healer who has brought\n"+
	  "one into the world of the Healers.\n\n");
	write("To refer another Healer as your Mentor \n"+
	  "  type 'refer <name>'\n"+
	  "Remember you can only have ONE Mentor.\n\n"+
	  "To see all the referers type 'referred'\n");
    }
}

check(object ob) {
    if(read_file("/"+MEM+ob->query_real_name()+".o")) return 1;
    return 0;
}

save_me() { save_object(SAVE); }

init() {
    if(check(tp)) {
	add_action("refer","refer");
	add_action("referred","referred");
	if(member_array(tpn,refr) != -1) gain(tp);
	if(member_array(tpn,who) != -1) award(tp);
	save_me();
    }
}

refer(str) {
    int h;
    if(!str) { write("Refer who?\n"); return 1; }
    if((h = member_array(tpn,who)) != -1) {
	write("You can only refer ONCE!\n"+
	  "You already referred "+refr[h]+"\n");
	return 1; }
    if(!read_file("/"+MEM+str+".o")) {
	write("That person is not a Healer!\n");
	return 1; }
    if(str == tpn) { write("you can not refer yourself!\n"); return 1; }
    h = tp->query_level() + tp->query_extra_level();
    who += ({tpn});
    refr += ({str});
    level += ({h});
    store_xp += ({AMOUNT});
    save_me();
    write("You have referred "+str+"\n");
    if(find_player(str)) tell_object(find_player(str),tpn+" has referred you.\n");
    return 1;}

referred() {
    int h;
    write("Name                   Mentor\n");
    write("----------------------------------------------\n");
    for(h=0;h<sizeof(refr);h++) {
	write(who[h]+"               "+refr[h]);
	if(tp->query_level() > 90) write("     "+level[h]);
	write("\n");
    }
    write("\n");
    return 1; }

gain(object ob) {
    int h;
    string name;
    name = ob->query_real_name();
    for(h=0;h<sizeof(refr);h++) {
	if(refr[h] == name)
	    if(store_xp[h] > 0) {
		ob->add_xp(store_xp[h]);
		tell_object(ob,"You have gained "+store_xp[h]+" xp because "+who[h]+" who is\n"+
		  "under your care has grown up a bit more!\n");
		store_xp[h] = 0;
	    }
    }
    save_me();
    return 1;}

award(object ob) {
    int h,i;
    h = member_array(ob->query_real_name(),who);
    if((i = (ob->query_level() + ob->query_extra_level()) - level[h]) > 0) {
	store_xp[h] = store_xp[h] + (i * AMOUNT);
	level[h] = ob->query_level() + ob->query_extra_level();
    }
    save_me();
    return 1; }
