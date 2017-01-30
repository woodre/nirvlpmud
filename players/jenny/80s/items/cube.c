#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int solved;
string CUBE;
reset(int arg) {
   CUBE = BLU+"RU"+YEL+"BI"+RED+"K'S "+GRN+"CU"+BLU+"BE"+NORM;
   if(arg) return;
   set_id("rubik's cube");
   set_alias("cube");
   set_short(GRN+"A "+CUBE);
   set_long("This is the infamous "+CUBE+", which drove everyone nuts in the 80's\n"+
      "It is a cubed shaped puzzle.  You have to match the colors on each side\n"+
      "of the cube.  To play with it, type: "+CYN+"twist cube."+NORM+"\n");
   
   
   set_weight(1);
   set_value(100); }
init() {        
   ::init();  
   add_action("cube","twist");
}
cube(arg) { 
   if(!arg) { return 0; }
   if(arg == "cube") {
      if(solved > 1) {write("It is already solved.  Why mess it up again?\n");
         return 1;}
      TP->add_spell_point(-1);
      if(TP->query_attrib("int") > random(400)) {
         write("You have solved the "+CUBE+".\n");
         say(TPN+" has solved the "+CUBE+".\n");
         if(TP->query_level() < 15) {
            TP->set_title("solved the "+BLU+"RU"+YEL+"BI"+RED+"K'S "+GRN+"CU"+BLU+"BE!"+NORM);
            write_file("/players/jenny/logs/cube", ""+TPN+" solved the "+CUBE+" on "+ctime()+"\n"); }
         solved = 2;
         return 1;}
      else {
         write("You play with the "+CUBE+" for a while, then become frustrated.\n");
         say(TPN+" plays with the "+CUBE+" for a while, then becomes visibly frustrated.\n");
         return 1; }}}
