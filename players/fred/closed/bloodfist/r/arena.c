inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch, i, j, size, rank, x;
object *arena, master, in_use, here, obit, gob;
string trial_name;
#include "/players/fred/closed/bloodfist/r/torches.h"
#define WAIT_LENGTH 60

reset(arg){

  arena = ({ 
    "players/fred/closed/bloodfist/r/arena_room1",
    "players/fred/closed/bloodfist/r/arena_room2",
    "players/fred/closed/bloodfist/r/arena_room3",
    "players/fred/closed/bloodfist/r/arena_room4", });

  if(!present("atheos"))
  {
    master = clone_object("/players/fred/closed/bloodfist/NPC/beastmaster.c");
    move_object(master, this_object());
  }
  if(!present("arena_obit"))
  {
    obit = clone_object(DIR+"obj/arena_obit.c");
    move_object(obit, this_object());
  }

  if (arg) return;

  torch = 1;
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "doors",
      "The thick metal doors of the arena are intricately designed,\n"+
      "however many of the details of them are filled with sand and\n"+
      "difficult to make out",
    "walls",
      "The stone walls of the encampment are visible beyond the arena\n"+
      "to the north.  They protrude from the ground at a sharp angle",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground is destolate, cracked and broken",
    "sand",
      "The ground is caked with a layer of dry sand",
    "staircase",
      "The metal stairs are attached to the outer wall of the arena.  They\n"+
      "wrap up around the side leading to the stands above the arena",
  });

  dest_dir=({
    DIR + "r/armory.c",       "east",
    DIR + "r/well.c",         "south",
    DIR + "r/arena_stands.c", "up",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc = 
"  The darkness of the sky above is thick and consuming.  Ahead lie two\n"+
"large metal doors that provide the only entrance into the arena.  Two\n"+
"torches are mounted in the rock that protrudes from the ground forming\n"+
"the arena.  Each of the torches is lit, casting shadows down upon the\n"+
"desolate camp.  Beyond the arena to the north the stone walls of the\n"+
"encampment jut out of the ground parallel to the ground.  A metal\n"+
"staircase bends around the arena leading up to the stands.\n";
  else
    long_desc = 
"  The darkness of the sky above is thick and consuming.  Ahead lie two\n"+
"large metal doors that provide the only entrance into the arena.  Two\n"+
"torches are mounted in the rock that protrudes from the ground forming\n"+
"the arena.  The torches are unlit right now.  Beyond the arena to the\n"+
"north the stone walls of the encampment jut out of the ground parallel\n"+
"to the ground.  A metal staircase bends around the arena leading up to\n"+
"the stands.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("enter", "enter");
}

int clean_arena(){
  object *rinv;
  if(ARENA_DAEMON->occupants()) return 0;   /* player occupied */
  for(i = 0; i < 4; i++)
  {
    tell_room(arena[i], "A strong wind blows through the arena.\n");
    rinv = all_inventory(arena[i]);
    size = sizeof(rinv);
    if(size > 0)
    {
      for(j = 0; j < size; j++)
        move_object(rinv[j], "/room/void.c");
    }
  }
  return 1;  /* arena cleaned */
}

status enter(string what){
  gob = present("bloodfist_gob", this_player());
  rank = (int)gob->query_glevel();
  if(!gob->query_trial_to_do())
  {
    tell_room(this_object(),
      "Atheos says, \"You are not allowed to enter unless you are ready for a trial.\"\n");
    return 1;
  }
  if(what != "doors" && what != "arena") return 0;
  if(this_player()->query_ghost())
    return (notify_fail("You can not enter the arena as a ghost.\n"), 0);
  if(ARENA_DAEMON->occupants())
  {
    if(present(master, this_object()))
    {
      tell_room(this_object(), 
        "Atheos says, \"The arena is already in use, "+
        "you'll have to wait.\"\n");
      return 1;
    }
    else {
      notify_fail("The arena is already in use.\n");
      return 0;
    }
  }
  else if(in_use && in_use != this_player())
  {
    if(present(master, this_object()))
    {
      tell_room(this_object(), 
        "Atheos says, \"The arena is waiting to be used "+
        "by "+capitalize((string)in_use->query_real_name())+".\"\n");
      return 1;
    }
    else {
      notify_fail("The arena is waiting to be used by "+
        in_use->query_real_name()+".\n");
      return 0;
    }
  }
  else if(!in_use)
    ARENA_DAEMON->clean_arena();
  write("You push open the doors and enter the arena.\n");
  if(rank == 0)
  {
    CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+" has just entered the arena to "+
    "battle, Jetrho Hunter the Warrior, for guild level 1!\n"+NORM);
   this_player()->move_player("arena#"+DIR+"r/arena_room1.c");
  }
  else if(rank == 1)
  {
    CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+" has just entered the arena to "+
    "battle, A Giant Desert Fiend, for guild level 2\n"+NORM);
   this_player()->move_player("arena#"+DIR+"r/arena_room1.c");
  }
  else if(rank == 2)
  {
    CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+" has just entered the arena to "+
    "battle, Christian the Brute Lord Slayer, for guild level 3!\n"+NORM);
   this_player()->move_player("arena#"+DIR+"r/arena_room1.c");
  }
  else if(rank == 3)
  {
    CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+" has just entered the arena to "+
    "battle, Trugen the Desert Berzerker, for guild level 4!\n"+NORM);
   this_player()->move_player("arena#"+DIR+"r/arena_room1.c");
  }
  else if(rank == 4)
  {
    CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+" has just entered the arena to "+
    "battle, Atheos the Beastmaster, for guild level 5!\n"+NORM);
   this_player()->move_player("arena#"+DIR+"r/arena_room1.c");
  }
  else if(rank == 5)
  {
    CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+" has just entered the arena to "+
    "battle, Lord Bruetus Faust of the Bloodfist, for guild level 6!\n"+NORM);
   this_player()->move_player("arena#"+DIR+"r/arena_room1.c");
  }
  else if(rank == 6)
  {
    CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+" has just entered the arena to "+
    "battle, Haemon, for guild level 7!\n"+NORM);
   this_player()->move_player("arena#"+DIR+"r/arena_room1.c");
  }
  else
  {
    CHAN_DAEMON->hprint(BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+" has just entered the arena to "+
    "battle, Erilon the Elder, for guild level 8!\n"+NORM);
   this_player()->move_player("arena#"+DIR+"r/arena_room1.c");
  }
  return 1;
}

