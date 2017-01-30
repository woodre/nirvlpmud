/*

 THIS WEAPON HAS WC 23.

It also weighs 9. _9_. Nine. Nueve. 9 = heavy.
HEAVY.
H E A V Y.

*/
inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("telephone pole");
    set_short("A telephone pole");
    set_class(23);
    set_value(3000);
    set_alias("pole");
    set_weight(12);
/*Added by Hawkeye Sept 23 1994 for two reasons, 1) Mainly its
wc 23 and no superweaopn like that should store and 2) just for
game play, do you really think a telephone pole will fit in
a hotel room?*/
/* 60 is way over the top. 12. */
/* verte 2004. */
     set_save_flag(1);
    set_hit_func(this_object());
    set_long("This is a very BIG stick, about the size of a tree.\n"); 
    }
}
/* added this in weapon_hit(), this stuff was in reset() */
weapon_hit(attacker)
{
 if(random(100) < 11) {
	write("You smash your opponent with a telephone pole!\n");
        say(environment()->query_name()+" goes batty with a telephone pole!\n");
	return 7 ;
	}
}
