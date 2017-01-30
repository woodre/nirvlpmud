/*  ARENA.C - The arena in Delnoch is a place where players of any level
    may come and summon monsters to fight.  There is a limit of 6
    monsters per player which may be summoned.  Monster levels are
    set with a random factor to be in a range that is near the level
    of the player who rings the 'gong'.  The monster files are:
    /players/traff/delnoch/mon/glad1.c - glad4.c
    As of 2-7-00 this file has been redone.  The use of an
    array keeps track of players who ring the gong.  Each player
    may ring the gong only once which will generate 6 monsters.
*/

#include "/players/traff/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

string *rang_gong;
int g;

reset(arg) {

  if(!arg){

    rang_gong = ({ }); /* allocate starting point */

    set_light(1);
    long_desc=(HIY+
"Since Casca has gained power, gladiator style fighting has become\n"+
"popular.  Many people fight because they can earn money no other way.\n"+
"You now stand in such an arena.  As you look around you notice that\n"+
"the stands are empty, and the arena seems to be deserted.  Off to\n"+
"one side you see a large brass gong.\n"+NORM);

    items=({
"ground","The ground here is covered with garss",
"stands","Row upon row of wooden bench seats for the spectators",
"gong","A large brass gong suspended from a wooden framework about 6 feet\n"+
"tall.  Hanging from the frame is large striker.  You wonder what\n"+
"would happen if you were to <ring> the <gong>",
 });

    dest_dir=({
    "/players/traff/delnoch/town/dmain.c","west",
      });
  }   }


init()  {
 ::init();
  add_action("ring_gong","ring");
}

short() { return HIR+"Delnoch Arena"+NORM;}

/* Check array to see if player has rung the gong. */
is_member(str, arr) {
  int i,so;
  for(i = 0, so = sizeof(arr); i < so; i++) {
    if(arr[i] == str) return 1;
  }
  return 0;
}

/* RING_GONG performs many checks.
   First the room is checked for the presence of gladiators.
   If any are present, more may NOT be summoned.  Next ring_gong
   is checked for empty str.
   Then a check is made to see if the player has rung the gong.
   If they have a message is displayed, if not the player is
   added to the array.  The next 4 checks then determine the
   players level and make a call out to create 6 of the
   correct monsters.
*/
ring_gong(str)  {
  if(present("gladiator"))  {
  say(this_player()->query_name()+" tries to summon more fighters!\n");
  write("There is already a gladiator here.  You must kill him before\n"+
     "you summon more!\n");
  return 1;  }

  if(!str) {
    write("You must ring something.\n");
    return 1; }

  if(is_member(tp,rang_gong)) {
    write("No more gladiators are willing to face you right now!\n");
    return 1; }

    write("You ring the gong.\n");
    say(call_other(this_player(), "query_name")+" rings the gong.\n");
    rang_gong += ({ tp });
    g = (random(100));

      if(this_player()->query_level()<6)  {
      call_out("make_glad1",1);
      return 1;  }

      if(this_player()->query_level()<11)  {
      call_out("make_glad2",1);
      return 1;  }

      if(this_player()->query_level()<16)  {
      call_out("make_glad3",1);
      return 1;  }

      if(this_player()->query_level()>15)  {
        if(g < 30)  {call_out("make_glad4",1); }
        if(g > 29 && g < 95)  { call_out("make_glad4",1); }
        if(g > 94)  { call_out("make_glad4",1); }
      return 1;  }

}

make_glad1()  {

  while(!present("gladiator 6"))  {
    say("\nA Gladiator strides onto the field.\n");
    write("\nA Gladiator strides onto the field.\n");
      move_object(clone_object("/players/traff/delnoch/mon/glad1.c"),this_object());
      }
return 1;
}

make_glad2()  {

  while(!present("gladiator 6"))  {
    say("\nA Gladiator strides onto the field.\n");
    write("\nA Gladiator strides onto the field.\n");
      move_object(clone_object("/players/traff/delnoch/mon/glad2.c"),this_object());
      }
return 1;
}

make_glad3()  {

  while(!present("gladiator 6"))  {
    say("\nA Gladiator strides onto the field.\n");
    write("\nA Gladiator strides onto the field.\n");
      move_object(clone_object("/players/traff/delnoch/mon/glad3.c"),this_object());
      }
return 1;
}

make_glad4()  {

  while(!present("gladiator 6"))  {
    say("\nA Gladiator strides onto the field.\n");
    write("\nA Gladiator strides onto the field.\n");
      move_object(clone_object("/players/traff/delnoch/mon/glad4.c"),this_object());
      }
return 1;
}

