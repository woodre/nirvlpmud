inherit "obj/monster";
#include "/players/fred/ansi.h"
#include "/players/fred/closed/templar/defs.h"
#define ME "Jacoby"
#define to this_object()
string *questers, tl;
object scroll, gob, grail;
string p1,p2,p3,p4,p5,p6,p7,p8;
int ok;

reset (arg)
{
  ::reset(arg);
  if(!arg)
  { 

    set_name("jacoby");
    set_alias("templar_mob");
    set_short(ME+RED+" ["+NORM+BOLD+"Templar"+NORM+RED+"]"+NORM+BOLD+" Elite Guardsman"+NORM);
    set_long(ME+" is an older man.  Time has taken a toll on this once young, \n"+
            "powerful warrior.  He is wearing an older robe with a small satchel\n"+
            "dangling on his left side.\n");
    set_level(25);
    set_wc(30);
    set_ac(25);
    set_hp(500);
    set_al(1000);
    set_gender("male");
  }
}

init()
{
  ::init();
  add_action("deal2","RA8@ad&83");
  add_action("go","*8&#@132k");
  add_action("stop","$6JB97@3S");
}

void catch_tell(string str)
{
  string r1, r2;
  object you, it;
  if(!this_player()) return;
  if(sscanf(str, "%s arrives.%s\n", r1, r2))
  {
    you = this_player();
    if(you->is_player() && !you->query_attack())
    call_out("Cmd_greet",2,you);
  }
  if(sscanf(str, "%sbows%syou.", r1, r2))
  {
    you = this_player();
    if(you->is_player() && !you->query_attack())
      call_out("Cmd_bowback",2,you);
  }
  if(sscanf(str, "%sholy grail%s\n", r1, r2))
  {
    you = this_player();
    if(you->is_player() && !you->query_attack())
      call_out("Cmd_msg1", 2, you);
  }
  if(sscanf(str, "%sdone%s\n", r1, r2) ||
     sscanf(str, "%scomplete%s\n", r1, r2) ||
     sscanf(str, "%scompleted%s\n", r1, r2))
  {
    you = this_player();
    if(you->is_player() && !you->query_attack())
      call_out("Cmd_check", 2, you);
  }
  if(sscanf(str, "%s gives scroll to Jacoby.%s\n", r1, r2))
  {
    if(present("templar_quest_scroll", this_object()))
    {
      you = this_player();
      if(you->is_player() && !you->query_attack())
      it = present("templar_quest_scroll", this_object());
      move_object(it, you);
        call_out("give_back", 2, you);
    }
  }
  if(sscanf(str, "%s gives grail to Jacoby.%s\n", r1, r2))
  {
    if(present("templar_quest_grail", this_object()))
    {
      you = this_player();
      call_out("complete", 2, you);
      return;
    }
    you = this_player();
    call_out("huh", 2, you);
    return;
  }     
  if(sscanf(str, "%s ready to go%s\n", r1, r2))
  {
    you = this_player();
    if(you->is_player() && !you->query_attack())
      call_out("Cmd_follow", 2, you);
  }
}

give_back(object x)
{
  if(!x) return;
  TO(x,
    ME+" says, \"You should hold onto this "+x->QN+"\".\n"+
    ME+" hands the scroll back to you.\n");
  TR(ENV,
    ME+" hands the scroll back to "+x->QN+".\n", ({ x }));
}   

Cmd_greet(object x)
{
  if(!x) return;
  gob = present("KnightTemplar", x);
  if(DAEMON->query_questers(x->QRN) && !gob->query_ready())
  {
    switch(random(4))
    {
      case 0: tl = ME+" says, \"Welcome back "+x->QN+"\""; break;
      case 1: tl = ME+" says, \""+x->QN+", did you get the items I wanted?\""; break;
      case 2: tl = ME+" says, \"I'm glad you made it back "+x->QN+"\""; break;
      case 3: tl = ME+" says, \"Good you're back. Did you get my things?\""; break;
    }
    TO(x, tl+".\n");
    return 1;
  }
  else
  {  
    switch(random(5))
    {
      case 0: tl = ME+" smiles at you"; break;
      case 1: tl = ME+" says, \"Well, hello "+x->QN+"\""; break;
      case 2: tl = ME+" looks up at you"; break;
      case 3: tl = ME+" says, \"Greetings "+x->QN+"\""; break;
      case 4: tl = ME+" says, \""+x->QN+", it's good to see you\""; break;
    }
  }
  TO(x, tl+".\n");
  return 1;
}

