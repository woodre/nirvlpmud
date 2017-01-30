#define EP environment(this_player())
#define RING "/players/cosmo/closed/ring.c"

id(str) { return str == "wedder"; }
reset(arg) { if(arg) return; }
short() { return("A wedding performer [wedder]"); }
long() { write("Usage: marry <who1> <who2>\n"); }
init() { add_action("wed","marry"); }

wed(str) {
string who1,who2;
object me,you;
object r1,r2;
  if(sscanf(str,"%s %s",who1,who2) != 2) {
    write("Usage: marry <who1> <who2>\n");
    return 1;
  }
  me = present(who1,EP);
  you = present(who2,EP);
  if(!me || !you){
    write("The spouses aren't present!\n");
    return 1;
  }
  r1 = clone_object(RING);
  r2 = clone_object(RING);
  r1->set_spouse(who2);
  move_object(r1,me);
  r2->set_spouse(who1);
  move_object(r2,you);
  tell_object(me,"... I now pronounce you man and wife.\n");
  tell_object(you,"... I now pronounce you man and wife.\n");
  write("You may kiss the bride.\n");
  return 1;
}
