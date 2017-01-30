
query_auto_load() { return "players/eurale/closed/sore_throat:"; }

id(str) { return str == "throat_curse"; }

long() { write("How can you look at a cursed throat?\n"); }

drop() { return 1; }

init() {
  add_action("nothing","form");
  add_action("no_talk","party say");
  add_action("no_talk","shout");
  add_action("no_talk","gossip");
  add_action("no_emote","gossip :");
  add_action("no_talk","stt");
  add_action("no_emote","ste");
  add_action("no_emote","emote");
  add_action("no_emote","farem");
  add_action("no_talk","risque");
  add_action("no_talk","say");
  add_action("no_talk","'");
}

nothing() {
  write("You feel too weak to do that right now.\n");
  return 1; }

no_talk() {
	write("You can't talk with a sore throat!\n");
	say(call_other(this_player(), "query_name") +
	    " makes croaking sounds.\n");
   this_player()->heal_self(-random(20));
return 1; }

no_emote() {
  write("You don't feel well enough to do that now..\n");
  say(call_other(this_player(),"query_name")+
    " looks very peeked and pale...\n");
  this_player()->heal_self(-random(20));
return 1; }

short() { return "A sore throat"; }
