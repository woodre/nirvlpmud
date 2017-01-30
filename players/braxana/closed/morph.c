reset(arg) {
   string moo;
  string meow;
  int mo;
  mo = random(100000);
   meow = ""+mo;
  moo = "/players/braxana/closed/"+meow+".c";
    write_file(moo,"id(str) { return str == ");
    write_file(moo,"\"");
  mo = random(100000);
   meow = ""+mo;
    write_file(moo,meow);
    write_file(moo,"\"");
   write_file(moo,"; }");
  destruct(this_object());
return 1; }
