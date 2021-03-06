#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

string invader;
string invited;
int alarm;
int secure;
int lock;

extra_init(){
  if(call_other(this_player(),"query_real_name",0) == "sandman")  {
    add_action("invite");    add_verb("invite");
    add_action("force");       add_verb("invite!");
    add_action("alarm");     add_verb("alarm");
    add_action("secure");      add_verb("secure");
    add_action("stat");        add_verb("ck");
    add_action("gold","gold");
    add_action("dest");        add_verb("dest");
  }
invader = this_player()->query_real_name();
if (this_player()->is_invis() > 0 && invader !="sandman")  {
   this_player()->force_us("vis");
  }
if (secure == 0 && invader !=invited && invader !="sandman")  {
   say(invader + " has tried to enter this room, but was deflected\n");
   write("You have tried to go where you were not invited!\n");
   write("You are in the void..........\n");
   transfer(this_player(),  "room/void");
   return 1;
   }
   if(secure == 1 && alarm == 0)  {
     say(invader + " has entered this room\n");
     return 1;
   }
   return 1;
}
dest()  {
   if(call_other(this_player(),"query_real_name",0) !="sandman")  {
     return 1;  }
   return 0;  }

gold(str)  {
  object money;
  int n;

  sscanf(str,"%d",n);
  money=clone_object("obj/money");
  call_other(money,"set_money",n);
  move_object(money,this_object());
  return 1;

}
is_castle() {
return 1;
}
exit() {
  if(alarm == 0)  {
  invader = this_player()->query_real_name();
  say(invader + " has exited this room\n");
  return 1;
  }
  return 1;
}

invite(str)  {
  if(!str)  {
  invited = "";
  return 1;
  }
  invited = str;
  write(invited + " is invited into the room\n");
  return 1;
}

force(str)  {
  object person;

  if(!str)  {
    write("you must specifiy a person to summon\n");
    return 1;
  }
  person = find_player(str);
  if (!person)
    person = find_living(str);
  if (!person)  {
    write(str + " is not playing now.\n");
    return 1;
  }
  invited =str;
  tell_object(person,"You are brought to Sandman's workroom...\n");
  transfer(person,this_object());
  write(str + " has arrived via your command\n");
  return 1;
}

alarm()  {
  if(alarm == 0)  {
    alarm = 1;
    write("Alarm off\n");
  return 1;
  }
  alarm = 0;
  write("Alarm on\n");
  return 1;
}

secure()  {
  if(secure == 1)  {
    secure = 0;
    write("Secure on\n");
    return 1;
  }
  secure = 1;
  write("Secure off\n");
  return 1;
}

stat(str)  {
  if(!str || str != "room")
    return 0;
  if(alarm == 0)
    write("Alarm on\n");
  else
    write("Alarm off\n");
  if(secure == 0)
    write("Room secured\n");
  else
    write("Room open\n");
  if(invited == "" || invited == 0)
    write("Nobody is invited into the room\n");
  else
    write(invited + " is invited into the room\n");
  return 1;
}

TWO_EXIT("room/church","church",
         "players/sandman/paladin/adv_guild","guild",
         "You are in the heart of the dreaming",
         "\n"
+ "This room is filled with swirling mist that constantly changes color.\n"
+ "In the center of the room stands a dark cloaked figure with a raven\n"
+ " on his shoulder. You feel like you must be dreaming.\n",1)
