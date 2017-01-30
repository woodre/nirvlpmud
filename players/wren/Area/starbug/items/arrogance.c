	/* weapon template */

inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("arrogance");
set_alias("knife");
set_short("Rimmers arrogance.");
set_long("You've managed to download Rimmer's arrogance. He seems to \n"+
         "have been just bristling with the stuff. It may be turned \n"+
         "to your advantage.  \n");

set_type("knife");   /*sword,knife,club,axe,bow,polearm */
set_class(15);
set_weight(2);
set_value(500);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(25);
if(W>=15)  {
    say("Rimmer's nostrils flare angrily. \n");
    write("Your nostrils flare much like Rimmer's. \n");
    return 3;
          }
if(W<5) {
    say(this_player()->query_name()+" tries to quote a spacecorp directive, its obviously the wrong one. \n");
    write("That should be spacecorp directive 20370-z23 me'lad'o. \n");
    return 8;
        }

return;
}
