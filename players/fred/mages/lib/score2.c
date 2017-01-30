#include "/players/fred/mages/defs.h"

cmd_score2(){
 string name;
 int soak, stuff, tox, money, exp, preg;
 int msoak, mstuff, mtox;
 int hp, mhp, sp, msp, gexp, glvl;
  name = TP->short();
  tox = TP->query_intoxination();
  stuff = TP->query_stuffed();
  soak = TP->query_soaked();
  mtox = TP->query_max_intox();
  mstuff = TP->query_max_stuff();
  msoak = TP->query_max_soak();
  money = TP->query_money();  
  exp = TP->query_exp();
  gexp = TP->query_guild_exp();
  glvl = TP->query_guild_rank();
  hp = TP->query_hp();
  sp = TP->query_sp();
  mhp = TP->query_mhp();
  msp = TP->query_msp();
  write(name+"\n");
  write(pad("Coins: "+money, 35));
  write("Quest points: "+TP->query_quest_point()+"\n");
  write(pad("Level: "+LVL+"+"+XLVL, 35));
  write("Guild Level: "+glvl+"\n");
  write(pad("Exp: "+exp, 35));
  write("Guild Exp: "+gexp+"\n");
  write(pad("Hit Points: "+hp+"/"+mhp, 35));
  write("Spell Points: "+sp+"/"+msp+"\n");
  if(LVL < 20) next_expp();
  if(LVL < 20) next_gexpp();
  TP->show_age();
  write("Time: "+ctime(time())+"\n");
  write(BOLD+BLK+"Intox ("+NORM+(tox*100)/mtox+BOLD+BLK+"%)   "+
      "Soak ("+NORM+(soak*100)/msoak+BOLD+BLK+"%)   "+
      "Stuff ("+NORM+(stuff*100)/mstuff+BOLD+BLK+"%)   "+
      "Infuse ("+NORM+TP->query_infuse()*100/TP->query_infuse_limit()+BOLD+BLK+"%)\n\n"+YEL);
  write(pad("  Str: "+STR, 12));
  write(pad("Sta: "+STA, 10));
  write(pad("Mag: "+MAGIC, 10));
  write(pad("Ste: "+STE, 10));
  write("Luc: "+LUC+"\n");
  write(pad("  Dex: "+DEX, 12));
  write(pad("Cha: "+CHA, 10));
  write(pad("Int: "+INT, 10));
  write(pad("Wil: "+WIL, 10));
  write("Pie: "+PIE+NORM+"\n\n");

  if(TP->query_pregnancy()){
    preg = TP->query_age() - TP->query_pregnancy();
  if(preg > 4000)
  write("Pregnant: "+preg*100/16300+"%\n");
  }
  write("\nCurrent Area Creator: ");
    if(creator(environment(TP))) write(capitalize(creator(environment(TP))));
    else write("None");
    write(".\n");
  write("Pk Area: ");
  TP->check_fight_area();
  if(TP->query_fight_area()) write("Yes.\n");
  else write("No.\n");
    return 1;
  }
  
next_expp(){
 int woo, foo, blah, amt, check;
 if(XLVL < 1)  
   woo = call_other("room/adv_guild","get_next_exp",LVL-1);
 if(XLVL > 0)
   woo = call_other("room/exlv_guild","get_next_exp",XLVL-1);
 if(XLVL < 1)  
   foo = call_other("room/adv_guild","get_next_exp",LVL);
 if(XLVL > 0)
   foo = call_other("room/exlv_guild","get_next_exp",XLVL);
 if(XLVL < 1)
   blah = TP->query_exp() - call_other("room/adv_guild","get_next_exp",LVL-1);
 if(XLVL > 0)
   blah = TP->query_exp() - call_other("room/exlv_guild","get_next_exp",XLVL-1);
 if(LVL == 19 && XLVL < 1){
   check = TP->query_exp();
   foo = 2500000;
   woo = 2000000;
   blah = (check-woo); 
   }
 if(blah > (foo-woo)){
  write(pad("Exp. to Level: None", 35)); return 1;}
 amt = ((foo-woo)-blah);
 write(pad("Exp. to Level: "+amt, 35));
 return 1;
 }

next_gexpp(){
 int amt, foo, pop, exp, k;
 exp = TP->query_exp();
 k = TP->query_guild_rank();
 switch(k){
  case 0: amt = 50000; break;
  case 1: amt = 150000; break;
  case 2: amt = 750000; break;
  case 3: amt = 1500000; break;
  case 4: amt = 2500000; break;
  }
 if(TP->query_guild_rank() == 5){
  write("Exp. to Glevel: Maxxed\n"); return 1;}
 if(XLVL < 1)
   foo = call_other("room/adv_guild","get_next_exp",LVL-1);
 if(XLVL > 0)
   foo = call_other("room/exlv_guild","get_next_exp",XLVL-1); 
 if(amt < (exp-foo)){
   write("Exp. to Glevel: None\n"); return 1;}
 pop = (amt-(exp-foo));
 write("Exp. to Glevel: "+pop+"\n");
 return 1;
}
