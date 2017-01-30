/*

          The Castle of Vertebraker!

        [tm] 2001 All Rights Reserved.

*/
#include "ansi.h"
#include "closed/CastleDefs.h"
#include "closed/load_object.h"

#define CLOSED "/players/vertebraker/closed/"
#define NADSAT "/players/vertebraker/nadsat/"

status 
id(string str) 
{
    return (str == "path" || str == "sign" || str == "ground");
}

string
short() 
{
    return "\
A dark path plunges west, into the forest.\n\
Nearby, a wooden sign sticks out of the ground";
}

void
long(string str)
{
      if(str == "trail")
        write("\
A narrow trail that leads deep into the hills\n\
to the north. Far to the north you see large\n\
mountains...\n");
      if(str == "path")
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
   add_action("north","north");
   add_action("cmd_read", "read");
}

void
reset(int arg)
{
  object obj;
 
  if(arg) return;
  
  move_object(this_object(), DEST);
  
  call_other("/obj/attrib_mod","???");
  call_other("/players/vertebraker/prizes/slacker","???");
  "/room/south/sforst25"->yayyayayayyayaya();
    if(!present("can", find_object("/room/south/sforst25")))
    move_object(clone_object("/players/vertebraker/obj/can"), 
    find_object("/room/south/sforst25"));
    if(environment() && !present("mudsex_sign", environment()))
      move_object(clone_object("/players/vertebraker/obj/mudsex_sign"),
      environment());
    
/*
     call_other("/players/vertebraker/obj/vote_reminder","???");
*/
     call_other("/players/vertebraker/guilds/samurai/obj/mark","???");
       call_other("/players/mokri/clans/object","???");
     call_other("/players/vertebraker/prizes/autoloader","???");
     call_other("/players/vertebraker/obj/scavenger", "???");
    
     "/players/vertebraker/misc/newbie_helpers/noob"->whoa();
   
     "/room/mine/tunnel13"->load_me();
    if(!present("cyberjesus", find_object("/room/mine/tunnel13"))){
      move_object(clone_object("/players/vertebraker/misc/cj/cyberJesus"), 
      "/room/mine/tunnel13"); }
    "/room/narr_alley"->load();
    
    if(!present("shop",find_object("/room/narr_alley")))
      move_object(clone_object(
     "/players/vertebraker/misc/holiday/h/OBJ/shop"), "room/narr_alley");
    
/* heh...
     "/players/x/closed/guest"->load();
*/
    
#ifndef __LDMUD__ /* Rumplemintz */
    if(!find_living("gilmour_the_seer"))
#else
    if (!find_object("gilmour_the_seer"))
#endif
    {
      DEST->set_no_clean(1);
      move_object(clone_object(MAGE), DEST);
    }

    if(arg) return;
    
    destruct(clone_object("/players/sado/saber_flu"));
    if((obj = loadObject("/room/pub2")) && 
       !present("tic-tac-toe", obj))
      move_object(clone_object(TTT), obj);

    if((obj = loadObject("/players/fakir/woods/whroom")) &&
       !present("vidscreen", obj))
    {
      obj->set_no_clean(1);
      move_object(clone_object(VID), obj);
    }

    loadObject("/players/vertebraker/closed/shardak/mark");
    loadObject("/players/vertebraker/closed/shardak/obj/allymark");
    loadObject("/players/vertebraker/closed/shardak/room/formation");

    "/players/vertebraker/closed/shardak/obj/blast_loader"->load_holy_blasts();
   "/players/vertebraker/closed/shardak/daemons/actions"->load_it();
    call_out("er_bleh", 10);
    loadObject("/players/boltar/templar/vtool");
    loadObject("/players/dune/closed/guild/implants");
#ifndef __LDMUD__ /* Rumplemintz */
      /* LD complaining big time about missing return values and using
         strong_types with not function casting */
    /*
    loadObject("/players/vertebraker/guilds/meijin/gob");
    */
#endif





}

status
is_castle()
{
    return 1;
}

status
west() 
{
    string out;
    object t;

    if(t = this_player())
    {
      write("You plunge into the thick of the forest.\n");
      t->move_player("\
into the dark heart of the forests#" + VORTEX);
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

void
er_bleh()
{
    "/players/vertebraker/closed/shardak/daemons/shardak"->demand_stuff();
}

