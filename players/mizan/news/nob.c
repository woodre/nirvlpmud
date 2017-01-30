#define MASTER_R          "/players/mizan/news/NDM.c"
#define NEWS_READER_ID    "news_reader_thingy"

int news_index;
string new_hd;
string new_body;

id(str) { return str == "thingy" || str == NEWS_READER_ID; }
short() { return "A news thingy"; }
get() { return 1; }
drop() { return 1; }

query_save_flag() { return 1; }
query_news_index() { return news_index; }
set_news_index(str) { news_index = str; }

init()
{
   add_action("news_post","Np");
   add_action("news_read","Nr");
   add_action("news_delete","Nd");
   add_action("news_headers","Nh");
   add_action("news_grouplist","Nl");
   add_action("news_next_group","Nn");
   add_action("news_goto_group","Ng");
   /* add_action("news_add_group","Na");  I don't know if this works */
   /* add_action("news_delete_group","Nk"); ditto */

}

news_read(str) { return MASTER_R->news_read(str); }
news_delete(str) { return MASTER_R->news_delete(str); }
news_delete_group(str) { return MASTER_R->news_delete_group(str); }
news_add_group(str) { return MASTER_R->news_add_group(str); }
news_headers() { return MASTER_R->news_headers(); }
news_grouplist() { return MASTER_R->news_grouplist(); }
news_next_group() { return MASTER_R->news_next_group(); }
news_goto_group(arg) { return MASTER_R->news_goto_group(arg); }

news_post(str)
{
   if(!MASTER_R->news_post_check(str)) return 1;
   input_to("get_body");
   new_hd = str;
   new_body = "";
   return 1;
}

get_body(str) 
{
   if(str == "**") 
   {
      MASTER_R->news_feed(new_hd,new_body);
      new_body = 0; new_hd = 0;
      return 1;
   }

   if(str == "~q")
   {
      write("\n>> Aborted.\n");
      new_body = 0; new_hd = 0;
      return 1;
   }

   new_body = new_body + str + "\n";
   write("]");
   input_to("get_body");
}

/* fin */