Cmd_bowback(object x)
{
  if(!x) return;
  TR(ENV,
    ME+" crosses his arm and bows low to "+x->QN+".\n", ({ x }));   
  TO(x, ME+" crosses his arm and bows low to you.\n");
}
 
Cmd_msg1(object x)
{
  if(!x) return;
  gob = present("KnightTemplar", x);
  if(!gob) return;
  if(!gob->query_recruited()) return;
  if(DAEMON->query_questers(x->QRN))
  {
    TO(x,
      ME+" says, \"You know the deal "+x->QN+". I will tell you more\n"+
      "when you complete your task and bring me the items that I\n"+
      "have been searching for.\"\n");
    return 1;
  } 
  TO(x, 
    ME+" says, \"Ahhh, so you want to know about the Holy Grail do ya?\"\n");
  call_out("Cmd_msg2",5,x);
}

Cmd_msg2(object x)
{
  if(!x) return;
  TO(x,
    "\n"+ME+" glances around the room....\n\n"+
    "\"Usually I don't like to talk about it but I'd be willing to make\n"+
    "a deal with you.  I too have been searching for some lost items that\n"+
    "are scattered throughout the lands.  If you bring me the items I'm\n"+
    "looking for, I'll tell you everything I can remember about the Grail.\n\n");
  TO(x, "\"Do we have a deal?\" <Y or N> ");
  command("RA8@ad&83",x);
}

status deal2(string str)
{
  input_to("deal");
  return 1;
}

status deal(string str)
{
  object x;
  x = this_player();
  if(!x) return 1;
  if(str == "Yes" || str == "yes" || str == "Y" || str == "y")
  {
    command("*8&#@132k",x);
    return 1;
  }
  else
  {
    command("$6JB97@3S",x);
    return 1;
  }
}    
           
stop(object x)
{
  x = this_player();
  if(!x) return;
  TR(ENV,
    ME+" sighs, \"Very well then, perhaps another time\".\n");
}

go(object x)    
{
  x = this_player();
  if(!x) return;
  TO(this_player(),
    "\n"+ME+" says, \"Wonderful!\"\n"+
    "Here take this scroll.  Once you have found all the items on it\n"+
    "bring them back to me and I'll tell you what you want to know.\n"+
    "Go quickly now....\"\n");
  TO(this_player(),
    "\nOnce you have all the items give them to me and tell me when\n"+
    "you are done\n");
  scroll = clone_object("/players/fred/closed/templar/scroll.c");
  move_object(scroll, this_player());
  DAEMON->add_questers(this_player()->QRN);
  return 1;
}
      
Cmd_check(object x)
{
  if(!x) return 0;
  scroll = present("templar_quest_scroll",x);
  gob = present("KnightTemplar", x);
  if(!gob) return;
  if(!scroll)
  {
    TO(x,
      ME+" says, \"Where is your scroll at?\"\n");
    return 0; 
  } 

  p1 = DAEMON->get_item(scroll->query_a());
  p2 = DAEMON->get_item(scroll->query_b());
  p3 = DAEMON->get_item(scroll->query_c());
  p4 = DAEMON->get_item(scroll->query_d());
  p5 = DAEMON->get_item(scroll->query_e());
  p6 = DAEMON->get_item(scroll->query_f());
  p7 = DAEMON->get_item(scroll->query_g());
  p8 = DAEMON->get_item(scroll->query_h());

  if(present(p1, to) && present(p2, to) && present(p3, to) &&
     present(p4, to) && present(p5, to) && present(p6, to) &&
     present(p7, to) && present(p8, to))
  {
    TO(x,
      "\n"+ME+" says, \"Wonderful!\n"+
      "              I've been looking for these items for what seems\n"+
      "              like an eternity!  Since you have held up your end\n"+
      "              of our agreement so shall I.\n\n");
    gob->set_ready(1);
    gob->save_ob();
    destruct(present(p1, to));
    destruct(present(p2, to));
    destruct(present(p3, to));
    destruct(present(p4, to));
    destruct(present(p5, to));
    destruct(present(p6, to));
    destruct(present(p7, to));
    destruct(present(p8, to));
    
    call_out("step1",4,x);
  }
  else
  {
    TO(x, 
     "\n"+ME+" sighs...\n"+
     "I'm sorry but you haven't retrieved all the items I have\n"+
     "requested.  Please bring me the rest of the items.\n");
  }
  return 1;
}

step1(object x)
{
  if(!x) return;
  TO(x,
    ME+" says, \"Centuries ago the grail was stolen by a group of\n"+
    "              thieves as it was being transported to a new location...\"\n\n");
  call_out("step2", 6, x);
}

