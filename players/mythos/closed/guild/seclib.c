#include "/players/mythos/closed/guild/def.h"
int q,w,e,r,t,y;
int a,s,d,f,g,h;
inherit "room/room";
reset(arg) {
   q = w = e = r = t = a = s = d = 0;
  if(!arg) {
  set_light(1);
    short_desc = "Dark Room ";
    long_desc =
    "You have entered the Library Annex, where all the rare and\n"+
    "important books are kept.  Here the 'books' written by the\n"+
    "Hunter and his apprentices are kept.\n";
  items = ({
    "books","You may look at what books exist by looking at the 'titles'",
    "titles","Try typing 'titles'",
  });

} }
realm() {return "NT"; }
init() {
  ::init();
  this_player()->set_fight_area();
  add_action("push","push");
  add_action("back","back");
  add_action("titles","titles");
  add_action("read","read");
  add_action("search","search");
  add_action("book_return","return");
}

back() {
  write("You slowly push past the secret door and step into the Library.\n");
  move_object(this_player(),"/players/mythos/lroom/library3.c");
  return 1;}

search() {
  write("You notice one of the 'bookcase's is a bit loose.\n"+
       "Perhaps 'push'ing it might do something.\n");
       return 1;}

push(str) {
if(!str) {write("What?\n"); return 1;}
if(str=="bookcase") {
  write("You push the bookcase and step into the guild hall.\n");
  move_object(this_player(),"/players/mythos/closed/guild/hall.c");
  command("look",this_player());
  return 1;}
  write("What?\n");
  return 1;}

titles() {
  write("The following books may be 'read':\n\n"+
    "\t\tgrimoire  law  chronicles  bindings  fragments");
    write("\n\t\tblood");
 write("  dread");
write("  damned");
  write("\n");
  return 1;}

read(str) {
object book;
int last, lnt;
  if(!str) return 0;
  if(str != "grimoire" && str != "chronicles" && str != "law" &&
     str != "bindings" && str != "fragments" && str != "blood" &&
     str != "damned" && str != "dread") {
    write("That title does not exist.\n");
  return 1;}
  if((str == "grimoire" && q) || (str == "chronicles" && w) ||
      (str == "law" && e) || (str == "bindings" && r) ||
      (str == "fragments" && t) || (str == "blood" && a) ||
      (str == "damned" && s) || (str == "dread" && d)) {
    write("That book is out.\n"); return 1;}
  if(str == "grimoire" && !q ) { last = 6; q = 1; lnt = 0;}
  if(str == "chronicles" && !w ) { last = 4; w = 1;lnt = 0;}
  if(str == "law" && !e ) { last = 3; e = 1;lnt = 0;}
  if(str == "bindings" && !r) { last = 3; r = 1; lnt = 0;}
  if(str == "fragments" && !t) { last = 3; t = 1; lnt = 0;}
  if(str == "blood" && !a) { last = 3; lnt = 0; a = 1; }
  if(str == "damned" && !s) { last = 3; lnt = 0; s = 1; }
  if(str == "dread" && !d) { last = 3; lnt = 0; d = 1; }
    book = clone_object("/players/mythos/closed/guild/books/book.c");
    book->set_cond(0);
    book->set_title(str);
    book->set_last(last);
    book->set_not(lnt);
    move_object(book,tp);
  write("You pull a book from the bookcase.\n");
  write("You must 'return <title>' after you are done.\n");
  say(capitalize(tpn)+" takes a book from the bookcase.\n");
return 1; }

book_return(str) {
  if(!str) return 0;
  if(str != "grimoire" && str != "chronicles" && str != "law" &&
   str != "bindings" && str != "fragments" && str != "blood" &&
   str != "dread" && str != "damned") {
    write("That title does not exist.\n");
  return 1;}
  if(!present(str,tp)) { write("You do not have that to return.\n"); return 1;}
    if(str == "grimoire") { q = 0; }
    if(str == "chronicles") { w = 0; }
    if(str == "law") { e = 0; }
    if(str == "bindings") { r = 0; }
    if(str == "fragments") { t = 0; }
    if(str == "blood") { a = 0; }
    if(str == "damned") { s = 0; }
    if(str == "dread") { d = 0; }
  write("You return the "+capitalize(str)+".\n");
  destruct(present(str,tp));
  say(capitalize(tpn)+" returns a book to the bookcase.\n");
return 1; }

