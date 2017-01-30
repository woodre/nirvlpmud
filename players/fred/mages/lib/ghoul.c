#include "/players/fred/mages/defs.h"

cmd_ghoul(){
 string handle;
 object body, ghoul, me, ob;
 int gac, gwc, ghp, gval;
 int ghouled, dragoned;
 body = present("corpse", ENV(TP));
 ob = present("dark_circle", TP);
 ghouled = query_has_ghoul();
 dragoned = query_has_dragon();
   if(ghouled != 0){
     write("You already have a ghoul.\n"); return 1; }
   if(dragoned != 0){
     write("You are only allowed to use on pet at a time.\n"); return 1; }
   if(!body){
     write("You need a corpse to manufacture a ghoul.\n"); return 1;}   
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(RANK < 2){
     write("You have not mastered that art yet.\n"); return 1;}
   if(INT < 20){
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
   if(USER->query_sp() < 50){
     write("You don't have enough energy.\n"); return 1;} 
    handle = body->short();  
    me = TP;
    gac = body->query_ac();
    gwc = body->query_wc();
    ghp = body->query_mhp();
    if(ghp > 350) ghp = 350;
    gval = body->heal_value();
    MO(CO("/players/fred/mages/mon/ghoul.c"), ENV(TP));
    destruct(body);
    ghoul = present("ghoul", ENV(TP));
    ghoul->patch_owner(me);
    ghoul->set_short("A Ghoulish "+handle);
    ghoul->set_level((gval+2)/2);
    ghoul->set_ac((gac/10)+RANK);
    ghoul->set_wc((gwc/10)+RANK);
    ghoul->set_hp(ghp);
    ghoul->set_life((LVL*80)+(XLVL*30));
    ghoul->set_decay(((LVL-1)*80)+(XLVL*30));
    ghoul->init();
    ob->set_has_ghoul(1);
    ob->ssave();
    USER->add_spell_point(-50);
    write(BOLD+BLK+"Energy flows from your body into "+handle+"....\n"+
         ""+capitalize(handle)+" slowly rises and becomes your slave."+NORM+"\n");
    say(BOLD+BLK+"Energy flows from "+capitalize(TPN)+" into "+capitalize(handle)+"...\n"+
         ""+capitalize(handle)+" slowly rises and bows to "+capitalize(TPN)+", its new master."+NORM+"\n");
   return 1;
}
