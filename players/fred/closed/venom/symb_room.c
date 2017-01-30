#include "defs.h"
#define SYMB present("venom_object", TP) 

inherit "room/room";

int allow_challenge;
object sponsor;

reset(arg) 
{
  if(!present("black ball", this_object()))
  {
    move_object(clone_object("/players/fred/closed/venom/OBJ/ball.c"), this_object());
  }
  
  if(arg) return;
  
  set_light(1);

  long_desc = 
    BOLD+"  You find yourself standing in a room made of dark matter.  The walls\n"+
    "glisten in the dim light.  A small blackish pool stands in the center\n"+
    "of the room."+NORM+"\n";

  items = ({
    "pool",
      "You concentrate on the pool and find that you may do any of the\n"+
      "following:\n"+
      "   renew_symbiote   -  Get a new symbiote object. Use this to update\n"+
      "                       or if you have lost your object.\n"+  
      "   news             -  Use this command to see any news on the guild.\n"+
      "   store_coins      -  Store coins in the pool of matter",
    "walls",
      "They are made of a rock hard glistening substance. You aren't sure\n"+
      "exactly what it is",
  });

  dest_dir = ({
    "/players/maledicta/castle/rooms/m3.c","out",
  });
}

short(){ return ""+BOLD+"Dark Matter"+NORM+""; }

init()
{
  ::init();
  add_action("renew_object", "renew_symbiote");
  /*
  add_action("news_stuff", "news");
  */
  add_action("challenge","challenge");
  add_action("open_challenge","open");
}

open_challenge(str)
{
  object ob;
  ob = present("new_venom_object", TP);

  if(!ob)
  {
    return 0;
  }
 
  if(!str)
  {
    write("Open what?\n");
    return 1; 
  }
  if(ob->query_recruit() > 1)
  {
    write("You have already recruited your limit.\n");
    return 1;
  }  
  if(str == "crack")
  {  
    if(allow_challenge)
    { 
      write("It is already open!\n"); 
      return 1; 
    } 
    write("You pry open the "+BOLD+"Dark Matter"+NORM+" wall...\n"+
          "A large crack forms allowing entrance for just one person.\n"+
          "Your chosen one may now 'challenge symbiote'.\n");
    write_file("/players/fred/log/opened", 
    TP->QRN+" opened on "+ctime(time())+".\n");
    say(TP->QN+" grips the "+BOLD+"Dark Matter"+NORM+" wall tightly and tears it open...\n");
    allow_challenge = 1;
    ob->add_recruit(1);
    sponsor = TP;
    call_out("blahblah", 60);
    return 1;
  }
  write("open what?\n");
  return 1;
}

blahblah()
{
  if(!allow_challenge) 
    return;
  else
  {
    allow_challenge = 0;
    tell_room(this_object(), "The walls breach closes...\n");
  }
}

challenge(str)
{
  object arena;
  object mob;
  string named;
  if(!allow_challenge) 
    return 0;
  if(!present("venom_object_chal", TP)) 
    return 0;
  if(TP->QL < 19 && TP->QEL < 8) return 0;
  if(!str)
  { 
    write("You must 'challenge symbiote'.\n"); 
    return 1; 
  }
  if(str != "symbiote")
  { 
    write("You must 'challenge symbiote'.\n"); 
    return 1; 
  }
  if(SYMB->query_changed())
  { 
    write("You cannot challenge your symbiote while changed!\n"); 
    return 1; 
  }
  write_file("/players/fred/log/challenged!",
  TP->QRN+" challenged symbiote on "+ctime(time())+".\n");
  named = SYMB->query_symbiote();

  mob = clone_object("/players/chip/venom2/OBJ/symbiote_mob.c");
  mob->set_symb_name(named);
  mob->set_challenger(TP);
  mob->set_sponsor(sponsor);
  mob->set_saved_money(SYMB->query_stored_coins());

  arena = clone_object("/players/chip/venom2/OBJ/challenge_room.c");
  arena->set_who(TP);
 
  move_object(TP, arena);
  move_object(mob, arena);
  tell_object(TP, 
    "\n\n\n"+HIR+"As you are pulled into the pool of Dark Matter, you feel as though you are\n"+
    "torn in half!"+NORM+"\n\n\n"); 
  TP->hit_player(100 + random(50)); 
  
  command("look", TP);
  
  tell_object(TP,
   HIR+"Your symbiote is pulled from your body and forms up before you..."+NORM+"\n\n");
  tell_object(TP,
   BOLD+CAP(named)+" hisses: Traitor! I will destroy you!"+NORM+"\n");
  
  TP->set_guild_name(0);
  destruct(SYMB);
  TP->set_guild_file(0);
  allow_challenge = 0;
  remove_call_out("blahblah");
  return 1;
}

renew_object(str)
{
  if(TP->query_guild_name() != "symbiote") 
    return 0;
  if(!present("venom_object", TP))
  {
    move_object(clone_object("/players/fred/closed/venom/venom.c"), TP);
    write("Your lost object has been restored...\n");
    return 1;
  }
  else
  {
    if(SYMB->query_venomed())
    {
      write("You must return to normal shape first!\n");
      return 1;
    }
  command("save", TP);
  call_other(TP, "stop_wearing", SYMB, "mine", 1);
  destruct(SYMB);
  move_object(clone_object("/players/fred/closed/venom/venom.c"), TP);
  write("Object updated...\n");
  return 1;
  }
  return 1;
}

realm() { return "NT"; }

news_stuff()
{
  if(TP->query_guild_name() != "symbiote") 
    return 0;
  cat("/players/fred/closed/venom/news");
  return 1;
}

no_hunter(){ return 1; }
