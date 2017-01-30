	/* MR.FLIBBLE muhahaha */

#include <ansi.h>
inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("flibble");
set_alias("penguin");
set_short("a "+HIK+"pe"+WHT+"ngu"+HIK+"in"+NORM+" handpuppet");
set_long("Ah Mr.Flibble, demented sidekick to the holovirused Rimmer. He is \n"+
         "not a puppet to be triffled with. He is known to possess psionic \n"+
         "abilities and a tendancy to hurt people. You think you may like him. \n"+
         "Provided you find someone to clean up the mess.\n");

set_type("puppet");   /*sword,knife,club,axe,bow,polearm */
set_class(17);
set_weight(2);
set_value(2000);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(45);
if(W>20 && W<=25)  {
    say(this_player()->query_name()+" listens to Mr.Flibble. Then gasps. 'But who'll clean up the mess?'\n");
    say(this_player()->query_name()+" and Mr.Flibble's eyes "+RED+"glow"+NORM+"...\n");
    write("You listen to Mr.Flibble. His suggestion is for a very messy end for you foe. \n");
    return 7;
          }

if(W>=14 && W<=20 ) {
    say("Mr.Flibble "+YEL+"telekinetically"+NORM+" lodges a medium sized fire "+HIK+"axe"+NORM+" in his opponent's back.\n");
    write("Mr.Flibble "+YEL+"telekinetically"+NORM+" lodges a medium sized fire "+HIK+"axe"+NORM+" in his opponent's back.\n");
    return 6;
       }

if(W<=10 && W>=7) {
    say("Mr.Flibble blasts opponents with his "+BLINK+BRED+"HEX"+NORM+" vision.\n");
    write("Mr.Flibble blasts opponents with his "+BLINK+BRED+"HEX"+NORM+" vision.\n");
    return 5;
       }

if(W<=4) {
    say("Mr.Flibble is very cross. His eyes glow...\n");
    say(".     "+RED+" -=0=-    -=0=-" +NORM+ "       . \n");
    write("Mr.Flibble is very cross. His eyes glow "+RED+"RED"+NORM+".\n");
    return 8;
       }

return;
}
