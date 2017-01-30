inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(12);
                set_value(250);
                set_weight(5);
                set_alias("sword");
                set_hit_func(this_object());
set_short("The sword of Baltek");
set_long("Forged by the smiths of Urn, this sword sometimes will sometimes\n"+
         "attack with potent magic!\n");
}
}
weapon_hit(attacker)
{
if(random(100) < 5) {
   write ("The sword fires bolts of blue energy at your opponent!\n");
   say("The sword suddenly erupts into a fountain of blue light!\n");
   return 3;
}
return 0;
}
