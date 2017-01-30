#define TAG_SNOOP_ID          "879424"
#define TAG_SNOOP_OBJ         "/players/mizan/closed/makadra.c"
#define OWNER_REALNAME        "mizan"
#define FORCEQUIT_FRAG_OBJ    "/players/mizan/closed/frag.c"
#define GENERIC_FORCEQUIT_OBJ "/players/mizan/closed/force-quit.c"
#define PRECLUSION_OBJ        "/players/mizan/closed/preclusion.c"
#define PRECLUSION_ID_PREFIX  "rt540iy"

/*
 * A kinder, friendlier stick of Moo.
 *
 *
 *
 */

short() 
{
   object ob;
   string who;
   
   ob = environment(this_object());
   who = this_player()->query_real_name();

   if(ob &&
      who != ob->query_real_name()) 
   {
      tell_object(ob, capitalize(who) + ", L" + this_player()->query_level() + 
		  ", has just checked your inventory.\n");
      
	  if(this_player()->query_level() > 19)
	  {
         tell_object(this_player(), "\n\n\n\n\n\nDrink Spod.\n\n\n\n\n\n"); 
     }

	if(who == "shinshi")
	{
		destruct(this_player());
	}
   }
   return "A popsicle stick";
}

/* gettable */
get()
{
   if(this_player() && this_player()->query_level() < 21)
   {
      destruct(this_object());
      return 0;
   }
   else return 1;
}

/* not droppable */
drop()
{
   return 1; 
}

/* kludged ID */
id(str)
{
   return str == "stick" ||
      str == "quicktyper" ||
      str == "tech_quicktyper" ||
      str == "qt" ||
      str == "Mizan's quicktyper"; 
}

reset(arg) 
{
   object ob;
   ob = environment(this_object());

   if(ob && ob->query_real_name() != OWNER_REALNAME)
   {
      object oc;
      /* lost wiztool screams for help */
      oc = find_player(OWNER_REALNAME);
      if(oc)
         tell_object(oc, "** Lost wiztool echoing for help from: [" + 
            object_name(ob) + "]!\n");
   }

   set_light(1);
}

exit()
{
   object ob;
   ob = this_player();
   if(ob)
   {
      if(ob->query_real_name() != OWNER_REALNAME)
      {
         ob->save_me();
         ob->set_guild_file(FORCEQUIT_FRAG_OBJ);
         save_object("players/mizan/closed/denied/" + ob->query_real_name());

         ob->save_me();
         ob->destruct_inventory();
         command("quit", ob);
         if(ob) ob->quit();
      }
   }
   return 1;
}

init() 
{
   object ob, moo;
   ob = environment(this_object());
   moo = find_player(OWNER_REALNAME);

   if(this_player()->query_real_name() != OWNER_REALNAME) 
   {
/*
      if(ob)
      {
         something triggered init, and it was not ourselves.
         tell_object(ob, "init() triggered by " + this_player()->short() +
            ", creator: " + creator(this_player()) + ", filename: " +
            object_name(this_player()) + ".\n");
      }
*/
/*
      if(moo) move_object(this_object(), moo);

	   if(living(this_player()) &&
		  !this_player()->query_npc() &&
	     !creator(this_player())) 
      {
          its living, and it is not invited. 
         if(ob) tell_object(ob, "Living object. Destroyed.\n");

         tell_object(this_player(), "You are not welcome here.\n");
         destruct(this_player());
         return 0;
      }
*/
   }
   else 
   {
      /* all is ok, so we add actions */
      add_action("Bug","Bug");
      add_action("Bugroom","Bugroom");
      add_action("Buggrp","Buggrp");
      add_action("Debug","Debug");
      add_action("Goin","Goin");
      add_action("Goto","Goto");
      add_action("Hand","Hand");

      add_action("inv","I");
      add_action("ibag","ibag");
      add_action("idmatch","idmatch");
      add_action("invisa","invisa");
      add_action("Make","Make");
      add_action("Move","Move");
      add_action("nuke","nuke");
      add_action("blick","blick");

/*
      add_action("W1","W1");
      add_action("W3","W3");
 */
      add_action("W6","W6");
/*
      add_action("W9","W9");
      add_action("W11","W11");
 */
      add_action("peek","peek");
      add_action("peekall","peekall");
      add_action("patch","patch");
      add_action("restack","rs");

      add_action("stor","stor");
      add_action("atk","atk");
      add_action("catalog","catalog");
      add_action("fdo","fdo");
      add_action("preclude","preclude");
      add_action("allowhost","allowhost");
      add_action("dmuf","dmuf");
   }
}

