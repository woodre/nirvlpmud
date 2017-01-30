#include "/players/pestilence/define.h"

object lcp,player;
string name;
int dmg, amt, time;

/*
set_name(str) { name = str;}
*/

set_time(num){
 time = 200*num;
 call_out("quit_lich", time); }
 
liched(){ return 1; }

do_shadow(ob) {
  lcp = ob;
shadow(ob,1);
}

/*
id(str) {return str == "Predator" || str == name || str == "predator_obj"; } 
*/

/*
query_name(){
  if(lcp->query_ghost())
    return "some mist";
  return "Predator";
 }
*/

id(str) {return str == "Santa" || str == name || str == "santa_obj"; }


query_name(){
  if(lcp->query_ghost())
    return "some mist";
  return HIR+"Santa "+HIW+"Claus"+NORM;
 }

short() { return HIR+"Santa "+HIW+"Claus"+NORM+" ("+HIR+"M"+HIW+"e"+HIR+"r"+HIW+"r"+HIR+"y"+HIW+" C"+HIR+"h"+HIW+"r"+HIR+"i"+HIW+"s"+HIR+"t"+HIW+"m"+HIR+"a"+HIW+"s"+NORM+")"+NORM;}

long(){ 
  if(TP->query_level() < 21 && !present("destroyer_ob", TP)){
    write(short()+".\n");
    write("You become very intimidated and lower your weapon.\n");
    TP->stop_wielding();
    return 1;
    }
  write(short()+".\n");
  if(lcp->query_hp() < (lcp->query_mhp()/10)) {
    write("Predator is in very bad shape.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp()/5)) {
    write("Predator is in bad shape.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp()/2)) {
    write("Predator is somewhat hurt.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp() - 20)){
    write("Predator is slightly hurt.\n"); return;}
    write("Predator is in good shape.\n");
    return 1;
  }

hit_player(arg){
 dmg = arg;
amt = (dmg);
 lcp->hit_player(amt);
 return amt;
}

quit_lich() {
/*
 write(BOLD+BLK+"Your Lich grows weak and you turn back into your original form.\n"+NORM); 
*/
 write(BOLD+HIY+"You are no longer in Predator mode.\n\n"+NORM);
say(BOLD+BLK+"Enhanced Predator lets "+TPN+" return back into "+TP->query_possessive()+" original form.\n"+NORM);
 destruct(TO);
 return 1;
}
