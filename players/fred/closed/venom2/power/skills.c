#include "../defs.h"

status main(string str, object PO, object User)
{
  int i;
  TOU PO->query_color()+"Control:"+NORM+"\n");

  for(i = 0; i < (int)PO->query_control(); i ++)
  {
    if(i == 4) 
      TOU "\n");
    TOU "L"+(i+1)+"["+HIG+CONTROL[i]+NORM+"] ");
  }
  TOU "\n\n");

  TOU PO->query_color()+"Combat:"+NORM+"\n");
  for(i = 0; i < (int)PO->query_combat(); i++)
  {
    if(i == 4) 
      TOU "\n");
    TOU "L"+(i+1)+"["+HIR+COMBAT[i]+NORM+"] ");
  }
  TOU "\n\n");

  TOU PO->query_color()+"Creation:"+NORM+"\n");
  for(i = 0; i < (int)PO->query_creation(); i++)
  {
    if(i == 4) 
      TOU "\n");
    TOU "L"+(i+1)+"["+HIB+CREATION[i]+NORM+"] ");
  }
  TOU "\n\n");

  TOU PO->query_color()+"Control/Combat:"+NORM+"\n");
  
  if((int)PO->query_control() > 2 && (int)PO->query_combat() > 2)
    TOU "L3/3["+HIY+"Feed"+NORM+"] ");

  if((int)PO->query_control() > 4 && (int)PO->query_combat() > 4) 
    TOU "L5/5["+HIY+"Suffocate"+NORM+"] ");

  TOU "\n\n");

  TOU PO->query_color()+"Creation/Combat:"+NORM+"\n");

  if((int)PO->query_creation() > 4 && (int)PO->query_combat() > 4)
    TOU "L5/5["+HIY+"Block"+NORM+"] ");

  if((int)PO->query_creation() > 5 && (int)PO->query_combat() > 5) 
    TOU "L6/6["+HIY+"Dominate"+NORM+"] ");

  TOU "\n\n");

  TOU PO->query_color()+"Level Based Skills and Abilities:"+NORM+"\n");

  TOU "Level 1  - ["+HIM+"Threat"+NORM+"]  ["+HIM+"Absorb"+NORM+"]");
  TOU "  ["+HIM+"Wield"+NORM+"] ["+HIM+"Tentacles"+NORM+"]\n");

  if((int)PO->query_glvl() > 15)
    TOU "Level 16 - ["+HIM+"Lair"+NORM+"]\n"); /* ["+HIM+"Recruit"+NORM+"]\n"); */

  TOU "\n");

  TOU PO->query_color()+"Other Skills and Abilities:"+NORM+"\n");

  TOU "[mp] [sc] [save] [convert] [raise_skill] [setcolor]\n"+
      "[pklist]\n");

  TOU NORM+"For additional help on any topic type '"+HIB+"link <name>"+NORM+"'.\n\n");
  return 1;
}
