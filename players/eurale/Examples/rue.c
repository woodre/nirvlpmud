/*
  This is an NPC whose function is to barter for items that have
  been gotten off of big NPCs where it would not make sense for
  the NPC to have coins on them.  Shops should still be  used to
  sell normal items and anything with values of 1000 coins or
  less.  This NPC is called madame rue and she is a seller of
  items as well as a buyer of special things.
*/

#define TP this_player()
inherit "obj/monster";
object buyer,item;
int value,m;

reset(arg) {
  ::reset(arg);
  if(arg) return;

set_name("madame rue");
set_alias("rue");
set_race("human");
set_short("Madame Rue");
set_long(
  "  This is a frail looking lady.  The years seem to have taken\n"+
  "their toll on her.  Her hair is dirty and streaked with gray.  Her\n"+
  "leathery skin is wrinkled and hangs off her bones without enough\n"+
  "meat to make it matter.  She has a multitude of freckles from many\n"+
  "years wandering the glade in search of her needs.  Her lips are\n"+
  "thin and cracked, her mouth toothless and her pointed nose seems\n"+
  "much too large for her face.  The one thing about her that strikes\n"+
  "you as odd and out of place is her eyes.  They are jet black,\n"+
  "bright and very al sellerert... missing nothing.  She is the local\n"+
  "and has been know to 'barter' for odd or interesting items.\n");

set_level(16);
set_hp(400);
set_al(0);
set_wc(22);
set_ac(13);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Rue whispers, 'I love to barter for items.'\n");
  load_chat("'Want to see my wares?  Just 'ask', says Rue.\n");

}

init() {
add_action("ask","ask");
add_action("buy","buy");
add_action("barter","barter");
}

ask(str) {
if(!str || str == "rue" || str == "madame rue") {
  write(
   "This weathered, toothless old had smiles and whispers to you..\n\n"+
	"'The glade provides me with the items I need to mix my potions\n"+
	"and elixirs.  If there is something you'd like, just 'buy'\n"+
	"whatever it is that suits your fancy and then be on your way.\n"+
	"Take a look at what I have.......\n\n"+
        "     item number one             400 coins\n"+
	"\nOh yes, one other thing.........\n"+
	"There are other items scattered throughout Nirvana that I\n"+
	"might be interested in.  Just bring them here and we can\n"+
	"'barter' over the value.....'\n"+
	"And with that, she turns and goes back to her work....\n\n");
  return 1; }
}

buy(str) {
m = 0;

if(str == "number one") {
  item = clone_object("players/wiz/area/OBJ/item.c");
  value = 400;
  m = 1; }

if(m) {
if(this_player()->query_money() <value) {
  write("'You better check your coins', whispers Rue\n");
return 1; }

if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
write("The witch cackles, 'You'll have to lighten up first!'\n");
return 1; }

this_player()->add_money(-value);  /* take coins from player  */
this_object()->add_money(value/10);  /*  add coins to this object  */
  if(money > 1001) money = 900 + random(100);

move_object(item,this_player());

say(capitalize(this_player()->query_real_name())+" purchases a "+str+" \n"); }
else {
  write("'I don't have that item, sorry....', says the witch\n");
  }
return 1;
}

barter(str) {
int num;
object ob;
string str1,str2,str3;

if(!str) {
  write("'What is it you want to barter over?', asks Rue\n");
  return 1; }

/*
  This is the bartering process.  For security reasons, only the
  specific items whose path names match can be bartered.  This
  makes sure that an item accidently given the name of a barter-
  ble one cannot be bartered.  Also, try to give each item a
  different message when it's bartered.. adds to the game.
*/

if(str == "name") {
  ob = present("unique id",TP);
  str1 = file_name(ob);
  sscanf(str1,"%s#%s",str2,str3);
  if(str2 != "players/wiz/area/obj/item") {
    write("Rue cackles, 'You don't even have one.'\n");
    return 1; }
  num = 3800 + random(200);
  say("Rue buys a "+str+" from "+TP->query_real_name()+".\n");
  write("Rue cackles and takes the unique item.  She looks it over..\n"+
        "She smiles a toothless grin and after some friendly bartering\n"+
        "she hands you "+num+" coins for it....\n");
  TP->add_money(num);
  destruct(ob);
  return 1; }


}
