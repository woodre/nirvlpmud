#include "/players/maledicta/ansi.h"
#define USER environment()
#define NAME USER->query_name()
#define TP this_player()
#define DEALER present("drug_dealer", ppl[i])
#define STAND present("dealers_stand", environment(USER))
#define CHUNK 20
query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }

static string more_file;        /* Used by the more command */
static int more_line;

int warned;
int supply,rsupply;
int psupply;
int pprice;
int ratio_sold;
int ratio_buy;
int patches_allowed;
int price;
static int no_change;

id(str){
   return str == "drug_dealer" || str == "scarf";
}

query_auto_load(){ 
save_object("players/maledicta/closed/dealers/members/"+USER->query_real_name());
return "/players/maledicta/closed/dealers/dealer.c:"; 
}

long(){
   write(
    "This is a light "+HIG+"green"+NORM+" scarf that is tied around your right arm. It\n"+
    "symbolizes your involvement as an Injector Dealer. For help on what\n"+
    "to do, type 'help dealer'.\n");   
    return 1;
}

extra_look(){
  return NAME+" has a "+HIG+"green scarf"+NORM+" tied around "+USER->query_possessive()+" right arm";
}

init(){
   if(!environment()) return;
   if(this_player())
   if(this_player() != environment()) return;
  tell_object(this_player(), "\n\n\n\n\n\nNo one is dealing, so this goes away.\n\n\n\n\n\n\n");
   destruct(this_object());
    return 1;
   supply = 5;
   rsupply = 0;
   price = 1000;
   if(!restore_object("players/maledicta/closed/dealers/members/"+USER->query_real_name())){
    save_object("players/maledicta/closed/dealers/members/"+USER->query_real_name());
    }
   add_action("set_up_shop", "set");
   add_action("offer_goods", "offer");
   add_action("go_straight", "go_straight");
   add_action("help", "help");
   add_action("goods", "goods");
   add_action("pick_up_package", "pick");
   
   add_action("set_price", "set_price");
   add_action("set_pprice", "patch_price");
   add_action("locations", "locations");
 if(this_player()->query_real_name() == "wasted" || this_player()->query_level() > 19){
   add_action("dealer", "dealer");
   add_action("rdealer", "rdealer");
   add_action("dealers", "dwho");
   add_action("sell_record", "srecord");
   add_action("patch_allow", "toggle_patches");
   }
}

sell_record(){
 more("/players/maledicta/log/srecord");
 return 1;
 }

set_patches_allowed(int i){ patches_allowed = i; }
query_patches_allowed(){ return patches_allowed; }
query_pprice(){ return pprice; }



dealer(str){
object peep;
 if(!str){ write("make who a dealer?\n"); return 1; }
peep = find_living(str);
if(!peep){ write("Who?\n"); return 1; }
if(!present(peep, environment(this_player()))){
  write("You don't see them here.\n");
  return 1;
  }
if(present("drug_dealer", peep)){
 write("They are already a dealer.\n");
 return 1;
 }
move_object(clone_object("/players/maledicta/closed/dealers/dealer.c"), peep);
write("You make "+str+" a dealer.\n");
tell_object(peep, this_player()->query_name()+" ties a green scarf around your arm.\n");
return 1;
}

rdealer(str){
object peep;
 if(!str){ write("remove who as a dealer?\n"); return 1; }
peep = find_living(str);
if(!peep){ write("Who?\n"); return 1; }
if(!present(peep, environment(this_player()))){
  write("You don't see them here.\n");
  return 1;
  }
if(!present("drug_dealer", peep)){
 write("They aren't a dealer.\n");
 return 1;
 }
destruct(present("drug_dealer", peep));
write("You remove "+str+" as a dealer.\n");
tell_object(peep, this_player()->query_name()+" removes you as a dealer.\n");
return 1;
}

