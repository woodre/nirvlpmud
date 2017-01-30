#define TP   this_player()
#define TO   this_object()
#define TR   tell_room

shout(string str) {
  string file;
  file = "/players/dune/closed/pavilion/rooms/field/";
  TR(file+"blue1.c", str);
  TR(file+"blue2.c", str);
  TR(file+"blue3.c", str);
  TR(file+"blue4.c", str);
  TR(file+"white1.c", str);
  TR(file+"white2.c", str);
  TR(file+"white3.c", str);
  TR(file+"white4.c", str);
  TR(file+"black1.c", str);
  TR(file+"black2.c", str);
  TR(file+"black3.c", str);
  TR(file+"black4.c", str);
  TR(file+"red1.c", str);
  TR(file+"red2.c", str);
  TR(file+"red3.c", str);
  TR(file+"red4.c", str);
  TR(file+"green1.c", str);
  TR(file+"green2.c", str);
  TR(file+"green3.c", str);
  TR(file+"green4.c", str);
  return 1; }

realm() { return "NT"; }
