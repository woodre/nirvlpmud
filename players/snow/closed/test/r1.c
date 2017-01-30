inherit "/room/room.c";
#include "/players/snow/closed/color.h"

string *ppl;

reset(arg) {
  ppl = ({});
  if(!arg) {
  set_light(1);
  short_desc="Preparation Chamber";
  long_desc="\tYou are in the Chamber of Preparation.\n"+
    "This is where adventurers willing to take the Elemental Test take\n"+
    "last breaths. If you are willing to take the test, understanding\n"+
    "that you may very well die, ENTER.\n"+
    "\nTo see a list of warriors who have completed the Test, type 'warriors'\n";
  dest_dir=({"/players/snow/gate","back"});
}}

init() {
#if 0
if ((int)this_player()->query_level() > 19) return;
write("This is offlimits for now.  Go actually test something instead.\n");
move_object(this_player(), "/room/vill_green");
return;
#endif
  ::init();
  tell_object(this_player(),
    RED+"\n! ! WARNING ! ! THIS IS A VERY DANGEROUS AREA ! !\n\n"+OFF);
  add_action("show_warriors", "warriors");
  add_action("test_enter","ENTER"); }

/* fixed by vert */
show_warriors() {
  string pth; int line;
  pth="/players/snow/closed/test/complete";

  while(cat(pth, line, 20) != 0)
    line+=20;
  write("\n"); return 1; }

test_enter() {
  object boo, hoo, ohno;
  hoo = this_player();
  if(member_array(hoo->query_real_name(), ppl) != -1) {
    write("You have recently started the Elemental Test.\nGo do something else for a while.\n");
    return 1;
  }
  if(hoo->query_level() > 19 && hoo->query_level() < 100) {
    write("Wizzes cannot take the Test.\n"); return 1; }
  if(hoo->query_level() < 19) {
    write("You are too low level to attempt the Elemental Test.\n"); return 1; }
  boo = clone_object("/players/snow/closed/test/room.c");
  ohno = clone_object("/players/snow/closed/test/granite.c");
  boo->set_short("THE ELEMENTAL TEST");
  boo->set_long("You have begun the Elemental Test.\n"+
    "You may not leave until you have won. If you quit, your\n"+
    "equipment will be lost. Good luck.\n");
  move_object(hoo,boo);
  move_object(ohno,boo);
  command("look",hoo);
  ppl += ({ hoo->query_real_name() });
  ohno->set_testvic(this_player());
  write_file("/players/snow/closed/test/log",ctime(time())+
    " "+this_player()->query_real_name()+" began the test.\n");
  return 1; }
