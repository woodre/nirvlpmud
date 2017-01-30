/* Bone Marketeer obj found within the undercity of Qual'tor 
   code taken from my old necromancer obj */
/* Thanks to Verte, Mal, and Jaraxle for helping debug things */

#include "/players/daranath/closed/market/defs.h"
#include <ansi.h>
#define CHAT "/players/daranath/closed/market/chatter.c"
#define SAVE "players/daranath/closed/market/member/"
#define SPELL "/players/daranath/closed/market/daemon.c"

int total, current, bigkill, expgain;
string title;

query_auto_load() {return "/players/daranath/closed/market/badge.c:"; }
id(str) {return str == "market_ob" || str == "badge" || str == "kill_check_object"; }
short() { return (WHT+"Badge"+NORM+" of the "+WHT+"Bone Marketeer"+NORM); }
long() {
write("The Bone Badge is a small, palm sized talisman fashioned of black\n"+
      "onyx and silver in the shape of a skull blindfolded and \n"+
      "gagged by lengths of chain.\n"+
      "<"+BOLD+"mkt_help"+NORM+"> for a list of powers every marketeer has.\n");
  }

drop() { return 1;}
get() { return 0;}

extra_look() {
/* verte help here */
    if(environment() == this_player())
      write("You belong to the "+WHT+"Bone Marketeers"+NORM+".\n");
    else write(environment()->query_name() + " belongs to the " +
        WHT + "Bone Marketeers" + NORM + ".\n");
}

init() {
if(environment(this_object()) == this_player()) {
  if(!restore_object(SAVE+tpn)) {
  total = 0;
  current = 0;
  bigkill = 0;
CHAT->chat_line("has joined the Bone Market",tp->query_real_name(),1);
   save_object(SAVE+tpn);
  }
  CHAT->add_membr(tp);
  expgain = 0;
write(WHT+"<------------------------------------------------------>"+NORM+"\n");
write(HIR+"       Welcome to the Bone Marketeers"+NORM+"\n");
write("\n");
write(HIW+"          ----> Market News <----"+NORM+"\n");
write("\n");
write(WHT+"There is now a history on the Market Chat line.\n"+NORM);
write("\n");
write(WHT+"<------------------------------------------------------>"+NORM+"\n");

add_action("market_overview","mkt_basics");
add_action("world_emote","emote");
add_action("market_score","mkt_score");
add_action("market_score","msc");
add_action("market_who","mkt_who");
add_action("market_rules","mkt_rules");
add_action("market_exchange","mkt_ex");
add_action("market_exchange","mkt_exchange");
add_action("market_update","mkt_update");
add_action("market_preserve","preserve");
add_action("market_quit","mkt_quit");
add_action("market_chat","mkt_chat");
add_action("market_chat","mc");
add_action("market_emote","mkt_emote");
add_action("market_emote","mce");
add_action("market_title","mkt_title");
add_action("market_help","mkt_help");
add_action("market_kills","topkill");
add_action("market_tops","topmark");
add_action("boneshop_list","shop_list");
add_action("market_consider","mkt_consider");
/* Taken out to eliminate problems with the bard guild
add_action("market_id","identify");
*/
add_action("market_id","id");
add_action("quit","quit");
add_action("market_save","mkt_save");
/* Added in 6-5-02  -Dar */
add_action("market_muffles","mkt_hush");
add_action("market_unmuffles","mkt_unhush");
}
  }

save_me() {save_object(SAVE+epn); return 1; }

market_save() { save_me(); tell_object(ep,"<"+HIW+"Market"+NORM+"> Bone Marketeer status saved.\n"); return 1; }

market_update() {
  move_object(clone_object("/players/daranath/closed/market/badge.c"),tp);
  write("<"+HIW+"Market"+NORM+"> Market Status Updated.\n");
  save_me();
  destruct(this_object());
return 1; }

market_muffles() {
  CHAT->sub_membr(tp);
return 1;
}

market_unmuffles() {
  CHAT->add_membr(tp);
return 1;
}

