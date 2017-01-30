#define tp this_player()->query_name()
id(str) {return str == "emoter"; }
 short() {return "An emoter"; }
   long() { write (
 "An emoter - type emote <blah blah> to use\n");
      }
   get() { return 1; }
   query_weight() { return 0; }
   query_value() { return 0; }

init() {
   add_action ("emote", "emote");
}
static emote(str) {
   if (!str) {
  write ("emote?\n");
return 1;
}
 say(tp+" "+str+" \n");
  write ( "You emote: "+tp+" "+str+" \n");
return 1;
}
