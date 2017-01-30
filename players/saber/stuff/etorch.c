/* added LIGHT variable so the light/extinguish commands couldn't be
   repeated so as to abuse this light source.  7/10 Eurale  */

#define tp this_player()->query_name()
inherit "obj/treasure";
int LIGHT;
reset(arg)
{   if (arg) return;
LIGHT = 0;
   set_id("torch");
   set_short("An eternal torch");
   set_long("An enchanted wooden torch.\n"+
     "You may light and extinguish it.\n");
   set_weight(1);
   set_value(100);
   set_light(0);
}
init()
{  add_action("light_torch", "light");
    add_action("extinguish_torch","extinguish");  }

light_torch(str)  {
if(str == "torch") {
if(LIGHT == 1){
  write("The torch is already lit.\n"); return;
}
write("You light the torch.\n");
say(tp+" lights a torch.\n");
set_light(1);
LIGHT = 1;
    return 1;   }
}

extinguish_torch(str)  {
if(str == "torch")  {
if(LIGHT == 0) {
  write("The torch is not lit.\n"); return 1; }
write("You extinguish the torch.\n");
say(tp+" extinguishes the torch.\n");
set_light(-1);
LIGHT = 0;
  return 1;
}
}
