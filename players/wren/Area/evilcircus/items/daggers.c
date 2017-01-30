	/* Blade acrobat daggers */

inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_id(" ");
set_name(" ");
set_alias(" ");
set_short(" ");
set_long("  \n");

set_type(" ");   /*sword,knife,club,axe,bow,polearm */
set_class( );
set_weight( );
set_value( );
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
