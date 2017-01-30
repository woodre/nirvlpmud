#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
  int intox_level;
  string tmp;
  int tmpp, ex_lv, plev, pqp;
  int infuse, level;
  int tkill;
  mixed *top_kill;
    
  if (User->query_ghost())
  {
    write("You are in an immaterial state with no scores.\n");
	  return 1;
  }
  User->transfer_extra_eq();
  write("\n");
  
  write(User->short()+"\n");
  level = (int)User->query_level();
  ex_lv=(int)User->query_extra_level();
  plev = (int) User->query_prestige_level();
  write("Level: "+level+"+"+ex_lv+"\n");
  /*write("Level: "+level+(ex_lv ? "+"+add_zero(ex_lv) : "")+(plev ? HIG+"{"+plev+"}"+NORM : "")+
   (ex_lv ? (" ("+User->query_total_level()+")\n") : "\n"));*/
 
  write("Score: "+comma_number((int) User->query_prestige_score()) +"\n");
  write(pad("Coins: "+comma_number((int)User->query_money()),COL1_SIZE)
  +"Experience: "+comma_number((int)User->query_exp())+"\n");
  
  write(pad("Hit points: "+(int)User->query_hp()+"/"+(int)User->query_mhp(),COL1_SIZE)+
            "Spell points: "+(int)User->query_sp()+"/"+(int)User->query_msp()+"\n");
  pqp = (int)User->query_prestige_qp();
  write(pad("Quest points: "+(int)User->query_quest_point(),COL1_SIZE)+
       (pqp ? "Prestige Quest Points: "+ pqp : "")+"\n");
  
  top_kill = (mixed *) User->query_top_kill();
  if( top_kill )
    tkill = top_kill[0];
  else
    tkill = 0;
  
  write( pad("Top Kill: " +comma_number(tkill), COL1_SIZE ));
  write( "Top Boot Exp: " +comma_number(User->query_top_boot_xp()) +"\n");
  
  infuse = (int)User->query_infuse();
  
  if(infuse > 0)
    write("Infused: "+(2*infuse/3)+"/"+(2*(INFUSE_LIMIT)/3)+"\n");
  if (((int)User->query_level() > 19) || (User->is_testchar()))
    if ((int)User->query_bank_balance())
      write("Bank Balance: " + comma_number(User->query_bank_balance()) + "\n");
  User->show_age();
  
  if(User->query_tellblock_index(0) && 
     (string)User->query_tellblock_index(0) != "off") write("Tellblock is ON.\n");
     
  if(User->query_pregnancy())
  {
    tmpp=(int)User->query_age()-(int)User->query_pregnancy();
    if(tmpp > 4000) 
      write("You are Pregnant ("+tmpp+" / 16200)\n");
  }
  
  if(User->query_hunter() && User->query_hunter()->query_name())
    write("You are hunted by "+(string)User->query_hunter()->query_name()+ ".\n");
    
  if (!User->query_intoxination())
    write("You are sober.\n");
  else
  {
    intox_level=level+4;
    intox_level/=(int)User->query_intoxination();
    if (intox_level == 0)
      write("You are in a drunken stupor.\n");
    else if (intox_level == 1)
      write("You are roaring drunk.\n");
    else if (intox_level == 2)
      write("You are somewhat drunk.\n");
    else if (intox_level == 3)
      write("You are quite tipsy.\n");
    else
      write("You are slightly tipsy.\n");
  }
  if (User->query_stuffed() || User->query_soaked()) {
	  write("You are ");
    if (User->query_stuffed())
      write("satiated"+(User->query_soaked() ? " and " : ".\n"));
	  if (User->query_soaked()) write("not thirsty.\n");
  }

  if (User->query_whimpy())
	  write("Wimpy mode.\n");
	  
	if(User->check_fight_area()) write("You are in a "+HIR+"PK"+NORM+" zone.\n");
  write("Carrying "+(int)User->query_pct_weight()+"% of maximum capacity.\n");
  write("\n\n");
  write(YEL+"Air Rank: "+PO->query_AIR()+"\n"+NORM);
  write(GRN+"Earth Rank: "+PO->query_EARTH()+"\n"+NORM);
  write(RED+"Fire Rank: "+PO->query_FIRE()+"\n"+NORM);
  write(CYN+"Water Rank: "+PO->query_WATER()+"\n"+NORM);
  return 1;
}
