/* Author: Autumn
* "The Cube"
*/

inherit "/players/autumn/cube/rooms/cube.c"; 
#include "/players/autumn/defs.h" 


reset(arg) 
{

  if(arg) return;
  

short_desc=(HIB+"A "+HIG+"Green "+HIB+"cube");

long_desc=
HIG+"      __________________\n"+
"     /\\   ______________ \\\n"+      
"   /:/\\.\\ \\        /:/\\:\\ \\ \n"+   
"  /:/Z/\\:\\ \\      /:/Z/\\:\\ \\ \n"+  
" /:/Z/__\\:\\ \\____/:/Z/  \\:\\ \\ \n"+  
"/:/Z/____\\:\\ \\___\\/Z/    \\:\\ \\ \n"+ 
"\\:\\ \\ZZZZZ\\:\\ \\ZZ/\\ \\     \\:\\ \\ \n"+ 
" \\:\\ \\     \\:\\ \\ \: \\ \\     \\:\\ \\ \n"+    
"  \\:\\ \\     \\:\\ \\_\;_\\_\\_____\\;\\ \\ \n"+     
"   \\:\\ \\     \\:\\_________________\\ \n"+      
"    \\:\\ \\    /:/ZZZZZZZZZZZZZZZZZ/ \n"+      
"     \\:\\ \\  /:/Z/    \\:\\ \\  /:/Z/ \n"+       
"      \\:\\ \\/:/Z/      \\:\\ \\/:/Z/ \n"+              
"       \\:\\/:/Z/________\\;\\/:/Z/ \n"+            
"        \\::/Z/_______itz_\\//Z/ \n"+           
"         \\/ZZZZZZZZZZZZZZZZZ/ \n\n"+NORM+
"     An empty room: the walls are made of steel, lined with four \n"+
"illuminated panels which create an appearance that the room is "+HIG+"green"+NORM+".\n"+
"There is a small, mysterious hatch on each wall, the ceiling, and the \n"+
"floor; the hatch is about three feet wide and three feet high. The \n"+
"walls, ceiling, and floor are identical, with exception of a \n"+
"mysterious number in the upper corner of the room. It is rather warm \n"+
"and musty. The smell of sweat permeates the area. The air is still, \n"+
"near motionless; a sense of fear and panic lingers. It is impossible to \n"+
"determine a way out. One could easily lose their mind in here - betray\n"+
"their friends, do things they normally would not do. Oddly, there is\n"+
"a boot laying on the floor.\n";


}	

init() {
::init();

get_newRoom();

}
