#include "/players/francesco/univ/ansi.h"
reset(arg)
{
    if(arg) return;
}
short() { return HIW+call_other(this_player(),"query_name")+"'s puzzle book"+NORM; }
long(str) {
    write("The puzzle book is made by five pages, folded to each other to make it\n"+
          "a compact and fast to use tool.  You may read the various pages.\n");
	return;
    }
init() {
    add_action("read_book","read");
}
id(str){ return (str == "book" || str == "puzzler"); }
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
     write("        S t a t i s t i c s \n");
     return 1; }
     if (stri=="page 3")  {
     write("        A n s w e r \n"+
           "        The answers must be given in a simple format like this one:\n"+
           "        'answer #'   Be careful to exactly type your answer.\n"+
           "        Three chances are given to say the right answer.\n\n");
     return 1;  }
     if (stri=="page 4")  {
     write("        H e l p \n"+
           "        Each letter means a single cypher \n"+
           "        Different letters mean different cyphers\n"+
           "        Multiple letters together mean a multiple digit number\n"+
           "        examples:  a = 2      b = 3     ab = 23\n\n");
     return 1;  }
     if (stri=="page 5")  {
     write("        E x a m p l e \n"+
           "        a + b = c                           1 + 4 = 5\n"+
           "        +   *   +                           +   *   +\n"+
           "        d / a = d    is easily solved by    3 / 1 = 3\n"+
           "        =   =   =                           =   =   =\n"+
           "        b + b = e                           4 + 4 = 8\n"+
           "        (note: the operations must be performed either by rows and columns)\n\n");
     return 1;  }
}
 
