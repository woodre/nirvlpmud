#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
string invader;
string invited;
int alarm;
int secure;
int lock;
 
extra_init(){
if(this_player()->query_real_name() == "sandman" || this_player()->query_real_name() == "airwoman") { 
    add_action("invite");    add_verb("invite");
    add_action("look");      add_verb("look");
    add_action("look");      add_verb("l"); 
    add_action("climb");     add_verb("climb");
    add_action("lay");       add_verb("lay");
    add_action("force");     add_verb("invite!");
    add_action("alarm");     add_verb("alarm");
    add_action("secure");    add_verb("secure");
    add_action("stat");      add_verb("ck");
    add_action("gold","gold");
    add_action("dest");      add_verb("dest");
  }
invader = this_player()->query_real_name();
if (this_player()->is_invis() > 0 && invader !="sandman" && invader != "airwoman")
 {
   this_player()->force_us("vis");
  }
if (secure == 0 && invader !=invited && invader !="sandman" && invader != "airwoman") { 
   say(invader + " smashes against the shields in a futile attempt "+ 
        "to come into the room\n");
   write("You have attempted to trespass!\n");
   write("You have sinned!  You are sent to church to repent your "+
         "sins.\n");
   transfer(this_player(),  "room/church");
   return 1;
   }
   if(secure == 1 && alarm == 0)  {
     say(invader + " has entered this exquisite penthouse.\n");
     return 1;
   }
   return 1;
}
dest()  {
   if(call_other(this_player(),"query_real_name",0) !="sandman")
{
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
exit() {
  if(alarm == 0)  {
  invader = this_player()->query_real_name();
  say(invader + " has exited this wonderful room.\n");
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
  write(invited + " is invited into this wonderful room.\n");
  return 1;
}
 
look(str) {
   if(str == "at bed" || str == "at waterbed") {
      write("A large comfy waterbed, maybe you should 'lay on waterbed'\n");      
      return 1;                                         
      }
   if(str == "at jacuzzi") {                            
        write("A champagne glass shaped jacuzzi.  It is "+
        "filled with soft fluffy bubbles.\n"+  
        "Steam emmanates from the jacuzzi fit for two only.\n"+
        "Perhaps you should 'climb into jacuzzi'?\n");  
        return 1;
        }
   
}        
 
climb(str) {
        if(str == "into jacuzzi") {
        write("The second you climb into the jacuzzi, a dazed\n"+
        "feeling comes to you.  All your muscles relax as if\n"+
	"you're floating on a cloud.\n");
        say(this_player()->query_real_name() + " climbs into the "+
        "jacuzzi to relax.\n");
        return 1; 
        }
 
}
lay(str) {
   if(str == "on bed" || str == "on waterbed") {
      write("You jump onto the waterbed and settle down on it to relax.\n");
      say(this_player()->query_real_name() + " lays on the waterbed.\n");
      return 1;
   }
}
force(str)  {
  object person;
  if(!str)  {
    write("You must specify a person to summon\n");
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
  tell_object(person,"You are brought to Sand & Air's penthouse...\n");
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
    write("No idiot is invited into the room\n");
  else
    write(invited + " is invited into the room\n");
  return 1;
}
 
TWO_EXIT("players/airwoman/closed/pool", "up",
         "room/well","down",
         "Sandman & Airwoman's Private Penthouse",
         "\n"
+ "This is a lavish penthouse apartment. The carpet is woven of silver.\n"
+ "On the walls are expensive paintings and the room is filled with elegent\n"
+ "furniture. The ceiling is made center of the room is a huge waterbed.\n"
+ "On one side of the room near the fireplace there is a champagne\n"
+ " glass-shaped jacuzzi.\n", 1)  
 
 
 
 
