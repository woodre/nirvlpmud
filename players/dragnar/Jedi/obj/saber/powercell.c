int life;

id(str) { return str == "cell" || str == "power cell"; }

reset(arg) {
  if(arg) return;
}

short() {
  return "A power cell";
}

long() {
   write(
    "This power cell is contained in a dense plastic shell.  The total size\n"+
    "of the cell is only approximately 3 centimeters by 1.5 centimeters.\n"+
    "There is a sticker on the side of the cell that gives the power rating\n"+
    "for the cell, but the rating is amazing for such a small device.  If\n"+
    "the rating is correct, this cell is very technically advanced.\n");
   return 1;
}

void set_life(int x) { life = x; }
int query_life() { return life; }

get() { return 1; }
query_weight() { return 1; }
query_value() { return life/10*100; }
