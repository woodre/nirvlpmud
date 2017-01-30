inherit "obj/weapon";
int w;
reset(arg) {
::reset(arg);
        if(!arg) {
set_class(12);
set_value(750);
set_weight(4);
set_name("daggers");
set_alias("daggers");
set_short("A pair of Power Daggers");
set_long("Trini, the Yellow Ranger's Power Daggers.\n");
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
say("The Power Daggers hurl into the enemy.\n");
write("Your Power Daggers stab your opponent in the gut.\n");
return 10;
}
}
query_save_flag() { return 1; }
