inherit "/obj/monster.c";
#include "../definitions.h"

int my_random_move_time;

void set_random_move_time(int arg)
{
	if(!arg || arg < 0) return;
	my_random_move_time = arg;
}

void reset(int arg)
{
	::reset(arg);

	/* blank out our variables */
	my_random_move_time = 0;

	enable_commands();
	remove_call_out("make_random_move");
	call_out("make_random_move", 1);
}

void make_random_move()
{
   int n;
   if(my_random_move_time < 1) return;
   
   /* if we are not fighting, we move */
   if(!this_object()->query_attack())
   {
      n = random(5);
      if (n == 1)
      command("west");
      if (n == 2)
      command("east");
      if (n == 3)
      command("south");
      if (n == 4)
      command("north");
   }

   remove_call_out("make_random_move");
   call_out("make_random_move", my_random_move_time);

}
