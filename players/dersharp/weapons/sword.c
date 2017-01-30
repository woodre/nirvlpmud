inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(14);
                set_value(500);
                set_weight(3);
                set_alias("sword");
set_short("Carpathian Sword");
set_long(
"This sword was taken from the unfortunate soul who dared try to destroy\n"+
"Count Magnus Lea. Even though the sword is special against vampires,\n"+
"it did the hardy adventurer no good.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 30) return 2;
}
