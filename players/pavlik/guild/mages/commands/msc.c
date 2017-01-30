#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("msc");
  set_name("Mage Score");
  set_color_name(HIC+"Mage Score"+NORM);
  set_rank(1);
  set_descrip(
	"Display your guild score information.\n"
  );
}


cmd(){
  int next_exp, spend;
  int level, ntime;

  level = tp->query_level();

  next_exp = ("/players/pavlik/guild/mages/inherit/advance")->rank_costs(tp->query_guild_rank()+1);
  next_exp = next_exp - tp->query_guild_exp();
  if(next_exp < 0) next_exp = 0;

  spend = ("/players/pavlik/guild/mages/inherit/advance")->rank_costs(tp->query_guild_rank());
  spend = tp->query_guild_exp() - spend;
  if(spend < 0) spend = 0;

write(CYN+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
write(NORM);

write(NORM+tp->short()+" {"+align_title()+"}\n"+NORM);
write("Level: "+tp->query_level()+"\t\t\t");
write("Extra Level: "+tp->query_extra_level()+"\n");

write("Experience: "+tp->query_exp());
if(tp->query_exp() > 999) write("\t\t"); else write("\t\t\t");
write("Quest Points: "+tp->query_quest_point()+"\n");

write("Hit Points: ");
if(tp->query_hp() < tp->query_mhp()/10) write(HIR+tp->query_hp()+NORM);
else write(tp->query_hp());
write("/"+tp->query_mhp()+"\t\t");

write("Spell Points: ");
if(tp->query_sp() < tp->query_msp()/10) write(HIR+tp->query_sp()+NORM);
else write(tp->query_sp());
write("/"+tp->query_msp()+"\n");

write("Coins: "+tp->query_money() );
if(tp->query_prestige_level() )
  write("\t\t\tSpell Damage: "+guild->query_spell_dtype_msg() );
write("\n");
write("Age: "+display_age()+"\n");
write("Intox:  "+tp->query_intoxination()*100/tp->query_max_intox()+"%  ");
write("Stuff:  "+tp->query_stuffed()*100/tp->query_max_stuff()+"%  ");
write("Soak:   "+tp->query_soaked()*100/tp->query_max_soak()+"%  ");
write("Infuse: "+tp->query_infuse()*100/tp->query_max_infuse()+"%\n");
write("Carrying: "+tp->query_pct_weight()+"% of maximum.\n");

write("\n");

write("Guild Rank: "+tp->query_guild_rank()+"\t\t\t");
write("Guild Experience: "+tp->query_guild_exp()+"\n");
write("Next Rank: "+next_exp+" exp\t\t");
write("Spendable Exp: "+spend+"\n");
write("Division: "+guild->query_divd()+"%\t\t\t");
write("Guild Donation: "+guild->query_donation()+"\n");
write("\n");

/* write(CYN+"  [Attribs]:             [Stats]:                 [Delays]:\n"+NORM); */
write(CYN+"  [Attribs]:                            [Stats]:\n"+NORM);

write(" Intel: "+show_adj("intelligence")+" Conj: "+show_adj("conjuration")+"\n");

/*
write("Next Prot:  ");
ntime = guild->query_next_casting("all") - time();
if(ntime <= 0)
  ntime = guild->query_next_casting("protection") - time();
if(ntime <= 0) write("Now.\n");
else {
  write(ntime/60+":");
  ntime = ntime - (ntime/60)*60;
  if(ntime < 10) write("0"+ntime+"\n");
  else write(ntime+"\n");
}
*/

write(" Power: "+show_adj("power")+" Ench: "+show_adj("enchantment")+"\n");

/*
write("Next Dmg :  ");
ntime = guild->query_next_casting("all") - time();
if(ntime <= 0)
  ntime = guild->query_next_casting("damage") - time();
if(ntime <= 0) write("Now.\n");
else {
  write(ntime/60+":");
  ntime = ntime - (ntime/60)*60;
  if(ntime < 10) write("0"+ntime+"\n");
  else write(ntime+"\n");
}
*/

write("Wisdom: "+show_adj("wisdom")+" Evoc: "+show_adj("evocation")+"\n");

/*
write("Next Heal:  ");
ntime = guild->query_next_casting("all") - time();
if(ntime <= 0)
  ntime = guild->query_next_casting("heal") - time();
if(ntime <= 0) write("Now.\n");
else {
  write(ntime/60+":");
  ntime = ntime - (ntime/60)*60;
  if(ntime < 10) write("0"+ntime+"\n");
  else write(ntime+"\n");
}
*/

write("  Will: "+show_adj("will power")+" Illu: "+show_adj("illusion")+"\n");

/*
write("Next Altr:  ");
ntime = guild->query_next_casting("all") - time();
if(ntime <= 0)
  ntime = guild->query_next_casting("alteration") - time();
if(ntime <= 0) write("Now.\n");
else {
  write(ntime/60+":");
  ntime = ntime - (ntime/60)*60;
  if(ntime < 10) write("0"+ntime+"\n");
  else write(ntime+"\n");
}
*/

write(pad("", 38) + " Necr: "+show_adj("necromancy")+"\n");
write("\n");
write("You have: "+guild->query_new_spell_chances()+" new spell chances.\n");
write("You have: "+guild->query_training_sessions()+" training sessions.\n");
if(tp->check_fight_area()) write("You are in a "+HIR+"PK"+NORM+" zone.\n");

write(CYN+
"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

write(NORM);
return 1;
}

display_age() {
  int i;
  string tmp;

  i = tp->query_age();

  if (i/43200) {
    tmp = (i/43200) + " days ";
    i = i - (i/43200)*43200;
  }
  if (i/1800) {
    tmp = tmp + (i/1800) + " hours ";
    i = i  - (i/1800)*1800;
  }
  if (i/30) {
    tmp = tmp + (i/30) + " minutes ";
    i = i - (i/30)*30;
  }
  tmp = tmp + (i*2) + " seconds.";

  return tmp;
}

show_adj(str) {
  int x, i;
  string tmp;

  tmp = guild->query_guild_stat(str)+"%";
  x = guild->query_guild_bonus(str);

  if(x > 0) {
    tmp += pad("",x,'+');
  }
  if(x < 0) {
    tmp += pad("",x,'-');
  }

  return pad(tmp, 30, ' ');
}

align_title() {
  int alignment;

  alignment = this_player()->query_alignment();
  if(alignment > 10 * 64) return "White Lord";
  if(alignment > 10 * 32) return "Paladin";
  if(alignment > 10 * 16) return "Crusader";
  if(alignment > 10 * 8) return "Good";
  if(alignment > 10 * 4) return "Honorable";
  if(alignment > - 10 * 4) return "Neutral";
  if(alignment > - 10 * 8) return "Malicious";
  if(alignment > - 10 * 16) return "Evil";
  if(alignment > - 10 * 32) return "Infamous";
  if(alignment > - 10 * 64) return "Black Knight";
  return "lord of evil";
}