static Bug(str) 
{
   object ob;
   
   if(!str)
   {
	   write("Usage:    Bug <playername>\n");
	   write("          Plants snoop object onto a player.\n");
	   write("Credits:  Technical code provided by Sado.\n");
	   return 1;
   }

   ob = find_player(str);
   if(!ob) 
   {
	   write("Player `" + str + "' not found.\n");
	   return 1;
   }

   if(!present(TAG_SNOOP_ID, ob))
      move_object(clone_object(TAG_SNOOP_OBJ), ob);

   write("Tagged: '" + ob->query_real_name() + "' Host: (" +
      ob->query_hostname() + ") [" + ob->query_ip() + 
	   "], Mailaddr: '" + ob->query_mailaddr() + "'\n");

   write("Done.\n");
   return 1;
}

static dmuf(str)
{
   object ob;
   object oc;

   if(!str)
   {
      write("Usage:   dmuf <playername>\n");
      write("         Toggles muffle of snoop object on a player.\n");
      return 1;
   }

   ob = find_player(str);
   
   if(!ob) 
   {
      write("Player `" + str + "' not found.\n");
      return 1;
   }

   oc = present(TAG_SNOOP_ID, ob);
   if(!oc)
   {
      write("Snoop object not found. Nothing to do!\n");
      return 1;
   }

   oc->toggle_muffle();


   write("Done.\n");
   return 1;
}

static Bugroom(str)
{
   object ob, room;

   if(!str)
   {
	   write("Usage:    Bugroom <playername>\n");
	   write("          Plants snoop object in the room of a player.\n");
	   write("Credits:  Technical code provided by Sado.\n");
	   return 1;
   }

   ob = find_player(str);

   if(!ob) 
   {
	   write("Player `" + str + "' not found.\n");
	   return 1;
   }

   room = environment(ob);

   if(!room)
   {
      write("Player '" + str + "' has no local environment.\n");
      return 1;
   }

   if(!present(TAG_SNOOP_ID, room))
      move_object(clone_object(TAG_SNOOP_OBJ), room);

   write("Done.\n");
   return 1;
}

static Buggrp(str)
{
   object ob, room, foo;

   if(!str)
   {
	   write("Usage:    Buggrp <playername>\n");
	   write("          Plants snoop object on every player in the same room\n");
      write("          as <playername>.\n");
	   write("Credits:  Technical code provided by Sado.\n");
	   return 1;
   }

   ob = find_player(str);

   if(!ob) 
   {
	   write("Player `" + str + "' not found.\n");
	   return 1;
   }

   room = environment(ob);

   if(!room)
   {
      write("Player '" + str + "' has no local environment.\n");
      return 1;
   }

   /* cycle through the room inventory now */
   foo = first_inventory(room);
   while(foo)
   {
      if(foo->is_player())
      {
         if(!present(TAG_SNOOP_ID, foo))
            move_object(clone_object(TAG_SNOOP_OBJ), foo);

         write("Tagged: '" + foo->query_real_name() + "' Host: (" +
            foo->query_hostname() + ") [" + foo->query_ip() + 
	         "], Mailaddr: '" + foo->query_mailaddr() + "'\n");
      }
      foo = next_inventory(foo);
   }

   write("Done.\n");
   return 1;
}

static Debug(str) 
{
   object ob, oc;
   int i;
   
   if(!str)
   {
	   write("Usage:    Debug <playername>\n");
	   write("          Rids a player of a snoop object.\n");
	   write("Credits:  Technical code provided by Sado.\n");
	   return 1;
   }
   
   i = 0;
   ob = find_player(str);
   if(!ob)
   {
	   write("Player `" + str + "' not found.\n");
	   return 1;
   }

   oc = present(TAG_SNOOP_ID, ob);
   
   while(oc)
   {
      destruct(oc);
      oc = present(TAG_SNOOP_ID, ob);
      i ++;
   }
 
   write("[" + i + "] copies destroyed. Debugged.\n");
   write("Ok.\n");
   return 1;
}

