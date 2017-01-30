	/* Blade of Virtue */

inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_id("blade");
set_name("blade of virtue");
set_alias("virtue");
set_short("Aboth's Blade");

set_long("This Blade of Virtue was carried by Aboth the Avenger. Since it is \n"+
"not with him now he must be dead or seeking it. It is the sword of \n"+
"a Demon hunter, carried into places of evil to spare others from   \n"+
"the horrors. Silver filigree runs from near the tip up the razor   \n"+
"edge blending almost seamlessly with the swirling hand-guard. \n");

set_type("sword");   /*sword,knife,club,axe,bow,polearm */
set_class(18);
set_weight(3);
set_value(1600);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(13);
if(W>9)  {
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }
return;
}
