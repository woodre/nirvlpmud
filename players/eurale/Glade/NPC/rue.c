#include "/players/eurale/Glade/defs.h"
inherit "obj/monster";
object item;
int value,m;
int MAL,VIR,TUMS;

reset(arg) {
object buyer;
MAL = 6;
VIR = 6;
TUMS = 6;

::reset(arg);
if(arg) return;
set_name("madame rue");
set_alias("madame");
set_alt_name("rue");
set_race("human");
set_short(BOLD+"Madame Rue"+NORM);
set_long(
  "  This is a frail looking lady.  The years seem to have taken\n"+
  "their toll on her.  Her hair is dirty and streaked with gray.  Her\n"+
  "leathery skin is wrinkled and hangs off her bones without enough\n"+
  "meat to make it matter.  She has a multitude of freckles from many\n"+
  "years wandering the glade in search of her needs.  Her lips are\n"+
  "thin and cracked, her mouth toothless and her pointed nose seems\n"+
  "much too large for her face.  The one thing about her that strikes\n"+
  "you as odd and out of place is her eyes.  They are jet black,\n"+
  "bright and very alert.....missing nothing.\n");

set_level(16);
set_hp(400);
set_al(-700);

if(!present("sandals")) {
  move_object(clone_object("players/eurale/Glade/OBJ/sandals.c"),
    this_object()); }
if(!present("shawl")) {
  move_object(clone_object("players/eurale/Glade/OBJ/shawl.c"),
    this_object()); }
init_command("wear sandals");
init_command("wear shawl");

set_wc(33);
set_ac(17);
set_heal(15,2);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Madame Rue whispers, 'If you'd like to see my wares, just\n"+
	    "ask me...' and she snickers.\n");
  load_chat("'I make wonderful potions', says Madame Rue\n");
  load_chat("The witch rubs her hands together and says, 'Did you bring\n"+
	    "me anything interesting?'\n");
  load_chat("The old witch cackles solftly to herself.....\n");
  load_chat("The witch whispers, 'Beware the dark elf that lives in\n"+
	    "the glade.  She is powerful and your magic will narry help\n"+
	    "you in a fight with her.'\n\n");
  load_chat("'I think my interferon might just cure VD,' says Rue\n");
  load_chat("Rue whispers, 'I love to barter for items.'\n");

set_chance(23);
set_spell_dam(65);
set_spell_mess1(
  "\nMadame Rue's eyes open wide.....\n"+
  "     She mumbles something and SPITS.....\n"+
  "          There's a cloud of white smoke.....\n"+
  "               You see her target DOUBLE OVER in pain!\n");

set_spell_mess2(
  "\nMadame Rue's eyes open wide.....\n"+
  "     She mumbels something and SPITS at your feet.....\n"+
  "          There's a cloud of blueish-white smoke.....\n"+
  "               INTENSE PAIN grips your chest!\n");

}

init() {
  add_action("ask","ask");
  add_action("buy","buy");
  add_action("barter","barter");
  add_action("Search","search");
}

ask(str) {
if(str == "madame" || str == "madame rue" || str == "rue") {
  write("This weathered, toothless old hag smiles and whispers to you..\n\n"+
	"'The glade provides me with the items I need to mix my potions\n"+
	"and elixirs.  If there is something you'd like, just 'buy'\n"+
	"whatever it is that suits your fancy and then be on your way.\n"+
	"Take a look at what I have.......\n\n"+
	"     elixir of [virtue]         ~400 coins\n"+
	"     elixir of [malice]         ~400 coins\n"+
        "     bicarbonate of soda       ~1800 coins\n"+
	"     dmso antitoxin            ~2500 coins\n"+
	"     interferon               ~80000 coins\n"+
	"\nOh yes, one other thing.........\n"+
	"There are other items scattered throughout Nirvana that I\n"+
	"might be interested in.  Just bring them here and we can\n"+
	"'barter' over the value.....'\n"+
	"And with that, she turns and goes back to her work....\n\n");
  return 1; }
}

buy(str) {
m = 0;

if(str == "virtue") {
if(VIR == 0) {
  write("I'm sorry, all out of those at the moment.. check later.\n");
  return 1; }
else {
  item = clone_object("players/eurale/Glade/OBJ/virtue.c");
  value = 414;
  VIR = VIR - 1;
  m = 1; }
}

if(str == "malice") {
if(MAL == 0) {
  write("Rue says, 'Just sold my last one, maybe more later.'\n");
  return 1; }
else {
  item = clone_object("players/eurale/Glade/OBJ/malice.c");
  value = 411;
  MAL = MAL - 1;
  m = 1; }
}

if(str == "bicarbonate") {
if(TUMS == 0) {
  write("Rue frowns and whispers, 'Someone just bought the last bicarbonate\n"+
	"of soda I had, I'll have more later if you come back.'\n");
  return 1; }
else {
  item = clone_object("players/eurale/Glade/OBJ/bicarbonate.c");
  value = 1800 + random(10);
  TUMS = TUMS - 1;
  m = 1; }
}

if(str == "dmso" || str == "antitoxin") {
  item = clone_object("players/eurale/Glade/OBJ/dmso.c");
  value = 2497;
  m = 1; }

if(str == "interferon") {
  item = clone_object("players/eurale/Glade/OBJ/interferon.c");
  value = 78000;
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
object ob;
if(!str) {
  write("'What is it you want to barter over?', asks Rue\n");
  return 1; }

ob = present(str,TP);
if(!ob) {
  write("'You better check your inventory', snickers Rue.\n");
  return 1; }
}

Search() {
  write("Madame Rue slaps your hand and glares at you..\n");
  TP->heal_self(-random(15));
  return 1; }
