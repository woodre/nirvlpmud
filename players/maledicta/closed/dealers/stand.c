#include "/players/maledicta/ansi.h"
#define OWNER present(owner, environment())
#define DEALER present("drug_dealer", OWNER)
string owner;

get(){ return 0; }
drop(){ return 0; }
query_value(){ return 0; }
query_weight(){ return 5000000; }


id(str){ return str == "dealers_stand"; }
init(){
 if(!environment()) return;
 if(!present(owner, environment())) destruct(this_object());
 add_action("purchase", "purchase");
 }

set_owner(str){ owner = str; }
query_owner(){ return owner; }

purchase(str){
 if(!str){ write("purchase what?\n"); return 1; }
 
 if(!OWNER){ destruct(this_object()); return 0; }
 if(!DEALER){ destruct(this_object()); return 0; }
if(str == "injector"){
 if(DEALER->query_supply() < 1){
  tell_object(OWNER, "Your supply has run out. Go back to the shop and get more!\n");
  write(owner+" has run out of injectors.\n");
  return 1;
  }
 if(OWNER->query_attack()){ write("They are a little busy right now!\n"); return 1; }
 if(!this_player()->add_weight(1)){
  write("You can't carry it!\n"); 
  tell_object(OWNER, "They can't carry it!\n");
  return 1;
  }
if(this_player()->query_real_name() != owner){
 if(this_player()->query_money() < DEALER->query_price()){
  write("You cannot afford the "+DEALER->query_price()+" coins!\n");
  return 1; 
 }
}

 DEALER->add_supply(-1);

 if(this_player()->query_real_name() == owner) DEALER->add_ratio_buy(1);
 else DEALER->add_ratio_sold(1);

if(this_player()->query_real_name() != owner){
 OWNER->add_money(DEALER->query_price());
 this_player()->add_money(-DEALER->query_price());
}

if(this_player()->query_real_name() == owner){
 write("You draw from your own supply of injectors...\n");
 }
else{
 write("You buy a "+HIG+"Green Injector"+NORM+" from "+owner+".\n");
 tell_object(OWNER, this_player()->query_name()+" buys an injector from you.\n");
 }
 write_file("/players/maledicta/log/srecord", 
 OWNER->query_real_name()+" sold to "+this_player()->query_real_name()+" for "+DEALER->query_price()+" on "+
 ctime(time())+".\n");
 
 move_object(clone_object("/players/maledicta/town/obj/green.c"), this_player());
 if(present("ddea_guard", environment(this_player()))){
 present("ddea_guard", environment(this_player()))->call_caught(this_player(), owner);
 }
return 1;
}

if(str == "patch"){
 if(DEALER->query_psupply() < 1){
  tell_object(OWNER, 
  "Your supply of patches has run out. Go to the backroom and get more!\n");
  write(owner+" has run out of patches.\n");
  return 1;
  }
 if(OWNER->query_attack()){ write("They are a little busy right now!\n"); return 1; }
 if(!this_player()->add_weight(1)){
  write("You can't carry it!\n"); 
  tell_object(OWNER, "They can't carry it!\n");
  return 1;
  }
if(this_player()->query_real_name() != owner){
 if(this_player()->query_money() < DEALER->query_pprice()){
  write("You cannot afford the "+DEALER->query_pprice()+" coins!\n");
  return 1; 
 }
}

 DEALER->add_psupply(-1);

 if(this_player()->query_real_name() == owner) DEALER->add_ratio_buy(1);
 else DEALER->add_ratio_sold(1);

if(this_player()->query_real_name() != owner){
 OWNER->add_money(DEALER->query_pprice());
 this_player()->add_money(-DEALER->query_pprice());
}

if(this_player()->query_real_name() == owner){
 write("You draw from your own supply of patches...\n");
 }
else{
 write("You buy a "+HIG+"Green Patch"+NORM+" from "+owner+".\n");
 tell_object(OWNER, this_player()->query_name()+" buys a patch from you.\n");
 }
 write_file("/players/maledicta/log/srecord", 
 OWNER->query_real_name()+" sold a PATCH to "+this_player()->query_real_name()+" for "+DEALER->query_pprice()+" on "+
 ctime(time())+".\n");
 
 move_object(clone_object("/players/maledicta/closed/dealers/gpatch.c"), this_player());
 if(present("ddea_guard", environment(this_player()))){
 present("ddea_guard", environment(this_player()))->call_caught(this_player(), owner);
 }
return 1;
}
write("purchase what?\n");
 return 1;
 }