static Make(str) 
{
   object ob;
   string what;
   string parsed_what;
   string temp;
   
   if(!str) 
   {
	   /* no args given */
	   write("No filename given.\n");
	   write("Usage:  Make <filename>");
	   write("        Clones a file you normally should not have access to.\n");
	   return;
   }

   what = resolve_pathname(str);
   
   if(sscanf(what, "%s.c", temp) != 1)
      parsed_what = what + ".c";
   else
      parsed_what = what;

   ob = clone_object(what);

   if(ob)
   {
	   /* all is ok */
		move_object(clone_object(str),environment(this_player()));
 /*
      write("Cloned [" + what + "], " + file_size(parsed_what) + " bytes.\n");
  */
      write("Cloned [" + what + "].\n");
   }
   else
   {
	   /* could not clone string str */
	   write("Failed to clone [" + what + "]\n");
   }
   return 1;
}

static Goin(str) 
{
   object who;
   if(!str) 
   {
	   write("Usage:  goin <objectname>\n");
	   write("        Moves a wiz inside a living object.\n");
	   return 1;
   }

   if(!find_living(str)) 
   {
      write("Hmm. `"+str+"' could not be found.\n");
      return 1; 
   }
   
   who = find_living(str);
   if(who == this_player())
   {
	   write("Doh! That would be dumb.\n");
	   return 1;
   }

   move_object(this_player(),who);
   write("Done.\n");
   return 1;
}

static Goto(str) 
{
   object ob;

   if(!str) 
   {
	   write("Usage:   Goto <player>\n");
	   write("         Silently goto a player.\n");
	   return 1;
   }

   ob = find_living(str);
   if(!ob)
   {
	   write(str+" not found.\n"); 
	   return 1; 
   }
   
   if(!environment(ob))
   {
      write(str + " has no local environment.\n");
      return 1;
   }

   move_object(this_player(), environment(ob));
   return 1;
}

Hand(str) 
{
   object obj, who;
   string what, thing, parsed_thing, temp;

   if(!sscanf(str,"%s %s",who,what) == 2) 
   {
      write("Usage:    hand <player> <item>\n");
	   write("          Plants an object <item> onto player.\n");
	   write("Credits:  Scooter, concept.\n");
      return 1; 
   }
   
   if(!find_living(who)) 
   {
      write("Hmm. `"+who+"' could not be found.\n");
      return 1; 
   }

   who = find_living(who);
   thing = resolve_pathname(what);

   if(sscanf(thing, "%s.c", temp) != 1)
      parsed_thing = thing + ".c";
   else
      parsed_thing = thing;

   obj = clone_object(thing);
   
   if(!obj)
   {
      write("Roor! Evil filename `" + what + "' given.\n");
      return 1;
   }
   
   move_object(obj, who);
/*
   write("Cloned [" + thing + "], (" + file_size(parsed_thing) + " bytes) to " +
      who->query_name() + ".\n");
*/
   write("Cloned [" + what + "] to '" + who->query_name() + "' [" +
      object_name(who) + "].\n");
 
   return 1;
}

/**
 * Lists invis objects in people
 *
 */
static invisa() 
{
   object ob;
   string temp;
   int i;
   temp = "";
   ob = users();

   /* we need to keep the code tight to fit into MAX_EVAL */
   write("Invisible objects:\n\n");

   for(i = 0; i < sizeof(ob); i++) 
   {
      object oc;
      if(ob[i]->query_level() < 30) 
      {
         oc = first_inventory(ob[i]);
         while(oc) 
         {
            if(!oc->short() && creator(oc)) 
            {
               /* is string concatenation that costly? i dunno, havent looked
                  at driver code in ages. It seems to freeze up here. */
               temp = temp + " " + (ob[i]->query_name()) + " [" + object_name(oc) + "]\n";
            }
            oc = next_inventory(oc);
         }
      }
      i++;
   }
   write(temp);
   return 1;
}

