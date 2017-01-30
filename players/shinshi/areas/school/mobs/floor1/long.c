inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("long");
	set_alt_name("teacher");
	set_race("human");
	set_alias("greg");
	set_short(HIK+"Mr. Long, Trigonometry Teacher"+NORM);
	set_long("\
	This is Greg Long. He is a tall, musclar man\n\
	with a light blue shirt on that has the school\n\
	mascot and logo on the pocket. He has short,\n\
	spikey hair and a goatee. He looks like he has\n\
	had one too many joints in his day.\n");
	set_level(25);
	set_hp(2500 + random (50));
	set_ac(40 + random (10));
	set_wc(40 + random(5));
	set_al(-7000);
	set_heal(50, 1);
	set_multi_cast(1);
	set_dead_ob(this_object());
	add_spell("water_dam",0,0,100,0,"physical",0, "do_water_dam");
	add_spell("shark",
	"\n\n"+HIK+"#MN# turns into a "+HIW+"hammerhead shark"+HIK+" and "+HIR+"CHOMPS "+HIK+"down on your leg!"+NORM+"\n\n",
	"\n\n"+HIK+"#MN# turns into a "+HIW+"hammerhead shark"+HIK+" and "+HIR+"CHOMPS "+HIK+"down on #TN#'s leg!"+NORM+"\n\n",
	35, 75, 0);
}

init(){
	::init();
	
	add_action("no_move", "out");
}

no_move()
{
	write("The door is locked!\n");
}

do_water_dam(object target, object room, int damage){
	
	object *inv;
	int i, size;
	
	if(!room) return;
	
	inv = all_inventory(room);
	for(i=0, size = sizeof(inv); i < size; i++)
	{
		if(inv[i]->is_npc() || inv[i]->is_player())
		{
			tell_object(inv[i], HIB+"\n\nWater fills your lungs!\n\n"+NORM);
			inv[i]->hit_player(10, "other|water");
		}
	}
}

monster_died()
{	
	move_object(clone_object("/players/shinshi/areas/school/heals/lifesavers.c"), environment());
	move_object(clone_object("/players/shinshi/areas/school/heals/lifesavers.c"), environment());
}