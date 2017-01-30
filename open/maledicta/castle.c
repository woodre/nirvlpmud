#include "/players/vertebraker/ansi.h"

#define VID "/players/vertebraker/exp/vid"
#define DEST "room/south/sforst24"
#define MAGE "/players/vertebraker/misc/mage/mage"
#define TTT "/players/vertebraker/t/t"
#define ERUPT_MASTER "/players/vertebraker/obj/erupt_master"
#define VORTEX "/players/vertebraker/castle/new/bvortex"
#define MAL "/players/maledicta/path/rooms/r9"
#define LOGDIR "/players/vertebraker/log/"

status id(string str) 
{
    return (str == "path" || str == "sign" || str == "ground" || str == "trail");
}

string
short() 
{
    return "\
A dark path plunges west, into the forest.\n\
Nearby, a wooden sign sticks out of the ground.\n\
A trail leads north into the hills";
}

void
long(string str)
{
      if(str == "trail")
        write("\
A narrow trail that leads deep into the hills\n\
to the north. Far to the north you see large\n\
mountains...\n");
      else if(str == "path")
        write("\
A darkened path that seems to wrap to the west,\n\
plunging into the dark heart of the forest.  You\n\
may be able to continue on with it...\n");
      else if(str == "ground")
        write("\
The ground is littered with a line of dark brown soil,\n\
which continues on into the western heart of the forest.\n");
     
      else
        write("\
The sign reads:\n\n\
\tThe realms of the wizard Vertebraker lie west, deeper\n\
\tinto the forest.  Tread carefully.\n\n");
}

void
init() 
{
   add_action("west","west");
   add_action("cmd_read", "read");
   add_action("north","north");
}

void
reset(int arg)
{
   object pub;

   if(arg)
   {
      "/players/cosmo/hslist/svds_new"->update_alltime();
      return;
   }

   move_object(this_object(), DEST);

   /* jaraxle's volcano */
    call_out("volcano_erupt", (12000 + random(5000)));

   /* ~/misc/mage/ */
    if(!find_living("gilmour_the_seer"))
      move_object(clone_object(MAGE), DEST);

    pub = find_object("/room/pub2");
    if(!pub)
    {
      "/room/pub2"->load_me();
      pub = find_object("/room/pub2");
    }
    if(!present("tic-tac-toe", pub))
      move_object(clone_object(TTT), pub);
    pub = find_object("/players/fakir/woods/whroom");
    if(!pub)
    {
      "/players/fakir/woods/whroom"->load_me();
      pub = find_object("/players/fakir/woods/whroom");
    }
    pub->set_no_clean(1);
    if(!present("vidscreen", pub))
      move_object(clone_object(VID), pub);
}

status
is_castle()
{
    return 1;
}

status
west() 
{
    object t;

    if(t = this_player())
    {
      write("You plunge into the thick of the forest.\n");
      t->move_player("\
into the dark heart of the forests#" + VORTEX);
      write_file(LOGDIR + "ENTER", 
        HIC + "[" + ctime()[4..15] + "]" + NORM + "\
 " + capitalize((string)t->query_real_name()) + 
" [" + (int)t->query_level() + "+" + (int)t->query_extra_level() + "]\n");
      return 1;
    }
}

status
north() 
{
    object t;

    if(t = this_player())
    {
      write("You follow the trail north.\n");
      t->move_player("\
into the forest hills#" + MAL);
     return 1;
    }
}


void
volcano_erupt()
{
    object d;

    if(!(d = find_object(ERUPT_MASTER)))
    {
      ERUPT_MASTER->load_me();
      d = find_object(ERUPT_MASTER);
    }

    if(!d->query_erupting()) d->init_lava();

    call_out("volcano_erupt", (12000 + random(5000)));
}

status
cmd_read(string str)
{
    if(!str)
    {
      notify_fail("Read what?\n");
      return 0;
    }
    if(str == "sign" || str == "the sign" || str == "wooden sign")
    {
      long("sign");
      return 1;
    }

    return 0;
}
