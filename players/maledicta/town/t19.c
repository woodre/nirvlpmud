/*  This room sets a players title for the cost of 1000 coins.
    Guildless and anyone above level 8 can set title. This
    keep those guilded ppl from setting to something outside
    of theme.  
    All titles set are logged in /players/maledicta/log/titles.
    Players are told that abuse of this will lead to jailtime,
    And so, if they do abuse it, jail them. 
    As of 5/13 I have opened the title setter to symbiotes and
    fallen with permission of Zeus that his guild can set their
    title without interfering with theme  */

#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object owner;
reset(arg) {
if(!present("hall_clerk")){
	owner = clone_object("/players/maledicta/town/mobs/hall_clerk.c");
	move_object(owner, this_object());
	}	
	
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  This is the entry chamber of Derellia IV's town hall. The walls here are\n"+
"made of a beautiful white stone, the floor a polished black marble. Tall\n"+
"pillars line the walls, several heavy cloth banners hanging between them.\n"+
"A help desk can be seen directly in front of you, a small plastic sign\n"+
"sitting on its surface.\n";

items = ({
  "walls",
  "Beautiful white stone walls that are very clean and shine",
  "stone",
  "It is much the same as the other white stone seen around town, only\n"+
  "polished to a fine finish",
  "floor",
  "Made of polished marble, it is beautiful and well cared for",
  "marble",
  "A fine marble uncommon to this area",
  "pillars", 
  "Reaching all the way to the ceiling, they are finely crafted and\n"+
  "sturdy",
  "banners",
  "Made from a heavy cloth, the banners display the symbol of the town\n"+
  "as well as a few others symbols you aren't familiar with",
  "desk",
  "A long wooden desk that has been placed here to help the visitors\n"+
  "to the hall. A plastic sign sits on top of it",
  "sign",
  "This is a small clear plastic sign with black letters imprinted\n"+
  "on its smooth surface. Perhaps you should try reading it?",
});

dest_dir = ({
  "/players/maledicta/town/rooms/t14.c","out",
});

}
init(){
  ::init();
  add_action("read_it", "read");
  add_action("title_set", "change_title");
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	


read_it(string str){
	if(!str){ write("Read what?\n"); return 1; }
	  if(str = "sign"){
  	write(
"\t .........******Welcome to Town Hall******.........\n"+
"\t .                                                .\n"+
"\t . For a small processing fee of 1000 coins we    .\n"+
"\t . can legally change your title. To do so use:   .\n"+
"\t .                                                .\n"+
"\t .              change_title <title>              .\n"+
"\t .                                                .\n"+
"\t . For example:                                   .\n"+
"\t .    change_title the great                      .\n"+
"\t .                                                .\n"+
"\t .                  [NOTICE]                      .\n"+
"\t .        Misuse will lead to JAIL time, do       .\n"+
"\t .        NOT abuse this.  All titles set         .\n"+
"\t .        are logged and checked regularly.       .\n"+
"\t ..................................................\n"+
"\t              --- Have a nice day ---              \n");
  	return 1;
        }
  return;
  }		
title_set(string str){
if(!present("hall_clerk", this_object())){
write("The clerk isn't here to assist you.\n");
return 1;
}
if(this_player()->query_level() < 8){
   write(
   "Clerk says: I'm sorry, but I cannot find your records. Please come back another time.\n");
    return 1;
    }		
if(this_player()->query_guild_name() == "symbiote"){  
if(present("venom_object", this_player()) &&
   present("venom_object", this_player())->query_venomed()){
   write("You cannot set your title when changed!\n");
   return 1;
   }  
if(this_player()->query_money() < 1000){
write("You don't have enough coins!\n");
return 1;
}
this_player()->set_title(str);
this_player()->add_money(-1000);
write_file("/players/maledicta/log/titles",
  ctime(time())+"  "+HIR+this_player()->query_real_name()+NORM+" set title too: "+str+"   \n");

write("Your title has been officially changed to "+this_player()->query_name()+" "+
""+this_player()->query_title()+".\n");
return 1;
}	

if(!str){
write("change it to what?\n");
return 1;
}

if(this_player()->query_guild_rank() ||
   this_player()->query_guild_exp()){
   write("Clerk says: I'm sorry, but you cannot set your title if you are in a guild.\n");
   return 1;
   }
if(this_player()->query_guild_name() == "fallen"){
if(this_player()->query_money() < 1000){
write("You don't have enough coins!\n");
return 1;
}
this_player()->set_title(str);
this_player()->add_money(-1000);
write_file("/players/maledicta/log/titles",
  ctime(time())+"  "+HIR+this_player()->query_real_name()+NORM+" set title too: "+str+"   \n");

write("Your title has been officially changed to "+this_player()->query_name()+" "+
""+this_player()->query_title()+".\n");
return 1;
}	
if(this_player()->query_guild_rank() ||
   this_player()->query_guild_exp()){
   write("Clerk says: I'm sorry, but you cannot set your title if you are in a guild.\n");
   return 1;
   }

if(this_player()->query_guild_name()){
  write("Clerk says: I'm sorry, but you cannot set your title if you are in a guild.\n");
  return 1;
  }

if(this_player()->query_money() < 1000){
write("You don't have enough coins!\n");
return 1;
}
this_player()->set_title(str);
this_player()->add_money(-1000);
write_file("/players/maledicta/log/titles",
  ctime(time())+"  "+HIR+this_player()->query_real_name()+NORM+" set title too: "+str+"   \n");

write("Your title has been officially changed to "+this_player()->query_name()+" "+
""+this_player()->query_title()+".\n");
return 1;
}				