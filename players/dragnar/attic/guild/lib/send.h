#include "/players/dragnar/guild/defs/def.h"
send(str) {
        int amount;
        string who;
        if(!str || sscanf(str, "%s %d", who, amount) != 2) { 
        write("To use send: 'send <who> <amount>'\n");
        return 1; }
        if(!find_player(who)) {
        write(capitalize(who)+" is not on.\n");
        return 1; }
        if(amount < 1) {
        write("Shardak forbids you to dishonor him by cheating.\n");
        return 1; }
        if(amount > usp) {
        write("You do not have enough spell points to sacrifice.\n");
        return 1; }
        find_player(who)->add_spell_point(amount);
        this_player()->add_spell_point(-amount);
        write("You send "+amount+" hit points to "+capitalize(who)+".\n"+
        "You stumble from the loss of energy.\n");
        tell_object(find_player(who), capname+" uses his Shardak energy to send you "+amount+" spell points.\n");
        return 1; }
