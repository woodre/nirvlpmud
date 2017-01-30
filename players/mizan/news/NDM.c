/* News Server, based on original bulletin board. Heavily modified by Mizan.
 *
 * Note that you need to adapt this to your requirements.
 *
 * tij@beanos.com
 */ 

#define HOME              "/players/mizan/workroom"
#define NEWSFILE          "players/mizan/news/NEWSFILE"
#define NEWS_READER_ID    "news_reader_thingy"


string news_group;      /* [ARRAY] News stuff - used to store array of all topics */
string messages;        /* [ARRAY] News stuff - used to store array of all messages */
int num_messages;       /* [ARRAY] Used to store message counts */

short() { return "A soggy pile of newspaper"; }

long()
{
   write("This is a massive pile of soggy newspaper rolls.\n");
}
reset(arg)
{
   move_object(this_object(), HOME);
   if(!arg) loadnews();
}

/* ---- [NEWS READER STUFF] 8< cut here--- */

loadnews() 
{
   if(!restore_object(NEWSFILE)) 
   {
      news_group = allocate(5);
      news_group[0] = "test.announce";
      news_group[1] = "test.general";
      news_group[2] = "test.ideas";
      news_group[3] = "test.else";

      /* Last group reserved for hilev guild + */
      news_group[4] = "sys.command";
      
      num_messages = allocate(5);
      messages = allocate(5);
      messages = ({"","","",""});
      save_object(NEWSFILE);
   }
   
}

news_grouplist() 
{
   int i;
   write("You study your lump of clay and some words appear on it:\n"+
      "\n>> Current available groups:\n\n");
   while(i < sizeof(news_group)) {
      if(i == (sizeof(news_group) - 1) && this_player()->query_level() < 20) break;
      write(" (" + (i + 1) + ")\t[" + news_group[i] + "] (" + num_messages[i] + ") messages.\n");
      i++;
   }
   return 1;
}


news_headers() 
{
   string hd, body, rest;
   int i,indx,tmp;
   i = 1;
   indx = index_number();
   if(!num_messages[indx])
   {
      write("\n>> [" + news_group[indx] + "] is empty.\n");
      return 1;
   }
   rest = messages[indx];
   write("\n>> Postings in group [" + news_group[indx] + "]:\n");
   
   while(rest != 0 && rest != "") 
   {
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
      
      if(tmp != 2 && tmp != 3) 
      {
         write("\n>> File corrupted.\n");
         return;
      }
      write(i + ":\t" + hd + "\n");
      i += 1;
   }
   return 1;
   
}

news_read(str) 
{
   string hd, body, rest;
   int i,indx,tmp;
   
   if(str == 0 || sscanf(str, "%d", i) != 1) return 0;
   
   indx = index_number();
   
   if(i > num_messages[indx]) 
   {
      write("\n>> There are only (" + num_messages[indx] +") messages.\n");
      
      return 1;
   }
   
   rest = messages[indx];
   
   while(rest != 0 && rest != "") 
   {
      i -= 1;
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);

      if (tmp != 2 && tmp != 3) 
      {
         write("Corrupt.\n");
         return;
      }

      if (i == 0) 
      {
         write("\n>> The message is titled '" + hd + "':\n\n");
         write(body);
         write(">> End of message (" + str + ").\n");
         return 1;
      }
   }
   write("\n>> Hm. This should not happen.\n");
}

news_delete(str,arg) 
{
   string hd, body, rest;
   int i,indx,tmp;
   if(str == 0 || sscanf(str, "%d", i) != 1) return 0;
   indx = index_number();

   if(i > num_messages[indx]) 
   {
      write(">> There are only [" + num_messages[indx] +"] postings.\n");
      return 1;
   }

   rest = messages[indx];
   messages[indx] = "";
   
   while(rest != 0 && rest != "") 
   {
      i -= 1;
      tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
      if (tmp != 2 && tmp != 3) 
      {
         write("\n>> File corrupted.\n");
         return;
      }

      if (i == 0) 
      {
         if(!arg) write("\n>> Done.\n");
         messages[indx] = messages[indx] + rest;
         num_messages[indx] -= 1;
         save_object(NEWSFILE);
         return 1;
      }
      messages[indx] = messages[indx] + hd + ":\n**\n" + body + "\n**\n";
   }
   write("\n>> Hm. This should not happen.\n");
}


index_number() 
{
   object gob;
   int i;
   gob = present(NEWS_READER_ID, this_player());
   if(!gob) return 0;
   i = gob->query_news_index();
   
   if(i >= sizeof(news_group)) 
   {
      i = 0;
      gob->set_news_index(i);
   }
   return i;
   
}

news_next_group() 
{
   object gob;
   int i,max;

   gob = present(NEWS_READER_ID, this_player());
   if(!gob) return 0;
   
   i = index_number();
   i++;
   if(i == (sizeof(news_group) - 1) && 
      this_player()->query_level() < 20) i = 0;
   if(i >= sizeof(news_group)) i = 0;
   gob->set_news_index(i);
   write("\n>> Switching to group [" + news_group[i] + "], (" +
      
      num_messages[i] + ") messages.\n");
   return 1;
}

