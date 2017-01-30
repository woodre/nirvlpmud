/*
 *
 */


/* The log interval is going to be short right now because I want to build
 * up a big dataset quickly.
 */
#define LOG_SNAP        60
#define HOME            "/players/mizan/workroom.c"


id(string str)
{
   return str == "cleaner" || str == "vacuum";
}

short()
{
   return "A vacuum cleaner";
}

long()
{
   write("This is vacuum cleaner. It sucks!\n");
   return;
}

reset(mixed arg)
{
   if(arg) return;
   enable_commands();
   
  call_out("log_SQL_data", 60);
   move_object(this_object(), HOME); 
   return;
}

/*
 * this function does the log work.
 *
 */
log_SQL_data()
{
   object ob;     /* our user array */
   object room;   /* the room the user is in */
   object thing;  /* the object in player inventory */
   int i;         /* the random person in our lottery who gets scanned */
   
   string lfilename;  /* the name of our log file */
   string temp;   /* temp string, constitutes one line of text usually. */
   string ctm;    /* current time (used for table ID purposes)  */
   int debugmode;

   /* a kludge, but assembled together to make ctime() */
   string YYYY;
   string MM;
   string DD;
   string hh;
   string mm;
   string ss;
   string temptime;

   temptime = ctime(time());
   debugmode = 0;

   YYYY = extract(temptime, 20, 23);
   MM = extract(temptime, 4, 6);
   DD = extract(temptime, 8, 9);
   hh = extract(temptime, 11, 12);
   mm = extract(temptime, 14, 15);
   ss = extract(temptime, 17, 18);
   
   ctm = YYYY + "-" + convert_month(MM) + "-" + (DD) + " " + hh + ":" + mm + ":" + ss;

   ob = users();

   temp = "";

   if(sizeof(ob)) { /* added by verte */
   i = random(sizeof(ob));
   
   /*
   if(debugmode && find_player("mizan")) 
      tell_object(find_player("mizan"), "A vacuum cleaner says: I have selected " + ob[i]->query_name() + ".\n");
   */
 
  if(ob[i])
   room = environment(ob[i]);

   /* we dont want to scan wizards. */
   if(room &&
      ob[i] &&
      ob[i]->query_level() <= 19)
    {
      thing = first_inventory(ob[i]);
         

      while(thing)
      {
                     
         /*            
         if(debugmode && call_other(thing, "short") && find_player("mizan")) 
            tell_object(find_player("mizan"), "A vacuum cleaner says " + call_other(thing, "short") + ".\n");
          */
         
         /* we only want people who are logged in */
        
         temp += ctm + "\t";                                /* our timestamp - used as a key */
         temp += ob[i]->query_real_name() + "\t";           /* the real name - used as a key too */
         temp += creator(thing) + "\t";                     /* the creator of the thing */
         temp += strip_references(object_name(thing)) + "\t"; /* the filename of the object sans reference */
         temp += get_references(object_name(thing)) + "\t";   /* our reference number */
         temp += call_other(thing, "query_name") + "\t";    /* the short name of the thing */
         temp += call_other(thing, "query_value") + "\t";   /* the value name of the thing */
         temp += call_other(thing, "weapon_class") + "\t";  /* the effective wc */
         temp += call_other(thing, "armor_class") + "\t";   /* the effective ac */
         temp += call_other(thing, "query_weight") + "\t";  /* the weight of the object */
         temp += call_other(thing, "query_type") + "\t";     /* the armor class of object */
 
         thing = next_inventory(thing);
   
         /* finish off with a line break */
         temp += "\r\n";
          
      }
   }
 



}
/* we are going to log to a fixed file now... */
   lfilename = "mizan.dataloggerobj" + random(9);

   log_file(lfilename, temp);

   say("The vacuum cleaner continues its work.\n");

   remove_call_out("log_SQL_data");
   call_out("log_SQL_data", LOG_SNAP);

   return;
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

get_references(string str)
{
   string temp, letter;
   int i;
   int go;

   temp = "";
   go = 0;

   if(!str) return "";
   else
   {
      for(i = 0; i < strlen(str); i++)
      {
         /* grab a letter */
         letter = extract(str, i, i);
         
         /* if its a # sign we start saving the number. */
         if(letter == "#") go = 1;
         
         if(go && letter !="#") temp += letter;
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
