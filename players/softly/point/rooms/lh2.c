#include "/players/softly/closed/ansi.h"
inherit "/players/softly/point/rooms/std_lh.c";

#define NAME (string)this_player()->query_real_name()

string *readers;

void reset(int arg)
{
    if(arg) return;
set_light(1);

short_desc = RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint " + HIY + "Light" + NORM + "house";
long_desc ="\
  The kitchen of the living quarters looks well lived\n"+
"in.  A large wooden table surrounded by four wooden\n"+
"chairs sits in the center.  White dishes painted with\n"+
"pictures of blue boats are visible in the cabinets.  A\n"+
"heavy closed door lies to the east.\n";

items = ({
  "table","A large hand made table of wide wooden planks\n"+
          "dominates the room",
  "chairs","Four simple painted wooden chairs are pushed\n"+
           "up to the table.  Two are blue and two are white",
  "dishes","Sturdy white ceramic dishes have blue boats\n"+
           "painted in the center",
  "cabinets","The white painted cabinets have glass panels\n"+
             "in the doors through which dishes may be seen",
  "door","The large heavy door has been reinforced many\n"+
         "times.  It seems designed to keep out something...",  
  "sign",
"A large sign is affixed to the door.\n"+ HIR +
         " |----------------------------| \n"+
         " |'       D A N G E R        '| \n"+
         " |                            | \n"+
         " |         KEEP OUT!          | \n"+
         " |                            | \n"+
         " |,     This means you       ,| \n"+
         " |----------------------------| " + NORM +
"",
  });

dest_dir = ({
  "/players/softly/point/rooms/lh1.c","west",
  "/players/softly/point/rooms/lh5.c","east"
});
  readers = ({ });
}
void init()
{
    ::init();
    add_action("east","east");
    add_action("read","read");
}

status east()
{
    if(member_array(NAME, readers) == -1)
      write("\
Something is holding you back.  Perhaps you\n\
should read the sign on the door.\n");
    else
    {
      write("\
You open the door and walk east.\n\n\
You carefully close the door behind you.\n");

call_other("/players/softly/point/rooms/lh20.c","load_me");
    if(present("blackbeard", find_object("/players/softly/point/rooms/lh20"))) present("blackbeard", 
find_object("/players/softly/point/rooms/lh20"))->john_candy();
      return 0;
    }
    return 1;
}
status read(string str)
{
    if(str == "the sign" || str == "sign" || str == "door" || str == "the door")
    {
      write("You read the sign.\n\n"
+ HIR +
         "     |----------------------------| \n"+
         "     |'       D A N G E R        '| \n"+
         "     |                            | \n"+
         "     |         KEEP OUT!          | \n"+
         "     |                            | \n"+
         "     |,     This means you!      ,| \n"+
         "     |----------------------------| " + NORM +
"\n");

      if(member_array(NAME, readers) == -1)
        readers += ({ NAME }); 
      return 1;
    }
}
