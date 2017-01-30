inherit "/obj/monster";
#include <ansi.h>
reset(arg) {
object gold;

if(arg) return ;  ::reset(arg);

set_name("Shadow Creature");
set_short(HIK+"a Shadow Creature"+NORM);
set_alias("shadow");
set_long("This is a shadow of the underworld. It is said when this\n"+
         "touches you is to meet certain death.\n");
set_level(12);
set_wc(16);
set_ac(8);
set_hp(180);

gold=clone_object("obj/money");
gold->set_money(500+random(50));
move_object(gold,this_object());
}
