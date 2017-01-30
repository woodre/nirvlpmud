id(str) { return str == "obelisk"; }
short() {return "A mystic Obelisk"; }
long() {
  write("This is a mystic device of communication to Snow.\n"+
        "To give any comments, suggestions, complaints-\n"+
        "You must: snowcom <message>\n"+
        "Example: snowcom I think your realm is great!\n");
return 1;
    }


init() {

add_action("snowcom","snowcom");

   }

snowcom(arg)  {
if(!arg) { write("snowcom <message>\n"); return 1; }
else
if(find_player("snow"))
  tell_object(find_player("snow"),this_player()->query_real_name()+
    " - SNOWCOM: "+arg+".\n");

write_file("/players/snow/log/com",ctime(time())+" "+
      this_player()->query_real_name()+" says: "+arg+"\n");
   write("Your message will be received, thank you.\n");
return 1;

  }
