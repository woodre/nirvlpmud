#include "/players/francesco/univ/ansi.h"
int current_page;
int total_puzzles;
int total_puzzle_points;
int position;

reset(arg)
{
    if(arg) return;
    current_page = 0;
}

short() { return HIW+call_other(this_player(),"query_name")+"'s puzzle book"+NORM; }


long(str) {
    write("The puzzle book is made by five pages, folded to each other to make it\n"+
          "a compact and fast to use tool.  You may read page 1 through 5.\n");
	return;
    }
    

init() {
    add_action("read_book","read");
}

id(str) { return str == "book" || str == "puzzler"; }


/**   for(i=sizeof(entered)-1;i>=0;i--) 
   {
    if(entered[i]==puzzle_number) return "fuck off"; } 
    return "cool bro";
**/

read_book(stri) {
     if (!stri) {notify_fail("Read what?\n");return 0;}
     if(stri == "page 1") {
     write("        P e r s o n a l   p u z z l e   b o o k   o f   \n\n"+
           "                             "+HIW+call_other(this_player(),"query_name")+NORM+"\n\n");
     return 1; }
     if (stri=="page 2")  {
     write(HIW+"\n        S t a t i s t i c s \n"+NORM+
           "        Puzzles solved up to today are           "+total_puzzles+"\n"+
           "        Puzzle points gained up to today are     "+total_puzzle_points+"\n"+
           "        Position in the all-time list is         "+position+"\n\n");
     return 1; }
     if (stri=="page 3")  {
     write(HIW+"\n        A n s w e r i n g \n"+NORM+
           "        The answers must be given in a simple format like this one:\n"+
           "        'answer #'   Be careful to exactly type your answer.\n"+
           "        Three chances are given to say the right answer.\n\n");
     return 1;  }
     if (stri=="page 4")  {
     write(HIW+"\n        H e l p \n"+NORM+
           "        Each letter means a single cypher \n"+
           "        Different letters mean different cyphers\n"+
           "        Multiple letters together mean a multiple digit number\n"+
           "        examples:    a = 2      b = 3      ba = 32\n\n");
     return 1;  }
     if (stri=="page 5")  {
     write(HIW+"\n        E x a m p l e \n"+NORM+
           "        a + b = c                           1 + 4 = 5\n"+
           "        +   *   +                           +   *   +\n"+
           "        d / a = d    is easily solved by    3 / 1 = 3\n"+
           "        =   =   =                           =   =   =\n"+
           "        b + b = e                           4 + 4 = 8\n"+
           "        note: the operations must be performed either by rows and columns\n\n");
     return 1;  }
     {notify_fail("Read what?\n");return 0;}
}
/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
