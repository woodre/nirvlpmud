#include "std.h"

reset(arg){
   


      if(arg)
        return 0;
      set_light(1);
      
}
string invader;
string invited;
int alarm;
int secure;
int lock;

init(){
  if(call_other(this_player(),"query_real_name",0) == "hagbard") {
    add_action("invite");   add_verb("invite");
    add_action("force");    add_verb("invite!");
    add_action("alarm");   add_verb("alarm");
    add_action("secure"); add_verb("secure");
    add_action("stat");    add_verb("ck");
    add_action("gold");     add_verb("gold");
    }
   add_action("west");       add_verb("west");
   add_action("east");       add_verb("east");
   add_action("dest");       add_verb("dest");
   add_action("dest");       add_verb("destruct");
   invader = this_player()->query_real_name();
   if(this_player()->is_invis() > 0 && invader != "hagbard") {
     this_player()->force_us("vis");
   }
  if(secure == 0 && invader != invited && invader !="hagbard") {
     say(invader + " has tried to enter this room, but was deflected\n");
     write("You have entered uninvited.  Prepare to die!\n");
     write("You are sent to the void!!\n");
     if(find_player("hagbard"))
      tell_object(find_player("hagbard"), invader + " tried to enter your"
                  + " workroom but\n was deflected.\n");
     transfer(this_player(), "room/void");
     return 1;
   }
   if(secure == 1 && alarm == 0) {
     say(invader + " has entered your room\n");
     return 1;
   }
  return 1;
}





east(){
   
      call_other(this_player(),"move_player","east#room/crop");
      return 1;
}


west(){

      call_other(this_player(),"move_player","west#room/pub2");
      return 1;
}








gold(str) {
  object money;
  int n;
  
  sscanf(str,"%d",n);
  money=clone_object("obj/money");
  call_other(money,"set_money",n);
  move_object(money,this_object());
  return 1;
}
exit() {
  if(alarm == 0) {
    invader = this_player()->query_real_name();
    say(invader + " has exited the room.\n");
    return 1;
    }
  return 1;
}
  
invite(str) {
  if(!str) {
    invited == " ";
    return 1;
  }
  invited = str;
  write(invited + " is invited into the room\n");
  return 1;
}

force(str) {
  object person;
  
  if(!str) {
    write("You must specify someone\n");
    return 1;
  }
  person = find_player(str);
  if(!person)
    person = find_living(str);
  if(!person) {
    write(person + "is not playing!!!!!\n");
    return 1;
  }
  invited = str;
  tell_object(person,"You are carried to the Lief Erikson....\n");
  transfer(person,this_object());
  write(str + " is now on board the Lief Erikson.\n");
  return 1;
}

alarm() {
  if(alarm == 0) {
    alarm = 1;
    write("Alarm is off\n");
    return 1;
  }
  alarm = 0;
  write("alarm is on\n");
  return 1;
}

secure() {
  if(secure == 1) {
    secure = 0;
    write("secure is on\n");
    return 1;
  }
  secure = 1;
  write("secure is off\n");
  return 1;
}

dest(str) {
  object fool;
  string foolname;

  fool = this_player();
  foolname = fool->query_real_name();
  if(foolname == "hagbard")
    return 0;
  else
      return 1;
    return 1;
}

stat (str) {
  if(!str || str != "room")
    return 0;
  if(alarm == 0)
    write("alarm on\n");
  else 
    write("alarm off\n");
  if(secure == 0)
    write("secure on\n");
  else
    write("room open to anyone you idiot\n");
  if(invited == ""  || invited == 0)
    write("nobody is invited into this room\n");
  else
    write(invited + " is invited into the room\n");
  return 1;
}
short(){

    return "Hagbard's workroom.";
}
  

long(){

     write("You are in Hagbard's workroom.  It looks like the bridge of a\n");
     write("submarine.\n");
     write("There are exits to the east and west.\n");
}

