#include "/players/pestilence/define.h"

status main(string str) {
  object ob;
  if(str){
    notify_fail("Just dlead will work.\n");
    return 0;
  }
if(this_player()->query_guild_rank() < 2){ write("You can't use this yet.\n"); return 1; }
    if(this_player()->query_sp() < 10){
        write("You are to weak.\n");
        return 1;     }
  if(!this_player()->query_attack()) {
    write("You must be fighting to lead!!\n");
    return 1; }
  ob = (object)this_player()->query_attack();
  if(ob->is_player()) {
    write("You cannot use against players.\n");
    return 1; }
  this_player()->add_spell_point(-10);
  ob->attack_object(this_player());
  this_player()->attack_object(ob);
  write("You strive for pain, and begin to take the hits!\n");
  say(TPN+" strives for pain, and begin to take the hits!\n");
  return 1;
}
