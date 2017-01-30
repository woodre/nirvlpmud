inherit "obj/weapon.c";

/*
 *	Test Weapon to see if I still got it.
 */

reset (arg)
{
	::reset (arg);

	if (arg) return;

	set_name	("test_weapon");
	set_alias	("test");
	set_alias	("sword");

	set_long	("This is a test weapon.  It looks dull\n");
	set_short	("A Test Weapon");

	set_class	(10);
	set_weight	(2);
	set_value	(200);
	set_hit_func (this_object ());
}

weapon_hit (attacker)
{
	say (	"You see " + 
			capitalize (environment (this_object ())->query_name ()) +
			"swing the " + short () + " at " + 
			environment (this_object())->query_attacker ()->query_name () +
			".\n");
	write (	"You swing the " + short () + " at " + 
			environment (this_object())->query_attacker ()->query_name () +
			".\n");

	return (0);
}
