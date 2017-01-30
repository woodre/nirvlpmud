/* Version 1.0 of the Bone Marketeer Status listing, taken from the
   old necromancer score      -Dar  */

market_score() {

object ob;

ob = present("market_ob",this_player());
write(WHT+"<---------------------------------------------------------->"+NORM+"\n");
 write("          "+HIR+this_player()->query_name()+" the Bone Marketeer"+NORM+"\n");
write(WHT+"<---------------------------------------------------------->"+NORM+"\n");
write(pad("Level: "+tp->query_level()+" + "+tp->query_extra_level(), 25));
 write("Experience: "+tp->query_exp()+"\n");
write("Race: "+tp->query_race()+"\n");
/*
write("Alignment: "+tp->alignment()+"\n");
*/
write(pad("Hit Points: "+tp->query_hp()+"/"+
    tp->query_mhp(), 25));
write("Spell Points: "+tp->query_sp()+"/"+
    tp->query_msp()+"\n");
write("Quest Points: "+tp->query_quest_point()+"\n");
write("\n");
write(pad("Str: "+tp->query_attrib("str"), 12));
write(pad("Int: "+tp->query_attrib("int"), 15));
write("Stuff: "+HIW+tp->query_stuffed()*100/(tp->query_level()*8)+NORM+"%\n");
write(pad("Mag: "+tp->query_attrib("mag"), 12));
write(pad("Wil: "+tp->query_attrib("wil"), 15));
write("Soak:  "+HIW+tp->query_soaked()*100/(tp->query_level()*8)+NORM+"%\n");
write(pad("Sta: "+tp->query_attrib("sta"), 12));
write(pad("Pie: "+tp->query_attrib("pie"), 15));
write("Intox: "+HIW+tp->query_intoxination()*100/(tp->query_level()+3)+NORM+"%\n");
write(pad("Luc: "+tp->query_attrib("luc"), 12));
write("Ste: "+tp->query_attrib("ste")+"\n");
write("\n");
write(YEL+"Gold Coins"+NORM+": "+tp->query_money()+"\n"); 
write(HIW+"Market Credits"+NORM+": Current: "+HIW+ob->query_current()+NORM+"\n");
write(HIW+"              "+NORM+"  Career:  "+HIW+ob->query_total()+NORM+"\n");
write("\n");

write("Exp Gained - Current:   "+HIW+ob->query_expgain()+NORM+" exp\n");
write("Biggest Career Kill:    "+HIW+ob->query_bigkill()+NORM+" exp\n");
tp->show_age();
write(WHT+"<---------------------------------------------------------->"+NORM+"\n");
return 1; 
}

