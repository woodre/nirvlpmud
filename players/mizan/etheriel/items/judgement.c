inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
		set_class(18);
		set_value(10000);
		set_weight(4);
                set_alias("sword");
	set_short("Sword of Judgement");
set_long(
"  Crafted of a sinister blue steel, and crowned with a sleek polished hilt,\n"+
"  this weapon looks like it is fit for even the gods to use.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 25)  {
	write("Your blade vibrates with sheer power!\n");
	say((this_player()->query_name())+"'s sword thunders with pure energy!\n");
	return 4;
	}
}