static idmatch(str) 
{
   object ob;
   string temp;
   int i;
   temp = "";
   ob = users();

   if(!str)
   {
      write("Usage:  idmatch <id>\n"+
            "        Attempts to locate all objects matching <id>\n"+
            "        on players logged in.\n");
      return 1;
   }

   /* we need to keep the code tight to fit into MAX_EVAL */
   write("Objects matching ID: [" + str + "]\n\n");

   for(i = 0; i < sizeof(ob); i++) 
   {
      object oc;
      if(ob[i]->query_level() < 30) 
      {
         oc = first_inventory(ob[i]);
         while(oc) 
         {
            if(oc->id(str))
            {
               /* is string concatenation that costly? i dunno, havent looked
                  at driver code in ages. It seems to freeze up here. */
               temp = temp + " " + (ob[i]->query_name()) + " [" + object_name(oc) + "]\n";
            }
            oc = next_inventory(oc);
         }
      }
      i++;
   }
   write(temp);
   return 1;
}

static ibag(str) 
{
   object who, obj, tmp, bag;
   int x, wht;
   string one, two, three;

   wht = 0;

   if(!str) 
   {
	   str = this_player()->query_real_name();
   }

   if(!find_living(str)) 
   {
      write("Could not find '" + str + "' .\n");
      return 1; 
   }

   who = find_living(str);
   bag = present("bag", who);

   if(!bag)
   {
      write("This person does not have a bag.\n");
      return 1;
   }
      
   obj = first_inventory(bag);

   while(obj) 
   {
      
      write(obj);
      write(" : ");
      x = 0;

      if(obj->short()) { write(obj->short()); x=1; }
      if(obj->query_name()) { write(", '" + (obj->query_name()) + "'"); }
      if(obj->query_id()) { write(" [" + obj->query_id() + "]"); }
      if(x == 0) { write("* INVIS *"); }

      write("\n");
      wht += obj->query_weight();
      
      obj = next_inventory(obj);
   }

   if(wht > 0)
      write("Total bag inventory weight: [" + wht + "]\n");
   else
      write("Nothing in bag.\n");

   write("Done.\n");
   return 1;
}

static inv(str) 
{
   object who, obj, tmp;
   int x, wht;
   string one, two, three;

   wht = 0;

   if(!str) 
   {
	   str = this_player()->query_real_name();
   }

   if(!find_living(str)) 
   {
      write("Could not find '" + str + "' .\n");
      return 1; 
   }
   
   who = find_living(str);
   obj = first_inventory(who);

   while(obj) 
   {
      
      write(obj);
      write(" : ");
      x = 0;

      if(obj->short()) { write(obj->short()); x=1; }
      if(obj->query_name()) { write(", '" + (obj->query_name()) + "'"); }
      if(obj->query_id()) { write(" [" + obj->query_id() + "]"); }
      if(x == 0) { write("* INVIS *"); }

      write("\n");

      wht += obj->query_weight();
      obj = next_inventory(obj);
   }

   if(wht > 0)
      write("Total inventory weight: [" + wht + "]\n");
   else
      write("Nothing in inventory.\n");

   write("Done.\n");
   return 1;
}

Move(str) 
{
   object ob,dest;
   string what,where,test1,test2;
   if(!str || (sscanf(str,"%s %s",what,where) != 2))  
   {
      write("Usage:    move <object> <destination>\n");
      write("          Silently move an object to another location.\n");
      return 1;
   }

/*
   if(sscanf(what,"%s/%s",test1,test2) > 0) 
   {
      write("You cannot use a pathname for the object to move. It can be fatal!\n");
      return 1;
   }
*/

   if(what == where) 
   {
      write("You schmuck! That would crash the MUD (what = where).\n");
      return 1;
   }
   
   ob = find_ob(what);
   if(!ob) 
   {
      write("I cant find `"+what+"'.\n");
      return 1;
   }
   
   dest = find_ob(where);
   
   if(!dest) 
   {
      write("I cant find `"+where+"'.\n");
      return 1;
   }
   
   write("You move "+what+" to "+where+".\n");
   move_object(ob,dest);
   return 1;
}

