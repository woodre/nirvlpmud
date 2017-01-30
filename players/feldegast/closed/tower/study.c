#include "std.h"
#include "/players/feldegast/closed/ansi.h"
#define NAME "feldegast"
 int shield;
reset(arg) {
  if(file_size("/players/feldegast/log/messages.log")>0 && !present("mail",this_object()))
    move_object(clone_object("/players/feldegast/closed/tower/mail"),this_object());
}
init() {
  add_action("west","west");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("church"); add_verb("church");
  add_action("post"); add_verb("post");
  add_action("portal"); add_verb("portal");
  add_action("inner"); add_verb("inner");
  add_action("assembly"); add_verb("assembly");
#else
  add_action("church", "church");
  add_action("post", "post");
  add_action("portal", "portal");
  add_action("inner", "inner");
  add_action("assembly", "assembly");
#endif
  add_action("arena","arena");
  add_action("shields","shields");
  add_action("escort","escort");
  add_action("wizzes","wizzes");
  set_light( 1);
  if(this_player()->query_real_name() != NAME && shield == 1) {
    write("You feel an electric shock and see a flash of white light as\n");
    write("you rebound off of the shield.\n");
    this_player()->move_player("off the shields#room/church");
  }
}
short() {
  return "A simple study";
}
long() {
  write(
    "This is the study of the wizard Feldegast.  It is covered wall to wall\n"+
    "in mahogany bookshelves full of assorted tomes and grimoires.  A large\n"+
    "desk, covered with old parchments and unread mail lies against one wall.\n"+
    "A couple of old couches face each other in the center of the room for\n"+
    "casual conversation.\n"+
    "    There is one obvious exit: west\n"
  );
}
shields() {
  if(this_player()->query_real_name()!="feldegast")
    return 0;
  if(shield) {
    write("You deactivate the shields.\n");
    shield=0;
    return 1;
  }
  else {
    write("You activate the shields.\n");
    shield=1;
    return 1;
  }
}
escort(str)  {
  object person;
  if(!str)  {
    write("You must specifiy a person to escort.\n");
    return 1;
  }
  person = find_player(str);
  if (!person)
    person = find_living(str);
  if (!person)  {
    write(str + " is not on right now.\n");
    return 1;
  }
  tell_room(environment(person), 
"A giant eagle swoops down and snatches "+capitalize(str)+" from the ground.\n"
  );
  transfer(person,this_object());
  tell_object(person,"You have been taken to the Feldegast's tower.\n");
  tell_room(this_object(),
  "A giant eagle flies in and deposits "+capitalize(str)+" on the floor, then glides back out.\n"
  );
  return 1;
}
wizzes() {
  object list;
  int i, level, invis;
  string name,ed;
  list = users();
  write("Name"+"\t\t"+"Level"+"\t"+"Invis"+"\t"+"Edit\n");
  write("====================================================\n");
  for(i=0; i <sizeof(list); i++)     {
    name = list[i]->query_name()+"          ";
    level = list[i]->query_level();
    invis = list[i]->query_invis();
    if(invis>999) {invis = 999;}
    ed = " ";
    if (in_editor(list[i])){
      ed= "Ed";
    }
    if (level > 19)   {
      write (name[0..11]+"\t"+level+"\t"+invis+"\t"+ed+"\n"); }
   }
   return 1;
}

/* Exits */
  church() {
    this_player()->move_player("church#room/church");
    return 1;
  }
  inner() {
    call_other(this_player(), "move_player", "inner#room/adv_inner.c");
    return 1;
  }
  post() {
    this_player()->move_player("post#room/post");
    return 1;
  }
  portal() {
    this_player()->move_player("portal#players/saber/ryllian/portal");
    return 1;
  }
  assembly() {
    if (this_player()->query_real_name()=="feldegast") {
      this_player()->move_player("darkness#players/mythos/closed/guild/assembly");
      return 1;
    }
  }
  arena() {
    this_player()->move_player("arena#/players/feldegast/arena/rooms/foyer");
    return 1;
  }

west() {
  this_player()->move_player("west#players/feldegast/closed/tower/tower2");
  return 1;
}
