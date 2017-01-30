
/*
 * To be added into player.c
 */

int color_ok;

toggle_color() {
   color_ok = !color_ok;
   if(color_ok)
     write("Ansi color is ON!\n");
   else
     write("Ansi color is OFF!\n");
   return 1;
}

query_color() { return color_ok; }

