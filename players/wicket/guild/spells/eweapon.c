status main(string str, object PO, object User)
{

	object weapon;
	string weapontype;
	
	if(PO->query_suspend())
	{
		write("You are suspended and cannot do that.\n");
		return 1;
	}
	
	if(!str)
	{
		write("You must select a certain Elemental Weapon.\n");
		write("Ex. 'air' 'earth' 'fire' 'water'\n");
		return 1;
	}
	
	if(str != "air" && str != "earth" && str != "fire" && str != "water")
	{
		write("You can only choose 'air' 'earth' 'fire' or 'water'.\n");
		return 1;
	}
	
	if(User->query_sp() < 15)
	{
		write("You do not have the energy to summon your weapon.\n");
		return 1;
	}
	
	if(User->query_wielded())
	{
		write("You are already wielding your weapon!\n");
		return 1;
	}
	
	if(present("wicket_elementalist_staff", User))
	{
		write("You already have your weapon!\n");
		return 1;
	}
	
	if(str == "air")
	{
		weapontype = "airweapon";
	}
	
	if(str == "earth")
	{
		weapontype = "earthweapon";
	}
	
	if(str == "fire")
	{
		weapontype = "fireweapon";
	}
	
	if(str == "water")
	{
		weapontype = "waterweapon";
	}
	
	weapon = clone_object("/players/wicket/guild/objs/"+weapontype+".c");
	move_object(weapon, User);
	write("You concentrate heavily on the Elements and beg for them to grant you\n");
	write("the ancient staff of their ancestors. A bright light appears besides you.\n");
	write("The light starts to grow and glow brighter. The tip of the light begins to\n");
	write("solidify into wood. The solidification process continues rather quickly.\n");
	write("\n");
	write("The bright light dissipates completely. The Ancient Staff of the Elements\n");
	write("floats into your hand and fuses it to your skin. You are now one with the Staff.\n");
	command("wield staff", User);
	User->add_spell_point(-15);
	return 1;
}