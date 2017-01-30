inherit "obj/monster.c";
object coins, item;
reset(arg) {
if(arg) return;
::reset();
set_name("wally");
set_short("Wally T. Salesman");
set_long("This is one of THE most annoying salesman you will ever find.\n");
set_al(50);
set_level(14);
set_wc(18);
set_hp(210);
set_ac(11);
set_aggressive(0);
set_chat_chance(70);
load_chat("The salesman says: You simply HAVE to see the areas around here!\n");
load_chat("The salesman says: How about putting in a good word for my boss..."+
"\n(I could use a raise.)\n");
load_chat("The salesman says: ATTENTION NEWBIES! Go south! Go south!\n");
load_chat("The salesman says: Over worked? Under paid? Under level 6?\n"+
"The salesman says: Then head south! Build up that revenue that your 19th\n"+
"level counter parts are too frugal to help you attain!\n");

coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
}
