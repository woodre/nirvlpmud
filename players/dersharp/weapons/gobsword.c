inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(12);
                set_value(100);
                set_weight(3);
                set_alias("sword");
set_short("A goblin's sword");
set_long("This sword is slightly bashed from the misuse it found in the hands\n"+
         "of its former owner.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 10) return 2;
}
