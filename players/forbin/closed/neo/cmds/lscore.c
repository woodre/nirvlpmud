#include "../defs.h"

status main(string str, object gob, object player)
{
  int myweight, carry, i,f,s,t, nextexp, a; 
  string com, con, cre, aa;

  a = (int)player->query_age();
  aa = "";
  if(a/43200) 
  {
    aa += (a/43200 +"d ");
    a = a - (a/43200)*43200;
  }
  if(a/1800) 
  {
    aa+= (a/1800 +"h ");
    a = a  - (a/1800)*1800;
  }
  if(a/30) 
  {
    aa += (a/30 +"m ");
    a = a - (a/30)*30;
  }
  aa += (a*2 +"s.");

  player->recalc_carry();  /* carry code by Snow  *thanx*  */
  carry = (int)player->query_level();
  carry += 6;
  carry += (int)player->query_attrib("str")/5;
  myweight = (int)this_object()->get_my_weight(player);

  nextexp = (int)"/bin/play/_xpnext.c"->query_next_xp(0, player); 

  i = (int)player->query_intoxination()*100 / ((int)player->query_level()+3);
  f = (int)player->query_stuffed()*100 / ((int)player->query_level()*8);
  s = (int)player->query_soaked()*100 / ((int)player->query_level()*8);
  t = (int)player->query_infuse()*100 / (((int)player->query_level()*9)/2);
  
  com = (string)gob->show_skill_prof("combat");
  con = (string)gob->show_skill_prof("control");
  cre = (string)gob->show_skill_prof("creation");
  
  tell_object(player,
    "\n"+SGC+"<<"+PGC+"==-==-==-==-==-=="+SGC+">> "+HIW+"Neo Symbiotes "+
    SGC+"<<"+PGC+"==-==-==-==-==-=="+SGC+">>"+NORM+"\n");
    
  tell_object(player,
    "   "+player->short()+"\n\n"+
    PGC+"  Level:  "+NORM+(int)player->query_level());
  if((int)player->query_extra_level() > 0)
    tell_object(player, colour_pad("+"+(int)player->query_extra_level(), 10));
  else
    tell_object(player, colour_pad("", 10));
  tell_object(player, 
    PGC+"Experience:  "+(int)player->query_exp());
  if(nextexp > 0)
    tell_object(player,
      SGC+" ["+NORM+nextexp+SGC+"]"+NORM+"\n");
  else
    tell_object(player, "\n");
  tell_object(player,
    PGC+"  Hp:    "+NORM+colour_pad((int)player->query_hp()+SGC+"/"+NORM+
      (int)player->query_mhp(), 20));   
  tell_object(player,
    PGC+"Gold:  "+NORM+YEL+(int)player->query_money()+NORM+"\n");
  tell_object(player,
    PGC+"  Sp:    "+colour_pad((int)player->query_sp()+SGC+"/"+NORM+
      (int)player->query_msp(), 12));   
  tell_object(player,
    PGC+"Quest Points:  "+NORM+(int)player->query_quest_point()+"\n");
  tell_object(player,
    PGC+"  Stuff:  "+NORM+colour_pad(f,-3)+SGC+"%          "+PGC+"Age: "+NORM+aa+"\n");
  tell_object(player,
    PGC+"  Soak:   "+NORM+colour_pad(s,-3)+"SGC+%\n");
  tell_object(player,
    PGC+"  Intox:  "+NORM+colour_pad(i,-3)+SGC+"%"+NORM+
    "         You are carrying "+myweight*100/carry+SGC+"%"+
    NORM+" of maximum.\n");
  tell_object(player,
    SGC+"<<"+PGC+"==-==-==--==-==-=="+SGC+">> "+HIW+"Guild Skills "+
    SGC+"<<"+PGC+"==-==-==--==-==-=="+SGC+">>"+NORM+"\n");
  tell_object(player,
    PGC+"  Guild Level:  "+NORM+colour_pad((int)gob->query_glevel(),8));
  tell_object(player,
    PGC+"         Guild Experience: "+NORM+(int)gob->query_guildexp()+"\n\n");
  tell_object(player,
    PGC+"  Combat: "+NORM+colour_pad((int)gob->query_skill("combat"),1)+
    SGC+" ["+NORM+colour_pad(com,-3)+SGC+"]  "+
    PGC+"Control: "+NORM+colour_pad((int)gob->query_skill("control"),1)+
    SGC+" ["+NORM+colour_pad(con,-3)+SGC+"]  "+
    PGC+"Creation: "+NORM++colour_pad((int)gob->query_skill("creation"),1)+
    SGC+" ["+NORM+colour_pad(cre,-3)+SGC+"]"+NORM+"\n");
  tell_object(player,
    SGC+"<<"+PGC+"==-==-==-==-==-==-==-=="+SGC+">> "+HIW+"* "+
    SGC+"<<"+PGC+"==-==-==-==-==-==-==-=="+SGC+">>"+NORM+"\n");    
  return 1;
}

int get_my_weight(object ob) /* Code by Snow  *thanx*  */
{    
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

