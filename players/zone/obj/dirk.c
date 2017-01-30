inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("shadow dirk");
set_alias("dirk");
set_short("dirk");
set_long(
"A dirk with a curvy blade.  The silvery blade has a ruddy glow eminating\n"
+ "from it's surface.  The pommel is the skull of a minotour, and the\n"
+ "hilt is of carved hoof.  The crosspiece is made of two long canine teeth\n"
+ "giving the dagger an overall sinister look.\n");
set_value(10000);
set_weight(1);
set_class(15);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) > 90) {
write("The dirk eminates black and envelops "+attacker->query_name()+"\n");
say("The dirk glows black (never seen that before) and feels cold.\n");
return 1;
 }
}
