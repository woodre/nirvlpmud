inherit "obj/weapon";
reset(arg){
if(arg) return;
::reset(arg);
set_name("spear");
set_alt_name("spear");
set_alias("weapon");
set_short("A big spear");
set_long("A very big spear.  Probally was take off of a giant or somethig of that\n"+
         "effect.\n");
set_class(15);
set_weight(4);
set_value(2200);
set_hit_func(this_object());
}
weapon_hit(attacker){
        if (random (100) < 30) {
        write("You drop the spear on your opponent's head.\n");
        say(capitalize(this_player()->query_real_name()) + " drops his spear on his opponent's head.\n");
        return(random(6));
}
}
