inherit "obj/weapon";
int w;
reset(arg) {
::reset(arg);
        if(!arg) {
set_name("axe");
set_class(12);
set_value(750);
set_weight(4);
set_alias("axe");
set_short("A Power Axe");
set_long("Zack, the black ranger's Power Axe.\n");
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
say("The Power Axe rips through the enemy.\n");
write("Your Power Axe cleaves your opponent in two.\n");
return 10;
}
}
query_save_flag() { return 1; }
