#include "../defs.h"

status main(string str, object PO, object User)
{
  int amt;
  if(GHOST) return 0;
  if(!PO->query_venomed())
  {
    TOU CAP((string)PO->query_symbiote())+" hisses, \"We are not changed...\"\n");
    return 1;
  }

/********* Link help ***********/
  if(!str)
  {
    if(User->QL < 8) return 0; 
    if(User->QL > 7)
    {
      TOU ""+HIW+""+CAP((string)PO->query_symbiote())+""+NORM+" whispers into your mind,\n"+
          "  'I can help you do the following abilities..'\n");
      
      TOU "       "+HIB+"Flee..."+NORM+"\n");
    }
    if(User->QL > 7 && PO->query_hardened())
    {
      TOU "       "+HIB+"Harden..."+NORM+" "+HIR+"(Active)"+NORM+"\n");
    }
    else if(User->QL > 7)
    {
      TOU "       "+HIB+"Harden..."+NORM+"\n");
    }         
    
    if(User->QL > 9 && PO->query_regen())
    {
      TOU ""+HIB+"       Regenerate..."+NORM+" "+HIR+"(Active)"+NORM+"\n");
    }
    else if(User->QL > 9)
    {
      TOU "       "+HIB+"Regenerate..."+NORM+"\n");
    }

    if(User->QL > 10 && (string)PO->query_shapetype() == "sword")
    {
      TOU "       "+HIB+"Sword..."+NORM+" "+HIR+"(Active)"+NORM+"\n");
    }
    else if(User->QL > 10)
    {
      TOU "       "+HIB+"Sword..."+NORM+"\n");
    }
    if(User->QL > 10 && (string)PO->query_shapetype() == "spear")
    {
      TOU "       "+HIB+"Spear..."+NORM+" "+HIR+"(Active)"+NORM+"\n");
    }
    else if(User->QL > 10)
    {
      TOU "       "+HIB+"Spear..."+NORM+"\n");
    }
    if(User->QL > 10 && (string)PO->query_shapetype() == "maul")
    {
      TOU "       "+HIB+"Maul..."+NORM+" "+HIR+"(Active)"+NORM+"\n");
    }
    else if(User->QL > 10)
    {
      TOU "       "+HIB+"Maul..."+NORM+"\n");
    }
    if(User->QL > 10 && (string)PO->query_shapetype() == "axe")
    {
      TOU "       "+HIB+"Axe..."+NORM+" "+HIR+"(Active)"+NORM+"\n");
    }
    else if(User->QL > 10)
    {
      TOU "       "+HIB+"Axe..."+NORM+"\n");
    }
    if(User->QL > 10 && (string)PO->query_shapetype() == "shield")
    {
      TOU "       "+HIB+"Shield..."+NORM+" "+HIR+"(Active)"+NORM+"\n");
    }
    else if(User->QL > 10)
    {
      TOU "       "+HIB+"Shield..."+NORM+"\n");
    }
    if(User->QL > 10)
    {
      TOU "       "+HIB+"Noshape..."+NORM+"\n");
    }

    if(User->QL > 18 && PO->query_burnoff())
    {
      TOU "       "+HIB+"Burnoff..."+NORM+" "+HIR+"(Active)"+NORM+"\n");
    }
    else if(User->QL > 18)
    {
      TOU "       "+HIB+"Burnoff..."+NORM+"\n");
    }

    TOU "\n"+NORM+""+HIW+"You can "+HIB+"link <power>"+HIW+" to perform any of the above abilities."+NORM+"\n");         
    return 1;
  }       

/********** Flee *************************/
  if(str == "flee" || str == "Flee")
  {

    object ob, altob;                             
    
    ob = (object)User->query_attack();     
    altob = (object)User->query_alt_attack();

    if(User->QL < 8) return 0;
    if(User->query_sp() < 15)
    {
      TOU "Your symbiotic link is too weak for that.\n");
      return 1;
    }	
    if(!ob)
    {
      TOU "You can only do this in combat!\n");
      return 1; 
    }

    TRU ""+User->QN+" snarls and flees from combat!\n\n", ({ User }));                 
  
    if(altob)
    {
      altob->stop_fight();    
      User->stop_fight();
      altob->stop_hunter();
      User->stop_hunter();
    }               
    if(ob)
    {        
      ob->stop_fight();
      User->stop_fight();   
      ob->stop_hunter();
      User->stop_hunter();
    }
    if(altob)
    {
      altob->stop_fight();    
      User->stop_fight();
      altob->stop_hunter();
      User->stop_hunter();
    }               
    if(ob)
    {
      ob->stop_fight();
      User->stop_fight();   
      ob->stop_hunter();
      User->stop_hunter();
    }
  
    TOU "You turn and flee from combat!\n");
    User->add_spell_point(-15);
    return 1;
  }