patch_allow(str){
object peep;
object duh;
 if(!str){ write("allow which dealer to sell patches?\n"); return 1; }
peep = find_living(str);
duh = present("drug_dealer", peep);
if(!peep){ write("Who?\n"); return 1; }
if(!present(peep, environment(this_player()))){
  write("You don't see them here.\n");
  return 1;
  }
if(!duh){
 write("They aren't a dealer.\n");
 return 1;
 }
if(duh->query_patches_allowed()){
 duh->set_patches_allowed(0);
 write("You remove "+str+"'s ability to sell patches.\n");
 tell_object(peep, this_player()->query_name()+" removes you as a patch dealer.\n");
 }
else{
 duh->set_patches_allowed(1);
 write("You allow "+str+" to sell patches.\n");
 tell_object(peep, this_player()->query_name()+" adds you as a patch dealer.\n");
 }
return 1;
}


dealers(){
 object ppl;
 int i;
 ppl = users();
 write("Name:          Sold:  SelfBought:  Supply:   Price: \n");
 for(i = 0; i < sizeof(ppl); i++){
  if(DEALER){
    write(ppl[i]->query_real_name()+"\t");
    write(DEALER->query_ratio_sold()+"\t");
    write(DEALER->query_ratio_buy()+"\t\t");
    write(DEALER->query_supply()+"\t");
    write(DEALER->query_price()+"\n");
    }
 }
 return 1;
}


set_up_shop(str){
 object stand;
 string rmstr;
 if(!str) return;
 if(str != "up shop") return;
 if(STAND){
  write(STAND->query_owner()+" has already set up here.\n");
  return 1;
 }
 rmstr = file_name(environment(USER));
 if(rmstr == "room/vill_shore" || rmstr == "room/alley" || rmstr == "room/clearing" ||
 rmstr == "room/ruin" || rmstr == "room/inn" || rmstr == "room/ptroom" || 
 rmstr == "room/well" || rmstr == "room/townh" || rmstr == "players/mythos/enterance" ||
 rmstr == "players/eurale/RMS/warp" || rmstr == "players/pathfinder/detroit/rooms/entrance"){
 stand = clone_object("/players/maledicta/closed/dealers/stand.c");
 stand->set_owner(USER->query_real_name());
 write_file("/players/maledicta/log/setup",
 NAME+" set up shop at "+rmstr+" on "+ctime(time())+".\n");
 move_object(stand, environment(USER));
 tell_room(environment(this_player()),
 this_player()->query_name()+" leans against a nearby wall.\n", ({ this_player() }));
 write("You lean against a nearby wall and wait. You are ready for customers.\n");
 return 1;
 }
 write("You are not in a location for dealing.\n");
 return 1;
 }

offer_goods(str){ 
 object peep;
 if(!str){ write("offer to who?\n"); return 1; }
 peep = present(str, environment(USER));
 if(!peep){ write("you don't see them here.\n"); return 1; }
 if(!living(peep)){ write("You can only offer to the living.\n"); return 1; }
 if(peep->is_npc()){ write("Players only!\n"); return 1; }
 tell_object(peep, 
 NAME+" offers you a good deal on "+HIG+"Green"+NORM+" Injectors.\n"+
 "  ["+price+"] coins per injector. "+USER->query_pronoun()+" has "+supply+" available.\n"+
 "  Just '"+HIG+"purchase injector"+NORM+"' to buy from "+USER->query_objective()+".\n");
 if(patches_allowed)
 tell_object(peep,
 NAME+" also has a deal on "+HIG+"Green"+NORM+" Patches.\n"+
 "  ["+pprice+"] coins per patch with a supply of "+psupply+".\n");
 write("You offer your goods to "+capitalize(str)+". Your price cannot\n"+
       "change for 5 minutes.\n");
 no_change = 1;
 call_out("no_changer", 300);
 return 1;
 }

no_changer(){ no_change = 0; return 1; }

