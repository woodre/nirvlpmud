/*
  This is a guide for newbies in the adventurer's school.  He will
  follow them if they so wish and explain various aspects of the game.
  He will leave when they "dismiss" him.  Softly/Nirvana - February, 2001 
*/

#include "/players/softly/misc/ansi.h"
#include "/players/softly/newbie/define.h"                
inherit "/players/softly/closed/std/monster";

object mynewbie, yadvent, club;
int follow;
mapping spoken;
string who, what, arg;

reset(arg) {
  spoken = (["ns1":0, "ns2":0, "ns2a":0, "ns2b":0, "ns3":0, "ns4":0, "ns4u":0, "ns5":0, "ons1":0, "ons2":0, "ons3":0, "ons4":0, "ons5":0, "ons6":0, "ons7":0, "ons8":0]);
  ::reset(arg);
  if (arg) return;

  set_name("drag'oman");
  set_alt_name("Newbie Guide");   
  set_alias("guide");
  set_long(
	   "The tall strong man wears a regal "+HIR+"red "+NORM+"and "+MAG+"purple "+NORM+"\n"+
	   "cloak, edged with "+YEL+"gold"+NORM+".  His face is shadowed by\n"+
	   "a generous hood.  He moves to greet you, glad to\n"+
	   "see a visitor.  If you wish him to leave say 'dismiss'.\n");
  set_short(HIR+"Drag'oman, A Guide"+NORM);
  set_type("spirit");
  set_level(10);
  set_wc(15);
  set_ac(7);
  set_hp(150);
  set_al(1000);
  set_aggressive(0);

  set_chat_chance(5);
  load_chat(HIR+"Drag'oman"+NORM+" says: I wish to help you young adventurer.\n");
  load_chat(HIR+"Drag'oman"+NORM+" says: We are glad you have come to our realm.\n");
  load_chat(HIR+"Drag'oman"+NORM+" says: If you wish my help, just ask.\n");
  load_chat(HIR+"Drag'oman"+NORM+" says: You need only say 'help' and I will help you.\n");
  load_chat(HIR+"Drag'oman"+NORM+" says: We are glad you have come to our realm.\n");
  load_chat(HIR+"Drag'oman"+NORM+" says: Welcome to Nirvana !\n");
  enable_commands();
  set_heart_beat(1);
}

void catch_tell(string str){
  if (sscanf(str, "%s says: %s\n", who, what) == 2) {
    what = lower_case(what);
    if (sscanf(what, "%shelp", who)){
      yadvent = this_player();
      call_out("intro",2,yadvent);
    }
    else if (sscanf(what, "%sdismiss", who)){
      yadvent = this_player();
      call_out("go_away",2,yadvent);
    }
  }
}

void intro(object asker)
{
  if(!asker) return;
  if(!spoken["ns1"]==0) return;
  follow = 1;
  tell_object(asker, "\n"+HIR+"Drag'oman"+NORM+" speaks:\n"+ 
	      " Nirvana is much like life.  You pass the days, gain experience, eat,\n"+
	      "drink, and sometimes have to fight or kill to survive.  In this school\n"+
	      "you may practice some of those skills.  I will do my best to help you.\n"+
	      "I hope you are patient and listen well.  Please take your time, wait,\n"+
	      "and be patient so you can read all that I have to say.\n\n"+
	      " First you must learn to monitor your health.  Type 'sc' and you will see\n"+
	      "important information about yourself.  Look at Hit Points ... it looks\n"+
	      "much like 48/50.  The first number is the number you actually have; the\n"+
	      "second the maximum you may have.  If your hit points go to zero you will\n"+
	      "die!!  To monitor this, type 'mon' and a monitor will be present when\n"+
	      "you are in battle.\n\n");

  call_out("cont1",26,yadvent);  
}

void cont1(object asker)
{
  if(!asker) return;
  tell_object(asker, "\n"+HIR+"Drag'oman"+NORM+" continues:\n"+ 
	      " Here you can expect to fight monsters, and often find treasure if you\n"+
	      "search their corpses.  Besting these mobs will give you experience (xp). \n"+
	      "As you get more experience, you will get stronger and gain skills.\n"+
	      "    \n\n"+
	      "\tDrag'oman gazes at you, taking your measure.\n"+
	      "   \n\n"+
	      " To successfully win against mobs, you must have a weapon.  I can give you\n"+
	      "a simple club, but keep looking for a better weapon.  You must 'wield' the\n"+
	      "weapon.  Typing 'i' or 'inventory' allows you to see what you carry, and\n"+
	      "if your weapon is wielded.\n\n"+
	      "  To get the club, simply type 'club'.\n\n");
  call_out("cont2",8,yadvent);
}

void cont2(object asker)
{
  if(!asker) return;
  tell_object(asker, "\n\tDrag'oman looks you over very carefully.\n"+
	      "\n"+HIR+"Drag'oman"+NORM+" says:\n"+
	      " It is time to go north and see what awaits you. I will\n"+
	      "follow you for a while and teach you.  If you wish me to\n"+
	      "leave, just 'dismiss' me.\n\n");
  spoken["ns1"]+= 1;
}

set_spoken(arg) { 
  spoken[arg] += 1; 
  return;
}


status query_spoken(string str) { 
  return spoken[str]; 
}
/* Get rid of the object on the newbie if I dest */
  remove_object() { 
    if(mynewbie && present("5n3b13", mynewbie)) destruct(present("5n3b13", mynewbie)); 
  }

void go_away(object asker)
{   
  tell_object(asker, "\n"+HIR+"Drag'oman"+NORM+" says:\n  I will be on my way then.  Good luck.\n");
  tell_room(environment(),"Drag'oman goes to wait for another adventurer.\n");
  remove_object();
  destruct(this_object());
}

/*****
      Who is my newbie?
*****/
set_mynewbie(str) { 
  mynewbie = find_player(str); 
}


/* Check for my newbie every heartbeat */

heart_beat(){ 
  ::heart_beat();

  /* Don't follow outside of school - Bye bye Drag'oman */
  {
    if(mynewbie && environment(mynewbie) && !environment(mynewbie)->adv_skool()){ 
      tell_room(environment(mynewbie),
		"Drag'oman says: I must find my student.\n");
      remove_object();
      destruct(this_object()); 
      return 1;
    }
    /* Is the newbie lost?  Find and go to him/her. */
    if(mynewbie && !present(mynewbie, environment(this_object()))) {
      tell_room(environment(this_object()),
		"The "+HIR+"Drag'oman"+NORM+" leaves seeking " +(string)mynewbie->query_name()+".\n");
      move_object(this_object(), environment(mynewbie));
      tell_room(environment(mynewbie),
		"A "+HIR+"Drag'oman"+NORM+" enters and stands by "+(string)mynewbie->query_name()+".\n");
      return 1; 
    }

    if(mynewbie && mynewbie->query_ghost()){  /* newbie died */
      tell_room(environment(mynewbie),
		"Drag'oman says: What a shame!  And at such an early age.\n"+
		"                Do be more careful next time!\n");
      remove_object();
      destruct(this_object()); 
      return 1; 
    }	
  }
}
          			
query_whoisnewbie() { return mynewbie; }




