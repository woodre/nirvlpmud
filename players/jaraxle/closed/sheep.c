/* This is adapted from Sandman's basic pet code for a skeleton
and highly modified by me.  Jaraxle 5/7/02 */
   
/* This is for China to play with, you don't like it - too fucking bad.  */

#include "/players/jaraxle/define.h"
inherit "obj/monster";
is_pet() { return 1; }
object owner;
reset(arg) {
   if (arg) return;
   set_alias("sheep");
   set_name("sheep");
   set_gender("female");
   set_level(1);
   set_hp(1);
   set_wc(8);
   set_ac(1);
    set_chat_chance(8);
    load_chat("The sheep goes, 'Baa'\n");
    load_chat("The sheep looks around the room\n");
    load_chat("The sheep rubs up against you.\n");
    load_chat("The sheep's eyes look glazed over.\n");
    load_chat("The sheep goes, 'Baa'\n");
    load_chat("The sheep winks at you.\n");
   enable_commands();
}
short(){ return HIW+"A sheep"+NORM; }
   long(){
      write("A furry, cuddly sheep.\n"+
         "Perfect for "+HIW+"banging"+NORM+".\n");
   }
   id(str) { return str == "sheep" || str == "a sheep" || str == "farm animal"; }
   patch_owner(o) { owner = o; }
   
   
   add_weight(){
      write("What?\n");
      return 0; }
   
   init() {
      ::init();
      add_action("bang","bang");
      add_action("name","name");
      add_action("free","free");
   }
   
   bang(str) {
      object target;
      if (!str) return 0;
      if(str != "sheep"){ write("Bang what?\n"); return 1; }
      say(TPN+" begins to bang on the sheep.\n"+
         "\t"+TPN+" works the sheep real good, sweating...\n"+
         "\t\tpanting, as the sheep bucks against "+TPN+".\n");
      return 1; }
   
   
free(str){
  if(str != "sheep"){ notify_fail("Free what?\n"); return 0; }
   if(!str){ notify_fail("Free what?\n"); return 0; }
      if (!check_ok()) return 0;
      write("You let your sheep go home.\n");
      destruct(this_object());
      return 1; }
   
   check_ok() {
      if (!owner) owner = this_player();
      if (this_player() != owner) {
         tell_object(owner, this_player()->query_name()+" is trying "+
            "to command your sheep.\n");
         return 0;
}
      if(this_player()->query_ghost()) {
         write("You are a ghost!\n");
         return 0; }
      return 1;
   }
   
   heart_beat() {
  if(!owner || (owner && owner->query_ghost())) { destruct(this_object()); return 1; }
      if (environment(this_object()) != environment(owner)) {
         tell_room(environment(this_object()), this_object()->query_name()+
           " waddles away.\n");
        tell_room(environment(owner), this_object()->query_name()+
           " waddles in.\n");
         move_object(this_object(),environment(owner));
      }
   }
   
