#define TOURNEYTIME "Saturday June 12, 1999 at 9pm EST"
#include "/players/feldegast/defines.h"
#include "/players/feldegast/std/colorize.h"

string *titles;
string *names;

inherit ROOM;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Arena Master's Office";
  long_desc=
"  A tall antique desk, made out of mahogany and stained to a dark\n\
finish, creaks in the center of room, vainly attempting to hold up\n\
a disproportionate mound of paperwork.  A bronze candelabra, the\n\
only source of light in this dim chamber stands next to it, attempting\n\
to put it out of its misery through a sporadic shower of sparks.\n";
  dest_dir=({
    "/players/feldegast/arena/rooms/foyer","southwest",
  });
  names=({});
  titles=({});
  move_object(clone_object("/players/feldegast/mon/pippin"),this_object());
  restore_object("players/feldegast/arena/rooms/titles");
}
save_me() {
  save_object("players/feldegast/arena/rooms/titles");
}

long(str) {
  if(this_player()->query_level() >=40)
    write(BOLD+"Wiz commands: "+NORM+"add_title, remove_title, list_titles\n");
  ::long(str);
}

init() {
  ::init();
  add_action("fix_title","fix");
  add_action("signup","signup");
  if(this_player()->query_level() >= 40) {
    add_action("add_title","add_title");
    add_action("list_titles","list_titles");
    add_action("remove_title","remove_title");
  }
}
fix_title(str) {
  string name;
  string title;
  notify_fail("Fix what?\n");

  if(!present("pippin",this_object())) return 0;

  if(!str || str!="title") return 0;
  name=this_player()->query_real_name();

  if(member_array(name,names)!=-1) {
    title=titles[member_array(name,names)];
    write("Pippin starts shifting stacks of parchment around, attempting\n"+
          "to find your name.  Suddenly, he looks up with a drunken grin\n"+
          "and says, \"Aiii!  Found it, mate!  According to this piece of\n"+
          "paper here, you be '"+name+" "+title+"'!\"\n");
    this_player()->set_title(title);
    return 1;
  }
  write("Pippin frowns thoughtfully at you and says, \"Y'know, I don't think\n"+
        "I've ever heard of you.  Perhaps you should leave now.\"\n");
  return 1;
}
add_title(str) {
  string name;
  string title;
  notify_fail("Usage: add_title <player> <title>\n");
  if(!str) return 0;
  if(sscanf(str,"%s %s",name,title)!=2) return 0;
  title=colorize(title);
  titles+=title;
  names+=name;
  write("You have made a new title for '"+name+"' of '"+title+"'.\n");
  write_file("/players/feldegast/log/titles.log",ctime(time())+"\t"+
             TPRN+"\t"+name+"\t"+title+"\n");
  save_me();
  return 1;
}

list_titles() {
  int i;
  write("Titles:\n");
  for(i=0; i < sizeof(names); i++)
    write(pad(names[i],20)+titles[i]+"\n");
  return 1;
}

remove_title(str) {
  notify_fail("Usage: remove_title <player>\n");
  if(!str) return 0;
  if(member_array(str,names)==-1) {
    write("That name is that on the list.\n");
    return 1;
  }
  titles-=titles[member_array(str,names)];
  names-=str;  
  write("Deleting "+str+"'s title.\n");
  write_file("/players/feldegast/log/titles.log",ctime(time())+"\t"+
             TPRN+"\t"+str+"\n");
  save_me();
  return 1;
}
int signup(string str)
{
  write("You are now signed up for the tournament taking place:\n"+TOURNEYTIME+"\n");
  write_file("/players/feldegast/log/signup.log",ctime(time())+" "+TPN+"\n");
  return 1;
}
