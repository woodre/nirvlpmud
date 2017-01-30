	/* Cardinal Glick's driver */

#include <ansi.h>
inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("driver");
set_alias("club");
set_short("a "+HIK+"golf driver"+NORM);
set_long("Silent Bob lifted this driver from Cardinal Glick after \n"+
         "an audience with his holiness. It was blessed by the priest \n"+
         "for a better game.  \n");

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
    say(this_player()->query_name()+" trips and "+MAG+"cracks "+NORM+this_player()->query_possessive()+" shin.\n");
    write("You trip over a toy truck and crack yourself in the shin.  \n");
    return -10;
       }

if(W<=4) {
    say(this_player()->query_name()+ "swings the"+HIK+" club"+NORM+" bashing opponent in the chest.  \n");
    write("You swing the"+HIK+" club"+NORM+" fiercly cracking your opponent in the chest.  \n");
    return 4;
       }

return;
}
