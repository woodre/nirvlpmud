#include "/players/fred/mages/defs.h"

cmd_xfer(num){
 object ob;
 int amt, mreserve, rpower, x;
 ob = present("dark_circle", TP);
   if(!num){
     write("How much energy would you like to reserve?\n"); return 1;}
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}   
   if(sscanf(num, "%d", amt)){
     if(amt <= 0 || amt > USER->query_sp())
     return (tell_object(USER, "You don't have that much energy.\n"), 1);
   mreserve = ((LVL + (XLVL / 5) + INT) * (25+RANK));
   amt = ((amt*(50-INT))/100);
   rpower = query_reserve_power();
   if((rpower + amt) > mreserve){
     write("You can only reserve "+(mreserve - rpower)+" at this time.\n"); return 1; }
   ob->add_reserve_power(amt);
   USER->add_spell_point(-amt);
   write("You transfer "+BOLD+YEL+"energy"+NORM+" into your robes.\n");
   say(capitalize(TPN)+" transfers "+BOLD+YEL+"energy"+NORM+" into +POS+ robes.\n");
   return 1; }
}
