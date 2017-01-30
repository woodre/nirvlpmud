/* BLACK WILLOW ORDER DOCUMENTATION
   FILE: 					_say.c
	 CATEGORY:			Guild Command
	 DESCRIPTION:		This command handles converting a players intended
									say into the guild format. Since guild rules dictate
									that members take a vow of silence until attaining
									rank 3, the player's rank is checked. If rank is 
									found to be insufficient the player is notified of
									the infraction and is punished severely. Hit points
									are reduced to 10 
*/
#include <ansi.h>
cmd_say(str)
{
  object slave;
  if(this_player()->query_guild_rank() < 3) {
		write("Your head feels like it will explode as a booming voice invades your mind.\n"+
					HIK+"		You will learn to respect the "+HIC+"Oath of Silence"+HIK+"!\n"+NORM+
					"Suddenly you are engulfed in a pillar of searing "+HIK+"Black Flame"+NORM+", burning you!\n"+
					"Your skin begins to melt from your body as intense pain saps your strength!\n"+
					"Just as you are about to die the flames disappear, leaving your body smoking.\n");
		say("From out of nowhere a pillar of "+HIK+"Black Flame"+NORM+" engulfs "+this_player()->query_name()+"!\n"+
				this_player()->query_name()+" rolls on the ground in a pathetic attempt to extinguish the flames.\n"+
				"Suddenly the flames disappear without a trace except for the horrific burns on "+this_player()->query_name()+".\n");			
		this_player()->set_hp(10);
		return 1;
	}
	
	write("You transmit: '"+str+"'\n");
  say(HIR+"["+HIK+this_player()->query_name()+HIR+"] "+HIY+"::"+HIR+" \""+HIK+capitalize(str)+HIR+"\"\n"+NORM);
  return 1; 	
}
