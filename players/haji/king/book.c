id() {return "book";}

short() {return "A joke book";}

long() {return "The jester's book of jokes.\n";}

query_value() {return 100;}

query_weight() {return 2;}


get() {return 1;}

drop() {return 1;}


init() {
   add_action("read", "read");
  }
read(str) {
  if(str!="book") {
    write("Read the BOOK!!!\n");
    return 1;
    }
  write("You open up the book and read...\n");
  write("What is 9 x 6?\n");
  write("The meaning of life!!!\n");
  write("You can't make out the rest of the writing.\n");
  return 1;
  }
reset(arg) {}
