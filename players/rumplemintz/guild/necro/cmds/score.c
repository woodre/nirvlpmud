#include "../DEFS"

#define BAR  "\t<----------------------------------------------------------->\n"
#define SPACE "       "

string cutstring(string str, int length){
    string str2;
    if(!length || length < 0)
	length = 20;
    str = str+"                                                                                  ";
    str2 = str[0..length];
    return str2;
}

string display_age(){
    string msg;
    int i;
    msg = "";
    i = (int)this_player()->query_age();
    if(i/43200){
	msg += i/43200 + " days ";
	i=i - (i/43200) * 43200;
    }
    if(i/1800){
	msg += i/1800 + " hours ";
	i=i - (i/1800) * 1800;
    }
    if(i/30){
	msg += i/30 + " minutes ";
	i=i - (i/30) * 30;
    }
    msg += i*2 + " seconds.";
    return msg;
}


int cmd(string str){
    int g_level, glevel;
    int *a,min_xp, c_xp, extra_xp, need_xp;
    int c_val, need_val, amount, amount2;
    string dmsg,path;
    if(!present("necro_ob", this_player()))
	return 0;
    if(str)
	if(str == "-old")
	    return 0;
    write("\n");
    write("\n");    
    write("\t<"+HIR+"Necromantic Score"+OFF+
      ">----------------------------------------->\n");
    write("\n");
    write(SPACE+BOLD+BLK+"Name: "+OFF+this_player()->short()+"\n");
    write(SPACE+BOLD+BLK+cutstring("Level:",15)+OFF+
      this_player()->query_level());
    if(this_player()->query_extra_level())
	write("+"+this_player()->query_extra_level());
    write(OFF+"\n");
    write(SPACE+BOLD+BLK+cutstring("Coins:",15)+OFF+
      cutstring((string)this_player()->query_money(),11)+OFF+BOLD+BLK+
      cutstring("Exp:",15)+OFF+
      cutstring((string)this_player()->query_exp(),11)+OFF+"\n");
    write(SPACE+BOLD+BLK+cutstring("Hit Points:", 15)+OFF+
      cutstring(this_player()->query_hp()+"/"+this_player()->query_mhp(),11)+
      OFF+BOLD+BLK+cutstring("Spell Points:",15)+OFF+
      cutstring(this_player()->query_sp()+"/"+this_player()->query_msp(),11)+
      OFF+"\n");
    write(SPACE+BOLD+BLK+cutstring("Race:",15)+OFF+
      cutstring((string)this_player()->query_race(),11)+OFF+BOLD+BLK+
      cutstring("Sex:",15)+OFF+this_player()->query_gender()+OFF+"\n");
    write(SPACE+BOLD+BLK+cutstring("Height:",15)+OFF+
      cutstring(this_player()->query_phys_at(1)+"'"+
	this_player()->query_phys_at(2)+"\"",11)+OFF+BOLD+BLK+
      cutstring("Weight:",15)+OFF+
      cutstring(this_player()->query_phys_at(3)+" lbs",11)+OFF+"\n");
    write(SPACE+BOLD+BLK+cutstring("Quest Points:",15)+OFF+
      cutstring((string)this_player()->query_quest_point(),11)+OFF+BOLD+BLK+
      cutstring("Spouse:",15)+OFF);
    if(!present("wedding ring",this_player()))
	write("--\n");
    else
	write(capitalize((string)present("wedding ring",this_player())->query_spouse())+
	  OFF+"\n");
    write(SPACE+BOLD+BLK+cutstring("Player Killer:",15)+OFF);
    if(this_player()->query_pl_k())
	write(HIR+cutstring("YES",11)+NORM);
    else
	write(cutstring("no",11)+OFF);
    write(BOLD+BLK+cutstring("Criminal:",15)+OFF);
    if(this_player()->query_crime())
	write(HIR+cutstring("YES",11)+OFF);
    else
	write(cutstring("no",11)+OFF);
    write("\n");
    write(SPACE+BOLD+BLK+"Age: "+OFF+display_age()+OFF+"\n");
    write(SPACE+BOLD+BLK+"Email: "+OFF+this_player()->query_mailaddr()+
      OFF+"\n");
    if(this_player()->query_pregnancy())
	write(SPACE+BOLD+BLK+"Pregnancy: "+HIR+
	  ((int)this_player()->query_age() - (int)this_player()->query_pregnancy())+
	  "/16200\n"+OFF);
    write("\n");
    write(SPACE+BOLD+BLK+"   Str: "+OFF+BOLD+
      cutstring((string)this_player()->query_attrib("str"),5)+OFF);
    write(BOLD+BLK+"Sta: "+OFF+BOLD+
      cutstring((string)this_player()->query_attrib("sta"),5)+OFF);
    write(BOLD+BLK+"Pie: "+OFF+BOLD+
      cutstring((string)this_player()->query_attrib("pie"),5)+OFF);
    write(BOLD+BLK+"Wil: "+OFF+BOLD+
      cutstring((string)this_player()->query_attrib("wil"),5)+OFF);
    write(BOLD+BLK+"Cha: "+OFF+BOLD+this_player()->query_attrib("cha")+OFF);
    write("\n");
    write(SPACE+BOLD+BLK+"   Mag: "+OFF+BOLD+
      cutstring((string)this_player()->query_attrib("mag"),5)+OFF);
    write(BOLD+BLK+"Luc: "+OFF+BOLD+
      cutstring((string)this_player()->query_attrib("luc"),5)+OFF);
    write(BOLD+BLK+"Int: "+OFF+BOLD+
      cutstring((string)this_player()->query_attrib("int"),5)+OFF);
    write(BOLD+BLK+"Ste: "+OFF+BOLD+
      cutstring((string)this_player()->query_attrib("ste"),5)+OFF);
    write(BOLD+BLK+"Dex: "+OFF+BOLD+this_player()->query_attrib("dex")+OFF);
    write("\n\n");
    write(SPACE+BOLD+BLK+cutstring("Guild: ",12)+OFF+
      cutstring(capitalize((string)this_player()->query_guild_name()),15)+OFF+"\n");
    write(SPACE+BOLD+BLK+"Guild Rank:  "+OFF+
      this_player()->query_guild_rank()+OFF+"\n");
    write(SPACE+BOLD+BLK+"Guild Exp:   "+OFF+
      this_player()->query_guild_exp()+OFF+"\n");
    write(SPACE+BOLD+BLK+"Guild Title: "+OFF+
      present("necro_ob", this_player())->query_guild_title()+OFF+"\n");
    if(this_player()->query_level() > 19){
	write(SPACE+BOLD+BLK+"You have no need for necromanic experience.\n"+OFF);
    } else {
	if(this_player()->query_extra_level()){
	    min_xp = (int)"/room/exlv_guild"->get_next_exp((int)this_player()->query_extra_level()-1);
	} else {
	    min_xp = (int)"/room/adv_guild"->get_next_exp((int)this_player()->query_level()-1);
	}
	c_xp = (int)this_player()->query_exp();
	extra_xp = c_xp - min_xp;
	c_val = (int)present("necro_ob", this_player())->query_val();
	glevel = (int)this_player()->query_guild_rank();
	path = PATH+"/room/rod.c";
	a = (int *)path->get_needed_xp_val(glevel);
	need_xp = a[0];
	need_val = a[1];
	amount = need_xp - extra_xp;
	if(glevel > 8){
	    write(SPACE+BOLD+
	      "You have advanced your level as far as The Realm of Death can teach you.\n"+OFF);
	    return 1;
	}
	if(amount > 0)
	    write(SPACE+BOLD+BLK+
	      "Exp needed for next Necromancer level: "+OFF+BOLD+amount+OFF+"\n");
	else 
	    write(SPACE+BOLD+
	      "You have enough experience to advance your necro level.\n"+OFF);
    }
    amount2 = need_val - c_val;
    if(amount2 > 100)
	write(SPACE+BOLD+"The Realm of Death still hungers from you...\n"+OFF);
    if((amount2 < 100) && (amount2 > 0))
	write(SPACE+BOLD+
	  "The Realm of Death looks upon your actions with interest.\n"+OFF);
    if(amount2 < 1)
	write(SPACE+BOLD+"The Realm of Death is pleased with your actions.\n"+OFF);
    write("\n"+BAR+"\n\n");
    return 1;
}