go_straight(){ 
  write("You decide to go straight...\n");
  rm("/players/maledicta/closed/dealers/members/"+USER->query_real_name()+".o");
  destruct(this_object());
  return 1;
  }

help(str){
 if(!str) return;
 if(str != "dealer") return;
 write(
 "\n\n             -=[ "+HIG+"Dealer Help"+NORM+" ]=-\n"+
 "As an Injector Dealer you can do the following:\n"+
 "  set up shop     - If you are at an appropriate place, you can\n"+
 "                    set up to start selling to players.\n"+
 "  offer <who>     - offer your goods to a player that is present.\n"+
 "  goods           - Find out how many injectors you have left.\n"+
 "  pick up package - Pick up more injectors from the derellia heal\n"+
 "                    shop. You must be there to do this!\n"+
 "  set_price <amount>  - Set the price of how much you will sell\n"+
 "                        your injectors for. 1000 - 1300 coins.\n"+
 "                        The higher, the more profit!\n");
if(patches_allowed){
 write(
 "  pick up patches - pick up more patches in the backroom of derellia.\n"+
 "  patch_price <#> - set the price of patches. 1 - 1000.\n");
 }
 write(
 "  locations       - show locations of where you can deal from.\n\n"+
 HIG+"Remember, you are out to deal to others, not just yourself! Be\n"+
 "sure your ratio is much greater for number dealt to others over\n"+
 "yourself. It's important to get people hooked! Repeat business!"+NORM+"\n");
 if(this_player()->query_real_name() == "wasted" || this_player()->query_level() > 19){
 write(
 "  dealer <who>  - make someone a dealer.\n"+
 "  rdealer <who> - remove someone from the dealers.\n"+
 "  dwho - See who is on and their stats.\n"+
 "  srecord - Sell record of all transactions.\n"+
 "  toggle_patches <who> - allow a dealer to sell patches.\n");

 }
 return 1;
 }


locations(){
 write(
 "All directions start from the village green:\n"+
 HIG+"4w"+NORM+" - clearing.\n"+
 HIG+"5e"+NORM+" - in front of pizza hut.\n"+
 HIG+"3e,n,e"+NORM+" - old party room.\n"+
 HIG+"2e,n,w"+NORM+" - trix's alley.\n"+
 HIG+"4w,3n,e"+NORM+" - the ruins.\n"+
 HIG+"2n"+NORM+" - the town hall.\n"+
 HIG+"2e,s,d"+NORM+" - down the well.\n"+
 HIG+"5e,5n,w"+NORM+" - the inn.\n"+
 "Remember, respect the territory of the other dealers.\n"+
 "Deal from a different location!\n"+
 "If you have found a unique location you want to deal\n"+
 "from, mudmail Maledicta about it. He will add it.\n");
 return 1;
 }

goods(){
 write(
 "Your current supply is at "+HIG+supply+NORM+", at a price of "+HIB+price+NORM+".\n");
if(patches_allowed)
 write(
 "Patch supply is at "+psupply+", at a price of "+pprice+".\n");
 return 1;
 }