timer(object me)
{
  object env, gob;
  string g,h;
  if(in_use && me && find_player((string)me->query_real_name()))
  {
    env = environment(me);
    gob = present("bloodfist_gob", me);
    if(!env){ in_use = 0; return; }
    if(sscanf(env, "%s/fred/closed/bloodfist/r/arena_%s", g,h)) return; /*in*/
    if(!gob->query_trial_to_do()) return; /* already killed NPC and left it */
    if(present(me, here))
    {
      tell_room(here,
        "Atheos says, \"I'm going to make the arena "+
        "available to everyone again.\"\n");
    }
    else {
      tell_object(me, 
        "Atheos tells you, \"I'm going to make the arena "+
        "available to everyone again.\"\n");
    }
  }
  if(present(master, here))
  {
    tell_room(here,
        "Atheos says, \"The arena is available again.\"\n");
  }
  in_use = 0;
}

void ready(object me) /* called from beastmaster.c */
{
  in_use = me;
  here = this_object();
  call_out("timer", WAIT_LENGTH, me);
}

void reset_use(){  in_use = 0; } /* for if the player leaves the arena */

get_name(object me)
{ 
  gob = present("bloodfist_gob", me);
  x = gob->query_glevel();
  if(x == 0) return "Jetrho Hunter the Warrior"; 
  else if(x == 1) trial_name = "A Giant Desert Fiend";
  else if(x == 2) trial_name = "Christian the Brute Lord Slayer";
  else if(x == 3) trial_name = "Trugen the Desert Berzerker";
  else if(x == 4) trial_name = "Atheos the Beastmaster";
  else if(x == 5) trial_name = "Lord Bruetus Faust of the Bloodfist";
  else if(x == 6) trial_name = "Haemon";
  else trial_name = "Erilon the Elder";
}

