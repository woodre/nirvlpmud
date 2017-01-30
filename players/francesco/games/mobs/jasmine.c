#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

reset(arg){
  if(arg) return;
   set_name("jasmine");
   set_race("human");
   set_alias("seller");
      set_short("Jasmine, the cigarette seller");
     set_long("Jasmine is a tall and strong woman, wearing a miniskirt and a tie\n"+
              "top which completely holds her ample breasts.  A red garter can be\n"+
              "seen now and then under her skirt.  She has brown blue eyes and brown\n"+
              "hair as well.  Her movements look snobbish, her body looks very well\n"+
              "built up, with ample shoulders and strongs arms,  her voice is deep. \n"+
              "She carries a box with several cigarette packs in it,  held around \n"+
              "her neck by two straps.  She is kind enough to answer when is 'ask'ed.\n");

   set_level(10);
   set_hp(250);
   set_wc(10);
   set_ac(5);
   set_chat_chance(2);
   load_chat("Jasmine says:  Welcome to the games.  Enjoy yourself.\n"); 
   load_chat("Jasmine smiles:  All are easy to play, just start playing it and you will like them.\n"); 
   load_chat("Jasmine mumbles:  Only 500 coins per play, it is a fair game.\n");
   load_chat("Jasmine whispers:  C'mon guys, you will enjoy it.\n");
   load_chat("Jasmine asks:  Do you want a smoke?\n");

}


init() {
::init();
add_action("ask","ask");
add_action("purchase","purchase");
}


ask(str) {
     if(str!="jasmine") { notify_fail("Ask whom?\n"); return 0;}
  write("\nJasmine searches through her pouch, takes a small notebook and softly says:\n"+
	"I wish to sell you this game named Mastermind, but due to superior orders I cant.\n"+
        "Perhaps you want to console yourself with some cigarettes?  320 coins per pack.\n");
return 1; }


purchase(str) {
int value, m;
object item;
     if(!str) { notify_fail("Purchase what?\n"); return 0;}
 m = 0;
/***
  if(str == "mastermind" || str == "game") {
  item = clone_object("players/francesco/games/items/mastermind4.c");
  value = 300;
  m = 1; }
****/
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

