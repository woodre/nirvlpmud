#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "obj/treasure";
int size;
 
reset(arg) {
  if(!arg) {
    size = 1;
    call_out("go_away",10+random(30));
  }
}

id(str){ return str == "pool" || str == "blood" || str == "blood_pool"; }


go_away()
{
  if(!EN) return;
  if(size > 1)
  {
    tell_room(environment(this_object()),
    BOLD+BLK+"\nSome of the blood is slowly absorbed into the ground.\n"+NORM);
    size -= 1;
    call_out("go_away", 10+random(30));
  }
  if(size < 2)
  {
    tell_room(environment(this_object()),
    BOLD+BLK+"\nThe last few drops of blood are slowly absorbed into the ground.\n"+NORM);
    bye();
  }
}

drop()  { return 1; } 
get()   { return 0; } 

bye()
{
  destruct(TO);
}


short()
{
  if(size > 4) return BOLD+RED+"A massive pool of blood"+NORM;
  if(size > 3) return BOLD+RED+"A large pool of blood"+NORM;
  if(size > 2) return BOLD+RED+"A pool of blood"+NORM;
  if(size > 1) return BOLD+RED+"A small pool of blood"+NORM;
  if(size > 0) return BOLD+RED+"A few drops of blood"+NORM;
}

increase_size()
{
  size += 1;
}

long()
{
  if(size > 4) write("A massive pool of blood from a recent battle\n");
  if(size == 4) write("A large pool of blood from a recent battle\n");
  if(size == 3) write("A pool of blood from a recent battle\n");
  if(size == 2) write("A small pool of blood from a recent battle\n");
  if(size == 1) write("A few drops of blood from a recent battle\n");
}
