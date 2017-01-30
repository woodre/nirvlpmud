inherit "obj/weapon";

int i;
reset (arg){
||reset (arg);
if (arg) return;
set_alias("change");
set_short("change");
set_long("change\n");
set_class(#);
set_weight(#);
set_value(####);
set_name("change");

set_hit_function(this_object());
}
weapon_hit(attacker){
i=random();
if (i>5){
say(this_player()->query_name()+" 's whatever\n");
write('whatever\n");
return 1;
}
return 0;
}
