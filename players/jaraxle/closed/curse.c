#include "/players/fred/mages/defs.h"

cmd_curse(str){
 object ob, curse;
 int wc,ac;
   if(!str){ write("What do you seek to curse?\n"); return 1;}
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(INT < 20){
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}   
   if(RANK < 3){ 
     write("You have not mastered this art yet.\n"); return 1;}   
   if(USER->query_sp()<25){
      write("You don't have enough energy.\n"); return 1;}
  ob = present(str, TP);
  if(!ob){write("You don't have that in your inventory.\n"); return 1;}
  curse = CO("players/fred/mages/obj/item_curse.c");
  MO(curse,ob);
  wc = ob->weapon_class();
  ac = ob->armor_class();
  curse->set_wc(wc);
  curse->set_ac(ac);
  ob->set_class(0);
  ob->set_ac(0);
  ob->set_long("This item was cursed by one of the local Black Circle Mages.\n"+
               "If you ask nicely, one of them might remove the curse for you.\n");
  write("You lay a foul curse upon "+ob->short()+".\n");
  say(capitalize(TPN)+" lays a foul curse upon "+ob->short()+".\n");
  TP->add_spell_point(-25); 
return 1;}
