inherit "obj/weapon";

int i;
reset (arg){
::reset(arg);
if(!arg){
set_name("bow");
set_alias("bow");
set_short("A Compound Bow");
set_long("The compound bow is used primarily for hunting big game.\n"+
"This includes hunting such creatues as: deer, elk, moose, bear,\n"+
"children, men, women, the elderly. Hunt to your heart's content.\n"+
".....................Smile and have a nice day!!!!!.......\n");
set_class(16);
set_weight(2);
set_value(4000);

}
set_hit_func(this_object());
}
weapon_hit(attacker){
i=random(20);
if (i>5){
say(this_player()->query_name()+" 's arrow stops you DEAD in your tracks.\n");
write("You whip off a few arrows-maiming your prey for life.\n");
return 1;
}
return 0;
}
