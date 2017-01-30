#include <ansi.h>
#define FILE "/players/boltar/test/w/gobj"

int *exp_to_level;
int tot_exp;
int glvl;

void reset(status arg)
{
  exp_to_level =({0,10000,15000,20000,25000,30000,45000,50000,55000,60000,70000,
  80000,80000,80000,80000,90000,90000,100000,100000,100000,100000,100000,100000,
  120000,120000,120000,120000,120000,120000,120000,120000,150000,150000,150000,
  150000,180000,180000,200000,200000,250000,250000,});
  if(root())
  {
    int sz;
    sz=sizeof(exp_to_level);
    while(sz--)
      tot_exp += exp_to_level[sz];
  }
  write(tot_exp);
}

int query_tot_exp() { return tot_exp; }   

int compute_compensation(int glv)
{
  int x;
  x=exp_to_level[glv];
  write("X: "+x + "\n");
  while(glv--)
    x+=exp_to_level[glv];
  return x;
}

init()
{
  string ename;
  add_action("poke","poken");
/*
  if(environment())
    restore_object("players/maledicta/closed/w/member/"+
     environment()->query_real_name());
  if(environment() == this_player())
  {
    string file;
    if(file_size(file="/players/maledicta/closed/w/member/"+
     environment()->query_real_name() + ".o") > 0)
    {
      int y;
      if(glvl < 40)
        y=(int)this_object()->compute_compensation(glvl);
      if(glvl == 40)
        y=(int)this_object()->query_tot_exp();
      if(glvl > 40)
      {
        int i;
        y=(int)FILE->query_tot_exp();
        for(i=41;i<glvl;i++)
          y+=500000;
      }
      write(HIR +"\n\t\tSorry, the guild's closed.\n\t\tMal went bonkers.\n\t\tSend problems to Vertebraker.\n\n"+NORM);
      write("Refunding: " + y + " xp\n");
      this_player()->add_exp(y);
      return 1;
    }
  }
*/
}

status mal_okay() { return 1; }
poke(str) { 
      int y;
    reset();
restore_object("players/maledicta/closed/w/member/"+str);
      if(glvl < 40)
        y=compute_compensation(glvl);
      if(glvl == 40)
       {
        y=query_tot_exp();
        write(tot_exp);
      }
      if(glvl > 40)
      {
        int i;
        y=query_tot_exp();
        for(i=41;i<glvl;i++)
          y+=500000;
      }
      if(glvl==41) {
       y=query_tot_exp() + 5000000;
      }
write("exp "+y+"\n");

}
