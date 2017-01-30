inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("lightsaber");
                set_class(15);
                set_value(10000);
                set_weight(1);
     set_hit_func(this_object());
                set_alias("lightsaber");
                set_short("Ancient Lightsaber");
set_long("This is the Jedi's greatest hand to hand weapons\n"+
         "in fighting the foes of the great Republic.\n");
}
}
weapon_hit(attacker){
write("The lightsaber elegantly blocks your opponents blow.\n");
find_living(attacker->stop_fight());
return 1;
}
