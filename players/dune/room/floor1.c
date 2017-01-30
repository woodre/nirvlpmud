inherit "room/room";
#include <ansi.h>


init()
{
  add_action("upsy","up");
  add_action("upsy","u");
  ::init();
}


reset(arg)
{

  if (!present("guard"))
  {
    move_object(clone_object("players/dune/monsters/guard.c"),
      this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Bottom Floor";
    long_desc=
HIY+
"                     _     \n"+
"                    |_|_   \n"+
"  E L E M E N T A L  |__|_ \n"+
"                     _|___|\n"+
"    T O W E R     __|_____|\n"+
"              ___|_______||\n"+
"           __|__________/ |\n"+
"        __|___________/   |\n"+
"     __|____________/     |\n"+
"____|____________|________|\n"+OFF+
"\n"+
"     You are on the bottom floor of the tower.\n"+
"Above you, the smooth round walls stretch into\n"+
"seemingly infinite heights. A large green\n"+
"staircase spirals upward. A sign lies engraved\n"+
"in the wall.\n";

    items=({
"sign","    The sign says: 'Elemental Tower'\n"+
       "The Tower is for players of all levels, but\n"+
       "middle to high-level characters will find the\n"+
       "Tower more rewarding. For an especially awesome\n"+
       "fight, seek Omni, Overlord of Elements.\n",
"walls",    "The walls are perfectly circular",
"staircase","The huge 20' wide green staircase leads upward",
"floor",    "The floor is of pale green stone",
 });

    dest_dir=({
"players/dune/closed/castle/rooms/hill10.c","out",
"players/dune/room/floor2.c","up",
    });
  }
}


upsy()
{
  if (present("guard"))
  {
    write("The guard blocks your way!\n");
    return 1;
  }
  call_other(this_player(),"move_player",
    "up#players/dune/room/floor2.c");
  return 1;
}

realm() { return "NT"; }
