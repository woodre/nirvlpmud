#include "/players/fred/mages/defs.h"

object lcp, player, party;
string name;
int dmg, amt, time;

set_name(str) { name = str;}

set_time(num){
 time = 25*num;
 call_out("quit_lich", time); }
 
liched(){ return 1; }

do_shadow(ob) {
  lcp = ob;
shadow(ob,1);
}

id(str) {return str == "lich" || str == name || str == "liched_obj" || str == "silent_move_object"; }

query_name(){
  if(lcp->query_ghost())
    return "some mist";
  return "Lich";
 }

short(){
  party = present("party_object", lcp);
  if(party && lcp->query_mounted())
  {
    return BOLD+BLK+"{"+RED+"o"+BLK+"} Lich the Undead Archmage ("+RED+"corrupt"+BLK+")"+NORM+" mounted on a "+CYN+"winged "+BOLD+BLK+"drakyr "+NORM+party->extra_short();
  }
  if(lcp->query_mounted())
  {
    return BOLD+BLK+"{"+RED+"o"+BLK+"} Lich the Undead Archmage ("+RED+"corrupt"+BLK+")"+NORM+" mounted on a "+CYN+"winged "+BOLD+BLK+"drakyr"+NORM;
  }
  if(party)
  {
    return BOLD+BLK+"{"+RED+"o"+BLK+"} Lich the Undead Archmage ("+RED+"corrupt"+BLK+") "+NORM+party->extra_short();
  }
  else
  {
    return BOLD+BLK+"{"+RED+"o"+BLK+"} Lich the Undead Archmage ("+RED+"corrupt"+BLK+")"+NORM;
  }
}

long(){ 
  if(TP->query_level() < 21 && !present("dark_circle", TP)){
    write(short()+".\n");
    write("The Liche's aura of fear is too great...\n"+
          "You want to run away in terror!!!\n");
    TP->run_away();
    return 1;
    }
  write(capitalize(name)+", disguised as a Lich.\n");
  write(short()+".\n");
  if(lcp->query_hp() < (lcp->query_mhp()/10)) {
    write("Lich is in very bad shape.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp()/5)) {
    write("Lich is in bad shape.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp()/2)) {
    write("Lich is somewhat hurt.\n"); return; }
  if(lcp->query_hp() < (lcp->query_mhp() - 20)){
    write("Lich is slightly hurt.\n"); return;}
    write("Lich is in good shape.\n");
    return 1;
  }

hit_player(arg){
 dmg = arg;
 amt = ((dmg*(98+random(3)))/100);
 lcp->hit_player(amt);
 return amt;
}

quit_lich() {
 write(BOLD+BLK+"Your Lich grows weak and you turn back into your original form.\n"+NORM); 
 write(BOLD+HIY+"\t\n\nYOU ARE NO LONGER A LICH!!!\n\n"+NORM);
 say(BOLD+BLK+TPN+"'s lich grows weak and "+TP->query_pronoun()+" turns back into "+TP->query_possessive()+" original form.\n"+NORM);
 destruct(TO);
 return 1;
}
