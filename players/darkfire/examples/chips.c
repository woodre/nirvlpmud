#include "/obj/ansi.h"
int five_coin,one_coin,twfive_coin,hundo_coin,g_coin;

short() { return "A stack of casino chips"; }

long() {
   write("A stack of casino chips, each is embossed with a hologram\n"+
      "logo of the Casa de Nirvana Hotel and Casino.\n"+
      "The stack of chips contains the following:\n"+
      BLU+"Blue 1 coin chips      \t"+one_coin+NORM+"\n"+
      RED+"Red 5 coin chips       \t"+five_coin+NORM+"\n"+ 
      GRN+"Green 25 coin chips    \t"+twfive_coin+NORM+"\n"+
      BWHT+BLK+"Black 100 coin chips   \t"+hundo_coin+NORM+"\n"+         
      MAG+"Magenta 1000 coin chips\t"+g_coin+NORM+"\n\n");
   return 1;
}

query_value() { return 0; }
query_weight() { return 0; }
query_save_flag() { return 1; }
query_chip_value() {
   int value;
   value = one_coin+5*five_coin+25*twfive_coin+100*hundo_coin+1000*g_coin;
   return value;
}

id(str) { 
   return str == "chip" || str == "chips" || str == "casino chips" || 
   str == "poker chips" || str == "ND";
}

init() {
  object mychips, env;
  env = environment();

  if( !env )
    return;

  mychips = present("casino chips 2", env );
  if( !mychips )
    return;
  else {
    mychips->add_chip_value( query_chip_value() );
    add_chip_value( -query_chip_value() );
    destruct( this_object() );
    return 1;
  }
}

get() { 
  /*object mychips;
  mychips = present("casino chips", this_player() );
  if( !mychips )
    return 1;
  else {
    mychips->add_chip_value( query_chip_value() );
    add_chip_value( -query_chip_value() );
    set_heart_beat(1);
    return 1;
  }
*/
  return 1;
}
drop() { return 1; }

reset(arg) {
   if(arg) return;
   return;
}
add_chip_value(arg) {
   int one,five,twfive,hundo,g,tmp;
   
   if(query_chip_value()) {
      tmp = query_chip_value();
      tmp += arg;
      one_coin = 0; five_coin = 0; twfive_coin = 0;
      hundo_coin = 0; g_coin = 0;
      add_chip_value(tmp);
      return 1; }
   
   g = arg/1000;
   arg = arg - g*1000;
   hundo = arg/100;
   arg = arg - hundo*100;
   twfive = arg/25;
   arg = arg - twfive*25;
   five = arg/5;
   arg = arg - five*5;
   one = arg;
   
   one_coin+=one; five_coin+=five; twfive_coin+=twfive; 
   hundo_coin+=hundo; g_coin+=g;
   return 1;
}

heart_beat() {
    if (query_chip_value() == 0)
        destruct(this_object());
}

