/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Shardak Masters Throne Room
//  Create Date:  2005.06.03
//	 Thanks to Everyone who helped me, specifically Vertebraker
*/
#include "/players/vertebraker/closed/shardak/def.h"
#include "/players/tristian/lib/ansi.h"
inherit "players/vertebraker/closed/std/room.c";
int x;


reset(arg) {
	if(arg) return;
  
set_light(1);
x = 1;

short_desc = HIR+"The Depths"+NORM+" of "+HIK+"'Hate and Loathing'"+NORM; 

long_desc =
	" This is where the mortal incarnation of "+RED+"Shardak's"+NORM+" hate for the\n"+
	"world comes to contemplate the fates of his fellow followers of\n"+
	"the "+HBWHT+"Dark God"+NORM+" and the fates of the rest of the infidels. There is a\n"+
	"massive throne of the blackest "+HIK+"obsidian "+NORM+"sitting in the center of\n"+
	"the chamber, covered in "+YEL+"human hides"+NORM+". Inscribed into the floor is\n"+
	"a pentagram that is filled with what appears to be molten "+WHT+"silver\n"+NORM+
	"and to the rear of the chamber is an altar covered in dried "+HIR+"blood"+NORM+".\n\n";

items = ({

"pentagram",
        HIR+"             ,,---n---,,               \n"+
        "        ,--**   l   l  **--,          \n"+
        "      ,*        |   |        *,        \n"+
        "    ,'          |   |          *,      \n"+
        "   l           l     l           l     \n"+
        "  l           |       |           l    \n"+
        " ,=-----------+-------+-----------=,   \n"+
        " l *-,       l         l       ,-* l   \n"+
        ",'    *,    |           |    ,*    ',  \n"+
        "|       *-, |           | ,-*       |  \n"+
        "|          )-,         ,-(          |  \n"+
        "*         |   *,     ,*   |         *  \n"+
        " l       l      *-,-*      l       l   \n"+
        " *,     |      ,-' '-,      |     ,*   \n"+
        "  l     |    ,*       *,    |     l    \n"+
        "   l   l  ,-*           *-,  l   l     \n"+
        "   *,|,-*                 *-,|,*       \n"+
        "     *,                     ,*         \n"+
        "       *--,,           ,,--*           \n"+
        "           '**-------**'               "+NORM+"",
"throne", 
  "A huge throne of the blackest"+HIK+" obsidian"+NORM+" sits in the\n"+
	"center of the room, covered in the "+YEL+"skins "+NORM+"of those who\n"+
	"have fallen to The Master, Worm\n",
"silver",
	HIK+"Silver"+NORM+", in its liquid form, flows as if almost alive, and\n"+
	"is cool to the feel. Liquid Silver that is cool, must surely\n"+
	"be the will of the "+HIG+"Dark God "+NORM+"that created this room\n",
"altar",
	"An altar to the Master's god "+HIR+"Shardak"+NORM+". The "+RED+"blood\n"+NORM+
	"on it is testament to its frequent use\n",
   
});

dest_dir = ({
"/players/vertebraker/closed/shardak/room/grotto.c","grotto",
});

}

