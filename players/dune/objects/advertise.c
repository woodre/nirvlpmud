  get() { return 1; }
  query_weight() { return 0; }
  query_value() { return 0; }

id(str) { return str == "manual"; }

short() { return "Manual of Elements"; }
long() {
  sign_disp();
}

init() {
  add_action("read","read");
}

read (str) {
  if(!str || str != "manual") return 0;
  sign_disp();
  return 1;
}

sign_disp() {
  write("You open the Manual of Ever-Changing Color\n"+
        "and read the following:\n\n"+
  "          E L E M E N T A L    T O W E R\n"+
  "     A place of bedazzlement and godly aggressors.\n"+
  "Thou must see it for thineself to believe it.\n"+
  "From the church, go: s, 4w, 2n, e, 2n.\n"+
  "THE BOSS MONSTERS NOW HAVE REALLY NEAT ITEMS\n\n"+
  "When you finish reading, the book changes colors\n"+
  "once more, then closes.  A rainbow bookmark forms\n"+
  "from between the page you just read.\n");
}

