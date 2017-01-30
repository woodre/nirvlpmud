#include <esc.h>


int lightstate;
int stoptalk;
short()
{
   if(lightstate == 0) 
     return "A light up plastic Snowman";
    if(lightstate == 1)
   return esc+"[0m"+esc+"[1m"+esc+"[1m"+esc+"[37m"+esc+"[40m A light up plastic Snowman (lit)"+esc+"[0m";
}

query_value() { return 0; }

query_weight() { 
  if(this_player()->query_real_name()=="slacker") return 1;
  else return 10000; }
long()
{
  write("A light up plastic Snowman. It looks a bit like Frosty.\n");
}

init() {
     add_action("light","light");
     add_action("extinguish","extinguish");
}

id(str) {
    return str == "snowman" || str == "plastic snowman";
}

light(str) {
    if (str && !id(str))
        return 0;
   if(lightstate != 0) {
   write("The snowman is already lit.\n");
    return 1;
}
     write("You turn on the Snowman, and it glows brightly.\n");
   if (this_player()) {
       say(call_other(this_player(), "query_name") +
  " turns on the Snowman. \n"
   );
}
   set_light( 1);
   lightstate = 1;
    return 1;
}

get() {
   write("Ok.\n");
    return 1;
}
extinguish(str) {
    if (str && !id(str))
      return "extinguish what?";
    if(lightstate != 1) {
    write("The snowman is not lit.\n");
   return 1;
}
    write("You extinguish the snowman.\n");
    say(call_other(this_player(), "query_name") +
   " turns off the snowman.\n");
   set_light(-1);
   lightstate = 0;
   return 1;
}

remove_object(ob) { log_file("XMAS",file_name(ob)+"\n"); }
