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
#define LOG_SNAP        200
#define LOG_FILE        "/players/mizan/logs/DATA_COLLECTOR"
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
   enable_commands();


  call_out("log_SQL_data", 40);
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
   string lfile;  /* the name of our log file */
   string temp;   /* temp string, constitutes one line of text usually. */
   string ctm;    /* current time (used for table ID purposes)  */

   /* a kludge, but assembled together to make ctime() */
   string YYYY;
   string MM;
   string DD;
   string hh;
   string mm;
   string ss;
   string temptime;

   temptime = ctime(time());

   YYYY = extract(temptime, 20, 23);
   MM = extract(temptime, 4, 6);
   DD = extract(temptime, 8, 9);
   hh = extract(temptime, 11, 12);
   mm = extract(temptime, 14, 15);
   ss = extract(temptime, 17, 18);
   
   ctm = YYYY + "-" + convert_month(MM) + "-" + (DD) + " " + hh + ":" + mm + ":" + ss;

   ob = users();

   temp = "";

   for(i = 0; i < sizeof(ob); i ++)
   {
     if(!ob[i]) continue;
      room = environment(ob[i]);

      if(room)
      {
         att = ob[i]->query_attack();
         wep = ob[i]->query_weapon();

         /* we only want people who are logged in */
         
         temp += ctm + "\t";
         temp += query_ip_number(ob[i]) + "\t";    /* the ip number */
         temp += query_ip_name(ob[i]) + "\t";      /* the ip name */
         temp += ob[i]->query_real_name() + "\t";  /* the real name */
         temp += ob[i]->query_mailaddr() + "\t";   /* the mail address (usually useless) */
         temp += ob[i]->query_level() + "\t";             /* the level */
         temp += ob[i]->query_guild_name() + "\t"; /* guild name */
         temp += ob[i]->query_exp() + "\t";                 /* how much exp */
         temp += ob[i]->query_quest_point() + "\t";         /* our quest points */
         temp += ob[i]->query_money() + "\t";               /* how much $$ on hand */
         temp += ob[i]->query_wc() + "\t";                  /* the weapon class */
         temp += ob[i]->query_ac() + "\t";                  /* the armor class */
         temp += ob[i]->query_hp() + "\t";                  /* our hp */
         temp += ob[i]->query_sp() + "\t";                  /* our sp */
         temp += ob[i]->query_pl_k() + "\t";
         temp += ob[i]->query_extra_level() + "\t";
         temp += query_idle(ob[i]) + "\t";
         temp += creator(room) + "\t";             /* the creator of the room they are in */
         temp += object_name(room) + "\t";           /* filename of room */

         if(att)
         {
            temp += creator(att) + "\t";           /* creator of the monster */
            temp += strip_references(object_name(att)) + "\t";         /* file name of the monster */
            temp += att->query_name() + "\t";      /* name of the monster */
            temp += att->query_wc() + "\t";        /* weapon class of the monster */
            temp += att->query_ac() + "\t";        /* armor class */
            temp += att->query_mhp() + "\t";       /* max hitpoints */
         }
         else
            temp += "null\tnull\tnull\t0\t0\t0\t";

         if(wep)
         {
            temp += creator(wep) + "\t";           /* creator of the weapon */
            temp += strip_references(object_name(wep)) + "\t";         /* the file name of the weapon */
            temp += wep->query_name() + "\t";           /* the short name of the weapon */
            temp += wep->weapon_class();           /* the effective wc */
         }
         else
            temp += "null\tnull\tnull\t0";

	
	temp += "\r\n";

      }
   }

  

/* we are going to log to a fixed file now... */
lfile = "mizan.datalogger"; 

/* add a random number just because... we are spreading our log out over
   multiple files to get around a space limitation */
   lfile += random(9);

   lfile = strip_whitespace(lfile);

   log_file(lfile, temp);

   say("The petrified log continues its work.\n");

   remove_call_out("log_SQL_data");
   call_out("log_SQL_data", LOG_SNAP);

   return;
}

/* This function just strips the whitespace out of a string and replaces
 * with _ 
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

/*
 * This function just strips the references off a filename
 * so something that starts off as 'obj/beano.c#90202'
 * becomes just 'obj/beano.c'
 *
 *
 */
strip_references(string str)
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
         
         /* if its a # sign we stop with what we've got. */
         if(letter == "#") break;
         else temp += letter;
      }

      /* we're done. */
      return temp;
   }
}

subzeroes(string str)
{
   string temp, letter;
   int i;
   
   temp = "";                                                                    return temp;
   
   if(!str) return "01";
   else
   {
      for(i = 0; i < strlen(str); i ++)
      {
         letter = extract(str, i, 1);
         
         if(letter == " ") temp += "0";
         else temp += letter;
      }
      
      return temp;
   }
                                                                                       
}


convert_month(arg)
{
   
   if(arg == "Jan") return "01";
   else if(arg == "Feb") return "02";
   else if(arg == "Mar") return "03";
   else if(arg == "Apr") return "04";
   else if(arg == "May") return "05";
   else if(arg == "Jun") return "06";
   else if(arg == "Jul") return "07";
   else if(arg == "Aug") return "08";
   else if(arg == "Sep") return "09";
   else if(arg == "Oct") return "10";
   else if(arg == "Nov") return "11";
   else if(arg == "Dec") return "12";
   else return "01";
  
}
