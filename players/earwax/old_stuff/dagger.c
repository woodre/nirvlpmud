
id(str) { return str == "dagger"; }
short(){  return "Dagger of Assassination"; }
long() {
     write("An object all Godfathers must have. It does neat things, like:\n");
     write("apromote <player> <level>   promote player in guild\n");
     write("aexp <player> <amount>      set player's guild exp\n");
     write("reg <player>                forces player to 'register'\n");
     write("arank <player>              shows a player's guild stats\n");
     write("expell <player>             expell player from guild\n");
     write("self_recruit                gets you back in after a crash\n");
     write("NOTE: for apromote, use a number appropriate for the level...\n");
     write("e.g. to promote someone to senior assassin, apromote <player> 2\n");

}
get() { return 1; }
query_auto_load(){
/*
     return "/players/deathmonger/ASSASSIN/dagger:";
*/
     return "/players/silent/equip/dagger:";
}

init(){
     add_action("apromote","apromote");
     add_action("aexp","aexp");
     add_action("reg","reg");
     add_action("arank","arank");
     add_action("expell","expell");
     add_action("self_recruit","self_recruit");
}

apromote(str){
     object guild;
     string who;
     int amount;
     if(sscanf(str, "%s %d", who, amount) == 2){
     guild = present("license", find_player(who));
     if(!guild){
       write("No such assassin logged on.\n");
       return 1;
     }
     guild->set_guild_quest(amount);
     write(who+" set to level "+amount+".\n");
     guild->set_guild_name();
     return 1;
     }
}


self_recruit(){
     object license;
     license = clone_object("players/deathmonger/ASSASSIN/license");
     license->set_quest(4);
     license->set_rank();
     move_object(license, this_player());
     write("You have restored yourself in the guild.\n");
     return 1;
}
aexp(str){
     object guild;
     string who;
     int amount;
     if(sscanf(str, "%s %d", who, amount) == 2){
       guild = present("license", find_player(who));
     if(!guild){
       write("No such assassin logged on.\n");
       return 1;
     }
     guild->set_guild_exp(amount);
     write(who+"'s guild exp set at "+amount+".\n");
     return 1;
    }
}

reg(str){
     object guild;
     guild = present("license", find_player(str));
     if(!guild){
       write("No such assassin logged on.\n");
       return 1;
     }
     command("register", find_player(str));
     write("Done.\n");
     return 1;
}

arank(str){
     object guild;
     guild = present("license", find_player(str));
     if(!guild){
       write("No such assassin logged on.\n");
       return 1;
     }
write(capitalize(str)+"\n");
write("Level: "+find_player(str)->query_level()+"\n");
write("Assassin level: "+guild->query_guild_name()+"\n");
write("Guild exp: "+guild->query_guild_exp()+"\n");
write("Money: "+find_player(str)->query_money()+"\n");
return 1;
}

expell(str){
     object guild;
     guild = present("license", find_player(str));
     if(!guild){
       write("No such assassin logged on.\n");
       return 1;
     }
     destruct(guild);
     find_player(str)->set_guild_exp(0);
     write("You have expelled "+str+" from the guild.\n");
     tell_object(find_player(str),
     "You have been expelled from the guild.  Now you've got problems.\n");
     return 1;
}
