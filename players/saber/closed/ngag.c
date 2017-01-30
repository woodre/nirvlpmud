#define tp this_player()->query_name()
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
reset()  {
call_out("go_away",300);
}

go_away()  {
destruct(this_object());
write("The Crimson Magic fades.\n");
say("The Crimson Magic fades.\n");
}

init() {
add_action("nope","shout");
add_action("nope","gossip");
add_action("nope","tell");
add_action("nope","kick");
add_action("nope","puke");
add_action("nope","risque");
add_action("nope","dose");
add_action("nope","emote");
add_action("nope","spit");
add_action("nope","rock");
add_action("nope","pester");
add_action("nope","bonk");
add_action("nope","hug");
add_action("nope","tickle");
add_action("nope","move");
add_action("nope","rt");
add_action("nope","help");
add_action("nope","transfer");
add_action("nope","goose");
add_action("nope","ride");
add_action("nope","cuff");
add_action("nope","order");
add_action("nope","buy");
add_action("nope","quit");
add_action("nope","who");
add_action("nope","push");
add_action("nope","bop");
add_action("nope","bite");
add_action("nope","list");
add_action("nope","moon");
add_action("nope","burp");
add_action("nope","be");
add_action("nope","think");
add_action("nope","fart");
add_action("nope","re");
add_action("nope","thwap");
add_action("nope","equip");
add_action("nope","emergency");
add_action("nope","wiz");
add_action("nope","te");
add_action("nope","tf");
add_action("nope","chomp");
add_action("nope","score");
add_action("nope","score2");
add_action("nope","sco");
add_action("nope","sc2");
add_action("nope","sc");
add_action("nope","bt");
add_action("nope","bte");
add_action("nope","bising");
add_action("nope","bsing");
add_action("nope","ayre");
add_action("nope","know");
add_action("nope","ele");
add_action("nope","monitor");
}

nope()  {
 write("You can not do that, as you are bound by Crimson Magic...\n");
  return 1;
        }
