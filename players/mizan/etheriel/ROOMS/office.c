/* Single storable room idea courtesy of Ilse Rubin */
inherit "players/mizan/closed/RandomRoom.c";
#include "/players/mizan/closed/poly/definitions.h"
#define ITEMLIST "players/mizan/etheriel/ROOMS/OFFICE-ITEMLIST"

string items;
int pushed_tl;

object portrait;
object desk;
object gun_cabinet;


reset(arg) 
{
   ::reset(arg);
   if(arg) return;

   if(restore_object(ITEMLIST)) 
      tell_room(this_object(), "The ether-muck swishes and swirls around you.\n");

   if(!desk) desk = move_object(clone_object("/players/mizan/etheriel/environs/mizan_desk.c"), this_object());
   if(!gun_cabinet) gun_cabinet = move_object(clone_object("/players/mizan/etheriel/environs/gun_cabinet.c"), this_object());
   if(!portrait) portrait = move_object(clone_object("/players/mizan/etheriel/environs/ingrid-portrait.c"), this_object());


   set_light(1);
}

init() 
{
   /* if not a guild member bounce them out. Wizzes are allowed however. */
   if(this_player()->query_guild_name() != "polymorph" &&
         this_player()->query_level() < 21 &&
         !this_player()->query_mizan_shell() &&
         this_player()->is_player()) 
      {
      write("You bounce off, and arrive elsewhere.\n");
      tell_room(this_object(), (this_player()->query_name()) + " is yanked out by an unseen force (Probably Spuck).\n");
      this_player()->move_player("out#players/mizan/etheriel/ROOMS/fall.c");
      return 1;
   }
   
   ::init();
   add_action("linna","linna");
   add_action("fatso","fatso");
   add_action("push","push");
   add_action("tug","tug");
}

linna() 
{
   this_player()->move_player("machine#players/mizan/etheriel/ROOMS/linna.c");
   return 1;
}

fatso() 
{
   this_player()->move_player("fatso#players/mizan/etheriel/ROOMS/spuck.c");
   return 1;
}

short() { return "Plane of Etheriel [obscured exits]"; }

long() 
{
   int i;
   string lngfrm;
   write("\n"+
      "\tThis region seems to be very orderly, a strange phenomenon within the\n"+
      "  ether-muck. Physics as you know them seem to be somewhat 'normal' around\n"+
      "  here and somewhat less inconsistent than in other spots. However it still\n"+
      "  takes an incredible amount of effort to get used to the fact that you\n"+
      "  are still drifting somewhat aimlessly.\n");
   lngfrm = "There are many obvious exits: linna, fatso,";

   while(i < sizeof(dest_dir)) 
   {
      lngfrm = lngfrm + " " + dest_dir[i];
      i += 1;
      if (i == sizeof(dest_dir) - 1)
         lngfrm = lngfrm + " and";
      else if (i < sizeof(dest_dir))
         lngfrm = lngfrm + ",";
   }
   lngfrm = lngfrm + ".";
   lngfrm = format(lngfrm, 70);
   write(lngfrm + "\n");
}

push() 
{
    object ob;
    string filname;
    string temp1;
    string filtemp;
    int tmpl;

    /* note that only wizards can use this tug and push. */
    if(this_player()->query_level() <= 20)
    {
        write("You fail.\n");
        return 1;
    }

    if(pushed_tl) 
    {
        write("You push helplessly at the ether-muck.\n");
        rsay((this_player()->query_name()) + " pushes helplessly at the ether-muck.\n");
        return 1;
    }

    write("You push against the ether-muck.\n");
    rsay((this_player()->query_name()) + " pushes against the ether-muck.\n");
    pushed_tl=1;
    items = "";
    ob = first_inventory(this_object());
    while(ob) 
    {
        object oc;
        oc=ob;
        ob=next_inventory(ob);
        
        if(!living(oc)) 
        {
            filtemp = object_name(oc);
            sscanf(filtemp, "%s#%s", filname, temp1);

            if(!oc->get() ||
            oc->query_save_flag() ||
            filname == "players/mythos/prac/bag")
            {
                rsay("Nothing happens to " + (oc->short()) + ".\n");
            } 
            else 
            {
                items = items + filname + "^!";
                tmpl ++;
                rsay((oc->short()) + " disappears into the ether-muck.\n");
                destruct(oc);
            }
        }

        if(tmpl > 50) break;
    }

    save_object(ITEMLIST);
    write("Ok.\n");
    return 1;
}

tug() 
{
    /* note that only wizards can use this tug and push. */
    if(this_player()->query_level() <= 20)
    {
        write("You fail.\n");
        return 1;
    }

    if(!pushed_tl) 
    {
        write("You tug helplessly at the ether-muck.\n");
        rsay((this_player()->query_name()) + " tugs helplessly at the ether-muck.\n");
        return 1;
    }
    
    if(restore_object(ITEMLIST)) 
    {
        write("You tug against the ether-muck.\n");
        rsay((this_player()->query_name()) + " tugs against the ether-muck.\n");
        load_thingies(items);
        pushed_tl=0;
        items="";
        return 1;
    }
    else 
    {
        write("Nothing happens.\n");
        rsay((this_player()->query_name()) + " tugs against the ether-muck but nothing happens.\n");
        return 1;
    }
}

load_thingies(str) 
{
    string file, argument, rest;
    object ob;
    while(str && str != "") 
    {
        if(sscanf(str, "%s^!%s", file, rest) != 2) 
        {
            write("Something wrong happens. Everything disappears with a soft 'poof'.\n");
            return;
        }
        str = rest;
        if(file) if(file != "0.c") 
        {
            ob = clone_object(file);
            rsay((ob->short()) + " fades into view.\n");
            move_object(ob, this_object());
        }
    }
}

rsay(str) 
{
    tell_room(this_object(), str);
    return 1;
}
