/*
 *  A new score ability for the Bards of Ryllian
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

score_new()  {
string temp, temp1, temp2;
int tmp1, preg;
object obj;

write("\n");
write("* Bards Guild\n");
write("* "+TP->query_pretitle()+" "+tp+" "+TP->query_title()+"\n");
write("* Guild Level "+TO->query_bard_level()+"\n");
write("*\n");
write("* Level: "+pad(TP->query_level(),33)+" Strength: "+TP->query_attrib("str")+"\n");
write("* Ex_Level: "+pad(TP->query_extra_level(),30)+" Stamina: "+TP->query_attrib("sta")+"\n");
write("* Hit Points:   "+pad(TP->query_hp()+"/"+TP->query_mhp(),26)+" Magic: "+TP->query_attrib("mag")+"\n");
write("* Spell Points: "+pad(TP->query_sp()+"/"+TP->query_msp(),26)+" Intelligence: "+TP->query_attrib("int")+"\n");
write("* Experience:   "+pad(TP->query_exp(),26)+" Will Power: "+TP->query_attrib("wil")+"\n");
write("* Golden Coins: "+pad(TP->query_money(),26)+" Piety: "+TP->query_attrib("pie")+"\n");
write("* Quest Points: "+pad(TP->query_quest_point(),26)+" Stealth: "+TP->query_attrib("ste")+"\n");
write("* Gender: "+pad(TP->query_gender(),32)+" Luck: "+TP->query_attrib("luc")+"\n");

if(TP->query_pregnancy()) { preg = TP->query_pregnancy();
write("* Pregnancy: "+preg+" / 16200\n"); }

write("*\n");
write("* Intox: "+TP->query_intoxination()+"               Stuffed: "+TP->query_stuffed()+"         Soaked: "+TP->query_soaked()+"\n");

temp = TP->query_wimpy();
 if(temp == 1) { temp = "yes";  } else { temp = "no "; }

temp1 = TP->query_crime();
 if(temp1 == 1) { temp1 = "yes";  } else { temp1 = "no "; }

obj = present("base_obj",TP);
  if(!obj)  {  temp2 = "none"; }  else  { temp2 = obj->query_newguild();  }
  
write("* Wimpy: "+temp+"             Crime: "+temp1+"         Mini Guild: "+temp2+"\n");
write("*\n");
write("* Age: ");  check_age();  write("*\n");

write("* You are an active member of the Bards Guild of Ryllian.\n"+
      "* Type < lore > to get an extensive help file, or check \n"+
      "* the bardic web page at www.ryllian.com/saber/bard.\n");
write("\n");
return 1;
}
