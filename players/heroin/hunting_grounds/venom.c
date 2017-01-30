inherit "obj/weapon";

int i;
reset (arg){
::reset(arg);
if(!arg){
set_name("venom");
set_alias("venom");
set_short("Alien Venom");
set_long("Make sure this shit doesn't touch your skin--it's like\n"+
"acid.  The alien's blood will eat through almost anything, but it\n"+
"works especially well on skin.  The blood of the alien is hard to\n"+
"use effectively, but if one can wield it- they are almost unstoppable.\n");
set_class(17);
set_weight(1);
set_value(5000);

}
set_hit_func(this_object());
}
weapon_hit(attacker){
i=random(50);
if (i>5){
say(this_player()->query_name()+" You feel the skin being eaten from your bones.\n");
write("You are successful in spreading the blood..the screams...\n");
return 1;
}
return 0;
}
