inherit "/players/wizardchild/newsoul/gender.c";
string word;
init_arg(arg) { call_out("set_word",1,arg); }
set_word(str)
{
   int i;
   int l;
   object r;
   word=str;
   l = strlen(word);
   for(i=0;i<l;i++)
   {
      r = clone_object("/players/sado/tailor/pimp_ring.c");
      r->set_letter(extract(word,(l-1)-i,(l-1)-i));
      move_object(r,environment(this_object()));
   }
}
reset(arg)
{
   if(arg) return;
   word="";
}
id(str) { return str == "ringloader"; }
drop() { return 1; }
get() { return 1; }
query_auto_load() { return "/players/sado/tailor/ringloader.c:"+word; }
init() { add_action("slap","slap"); }
slap(str)
{
   object who;
   if(!str) return 0; /* added by verte */
   who=present(str,environment(this_player()));
   if(who && living(who)) {
      if(who == this_player()) {
         write("You "+word+" slap yourself unconscious.\n");
         say(this_player()->query_name()+" reels after "+word+"-slapping "+noun()+"self.\n");
         weltify(who);
         return 1;
      }
      write("You reach out and lay a four-ringed "+word+" slap on "+who->query_name()+".\n");
      tell_object(who,this_player()->query_name()+" reaches out and lays a four-ringed "+word+" slap on you.\n");
      say(this_player()->query_name()+" slaps "+who->query_name()+" around the room.\n",who);
      weltify(who);
      return 1;
   } else {
      who = find_player(str);
      if(!who || who->query_invis() >= 20) {
         write("That player is not logged in.\n");
         return 1;
        }
      if(in_editor(who) || who == this_player()) {
         write("That player is not available.\n");
         return 1;
        }
      tell_object(who,this_player()->query_name()+" lays a four-ringed "+word+" slap on you from afar.\n");
      write("You reach way out and lay a four-ringed "+word+" slap on "+who->query_name()+".\n");
      weltify(who);
      return 1;
   }
}
weltify(who)
   {
   object w;
  if(!present("welt", who)) {
   w = clone_object("/players/sado/tailor/welt.c");
   w->init_bruise(word);
   move_object(w,who);
 }
}

query_weight() { return 5; }
