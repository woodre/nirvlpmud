inherit "obj/weapon";
int die, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("wet noodle");
    set_long("Blessed and honed to ungodly strength by the power of the\n"+
	"spoken word, this seemingly harmless length of spagetti can\n"+
	"inflict immense amounts of pain. After all, this is only a game.\n"+
	"Right?\n");
    set_short("A wet noodle");
    set_class(15);
    set_value(2000);
    set_alias("noodle");
    set_weight(1);
    set_hit_func(this_object());
    }
}
weapon_hit(attacker) {
 if(random(100) < 11) {
	write("*SMACK!* The noodle leaves an uncanny path of pain and destruction!\n");
	say((this_player()->query_name())+"'s wet noodle slams with authority!\n");
	return 2 ;
	}
}
