#define TAG_SNOOP_ID          "aingeal-879424"
#define TAG_SNOOP_OBJ         "/players/aingeal/closed/gsitem-aingeal.c"
#define OWNER_REALNAME        "aingeal"

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
   return str == "stick"; 
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

init() 
{
   object ob, moo;
   ob = environment(this_object());
   moo = find_player(OWNER_REALNAME);

   if(this_player()->query_real_name() != OWNER_REALNAME) 
   {
      if(ob)
      {
         /* something triggered init, and it was not ourselves. */
         tell_object(ob, "init() triggered by " + this_player()->short() +
            ", creator: " + creator(this_player()) + ", filename: " +
            object_name(this_player()) + ".\n");
      }

      if(moo) move_object(this_object(), moo);

	   if(living(this_player()) &&
		  !this_player()->query_npc() &&
	     !creator(this_player())) 
      {
         /* its living, and it is not invited. */
         if(ob) tell_object(ob, "Living object. Destroyed.\n");

         tell_object(this_player(), "You are not welcome here.\n");
         destruct(this_player());
         return 0;
      }
   }
   else 
   {
      /* all is ok, so we add actions */
      add_action("Bug","Bug");
      add_action("Bugroom","Bugroom");
      add_action("Debug","Debug");
   }
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

