/*
 *  The ability to set a storable quote.
 *  For version 2.0 of the mini guilds.
 *
 */

Quote(str)  {

  string QUOTE;
  object ob;

  ob = present("base_obj", this_player());

  if(!str)  {
  write("You must type in a quote.\n");
  return 1;
        }
  if(str == "|")  {
    QUOTE = 0;
    ob->set_quote(QUOTE);
    return 1;
        }

  QUOTE = str;
  ob->set_quote(QUOTE);
  write("Your quote is now: "+str+"\n");
  return 1;
        }
