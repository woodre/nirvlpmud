	/* Jay's ballbat */

#include <ansi.h>
inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("bat");
set_alias("ballbat");
set_short("a "+HIK+"ballbat"+NORM);
set_long("Jay's mighty ballbat. He used this to bring down the  \n"+
         "mighty LeFluers at the mall.  \n");

set_type("club");   /*sword,knife,club,axe,bow,polearm */
set_class(16);
set_weight(2);
set_value(1000);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(30);
if(W>=27)  {
    say(this_player()->query_name()+HIC+ " bashes"+NORM+" foe with an overhead swing. \n");
    write("You"+HIC+" bash"+NORM+" your foe with a mighty overhead swing. \n");
    return 8;
          }

if(W>14 && W<18) {
    say(this_player()->query_name()+BLU+" CRACKS "+NORM+" opponent upside the head.\n");
    write("You "+BLU+ "CRACK" +NORM+ " your opponent upside the head.\n");
    return 6;
       }

if(W==1) {
    say(this_player()->query_name()+" tries to spin the bat and"+MAG+" cracks "+NORM+this_player()->query_possessive()+"self in the groin painfully.\n");
    write("You try to spin that bat deftly mess up the twirl and crack yourself in the groin.  \n");
    return -10;
       }

if(W<=4) {
    say(this_player()->query_name()+ "swings the"+HIK+" bat"+NORM+" hoping to nut the smegger to oblivion.  \n");
    write("You swing the"+HIK+" bat"+NORM+" hoping to nut the smegger to oblivion.  \n");
    return 4;
       }

return;
}
