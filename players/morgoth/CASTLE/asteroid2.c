inherit "room/room";
int dig_count;
status stuff_is_got;
object ob1, ob2;
 
reset(arg)
{
    if (arg) return;
    set_light(1);
    short_desc = "An asteroid";
    long_desc = "The landscape grows steeper and forbidding.\n"+
                "To the east lies the twisted wreckage of a star-ship\n"+
                "Something shiny is partially buried in the black dust.\n";
    dig_count = 1;
    dest_dir = 
    ({
        "players/morgoth/CASTLE/Easteroid", "north",
        "players/morgoth/CASTLE/asteroid3", "east"
    });
}

init()
{
    add_action("find_sword", "dig");
    ::init();
}

find_sword()
{
  if(!stuff_is_got)
  {
    if(dig_count < 8)
    {
      write("You dig with great effort but to no avail...\n");
      dig_count += 1;
      return 1;
    }
    if(dig_count == 8)
   {
    write ("You found a Klezmeer sword !!\n");
    ob1 = clone_object("players/morgoth/WEAPONS/klez_sword");
	move_object(ob1,this_player());
/*  quest change  4/10/97  Eurale
    ob2 = clone_object("players/morgoth/ARMOR/klez_armor");
    move_object(ob2, this_player());
*/
   dig_count = 1;
    stuff_is_got = 1;
    return 1;
   }
  }
}

realm(){return "NT";}

query_temp() { return 2; }
