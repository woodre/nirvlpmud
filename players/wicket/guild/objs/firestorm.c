#include <ansi.h>
#define MAX_BEATS 10

id(str) { return str == "firestorm_damage"; }

start_it()
{
	set_heart_beat(1);
	call_out("end_it", MAX_BEATS);
}

heart_beat()
{
	object *inv, room;
	int i, size, damage;
	
	room = environment();
	
	if(!room) return;
	
	damage = 10 + random(6);
	
	inv = all_inventory(room);
	for(i=0, size = sizeof(inv); i < size; i++)
	{
		if(inv[i]->is_player())
		{
			if(inv[i]->query_guild_name() != "Elementalist" && inv[i]->query_pl_k() && inv[i]->query_fight_area())
			{
				tell_object(inv[i], HIR+"\nFire"+NORM+" rains down from the skies.\n");
				inv[i]->hit_player(damage, "other|fire");
			}
			
		}
		
		if(inv[i]->is_npc())
		{
			if(!inv[i]->is_djinn() && !inv[i]->is_kid())
			{
				tell_object(inv[i], HIR+"\nFire"+NORM+" rains down from the skies.\n");
				inv[i]->hit_player(damage, "other|fire");
			}
		}
	}
}
		/*if(inv[i]->is_player() || inv[i]->is_npc())
		{
			if(inv[i]->query_guild_name() != "Elementalist" && !inv[i]->is_djinn() && (inv[i]->is_player() && inv[i]->query_pl_k()))
			{
				tell_object(inv[i], HIR+"Fire"+NORM+" rains down from the skies.\n");
				inv[i]->hit_player(damage, "other|fire");
			}
		}*/

end_it()
{
	object roomie;
	
	roomie = environment();
	
	tell_object(roomie, "The "+HIR+"FireStorm"+NORM+" subsides.\n");
	destruct(this_object());
	return 1;
}