/* a little shorthand */
#define NAME (string)this_player()->query_real_name()

inherit "/room/room";

string *readers; /* make an array */

void reset(int arg)
{
    if(arg) return;
    set_light(1);
    short_desc = "A room";
    long_desc = "\
A room, with a door leading north.  And a sign on the door.\n";
    dest_dir = ({ "/players/whozit/whazit", "north" });
    readers = ({ }); /* initialize the array */
}

void init()
{
    ::init();
    add_action("north","north");
    add_action("read","read");
}

status north()
{
/* cat /doc/efun/member_array to see what the hell this is */
    if(member_array(NAME, readers) == -1)
      write("\
Something is holding you back.  Perhaps you should\n\
read that sign on the door.\n");
    else
    {
      write("\
You open the door and walk north.\n\n\
You carefully close the door behind you.\n");
      return 0;
    }
    return 1;
}

status read(string str)
{
    if(str == "the sign" || str == "sign" || str == "door"
       || str == "the door")
    {
      write("You read the sign.\n\n\
Blah blah blah!\n");
   /* add their name to the readers array, but
      first to check if it is in there */
      if(member_array(NAME, readers) == -1)
        readers += ({ NAME }); 
      return 1;
    }
}
