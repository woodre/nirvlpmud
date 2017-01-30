inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define TIME_STYLE BOLD+BLK+"["+NORM+ctime()[11..15]+BOLD+BLK+"]"+NORM
#define SAVE_PATH "/players/caelin/closed/CHATLOG"
#define SIZE 51
string *hist;
int next;

reset(arg){
  if(arg) return;

  hist = allocate(SIZE);
  next = 0;
  set_long("This is a small, white, octagonal shaped pill.\n");
  set_weight(1);
  set_value(0);
}

cae_check(object me)
{
  if(this_player() && this_player()->query_real_name() == "zeus"
    || this_player()->query_real_name() == "caelin"
    || this_player()->query_real_name() == "dustyrose"
    || this_player()->query_real_name() == "laetia")
    return 1;
  else
    return 0;
}

short(){
  if(!environment()) return 0;
  if(cae_check(this_player()))
    short_desc = "A small octagonal pill with a '"+HIW+"Z"+NORM+"' etched in it";
  else
    short_desc = 0;
  return short_desc;
}

id(str){ return str == "pill" || str == "zpill"; }
drop(){ return 1; }

init(){
  ::init();
  add_action("swallow_pill", "tell_zeus");
  add_action("pill_room", "tell_room");
}

add_history(string str){
  int a;
  hist[next] = TIME_STYLE+str;
  next++;
  if(next >= SIZE)
  {
    next = (SIZE-1);
    for(a = 0; a < (SIZE-1); a++)
      hist[a] = hist[a+1];
  }
}

print_history(object x){
  int a;
  if(!cae_check(x))
    return 0;
  if(!next && (file_size(SAVE_PATH) > 0))
    tail(SAVE_PATH);
  else if(!next)
    tell_object(x, "There is currently no history.\n");
  else {
    tell_object(x, "Pill history:\n");
    for(a = 0; a < next; a++)
      tell_object(x, (a+1)+". "+hist[a]);
    tell_object(x, "\nCurrent time is: "+TIME_STYLE+"\n\n");
  }
  return 1;
}

logit(object x){
  int a;
  tell_object(x, "\n"+next+" lines written to "+SAVE_PATH+"\n");
  if(file_size(SAVE_PATH) > 0)
    tell_object(x,  "Total size: "+file_size(SAVE_PATH)+"\n");
  for(a = 0; a < next; a++)
    write_file(SAVE_PATH, hist[a]);
  next = 0;
  return 1;
}

pill_room(string str){
  object z;
  string fstr, plus, x,y;
  if(!cae_check(this_player()))
    return 0;
  if(!str)
    return (print_history(this_player()));
  if(str == "logit")
    return (logit(this_player()));
  if(sscanf(str, "%s!?%s", x, y))  plus = "boggles";
  else if(sscanf(str, "%s?!%s", x, y))  plus = "boggles";
  else if(sscanf(str, "%s!%s", x, y)) plus = "exclaims";
  else if(sscanf(str, "%s?%s", x, y))  plus = "asks";
  else plus = "says";
  if(sscanf(str, ":%s", x))
  {
    fstr = HIR+capitalize((string)this_player()->query_real_name())+" "+x
      +NORM+"\n";
  }
  else
    fstr = HIR+capitalize((string)this_player()->query_real_name())+" "+
      plus+": "+NORM+str+"\n";
  tell_room(environment(this_player()), fstr);
  add_history(fstr);
  return 1;
}

swallow_pill(string str){
  object z;
  int idle;
  if(!cae_check(this_player()))
    return 0;
  if(!(z = find_player("zeus")))
    return(notify_fail("Zeus is not logged in.\n"), 0);
  if(!str)
  {
    idle = query_idle(z);
    write("\n"+z->query_pretitle()+" "+capitalize((string)z->query_real_name())+" "+
      z->query_title());
    write("\n currently logged in  ");
    if(idle >= 60)
      write(RED+"["+NORM+(idle / 60)+"m "+idle % 60+"s idle"+RED+"]\n"+NORM);
    else
      write(RED+"["+NORM+idle+"s idle"+RED+"]\n"+NORM);
    if((idle = z->query_invis()))
      write(" invis level "+idle+".\n");
    write(" location: ");
    if(environment(z) == environment(this_player()))
      write(HIY+"In Your Arms\n"+NORM);
    else
      write(environment(z)->short()+"\n");
    return 1;
  }
  else if(str == "history")
    return (print_history(this_player()));
  else if(str == "logit")
    return (logit(this_player()));
  tell_object(z, "Caelin tells you: "+str+"\n");
  write("You tell Zeus: "+str+"\n");
  add_history("You tell Zeus: "+str+"\n");

return 1;
}



