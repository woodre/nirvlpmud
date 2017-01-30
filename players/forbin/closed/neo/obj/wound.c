#include "../defs.h"

int Ticks, Num;

int drop() { return 1; }

id(str) { return str == "wound" || str == "neo_wound_object"; }

int query_value() { return 0; }
int query_weight() { return 0; }

reset()
{
	call_out("called_pain", 3);
}

void set_ticks(int x) { Ticks = x; }
void add_ticks(int x) { Ticks += x; }
int query_ticks() { return Ticks; }

void set_num(int x) { Num = x; }
void add_num(int x) { Num += x; }
int query_num() { return Num; }

called_pain()
{
	int damage;
	
	if(!environment(this_object())) 
	  return;
	  
	if(!living(environment(this_object())))
	{ 
		destruct(this_object()); 
		return 1; 
  }
  
	if(!Ticks)
	{
		destruct(this_object());
		return 1;
	}
	
	damage = (2 * Num) + random((3 * Num));

	tell_object(environment(this_object()),
	  RED+"Something painfully burrows further into your body!"+NORM+"\n");
  tell_room(environment(environment(this_object())),
    (string)environment(this_object())->QN+" writhes in agony!\n", ({ environment(this_object()) }));
	environment()->hit_player(damage, "other|poison");
	Ticks--;
	remove_call_out("called_pain");
	call_out("called_pain", 1 + random(3));
}
