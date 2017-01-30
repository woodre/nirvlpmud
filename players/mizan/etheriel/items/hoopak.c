inherit "obj/weapon";
int die, p, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("hoopak");
    set_long("This is something that reminds you of a modern-day defense lacrosse stick,\n"+
	"except it is made of rock maple and has a sturdy one-piece leather sling.\n");
    set_short("A hoopak");
    set_class(15);
    set_value(2100);
    set_alias("hoopack");
    set_weight(1);
    set_hit_func(this_object());
    }
}
weapon_hit(attacker) {
 if(random(100) < 23) {
	write("You giggle happily as you land a direct blow to your opponent's crotch.\n");
	say((this_player()->query_name())+" looks really froody wielding a hoopak.\n");
	return 4 ;
	}
}
