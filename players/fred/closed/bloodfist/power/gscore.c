#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int myweight, carry, glvl, i,f,s,t;

  User->recalc_carry();  /* carry code by Snow  *thanx*  */
  carry = (int)User->query_level();
  carry += 6;
  carry += (int)User->query_attrib("str")/5;
  myweight= (int)this_object()->get_my_weight(User);
  glvl = (int)PO->query_glevel();

  TOU RED+"\n["+NORM+BOLD+BLK+
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+NORM+RED+" Bloodfist "+NORM+BOLD+BLK+
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+NORM+RED+"]\n"+NORM);
  if(PO->query_f_s()) /* full score toggle */
  {
    i = (int)User->query_intoxination()*100 / ((int)User->query_max_intox());
    f = (int)User->query_stuffed()*100 / ((int)User->query_max_stuff());
    s = (int)User->query_soaked()*100 / ((int)User->query_max_soak());
    t = (int)User->query_infuse()*100 / (((int)User->query_level()*9)/2);
    TOU " "+User->short()+"\n"+                                /* short */
      pad(" Hp:    "+User->query_hp()+"/"+User->query_mhp(), 19)+ /* hp */
      "Level:  "+User->query_level());                         /* level */
    if(User->query_extra_level() > 0)                          /* xlvl */
      TOU pad("+"+User->query_extra_level(), 7));
    else
      TOU pad("", 7));
    TOU "Gold: "+User->query_money()+"\n"+                      /* gold */
      pad(" Sp:    "+User->query_spell_point()+"/"+User->query_msp(), 19)+
      pad("Exp:    "+User->query_exp(), 17)+                    /* exp */
      "Qps:  "+User->query_quest_point()+"\n");                 /* qps */
    TOU
      pad(" Intox:    "+i+"%", 19)+                             /* tox */
      pad("Stuff:  "+f+"%", 17)+
      pad("Soak: "+s+"%", 19)+
      "Infuse: "+t+"%\n\n");
  }
  TOU " "+pad("Glevel:",10)+pad(glvl,8)+
    pad("Gxp: ",9)+pad((string)PO->query_gexp(),8));
  if(glvl < 8)
  {
    TOU "Next: "+PO->query_glevel_amt()+" of "+
      PO->query_glevel_costdif()+"\n");
  }
  else
    TOU "\n");
  TOU "\n"+
    " "+pad("Agility:", 10)+pad((string)PO->show_attrib("AGL"), 8)+
    pad("Might:", 9)+pad((string)PO->show_attrib("MIT"), 8)+
    pad("Accuracy: ", 11)+pad((string)PO->show_attrib("ACC"),8)+
    pad("Free: ",7)+(string)PO->query_free_attribs()+"\n"+
    " "+pad("Vigor:", 10)+pad((string)PO->show_attrib("VIG"),8)+
    pad("Wisdom: ", 9)+pad((string)PO->show_attrib("WIS"), 8)+
    pad("Faith:",11)+(string)PO->show_attrib("FAI")+"\n"+
    "\n"+
    " "+pad("Combat stance: ",18)+
    colour_pad(capitalize((string)PO->query_stance(2)),17)+
    pad("Sheathed weapons: ",19)+(string)PO->query_sheathed()+" of "+
    (string)PO->query_max_sheathed()+"\n"+
    " "+pad("Carrying: ",18)+pad(myweight*100/carry+"% of max",17)+
    pad("Chosen weapons: ",19)+PO->query_chosen_current()+" of "+
    PO->query_chosen_max()+"\n"+
    " "+pad("Endurance: ",18));
  TOU pad(PO->query_endurance()+"/"+PO->query_max_endurance(), 17)+
    pad("Blood Honor: ",19)+
    HONOR_DAEMON->display_honor(User->query_real_name())+
    "\n");
  if(PO->query_f_s() || PO->query_a_c()) TOU "\n");
  if(PO->query_f_s()){
    TOU " ");  User->show_age();
  }
  if(PO->query_a_c())
    TOU " Additional commands: chosen, sheathed, stance, "+
    "raise <attrib> <amt>\n");
  TOU RED+"["+NORM+BOLD+BLK+"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+NORM+RED+"]\n\n"+NORM);

  return 1;
}

int get_my_weight(object ob) {  /* Coded by Snow  *thanx*  */
  int total;
  object one;
  if(!ob) return 1;
  one = first_inventory(ob);
  while(one)
  {
    total += (int)one->query_weight();
    one = next_inventory(one); 
  }
  return total;
}

