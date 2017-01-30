inherit "/obj/monster";
#include "/players/jenny/define.h"
int br;
int ck;
int co;
reset(arg)
{
br = 8+random(4);
ck = 94+random(14);
co = 94+random(14);
   ::reset(arg);
    if (arg) return;
    set_name("daisy duke");
    set_alt_name("daisy");
    set_race("human");
    set_alias("duke");
set_gender("female");
    set_al(200+random(75));
    set_level(14);
    set_hp(198+random(20));
    set_wc(16+random(4));
    set_ac(9+random(4));
    set_short(BOLD+""+CYN+"Daisy Duke"+NORM);
    set_long(
      "Daisy Duke is a beautiful young lady with long brown hair,\n"+
      "a friendly smile, and the best legs in Georgia.  She is wearing\n"+
     "a tight fitting white shirt and very low cut shorts that show off\n"+
      "every inch of those gorgeous legs.  She is also the best female\n"+
      "driver in Hazzard county.  Daisy is the waitress here at the\n"+
      "Boar's Nest, just "+MAG+"ask"+NORM+" her for a menu.  She is the cousin of\n"+
      "Bo and Luke Duke.\n");
  gold=clone_object("obj/money");
  gold->set_money(700+random(300));
  move_object(gold,this_object());
}
init() {
  ::init();
add_action("heal","order");
add_action("menu","ask");
}
heal(arg) {
if(!arg) { write(CYN+"Daisy says:  "+NORM+"What do ya want sugar?\n"); return 1; }
if(arg != "beer" && arg != "chicken" && arg != "coke") {
write(CYN+"Daisy says:  "+NORM+"Sorry sugar, we don't serve that.\n"); return 1; }
if(arg == "beer") {
if(!TP->drink_alcohol(3)) { write(CYN+"Daisy says:  "+NORM+"Sorry sugar, you're too drunk to serve.\n");
return 1;}
write(CYN+"Daisy brings you a glass of wattered down beer and says:  "+NORM+"Here ya\n"+
"go sugar.\n");
TP->heal_self(1);
TP->add_money(-br);
return 1; }
if(arg == "chicken") {
if(!TP->eat_food(4)) { write(CYN+"Daisy says:  "+NORM+"Well honey, I just don't think you can eat any more.\n");
return 1; }
write(CYN+"Daisy brings you a plate of Hazzard County's finest fried chicken."+NORM+"\n");
TP->heal_self(11);
TP->add_money(-ck);

return 1;}
if(arg == "coke") {
if(!TP->drink_soft(4)) { write(CYN+"Daisy says:  "+NORM+"Well honey, I just don't think you can drink any more.\n");
return 1; }
write(CYN+"Daisy brings you a coke and says:  "+NORM+"Here ya go sugar.\n");
TP->heal_self(11);
TP->add_money(-co);
return 1; }}
menu() {
write(RED+
"            *********************************************\n"+
"            *                                           *\n"+
"            *               "+WHT+"You can order:"+RED+"              *\n"+
"            *                                           *\n"+
"            *    "+WHT+"Beer                    "+br+"	coins"+RED+"	*\n"+
"            *                                           *\n"+
"            *    "+WHT+"Fried Chicken           "+ck+"	coins"+RED+"	*\n"+
"            *                                           *\n"+
"            *    "+WHT+"Coke                    "+co+"	coins"+RED+"	*\n"+
"            *                                           *\n"+
"            *********************************************"+NORM+"\n");
return 1; }
