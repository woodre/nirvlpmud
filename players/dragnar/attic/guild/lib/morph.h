#include "/players/dragnar/guild/defs/def.h"
morph(str) {
        int cs;
        if(!str) {
        write("What class do you want to morph into?\n");
        return 1; }
        if(str == "goro") {
        write("You grow into a Goro.\n");
        cs = 1;
        guildobj->set_guild_class(cs);
        return 1; }
        if(str == "sorcerer") {
        write("You turn into a Sorcerer.\n");
        cs = 2;
        guildobj->set_guild_class(cs);
        return 1; }
        if(str == "fighter") {
        write("You form into a fighter.\n");
        cs = 3;
        guildobj->set_guild_class(cs);
        return 1; }
        write("That is not an acceptable guild class.\n");
        return 1; }