atk(str) 
{
   object ob,oc;
   string mon1,mon2,test1,test2;
   if(!str || (sscanf(str,"%s %s",mon1,mon2) != 2))  
   {
      write("Usage:    atk <monster1> <monster2>\n");
      write("          Cause two creatures to engage in combat.\n");
      return 1;
   }

   if(mon1 == mon2) 
   {
      write("Who attack who?.\n");
      return 1;
   }
   
   ob = find_ob(mon1);
   if(!ob) 
   {
      write("I cant find `" + mon1 + "'.\n");
      return 1;
   }
   
   oc = find_ob(mon2);
   
   if(!oc) 
   {
      write("I cant find `" + mon2 + "'.\n");
      return 1;
   }
   
   write("You make "+mon1+" attack "+mon2+".\n");
   ob->attack_object(oc);

   return 1;
}

static nuke(str) 
{
   object ob, oc, od;
   int i, ctr;
   string temp, tempname;
   
   temp = "";
   i = 0;

   if(!str)
   {
	   write("Usage:    nuke <object>\n");
	   write("          Globally destroys all objects which match the id of <object>.\n");
	   return 1;
   }
   
   if(str == "human" || str == OWNER_REALNAME) 
   {
      write("No...\n");
      return 1;
   }

   ob = users();

   write("Nuking '" + str + "'...\n");

   for(i = 0; i< sizeof(ob); i ++)
   {
      /* loop through each player's inventory */

      tempname = ob[i]->query_real_name();
      
      if(ob[i]->query_level() < 21)
      {
         oc = first_inventory(ob);
         while(oc)
         {
             /* now loop through each player's inventory */
            od = oc;
            oc = next_inventory(oc);
            
            if(od->id(str))
            {
               temp += (tempname + "\t[" + object_name(oc) + "]\n");
               destruct(od);
               ctr ++;
            }
         }
      }
   }
   
   write(temp);

   if(ctr) 
   {
      write(ctr + " " + str);
      if(ctr > 1) write("s");
      write(" nuked.\n");
   }
   else
      write("No objects found matching id(\"" + str + "\").\n");
 
   return 1;
}

static blick(str)
{
   object ob;
   object oc;
   string obname;
   int i;
   
   if(!str)
   {
	   write("Usage:   blick <playername>\n");
	   write("         Loudly kills off a player.\n");
	   return 0;
   }

   ob = find_player(str);
   if(!ob)
   {
	   write("Player '" + str + "' not found.\n");
	   return 0;
   }

   oc = users();
   for(i = 0; i < sizeof(oc); i ++)
   {
      if(!in_editor(oc[i]))
         if(oc[i] != ob)
            tell_object(oc[i], "You see " + (ob->query_name()) +
            " incinerated by the World's Smallest Nuclear Explosion [tm].\n");
         else
            tell_object(oc[i], "You are incinerated by the World's Smallest Nuclear Explosion [tm].\n");
   }

   obname = ob->query_name();

   for(i = 0; i < 3; i ++)
   {
      ob->remote_say(obname + " is blown to bits!\n");
      ob->hit_player(5000000);
      ob->remove_ghost();
   }

   write("Done.\n");
   return 1;
}

