#include "/players/mizan/closed/poly/definitions.h"
#define ITEMLIST "players/mizan/etheriel/ROOMS/LINNA-STORAGELIST"

/* Single storable room idea courtesy of Ilse Rubin */

inherit "players/mizan/closed/RandomRoom.c";
#define TUG_R "players/mizan/closed/poly/tugDM.c"
#define MAX_ITEMS    8

string stuff;
string stuff_desc;
string stuff_pusher;

reset(arg) 
{
   ::reset(arg);
   if(arg) return;

   if(restore_object(ITEMLIST)) 
      tell_room(this_object(), "The ether-muck swishes and swirls around you.\n");

   if(!stuff || sizeof(stuff) != MAX_ITEMS)
      stuff = allocate(MAX_ITEMS);
      
   if(!stuff_desc || sizeof(stuff_desc) != MAX_ITEMS)
      stuff_desc = allocate(MAX_ITEMS);

   if(!stuff_pusher || sizeof(stuff_pusher) != MAX_ITEMS)
      stuff_pusher = allocate(MAX_ITEMS);

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
      this_player()->move_player("out#players/mizan/etheriel/ROOMS/red.c");
      return 1;
   }
   
   ::init();
   add_action("up","up");
   add_action("nuck","machine");
   add_action("office","office");
   add_action("adv","adv");
   add_action("fatso","fatso");
   add_action("push","push");
   add_action("tug","tug");
}

nuck() 
{
   this_player()->move_player("machine#players/mizan/etheriel/ROOMS/nuck.c");
   return 1;
}

fatso() 
{
   this_player()->move_player("fatso#players/mizan/etheriel/ROOMS/spuck.c");
   return 1;
}

up() 
{
   this_player()->move_player("up#room/wild1");
   return 1;
}

office() 
{
   this_player()->move_player("office#players/mizan/etheriel/ROOMS/office.c");
   return 1;
}

adv() 
{
   this_player()->move_player("adv#room/adv_guild");
   return 1;
}

push(str) 
{
   object ob, gob;
   string arg1;

   /* No guild object, no service */
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   
   if(this_player()->query_level() > 29)
   {
      write("Sorry, but wizards over L30 cannot use the tug-push.\n");
      write("It would display the short() of the object on weapons and armor\n");
      write("reflecting the armor or weapon classes to all players.\n");
      return 1;
   }

   if(str)
   {
      if(str == "history" || str == "activity") return tug_activity();
      else if(str == "tracking") return tug_tracking();
      else if(str == "list") return tug_list();
      else if(sscanf(str, "finger %s", arg1) == 1) return tug_finger(arg1);
      else if(str) return push_item(str);
      else return 0;
   }
   else
   {
      tell_room(this_object(), (this_player()->query_name()) + " didn't read the documentation and just typed 'push'.\n");
      write("Push usage has changed. Be sure to read 'info tug' for details.\n");
      return 1;
   }
}

