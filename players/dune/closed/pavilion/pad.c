get() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }
id(str) { return str == "pad" || str == "gyropad"; }
short() { return "(((( A GyroPad ))))"; }
long() { sign_disp(); }
init() { add_action("read","read"); }

read (str) {
  if(!str || str != "pad") return 0;
  sign_disp();
  return 1; }

sign_disp() {
  write(
  " _______________________________________________________\n"+
  "|                    R O B O M E C H:                   |\n"+
  "|                      Now Open!                        |\n"+
  "|Are you tired of PK?  Are you tired of killing monsters|\n"+
  "|      just so you can get more experience and coins?   |\n"+
  "|            Want to try something different?           |\n"+
  "|]]]]]]]]]]]]]]]     Play RoboMech!!     ]]]]]]]]]]]]]]]|\n"+
  "|     RoboMech is a strategy/action game where players  |\n"+
  "|    climb inside their own individualized robomech and |\n"+
  "|   fight the robomechs of other players.  Robomechs are|\n"+
  "|            robots which are piloted by players.       |\n"+
  "|Come Play:  from 1 south of church, go: 4w, 2n, e, 2n  |\n"+
  "|_______________________________________________________|\n");
}
