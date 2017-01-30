/* by illarion@nirvana
 * based on who command in player.c by various people
 * reworked by verte
 */

#include <ansi.h>

#define BAR ""+BLU+"<------------------------------------------------------------------->"+NORM+"\n"

add_zero(arg) {
  arg=""+arg;
  if(strlen(arg)==1)
    arg="0"+arg;
  return arg;
}

whop(arg) {
  int c;
  int lev,xlev,invis;
  int mylev,myxlev;
  object *ppl;
  object me;
  string wizes, players;
  int x,s,count1,count2;
  string a;
  string fl;
  string line,shrt;
  string *ll;
  int cc, cd;

  ppl=users();
  s=sizeof(ppl);
  me=this_player();
  mylev=me->query_level();
  myxlev=me->query_extra_level();
  write("\n");
  write(BAR);
  write(HIW);
  write("\t\t\t  n  i  r  v  a  n  a\n");
  write(NORM);
  write("\t\t  ...since 1991: still the original.\n");
  write(BAR);
  wizes=players="";
  for(x=0;x<s;x++) {
    lev=ppl[x]->query_level();
    invis=ppl[x]->query_invis();
    shrt=ppl[x]->short();
/*
    if(!shrt || lev < 1 || lev > 20 || ppl[x]->is_testchar())
*/
    if(!shrt || lev < 1)
      continue;
    if(lev > 20)
    {
      if(lev > 99)
        wizes += "  "+BLU+"[ "+HIW+"ADMIN"+NORM+BLU+" ]"+NORM;
      else
        wizes += "   "+BLU+"[ "+NORM+"Dev"+BLU+" ]"+NORM+" ";
      wizes += " "+shrt+"\n";
      count2++;
    }
    else
    {
      if(xlev = (int)ppl[x]->query_extra_level())
        line=BLU+" {"+NORM+" "+lev+"+"+pad(add_zero(xlev),3)+"";
      else
        line=BLU+" {"+NORM+"   "+pad(""+lev,2)+"  ";
      line+=BLU+"}"+NORM+" "+shrt;
      count1++;
      players += line+"\n";
    }
  }
  write(wizes);
  write(players);
  write(BAR);
  write("    " + count1 + " player" + (count1 == 1 ? "" : "s" ) +
        " total\n");
  write("Type \"devs\" for a list of developers.\n");
  return 1;
}
