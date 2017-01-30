#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#define ROOT2 "/players/daranath/closed/market/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
if(!present("xion")) {
move_object(clone_object("/players/daranath/closed/market/mon/xion.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Bone Market"+NORM+")");
    long_desc=
"               "+WHT+"Market of Bone"+NORM+"\n"+
"A large cavern has been converted into the infamous Market of Bone here\n"+
"within Qual'tors UnderCity. Tables and benches are scattered about the\n"+
"area, corpses and bits of bone scattered about the room. The eastern\n"+
"wall has a large stone archway, leading to the adjacent shop.\n";

    items=({
"cavern","The large cavern has been coverted into the Bone Marketplace",
"market","The marketplace is alive with activity. Long tables are about the area, several\n"+
     "with corpses laying upon them",
"corpses","Some of the corpses have been magically preserved",
"tables","Long wooden tables are here to the corpses upon",
"benches","The long benches are about a couple of the tables, allowing examinations of\n"+
     "the corpses themselves",
"archway","A large stone archway leads eastwards into the Bone Shop",
"stone","The dark grey stone that exists throughout the city is here as well",
"shop","The Bone Shop is where credits can be spent for members of the Bone Market",
    });

    dest_dir=({
ROOT+"undercity4.c","north",
ROOT+"bone_shop.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("market_exchange","mkt_exchange");
add_action("market_exchange","mkt_ex");
add_action("market_info","ask");
add_action("market_join","join");
    }

search() {
write("Bits of bone and dried blood are all about the area.\n");
  say(tp +" searches the area.\n");
return 1;
}

market_exchange(str) {
  object corp, ob;
  int creds;
if(!str) {write("What do you want to exchange?\n"); return 1; }
if(str != "corpse") {
write("You can only exchange a corpse for credit.\n");
return 1; }
if(!present("corpse", this_player())){
write("You must have a corpse to exchange here.\n");
return 1; }

ob = present("market_ob",this_player());
corp = present("corpse", this_player());

if(corp->id("bad_corpse")) {
write("Xion says: Unfortunatly, we have no use for that corpse here.\n"+
      "          You'll have to find another use for it.\n");
return 1; }

if(corp->query_corpse_level() < 11) {
  creds = (25+random(50));  }
if((corp->query_corpse_level() > 10) && (corp->query_corpse_level() < 16)) {
  creds = (50+random(50)); }
if((corp->query_corpse_level() > 15) && (corp->query_corpse_level() < 19)) {
  creds = (75+random(100)); }
if(corp->query_corpse_level() == 19) {
  creds = (100+random(100)); }
if(corp->query_corpse_level() == 20) {
  creds = (125+random(125)); }
if(corp->query_corpse_level() == 21) {
  creds = (150+random(125)); }
if(corp->query_corpse_level() == 22) {
  creds = (200+random(150)); }
if(corp->query_corpse_level() == 23) {
  creds = (250+random(175)); }
if(corp->query_corpse_level() == 24) {
  creds = (300+random(200)); }
if(corp->query_corpse_level() == 25) {
  creds = (350+random(225)); }
if(corp->query_corpse_level() == 26) {
  creds = (400+random(250)); }
if(corp->query_corpse_level() == 27) {
  creds = (450+random(300)); }
if(corp->query_corpse_level() == 28) {
  creds = (500+random(350)); }
if(corp->query_corpse_level() == 29) {
  creds = (750+random(400)); }
if(corp->query_corpse_level() == 30) {
  creds = (1000+random(1000)); }
if(corp->query_corpse_level() > 30) {
  creds = (1500+random(1500)); }

write("As you lay the corpse down upon one of the long tables,\n"+
      "Xion wanders over and gives you "+HIW+creds+NORM+" credits for it.\n"+
      "\nA pair of heavily cloaked monks carry the corpse away.\n\n");
say(this_player()->query_name()+" exchanges another corpse for credit.\n");
  ob->add_total(creds);
  ob->add_current(creds);
  ob->save_me();
  destruct(corp);
return 1; 
}

market_info() {
if(!present("xion")){
write("Xion is not here to give you information on the Bone Marketeers.\n"+
      "Check back when he is here.  Thanks...\n");
return 1; }
if(present("market_ob", this_player())) {
write("You are already a member of the Bone Market. Use "+HIW+"mkt_help"+NORM+" if you\n"+
      "have any questions about the group.\n");
return 1; }
write("Xion nods at and slowly begins to speak:\n");
cat("/players/daranath/closed/market/docs/overview.txt");
write("Xion turns and goes back to working on the corpses.\n");
return 1; 
}

market_join() {
  object mar_ob;
if(present("market_ob", this_player())) {
write("You are already a member of the Bone Marketeers, no need to join again.\n");
return 1; }
if(!present("xion")) {
write("Xion is not here right now, try again later to join the Bone Marketeers.\n");
return 1; }
if(this_player()->query_level() < 5) {
write("Sorry, but you must be at least level 5 to join the marketplace.\n");
return 1; }
if(this_player()->query_money() < 20000) {
write("Sorry, you don't have the necessary coins to join the Market right now.\n");
return 1; }
  mar_ob = clone_object(ROOT2+"badge.c");
write("Xion looks you over and says: \n     You want to Join the Marketeers?   Excellent!\n"+
      "He reaches into a deep pocket and pulls out a small, skull shaped\n"+
      "badge, hands it to you and wanders away, his job complete.\n");
say(this_player()->query_name()+" joins the Bone Marketeers.\n");
  this_player()->add_money(-20000);
  move_object(mar_ob, this_player());
return 1; 
}

