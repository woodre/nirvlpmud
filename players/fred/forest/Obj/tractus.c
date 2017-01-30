#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";
#define atn attacker->query_name()
int X;

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("sword ex tractus");
  set_alias("ex tractus");
  set_alt_name("tractus");
  set_short(BOLD+YEL+"Sword "+NORM+HIB+"ex "+NORM+BOLD+"tractus"+NORM);
  set_long(
     "  A finely crafted sword that sends pulses of energy\n"+
     "through your body. Electricity flows freely along the\n"+
     "blade which could cause some interesting occurances.\n" );
  set_type("sword");
  set_class(19);
  set_weight(4);
  set_value(5000);
  set_hit_func(this_object()); 
  }
  query_save_flag(){ 
   if(broke) return 1; 
   else return 0; 
  } 
  mixed
  weapon_hit(object attacker) {
  string name;
  int n, w;
  n = random(1000);
  w = random(100);
     if(n < 2) {
     if(environment(environment())->realm("NT")){
     write("A"+HIY+" swirl"+NORM+" of"+RED+" red"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
     write("For some reason nothing happens?\n");
     return 1; }
     else {
     int x;
     string dest;
     x = random(9);
     switch(x) {
       case 0: dest = "/players/snow/dark/rooms/r4.c";
               write("A"+HIY+" swirl"+NORM+" of"+GRN+" green"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;
       case 1: dest= "/players/zeus/realm/taus/road3.c";
               write("A"+HIY+" swirl"+NORM+" of"+MAG+" purple"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;
       case 2: dest= "/players/llew/closed/crystal/crys17.c"; 
               write("A"+HIY+" swirl"+NORM+" of"+HIR+" red"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;
       case 3: dest= "/players/dragnar/WasteLands/rooms/path1.c";
               write("A"+HIY+" swirl"+NORM+" of"+HIC+" light blue"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;
       case 4: dest= "/players/snow/ROOMS/summit.c";
               write("A"+HIY+" swirl"+NORM+" of"+HIY+" golden"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;
       case 5: dest= "/players/molasar/PLAINS/plain22";
               write("A"+HIY+" swirl"+NORM+" of"+HIG+" green"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;
       case 6: dest= "/players/nooneelse/entryforest/e_granite_quarry_pit";
               write("A"+HIY+" swirl"+NORM+" of"+HIB+" blue"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;
       case 7: dest= "/players/mythos/aroom/forest/tower4.c";
               write("A"+HIY+" swirl"+NORM+" of"+MAG+" magenta"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;
       case 8: dest= "/players/wocket/graveyard/gr9.c";
               write("A"+HIY+" swirl"+NORM+" of"+HIR+" red"+NORM+" electricity"+BOLD+" shoots"+NORM+" across the sword's blade!\n");
               write("Suddenly you find yourself in a new place.\n\n"); break;

       return 1; break;
       }  
      this_player()->move_player("#"+dest);  
      return 1; }
     } 
 
   if(w > 90) {
       int r, p;
       p = random(10)+1;
       r = random(4);          
       write("\nThe sword "+BOLD+"glows "+NORM+BOLD+RED+"softly"+NORM+" creating a");
       write(" swirling"+NORM+HIG+" vortex"+NORM+" behind "+BOLD+BLK+atn+NORM+"\n");
       write("The"+BOLD+"  -=[  VORTEX  ]=-  "+NORM+"passes over "+BOLD+BLK+atn+NORM+" draining their energy.\n\n");
       say("\n     A"+HIB+" swirling"+NORM+HIG+" vortex"+NORM+" opens behind "+BOLD+BLK+atn+NORM+"\n");  
       say("The"+BOLD+"  -=[  VORTEX  ]=-  "+NORM+"drains "+BOLD+BLK+atn+"'s"+NORM+" energy.\n\n");
      attacker->add_spell_point(-p);
      X+=r;
      return 5; }
    
    if(w > 80){
      int i, o;
      o = random(5)+1;
      i = random(4);
       write("\nThe sword "+BOLD+"glows "+NORM+BOLD+HIY+"softly"+NORM+" creating a");
       write(" swirling"+NORM+HIG+" vortex"+NORM+" above "+BOLD+BLK+atn+NORM+"\n");
       write("The"+BOLD+"  ***   VORTEX   ***  "+NORM+"passes through "+BOLD+BLK+atn+NORM+" stealing their health.\n\n");
       say("\n     A"+RED+" swirling"+NORM+HIG+" vortex"+NORM+" opens above "+BOLD+BLK+atn+NORM+"\n");
       say("The"+BOLD+"  ***"+HIG+"  VORTEX"+NORM+BOLD+"  ***  "+NORM+"drains "+BOLD+BLK+atn+"'s"+NORM+" health.\n\n");
       attacker->add_hit_point(-o);
       X += i;
      return 5; }
    
    if(w > 65){
       int y, q, u, a;  
       string where, what, col, thr;       
       y = random(5);
       q = random(4);
       u = random(6);
       a = random(5);
       switch(y){
         case 0: where="Shoulder"; break;
         case 1: where="Arm"; break;
         case 2: where="Mid Section"; break;
         case 3: where="Leg"; break;
         case 4: where="Neck"; break; }
       switch(q){
         case 0: what="cold"; break;
         case 1: what="hot"; break;
         case 2: what="warm"; break;
         case 3: what="cool"; break; }
       switch(u){
         case 0: col=BLU; break;
         case 1: col=BOLD+BLK; break;
         case 2: col=BOLD; break;
         case 3: col=HIY; break;
         case 4: col=HIB; break;
         case 5: col=BOLD+RED; break;
         case 6: col=GRN; break;
         case 7: col=MAG; break; }
       switch(a){
         case 0: thr="Slices"; break;
         case 1: thr="Hacks"; break;
         case 2: thr="Cleaves"; break;
         case 3: thr="Whistles"; break;
         case 4: thr="Rips"; break; }
 
       write("\nYou swing the "+HIY+"sword"+NORM+" through the "+col+what+NORM+BOLD+" AIR"+NORM+"\n");
       write("     striking "+BOLD+BLK+atn+NORM+" in the "+col+where+NORM+"\n\n"); 
       say("\nThe sword "+col+thr+NORM+" through the "+col+what+NORM+BOLD+" AIR"+NORM+"\n");
       say("   striking "+BOLD+BLK+atn+NORM+" in the "+col+where+NORM+"\n\n");
      return 7; }
     
    if(X > 20){
       write("The sword"+RED+" Explodes"+NORM+" with"+BOLD+" Energy"+NORM+"\n");
       say("The sword"+RED+" Explodes"+NORM+" with"+BOLD+" Energy"+NORM+"\n");
       this_player()->heal_self(20);
       X-=21;
       return 1; }  
    }
   
 