push_item(str)
{
   object ob, gob;
   string ob_filename, ob_temp, ob_temp2;
   int i, spot, found_spot, type, value;

   found_spot = 0;

   /* No guild object, no service */
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;
   
   /* Obtain the object */
   ob = present(str, this_object());
   if(!ob)
   {
      write("There is no such item drifting about this area.\n");
      return 1;
   }

   /* Check that the object can be pushed. If living or not gettable, bounce out.  */
   if(living(ob) || !ob->get())
   {
      say(this_player()->query_name() + " tried but obviously failed to push in " + lower_case(ob->short()) + ".\n");
      write("You can't push that in, silly.\n");
      return 1;
   }
   
   /* These are things we do NOT want to save */
   if(ob->query_save_flag() || !ob->short()) 
   {
      say(this_player()->query_name() + " stares in bogglement at " + lower_case(ob->short()) + ".\n");
      write("This is a special item and cannot be saved.\n");
      return 1;
   }

   /* Now get the filename */
   ob_temp = object_name(ob);
   sscanf(ob_temp, "%s#%s", ob_filename, ob_temp2);
   
   /* Check that this isnt a certain type of object */
   if(!ob_filename || ob_filename == "obj/armor" || !ob->query_weight() ||
      ob_filename == "obj/weapon" || ob_filename == "obj/food" ||
      ob_filename == "players/mythos/prac/bag" || !ob->query_value() ||
      ob_filename == "obj/treasure" || ob_filename == "obj/money")
   {
      say(this_player()->query_name() + " tried but failed to push in " + lower_case(ob->short()) + ".\n");
      write("This object is either worthless or too generic to be saved.\n");
      return 1;
   }
   
   /* Cycle through the list of items to find an empty spot. If one is there
    * we take it. Sort of like parking a car. 
    */
   for(i = 0; i < sizeof(stuff); i ++)
   {
      if(!found_spot)
         if(stuff[i] == 0 || stuff[i] == "")
         {
            /* We found a spot */
            spot = i;
            found_spot = 1;
         }
   }
   
   /* No empty spot was found */
   if(!found_spot)
   {
      say(this_player()->query_name() + " tried but failed to push something into the ether-muck but it was full.\n");
      write("There were no empty spots in the ether-muck to store your item.\n");
      return 1;
   }

   /* CREDIT PLAYER - gather the value of the object */
   value = ob->query_value();
   if(value < 0) value = 0;
   if(value > 10000) value = 10000;
    
   /* CREDIT PLAYER -  Register the item as being saved to the poly */
   gob->add_linna_items_value_total(value);
   gob->add_linna_push_items();
    
   /* CREDIT PLAYER -  Now figure out if the item is a weapon or an armor, and credit accordingly */
   if(ob->is_weapon() && ob->weapon_class() > 0)
   {
      gob->add_linna_weapons_wc_total(ob->weapon_class());
      gob->add_linna_weapons_num_total();
   }
   else if(ob->is_armor())
   {
      if(ob->query_type() == "armor") type = 0;
      else if(ob->query_type() == "helmet") type = 1;
      else if(ob->query_type() == "boots") type = 2;
      else if(ob->query_type() == "ring") type = 3;
      else if(ob->query_type() == "amulet") type = 4;
      else if(ob->query_type() == "shield") type = 5;
      else type = 6; /* we just assume it is misc */

      gob->add_linna_armor_ac_total(ob->armor_class(), type);
      gob->add_linna_armor_num_total(type);
   }

   /* Tell the room and player what happened */
   write("You push against the the ether-muck.\n");
   say(ob->short() + " disappears into the ether-muck.\n");
   tell_room(this_object(), ob->short() + " is now snugly pushed into location [" + (spot + 1) + "].\n");
   
   /* Finally, save this object's filename and destroy the object itself. */
   log_file("mizan.tugactivity", "[" + ctime() + "] " + this_player()->query_name() + " pushed in " + lower_case(ob->short())+ ".\n");
   stuff[spot] = ob_filename;
   stuff_desc[spot] = ob->short();
   stuff_pusher[spot] = this_player()->query_name();
   save_object(ITEMLIST);
   destruct(ob);
   return 1;
}


tug(str) 
{
   string arg1;
   int arg2;
   
   if(this_player()->query_level() > 29)
   {
      write("Sorry, but wizards over L30 cannot use the tug-push.\n");
      write("It would display the short() of the object on weapons and armor\n");
      write("reflecting the armor or weapon classes to all players.\n");
      return 1;
   }

   if(str)
   {
      if(str == "history" || str == "activity") return tug_activity();
      else if(str == "tracking") return tug_tracking();
      else if(str == "list") return tug_list();
      else if(sscanf(str, "finger %s", arg1) == 1) return tug_finger(arg1);
      else if(sscanf(str, "%d", arg2) == 1) return tug_item(arg2);
      else return 0;
   }
   else
   {
      tell_room(this_object(), (this_player()->query_name()) + " didn't read the documentation and just typed 'tug'.\n");
      write("Tug usage has changed. Be sure to read 'info tug' for details.\n");
      return 1;
   }
}

