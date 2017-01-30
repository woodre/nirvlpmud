 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Blackberry Curve 8330");
    set_alias("phone");
    set_short("A Sprint Blackberry Iphone4");
    set_long("A cell phone made by Research In Motion for Sprint.\n");
    set_class(20);
    set_weight(3);
    set_value(7500);
    {
    weapon_hit(attacker);
    int W;
W = random(100);
if(W > 50 && W < 90
  {  {
 say("The Blackberry zaps its foe with a powerful volt of electricity.\n");
 write("Your Blackberry zapped your target with a bolt of electricty.\n");
if(W > 98){ say(environment()->query_name()+"'s Blackberry is
destroyed!\n"); write("Your Blackberry is damaged and breaks.\n");
this_object()->weapon_break(); return 1; }

    }
    return;
}

