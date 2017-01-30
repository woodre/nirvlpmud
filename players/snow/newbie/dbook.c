#define BOOK "/players/snow/newbie/book.c"

id(str) { return str == "book"; }
 
short() { return "A NEW newbie book"; }
 
long()  {
write(
"<***********************************************************************>\n");
  write("This is your NEW newbie book! To use, type:\n");
  write("\n");
  write("read index   <for an index>\n");
  write("or\n");
  write("read page #   <the # is the page number you want to read>\n");
  write("Example: read page 1\n");
write(
"<***********************************************************************>\n");
    }
 
can_put_and_get() { return 0; }
 
get() { return 1; }
 
query_weight() { return 0; }
 
query_value() { return 0; }
 
init() {
add_action("read","read");
add_action("drop_object","drop");
   }

read(arg) { BOOK->read(arg); return 1; }
drop_object(str) {
    if (str == "all") {
        drop_object("book");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The NEW Newbie Book disappears as it touches the ground.\n");
    destruct(this_object());
    return 1;
}