pick_up_package(str){
 if(!str) return;
 if(str == "up package"){
 if(file_name(environment(USER)) != "players/maledicta/town/rooms/t10") return;
 if(!present("clerk_owner", environment(USER))){
   write("You do not see the owner here!\n");
   return 1;
   }
if(supply){
   write("The clerk says, 'You still have some on you...'\n");
   return 1;
   }
if(ratio_sold > 100 || ratio_buy > 100){
 if(ratio_buy > ratio_sold){
   if(warned){ 
    write("The clerk shakes her head and says, 'You didn't listen.'\n"+
          "You are no longer allowed to deal.\n");
    write_file("/players/maledicta/log/dealers",
    NAME+" was removed on "+ctime(time())+".\n");
    destruct(this_object());
    return 1; 
    }
   else{
    write("The clerk shakes her head and says,\n"+
          " 'You need to sell to others and not keep them all for youself! \n"+
          "  I am giving you a warning this time, but from now on, sell to\n"+
          "  others more than you buy for yourself.'\n");
    write_file("/players/maledicta/log/dealers", 
    NAME+" was warned on "+ctime(time())+".\n");
    warned = 1;
    ratio_sold = 0;
    ratio_buy = 0;
    rsupply = 0;
    }
  }
}
rsupply += 1;

if(rsupply > 2500){
 if(TP->query_money() < 20000){ write("You do not have 20,000 coins!\n"); return 1; }
 else{
 supply += 20;
 TP->add_money(-20000);
 write("You pay 20000 coins to the clerk.\n");
 }
 }
else if(rsupply > 1200){
 if(TP->query_money() < 15000){ write("You do not have 15,000 coins!\n"); return 1; }
 else{
 supply += 15;
 TP->add_money(-15000);
 write("You pay 15000 coins to the clerk.\n");
 }
 }
else if(rsupply > 500){
 if(TP->query_money() < 12000){ write("You do not have 12,000 coins!\n"); return 1; }
 else{
 supply += 12;
 TP->add_money(-12000);
 write("You pay 12000 coins to the clerk.\n");
 }
 }
else if(rsupply > 100){
 if(TP->query_money() < 8000){ write("You do not have 8,000 coins!\n"); return 1; }
 else{
 supply += 8;
 TP->add_money(-8000);
 write("You pay 8000 coins to the clerk.\n");
 }
 }
else{
 if(TP->query_money() < 5000){ write("You do not have 5,000 coins!\n"); return 1; }
 else{
 supply += 5;
 TP->add_money(-5000);
 write("You pay 5000 coins to the clerk.\n");
 }
 }
save_object("players/maledicta/closed/dealers/members/"+USER->query_real_name());
write("You pick up a supply of "+HIG+supply+NORM+" injectors.\n");
return 1;
}

 
 if(str == "up patches"){
 if(!patches_allowed) return; 
if(file_name(environment(USER)) != "players/maledicta/town/rooms/backroom") return;
if(psupply){
   write("You still have some on you.\n");
   return 1;
   }
if(ratio_sold > 100 || ratio_buy > 100){
 if(ratio_buy > ratio_sold){
   if(warned){ 
    write("The clerk enters and shakes her head, saying, 'You didn't listen.'\n"+
          "You are no longer allowed to deal.\n");
    write_file("/players/maledicta/log/dealers",
    NAME+" was removed on "+ctime(time())+".\n");
    destruct(this_object());
    return 1; 
    }
   else{
    write("The clerk shakes her head and says,\n"+
          " 'You need to sell to others and not keep them all for youself! \n"+
          "  I am giving you a warning this time, but from now on, sell to\n"+
          "  others more than you buy for yourself.'\n");
    write_file("/players/maledicta/log/dealers", 
    NAME+" was warned on "+ctime(time())+".\n");
    warned = 1;
    ratio_sold = 0;
    ratio_buy = 0;
    rsupply = 0;
    }
  }
}
rsupply += 1;

if(rsupply > 2500){
 if(TP->query_money() < 12000){ write("You do not have 12,000 coins!\n"); return 1; }
 else{
 psupply += 20;
 TP->add_money(-12000);
 write("You pay 20000 coins to the clerk.\n");
 }
 }
else if(rsupply > 1200){
 if(TP->query_money() < 9000){ write("You do not have 9,000 coins!\n"); return 1; }
 else{
 psupply += 15;
 TP->add_money(-9000);
 write("You pay 9000 coins to the clerk.\n");
 }
 }
else if(rsupply > 500){
 if(TP->query_money() < 7200){ write("You do not have 7,200 coins!\n"); return 1; }
 else{
 psupply += 12;
 TP->add_money(-7200);
 write("You pay 7200 coins to the clerk.\n");
 }
 }
else if(rsupply > 100){
 if(TP->query_money() < 4800){ write("You do not have 4,800 coins!\n"); return 1; }
 else{
 psupply += 8;
 TP->add_money(-4800);
 write("You pay 4800 coins to the clerk.\n");
 }
 }
else{
 if(TP->query_money() < 3000){ write("You do not have 3,000 coins!\n"); return 1; }
 else{
 psupply += 5;
 TP->add_money(-3000);
 write("You pay 3000 coins to the clerk.\n");
 }
 }
save_object("players/maledicta/closed/dealers/members/"+USER->query_real_name());
write("You pick up a supply of "+HIG+psupply+NORM+" patches.\n");
return 1;
}
write("Pick up what?\n");
return 1;
}

