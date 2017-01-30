#include "/players/mythos/myth/thief/def.h"
int coin,limit;
id(str) { return str == "money_bag" || str == "bag" || str == "money"; }

short() { return "A money bag"; }

long() { write("A small money bag to put your pickings in.\n"+
               "This is only used to store the money you pick.\n"+
               "You may also take money out - 'grab <amount>'\n"+
               "Currently there is "+coin+" coins stored.\n"+
               "Limit of storage is "+limit+" coins.\n");
        }

drop() { 
   tell_object(ep,"The bag disintegrates\n");
   destruct(this_object()); return 1;}
   
get() { return 1; }

query_weight() { return coin/1000 + 1; }
query_save_flag() { return 1; }
set_limit(n) { limit = n; }

reset(arg) {
  if(arg) return;
  coin = 0;
  limit = 10000;
}

add_coin(int n) { coin = coin + n; if(coin > limit) coin = limit; 
                  ep->recalc_carry(); }
query_coin() { return coin; }

init() {
  if(find_player(tpn) != tp) { destruct(this_object()); return 1; }
  if(tp == ep) add_action("grab","grab");
  add_action("put","put");
}

grab(str) {
int take;
  if(!str) { long(); return 1; }
  sscanf(str,"%d",take);
  if(take > coin) { 
    write("There is only "+coin+" coins in the bag.\n"); return 1; }
  if(take < 1) return 0;
  tp->add_money(take);
  add_coin(-take);
  write("You grab "+take+" coins from the bag\n"+
        "Current coinage in bag: "+coin+".\n"+
        "Coinage you carry: "+tp->query_money()+".\n");
return 1; }

put(str) {
string mo,moo;
  if(!str) return 0;
  if(sscanf(str,"%s in %s",mo,moo) == 2) {
    if(id(mo) || id(moo)) {
      write("You can not do that with the money bag.\n");
    return 1; } }
}