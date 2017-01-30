#include "/players/fred/mages/defs.h"

cmd_uncurse(str){
 object ob,curse;
 int wc, ac;
 string desc;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(!str){
     write("What do you seek to uncurse?\n"); return 1;}
   if(INT < 20){
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}   
   if(RANK < 3){ 
     write("You have not mastered this art yet.\n"); return 1;}   
   if(USER->query_sp() < 25) {
     write("You don't have enough energy.\n"); return 1;}
   ob = present(str, TP);
   curse = present("curse",ob);
   if(!curse){
     write("There is no curse on "+ob->short()+".\n"); return 1;}
   wc = curse->query_wc();
   ac = curse->query_ac();
   desc = curse->query_rem();
   ob->set_ac(ac);
   ob->set_class(wc);
   ob->set_long(ob->short()+".\n");
   write("You remove a foul curse from "+ob->short()+".\n");
   say(capitalize(TPN)+" removes a foul curse from "+ob->short()+".\n");
   USER->add_spell_point(-25); 
   destruct(curse);
   return 1;
 }                                                                                                                                                                                          