init() {
  ::init();
    add_action("Smell","smell");
    add_action("Search","search");
    add_action("Listen","listen");
    add_action("cmd_shardak", "shardak");
    add_action("sit","sit"); 
    add_action("go","go");
    add_action("stand","stand");
}
stand()
{
if (this_player()->query_real_name() != "worm")
{
return 0;
}
if (this_player()->query_real_name() == "worm")
{
  if( x == 1)
  {
    write("You are already standing.\n");
    return 1;
  }
  if( x == 2)
  {
    x = 1;
    write("You arise to your feet and prepare to make all suffer in\n"+
    "Shardak's name.\n");
    say("Worm arises from the obsidian throne, once again ready to make\n"+
    "others suffer in Shardak's name.\n");
    return 1;
  }
}
}
sit()
{
  if (this_player()->query_real_name() != "worm")
  {
    write("You are not the ruler of this realm, as you sit in the throne you are\n"+
    "wracked with mental agony as the will of the "+HIK+"Dark God "+NORM+"fills your\n"+
    "mind, and evil invades your soul.\n");
    this_player()->hit_player(random(25), "other|evil");
    this_player()->hit_player(random(25), "other|dark");
    say(this_player()->query_name()+" sits upon the throne and is wracked in agony as the power\n"+
    "of the "+HIR+"Dragon God Shardak "+NORM+"rips through his mind and soul.\n");
    return 1;
  }
  if (this_player()->query_real_name() == "worm")
  {
    if (x == 2)
	 {
	   write("You are already sitting upon your throne.\n");
     return 1;
   }
   if (x == 1)
	 {
	   x = 2;
	   write("You sit upon the obsidian throne and start to commune with your\n"+
	   "lord "+HIR+"Shardak "+NORM+"and you feel his power draining into\n"+
		 "you.\n");
     say("Worm sits upon the huge obsidian throne.\n");
/* make sure we don't process extra call_outs .. this next statement
cancels all heal_player call_outs currently processing */
    while(remove_call_out("heal_players") != -1);
    call_out("heal_players", 2);
    return 1;
  }
 }
}
heal_players()
{
  object worm;
/* instead of looping through inventory, we'll just see
if worm is logged on and is in this room */
  if((worm=find_player("worm")) && environment(worm)==this_object())
  {
    worm->heal_self(2);
/* if he's still here, we'll heal him and try again in 2 secs */
    call_out("heal_players", 2);
  }
/* if he's not, nothing happens */
  else
  {
/* nothing happens */
  }
}

int cmd_shardak(string str) {
  object fiend;
  if(str) return 0;

 (PATH+"shardak")->load();
  fiend = find_object(PATH+"shardak");
  if(!fiend || fiend->query_ghost()) {
    write("Shardak cannot be located in the world of the living.\n");
    return 1;
  }
    write("\n\tYou travel to the demonic demi-god Shardak.\n\n");
    say((string)this_player()->query_name() + "disappears in a flash.\n");
    move_object(this_player(), environment(fiend));
    command("look", this_player());
    return 1;
}
int go(string str) {
  object fiend;
  if(!str) {
    write("Where are you going?\n");
    return 1;}
  if(str == "lockers") 
  {
    move_object(this_player(), "/players/catwoman/tl");
    write("You kneel down, bowing your head and muttering an incantation\n"+
    "to "+HIR+"Shardak "+NORM+"and disappear in a swirl of dark"+HIK+" mist"+NORM+".\n\n\n");
    say(this_player()->query_name()+" kneels down, mutters an incantation and\n"+
    "disappears in a swirl of dark"+HIK+" mist"+NORM+".\n");
    command("look", this_player());
    return 1;
  }
  if(str == "post")
  {
    move_object(this_player(), "/room/post");
    write("You kneel down, bowing your head and muttering an incantation\n"+
    "to "+HIR+"Shardak "+NORM+"and disappear in a swirl of dark"+HIK+" mist"+NORM+".\n\n\n");
    say(this_player()->query_name()+" kneels down, mutters an incantation and\n"+
    "disappears in a swirl of dark"+HIK+" mist"+NORM+".\n");
    command("look", this_player());
    return 1;
  }
  if(str == "hotel")
  {
    move_object(this_player(), "players/boltar/hotel/hotel");
    write("You kneel down, bowing your head and muttering an incantation\n"+
    "to "+HIR+"Shardak "+NORM+"and disappear in a swirl of dark"+HIK+" mist"+NORM+".\n\n\n");
    say(this_player()->query_name()+" kneels down, mutters an incantation and\n"+
    "disappears in a swirl of dark"+HIK+" mist"+NORM+".\n");
    command("look", this_player());
    return 1;
  }
}

Smell(str) 
{
  if(!str || str == "air")
  {
  write("The smell of death and decay hang heavy in the air, along\n"+
  "with the sickening sweet smell of incense burning.\n");
  return 1;
  }
  return 1;
}

Search()
{
  write("You find nothing special.\n");
  return 1;
}

Listen()
{
  write("The sounds of the dead moaning fills the air, along with the\n"+
  "faint sounds of a sinister laugh, if you listen hard enough you\n"+
  "can almost hear the sounds of death creeping upon you.\n");
  return 1;
}



