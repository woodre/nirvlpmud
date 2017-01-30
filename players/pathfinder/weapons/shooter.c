inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
		set_name("gun");
		set_class(19);
		set_value(7000);
		set_weight(3);
		set_alias("gun");
	set_short("A Six Shooter");
set_long(
"Rolands pistol feels good as you hold it in your hands.  As you \n" +
"spin the bullets in their chamber you have a compelling feeling\n" +
"to squeez off all six into someone's body.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
/* I DONT THINK SO  - mythos <6-21-96>
	if(random(100) < 75) {
*/
   if(randon(3) == 0) {
say(capitalize(this_player()->query_real_name()) + "unloads all six rounds!\n");
write("***BLAM***\n" +
"     ***BLAM***\n" +
"          ***BLAM***\n" +
"               ***BLAM***\n" +
"                    ***BLAM***\n" +
"                         ***BLAM***\n");
return 3;
}
}
query_save_flag() { return 1; }
