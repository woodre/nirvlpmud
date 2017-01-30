#include "../defs.h"

status main(string str, object PO, object User)
{
  TOU" Name: ");

  if(User->query_pretitle()) 
    TOU User->query_pretitle()+" ");

  TOU CAP((string)User->QN)+" ");

  if(User->query_title())
    TOU USER->query_title()+" ");

  TOU "("+User->query_al_title()+")  [L: "+User->QL+"");

  if(User->QEL)
  {
    TOU "+"+User->QEL+"]  [GLVL: "+HIM+PO->query_glvl()+NORM+"]  ");
  }
  else
  {
    TOU "]  [GLVL: "+HIM+PO->query_glvl()+NORM+"] ");
  }

  if(User->query_invis()) 
    TOU GRN+" - "+BOLD+"Camouflaged"+NORM+GRN+" - "+NORM+"\n\n");
  else 
    TOU "\n\n");

  TOU " Strength  ["+STR+"]\t\t\tIntelligence ["+INT+"]\n"+
      " Stamina   ["+STA+"]\t\t\tWillpower    ["+WIL+"]\n"+
      " Stealth   ["+STE+"]\t\t\tPiety        ["+PIE+"]\n"+
      " Luck      ["+LUC+"]\t\t\tMagic        ["+MAGIC+"]\n"+
      " Dexterity ["+DEX+"]\t\t\tCharisma     ["+CHA+"]\n\n");

  TOU BLU+" HP"+NORM+" "+BOLD+"("+NORM+HIB+User->query_hp()+NORM+BOLD+"/"+NORM+HIB+User->query_mhp()+NORM+BOLD+")"+NORM+"\t\t");

  if(PO->query_glvl() > 15)
  {
    TOU "Guild Exp ["+PO->query_color()+"Maxed"+NORM+"]\n");
  }
  else
  {
    TOU "Guild Exp ["+PO->query_color()+PO->query_gxp()+NORM+"]\n");
  }

  TOU RED+" SP"+NORM+BOLD+" ("+NORM+HIR+User->query_sp()+NORM+BOLD+"/"+NORM+HIR+User->query_msp()+NORM+BOLD+")"+NORM+"\t\t");
  TOU "Guild Lvl ["+PO->query_color()+PO->query_glvl()+NORM+"]\n");
  TOU " Food["+BOLD+(int)User->query_stuffed()*100/((int)User->query_max_stuff())+NORM+"%] "+
      " Soak["+BOLD+(int)User->query_soaked()*100/((int)User->query_max_soak())+NORM+"%] "+
      " Intox["+BOLD+(int)User->query_intoxination()*100/((int)User->query_max_intox())+NORM+"%]\n");

  TOU " ___________________________________________________\n");
	
  TOU "Experience ["+User->query_exp()+"]     Coins ["+User->query_money()+"]  \n\n");

  if(User->query_quest_point())
    TOU "QPS        ["+User->query_quest_point()+"]\n");
  TOU "\n");
	
  User->show_age();
  TOU "\n");
	
  User->check_fight_area();
  if(User->query_fight_area())
  {
    TOU HIR+"PK Area"+NORM+"       ");
  }
  else
  {
    TOU HIB+"NON-PK Area"+NORM+"   ");
  }

  TOU "         MP: "+BOLD+PO->query_mp()+NORM+"\\"+BOLD+PO->query_max_mp()+NORM+"\n");
  TOU "Stored Coins/Matter/Sps: "+PO->query_stored_mon()+", "+PO->query_stored_mp()+", "+PO->query_stored_sp()+"\n");

  TOU "For a list of abilities type '"+HIM+"skills"+NORM+"' & '"+HIM+"link"+NORM+"' for help.\n");
  return 1;
}
