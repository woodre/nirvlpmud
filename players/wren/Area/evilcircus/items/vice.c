	/* Spear of Vice */

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

add_action("feed","draw");

}

feed() {
    
    /*streams of fire special, should look pretty but do very little*/
    /*perhaps attempt to add in a special damage of type fire */

    say("  .\n");
    write("  .\n");
    return;
    }



weapon_hit(attacker) {
int W;
W = random(120);
if(W<9)  {
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }

if(W>110)  {
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }

if(W>19 && W <22)  {
    /*increase evil in wielder*/
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }

if(W==88)  {
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }

return;
}