step2(object x)
{
  if(!x) return;
  TO(x,
    ME+" says, \"The thieves took refuge in a series of caves to hide\n"+
    "              from the King's men who were trying to track them down.\"\n\n");
  call_out("step3", 6, x);
}

step3(object x)
{
  if(!x) return;
  TO(x, 
    ME+" smiles...\"Little did they know that a powerful dragon had made\n"+
    "                 it's home within those very caves.  It wasn't long before\n"+
    "                 the dragon had killed the entire group.\"\n\n");
  call_out("step4", 8, x);
}

step4(object x)
{
  if(!x) return;
  TO(x,
    ME+" sighs...\"Alas the King's men were never able to retrieve the grail.\n"+
    "                It is believed that the Holy Grail is still in those very\n"+
    "                caves being guarded by the dragon.\"\n\n");
  call_out("step5", 6, x);
}

step5(object x)
{
  if(!x) return;
  TO(x,
    ME+" says, \"If you think you can defeat the dragon and return the grail\n"+
    "              to me it would be my honor to make you an Elite Knight.  When\n"+
    "              you are up to the challenge just let me know that you are 'ready\n"+
    "              to go' and I will take you to the entrance of the cave.\"\n");
}

Cmd_follow(object x)
{
  if(!x) return;
  gob = present("KnightTemplar", x);
  if(!gob) return; 
  if(!gob->query_ready()) return;
  TO(x,
    ME+" says, \"Very well then.  If you think you are ready I shall lead you to the cave.\"\n");
  call_out("fol1", 2, x);
}

fol1(object x)
{
  if(!x) return;
  tell_room(environment(x),
    ME+" smiles and quickly leaves the room.\n");
  TO(x,
    "You follow Jacoby.\n");
  move_object(to, "/players/fred/closed/templar/r1.c");
  x->move_player("following Jacoby#players/fred/closed/templar/r1.c");
  call_out("fol2", 4, x);
}

fol2(object x)
{
  if(!x) return;
  TO(x,
    "You follow Jacoby.\n");
  call_out("fol3", 4, x);
}

fol3(object x)
{
  if(!x) return;
  TO(x,
    "You follow Jacoby.\n");
  call_out("fol4", 4, x);
}

fol4(object x)
{
  if(!x) return;
  TO(x,
    "You follow Jacoby.\n");
  call_out("fol5", 4, x);
}

fol5(object x)
{
  if(!x) return;
  TO(x,
    "You follow Jacoby.\n\n");
  move_object(to, "/players/fred/closed/templar/r1.c");
  x->move_player("following Jacoby#players/fred/closed/templar/r2.c");
  command("look",x);
  call_out("leave", 2, x);
}

leave(object x)
{
  if(!x) return;
  TO(x,
    "\n"+ME+" says, \"Well here we are.  This is as far as I dare go.  Remember\n"+
    "                once you get the Grail come back to the Castle and give it\n"+
    "                it to me and I will make you an Elite Guardsman!  Good Luck.\"\n\n");
  call_out("leave2", 2, x);
}

leave2(object x)
{
  if(!x) return;
  TO(x,  
    "Jacoby turns and makes his way back towards the castle.\n");
  move_object(to, "/players/jaraxle/templar/rooms/quest.c");
  tell_room(environment(),
    "Jacoby enters the room.\n");
}

complete(object x)
{
  if(!x) return;
  gob = present("KnightTemplar", x);
  if(!gob->query_complete()) return;
  if(DAEMON->query_questers(x->QRN))
  {
    TO(x,
      ME+"'s eyes light up....\n");
    TO(x,
      ME+" exclaims, \"Excellent work "+x->query_name()+"!!!!\"\n\n");
    call_out("complete2", 2, x);
  }
}

complete2(object x)
{
  if(!x) return;
  gob = present("KnightTemplar", x);
  grail = present("grail", to);  
  TO(x,
    ME+" says, \"It is an honor to welcome you as a member of the the Elite Guardsman!!\"\n\n");
  gob->set_elite(1);
  gob->set_recruited(0);
  gob->set_ready(0);
  gob->set_complete(0);
  gob->save_ob();
  tell_room(environment(to),
    "\n"+ME+" runs off to put the grail in a safe place, and quickly returns.\n");
  command("tce has just become an Elite Guard!", x);
  destruct(grail);
}

huh(object x)
{
  if(!x) return;
  grail = present("grail", to);
  TO(x,
    ME+" says, \"This is not the grail I was looking for.\"\n");
  TO(x,
    ME+" hands the grail back to you.\n");
  move_object(grail, x);
}

  
    
  
