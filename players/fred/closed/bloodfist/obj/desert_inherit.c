
/* desert inherit file */

inherit "/room/room";
#define DESERT "/players/fred/closed/bloodfist/r/desert.c"

void reset(mixed arg){
  if(arg) return;

  add_property("no_teleport");
  set_light(0);
}

long(str){
  int i;
  if ((set_light(0) <= 0) && !present("dark_sight_object", this_player()))
     return(notify_fail("It is dark.\n"), 0);
  if(!str)
    write(long_desc);
  if(!items)
	  return;
  i = 0;
  while(i < sizeof(items))
  {
    if (items[i] == str)
    {
      write(items[i+1] + ".\n");
      return;
    }
    i += 2;
  }
}

short(){ return "inculta creperum"; }

void init(){
  ::init();
  add_action("desert_move", "leave");
}

status desert_move()
{
  return ((int)DESERT->move(this_player(),query_verb()));
}
