#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

reset(arg){
  if(arg) return;
   set_name("tippy");
   set_race("human");
   set_alias("seller");
      set_short("Tippy, the cigarette seller");
     set_long("Tippy is a tall and slim woman, wearing a miniskirt and a tie top\n"+
              "which completely hold her tiny breasts.  A red garter can be\n"+
              "seen now and then under her skirt.  She has deep violet eyes\n"+
              "and long brown hair.  She carries a box with several cigarette\n"+
              "packs in it,  held around her neck by two straps.  She is kind\n"+
              "enough to answer when is 'ask'ed.\n");

   set_level(10);
   set_hp(250);
   set_wc(10);
   set_ac(5);
   set_chat_chance(2);
   load_chat("Tippy says:  Welcome to the games.  Enjoy yourself.\n"); 
   load_chat("Tippy smiles:  All are easy to play, just start playing it and you will like them.\n"); 
   load_chat("Tippy mumbles:  Only 500 coins per play, it is a fair game.\n");
   load_chat("Tippy whispers:  C'mon "+tpn+", you will enjoy it.\n");
   load_chat("Tippy asks:  Do you want a smoke?\n");

}


init() {
::init();
add_action("ask","ask");
add_action("purchase","purchase");
}


ask(str) {
     if(str!="tippy") { notify_fail("Ask whom?\n"); return 0;}
  write("\nTippy searches through her pouch, takes a small notebook and softly says:\n"+
	"So far I can sell you a portable game named Morra.  You can 'purchase' it for\n"+
        "300 coins.  Or perhaps you want to buy some cigarettes?  320 coins per pack.\n");
return 1; }


purchase(str) {
int value, m;
object item;
     if(!str) { notify_fail("Purchase what?\n"); return 0;}
 m = 0;
  if(str == "morra" || str == "game") {
  item = clone_object("players/francesco/games/items/morrap.c");
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

