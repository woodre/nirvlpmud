#include "/players/dragnar/guild/defs/def.h"
score() {
	int ex_lv;
    int intox_level;
     string tmp;
      int tmpp;
	ex_lv = this_player()->query_extra_level();
	if(this_player()->query_ghost() > 0) {
        write("You are in an immaterial state with no scores.\n");
        return 1;
    }
    write("\n");
	write("[------------------------------------------------------------------------------]\n");
	write(this_player()->short()+"\n");
    write("Level: "+this_player()->query_level());
    if(!ex_lv) write("\n");
	if(ex_lv) write("\t\t\tExtra Level: "+ex_lv+"\n");
   write("Coins: "+this_player()->query_money()+"          \t\tExperience: "+this_player()->query_exp()+"\n");
    write("Hit points: "+uhp+"/"+umhp+"     ");
    write("\t");
    write("Spell points: "+usp+"/"+umsp+"\n");
    write("Quest points: "+this_player()->query_quest_point()+"\n");
	this_player()->show_age();
	write("\n");
	write("Guild Rank: "+this_player()->query_guild_rank()+"\n");
	write("Guild Exp: "+this_player()->query_guild_exp()+"\n");
	if(guildobj->query_guild_class() == 1) 
	write("Guild Class: Goro\n");
	if(guildobj->query_guild_class() == 2)
	write("Guild Class: Sorcerer\n");
	if(guildobj->query_guild_class() == 3) 
	write("Guild Class: Fighter\n");
	if(guildobj->query_color_flag() == 1)
	write("Guild Color: ON\n");
	if(guildobj->query_color_flag() == 0) 
	write("Guild Color: OFF\n");
	write("\n");
    if(this_player()->query_pregnancy()) {
    tmpp=this_player()->show_age()-this_player()->query_pregnancy();
    write("You are Pregnant ("+tmpp+" / 16200)\n");
    }
    if (this_player()->query_hunted() && call_other(this_player()->query_hunted(), "query_name"))
        write("You are hunted by " + call_other(this_player()->query_hunted(), "query_name") + ".\n");
	if(this_player()->query_intoxination()) {
	intox_level = (this_player()->query_level() + 4) / this_player()->query_intoxination();
        if (intox_level == 0)
            write("You are in a drunken stupor.\n");
        else if (intox_level == 1)
            write("You are roaring drunk.\n");
        else if (intox_level == 2)
            write("You are somewhat drunk.\n");
        else if (intox_level == 3)
            write("You are quite tipsy.\n");
        else
            write("You are slightly tipsy.\n");
    }
    if (this_player()->query_stuffed() || this_player()->query_soaked())
    {
        tmp = "You are ";
 
        if (this_player()->query_stuffed())
        {
            tmp += "satiated";
 
	if(this_player()->query_soaked())
                tmp += " and ";
            else
                tmp += ".\n";
        }
 
        if (this_player()->query_soaked())
            tmp += "not thirsty.\n";
 
        write(tmp);
    }
 
	write("[------------------------------------------------------------------------------]\n");
    write("\n");
    return 1;
}
