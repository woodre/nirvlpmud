#include "/players/coldwind/define.h"

#define user environment(this_object())->query_name()
inherit "obj/treasure.c";

id(str){ return str == "gift" || str == "box" || str == "blinkrest43"; }
short(){ return ""+BOLD+RED+"W"+GRN+"rappe"+RED+"d C"+GRN+"hristma"+RED+"s G"+GRN+"if"+RED+"t"+NORM+""; }

long()

{
	write("  A box that is wrapped in red and green. It looks\n"+
		  "like an expensive Christmas gift. You may 'unwrap' \n"+
		  "the 'gift'.\n");
}

init()
{
	add_action("giftt", "unwrap");
}

giftt(str){
if(str == "gift" || str == "box")
{
object one;
one = present("blinkrest43", this_player());
if (one){
say(""+user+" unwraps their gift, then stumbles back as shit sprays everywhere.\n");
write("You unwrap your gift...\n"+
  "You jump back as a pile of shit blows up, spraying you in the face.\n");
destruct (one);
move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), this_player());

	return 1;
}
if(!str){ write("unwrap what?\n"); return 1; }
} }
