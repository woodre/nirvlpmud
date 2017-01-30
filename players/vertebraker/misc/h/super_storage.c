#include "/players/vertebraker/ansi.h"

inherit "/players/vertebraker/closed/std/room";

mapping Users;

void
reset(status arg)
{
    if(arg) return;
    set_no_clean(1);
    Users = ([ ]);
    set_light(1);
    set_short("The Storage Area " + GRN + "[" + NORM + BOLD + 
      "Knights Templar" + NORM + GRN + "]" + NORM);
    set_long("\
     Iron boxes line the walls of this small, dim room.\n\
Hay has been spread all over the floor, and you spy the\n\
occasional horse dropping around you, even though this area\n\
is much cleaner and sanitary than the north end of the\n\
Stables.  A golden placard decorates the southern wall.\n");
    add_item(({ "iron boxes", "boxes" }), "\
Thick, heavy iron boxes with names of Knights inscribed\n\
upon them.  Perhaps one of these boxes belongs to you?");
    add_item("room", long_desc);
    add_item("hay", "\
Brown tufts of hay scattered out amongst the floor");
    add_item(({ "horse dropping", "dropping", "droppings" }), "\
You spy brown, gooey horse droppings amongst the hay on\n\
the ground");
    add_item("placard", "\n\
A golden placard that reads:\n\n\
\t" + HIY + "You may 'clear' any items you have in your box." + NORM + "\n\n");
    dest_dir = ({ "/players/vertebraker/misc/s2", "north" });
}

void
init()
{
    ::init();
    add_action("cmdClear", "clear");
this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

void
add_locker(string n, object boo)
{
    if(!Users[n]) Users[n] = ({ });
    Users[n] += ({ boo });
}

status
cmdClear(string arg)
{
    int s, flag, snoog;
    string a, sh;
    object b;

    if(arg && arg != "items" && arg != "box")
    {
      notify_fail("You may 'clear items'.\n");
      return 0;
    }
    
    a = (string)this_player()->query_real_name();

    if(!Users[a])
      Users[a] = ({ });

    if(!(s = sizeof(Users[a])))
    {
      snoog = 1;
      write("There isn't anything for you to take from your box.\n");
    }

    else
      while(s --)
      {
        if(objectp(b = Users[a][s]) && (sh = (string)b->short()))
        {
          if(transfer(b, this_player()) == 0)
          {
            flag = 1;
            Users[a][s] = 0;
            write("You take " + sh + ".\n");
          }
          else
            Users[a][s] = 0;
        }
        else
          Users[a][s] = 0;
      }
        

    if(!snoog && !flag) write("\
There isn't anything for you to take from your box.\n");
    return 1;
}
