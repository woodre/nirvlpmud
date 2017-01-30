inherit "obj/weapon";

int i;
reset (arg){
::reset(arg);
if(!arg){
set_name("joke");
set_alias("joke");
set_short("The Killing Joke");
set_long("This is the funniest jokes ever told all in one place\n"+
"and in one time.  Just even the thought of it makes you want to\n"+
"snicker and you haven't even heard the jokes-can you imagine\n"+
"the devistation if these jokes were told???\n");
set_class(18);
set_weight(2);
set_value(5000);

}
set_hit_func(this_object());
}
weapon_hit(attacker){
i=random(20);
if (i<5){
say(this_player()->query_name()+" 's joke starts off slow but packs a whollop!!\n");
write("You crack up even telling the joke!\n");
return 1;
}
return 0;
}
