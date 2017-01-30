/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Shardak Masters Throne Room
//  Create Date:  2005.06.03
//	 Thanks to Everyone who helped me, specifically Vertebraker
*/
#include "/players/vertebraker/closed/shardak/def.h"
#include "/players/tristian/lib/worm_define.h"
inherit "players/vertebraker/closed/std/room.c";
int x;
int bones;


reset(arg) {
  bones = 1; /* moved bones here */
	if(arg) return;
  
set_light(1);
set_no_clean(1);
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

add_property("PK");

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
    AA("read","read");
    AA("Smell","smell");
    AA("Search","search");
    AA("Listen","listen");
    AA("cmd_shardak", "shardak");
    AA("marry","marry");
    AA("sit","sit"); 
    AA("go","go");
    AA("stand","stand");
    AA("worship","worship");
    AA("no_quit","quit");
    AA("grotto","grotto");
}

grotto(){
  if (present(this_player()->query_real_name("worm"), this_object())){
	  if(this_player()->query_guild_name() != "shardak"){
	  write("Worm's force of Will, cowers you in place, and you can not leave.\n");
	  say(TPN+" tries to leave but cowers before the force of Worm's will.\n");
	  return 1;
 }else{
	 
	  move_object(this_player(),"/players/vertebraker/closed/shardak/room/grotto.c");
	  say(TPN+"leaves to the grotto.\n");
      command("look",this_player());
      return 1;
  }}}

no_quit() {
  write(HIR+"Shardak does not allow you to leave from this place.\n\n"+NORM);
  return 1;
  }
  
read (str)
{
if(!str || str != "parchment")
{
  /* changed to notify_fail return 0 */
  notify_fail("You can only read the 'parchment'.\n");
  return 0;
}
if(str == "parchment")
{
  if (TPRN == "worm" || TPQL > 20)
  {
  write("You can do any of the following:\n"+
  HIG+"Read"+NORM+" the"+HIG+" Parchment"+NORM+" - This list.\n"+
  HIG+"Sit"+NORM+" on the "+HIG+"Throne"+NORM+" - Heals you slowly over time.\n"+
  HIG+"Stand"+NORM+" - Stand up from throne.\n"+
  HIG+"Worship Shardak"+NORM+" - Worship before the altar of Shardak.\n"+
  HIG+"Shardak"+NORM+" - Goto the Dark God.\n"+
  HIG+"Go"+NORM+" to the"+HIG+" Post, Lockers, Green"+NORM+" or"+HIG+" Hotel"+NORM+" - Transport to those places.\n"+
  HIG+"Smell"+NORM+" - Smell the air.\n"+
  HIG+"Listen"+NORM+" - Listen to the sounds in the air.\n"+
  HIG+"Marry"+NORM+" <individual1> <individual2> - Marry some suckers off.\n"+
  HIG+"Search"+NORM+" - Search the room.\n");
      return 1;
   }
   if (TPRN != "worm")
   {
   write("You can not understand the words of the "+HBWHT+"Dark God "+HIR+BLINK+"Shardak"+NORM+".\n");
   say(TPN+" tries to read the words of the "+HBWHT+"Dark God "+HIR+BLINK+"Shardak"+NORM+".\n");
   return 1;
   }
 }
} 
   