news_post_check(hd) 
{
   int indx;
   indx = index_number();
   
   if(!hd) 
   {
      write(">> You must give a header.\n");
      return 0;
   }
   
   if(num_messages[indx] == 25) 
   {
      news_delete("1","silent");
      return 1;
   }

   if(strlen(hd) > 50) 
   {
      write("\n>> The header is too long.\n");
      return 0;
   }
   
   write("\n>> Posting to [" + news_group[indx] + "]:\n");
   write(">> Give message, ** to finish, ~q to abort.\n");
   return 1;
}

news_feed(arg,str) 
{
   
   object gob;
   string new_hd;
   int indx;
   indx = index_number();
   gob = present(NEWS_READER_ID, this_player());

   if(this_player()->query_invis() && 
      this_player()->query_real_name() == "mizan")
      new_hd = "[Spuck, " + ctime(time()) + "]  " + arg;
   new_hd = "[" + capitalize(this_player()->query_real_name()) +
   ", " + ctime(time())+ "]  " + arg;
   
   if(gob && gob->query_sig())
      messages[indx] = messages[indx] + new_hd + ":\n**\n" + str + "\n" +
   (gob->query_sig()) + "\n\n**\n";
   else
      messages[indx] = messages[indx] + new_hd + ":\n**\n" + str + "\n**\n";

   num_messages[indx] += 1;
   save_object(NEWSFILE);
   write("\n>> Message posted.\n");

   if(gob && gob->query_news_announce())

/* TODO - adapt this to your needs.
      if(indx != (sizeof(news_group) -1))
   guild_tell(":has completed a news message in [" + news_group[indx] + "]."); 
   else write("Announce message muffled due to newsgroup type.\n");
*/

   return 1;
}

news_goto_group(arg) 
{
   object gob;
   int i;
   gob = present(NEWS_READER_ID, this_player());
   if(!arg) return 0;
   if(!gob) return 0;
   if(sscanf(arg, "%d", i) != 1) return 0;
   i--;

   if(i < 0 || i > sizeof(news_group)) 
   {
      write(">> Invalid newsgroup number.\n");
      return 1;
   }
   
   if(this_player()->query_level() < 20 &&
         i == (sizeof(news_group) - 1)) 
   {
      write(">> Invalid newsgroup number.\n");
      return 1;
   }
   
   write(">> Going to news group [" + news_group[i] + "], (" + num_messages[i] + ") messages.\n");
   gob->set_news_index(i);
   return 1;
}

news_add_group(str) 
{
   string msgtmp,grptmp;
   int numtmp;
   int i;
   if(!check_level(5)) return 1;

   if(strlen(str) > 30) 
   {
      write(">> That header name is too long. 30 characters or less.\n");
      return 1;
   }
   
   msgtmp = messages;
   numtmp = num_messages;
   grptmp = news_group;
   messages = allocate(sizeof(msgtmp + 1));
   num_messages = allocate(sizeof(numtmp + 1));
   news_group = allocate(sizeof(grptmp + 1));
   while(i < sizeof(messages)) 
   {
      if(i == (sizeof(messages) - 2)) 
      {
         messages[i] = "";
         news_group[i] = str;
         messages[i+1] = msgtmp[i];
         news_group[i+1] = grptmp[i];
         num_messages[i+1] = numtmp[i];
         break;
      }
      else
      {
         messages[i] = msgtmp[i];
         news_group[i] = grptmp[i];
         num_messages[i] = numtmp[i];
      }
      i++;
   }
   write(">> New newsgroup formed.\n");
/* TODO: adapt this to your needs
   guild_tell(": has created a new newsgroup [" + str + "]!\n");
 */
   save_object(NEWSFILE);
   return 1;
}

news_delete_group(str) 
{
   string msgtmp, grptmp;
   string tmp;
   int numtmp, sel, i;
   if(!check_level(5)) return 1;
   if(sscanf(str, "%d", sel) != 1) return 0;
   if(sel == sizeof(news_group)) return 0;

   if(sel < 4) 
   {
      write(">> You cannot delete that newsgroup.\n");
      return 1;
   }

   if(num_messages[sel]) 
   {
      write(">> That newsgroup is not empty!\n");
      return 1;
   }
   msgtmp = messages;
   grptmp = news_group;
   numtmp = num_messages;
   tmp = news_group[(sel - 1)];
   messages = allocate(sizeof(msgtmp - 1));
   news_group = allocate(sizeof(grptmp - 1));
   num_messages = allocate(sizeof(numtmp - 1));
   while(i < sizeof(messages)) 
   {
      if(i == sizeof(messages)) 
      {
         messages[i] = msgtmp[i + 1];
         news_group[i] = grptmp[i + 1];
         num_messages[i] = numtmp[i + 1];
         break;
      }
      else
      {
         messages[i] = msgtmp[i];
         news_group[i] = grptmp[i];
         num_messages[i] = numtmp[i];
      }
      i++;
   }
   write(">> Deletion successful.\n");
/* TODO: Adapt this to your needs
   guild_tell(": has deleted newsgroup [" + tmp + "]!\n");
 */
   save_object(NEWSFILE);
   return 1;
}
