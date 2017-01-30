inherit "obj/weapon";

int i;
reset (arg){
::reset(arg);
if(!arg){
set_name("Bikini top");
set_alias("top");
set_short("Bikini top");
set_long("This is definitely something a rocker-girl like you\n"+
"would wear.  It is a bright, gold, tiger striped bikini top.\n"+
"Of course, this might have made good protection from the sun, it\n"+
"however, makes a even better weapon.\n");
set_class(15);
set_weight(2);
set_value(1000);

}
set_hit_func(this_object());
}
weapon_hit(attacker){
i=random(20);
if (i>5){
say(this_player()->query_name()+" 's bikini snaps you in the face--<TWAP>.\n");
write("The bikini comes to rest in your opponents crotch.\n");
return 1;
}
return 0;
}
