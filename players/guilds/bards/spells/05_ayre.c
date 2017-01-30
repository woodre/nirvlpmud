#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  string strln;
  int *attribs;
  int n,x;

  if(spell(-123, 5, 15) == -1)
    return 0;

  if(!str) 
    FAIL("You must select a target for the Ayre of Ability.\n");
  ob = present(str, environment(TP));
  if(!ob)
    FAIL("Your target must be present.\n");
  if(!ob->is_player())
    FAIL("Your target must be a player.\n");
  say(tp + " plays a short ayre on "+ POSS(TP) + " "+INST + ".\n");
  write("You play the Ayre of Ability upon " + NAME(ob) + ".\n");
  write(HIM+"  __________________________________________________\n");
  write(" |                                                  |\n");
  attribs=allocate(10);
  attribs[0] = (int)ob->query_attrib("str");
  attribs[1] = (int)ob->query_attrib("sta");
  attribs[2] = (int)ob->query_attrib("luc");
  attribs[3] = (int)ob->query_attrib("mag");
  attribs[4] = (int)ob->query_attrib("ste");
  attribs[5] = (int)ob->query_attrib("pie");
  attribs[6] = (int)ob->query_attrib("wil");
  attribs[7] = (int)ob->query_attrib("int");
  attribs[8] = (int)ob->query_attrib("dex");
  attribs[9] = (int)ob->query_attrib("cha");
  for(n=30; n>0; n-=4) {
    strln=" |"+NORM;
    for(x=0;x<10;x++)
      if(n <= attribs[x])
        strln+= MAG+"  *  ";
      else
        strln+= "     ";
    strln+=HIM+"|\n";
    write(strln);
  }

  write(" |_STR__STA__MAG__STE__INT__WIL__PIE__LUC__DEX__CHA_|\n"+NORM);
  return 1;
}
