inherit "/obj/monster";
#include "/players/jenny/define.h"
int num;
string color;
id(str) { return str == "a girl with big hair" ||  str == "girl" || str == "chick"; } 
reset(arg) {
num = random(3);
if(num == 0) {color = HIR+"red "+NORM;}
if(num == 1) {color = HIW+"white "+NORM;}
if(num == 2) {color = HIY+"yellow "+NORM;}
   ::reset(arg);
    if (arg) return;
    set_name("girl with big hair");
    set_race("human");
set_gender("female");
    set_al(25+random(10));
    set_level(3); 
    set_hp(40+random(10));
    set_wc(6+random(2));
    set_ac(3+random(3));
    set_short("A girl with big hair");
    set_long(
"This is a 14 year old blonde girl with big hair.  It looks like, \n\
a ton of hair spray was used.  She is wearing a "+color+"shirt, \n\
and a pair of Jordache jeans.\n");
     set_info("This girl has hair that has been spritzed, moussed, sprayed,\n\
gelled and otherwise shaped to tower high overhead.\n");
  gold=clone_object("obj/money");
  gold->set_money(80+random(40));
  move_object(gold,this_object());
}
