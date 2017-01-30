#include "/players/cosmo/closed/ansi.h"
#define tp this_player()->query_name()
#define prez "cosmo"

id(str) {
    return str == "shirt";
}

reset(arg) {
  if(arg) return;
}

long() {
    write(GRN+"The front of the shirt reads "+HIY+"DISGRUNTLED "+GRN+"in large\n");
    write("bold print.  On the back you see:\n"+NORM);
    write("\n");
    write("     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    write("     |"+BGRN+HIY+"     Dissed                         "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     In                             "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Sexual                         "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Gratification,                 "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Repulsed by                    "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Ugly                           "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Newlyweds,                     "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Tends to                       "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Let                            "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Every                          "+NORM+"|\n");
    write("     |"+BGRN+HIY+"     Drunk know his feelings.       "+NORM+"|\n");
    write("     |"+BGRN+HIY+"                                    "+NORM+"|\n");
    write("     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
    write("Type "+BOLD+"dislist "+NORM+"for available commands.\n");
}

short () {return (GRN+"A "+HIY+"DISGRUNTLED "+GRN+"T-shirt"+NORM);}
drop() {return 1;}
get() { return 0; }


query_auto_load() {
    return "/players/cosmo/closed/disbtn.c:";
}

init() {
  add_action("dislist","dislist");
  add_action("dissed","dissed");
  add_action("grunt","grunt");
add_action("dismiss","dismiss");
  if(this_player()->query_real_name() == prez) {
  add_action("disnew","disnew");
  }
}

dislist() {
   write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
   write("-------> Available commands for DISGRUNTLED members <-------\n\n");
   write("   dissed\n");
   write("   disnew <name>\t[President only]\n");
   write("   dismiss\t[Rid yourself of this foolish T-shirt]\n\n");
   write("More commands to come later.  Mail ideas to Cosmo.\n\n");
   write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  return 1;
}

dissed () {
  write("You walk around the room in disgust, feeling very disgruntled.\n");
  say(capitalize(tp)+" hangs his head as he paces the room with a "+ 
   "disgruntled look.\n");
  return 1;
}

grunt () {
  return 1; }

dismiss() {
   write("You rip your shirt to shreds and vow to never feel disgruntled again.\n");
   destruct(this_object());
   return 1;
}

disnew(str) {
object shirt, target;
target = find_player(str);
if(!target) { write("No one on with that name.\n"); return 1; }
if(target->query_gender() != "male") {
   write("DISGRUNTLED is a male-only club!!\n");
   return 1; }
shirt = clone_object("players/cosmo/closed/disbtn.c");
move_object(shirt,target);
tell_object(target, capitalize(prez)+", the DISGRUNTLED king, has made you an "+
   "official member.\n"); 
write("You gave "+capitalize(str)+" an official DISGRUNTLED T-shirt.\n");
return 1;
}