stand()
{
if (TPRN != "worm")
{
return 0;
}
if (TPRN == "worm")
{
  if (x == 1)
  {
    write("You are already standing.\n");
    return 1;
  }
  if (x == 2)
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
  if (TPRN != "worm")
  {
    write("You are not the ruler of this realm, as you sit in the throne you are\n"+
    "wracked with mental agony as the will of the "+HIK+"Dark God "+NORM+"fills your\n"+
    "mind, and evil invades your soul.\n");
    TP->hit_player(random(30), "other|evil");
    TP->hit_player(random(30), "other|dark");
    say(TPN+" sits upon the throne and is wracked in agony as the power\n"+
    "of the "+HIR+"Dragon God Shardak "+NORM+"rips through his mind and soul.\n");
    return 1;
  }
  if (TPRN == "worm")
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
    say((string)TPN + "disappears in a flash.\n");
    move_object(TP, environment(fiend));
    command("look", TP);
    return 1;
}
int go(string str) {
  object fiend;
  if(!str) {
    write("Where are you going?\n");
    return 1;}
  if(str == "lockers") 
  {
    write("You kneel down, bowing your head and muttering an incantation\n"+
    "to "+HIR+"Shardak "+NORM+"and disappear in a swirl of dark"+HIK+" mist"+NORM+".\n\n\n");
    say(TPN+" kneels down, mutters an incantation and\n"+
    "disappears in a swirl of dark"+HIK+" mist"+NORM+".\n");
    move_object(TP, "/players/catwoman/tl");
    command("look", TP);
    return 1;
  }
  if(str == "green") 
  {
    write("You kneel down, bowing your head and muttering an incantation\n"+
    "to "+HIR+"Shardak "+NORM+"and disappear in a swirl of dark"+HIK+" mist"+NORM+".\n\n\n");
    say(TPN+" kneels down, mutters an incantation and\n"+
    "disappears in a swirl of dark"+HIK+" mist"+NORM+".\n");
    move_object(TP, "/room/vill_green");
    command("look", TP);
    return 1;
  }
  if(str == "post")
  {
    write("You kneel down, bowing your head and muttering an incantation\n"+
    "to "+HIR+"Shardak "+NORM+"and disappear in a swirl of dark"+HIK+" mist"+NORM+".\n\n\n");
    say(TPN+" kneels down, mutters an incantation and\n"+
    "disappears in a swirl of dark"+HIK+" mist"+NORM+".\n");
    move_object(TP, "/room/post");
    command("look", TP);
    return 1;
  }
  if(str == "hotel")
  {
    write("You kneel down, bowing your head and muttering an incantation\n"+
    "to "+HIR+"Shardak "+NORM+"and disappear in a swirl of dark"+HIK+" mist"+NORM+".\n\n\n");
    say(TPN+" kneels down, mutters an incantation and\n"+
    "disappears in a swirl of dark"+HIK+" mist"+NORM+".\n");
    move_object(TP, "players/boltar/casino/hall2x1");
    command("look", TP);
    return 1;
  }
}
worship(str)
{
  if(!str || str != "shardak")
  {
    write("You can only worship your "+HBWHT+"Dark God "+HIR+BLINK+"Shardak"+NORM+".\n");
    return 1;
  }
  if(str == "shardak")
  {
    if (bones == 1)
    {
      write("Your sacrifice a victim on the altar, and flense the skin from his bones\n"+
      "and offer them to your "+HBWHT+"Dark God "+HIR+BLINK+"Shardak"+NORM+".\n");
      TP->add_alignment (-500);
      bones = 2;
      return 1;
    }
    if (bones == 2)
    {
    write("You have already sacrificed a victim to your "+HBWHT+"Dark God "+HIR+BLINK+"Shardak"+NORM+" today.\n");
    return 1;
    }
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



marry(str) {
  object g,b;
  object ring;
  string who1, who2;
  if((string)this_player()->query_real_name()!="worm") return 0;
  if(!str || sscanf(str, "%s %s", who1, who2) < 2) {
    write("Usage: 'marry <who> <who2>'\n");
    return 1;
  }
  if(!(g=find_player(who1))) {
    write("Can't find "+who1+"\n");
    return 1;
  }
  if(!(b=find_player(who2))) {
    write("Can't find "+who2+"\n");
    return 1;
  }
  if(!present(g, environment(this_player())) || !present(b, environment(this_player()))) {
    write(who1+" and "+who2+" must both be in the throne room.\n");
    return 1;
  }
  if(present("wedding ring", g) || present("wedding ring", b)) {
    write("Both parties must be unmarried !\n");
    return 1;
  }
  write("You marry "+who1+" and "+who2+".\n");
  ring = clone_object("/players/bastion/closed/ring");
  ring->init_arg(capitalize(who2));
  move_object(ring, g);
  ring = clone_object("/players/bastion/closed/ring");
  ring->init_arg(capitalize(who1));
  move_object(ring, b);
  tell_object(g, "You have been married!\n");
  tell_object(b, "You have been married!\n");
  who1=capitalize(who1); who2=capitalize(who2);
  emit_channel("junk", "(junk) The demon priest "+RED+"WORM"+NORM+" has laid an unholy blessing on "+who1+" and "+who2+".\n");
  return 1;
}



clean_up() { return 0; }
