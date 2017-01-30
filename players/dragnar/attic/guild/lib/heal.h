#include "/players/dragnar/guild/defs/def.h"
heal(str) {
        int amount;
        string who;
	     if(!str || sscanf(str, "%s %d", who,amount) != 2) {
        write("To heal someone: 'heal <who> <amount>'\n");
        return 1; }
	     if(amount < 1) {
	     write("Shardak forbids you to dishonor him by cheating.\n");
	     return 1; }
        if(!present(who, environment(user))) {
        write(capitalize(who)+" is not here.\n");
        return 1; }
        if(amount > usp) {
        write("You do not have enough spell points to sacrifice.\n");
        return 1; }
        if(!find_player(who)) {
        write("You can not heal something that isn't a player.\n");
        return 1; }
        find_player(who)->heal_self(amount/2);
        user->add_spell_point(-amount);
	     write("You touch "+capitalize(who)+" and heal "+find_player(who)->query_possessive()+" wounds.\n");
	     say(capname+" touches "+capitalize(who)+" and heals "+find_player(who)->query_possessive()+" wounds.\n");
        return 1; }
