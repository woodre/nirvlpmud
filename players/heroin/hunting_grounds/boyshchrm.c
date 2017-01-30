inherit "obj/weapon";

int i;
reset (arg){
::reset(arg);
if(!arg){
set_name("Boyish charm");
set_alias("charm");
set_short("Boyish charm");
set_long("The charm of a young chap should never be underestimated\n"+
"especially when wielded as a weapon.  This particular charm used\n"+
"to belong to Robin, the boywonder..and Gee, Now it's yours.\n");
set_class(13);
set_weight(1);
set_value(1000);

}
set_hit_func(this_object());
}
weapon_hit(attacker){
i=random(20);
if (i>5){
say(this_player()->query_name()+" 's charm wins you over and it hurts!\n");
write("You pour on the charm, till they choke on it.\n");
return 1;
}
return 0;
}
