inherit "obj/weapon";
int w;
reset(arg) {
::reset(arg);
        if(!arg) {
set_name("bow");
set_alias("bow");
set_short("A Power Bow");
set_long("Kimberly, the Pink Ranger's Power Bow.\n");
set_class(12);
set_value(750);
set_weight(4);
set_hit_func(this_object());
}
}
wield(arg) {
if(::wield(arg));
if(id(arg)) {
write("You feel a surge of...POWER!\n");
}
return 1;
}
weapon_hit(attacker)
{
w=random(20);
if (w>10) {
say("The Power Bow pierces the enemy.\n");
write("Your Power Bow pierces your opponent with an arrow.\n");
return 10;
}
}
query_save_flag() { return 1; }
