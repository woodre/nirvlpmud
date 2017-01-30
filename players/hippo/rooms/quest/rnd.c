#include "/players/hippo/bs.h"
#define MAX_COLORS 40
string *color;
string *color_list;
int color_amount;
/*
reset(arg){
   color_list = ({
      "crimson",
      "red",
      "orange",
      "yellow",
      "green",
      "blue",
      "indigo",
      "violet",
    });
   color_amount = 8;
}
*/
query_color(i){
   if(i > sizeof(color) - 1) return 0;
   return color[i];
}
show_colors(){
   int z;
   for(z=0;z<color_amount;z++){
      write("color:"+z+": = "+color[z]+BS);
   }
   return 1;
}
reset_colors(){
   int x, y;
   if(color_amount > MAX_COLORS) return;
   if(!color_list) return;
   if(!color){
      color = allocate(MAX_COLORS);
      for(x=0;x<color_amount;x++){
         color[x] = color_list[x];
      }
   }
   for(x=0;x<color_amount;x++){
      y = random(sizeof(color_list));
      color[x] = color_list[y];
   }
}
/* to use this file:
	1> include it.
	2> in the reset(arg) function of file you are using this in,
	   build an array like the one in the example reset function above.
	   you may use up to 40 elements (each color is an element)
   3> also set the number of colors you want to use like in the example
	   reset (color_amount = ???)
	4> lastly just code the file.
any questions just mail me
mathiast
*/
