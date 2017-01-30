inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("chainsaw");
    set_long("You can't help but laugh as you imagine plunging this into\n"+
	"some poor creature's chest...\n");
    set_short("A chainsaw");
    set_class(12);
    set_value(10);
    set_alias("chainsaw");
    set_weight(3);
    set_hit_func(this_object());
    }
 if(random(100) < 11) {
	write("You cackle gleefully as you swing the chainsaw wildly!\n");
	say((this_player()->query_name())+" goes nuts with a chainsaw!\n");
	return 7;
	}
}