set_price(int i){
 int newprice;
 if(no_change){ write("You just quoted a price!\n"); return 1; }
 if(!i){ write("set_price 1-2000\n"); return 1; }
 sscanf(i, "%d", newprice);
 if(newprice < 1 || newprice > 2000){
  write("You must set the price between 1 and 2000 coins.\n");
  return 1;
  }
 price = newprice;
 write("You set the price to "+newprice+".\n");
 save_object("players/maledicta/closed/dealers/members/"+USER->query_real_name());
 return 1;
 }   

set_pprice(int i){
 int newprice;
 if(no_change){ write("You just quoted a price!\n"); return 1; }
 if(!i){ write("patch_price 1-1000\n"); return 1; }
 sscanf(i, "%d", newprice);
 if(newprice < 1 || newprice > 1000){
  write("You must set the price between 1 and 2000 coins.\n");
  return 1;
  }
 pprice = newprice;
 write("You set the price to "+newprice+".\n");
 save_object("players/maledicta/closed/dealers/members/"+USER->query_real_name());
 return 1;
 }   


 query_price(){ return price; }
 set_supply(int i){ supply = i; }
 add_supply(int i){ 
 save_object("players/maledicta/closed/dealers/members/"+USER->query_real_name());
 supply += i; }
 query_supply(){ return supply; }
 add_ratio_sold(int i){ ratio_sold += i; }
 query_ratio_sold(){ return ratio_sold; }
 add_ratio_buy(int i){ ratio_buy += i; }
 query_ratio_buy(){ return ratio_buy; }
 set_psupply(int i){ psupply = i; }
 add_psupply(int i){ 
save_object("players/maledicta/closed/dealers/members/"+USER->query_real_name());
 psupply += i; }
 query_psupply(){ return psupply; }


more(str) {
  string tmore;
  string pwd,tilda,blah;
     if(!pwd) pwd="";
    if (!str)
	return 0;
   tmore = str;
   blah = pwd;
   if(extract(blah,0,0)!="/") blah = "/"+blah;
   if(extract(tmore,0,0)=="~") {
     tilda=extract(tmore,1,strlen(tmore));
     tmore = "/players/"+TP->query_real_name()+tilda;
    }
   if(extract(tmore,0,0)!="/") tmore = blah+tmore;
   if(file_size(tmore) < 1) {
       write("That file does not exist.\n");
       return 1;
    }
    more_file = str;
    more_line = 1;
    if (cat(more_file, more_line, CHUNK) == 0) {
	write("No such file\n");
	return 1;
    }
    input_to("even_more");
    write("More: (line " + (CHUNK + 1) + ") ");
    return 1;
}

static even_more(str) {
    if (str == "" || str == "d")
	more_line += CHUNK;
    else if (str == "q") {
	write("Ok.\n");
	return;
    } else if (str == "u") {
	more_line -= CHUNK;
	if (more_line < 1)
	    more_line = 1;
    }
    if (cat(more_file, more_line, CHUNK) == 0) {
	more_file = 0;
	write("EOF\n");
	return;
    }
    write("More: (line " + (more_line + CHUNK) + ") ");
    input_to("even_more");
}

tail_file(path)
{
    if (!path)
	return 0;
    if (!tail(path))
	return 0;
    return 1;
}

 


 
