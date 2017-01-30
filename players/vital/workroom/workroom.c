#include <ansi.h>
#define TP this_player()
#define NAME "vital"
inherit "room/room";
int shield;

void configure_long(string str);

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  short_desc = HIR + "Tower" + NORM + " of " + HIW + "Work" + NORM;
  long_desc =
"  This is a dark room. You cannot see anything here.\n";
  set_light(1);
  no_exits = 1;
  items = 
  ({
  });
  dest_dir = 
  ({
  });
}

init()
{
  ::init();
  add_action("on"); add_verb("on");
  add_action("off"); add_verb("off");
  if(this_player()->query_real_name() == NAME)
    this_player()->set_home( file_name( this_object() ) );
  if(this_player()->query_real_name() != NAME && shield == 1)
  {
    write("This area has been quarantined. Do not enter.\n");
    this_player()->move_player("off the shields#room/church");
    return 1;
  }
  if (!find_player("vital"))
  {
    move_object(this_player(),"/room/void.c");
    write_file("logs/workroom.log",this_player()->query_real_name() + 
        " illegal access " + ctime(time()) + "\n");
    destruct(this_object());
  }
}

short() { return short_desc; }

static on()
{
  write("You "+BOLD+"activate"+NORM+" the shield.\n");
  shield = 1;
  return 1; 
}

static off()
{
  if(TP->query_real_name() != NAME)
  {
    write("You are not allowed to do that!!!!!!!\n");
    return 1;
  }
  write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
  shield = 0;
  return 1; 
}

void
configure_long(string str)
{
  if(!str) return;
  switch(str)
  {
    case "guild" :
      short_desc = HIR + "Guild" + HIW + "Dev" + NORM;
      break;
    case "news" :
      short_desc = HIR + "News" + HIW + "Room" + NORM;
      break;
    case "area" :
      short_desc = HIR + "Area" + HIW + "Dev" + NORM;
      break;
    case "lib" :
      short_desc = HIR + "Lib" + HIW + "Dev" + NORM;
      break;
    case "class" :
      short_desc = HIR + "Class" + HIW + "Room" + NORM;
      break;
    case "idle" :
      short_desc = HIR + "Idle" + HIW + "Work" + NORM;
      break;
    case "base" :
      short_desc = HIR + "Tower" + " of " + HIW + "Work" + NORM;
      break;
    default :
      short_desc = HIR + "Tower" + " of " + HIW + "Work" + NORM;
  }
  return;
}
