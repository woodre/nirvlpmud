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
    add_action("jump");     add_verb("jump");
    add_action("jump");       add_verb("dive");
    add_action("force");     add_verb("invite!");
    add_action("alarm");     add_verb("alarm");
    add_action("secure");    add_verb("secure");
    add_action("stat");      add_verb("ck");
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
   if(str == "at pool") {
      write("You look at the pool.  The water is just luring you\n"+
        "to dive in...Perhaps you would like to 'dive into "+
        "pool'?\n");
  
      return 1;                                         
      }
   
}        
 
jump(str) {
        if(str == "into pool") {
        write("You jump into the pool.  SPLASHH!\n"+
        "The spring water splashes into your face as you\n"+
        "jump into the deep end.\n");
        say(this_player()->query_name() + " dives into the "+
        "pool.\n");
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
 
TWO_EXIT("room/church","up",
         "players/airwoman/closed/private","down",
         "Sand & Air's poolhouse",
         "\n"
+ "This is the 2nd floor of Sandair's penthouse.  A glimmering pool \n"
+ "shines crystal clear with clean water.  Looking down at the \n"
+ "pool, you can see through the thick clear glass floor \n"
+ "realizing that the bottom surface is also part of the 1st floor \n"
+ "ceiling.\n", 1)
 
 

