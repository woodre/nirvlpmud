inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  set_long("This is an ordinary drinking straw. Hmmm... rather useless,\n"+
	"except if you had a nice, cold can of soda, or a few spitballs.\n"+
	"Otherwise, I guess it could be 'wielded'.\n");
    set_short("A drinking straw");
    set_class(4);
    set_value(10);
    set_alias("straw");
    set_weight(1);
    set_hit_func(this_object());
}
