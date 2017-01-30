#include <ansi.h>      /* include statements before inherits */

/* Add a define for the playround path */
#define PLAYGROUND "/players/shinshi/areas/instance/rm/room"

inherit "/room/room";

string *people;    /* Array of who's been in the other room */

reset(arg)
{
   ::reset(arg);
   if(!present("shinshi_poster")) {
      move_object(clone_object("/players/shinshi/areas/pk/objs/posters.c"),this_object());
   }
   
   if(!present("shinshi_rogue_entrance")) {
	   move_object(clone_object("/players/shinshi/closed/rogue/hall/mobs/figure.c"), this_object());
   }
   
   if(arg) return;
   people = ({ });
   set_light(1);
   short_desc = "A large yellow school bus";
   long_desc =
      "The inside of this large, yellow school bus is filled with rows\n"+
      "and rows of high-backed seats. The seats are filled with kids, and\n"+
      "they are all staring at you. There is a "+HIK+"sign"+NORM+" here.\n";
   items =
   ({
        "kids", "Their eyes seem to pierce your soul as they stare you down",
        "sign", "There are currently two 'stop's available: pre-k and playground",
        "driver", "A dark figure wearing a dark leather hood",
        "bus driver", "A dark figure wearing a dark leather hood",
        "rows", "Sixteen seats lines on each side of the bus with a walkway in the middle",
        "seats", "Large brown leather seats which can seat up to two people",
        "walkway", "A large black walkway which runs all the way to the back of the bus",
   });
   dest_dir =
   ({
      "/room/south/sforst41.c", "out",
      "/players/shinshi/areas/pk/rooms/entry.c", "pk",
   });
}

realm(){ return "NT"; }
query_no_fight(){ return 1; }

init(){
   ::init();
   add_action("stop","stop");
   add_action("view","view");
   add_action("retrieve", "retrieve");
   add_action("bow", "bow");
   add_action("join", "join");
}

join()
{
	object ob, recruiter;
	int currentexp;
	
	ob = present("shinshi_rogue_seal", this_player());
	
	if(ob)
	{
		write("You are already a Rogue, idiot.\n");
		return 1;
	}
	
	if(this_player()->query_level() < 15){
		write("You need to be at least level 15.\n");
		return 1;
	}
	
	if(this_player()->query_guild_exp() || this_player()->query_guild_rank()){
		write("You are already in a guild.\n");
		return 1;
	}
	
	if(restore_object("players/shinshi/closed/rogue/members/"+this_player()->query_real_name()))
	{
		tell_object(this_player(), "You must speak to Shinshi to rejoin.\n");
		return 1;
	}
	
	recruiter = clone_object("/players/shinshi/closed/rogue/objects/recruiter.c");

	tell_object(this_player(), "\n");
	tell_object(this_player(), "If you wish to join the rogues, you will be\n");
	tell_object(this_player(), "reset to level 15 experience and you must set PK immediately.\n");
	tell_object(this_player(), "Once you join, it is highly recommended that\n");
	tell_object(this_player(), "you read through the help files. If you still\n");
	tell_object(this_player(), "wish to become a Rogue, you may type 'join' now.\n");
	tell_object(this_player(), "\n");
	move_object(recruiter, this_player());
	recruiter->start_it();
	write_file("/players/shinshi/closed/rogue/logs/OFFERED", ctime()[4..15] + "  " +this_player()->query_name()+ " has been offered to join the guild.\n");
	return 1;
}

bow(str)
{
	object gob;
	if(!str)
	{
		write("Who would you like to bow to?\n");
		return 1;
	}
	
	gob = present("shinshi_rogue_seal", this_player());
	
	if(str == "figure")
	{
		if(!gob)
		{
			write("The "+HIK+"dark figure"+NORM+" looks at you suspiciously.\n");
			return 1;
		}
		
		if(gob)
		{
			write("The "+HIK+"dark figure"+NORM+" notices your seal and bows.\n");
			write("The "+HIK+"dark figure"+NORM+" stomps his foot onto the gas pedal.\n");
			write("The floor where you stand begins moving.\n");
			write("You fall through the floor into a dungeon!\n");
			move_object(this_player(), "/players/shinshi/closed/rogue/hall/rooms/entrance.c");
			return 1;
		}
		return 1;
	}
	else
	{
		write("You bow to your audience.\n");
		return 1;
	}
	return 1;
}

stop(str)
{
        if(!str)
        {
                write("Where would you like to stop?\n");
                return 1;
        }
   if(str=="pre-k")
   {
      this_player()->move_player("leaves#/players/shinshi/areas/coining/rooms/rm1.c");
      say(this_player()->query_name()+" is dropped off at school.\n");
      write_file("/players/shinshi/logs/entry.txt", ctime()[4..15] + " " + this_player()->query_name() + " has entered area: PRE-K\n");
      return 1;
   }
   
   if(str=="playground")
   {
	   /*write("The playground is currently down for reconstruction.\n");
	   return 1;
   }*/
      if(member_array(this_player()->query_real_name(), people) > -1)
      {
         write(HIR+"You are temporarily banished from the playground.\n"+NORM);
         say(this_player()->query_name()+
            " is temporarily banished from the playground.\n");
         return 1;
      }
      if(PLAYGROUND->query_occupied())
      {
         write("The playground is occupied.  Please try again later.\n");
         return 1;
      }   
      people += ({ this_player()->query_real_name() });
      PLAYGROUND->set_occupied(1);
      write(HIK+"You step off the bus and enter a misty doorway.\n"+NORM);
      this_player()->move_player("off the bus and into a misty doorway#/players/shinshi/areas/instance/rm/room.c");
      say(HIK+this_player()->query_name()+" is dropped off at the playground.\n"+NORM);
      write_file("/players/shinshi/logs/entry.txt", ctime()[4..15] + " " + this_player()->query_name() + " has entered area: PLAYGROUND\n");
      return 1;
   }
   
   if(str=="pk")
   {
	   this_player()->move_player("leaves#/players/shinshi/areas/pk/rooms/entry.c");
	   say(this_player()->query_name()+" is dropped off at the PK room.\n");
	   write_file("/players/shinshi/logs/entry.txt", ctime()[4..15] + " " + this_player()->query_name() + " has entered area: PK\n");
	   return 1;
   }
   
   write("You cannot stop there!\n");
   return 1;
}

view(str)
{
   if(!str)
   {
      write("What would you like to view?\n");
      return 1;
   }
   if(str != "agreement" && str != "notice" && str != "commands")
   {
      write("That is not here to view!\n");
      return 1;
   }
   if(str == "agreement")
   {
      cat("/players/shinshi/areas/pk/agreement.txt");
      return 1;
   }
   if(str == "notice")
   {
      cat("/players/shinshi/areas/pk/notice.txt");
      return 1;
   }
   if(str == "commands")
   {
      cat("/players/shinshi/areas/pk/commands2.txt");
      return 1;
   }
}

retrieve()
{
	object room, corpse;
	
	room = find_object("/players/shinshi/areas/instance/rm/room");
	
	if(!room) 
	{
		write("DEBUG: Room not found.\n");
		return 1;
	}
	
	corpse = present("corpse", room);
	
	if(!corpse)
	{
		write("Your corpse could not be found...\n");
		return 1;
	}

	if(member_array(this_player()->query_real_name(), people) > -1)
	{
		transfer(corpse, this_player());
		write("Your corpse magically appears in your inventory.\n");
		PLAYGROUND->set_occupied(0);
		return 1;
	}
}
