inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(19);
                set_value(500);
                set_weight(3);
                set_alias("sword");
set_short("Trixter sword");
set_long( "This sword was found in a corn field by the son of the farmer Joe Chickgrower,\n"+ "the boy soon learnt to slice his father's hens up , so the angry genitor took \n"+ "this sword and put it on the first train directed to west , and finally it got\n"+ "here in Nirvana , don't ask me how , u have it and that's enough !!!\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 30) return 2;
}
