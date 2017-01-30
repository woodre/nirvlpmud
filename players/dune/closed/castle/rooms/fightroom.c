inherit "room/room";
#include "definitions.h"


init()
{
  add_action("portal","portal");
  ::init();
}


reset(arg)
{
  if (!present("demosater"))
  {
    move_object(clone_object(CASTLEMONSTER+"/devil_duke.c"), 
      this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc=("Chamber of the Sithi");
    long_desc=
"     You find yourself in a dark pyramidal room. Black obsidian\n"+
"surrounds you on all sides. Near one wall, the world of Lothlorien\n"+
"can be seen through a shimmering portal. The only exit is 'portal'.\n";

    dest_dir=({
    });

    items=({
"obsidian","     The black obsidian seems to drain light into it",
"portal",  "     Shimmering white halls seem to lie beyond the portal",
"walls",   "     The glass walls are unbreakable",
    });
  }
}


portal()
{
  if (present("demosater", TO))
  {
    write("Demosater blocks your way.\n");
    return 1;
  }

  if (present("dunequestorb", TP))
  {
    present("dunequestorb", TP)->second_half_of_quest_is_solved(7);
    if (present("dunequestorb", TP)->quest_number() == 14)
    {
      this_player()->set_quest("lost_cities");
      write("\n"+
"    C                 ..:::::::::8:::::::::..\n"+
"    O              .::::::db::::d8b::::::::::::.\n"+
"    N            .::::::::88:::d888b:::::d888::::.\n"+
"    G          .:::::::::d88b::88888:::d888P:::::::.\n"+
"    R         :::::::::::888888P???Y88888P:::d88:::::\n"+
"    A        :::::888ba::888P?::aaa::?Y88::d888P::::::\n"+
"    T       ::::::Y8888888P:aad88888baa:Y8888P:::::::::\n"+
"    U      .::::::::Y8888P:d88888888888b:Y8P:::aaaadP::.\n"+
"    L      :::::::::::Y8P:a8888888888888a:Y88888888P::::\n"+
"    A      ::::aaaaaaad88:888888888888888:888888P:::::::\n"+
"    T      ::::8888888888:?8888888888888?:d888P:::::::::\n"+
"    I      `:::????????Y8b:Y88888888888P:d88:::::::::::'\n"+
"    O       :::::::::::ad8b:??Y88888P??:d8888b:::::::::\n"+
"    N        :::::aa88888888ba;:???:;ad888::Y88b::::::\n"+
"    S         :::::::::?Y888888baaaad88888::::Y8b::::\n"+
"    !          `::::::::::d88P:88888P88888:::::::::'\n"+
"    !            `:::::::d8P:::8888P:::Y88:::::::'\n"+
"    !              `:::::P:::::888P:::::YP:::::'\n"+
"                      ``:::::::Y8P:::::::::''\n");

      write_file("/players/dune/log/QUEST", 
                 capitalize(this_player()->query_real_name())+
                 ".......level ("+this_player()->query_level()+")......."+
                 ctime()+"\n");
    }
  }

  say(TPN+" enters the portal.\n");
  write("You enter the portal and return to Lothlorien.\n");
  if (present("dunequestorb", TP)) destruct(present("dunequestorb",TP));
  move_object(TP, CASTLEROOM+"/end.c");
  return 1;
}
