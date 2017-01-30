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
    write("\t<"+HIR+"Necromantic Stat Score"+OFF+
      ">------------------------------------>\n");
    write(SPACE+BOLD+BLK+"\t     Str: "+OFF+BOLD+
      cutstring((string)me->query_attrib("str"),5)+OFF);
    write(BOLD+BLK+"Sta: "+OFF+BOLD+cutstring((string)me->query_attrib("sta"),5)+OFF);
    write(BOLD+BLK+"Pie: "+OFF+BOLD+cutstring((string)me->query_attrib("pie"),5)+OFF);
    write(BOLD+BLK+"Wil: "+OFF+BOLD+cutstring((string)me->query_attrib("wil"),5)+OFF);
    write(BOLD+BLK+"Cha: "+OFF+BOLD+cutstring((string)me->query_attrib("cha"),5)+OFF);
    write("\n");
    write(SPACE+BOLD+BLK+"\t     Mag: "+OFF+BOLD+
      cutstring((string)me->query_attrib("mag"),5)+OFF);
    write(BOLD+BLK+"Luc: "+OFF+BOLD+cutstring((string)me->query_attrib("luc"),5)+OFF);
    write(BOLD+BLK+"Int: "+OFF+BOLD+cutstring((string)me->query_attrib("int"),5)+OFF);
    write(BOLD+BLK+"Ste: "+OFF+BOLD+cutstring((string)me->query_attrib("ste"),5)+OFF);
    write(BOLD+BLK+"Dex: "+OFF+BOLD+cutstring((string)me->query_attrib("dex"),5)+OFF);
    write("\n");
    write(BAR+"\n");
    return 1;
}
