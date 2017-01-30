inherit"obj/monster";
reset(arg) {
object weapon;
::reset(arg);
if(arg) return;
set_name("skeleton");
set_alias("bones");
set_short("Skeleton");
set_long(
"A skeleton that is magically animated for some reason.  It isn't to smart\n"
+ "but it knows who it's victim is going to be.\n");
set_level(13);
set_race("skeleton");
set_al(150);
set_wc(20);
set_ac(13);
weapon = clone_object("/players/mouzar/players/mouzar/castle/under/obj/lbone");
move_object(weapon,this_object());
}