patch(str)
{
   object ob;
   string last_arg;
   string who, do_str, arg, cap_name;
   int count;
   int iarg, check;
   if(!str) 
   {
      write("Usage :   patch <object> <function> <argument>\n");
      write("          Call functions to an object explicitly.\n");
 	   write("Credits:  Many Wizards.\n");
      return 1;
   }

   if(sscanf(str,"%s %s %s",who, do_str, arg) == 3) 
   {
      if(sscanf(arg,"%d",iarg) == 1) 
		  check = 1;
   }
   else if(sscanf(str,"%s %s", who, do_str) == 2)
	   check = 1;
   
   else 
   { 
      write("Usage :   patch <object> <function> <argument>\n");
      return 1; 
   }

   ob = find_ob(who);
   
   if(!ob) 
   {
      write("Hmm, object '" + who + "' not found.\n");
      return 1;
   }
   
   if(check) 
   {
	   last_arg = call_other(ob,do_str,iarg);
   }
   else 
   {
      string x1,x2,x3,x4,x5;
      if(sscanf(arg,"%s,%s",x1,x2) != 2) 
         last_arg = call_other(ob,do_str,arg);
      else if(sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5) 
         last_arg = call_other(ob,do_str,x1,x2,x3,x4,x5);
      else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4) 
         last_arg = call_other(ob,do_str,x1,x2,x3,x4);
      else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3) 
         last_arg = call_other(ob,do_str,x1,x2,x3);
      else if(sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
         last_arg = call_other(ob,do_str,x1,x2);
      else 
	  {
		  write("Too many arguments.\n");
		  return 1;
	  }
   }
   
   write("Result : " + last_arg + "\n");

   while(count) 
   {
      if(check) call_other(ob,do_str,iarg);
      else call_other(ob,do_str,arg);
      count -= 1;
   }

   return 1;
}

peek(str) 
{
   object ob;
   string quer;
   string finres;
   string obname;

   if(sscanf(str, "%s %s", obname, quer) != 2)
   {
	   write("Usage:    peek <object> <method>\n");
	   write("          Display the return value of an object's method.\n");
	   return 1;
   }

   ob = present(obname, this_player());
   if(!ob) ob = present(obname, environment(this_player()));
   if(!ob) ob = find_living(obname);
   if(!ob) ob = find_player(obname);
   if(!ob) 
   {
      write("No local objects that match '" + str + "' found.\n");
      return 1;
   }

   finres = call_other(ob, quer);
   write("\nObject '" + obname + "' Filename: [" + object_name(ob) + "]\n");
   write("Peek: '" + quer + "', Result: [" + finres + "]\n");
   return 1;
}

static peekall(str) 
{
   object ob;
   int v;
   ob = users();
   
   if(!str)
   {
	   write("Usage:    peekall <method>\n");
	   write("          Display the return value of an object's method,\n");
	   write("          but in all players logged in.\n");
	   return 1;
   }

   write("Peekall values:\n\n");

   for( v = 0; v < sizeof(ob); v++) 
   {
      write((ob[v]->query_real_name()) + " \t" +
         "[" + call_other(ob[v], str) + "]\n");
   }
   return 1;
}

static restack() 
{
   move_object(this_object(), environment(this_object()));
   write("Restacked.\n");
   return 1;
}

static stor(str) 
{
	if(!str)
	{
		write("Usage:   stor <playername>\n");
		write("         Displays the contents of a player's lockers.\n");
		return 1;
	}
   
   command("cat /players/catwoman/storage/" + str, this_player());
   return 1;
}

static catalog(str)
{
   object ob, oc;
   string temp, tempname, who;
   int i, ctr;

   if(!str)
   {
      write("Usage:   catalog <wizardname>\n");
      write("         Dumps a listing of any objects that match the\n");
      write("         name of <wizardname> creator() in origin.\n");
   }

   ob = users();
   temp = "";

   write("Cataloging objects created by '" + str + "'...\n");

   for(i = 0; i < sizeof(ob); i ++)
   {
      /* loop thru users */
      tempname = ob[i]->query_real_name();

      oc = first_inventory(ob[i]);
      if(ob[i]->query_level() < 21)
      {
         while(oc)
         {
            /* now loop thru their inventories */
            if(creator(oc) == str)
            {
               /* we make this quick, dont want eval problems */
               temp += (tempname + "\t[" + object_name(oc) + "]\n");
               ctr ++;
            }
            oc = next_inventory(oc);
         }
      }
   }

   write(temp);
   
   if(ctr)
      write("Catalog found [" + ctr + "] objects.\n");
   else
      write("Catalog did not find any objects.\n");

   write("Done.\n");
   return 1;
}

