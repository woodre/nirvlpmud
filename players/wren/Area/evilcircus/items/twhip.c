        /* Whip of Thorns*/

inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_id("whip");
set_name("thorns");
set_alias("thorn whip");
set_short("A viscious whip of thorns");
set_long("This spiney whip seems to be made from a living vine.\n"+
         "Sharp barps protrude at various angles all around it.\n"+
         "It seems to twitch on its own when held. Blood red   \n"+
         "veins run the length of whip becoming darkest at the \n"+
         "handle. This is definately a weapon for rending flesh\n"+
         "not a prop for a theatrical event. Handle it carefully. \n");

set_type("whip");   /*sword,knife,club,axe,bow,polearm */
set_class(18);
set_weight(2);
set_value(1400);
set_hit_func(this_object());
}

init()
{
::init();
add_action("enshrowd","darken");
}

weapon_hit(attacker) {
int W;
W = random(100);
if(W>90)  {
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }

if(W==49)  {
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }

if(W<10)  {
    say(" others hear. \n");
    write(" you hear. \n");
    return 3;
          }
}

int enshroud(string str) {
        /*reduce light by 2 around character for short term, won't work in -room */
    say(this_player()->query_name() + "   .\n");
    write("  .\n");
    environment(this_player())->add_light(-2);
    return 1;
     }
