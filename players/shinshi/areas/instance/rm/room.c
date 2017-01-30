/* Most of this screwed up code was thought of by myself. 
 * Rumplemintz helped with the counter and the if, else if, etc.
 * Mizan helped with the code to make it so only one person cound enter the
 * "instance" once per reset
 */

/* Quick note, you should try to keep your lines inside your code less 
 * than 80 columns wide.  Most editors handle that well, and it keeps it
 * easier to read.  Some exceptions are not bad, just in general
 */


/* First, some defines to use later to make the code easier to read */
#define MOB_PATH "/players/shinshi/areas/instance/mobs/"

#include <ansi.h>/* Includes should go before inherits */

inherit "/room/room";

int occupied;/* Integer to check if this room is occupied or not */
int count;   /* Integer to keep track of reloads */

string realm(){ return "NT"; }      /* No teleports! */

void reset(int arg)
{
   ::reset(arg);
   if(arg) return;
   set_light(1);
   short_desc = HIK+"A large playground"+NORM;
   long_desc = "\
This large open area is filled with many different types of\n\
playground equipment. Many of the children stand in line\n\
waiting for a turn on the large eighteen foot wave slide.\n\
A couple of the younger children frolic in the open grass\n\
chasing down the different creatures that come around.\n\
There is a large sign that is protruding from the ground.\n";
   
   count = 0;   /* Reset reload count to 0 on room reset */
   
   items =
   ({
	   "equipment", "There is a slide, some swings, a jungle gym, and much more",
	   "swings", "Large swings are built into the ground allowing children to swing on them",
	   "jungle gym", "A large metal jungle gym which children can climb on and climb into",
	   "gym", "A large metal jungle gym in which children can climb on and climb into",
	   "children", "Tons of elementary school kids gather around the playground equipment",
	   "slide", "An eighteen foot wave slide that is made of metal",
	   "creatures", "Worms, birds, wasps, and mosquitos. Oh my",
	   "sign", "A large wooden sign that can be read",
   });
}

void init()
{
   ::init();
   add_action("getthefuckout", "exit");  /* Block exit if mobs present */
   add_action("reload", "reload");   /* Get some new mobs ! */
   add_action("read", "read");
   add_action("count", "count");
}

int query_occupied()   /* Query if the room is occupied */
{                      /* Can call this from other rooms */
   return occupied;
}

void set_occupied(int arg)     /* Sets occupied to arg */
{
   occupied = arg;
}

int reload()      /*Reload the room with random mobs*/
{                /* Using some additional code here to make it easier*/
   int mobs_gen;    /* mobs_gen is used for the random*/
   int mobs_num;    /* used for the random*/
   int different;   /* different is kind of mob*/
   int clone_amount;  /* Amount of mobs to clone*/
   int i;           /* generic integer to use in for() statement*/
   string mob;      /* mob is the object we're cloning*/
   mobs_num = random(60);
   different = random(80);
   switch(different)       /* switch statements are more efficient than if*/
   {                       /* else because it doesn't have to evaluate all*/
      case 0 .. 19 :       /* the statements, just jumps to the correct one*/
         mob = MOB_PATH+"sandworm.c";
         break;
      case 20 .. 39 :
         mob = MOB_PATH+"wasp.c";
         break;
      case 40 .. 59 :
         mob = MOB_PATH+"bluebird.c";
         break;
      case 60 .. 79 :
         mob = MOB_PATH+"mosquito.c";
         break;
      default:
         break;
   }
   switch(mobs_num)
   {
      case 0 .. 19 :
         clone_amount = 1;
         break;
      case 20 .. 39 :
         clone_amount = 2;
         break;
      case 40 .. 59 :
         clone_amount = 3;
         break;
      default:
         break;
   }
   if(present("shinshi_sandworm") || present("shinshi_wasp") ||
         present("shinshi_bird") || present("shinshi_mosquito"))
   {
      write("You cannot reload until all the mobs are cleared.\n");
      return 1;
   }
   if(count > 39)
      {
      write("The teacher comes over to you and drags you away by the ear!\n");
      write(HIR+"You have reloaded the room too many times.\n");
      this_player()->move_player("leaves#/players/shinshi/entrancehall.c");
      say(this_player()->query_name()+" is pulled outside of the room by the teacher.\n");
      occupied = 0;
      reset(0);
      return 1;
   }
/*  Next few lines were for debugging, can remove if you want.
   write("Count = "+count+"\n");
   write("Mobs_num = "+mobs_num+"\n");
   write("Different = "+different+"\n");
   write("Mob = "+mob+"\n");
   write("Clone_amount = "+clone_amount+"\n");
*/
   
   for(i=0;i<clone_amount;i++)
      move_object(clone_object(mob), this_object());
   command("look", this_player());
   write("You have reloaded the room.\n");
   count ++;
   return 1;
}

int getthefuckout()
{
		if(present("shinshi_sandworm") && !this_player()->query_ghost() || present("shinshi_wasp") && !this_player()->query_ghost() ||
			present("shinshi_bluebird") && !this_player()->query_ghost() || present("shinshi_mosquito") && !this_player()->query_ghost())
   		{
		write("You cannot leave until all the mobs are cleared.\n");
		say(this_player()->query_name()+" tries to leave but is blocked.\n");
		return 1;
   		}
   		
   	this_player()->move_player("through the misty doorway#/players/shinshi/entrancehall.c");
   	say(this_player()->query_name()+" exits through the misty doorway.\n");
   	occupied = 0;
   	reset(0);
   	return 1;
}

read(str)
{
	if(!str)
	{
		write("What would you like to read?\n");
		return 1;
	}
	
	if(str != "sign")
	{
		write("Maybe you should read the 'sign'.\n");
		return 1;
	}
	
	if(str == "sign")
	{
		write("You can 'reload' the room up to forty times.\n");
		write("You may also check the current 'count' of the room.\n");
		write("You may only 'exit' if there are no monsters left.\n");
		write("If you happen to die, you will have to walk back\n");
		write("to the church by yourself. When you get back onto\n");
		write("the bus, you will be able to 'retrieve' your corpse.\n");
		return 1;
	}
}

count()
{
	write("Count = "+count+"\n");
	return 1;
}