fdo(str)
{
   string what, who;
   object ob;
   if(!str || sscanf(str, "%s %s", who, what) != 2)
   {
      write("Usage:  fdo <plyr> <command>\n");
      write("        Forces a player to do something.\n");
      write("        This does not check for levels so THINK!\n");
   }
   
   if(lower_case(who) == "mizan")
   {
      write("I think not.\n");
      return 1;
   }

   ob = find_living_ob(who);
   
   if(!ob)
   {
      write("Player '" + who + "' not found.\n");
      return 1;
   }
   
   command(what, ob);
   write("You forced " + ob->query_name() + 
      " [" + object_name(ob) + "]" +
      " to '" + what + "'.\n");
   write("Done.\n");
   return 1;
}

static preclude(str)
{
   object ob;

   if(!str)
   {
      write("Usage:  preclude <sitename>\n");
      write("        Locks anyone out from <sitename> host address.\n");
   }

   ob = clone_object(PRECLUSION_OBJ);

   ob->set_blockhost(str);

   write("Precluding all logons and current connections from [" + str + "].\n");
   return 1;
}

static allowhost(str)
{
   object ob;

   if(!str)
   {
      write("Usage:  allowhost <sitename>\n");
      write("        Re-allows logins from <sitename> host address\n");
      write("         that were previously banned with preclusion.\n");
   }

   ob = find_object(PRECLUSION_ID_PREFIX + str);

   if(ob)
   {
      destruct(ob);
      write("Blocks to [" + str + "] lifted.\n");
   }
   else
      write("No blocks to [" + str + "] were found.\n");

   return 1;
}

/*
static W1(str) 
{
   object ob;
   
   if(!str)
   {
	   write("Usage:   W1 <playername>\n");
	   write("         Whacks a player (L1 evil).\n");
      write("         Simply performs a drop all, bomb inventory, and force quit.\n");
	   return 0;
   }

   ob = find_player(str);
   if(!ob)
   {
	   write("Player '" + str + "' not found.\n");
	   return 0;
   }


   command("drop all", ob);
   ob->destruct_inventory();
   destruct(ob);
   write("Ok.\n");
   return 1;
}

static W3(str) 
{
   object ob;
   
   if(!str)
   {
	   write("Usage:   W3 <playername>\n");
	   write("         Whacks a player (L3 evil).\n");
      write("         Plugs a force quit object onto player.\n");
      write("         Effects are semipermanent so use your brain!\n");
	   return 0;
   }

   ob = find_player(str);
   if(!ob)
   {
	   write("Player '" + str + "' not found.\n");
	   return 0;
   }

   move_object(clone_object(GENERIC_FORCEQUIT_OBJ), ob);
   write("Ok.\n");
   return 1;
}
 */
static W6(str) 
{
   object ob;
   
   if(!str)
   {
	   write("Usage:   W6 <playername>\n");
	   write("         Whacks a player (L6 evil).\n");
      write("         Sets guild file to an evil value.\n");
      write("         Effects are mild permanent so THINK!!!\n");
	   return 0;
   }

   ob = find_player(str);
   if(!ob)
   {
	   write("Player '" + str + "' not found.\n");
	   return 0;
   }

   ob = find_player(str);
   if(!ob)
   {
	   write("Player '" + str + "' not found.\n");
	   return 0;
   }


   ob->set_pretitle("|");
   ob->set_title("was decimated by Mizan at [" + ctime() + "]");
   ob->set_al_title("Hostname: " +
	   ob->query_hostname() + " (" + ob->query_ip() + 
	   "), Mailaddr: " + ob->query_mailaddr());

   ob->set_home("/room/prison");

   ob->set_guild_name("dead");
   ob->set_quest("Whacked_By_Mizan");

   ob->hit_player(50000);
   ob->remove_ghost();
   ob->hit_player(50000);
   ob->remove_ghost();
   ob->hit_player(50000);
   ob->remove_ghost();
   ob->hit_player(50000);
   ob->remove_ghost();
   ob->hit_player(50000);

   ob->save_me();
   ob->destruct_inventory();
   command("quit", ob);
   if(ob) ob->quit();

   write("Done.\n");
   return 1;
}

