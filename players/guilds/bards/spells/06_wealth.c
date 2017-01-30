#include "/players/guilds/bards/def.h"

status main(string str) {
  string temp3, how_rich;
  int a,x;
  object ob;

  if (spell(-200, 6, 10) == -1)
    return 0;
  if (!str) 
    FAIL("You must pick a target for the Rhythm of Wealth.\n");
  ob = present(str, environment(TP));
  if (!ob)
    FAIL("Your target is not here.\n");
  if(!living(ob))
    FAIL("You need a living target for the Rhythm of Wealth.\n");

  say(tp + " plays a compelling rhythm on "+POSS(TP)+" "+INST+".\n");
  write("You play the rhythm of wealth upon your " + INST + ".\n"
       +"You sense the contents of "+NAME(ob)+"'s purse.\n");
  a = (int)ob->query_money();
  write(HIW+"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  write("$ ");
  temp3=HIY;
  for(x=0;x<a;x+=1250)
    temp3+="*";
  for(;x<=80000;x+=1250)
    temp3+=" ";
  write(temp3);
  write(HIW+"$\n");
  write("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"+NORM);
  call_other(TP, "add_spell_point", -10);
  return 1;
}
