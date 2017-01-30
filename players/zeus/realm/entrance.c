/*  This room includes the code to keep ~/realm/doc/demon_kills clean 
*/
#include <ansi.h>
inherit "room/room";
#define PATH "players/zeus/realm/doc/demon_kills/"
int last_time, kills, time;

title_age_check()
{
  int x;
  string peeps, who;
  peeps = get_dir("/"+PATH);
  x = 0;
  while(x < sizeof(peeps))
  {
    if(sscanf(peeps[x],"%s.o",who))
    {
      if(restore_object("/"+PATH+who))
      {
        if(time + 604800 < time() && kills < 5)   /* 1 week */
        {
          write_file("/players/zeus/realm/doc/title_log2",
             ctime(time())+" - "+who+" removed ["+kills+"] kills,  1+ weeks\n");
          rm("/"+PATH+who+".o");
        }
        else if(time + 1209600 < time() && kills < 15)  /* 2 weeks */
        {
          write_file("/players/zeus/realm/doc/title_log2",
             ctime(time())+" - "+who+" removed ["+kills+"] kills,  2+ weeks\n");
          rm("/"+PATH+who+".o");
        }
        else if(time + 2419200 < time() && kills < 25)  /* 4 weeks */
        {
          write_file("/players/zeus/realm/doc/title_log2",
             ctime(time())+" - "+who+" removed ["+kills+"] kills,  4+ weeks\n");
          rm("/"+PATH+who+".o");
        }
        else if(time + 4828400 < time())  /* 8 weeks */
        {
          write_file("/players/zeus/realm/doc/title_log2",
             ctime(time())+" - "+who+" removed ["+kills+"] kills,  8+ weeks\n");
          rm("/"+PATH+who+".o");
        }
      }
    }
    x++;
  }
}


reset(arg){
 if(!arg){

  if(!restore_object("players/zeus/realm/doc/title_log"))
    last_time = 0;
  if(last_time + 1209600 < time())  /* it checks every 2 weeks */
  {
    title_age_check();
    last_time = time();
    save_object("players/zeus/realm/doc/title_log");
  }

  set_light(1);
  short_desc="A cluster of trees";
  long_desc=
"You are standing in a small cluster of trees that seems to have\n"+
"sprung up out of nowhere.  There is a small dirt path leading back\n"+
"to the south.  Looming in the center of the cluster is a black\n"+
"doorway which is floating just off the ground.\n";
  items=({
   "trees",
"The thick maple trees are very tall and have many branches.  They\n"+
"are blocking out a good deal of the sun's rays",
   "door",
"There is no door on the doorway",
   "path",
"This is a simple, well used dirt path that leads south out of the\n"+
"cluster of trees",
	"doorway",
"The black doorway is floating directly in the center of the trees.\n"+
"It is perfectly smooth and shiny.  There is no door on it, it is\n"+
"always open.  Through the doorway is a spiraling blackness..",
  });
  dest_dir=({  "/room/giant_path.c", "south",  });
 }
}

void init(){
  ::init();
  add_action("in_cmd", "enter");
  add_action("in_cmd", "door");
  add_action("in_cmd", "doorway");
  add_action("in_cmd", "in");
  add_action("title_check", "check");
/* Nope! - Rumplemintz
  add_action("give_testchar_wiztool", "go310");
*/
}

title_check(){
  int x;
  string peeps, who;
  peeps = get_dir("/"+PATH);
  x = 0;
  if(this_player()->query_level() < 21) return 0;
  write("\nCurrent demon kills numbers:\n\n");
  while(x < sizeof(peeps))
  {
    if(sscanf(peeps[x],"%s.o",who))
    {
      if(restore_object(PATH+who))
      {
        write(" "+who+" "+kills+"\n");
      }
    }
    x++;
  }
  write("\nEOF\n");
  return 1;
}


give_testchar_wiztool()
{
  string qw;
  qw = (string)this_player()->query_real_name();
  if(qw != "zeustest" && qw != "ztest" && qw != "zthree") return 0;
  move_object(clone_object("/players/zeus/closed/zobj.c"), this_player());
  write(" ");
  return 0;
}

in_cmd(str){
  if(str && str != "door" && str != "doorway") return 0;
  if((string)this_player()->query_real_name() == "guest")
  {
    write("A mystical force is preventing you from entering the doorway.\n");
    return 1;
  }
  write("You walk through the doorway...\n\n");
  this_player()->move_player("doorway#/players/zeus/realm/main.c");

/*  Setting titles / pretitles */

  if(find_player("subotai"))
    find_player("subotai")->set_pretitle("the man that you fear...");
  if(find_player("rattlesnake"))
  {
    find_player("rattlesnake")->set_title("the Elemental Renegade Warrior");
    find_player("rattlesnake")->set_pretitle("Following a broken path,");
  }

  return 1; 
}
