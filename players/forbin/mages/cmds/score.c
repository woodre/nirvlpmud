#include "../def.h"

status main(string str, object gob, object player)
{
  int myweight, carry, i,f,s,t, nextexp; 

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
  
  
  tell_object(player,
    SGC+"\n["+PGC+"*"+SGC+"]=======================["+PGC+"*"+SGC+"]"+TGC+
    " MAGE GUILD "+SGC+"["+PGC+"*"+SGC+"]=======================["+PGC+"*"+SGC+"]\n"+NORM);
    
  tell_object(player,
    "   "+player->short()+"\n"+
    PGC+"   Level:  "+QGC+(int)player->query_level());
  if((int)player->query_extra_level() > 0)
    tell_object(player, colour_pad(QGC+"+"+(int)player->query_extra_level(), 15));
  else
    tell_object(player, colour_pad("", 15));
  tell_object(player, 
    PGC+"Experience:  "+QGC+(int)player->query_exp());
  if(nextexp > 0)
    tell_object(player,
      SGC+" ["+QGC+nextexp+SGC+"]\n");
  else
    tell_object(player, "\n");
  tell_object(player,
    PGC+"   Hp:    "+colour_pad(QGC+(int)player->query_hp()+PGC+"/"+
      QGC+(int)player->query_mhp(), 25));   
  tell_object(player,
    PGC+"Gold:  "+NORM+YEL+(int)player->query_money()+"\n");
  tell_object(player,
    PGC+"   Sp:    "+colour_pad(QGC+(int)player->query_sp()+PGC+"/"+
      QGC+(int)player->query_msp(), 17));   
  tell_object(player,
    PGC+"Quest Points:  "+QGC+(int)player->query_quest_point()+"\n");
  tell_object(player,
    PGC+"   Stuff:  "+colour_pad(QGC+f,-3)+SGC+"%            "+PGC+"Infuse:  "+QGC+""+t+SGC+"%"+PGC+"\n");
  tell_object(player,
    PGC+"   Soak:   "+colour_pad(QGC+s,-3)+SGC+"%    "+QGC);
  player->show_age();
  tell_object(player,
    PGC+"   Intox:  "+colour_pad(QGC+i,-3)+SGC+"%"+QGC+"    You are carrying "+
      myweight*100/carry+SGC+"%"+QGC+" of maximum.\n\n");
  tell_object(player,
    PGC+"   Guild Level:  "+colour_pad(QGC+gob->query_glevel(),14));
  tell_object(player,
    PGC+"Guild Experience: "+QGC+gob->query_gxp()+"\n");
  if(gob->query_glevel() < ((int)gob->sizeof_guildlevelcosts())-1)
    tell_object(player,
      PGC+"                               Next Guild Level: "+QGC+gob->show_next_guild_level()+"\n");
  tell_object(player,
    PGC+"                               Free Experience:  "+QGC+gob->show_free_exp()+"\n");    
  tell_object(player,
    SGC+"\n["+PGC+"*"+SGC+"]==================["+PGC+"*"+SGC+"]"+TGC+
    " Attributes & Schools "+SGC+"["+PGC+"*"+SGC+"]==================["+PGC+"*"+SGC+"]\n"+NORM);
  tell_object(player,
    PGC+" Power        "+SGC+"["+colour_pad(QGC+gob->query_attrib("power"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_attrib_bonus("power"), 4));        
  tell_object(player,
    PGC+" Abju "+SGC+"["+colour_pad(QGC+gob->query_school("abju"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_school_bonus("abju"), 4)); 
  tell_object(player,
    PGC+" Divi "+SGC+"["+colour_pad(QGC+gob->query_school("divi"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_school_bonus("divi"), 4)+PGC+" Next Attrib Pts");
  tell_object(player,
    PGC+"\n Will Power   "+SGC+"["+colour_pad(QGC+gob->query_attrib("will power"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_attrib_bonus("will power"), 4));        
  tell_object(player,
    PGC+" Conj "+SGC+"["+colour_pad(QGC+gob->query_school("conj"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_school_bonus("conj"), 4)); 
  tell_object(player,
    PGC+" Illu "+SGC+"["+colour_pad(QGC+gob->query_school("illu"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_school_bonus("illu"), 4)+SGC+"     ["+QGC);
  if(gob->query_attrib_level() < gob->sizeof_attribscosts())
    tell_object(player,
      colour_pad(""+gob->show_attributes_percentage(), -3)+SGC+"]"+SGC+"%");
  else 
    tell_object(player,
      colour_pad(""+gob->show_attributes_percentage(), -3)+SGC+"]");
  tell_object(player,
    PGC+"\n Intelligence "+SGC+"["+colour_pad(QGC+gob->query_attrib("intelligence"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_attrib_bonus("intelligence"), 4));        
  tell_object(player,
    PGC+" Ench "+SGC+"["+colour_pad(QGC+gob->query_school("ench"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_school_bonus("ench"), 4)); 
  tell_object(player,
    PGC+" Necr "+SGC+"["+colour_pad(QGC+gob->query_school("necr"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_school_bonus("necr"), 4)+PGC+" Next School Pts");  
  tell_object(player,
    PGC+"\n Wisdom       "+SGC+"["+colour_pad(QGC+gob->query_attrib("wisdom"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_attrib_bonus("wisdom"), 4));        
  tell_object(player,
    PGC+" Evoc "+SGC+"["+colour_pad(QGC+gob->query_school("evoc"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_school_bonus("evoc"), 4)); 
  tell_object(player,
    PGC+" Tran "+SGC+"["+colour_pad(QGC+gob->query_school("tran"), -3)+SGC+"]"+QGC+
    colour_pad(gob->show_school_bonus("tran"), 4)+SGC+"     ["+QGC);
  if(gob->query_school_level() < gob->sizeof_schoolscosts())
    tell_object(player,
      colour_pad(""+gob->show_schools_percentage(), -3)+SGC+"]"+SGC+"%");
  else
    tell_object(player,
      colour_pad(""+gob->show_schools_percentage(), -3)+SGC+"]");
  if((int)gob->query_school_pts() || (int)gob->query_attrib_pts() ||
     (int)gob->query_spell_level_trains())
  {
    tell_object(player,
      SGC+"\n["+PGC+"*"+SGC+"]===============================["+PGC+"*"+SGC+
      "]==============================["+PGC+"*"+SGC+"]"+NORM);
    if((int)gob->query_attrib_pts())
      tell_object(player,
        "\n     You have "+SGC+(int)gob->query_attrib_pts()+QGC+" points to spend on attributes.");      
    if((int)gob->query_school_pts())
      tell_object(player,
        "\n     You have "+SGC+(int)gob->query_school_pts()+QGC+" points to spend on schools of magic.");
    if((int)gob->query_spell_level_trains())
      tell_object(player,
        "\n     You can learn "+SGC+(int)gob->query_spell_level_trains()+QGC+" spell levels worth of spells.");
  }
    
  tell_object(player,
    SGC+"\n["+PGC+"*"+SGC+"]=======================["+PGC+"*"+SGC+"]"+TGC+
    " MAGE GUILD "+SGC+"["+PGC+"*"+SGC+"]=======================["+PGC+"*"+SGC+"]\n"+NORM);    
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

