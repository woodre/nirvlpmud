
/*
 * TOWER_CLOCK (4/24/94)
 */

id(str) { return str == "clock" || str == "tower clock" ||
                 str == "plaque" || str == "dial" || str == "dials"; }

short() { return "A large tower clock"; }

long(str) {
   if(str == "plaque") {
     show_plaque();
     return 1;
   }
   if(str == "dial" || str == "dials") {
     show_dial();
     return 1;
   }
   write("While all things around it have been destroyed this clock\n");
   write("remains in perfect condition. It is made of an unknown wood\n");
   write("with small iron dials which specify the day, week, month, and\n");
   write("year. Near the base of the clock is a golden plaque.\n");
}

get() {
   write("The clock tower is far too heavy to be moved.\n");
   return 0;
}

show_plaque() {
write("}-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-{\n");
write("}                                                             {\n");
write("}     MAY THIS CLOCK SYMBOLIZE THE ALLIANCE BETWEEN THE       {\n");
write("}      BARDS AND PALADINS. AS LONG AS THIS CLOCK RUNS         {\n");
write("}              THE ALLIANCE SHALL FLOURISH.                   {\n");
write("}                                                             {\n");
write("}-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-{\n");
}

show_dial() {
   write("The dials show the date to be:\n");
   call_other("/players/molasar/rowan/obj/clock","get_current_time");
}

