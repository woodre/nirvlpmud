inherit "obj/treasure";
init() {
  add_action("open","open");
  add_action("open","read");
  ::init();
}
reset(arg) {
   if (arg) return;
    set_id("cal_hob_books");
    set_short("A vintage collection of Calvin and Hobbes books");
   set_alias("books");
   set_weight(2);
   set_value(30000);
set_long("This is the collection of Calvin and Hobbes books the sage of ReesePort\nhas been looking for.\n");
}
open(str) {
  if (str=="book" || str=="books") {
    write("The books are sealed in a HEAVY coat of Mylar and cannot be opened to\nbe read.\n");
    return 1;
    }
return 0;
}

query_save_flag() { return 0; }
