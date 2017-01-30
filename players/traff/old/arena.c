/*  ARENA.C - The arena in Delnoch is a place where players of any level
    may come and summon monsters to fight.  There is a limit of 20
    monsters which may be summoned per reset.  Monsters levels are set
    with a random factor to be in a range that is near the level of the
    player who rings the 'gong'.
    Changes as of 5-30-96:
    Color added, paths changed to fit new directory structure.
    1-29-00
    Added notes to help clarify monster selection.
*/
#include "/players/traff/closed/ansi.h"
inherit "room/room";
int GONG;

reset(arg) {

  if(!arg){
     GONG = 0;
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

/* This summons a gladiator if one is not present */
ring_gong()  {
  if(present("gladiator"))  {
  say(this_player()->query_name()+" tries to summon another fighter!\n");
  write("There is already a gladiator here.  You must kill him before\n"+
     "you summon another\n");
  return 1;  }

/* Counter, keeps track of number of times gong has been rung */
  GONG=(GONG+1);
/* Until gradated scale for monster level is added, can only
   clone 6 total gladiators/reset  -Snow */
  if(GONG>6)  {
  say("The gong rings, but nothing happens.\n");
  write("You can't summon a gladiator right now.  Try again later.\n");
/*
  GONG=(GONG-1);
*/
  return 1;  }

/* Check for level and summon the gladiators */
  if(this_player()->query_level()<6)  {
  say(this_player()->query_name()+" rings the gong.\n"+
  "BONGGGGGGGG!\nA Gladiator strides onto the field.\n");
  write("You ring the gong.\nBONGGGGGGG!\n"+
  "A Gladiator strides onto the field.\n");

/* If player is less than level 6 */
/* This summons monster with random level 1-5 */
  move_object(clone_object("/players/traff/delnoch/mon/glad1.c"),this_object());
  return 1;  }

  if(this_player()->query_level()<11)  {
  say(this_player()->query_name()+" rings the gong.\n"+
  "BONGGGGGGGG!\nA Gladiator strides onto the field.\n");
  write("You ring the gong.\nBONGGGGGGG!\n"+
  "A Gladiator strides onto the field.\n");

/* If player is less than level 11 */
/* This summons monster with random level 6-10 */
  move_object(clone_object("/players/traff/delnoch/mon/glad2.c"),this_object());
  return 1;  }

  if(this_player()->query_level()<16)  {
  say(this_player()->query_name()+" rings the gong.\n"+
  "BONGGGGGGGG!\nA Gladiator strides onto the field.\n");

  write("You ring the gong.\nBONGGGGGGG!\n"+
  "A Gladiator strides onto the field.\n");

/* If player is less than level 16 */
/* This summons monster with random level 11-15 */
  move_object(clone_object("/players/traff/delnoch/mon/glad3.c"),this_object());
  return 1;  }

  {
  say(this_player()->query_name()+" rings the gong.\n"+
  "BONGGGGGGGG!\nA Gladiator strides onto the field.\n");
  write("You ring the gong.\nBONGGGGGGG!\n"+
  "A Gladiator strides onto the field.\n");

/* This summons monster with random level 16-20 */
  move_object(clone_object("/players/traff/delnoch/mon/glad4.c"),this_object());
  return 1;  }

}

