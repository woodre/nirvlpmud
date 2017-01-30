#include "../defs.h"

status main(string str, object PO, object User)
{
	object corpse, guts, berry;
	int lucky, lucky2;
	
	if(!str)
	{
		write("What would you like to dissect?\n");
		return 1;
	}
	
	if(str != "corpse")
	{
		write("You cannot dissect that!\n");
		return 1;
	}
	
	corpse = present("corpse", environment(User));
	
	if(!corpse)
	{
		write("There is no corpse to dissect.\n");
		return 1;
	}
	
	if(corpse)
	{
		lucky = random(98);
		lucky2 = random(4);
		
		if(present("guts", User))
		{
			if(lucky2 == 0)
			{
				berry = clone_object(OBJPATH+"berry1.c");
			}
			
			else if(lucky2 == 1)
			{
				berry = clone_object(OBJPATH+"berry2.c");
			}
			
			else if(lucky2 == 2)
			{
				berry = clone_object(OBJPATH+"berry3.c");
			}
			
			else if(lucky2 == 3)
			{
				berry = clone_object(OBJPATH+"berry4.c");
			}
			move_object(berry, User);
			destruct(corpse);
			say(User->query_name()+" decimates the corpse with "+possessive(User)+" weapon.\n");
			write("You dig through the corpse and find some berries.\n");
			return 1;
		}
		if(!present("guts", User))
		{
			
			if(lucky < 32)
			{
				guts = clone_object(OBJPATH+"guts.c");
				move_object(guts, User);
				destruct(corpse);
				say(User->query_name()+" decimates the corpse with "+possessive(User)+" weapon.\n");
				write("You dig through the corpse but only retrieve its guts.\n");
				return 1;
			}
			if(lucky > 32 && lucky < 65)
			{
				if(lucky2 == 0)
				{
					berry = clone_object(OBJPATH+"berry1.c");
				}
				else if(lucky2 == 1)
				{
					berry = clone_object(OBJPATH+"berry2.c");
				}
				else if(lucky2 == 2)
				{
					berry = clone_object(OBJPATH+"berry3.c");
				}
				else if(lucky2 == 3)
				{
					berry = clone_object(OBJPATH+"berry4.c");
				}
				move_object(berry, User);
				destruct(corpse);
				say(User->query_name()+" decimates the corpse with "+possessive(User)+" weapon.\n");
				write("You dig through the corpse and find some berries.\n");
				return 1;
			}
			if(lucky > 65)
			{
				guts = clone_object(OBJPATH+"guts.c");
				if(lucky2 == 0)
				{
					berry = clone_object(OBJPATH+"berry1.c");
				}
				else if(lucky2 == 1)
				{
					berry = clone_object(OBJPATH+"berry2.c");
				}
				else if(lucky2 == 2)
				{
					berry = clone_object(OBJPATH+"berry3.c");
				}
				else if(lucky2 == 3)
				{
					berry = clone_object(OBJPATH+"berry4.c");
				}
				move_object(berry, User);
				move_object(guts, User);
				destruct(corpse);
				say(User->query_name()+" decimates the corpse with "+possessive(User)+" weapon.\n");
				write("You dig through the corpse and gather some berries and some guts.\n");
				return 1;
			}
			return 1;
		}
		return 1;
	}
	return 1;
}