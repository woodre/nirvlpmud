inherit "obj/weapon.c";
#include "/sys/lib.h"
#include <ansi.h>
 
reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("raygun");
    set_alias("raygun");
    set_short("A "+HIY+"Massive "+HIR+"Ray Gun"+NORM+"");
    set_long("A Massive Ray Gun that was built by Stewie Griffin.\n"+
           "It was made for a plot of world domination.\n");
    set_class(15);
    set_weight(2);
    set_value(700);
    set_hit_func(this_object());
}

/* This is called by the weapon for *special* attacks.  */
weapon_hit(attacker){

/* This makes W an intiger */
int W;
/* This sets W equal to a number between 0 to 11 */
W = random(12);

/* If the random number W is greater than 9, than the following happens. */
if(W > 9)  {

/* A say is seen by everybody in the room BUT the user. */
  say("The "+HIR+"Ray Gun"+HIY+" Rattles "+NORM+"of a "+HIY+"Blast"+NORM+".\n"+
  "You smell something "+BOLD+"smoking"+NORM+".\n");

/* A write is seen ONLY by the user. */
  write("The "+HIR+"Ray Gun"+HIY+" Rattles "+NORM+"of a "+HIY+"Blast"+NORM+".\n"+
  "You smell something "+BOLD+"smoking"+NORM+".\n");

 /* This return is the additional damage called.  */
return 5;

    }
    return;
}