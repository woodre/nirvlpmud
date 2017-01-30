/* Version 1.0 of the Necromancer Score Listing */

necro_score() {

int g_level, glevel;
int min_xp, c_xp, extra_xp, need_xp;
int c_val, need_val, amount, amount2;
string dmsg;
object ob;

ob = present("necro_ob",this_player());

write(tp->short()+"\n");
write("Race: "+tp->query_race()+"\n");
write(pad("Level: "+tp->query_level(), 25));
write("Extra Level: "+tp->query_extra_level()+"\n");
write(pad("Coins: "+tp->query_money(), 25));
write("Experience: "+tp->query_exp()+"\n");
write(pad("Hit Points: "+tp->query_hp()+"/"+
    tp->query_mhp(), 25));
write("Spell Points: "+tp->query_sp()+"/"+
    tp->query_msp()+"\n");
write("Quest Points: "+tp->query_quest_point()+"\n");
tp->show_age();
write("\n");
write(pad("Str: "+tp->query_attrib("str"), 15));
write(pad("Wil: "+tp->query_attrib("wil"), 15));
write("Ste: "+tp->query_attrib("ste")+"\n");
write(pad("Mag: "+tp->query_attrib("mag"), 15));
write(pad("Int: "+tp->query_attrib("int"), 15));
write("Luc: "+tp->query_attrib("luc")+"\n");
write(pad("Sta: "+tp->query_attrib("sta"), 15));
write("Pie: "+tp->query_attrib("pie")+"\n\n");

if(present("ac_ob",this_player())){
  write("You are currently in Wraithform.\n\n"); }
write("Necromancer Level: "+ob->query_g_level()+"\n");
write("Necromancer Title: "+ob->query_guild_title()+"\n");
  if(tp->query_extra_level() > 21) { return 1; }

  if(tp->query_extra_level())
  min_xp = call_other("/room/exlv_guild","get_next_exp",tp->query_extra_level()-1);
else
  min_xp = call_other("/room/adv_guild","get_next_exp",tp->query_level()-1);
  c_xp = tp->query_exp();
  extra_xp = c_xp - min_xp; 
  c_val = ob->query_val();
  glevel = tp->query_guild_rank();
  switch(glevel) {
   case 1: need_xp = 20000; need_val = 100; break;
   case 2: need_xp = 25000; need_val = 200; break;
   case 3: need_xp = 25000; need_val = 400; break;
   case 4: need_xp = 50000; need_val = 550; break;
   case 5: need_xp = 75000; need_val = 750; break;
   case 6: need_xp = 100000; need_val = 850; break;
   case 7: need_xp = 150000; need_val = 1000; break;
   case 8: need_xp = 150000; need_val = 1250; break;
   case 9: need_xp = 300000; need_val = 1250; break;
   case 10: need_xp = 1500000; need_val = 5000; break;
}
  amount = need_xp - extra_xp;
  if(amount > 0) {
write("Exp needed for next Necromancer level: "+amount+"\n");
  } else {
write("You have enough experience to advance your necro level.\n");
}
  amount2 = need_val - c_val;
  if(amount2 > 100) {
write("The Realm of Death still hungers from you...\n"); }
  if((amount2 < 100) && (amount2 > 0)) {
write("The Realm of Death looks upon your actions with interest.\n"); }
  if(amount2 < 1) {
write("The Realm of Death is pleased with your actions.\n");
}
return 1; 
}
