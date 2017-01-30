#include "../DEFS"

#define BAR  "\t<----------------------------------------------------------->\n"

string cutstring(string str, int length){
    string str2;
    if(!length || length < 0)
	length = 20;
    str = str+"                                                                                  ";
    str2 = str[0..length];
    return str2;
}

int cmd(string str){
    int g_level, glevel;
    string lev;
    object ob,me;
    ob = present("necro_ob", this_player());
    me = this_player();
    if(!present("necro_ob", this_player()))
	return 0;
    if(str == "-old")
	return 0;
    write("\n  "); 
    write("\t<"+HIR+"Necromantic Quick Score"+OFF+
      ">----------------------------------->\n");
    if(this_player()->query_pl_k())
	write("          ("+HIR+"PK"+OFF+") ");
    else
	write("          ");
    write(cutstring(this_player()->query_name()+
	" "+this_player()->query_title(),55)+" "+OFF+"\n");
    write(BOLD+BLK+"          guild rank: "+OFF+
      this_player()->query_guild_rank()+OFF+"\n");
    lev = BOLD+BLK+"level: "+OFF+this_player()->query_level();
    if(this_player()->query_extra_level())
	lev += "+"+this_player()->query_extra_level(); 
    write("          "+cutstring(lev,30));
    write(BOLD+BLK+"coins: "+
      cutstring(OFF+this_player()->query_money(),16)+OFF);
    write(BOLD+BLK+"qpt: "+OFF);
    if(this_player()->query_quest_point())
	write(cutstring((string)this_player()->query_quest_point(),10)+OFF+"  ");
    else
	write(cutstring("-- ",12));
    write("\n          ");
    write(BOLD+BLK+"hp: "+OFF+BOLD+cutstring(this_player()->query_hp()+OFF+
	"/"+this_player()->query_mhp(),15)+"  ");
    write(BOLD+BLK+"sp: "+OFF+BOLD+cutstring(this_player()->query_sp()+OFF+
	"/"+this_player()->query_msp(),15)+"  "); 
    write(BOLD+BLK+"  exp: "+OFF+cutstring((string)this_player()->query_exp(),11)+OFF+
      "\n");
    write("          ");
    if(this_player()->query_fight_area())
	write("("+HIR+"pk area"+OFF+") ");
    if(this_player()->query_crime())
	write("("+HIR+"criminal"+OFF+") ");
    if(this_player()->query_invis())
	write("("+HIR+"invis"+OFF+") ");
    if(this_player()->query_wimpy())
	write("("+HIR+"wimpy"+OFF+") ");
    write("\n          ");
    write("["+BOLD+BLK+"Intox: "+OFF+BOLD+
      (((int)this_player()->query_intoxination()*100)/((int)this_player()->query_max_intox()))+
      OFF+"%]  " );
    write("["+BOLD+BLK+"Food: "+OFF+BOLD+
      (((int)this_player()->query_stuffed()*100)/((int)this_player()->query_max_stuff()))+
      OFF+"%]  " );
    write("["+BOLD+BLK+"Soak: "+OFF+BOLD+
      (((int)this_player()->query_soaked()*100)/((int)this_player()->query_max_soak()))+
      OFF+"%]  " );
    write("["+BOLD+BLK+"Infuse: "+OFF+BOLD+(
	((int)this_player()->query_infuse()*100) / (9*((int)this_player()->query_level()/2))
      )+OFF+"%]  ");
    write("\n"+BAR+"\n");
    return 1;
}
