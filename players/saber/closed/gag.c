#define tp this_player()->query_name()
#define DECAY_TIME   250
int decay;
id(str) { return str == "gag"; }
long() {
 write("A gag for annoying players.\n");
}
short() { write("A gag\n");
}
query_value() {
  return 0;
}
query_weight() {
  return 1;
}
drop() {
return 1;
}
reset() {set_heart_beat(1);
decay = DECAY_TIME;
}
heart_beat(){
decay -= 1;
if (decay > 0)
return;
destruct(this_object());
write("The blue magic fades.\n");
say("The blue magic fades.\n");
}

init() {
add_action("shout","shout");
add_action("say","say");
add_action("gossip","gossip");
add_action("whisper","whisper");
add_action("tell","tell");
add_action("kick","kick");
add_action("puke","puke");
add_action("risque","risque");
add_action("dose","dose");
add_action("emote","emote");
add_action("spit","spit");
add_action("not","bdt");
add_action("not","bbc");
add_action("rock","rock");
add_action("pester","pester");
add_action("bonk","bonk");
add_action("hug","hug");
add_action("tickle","tickle");
add_action("move","move");
add_action("rt","rt");
add_action("help","help");
add_action("transfer","transfer");
add_action("goose","goose");
add_action("ride","ride");
add_action("cuff","cuff");
add_action("order","order");
add_action("buy","buy");
add_action("quit","quit");
add_action("who","who");
add_action("push","push");
add_action("bop","bop");
add_action("bite","bite");
add_action("list","list");
add_action("moon","moon");
add_action("burp","burp");
add_action("be","be");
add_action("think","think");
add_action("fart","fart");
add_action("re","re");
add_action("thwap","thwap");
#ifndef __LDMUD__
  add_action("communicate"); add_xverb("");
#else
  add_action("communicate", "", 3);
#endif
add_action("equip","equip");
add_action("emergency","emergency");
add_action("wiz","wiz");
add_action("te","te");
add_action("tf","tf");
add_action("chomp","chomp");
}
