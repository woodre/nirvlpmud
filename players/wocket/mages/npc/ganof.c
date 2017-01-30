#include "/players/wocket/closed/ansi.h"
inherit "obj/monster.c";

reset(){
set_short(CYN+"Ganof the Scribe"+NORM);
set_name("ganof");
set_level(30);
set_hp(500);
set_wc(50);
set_ac(30);
}

init(){
  add_action("ask","ask");
  add_action("seal_book","seal");
  add_action("borrow","borrow");
  add_action("returning","return");
  add_action("buy","buy");
}

ask(){
say("Ganof whispers silently to "+this_player()->query_name()+".\n");
write("Ganof says, \"I am the scribe of the mages. I can help you with many things.\"\n");
write("Ganof asks, \"What would you like help with: \n"+
      "                'buy'ing 'page's or book 'bindings',\n"+
      "                'seal'ing books,\n"+
      "                'borrow'ing books,\n"+
      "                 or 'return'ing books?\"\n");
return 1;
}

seal_book(str){
object oldbook;
string newbook;
string savetitle;
string text;
int i,a,pagenumber;
object book;
if(!str || str != "book"){
  notify_fail("Ganof says, \"What would you like me to seal?\"\n");
  return 0;
}
oldbook = present("wocketbook",this_player());
if(!oldbook){
  notify_fail("Ganof says, \"You do not have a book I can seal.\"\n");
  return 0;
}
  write("Ganof begins to seal your book.\n");
  write("Ganof binds your book together with twine and magic.\n");
savetitle = oldbook->query_booktitle()+" ";
savetitle = explode(savetitle," ");
savetitle = implode(savetitle,"_");
newbook = "/players/wocket/mages/obj/books/"+savetitle+".c";
if(file_size(newbook) > 0){
  notify_fail("Ganof says, \"There is already a book entitled this. Please change\n"+
              "the title.\"\n");
  return 0;
}
/* changed order of inherit and include to work with LD - miz */
write_file(newbook,"inherit \"/players/wocket/mages/obj/bookobj.c\";\n");
write_file(newbook,"#include \"/players/wocket/closed/ansi.h\"\n");
write_file(newbook,"reset(){\n");
write_file(newbook,"booktitle = \""+oldbook->query_booktitle()+"\";\n");
write_file(newbook,"pagenumber = "+oldbook->query_pagenumber()+";\n");
write_file(newbook,"booktext = ({});\n");
for(i=0,a=oldbook->query_pagenumber();i<a;i++){
text = implode(explode(oldbook->query_booktext(i),"\n"),"\\n");
write_file(newbook,"booktext += ({\""+text+"\"});\n");
}
write_file(newbook,"}");
destruct(oldbook);
  write("Ganof gives you your sealed book.\n");
book = clone_object(newbook);
move_object(newbook,this_player());
return 1;
}

borrow(str){
object bookcase;
object book;
if(!str){
  notify_fail("Ganof asks, \"What would you like to borrow?\"\n");
  return 0;
}
bookcase = present("bookcase",environment(this_object()));
if(!bookcase){
 bookcase = clone_object("/players/wocket/mages/obj/bookcase.c");
 move_object(bookcase,environment(this_object()));
}
book = present(str,bookcase);
if(!book){
  notify_fail("Ganof says, \"I'm sorry but I don't have that to lend.\"\n");
  return 0;
}
write("Ganof reaches up against a bookcase and pulls down "+book->short()+".\n");
write("Ganof hands you "+book->short()+".\n");
write("Ganof says, \"enjoy\"\n");
move_object(book,this_player());
return 1;
}

returning(str){
object bookcase;
object book;
if(!str){
  notify_fail("Ganof asks, \"What would you like to return?\"\n");
  return 0;
}
book = present(str,this_player());
if(!book || !book->query_wocketbook()){
  notify_fail("Ganof says, \"That isn't a book from here.\"\n");
  return 0;
}
write("Ganof takes "+book->short()+" and puts it back on it's shelf.\n");
write("Ganof says, \"I hope you enjoyed it.\"\n");
bookcase = present("bookcase",environment(this_object()));
if(!bookcase){
  bookcase = clone_object("/players/wocket/mages/obj/bookcase.c");
  move_object(bookcase,environment(this_object()));
}
move_object(book,bookcase);
return 1;
}

buy(str){
int cost;
string file;
if(!str){
  notify_fail("Ganof says, \"What would you like to buy?\"\n");
  return 0;
}
if(str != "page" && str != "binding"){
  notify_fail("Ganof says, \"I'm sorry, but I do not have that to sell.\"\n");
}
switch(str){
case "page":  cost = 1000; file = "/players/wocket/mages/obj/blankpage.c"; break;
case "binding": cost = 50000; file = "/players/wocket/mages/obj/book_binding.c"; break;
}
if(this_player()->query_money() < cost){
  notify_fail("Ganof says, \"I'm sorry, but you do not have "+cost+" coins to\n"+
              "buy a "+str+".\"\n");
  return 0;
}
write("Ganof takes your money and hands you a "+str+".\n");
say(this_player()->query_name()+" buys a "+str+".\n");
this_player()->add_money(-cost);
move_object(clone_object(file),this_player());
return 1;
}
