/* What glaendor's negative blade was originally like... 
Not intended for player use. */

inherit "obj/weapon";
reset(arg) {
::reset(arg);
set_name("negative blade");
set_alias("blade");
set_class(30);
set_save_flag(1);
 
set_value(1000000);
set_short("A negative blade");
set_long("This weapon was crafted in the void.\n" + 
         "Nothing can withstand it.\n");
set_hit_func(this_object());
}
weapon_hit(attacker) {
 
write("Your sword hums ominously.\n");
say(capitalize(this_player()->query_name())+"'s sword hums ominously.\n");
 
    if(call_other(attacker,"id","minion")){
        write("Your Negative Blade whines as it destructs "+
capitalize(attacker->query_name())+".\n");
                say(capitalize(this_player()->query_name())+
"'s Negative Blade whines as it destructs "+
capitalize(attacker->query_name())+".\n");
 
    }
 
if(attacker->query_hp() > 50) {
 
write("You shatter "+capitalize(attacker->query_name())+" to tiny pieces.\n");
say(capitalize(this_player()->query_name())+" shattered "+
capitalize(attacker->query_name())+" to tiny pieces.\n");
attacker->hit_player(5);
 
write("You pulverize "+capitalize(attacker->query_name())+
" to bits of cosmic dust.\n");
say(capitalize(this_player()->query_real_name())+" pulverizes "+
capitalize(attacker->query_name())+" to bits of cosmic dust.\n");
attacker->hit_player(8);
                                        }
write("Your sword pounds away, shattering your foe.\n");
say(capitalize(this_player()->query_name())+
"'s humming grey sword pounds away at "+attacker->query_name()+ ".\n");
 
return 1;
}
