inherit "obj/treasure";
int no_move, wait;
object move;
init() {
   add_action("blah","confide");
   add_action("blah","emergency");
    add_action("blah","gt");
    add_action("blah","guild_tell");
    add_action("blah","guildtell");
    add_action("blah","tell");
    add_action("blah","say");
    add_action("blah","shout");
   add_action("blah","converse");
   add_action("blah","whisper");
   add_action("quit","quit");
  ::init();
 }
reset(arg) {
   if (arg) return;
   wait = 300;
   no_move = time() + wait;
   set_id("stape");
   set_weight(0);
   set_value(0);
}
blah() {
  if (no_move>=time()) {
 say(this_player()->query_name()+" tries to talk but his mouth has been taped shut.\n");
 say(this_player()->query_name()+" says: Mmmmph, Mmmph!\n");
 write("Your mouth is taped shut.  You try to talk but can't.\n");

 }
 if (no_move<time()) {
  destruct(this_object());
 write("The tape biodegrades letting you speak again.\n");
  }
 return 1;
  }
quit() {
  destruct(this_object());
  return 0;
  }
