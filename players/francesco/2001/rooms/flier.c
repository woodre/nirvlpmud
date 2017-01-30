#include "/players/francesco/univ/ansi.h"
int current_page;

reset(arg)
{
    if(arg) return;
    current_page = 0;
}
short() { return HIW+call_other(this_player(),"query_name")+"'s puzzle book"+NORM; }
long(str) {
    write("The puzzle book is made by four pages, folded to each other to make it\n"+
          "a compact and fast to use tool.  You may read the various pages.\n");
	return;
    }
init() {
    add_action("read_book"); add_verb("read");
}
id(str) { return str == "book" || "puzzler"; }
read_book(stri) {
      if (!stri)
      {
      write("Read what?\n");
      return 1;
      }
     if(stri == "page 1") {
     write("        P e r s o n a l   p u z z l e   b o o k   o f   \n\n"+
           "                             "+HIW+call_other(this_player(),"query_name")+NORM+"\n\n");
     return 1; }
     if (stri=="page 2")  {
     return 1; }
     if (stri=="page 3")  {
     write("        H e l p \n"+
           "        Each letter means a single cypher \n"+
           "        Different letters mean different cyphers\n"+
           "        Multiple letters together mean a multiple digit number\n"+
           "        examples:  a = 2      b = 3     ab = 23\n");
     return 1;  }
     if (stri=="page 4")  {
     write("        E x a m p l e \n"+
           "        a + b = c                           1 + 4 = 5\n"+
           "        +   *   +                           +   *   +\n"+
           "        d / a = d    is easily solved by    3 / 1 = 3\n"+
           "        =   =   =                           =   =   =\n"+
           "        b + b = e                           4 + 4 = 8\n"+
           "        (note: the operations must be performed either by rows and columns)\n");
     return 1;  }
     }
