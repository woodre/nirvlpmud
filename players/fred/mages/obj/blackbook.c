#include "/players/fred/mages/defs.h"

id(str){ return str == "black" || str == "book" || str == "black book"; }

reset(arg) {
   if (arg) return;
   set_light(1);
}

 
init(){ add_action("join","sign"); }

short(){ return BOLD+BLK+"A Black Book"+NORM; }

long(){
   write("This is a Necronomicon, crafted ages ago by the Great Lich Drunan Zath.\n"+
         "Sign your name to this book if you wish to be a Black Circle Mage.\n"); }
 
join(){
 object ob;
 int lvl, xlvl, woo, foo, cando;
 xlvl = TP->query_extra_level();
 lvl = TP->query_level();
 /* Check...If they have enough exp for their next level
    they have to raise level....no joining with tons of exp
    START */
 if(xlvl < 1)  
   woo = call_other("room/adv_guild","get_next_exp",lvl-1);
 if(xlvl > 0)
   woo = call_other("room/exlv_guild","get_next_exp",xlvl-1);
 if(xlvl < 1)  
   foo = call_other("room/adv_guild","get_next_exp",lvl);
 if(xlvl > 0)
   foo = call_other("room/exlv_guild","get_next_exp",xlvl);
 if(xlvl < 1)  
   cando = TP->query_exp() - call_other("room/adv_guild","get_next_exp",lvl-1);
 if(xlvl > 0)
   cando = TP->query_exp() - call_other("room/exlv_guild","get_next_exp",xlvl-1); 
 if(((cando - (foo-woo)) > 0) && xlvl < 100){
   write("You must advance level before joining.\n"); return 1;} 
 /* END */ 
 if(TP->query_guild_exp() > 0){
   write("You are already in a guild.\n"); return 1; }
 if(TP->query_attrib("int") < 20){
   write("You do not have the intelligence needed to join at this time.\n"); return 1; }
 if(present("guild_object", TP)){
   write("You already in a guild.\n"); return 1; }
 if(present("dark_circle", TP)){
   write("You are already in the guild.\n"); return 1;}
 if(TP->query_guild_rank() > 0){
   write("You are already in a guild.\n"); return 1; }
  write(BOLD+BLK+"You grab a pen and carefully scrawl "+TPN+" into the book...\n"+NORM);
  write(BOLD+BLK+"Dark Energy floods over your body...\n"+NORM);
  say(BOLD+BLK+TPN+" grabs a pen and carefully scrawls "+TPN+" into the book...\n"+NORM);
  say(BOLD+BLK+TPN+" joins the Black Circle Mages.\n"+NORM);
  MO(CO("/players/fred/mages/gob.c"), TP);
  write_file("/players/fred/mages/log/JOIN",
  capitalize(TPRN)+" joined the guild on "+ctime() [4..15]+".\n"); 
  ob = present("dark_circle", TP);
  ob->msave();
  return 1;
 }

get(){ return; }

