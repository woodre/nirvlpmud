#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(0);
  short_desc="The Great Hall";
  long_desc="    This is obviously a treasure room, otherwise, unadorned. \n";
  dest_dir =
  ({
    "/players/anshar/hall/room/hall10", "south",
  });
  if (!present("money"))
  {
    object money;
    money = clone_object("obj/money");
    move_object(money, "/players/anshar/hall/room/hall11");
    call_other(money, "set_money",(random(5000)+20000));
  }
}

realm() {return "NT"; }
