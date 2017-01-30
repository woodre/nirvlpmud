#include "/players/fred/mages/defs.h"
object lcp,player,party;
string name;
int dmg, amt, time;
      
set_name(str) { name = str;}

set_time(num){
 time = 40*num;
 call_out("quit_dk", time); }

dknighted(){ return 1; }
 
do_shadow(ob) {
 lcp = ob;
shadow(ob,1);
}

id(str) {return str == "deathknight" || str == name || str == "dknight_obj" || str == "silent_move_object"; }

query_name() {
  if (lcp->query_ghost()) 
      return "some mist";
  if (lcp->query_level() > 4999)
     return "fredjr";
  return "DeathKnight";
}

query_real_name(){
  if(lcp->query_level() < 4999)
    return lcp->query_real_name();
  return "fredjr";
}


short(){
  party = present("party_object", lcp);
  if(lcp->query_level() < 20)
  {
    if(party && lcp->query_mounted())
    {
      return BOLD+BLK+"{"+RED+"O"+BLK+"} DeathKnight the Undead Warrior ("+RED+"demonic"+BLK+")"+NORM+" mounted on a "+CYN+"winged "+BOLD+BLK+"drakyr "+NORM+party->extra_short();
    }
    if(lcp->query_mounted())
    {
      return BOLD+BLK+"{"+RED+"O"+BLK+"} DeathKnight the Undead Warrior ("+RED+"demonic"+BLK+")"+NORM+" mounted on a "+CYN+"winged "+BOLD+BLK+"drakyr"+NORM;
    }
    if(party)
    {
      return BOLD+BLK+"{"+RED+"O"+BLK+"} DeathKnight the Undead Warrior ("+RED+"demonic"+BLK+") "+NORM+party->extra_short();
    }   
    else
    {
      return BOLD+BLK+"{"+RED+"O"+BLK+"} DeathKnight the Undead Warrior ("+RED+"demonic"+BLK+")"+NORM;
    }
  }
}

long()
{
  if(lcp->query_level() > 20 && TP->query_level() > 20)
  {
    write("What you looking at Willis!!\n");
    return 1;
  } 
  if(TP->query_level() < 21 && !present("dark_circle", TP)){
     write(short()+".\n");
     write("The Deathknight's aura of fear is too great...\n"+
           "You want to run away in terror!!!\n");
     TP->run_away();
     return 1;
     }
 write(capitalize(name)+", disguised as a Deathknight.\n");
 write(short()+".\n");
 if(lcp->query_hp() < (lcp->query_mhp()/10)){
   write("Deathknight is very bad shape.\n"); return; }
 if(lcp->query_hp() < (lcp->query_mhp()/5)){
   write("Deathknight is in bad shape.\n"); return; }
 if(lcp->query_hp() < (lcp->query_mhp()/2)){
   write("Deathknight is somewhat hurt.\n"); return; }
 if(lcp->query_hp() < (lcp->query_mhp() - 20)){
   write("Deathknight is slightly hurt.\n"); return; }
   write("Deathknight is in good shape.\n");
   return 1;
 }

hit_player(arg){
 dmg = arg;
 amt = ((dmg*(90+random(5)))/100);
 lcp->hit_player(amt);
 return amt;
}

quit_dk() {
 write(BOLD+BLK+"Your Deathknight grows weak and you turn back into your original form.\n"+NORM); 
 write(BOLD+HIY+"\t\n\nYOU ARE NO LONGER A DEATHKNIGHT!!!\n\n"+NORM);
 say(BOLD+BLK+TPN+"'s deathknight grows weak and "+TP->query_pronoun()+" turns back into "+TP->query_possessive()+" form.\n"+NORM);
 destruct(TO);
return 1;
}