tug_item(arg)
{
   object ob, oc, gob;
   string tmp, arg1;
   int spot, sp_needed, value;
      
   /* No guild object, no service */
   gob = present(GUILD_ID, this_player());
   if(!gob) return 0;

   if(!arg) return 0;
   spot = arg - 1;
   if(spot > MAX_ITEMS || spot < 0)
   {
      tell_room(this_object(), (this_player()->query_name()) + " boggles in steep profusion.\n");
      write("That is not a location that can be tugged from.\n");
      return 1;
   }
   
   if(!stuff[spot] || stuff[spot] == "")
   {
      tell_room(this_object(), (this_player()->query_name()) + " tugs helplessly against the ether-muck.\n");
      write("That tug location is empty.\n");
      return 1;
   }
   
 
   ob = clone_object(stuff[spot]);
   if(!ob)
   {
      tell_room(this_object(), (this_player()->query_name()) + " tugs helplessly against the ether-muck.\n");
      write("Something fades into view but then disappears.\n");
      stuff[spot] = 0;
      stuff_desc[spot] = 0;
      stuff_pusher[spot] = 0;
      return 1;
   }
   
   /* NEW - added 06 oct 2003 by mizan */
   if(this_player()->query_level() > 5 && gob->query_linna_tug_items() > gob->query_linna_push_items())
   {
       write("You have a poor tug record of " + gob->query_linna_tug_items() + " tugged to " + gob->query_linna_push_items() +  " pushed items.\n");
       write("You have taken out more items than you have pushed in.\nNo service. Sorry.\n");
       tell_room(this_object(), (this_player()->query_name()) + " is rejected by the tug for being such a mooch.\n");
       return 1;
   }


   /* check for SPS */
   sp_needed = 2 * this_player()->query_level();

   if(this_player()->query_sp() < sp_needed)
   {
      write("You feel too drained to do this.\n");
      write("You need [" +  sp_needed + "]SP to use tug.\n");
      return 1;
   }
   else this_player()->add_spell_point(-sp_needed);
   
    
   /* CREDIT PLAYER - gather the value of the object */
   value = ob->query_value();
   if(value < 0) value = 0;
   if(value > 10000) value = 10000;
   
   /* CREDIT PLAYER - log the tug */
   gob->add_linna_tug_items();
   gob->add_linna_tugitems_value_total(value);
    
   /* CREDIT PLAYER - create the tracking object which logs where things are going */
   oc = clone_object("/players/mizan/closed/poly/linna-tracker.c");
   move_object(oc, "/players/mizan/dirt");
   oc->set_track_creator(this_player());
   oc->set_track(ob);
         
   /* Tell everyone what happened */
   write("You tug against the ether-muck.\n");
   tell_room(this_object(), (this_player()->query_name()) + " tugs against the ether-muck.\n");
   tell_room(this_object(), (ob->short()) + " fades into view.\n");
   
   if(ob->short())
   log_file("mizan.tugactivity", "[" + ctime() + "] " + this_player()->query_name() + " pulled out " + lower_case(ob->short())+ ".\n");
   stuff[spot] = 0;
   stuff_desc[spot] = 0;
   stuff_pusher[spot] = 0;
   save_object(ITEMLIST);
   
   /* now finally put the new object into the room */
   move_object(ob, this_object());
   ob->set_value(1);
   
   return 1; 
}

short() { return "Plane of Etheriel [many exits]"; }

long() 
{
   int i;
   string lngfrm;
   write("\n"+
      "\tThis spot seems to have a very consistent ether-muck viscosity,\n"+
      "  and it seems to lift stress right off your shoulders like a sublime\n"+
      "  form of therapy. You can get a better view of the ether-muck from here,\n"+
      "  in all of its confused glory. You are not exactly sure why, but this\n"+
      "  area in particular feels just like home.\n");
   lngfrm = "There are many obvious exits: up, machine, office, adv, fatso,";
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

tug_activity()
{
   say(this_player()->query_name() + " checks the tug history log.\n");
   write(">> Recent Tug Activity:\n\n");
   tail("/log/mizan.tugactivity");
   return 1;
}

tug_tracking()
{
   say(this_player()->query_name() + " checks the tug tracking log.\n");
   write(">> Recent Tug Object Tracking:\n\n");
   tail("/log/mizan.tugtracker");
   return 1;
}

tug_finger(str)
{
   say(this_player()->query_name() + " ponders the meaning of tug and statistics.\n");
   return TUG_R->tug_finger(str);   
}

tug_list()
{
   int i;
   
   say(this_player()->query_name() + " checks the tug listing.\n");
   write(">> Items Currently Pushed In:\n\n");
   
   for(i = 0; i < sizeof(stuff); i ++)
   {
      if(!stuff[i] || stuff[i] == "")
         write("[" + (i + 1) + "] (nothing)\n");
      else
         write("[" + (i + 1) + "] " + stuff_desc[i] + " (pushed in by " + stuff_pusher[i] + ")\n");
   }

   write("To retrieve an item, use the command 'tug #' as indicated by the list number.\n");
   write("Make sure you put it back when done! Or at least put something similar in.\n");
   return 1;
}

