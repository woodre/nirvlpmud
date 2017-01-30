inherit "obj/weapon";

int i;
reset (arg){
::reset(arg);
if(!arg){
set_name("keys");
set_alias("keys");
set_short("keys");
set_long("These keys are attached to a long chain, which when used\n"+
"properly, inflict major damage.  The keys are swung and after\n"+
"reaching proper velocity, are released unsuspectingly into the foes'\n"+
"face, torso, whatever.  Also, they are needed to drive Ted Nugent's\n"+
"limo.  \n");
set_class(17);
set_weight(4);
set_value(5000);
}
set_hit_func(this_object());
}
weapon_hit(attacker){
i=random(20);
if (i<5){
say(this_player()->query_name()+" 's keys stick into your eyes, good thing the wielder is a wimp!\n");
write("Keys fly everywhere sticking in all major areas of your foes face.\n");
return 1;
}
return 0;
}
