#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

id(str){ return str == "chloe" || str == "Chloe" || str == "chloe 2" || str == "seller" ;}

reset(arg){
  ::reset(arg);
  if(arg) return;
   set_name("chloe");
   set_race("human");
   set_alias("seller");
      set_short("Chloe, the cigarette seller");
     set_long("Chloe is a minute woman, wearing a miniskirt and a tight top\n"+
              "which barely hides her ample breasts.  A red garter can be\n"+
              "seen now and then under her skirt.  She has piercing green eyes\n"+
              "and long black hair.  She carries a box with several cigarette\n"+
              "packs in it,  held around her neck by two straps.  She is kind\n"+
              "enough to answer when is 'ask'ed.\n");

   set_level(10);
   set_hp(250);
   set_wc(10);
   set_ac(5);
   set_chat_chance(5);
   load_chat("Chloe says:  Welcome to the rock paper scissors game.  Enjoy yourself.\n"); 
   load_chat("Chloe smiles:  It is a simple game, just start playing it and you will like it.\n"); 
   load_chat("Chloe mumbles:  Only 500 coins for play, it is a fair game.\n");
   load_chat("Chloe whispers:  C'mon guys, you will enjoy it.\n");
   load_chat("Chloe asks:  Do you want a smoke?\n");

}


init() {
::init();
add_action("ask","ask");
add_action("purchase","purchase");
}


ask(str) {
     if(str!="chloe") { notify_fail("Ask whom?\n"); return 0;}
  write("\nChloe searches through her pouch, takes a small notebook and softly says:\n"+
	"So far I can sell you a portable game named Sasso.  You can 'purchase' it for\n"+
        "300 coins.  Or perhaps you want to buy some cigarettes?  320 coins per pack.\n"+
        "And if you feel alone I could play a game with you.\n");
return 1; }


purchase(str) {
int value, m;
object item;
     if(!str) { notify_fail("Purchase what?\n"); return 0;}
 m = 0;
 if(str == "sasso" || str == "game") {
  item = clone_object("players/francesco/games/items/sassop.c");
  value = 300;
  m = 1; }
 if(str == "cigarettes" || str == "pack") {
  item = clone_object("players/francesco/games/items/cigarettes.c");
  value = 320;
  m = 1; }

if(m) {
if(this_player()->query_money() <value) {
  write("You do not have enough to purchase this item! \n");
return 1; }

if(!call_other(tp,"add_weight",call_other(item,"query_weight"))) {
write("You better lighten your inventory before buying anything else.\n");
return 1; }

this_player()->add_money(-value);

move_object(item,this_player());
say(capitalize(this_player()->query_real_name())+" purchases a "+str+".\n"); }
else {
  write("That item cannot be purchased here. \n"); }
return 1;
}