/***************************************************/



/********** Harden *********************************/
  if(str == "harden")
  {

    if(User->QL < 8) return 0;
    if(User->query_sp() < 10 || PO->query_mp() < 1)
    {
      TOU "Your symbiotic link is too weak for that.\n");
      return 1;
    }	
    if(!PO->query_hardened() && PO->query_no_harden())
    {
      TOU "You cannot harden again so soon!\n");
      return 1;
    }	
    if(PO->query_hardened())
    {
      TRU User->QN+"'s body softens into a smooth black skin...\n");
      PO->set_hardened(0);
      return 1;
    }      

    TRU User->QN+" concentrates briefly.\n"+
        ""+User->QN+"'s body hardens into a unbreakable armor.\n");
    PO->set_hardened(1);
    PO->add_no_harden(100);
    PO->add_mp(-1);
    User->add_spell_point(-10);
    return 1;
  }
/***************************************************/


/********** Sword, Spear, Axe, Shield, Noshape *****/
/***************************************************/
  if(str == "sword" || str == "maul" || str == "spear" ||
     str == "axe" || str == "shield" || str == "noshape")
  {
    if(User->QL < 11) return 0;
    amt = 50;
    if(PO->query_has_changed()) amt = 20;    
    if(User->query_sp() < 50 || PO->query_mp() < amt)
    {
      TOU "Your symbiotic link is too weak for that.\n");
      return 1;
    }	
    if(PO->query_shaped())
    {
      TOU "You concentrate and feel your arm return to normal...\n");
      PO->set_shaped(0);
      PO->set_shapetype(0);
      return 1;
    }

    PO->set_shaped(1);
    PO->set_has_changed(1);
    PO->add_mp(-amt);
    User->add_spell_point(-50);
  
    if(str == "sword")
    {
      TOU "You concentrate briefly and feel the symbiote reshape itself into a razor sharp sword!\n");
      PO->set_shapetype("sword");
    }
    if(str == "maul")
    {
      TOU "You concentrate briefly and feel the symbiote reshape itself into a powerful maul!\n");
      PO->set_shapetype("maul");
    }
    if(str == "spear")
    {
      TOU "You concentrate briefly and feel the symbiote reshape itself into a long spear!\n");
      PO->set_shapetype("spear");
    }
    if(str == "shield")          
    {
      TOU "You concentrate briefly and feel the symbiote reshape itself into a huge shield!\n");
      PO->set_shapetype("shield");
    }
    if(str == "axe")
    {
      TOU "You concentrate briefly and feel the symbiote reshape itself into a huge battle axe!\n");
      PO->set_shapetype("axe");
    }
    if(str == "noshape")    
    {
      TOU CAP((string)PO->query_symbiote())+" sends you a mental grunt in confusion.\n");
      PO->set_shapetype(0);
      PO->set_shaped(0);
    }
    return 1;
  }
/***************************************************/


/********** Burnoff ********************************/
  if(str == "burnoff" || str == "Burnoff")
  {
    if(User->QL < 19) return 0;
    if(PO->query_burnoff())
    {
      TOU "Stopping the burnoff process...\n");
      PO->set_burnoff(0);
      return 1;
    }
    if(User->query_sp() < 15 || PO->query_mp() < 1)
    {
      TOU "Your symbiotic link is too weak for that.\n");
      return 1;
    }
    if(User->query_hp() < 50)
    {
      TOU "Your body is too weak to begin this process.\n");
      return 1; 
    }	

    PO->set_burnoff(1);	
    PO->add_mp(-1);
    User->add_spell_point(-15);
    
    TOU "You concentrate on your link and will it to burn off the harmful toxins in your\n"+
        "blood...\n");
    return 1;
  }      
/***************************************************/


/******** Regeneration *****************************/
  if(str == "regen" || str == "regenerate")
  {
    if(User->QL < 10) return 0;

    if(PO->query_regen())
    {
      TOU "You stop regenerating.\n");
      PO->set_regen(0);
      return 1;
    }
 
    if(User->query_sp() < 10 || PO->query_mp() < 1)
    {
      TOU "Your symbiotic link is too weak for that.\n");
      return 1;
    }	

    TOU "You concentrate briefly and feel "+CAP((string)PO->query_symbiote())+" begin to slowly mend your wounds.\n");
    PO->set_regen(1);
    PO->add_mp(-1);
    User->add_spell_point(-10);
    return 1;
  }
/***************************************************/

  return 0;
}
