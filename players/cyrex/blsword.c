inherit "obj/weapon";
object blsword;
reset(arg) {
::reset(arg);
set_name("blazing sword");
set_alias("sword");
set_short("Blazing Sword");
set_long("This sword seems to release a pulse of energy everytime it is swung.\n");
set_class(18);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}
weapon_hit(attacker){
if(random(60) < 20){
write("The sword pulses and releases a strong current of energy which fries "+attacker->query_name()+" to a crisp!\n");
return 2;
}
return 0;
}
