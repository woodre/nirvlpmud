/*
 * Hmm, this is a better way of gathering data than using my backscreens.
 *
 * There appears to be a security check that does not allow non-living
 * objects to call write_file(). Therefore I have created Loafy to do this.
 * At fixed intervals he will will execute the log command.
 *
 */


/* The log interval is going to be short right now because I want to build
 * up a big dataset quickly.
 */
#define LOG_SNAP        1800
#define LOG_FILE        "/players/mizan/logs/SQL/DATA_COLLECTOR"
#define HOME            "/players/mizan/workroom.c"

id(string str)
{
   return str == "log";
}

short()
{
   return "A petrified log";
}

long()
{
   write("This is an ordinary petrified log.\n"+
      "A brass plaque bolted on to it reads:\n"+
      "'Long live SQL'\n");
   return;
}

reset(mixed arg)
{
   if(arg) return;

   log_SQL_data();
   move_object(this_object(), HOME); 
   return;
}

void init()
{
   add_action("log_SQL_data","log_SQL_data");
}

/*
 * this function does the log work.
 *
 */
log_SQL_data()
{
   object ob;     /* our user array */
   object room;   /* the room the user is in */
   object att;    /* the attacker of the player */
   object wep;    /* the weapon the player is using */
   int i;         /* counter */
   string cday;   /* the current day */
   string lfile;  /* the name of our log file */
   string temp;   /* temp string, constitutes one line of text usually. */
   string ctm;    /* current time */
   string ctd;    /* current date */

   ob = users();
   
   ctd = extract(ctime(time()), 4, 9) + " " + extract(ctime(time()), 20, 24);
   ctm = extract(ctime(time()), 11, 18);

   temp = "";

   for(i = 0; i < sizeof(ob); i ++)
   {
      room = environment(ob[i]);

      if(room)
      {
         att = ob[i]->query_attack();
         wep = ob[i]->query_weapon();

         /* we only want people who are logged in */
         
         temp += ctm + "\t";
         temp += ctd + "\t";
         temp += query_ip_number(ob[i]) + "\t";    /* the ip number */
         temp += query_ip_name(ob[i]) + "\t";      /* the ip name */
         temp += ob[i]->query_real_name() + "\t";  /* the real name */
         temp += ob[i]->query_mailaddr() + "\t";   /* the mail address (usually useless) */
         temp += ob[i]->query_level() + "\t";      /* the level */
         temp += ob[i]->query_guild_name() + "\t"; /* guild name */
         temp += ob[i]->query_exp() + "\t";        /* how much exp */
         temp += ob[i]->query_money() + "\t";      /* how much $$ on hand */
         temp += ob[i]->query_wc() + "\t";         /* the weapon class */
         temp += ob[i]->query_ac() + "\t";         /* the armor class */
         temp += ob[i]->query_hp() + "\t";         /* our hp */
         temp += ob[i]->query_sp() + "\t";         /* our sp */
         temp += creator(room) + "\t";             /* the creator of the room they are in */
         temp += object_name(room) + "\t";           /* filename of room */

         if(att)
         {
            temp += creator(att) + "\t";           /* creator of the monster */
            temp += object_name(att) + "\t";         /* file name of the monster */
            temp += att->query_name() + "\t";      /* name of the monster */
            temp += att->query_wc() + "\t";        /* weapon class of the monster */
            temp += att->query_ac() + "\t";        /* armor class */
            temp += att->query_mhp() + "\t";       /* max hitpoints */
         }
         else
            temp += "0\t0\t0\t0\t0\t0\t";

         if(wep)
         {
            temp += creator(wep) + "\t";           /* creator of the weapon */
            temp += object_name(wep) + "\t";         /* the file name of the weapon */
            temp += wep->weapon_class() + "\t";        /* the effective wc */
         }
         else
            temp += "0\t0\t0\t";

         temp += "\n";
      }
   }

/*
   temp += "\n";
 */

   cday = extract(ctime(time()), 4, 9);

/*
   lfile = LOG_FILE + "_" + cday;
 */

   lfile = "mizan.SQLDATA_" + cday + ".txt";

   lfile = strip_whitespace(lfile);

/*
   write_file(lfile , temp);
*/

   log_file(lfile, temp);

   remove_call_out("log_SQL_data");
   call_out("log_SQL_data", LOG_SNAP);

   return;
}

/* This function just strips the whitespace out of a string and replaces
 * them with _ underscores. 
 */
strip_whitespace(string str)
{
   string temp, letter;
   int i;

   temp = "";

   if(!str) return "";
   else
   {
      for(i = 0; i < strlen(str); i++)
      {
         /* grab a letter */
         letter = extract(str, i, i);
         
         /* if its a space, replace it. Else add the letter. */
         if(letter == " ") temp += "_";
         else temp += letter;
      }

      /* we're done. */
      return temp;
   }
}