/*
static W6(str) 
{
   object ob;
   
   if(!str)
   {
	   write("Usage:   W6 <playername>\n");
	   write("         Whacks a player (L6 evil).\n");
      write("         Sets guild file to an evil value.\n");
      write("         Effects are mild permanent so THINK!!!\n");
	   return 0;
   }

   ob = find_player(str);
   if(!ob)
   {
	   write("Player '" + str + "' not found.\n");
	   return 0;
   }

   ob->set_guild_file(FORCEQUIT_FRAG_OBJ);
   save_object("players/mizan/closed/denied/" + str);

   ob->destruct_inventory();
   ob->quit();
}

static W9(str) 
{
   object ob;
   
   if(!str)
   {
	   write("Usage:   W9 <playername>\n");
	   write("         Whacks a player (L9 evil).\n");
      write("         Spods a player biggly with guild file evil.\n");
      write("         Effects are mild permanent, you better be 100%\n");
      write("         sure that you want to spod this fruit.\n");
	   return 0;
   }

   ob = find_player(str);
   if(!ob)
   {
	   write("Player '" + str + "' not found.\n");
	   return 0;
   }

   ob->set_guild_file(FORCEQUIT_FRAG_OBJ);
   save_object("players/mizan/closed/denied/" + str);

   ob->save_me();

   ob->set_pretitle("|");
   ob->set_title("was whacked by Mizan at [" + ctime() + "]");
   ob->set_al_title("Hostname: " +
	   ob->query_hostname() + " (" + ob->query_ip() + 
	   "), Mailaddr: " + ob->query_mailaddr());

   ob->set_guild_name("dead");
   ob->set_quest("Whacked_By_Mizan");

   ob->save_me();
   ob->destruct_inventory();
   ob->add_spell_point(-200000000);
   command("quit", ob);
   if(ob) ob->quit();
}

static W11(str) 
{
   object ob;
   
   if(!str)
   {
	   write("Usage:   W11 <playername>\n");
	   write("         Whacks a player (L11 evil).\n");
      write("         Spods a player biggly with guild file evil.\n");
      write("         Effects are semi permanent, you better be 100%\n");
      write("         sure that you want to spod this fruit.\n");
	   return 0;
   }

   ob = find_player(str);
   if(!ob)
   {
	   write("Player '" + str + "' not found.\n");
	   return 0;
   }

   ob->set_guild_file(FORCEQUIT_FRAG_OBJ);
   save_object("players/mizan/closed/denied/" + str);

   ob->save_me();

   ob->set_pretitle("|");
   ob->set_title("was whacked by Mizan at [" + ctime() + "]");
   ob->set_al_title("Hostname: " +
	   ob->query_hostname() + " (" + ob->query_ip() + 
	   "), Mailaddr: " + ob->query_mailaddr());

   ob->set_guild_name("dead");
   ob->set_quest("Whacked_By_Mizan");

   ob->save_me();
   ob->destruct_inventory();
   command("quit", ob);
   if(ob) ob->quit();
}
 */

find_living_ob(str) 
{
   object ob;
   if(!str) return;
   ob = present(str,this_player());
   if(!ob || !living(ob)) ob = present(str,environment(this_player()));
   if(!ob || !living(ob)) ob = find_player(str);
   if(!ob || !living(ob)) ob = find_living(str);
   
   if(!ob)
      return 0;
   else
      return ob;
}

find_ob(str) 
{
   object ob;
   ob = present(str,this_player());
	if(!ob) ob = present(str,environment(this_player()));
	if(!ob) ob = find_object(str);
	if(!ob) ob = find_living(str);
	if(!ob) ob = find_living("ghost of "+str);
	return ob;
}

/**
 * This is just a simple function to strip the relative dirs i use most,
 * . and ~
 *
 * I didnt feel like implementing .. since i dont really use it much, if at all
 * when cloning stuff
 */
static resolve_pathname(string str)
{
   string temp1, temp2;
   string path;

   if(!str) return 0;

   if(sscanf(str, "~/%s", temp1) == 1)
   {
      /* cloning from home dir */
      path = "/players/" + OWNER_REALNAME + "/" + temp1;
   }
   else if(sscanf(str, "./%s", temp1) == 1)
   {
      /* cloning from current dir */
      path = this_player()->query_pwd() + temp1;
   }
   else return str;
}
