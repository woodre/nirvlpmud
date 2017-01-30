 
inherit "obj/weapon";
 
int i;
reset (arg){
::reset(arg);
if(!arg){
set_name("rifle");
set_alias("gun");
set_short("A Rifle");
set_long("A ordinary military-issue rifle complete with bayonet.\n");
set_class(15);
set_weight(2);
set_value(1000);
 
}
set_hit_func(this_object());
}
weapon_hit(attacker){
i=random(20);
if (i>5){
say("ratat-a-tat-a-at.\n");
write("You slam the bayonet deep into their gut!\n");
return 1;
}
return 0;
}
      
