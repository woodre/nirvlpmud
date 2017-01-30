inherit "obj/monster.talk";

object gold;
reset(arg) {
  ::reset(arg);
if(!arg) {
set_name("Jack the Ripper");
set_race("human");
set_gender("male");
SetMultipleIds(({"jack","ripper","jack ripper","jack the ripper","sparky"}));
set_short("Jack the Ripper");
set_long("Announcer says: In this corner, weighing in at 185\n"+
"is a favorite in these parts.  He is famous for such moves\n"+
"as the under-the-arm, back slash, and the smiling throat cut.\n"+
"He is a favorite among the young ladies of london-with such\n"+
"nicknames as the Ripper and Stalker..but to his friends he is known as\n"+
"Sparky.  Tonight Sparky will be using his customary trademark the \n"+
"razor and sporting the dull grey trench coat.\n"+
"Announcer continues: And Sparky's challenger weighing in at\n"+
"an unknown weight, hails himself as the Illinois Inchworm.\n"+
"Not much is known about the inchworm except that his fav. color\n"+
"is mauve.  Fighters shake hands-and come out fighting!\n"+
"RAHHHH  RAHHHHHH RAHHHHH BOOO BOOOO YEAHH YEAH CHEER CHEER\n");
set_level(17);
set_hp(425);
set_al(-10);
set_wc(20);
set_ac(14);
add_spell("Slice",
  "With a quick flick of the wrist, Jack opens you up!\n",
  "With a quick flick of the wrist, Jack opens #CTN# up!\n",
  20, "10-20", "physical"); 
set_aggressive(0);
set_a_chat_chance(10);
  set_chat_chance(20);
load_chat("I am a Ladies' man..A killer lay\n");
load_chat("My friends call me Sparky-you can call me Sir Ripper\n");
load_a_chat("After i kill you-How many will that be,Hummm\n");
load_a_chat("I really did love all of them you know--its strange, i dont care about you\n");
gold = clone_object("obj/money");
gold -> set_money(random(1000)+1000);
  move_object(gold,this_object());
move_object(clone_object("/players/heroin/hunting_grounds/razor.c"), this_object());
move_object(clone_object("/players/heroin/hunting_grounds/trenchct.c"), this_object());
command("wield razor");
command("wear coat");
}
}
