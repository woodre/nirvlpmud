 
 
 
inherit "obj/armor";
 
 
string TSTR;
int ripped;
reset(arg) {
 
   ::reset(arg);
   if (arg) return;
 
    set_name("tshirt");
    set_alias("shirt");
    set_short("A blank T-shirt");
    set_long("A blank T-shirt\n");
    set_value(10);
    set_weight(1);
    set_ac(0);
    set_type("tshirt");
 
}
 
file(str) {

object catfile;
string who, what;

   if (sscanf(str,"%s %s\n",who,what)) {
      write (what+"\n");
      catfile = read_file(what);
      tell_object(find_player(who),catfile + "\n");
       return 1;
      } else if(sscanf(str,"%s\n",what)) {
        catfile = read_file(str);
        tell_object(this_player(), catfile + "\n");
        return 1;
        }
return 0;
}

paint(str) {
string who;
 
   if (environment(this_object()) != this_player()) return 0;
   if (str == "?") {
      write("paint <string> : paints a string of text onto the T-shirt.\n");
      return 1;
   }
   TSTR=str;
   who = call_other(this_player(), "query_possessive");
   say(call_other(this_player(), "query_name") + " paints "+who+" tshirt\n");
   return 1;
}
 
short() {
string w;
 
   if (query_worn()) w = " (worn)";
   else w = "";
 
 
   if (TSTR && ripped) return "A ripped '"+TSTR+"' t-shirt"+w;
   else if (TSTR && !ripped) return "A '"+TSTR+"' t-shirt"+w;
   else if (!TSTR && ripped) return "A ripped blank t-shirt"+w;
   else return "A blank t-shirt"+w;
 
}
 
long() {
 
   if (TSTR)  {
      write("A T-shirt with the words '"+TSTR+"' painted on it!\n");
      if (ripped) write("It has been tastefully ripped.\n");
      write("(use 'shirt ?' to learn how to use this shirt!)\n");
   } else {
      write("A blank T-shirt... use 'paint ?' to see help message.\n");
      if (ripped) write("It has been tastefully ripped.\n");
   }
   return 1;
}
 
 
init() {
   add_action("paint"); add_verb("paint");
   add_action("file"); add_verb("file");
   add_action("shirt"); add_verb("shirt");
   add_action("rip"); add_verb("rip");
}
 
shirt(str) {
 
   write("rip rips the shirt.\n");
   write("paint <str> paints a string of characters on your shirt.\n");
   return 1;
}
 
rip(str) {
 
   if (!id(str)) return 0;
 
   if (environment(this_object()) != this_player()) return 0;
 
   write("You rip the shirt!\n");
   say(call_other(this_player(), "query_name")+" rips a t-shirt.\n");
   ripped = 1;
   return 1;
}
