#include <universal.h>

#define bold(x) BOLD+x+NORM

int cmd_records()
{
 int t_exp, t_kills, t_deaths, t_age;

 if(TP->query_level() > 20)
 {
  write("Wizards do not have personal records.\n");
  return 1;
 }
 t_age = (TP->query_age() / 1800);
 t_exp = TO->query_total_exp(TP->query_exp(), TP->query_extra_level()); // add g
xp

 write(HIB+"\n\t\t:["+NORM+"Personal Records"+HIB+"]:\n\n"+NORM);
 printf(
"%s%s%s%s\n"+  // total exp, EPH
"%s%s%s%s\n"+  // big kill name, exp
"%s%s%s%s\n"+  // curr streak, alltime streak
"%s%s%s%s\n"+  // total kills, kill per hour
"%s%s%s%s\n"+  // total deaths, deaths per hour
"%s%s%s%s\n",  // total pkills, total pkdeaths
 bold("Total Exp:      "), pad(""+t_exp+"", 20),
 bold("Exp Per Hour:   "), !t_age?"0":""+(t_exp / t_age)+"."+((t_exp-((t_exp/t_a
ge)*t_age))*1000)/t_age+"",
 bold("BigKill Name:   "), pad(""+TP->query("kills.bigname")+"", 20),
 bold("BigKill Exp:    "), ""+TP->query("kills.big")+"",
 bold("Current Streak: "), pad(""+TP->query("kills.current-streak")+"", 20),
 bold("AllTime Streak: "), ""+TP->query("kills.alltime-streak")+"",
 bold("Total Kills:    "), pad(""+(t_kills=TP->query("kills.total"))+"", 20),
 bold("Kills Per Hour: "), !t_age?"0":""+(t_kills / t_age)+"."+((t_kills-((t_kil
ls/t_age)*t_age))*1000)/t_age+"",
 bold("Total Deaths:   "), pad(""+(t_deaths=TP->query("deaths.total"))+"", 20),
 bold("Death Per Hour: "), !t_age?"0":""+(t_deaths / t_age)+"."+((t_deaths-((t_deaths/t_age)*t_age))*1000)/t_age+"",
 bold("PK Kills:       "), pad(""+TP->query_pk_kills()+"", 20),
 bold("PK Deaths:      "), ""+TP->query_pk_deaths()+"");

 write("\n"+bold("Age:")+" "+calculate_age(TP)+"\n\n");
 return 1;
}

varargs int query_total_exp(int curr_exp, int level, int gxp)
{
 int i, y;
 for(i=1;i<level;i++)
  y += "/obj/player"->get_next_xp(i);
 return (curr_exp + y + gxp);
}
