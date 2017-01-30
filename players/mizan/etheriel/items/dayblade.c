inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("dayblade");
    set_long("This is a sword of ordinary design, but it radiates\n"+
	"a soft, yellow light, and you tremble slightly as you run your\n"+
	"fingers along the length of it.\n");
    set_short("Dayblade");
    set_class(17);
    set_value(6600);
    set_alias("blade");
    set_weight(3);
    set_hit_func(this_object());
    }
}
weapon_hit(attacker) {
 if(random(100) < 15) {
	write("Your sword glows with power!\n");
	say((this_player()->query_name())+"'s sword seems to glow for a moment.\n");
	return 6 ;
	}
}
