inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("teacher")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/teacher.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "Pre-Kindergarten Entrance";
	long_desc =
		"This small room is rather plain.  There are two sets of glass doors\n"+
		"on opposite sides, and the walls are bare.  The floor is polished to\n"+
		"a glossy shine, reflecting the bright lighting from the ceiling.  A\n"+
		"potted plant sits in one corner, adding a little decoration to the\n"+
		"otherwise empty room.\n";


items =

({
	"doors", "Which doors? Wooden or glass?",
	"glass doors", "Large glass doors make an exit to the outside",
	"walls", "Bare walls surround you",
	"floor", "The floor glistens and sparkles",
	"light", "Large lights are lined evenly among the ceiling",
	"ceiling", "White rectangular tiles form a ceiling",
	"plant", "A small plant that seems too green to be real",
	"corner", "Where two walls come together",
	"lighting", "Large lights are lined evenly along the ceiling",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm2.c", "north",
	"/players/shinshi/entrancehall.c", "exit",
});
}

query_no_fight() { return 1; }

init(){
  ::init();
	add_action("exchange","exchange");
  }

exchange(str){
  object one, two, three, four, teacher;
  	teacher = present("teacher");
	one = present("shinshi_lipstick", this_player());
	two = present("shinshi_key", this_player());
	three = present("shinshi_tampon", this_player());
	four = present("shinshi_purse", this_player());

	if(!teacher){
		return;
	}
	
	if(str == "lipstick")
	{
		if(!one)
		{
			write("The teacher looks at you and yells,\"YOU DON'T HAVE THAT ITEM!\"\n");
		return 1;
		}
			write("The teacher says, \"Thank you for returning my lipstick!\"\n");
			this_player()->add_money(4500 + random(1000)); destruct(one);
		return 1;
		}
	if(str == "key")
	{
		if(!two)
		{
			write("The teacher looks at you and yells,\"YOU DON'T HAVE THAT ITEM!\"\n");
		return 1;
		}
			write("The teacher says, \"Thank you for returning my key!\"\n");
			this_player()->add_money(4500 + random(1000)); destruct(two);
		return 1;
		}
	if(str == "tampon")
	{
		if(!three){
			write("The teacher looks at you and yells,\"YOU DON'T HAVE THAT ITEM!\"\n");
		return 1;
		}
			write("The teacher says, \"This isn't mine but I can still use it!\"\n");
			this_player()->add_money(4500 + random(1000)); destruct(three);
		return 1;
		}
	
	if(str == "purse")
	{
		if(!four)
		{
			write("The teacher looks at you and yells,\"YOU DON'T HAVE THAT ITEM!\"\n");
		return 1;
		}
			write("The teacher says, \"Thank you for returning my purse!\"\n");
			this_player()->add_money(7000 + random(1000)); destruct(four);
		return 1;
		}
}
