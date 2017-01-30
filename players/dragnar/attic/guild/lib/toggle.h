#include "/players/dragnar/guild/defs/def.h"
toggle(str) {
	     int amount, amount2, TSPS;
        string what, thisp;
	     if(!str || sscanf(str, "%d %s", amount,what) != 2) {
	     write("Usage Example: toggle 100 hps\n");
	     return 1; }
        if(!amount) {
        write("How much to you want to toggle?\n");
        return 1; }
        if(!what) {
        write("Do you want to toggle 'hps' or 'sps'?\n");
        return 1; }
	     if(what != "sps" && what != "hps") {
        write("You can only toggle 'hps' or 'sps'.\n");
        return 1; }
	     if(amount < 1) {
	write("Shardak forbids you to dishonor him by cheating.\n");
	return 1; }
        if(what == "sps") { 
        thisp = this_player()->query_sp();
        TSPS = usp;
         }
	   if(what == "hps") { thisp = this_player()->query_hp(); }
        if(amount > thisp) {
        write("You don't have enough "+what+" to toggle that much.\n");
        return 1; }
        if(what == "sps") {
        this_player()->heal_self(amount);
        if(usp == umsp) {
	     amount2 = ((umsp-TSPS)+amount);
	     this_player()->add_spell_point(-amount2);
	     write("You toggle "+amount+" sps to make yorself stronger.\n");
	return 1; }
        if(usp < umsp) {
	     this_player()->add_spell_point(-(amount * 2));
        }
        write("You toggle "+amount+" "+what+" to make yourself stronger.\n");
        return 1; }
        if(what == "hps") {
        this_player()->heal_self(-amount);
        this_player()->add_spell_point(amount * 2);
        write("You toggle "+amount+" "+what+" to increase your magic.\n");
        return 1; }
}
