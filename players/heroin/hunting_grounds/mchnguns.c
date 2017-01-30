inherit "obj/weapon";

int i;
reset (arg){
::reset(arg);
if(!arg){
set_name("Flame thrower");
set_alias("thrower");
set_short("A Flame Thrower");
set_long("This appears to be more of a salvage tool than a weapon,\n"+
"however, it should so just fine.  Once it is lit, it hard to \n"+
"extinquish it's flame- as well as the recipient of the flame!\n");
set_class(17);
set_weight(3);
set_value(5000);

}
set_hit_func(this_object());
}
weapon_hit(attacker){
i=random(20);
if (i>5){
say(this_player()->query_name()+"  lights you up like a b-day candle.\n");
write("Burn Baby Burn..Disco Inferno!!!!\n");
return 1;
}
return 0;
}
