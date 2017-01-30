#include "/players/zeus/circle/defs.h"

status score_cmd(){
  string end;
  int x, carry, myweight, poe, preg, mend,i,f,s,t;
  mend = (int)PO->query_max_endurance();
  poe = (int)PO->query_endurance();
  if(poe < -30)                    end = "completely exhausted";
  else if(poe < 0)                 end = "very weak";
  else if(poe <= (mend / 10))      end = "exhausted";
  else if(poe <= (mend * 2 / 10))  end = "worn out";
  else if(poe <= (mend * 3 / 10))  end = "tired";
  else if(poe <= (mend * 4 / 10))  end = "a bit tired";
  else if(poe <= (mend * 5 / 10))  end = "normal";
  else if(poe <= (mend * 6 / 10))  end = "okay";
  else if(poe <= (mend * 7 / 10))  end = "good";
  else if(poe <= (mend * 8 / 10))  end = "very good";
  else if(poe <= (mend * 9 / 10))  end = "great";
  else if(poe <= mend)             end = "completely refreshed";
  else end = "unknown";

  User->recalc_carry();  /* carry code by Snow  *thanx*  */
  carry = (int)User->query_level();
  carry += 6;
  carry += (int)User->query_attrib("str")/5;
  myweight= (int)this_object()->get_my_weight(User);

  if(User->query_fight_area())
    User->set_fight_area();
  else
    User->clear_fight_area();

  tell_object(User,  "\n"+NORM+User->short()+"\n");
  if(User->query_extra_level()){
    tell_object(User, pad("Level: "+User->query_level()+"+"+
      User->query_extra_level(), 32));
  }
  else
    tell_object(User, pad("Level: "+User->query_level(), 32));
  tell_object(User,
    "Experience: "+(int)User->query_exp()+"\n"+
    pad("Health:  "+(int)User->query_hp()+"/"+(int)User->query_mhp(), 32)+
    "Mana:  "+(int)User->query_spell_point()+"/"+(int)User->query_msp()+"\n"+
    pad("Quest points: "+(int)User->query_quest_point(),32)+
    "Room:  ");
    if(User->check_fight_area())
      tell_object(User, HIR+"PK  "+NORM);
    if((string)environment(User)->realm() == "NT" &&
       (string)environment(User)->realm() != "NM"){
      tell_object(User, HIC+"NON-TP\n"+NORM);
    }
    else if((string)environment(User)->realm() == "NM")
      tell_object(User, HIB+"NM\n"+NORM);
    else
      tell_object(User, "\n");
    tell_object(User, pad("XP percent: "+(int)PO->query_percent(), 32));
    if((int)User->query_pregnancy()) {
      preg = (int)User->query_age() - (int)User->query_pregnancy();
      tell_object(User, "Pregnant: "+preg*100/16300+"%\n"); 
    }
    else
      tell_object(User, "\n");
  tell_object(User, "You currently feel "+end+".\n"+
    "Carrying "+myweight*100/carry+"% of max, and "+
    (int)User->query_money()+" gold coins.\n");
  User->show_age();
  i = (int)User->query_intoxination()*100 / ((int)User->query_max_intox());
  f = (int)User->query_stuffed()*100 / ((int)User->query_max_stuff());
  s = (int)User->query_soaked()*100 / ((int)User->query_max_soak());
  t = (int)User->query_infuse()*100 / (((int)User->query_level()*9)/2);
/*  if(i > 0)
    tell_object(User,  "Intox:  "+HIW+i+"%"+pad(NORM, 13));
  else
*/    tell_object(User, pad("Intox:  "+i+"%", 13));
/*  if(f > 0)
    tell_object(User,  "Stuff:  "+HIW+f+"%"+pad(NORM, 13));
  else
*/    tell_object(User, pad("Stuff:  "+f+"%", 13));
/*  if(s > 0)
    tell_object(User,  "Soak:  "+HIW+s+"%"+pad(NORM, 12));
  else
*/    tell_object(User, pad("Soak:  "+s+"%", 12));
/*  if(t > 0)
    tell_object(User,  "Infuse:  "+HIW+t+"%\n\n"+NORM);
  else
*/    tell_object(User,  "Infuse:  "+t+"%\n\n");
  return 1;
}

int get_my_weight(object ob) {  /* Coded by Snow  *thanx*  */
	int total;
	object one;
	if(!ob) return 1;
	one = first_inventory(ob);
	while(one) {
		total += (int)one->query_weight();
		one = next_inventory(one); 
	}
  return total;
}

