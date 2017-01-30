#include "ansi.h"
inherit "room/room";
string location;

#define CASTLE "/room/farmroad3"
#define TEMPLE "/players/mosobp/areas/TEMPLE/rooms/temple0"
#define CPATH  "/players/mosobp/castle"
int busy;
int ppl;

reset(arg) {
  if(arg) return;
short_desc = HIK+"A Spaceship"+NORM;
long_desc = 
"Inside the ship you see a variety of buttons. The ship looks to be\n"+
"rather roomy, and it has padded walls for some reason. There \n"+
"is a closet on one side of the ship beside a sink.\n";
items = ({
"buttons","\
A variety of colored buttons; "+RED+"red"+NORM+" and "+GRN+"green"+NORM+"\n\
buttons catch your eye",
"red button", "A red button begging you to press it",
"green button", "A green button begging you to press it",
"button","Which button? [red or green ? ]",
"walls","The walls are padded in what looks to be a circle. Perhaps this \n"+
"was used as a training simulator at some point",
"closet","The closet appears to be empty",
"sink","The sink appears out of place with no water running through it",
});
set_light(1);
}
set_location(l) {
  location=l;
  dest_dir=({location,"out"});
}


init()
{
  if(this_player() && living(this_player())) ppl ++;
  ::init();
  add_action("cmd_push", "push");
}

cmd_push(str)
{
  if(!str)
  {
    notify_fail("Push what?\n");
    return 0;
  }
  else if(str == "button")
  {
    notify_fail("Be more specific.\n"+
                "Push the red or green button.\n");
    return 0;
  }
  else if(str == "red button" || str == "the red button")
  {
    if(location==TEMPLE)
    {
      write("Nothing happens.\n");
      return 1;
    }
    write("You push the "+RED+"red"+NORM+" button.\n");
    say(this_player()->query_name()+" pushes the "+RED
    +"red"+NORM+" button.\n");
    call_out("blast_off", 4, ({TEMPLE,this_player()}));
    return 1;
  }
  else if(str == "green button" || str == "the green button")
  {
    if(location==CASTLE)
    {
      write("Nothing happens.\n");
      return 1;
    }
    write("You push the "+GRN+"green"+NORM+" button.\n");
    say(this_player()->query_name()+" pushes the "+GRN
    +"green"+NORM+" button.\n");
    call_out("blast_off", 4, ({CASTLE,this_player()}));
    return 1;
  }
  else
  {
    notify_fail("You may only push the red or green button.\n");
    return 0;
  }
}

query_busy() { return busy; }

realm() { return "NT"; }

blast_off(data)
{
  if(!data[1] || !present(data[1], this_object()))
  {
    return;
  }
    
  tell_room(this_object(), "The Spaceship's engines "+HIR+"FIRE"+NORM+"!\n");
  tell_room(this_object(), "You feel everything moving...\n");
  tell_room(CASTLE, "The Spaceship takes off into the sky!\n");
/*
  move_object(find_object(CPATH), "/room/void");
*/
  
  busy=1;
  call_out("soar", 4, data);
}

land()
{
    tell_room(this_object(),
      "The Spaceship's engines go cold.\n");
    location=CASTLE;
    busy=0;
    tell_room(CASTLE,
      "The Spaceship lands.\n");
/*
    move_object(find_object(CPATH), CASTLE);
*/
}

soar(data)
{
  if(!data[1] || !present(data[1], this_object()))
  {
    land();
    return;
  }
  tell_room(this_object(), "The Spaceship soars over the heavens.\n");
  call_out("do_land", 4, data);
}

do_land(data)
{
  if(!data[1] || !present(data[1], this_object()))
  {
    land();
    return;
  }
  tell_room(this_object(), "The Spaceship lands with a rumble.\n");
  tell_object(data[1], "You set out into the unknown.\n");
  move_object(data[1], data[0]);
  command("look", data[1]);
  land();
}

exit(ob) {
  if(ob && living(ob)) ppl --;
  if(!ppl) call_out("blow_up", 1);
}

blow_up() {
  destruct(this_object());
}
