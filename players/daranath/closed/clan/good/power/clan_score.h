/* Version 1.0 of the Clan Score listing   */

clan_score() {

object ob;

ob = present("clan_ob",this_player());
write(HIW+"<> - <> - <> - <> - <> - <> - <"+HIC+"LION"+HIW+"> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
write(tp->short()+"\n");
if(tp->query_level() > 18) {
write("Level: "+tp->query_level()+" + "+tp->query_extra_level());
} else {
write("Level: "+tp->query_level());
}
write("      ");
  write("Experience: "+tp->query_exp()+"\n");
write("Gold Coins: "+tp->query_money()+"\n");
write("\n\n");
 write("Str: "+tp->query_attrib("str")+"   ");
 write("Sta: "+tp->query_attrib("sta")+"   ");
 write("Mag: "+tp->query_attrib("mag")+"   ");
 write("Ste: "+tp->query_attrib("ste")+"   ");
write("\n");
 write("Luc: "+tp->query_attrib("luc")+"   ");
  write("Int: "+tp->query_attrib("int")+"   ");
 write("Wil: "+tp->query_attrib("wil")+"   ");
 write("Pie: "+tp->query_attrib("pie")+"   ");
write("\n\n");
write("Hit Points: "+HIR+tp->query_hp()+NORM+WHT+"/"+
    HIR+tp->query_mhp()+NORM+"   ");
write("Spell Points: "+HIY+tp->query_sp()+NORM+WHT+"/"+
    HIY+tp->query_msp()+NORM+"\n");
write(HIC+"Stuff"+NORM+": "+HIW+tp->query_stuffed()*100/(tp->query_level()*8)+NORM+"%     ");
write(HIC+"Soak"+NORM+":  "+HIW+tp->query_soaked()*100/(tp->query_level()*8)+NORM+"%     ");
write(HIC+"Intox"+NORM+": "+HIW+tp->query_intoxination()*100/(tp->query_level()+3)+NORM+"%\n");
write("\n");
tp->show_age();
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
return 1; 
}

