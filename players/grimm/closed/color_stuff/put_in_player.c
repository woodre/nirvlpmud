The following lines should be put in "player.c"

 .
 .
 .
 int color_flag;

 .
 .
 .
 reset(arg) {
 ...
 color_flag = 0;
 ...
 }

 .
 .
 .
 init() {
 ...
 add_action("color_toggle","color");
 ...
 }

 .
 .
 .
 color_toggle() {
   if(color_flag) {
     write("Color: Off\n");
     color_flag = 0;
     return 1;
   }
   write("Color: On\n");
   color_flag = 1;
   return 1;
 }

 query_color() { return color_flag; }

 .
 .
 .