market_overview() {
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write(HIR+"           Marketeer of Bone Overview"+NORM+"\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
cat("/players/daranath/closed/market/docs/overview2.txt");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
return 1; 
}

market_consider(str) {
  object ctarg;
if(!str) {write("What did you want to consider?\n"); return 1; }

ctarg = present(str,environment(this_player()));
if(!ctarg) {write("Usage: consider <target>\n"); return 1; }

if(ctarg->query_level() < 11){
  write("That corpse would not be worth your time bringing to the market.\n"); }
if((ctarg->query_level() > 10) && (ctarg->query_level() < 16)){
  write("That corpse would be slightly less then average in value.\n"); }
if((ctarg->query_level() > 15) && (ctarg->query_level() < 19)){
  write("The corpse has an average Bone Market value.\n"); }
if(ctarg->query_level() == 19){
  write("That monster would be slightly better then average value to the Bone Market.\n"); }
if(ctarg->query_level() == 20){
  write("That monster would be a valuable corpse at the Bone Market.\n"); }
if(ctarg->query_level() == 21){
  write("That monster would be a very valuable corpse at the Bone Market.\n"); }
if(ctarg->query_level() > 21){
  write("That monster would be a rare and exotic corpse to the Bone Market,\n"+
        "quite the trophy to bring back for credit.\n"); }
return 1; 
}

market_help() {
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write(HIR+"               Basic Marketeer Abilities"+NORM+"\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write("   "+HIW+"mkt_basics"+NORM+": Overview of the Bone Marketeers\n");
write("   "+HIW+"mkt_chat"+NORM+" and "+HIW+"mkt_emote"+NORM+": Marketeer Chat Line ("+HIW+"mc"+NORM+", "+HIW+"mce"+NORM+" for short)\n");
write("   "+HIW+"mkt_who"+NORM+": Marketeer who listing\n");
write("   "+HIW+"mkt_score"+NORM+": Personal Bone Marketeer status ("+HIW+"msc"+NORM+" for short)\n");
write("   "+HIW+"mkt_rules"+NORM+": Rules of the Bone Marketeer\n");
write("   "+HIW+"mkt_update"+NORM+": Update this object\n");
write("   "+HIW+"mkt_title"+NORM+": Take on a bone marketeer title\n");
write("   "+HIW+"mkt_save"+NORM+": Save your Market status at any time\n");
write("   "+HIW+"mkt_quit"+NORM+": Leave the Bone Marketeers\n");
write("   "+HIW+"mkt_help"+NORM+": This listing\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write(HIR+"               Special Marketeer Abilities"+NORM+"\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write("   "+HIW+"preserve"+NORM+": Preserve a corpse for transport to the Market\n");
write("             Preserve Corpse costs "+HIR+"25"+NORM+" sps per use\n");
write("   "+HIW+"mkt_exchange"+NORM+": Turn in a corpse for credit at the Market\n");
write("               "+HIW+"mkt_ex"+NORM+" for short\n");
write("   "+HIW+"shop_list"+NORM+": Listing of items currently available at the\n"+
      "              Bone Market Shop and costs for same\n");
write("   "+HIW+"id"+NORM+": Identify a weapon, armor or heal.\n");
write("       identify costs "+HIR+"25"+NORM+" sps and "+HIW+"25"+NORM+" credits to use\n");
write("   "+HIW+"mkt_consider"+NORM+": Consider if a monster would make a good exchange\n");
write("   "+HIW+"topmark"+NORM+": Shows a listing of the top Bone Marketeers\n");
write("   "+HIW+"topkill"+NORM+": Shows a listing of the top individual kills\n");
write("            This will not work if you have a party object\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
return 1;
}

boneshop_list() {
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write("          "+HIR+"   Currently Available at the Bone Shop"+NORM+"\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write(HIR+"     Item Name            Coins    Credits    Notes"+NORM+"\n");
write("   "+HIW+"Recall Orb"+NORM+"             100      200          \n");
write("   "+HIW+"Breathing Scarf"+NORM+"        100      250          \n");
write("   "+HIW+"Rusty Meat Hook"+NORM+"        850      400        Weapon\n");
write("   "+HIW+"Unholy Essence"+NORM+"         1200     500        Unique Heal\n");
write("   "+HIW+"Blood of Innocents"+NORM+"     1500     650        Intox Heal\n");
write("   "+HIW+"Piece of Flesh"+NORM+"         1700     750        Food Heal\n");
write("   "+HIW+"Shard of Bone"+NORM+"          1700     750        Drink Heal\n");
write("   "+HIW+"Rancid Ichor"+NORM+"           1700     750        Combo Heal\n");
write("   "+HIW+"Wand of Immolation"+NORM+"     500      15000      Unique Item\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
return 1;
}

market_id(str) {
  string arval, wepval, itemwt;
  object id_ob;
if(!str) {write("<"+HIW+"Market"+NORM+"> What do you want to identify?\n"); return 1; }

id_ob = present(str, this_player());

if(!id_ob) {write("<"+HIW+"Market"+NORM+"> What do you want to identify?\n"); return 1; }
if(query_current() < 25) {write("<"+HIW+"Market"+NORM+"> You need 25 credits to identify something.\n"); return 1; }
if(this_player()->query_sp() < 25) {write("<"+HIW+"Market"+NORM+"> You need 25 spell points to identify someting.\n"); return 1; }

if(id_ob->query_type() == "armor") {
if(id_ob->query_weight() < 2) {itemwt = "very light"; }
if(id_ob->query_weight() == 2) {itemwt = "light"; }
if(id_ob->query_weight() == 3) {itemwt = "moderate"; }
if(id_ob->query_weight() == 4) {itemwt = "heavy"; }
if(id_ob->query_weight() > 4) {itemwt = "very heavy"; }
if(id_ob->armor_class() < 2) {arval = "poor"; }
if(id_ob->armor_class() == 2) {arval = "weak"; }
if(id_ob->armor_class() == 3) {arval = "average"; }
if(id_ob->armor_class() == 4) {arval = "good"; }
if(id_ob->armor_class() > 4) {arval = "outstanding"; }
}
if(!(id_ob->query_type() == "armor")) {
if(id_ob->query_weight() < 1) {itemwt = "extremly light"; }
if(id_ob->query_weight() == 1) {itemwt = "light"; }
if(id_ob->query_weight() == 2) {itemwt = "moderate"; }
if(id_ob->query_weight() == 3) {itemwt = "heavy"; }
if(id_ob->query_weight() > 3) {itemwt = "very heavy"; }
if(id_ob->armor_class() < 1) {arval = "not an armor"; }
if(id_ob->armor_class() == 1) {arval = "average"; }
if(id_ob->armor_class() == 2) {arval = "very good"; }
if(id_ob->armor_class() > 2) {arval = "otherworldly"; }
if(call_other(id_ob,"weapon_class") == 0) {wepval = "not a weapon"; }
if((id_ob->weapon_class() > 0) && (id_ob->weapon_class() < 6)) {wepval = "very poor"; }
if((id_ob->weapon_class() > 5) && (id_ob->weapon_class() < 10)) {wepval = "poor"; }
if((id_ob->weapon_class() > 9) && (id_ob->weapon_class() < 15)) {wepval = "average"; }
if((id_ob->weapon_class() > 14) && (id_ob->weapon_class() < 18)) {wepval = "good"; }
if(id_ob->weapon_class() == 18) {wepval = "excellent"; }
if((id_ob->weapon_class() > 18) && (id_ob->weapon_class() < 22)) {wepval = "outstanding"; }
if(id_ob->weapon_class() > 21) {wepval = "otherworldly"; }
}
if(!wepval) {wepval = "not a weapon"; }

write(WHT+"<------------------------------------------->"+NORM+"\n");
write(HIR+"      Bone Market Identify"+NORM+"\n");
write(WHT+"<------------------------------------------->"+NORM+"\n");
write(id_ob->short()+"\n");
write(pad("Weapon Rating:",16));
write(HIW+wepval+NORM+"\n");
write(pad("Armor Rating:",16));
write(HIW+arval+NORM+"\n");
write(pad("Item Weight:",16));
write(HIW+itemwt+NORM+"\n");
write(pad("Item Value:",16));
write(HIW+id_ob->query_value()+NORM+"\n");
write(WHT+"<------------------------------------------->"+NORM+"\n");
write("  You pay "+HIW+"25"+NORM+" Credits for the Identify.\n");
write(WHT+"<------------------------------------------->"+NORM+"\n");

this_player()->add_spell_point(-25);
add_current(-50); 
save_me();
return 1;
}

market_chat(str) {
  if(!str) { write("What do you want to say over the Market line.\n"); return 1; }
  if(str == "history") {
tail("/players/daranath/closed/market/history");
return 1; }
  CHAT->chat_line(str,tp->query_name());
write_file("/players/daranath/closed/market/history","<"+HIW+"Market"+NORM+"> "+tp->query_name()+" says: "+str+"\n");
return 1; }

kill_check(ob) {
  object marketeer;
  int this_kill;

this_kill = (int)ob->calculate_evaluated_worth(environment());
marketeer = environment(this_object());
if(!this_kill) {return; }
/*
write("<"+HIW+"Market"+NORM+"> Exp for Kill: "+HIW+this_kill+NORM);
*/
tell_object(marketeer, "<"+HIW+"Market"+NORM+"> Exp for Kill: "+HIW+this_kill+NORM); 
   add_expgain(this_kill);
if((this_kill > query_bigkill()) && (this_player()->query_level() < 20) && (!present("party_object",environment(this_object())))) {
  set_bigkill(this_kill);
tell_object(marketeer, HIY+" NEW HIGH!"+NORM);
  save_me();
  }
tell_object(marketeer, "\n");
}

market_emote(str) {
  if(!str) { write("What do you want to emote over the Market line.\n"); return 1; }
  CHAT->chat_line(str,tp->query_name(),1);
write_file("/players/daranath/closed/market/history","<"+HIW+"Market"+NORM+"> "+tp->query_name()+" "+str+"\n");
return 1; 
}

market_title() {
 title = ("the "+WHT+"Marketeer of Bone"+NORM);
  tp->set_title(title);
  write("<"+HIW+"Market"+NORM+"> Bone Marketeer Title Set.\n");
return 1; }

market_quit() {
	  tp->reset(1);
	  command("save",tp);
write("Sadly, you have decided to leave my Bone Marketeers.\nGoodbye!\n");
	  CHAT->sub_membr(tp);
	  CHAT->chat_line("has left the Bone Market",tp->query_real_name(),1);
      rm("/"+SAVE+tpn+".o");
	  destruct(this_object());
return 1; }

quit() {
  market_save();
  CHAT->sub_membr(ep);
return 0;
}

world_emote(str) {
  if(!str) return 0;
  tell_room(environment(tp),tp->query_name()+" "+str+"\n");
return 1; }

market_rules() {
 write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write(HIR+"               Rules of the Bone Marketeer"+NORM+"\n");
 write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write("The following are the only rules for the Bone Market. I don't want to\n"+
      "have any rules, but they are needed.  Here goes:\n");
write("\nA - There will be no offensive language on the Market Channel.\n");
write("    Treat this channel as if it was gossip.\n");
write("\nB - You will not harrass another player or spam on this line.\n");
write("    You get one warning, then you will loose the rights to be\n"+
      "    on this channel.\n");
write("\nC - The worst possible offense of the Bone Market is corpse stealing.\n");
write("    Purchasing and bartering for corpses is fine, as is accepting \n"+
      "    donations from players. "+HIW+"Corpse Stealing will not happen!"+NORM+"\n"+
      "    If caught - You will be banished from the channel and your corpse\n"+
      "    will be highly sought after.\n");
write("\nD - I reserve the right to toss anyone at anytime if I feel\n"+
      "    its necessary...\n");
write("\nFinally: Do not interfere if another player is trying to roleplay\n"+
      "         while on Nirvana. Even if you hate it, don't ruin \n"+
      "         someone else's fun.     -Daranath\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
return 1;
}

market_exchange() {
  if(!present("corpse", this_player())) {
write("You must have a corpse present to exchange at the Bone Market.\n");
return 1; }
  if(!present("xion",environment(this_player()))); {
write("You must be at the Bone Market to exchange a corpse.\n");
return 1; }
return 0;
}

market_kills() {
if(!present("dralgos")) {
write("Dralgos the Necromancer keeps track of those kills, you should go \n"+
      "see him at the Bone Market Shop to get this information.\n");
return 1; }
return 0;
}

market_tops() {
if(!present("dralgos")) {
write("The top Marketeers listing can be found at the Bone Market Shop\n"+
      "from Dralgos, the Dwarven Necromancer only.\n");
return 1; }
return 0;
}

query_total() { return total; }
query_current() { return current; }
query_bigkill() { return bigkill; }
query_expgain() { return expgain; }

add_total(int num) { total += num; }
add_current(int num) { current += num; }
add_expgain(int num) { expgain += num; }
set_bigkill(int num) { bigkill = num; save_me(); return 1; }

market_score() {SPELL->market_score(); return 1; }
market_who() {SPELL->market_who(); return 1; }
market_preserve(str) {SPELL->market_preserve(str); return 1; }

