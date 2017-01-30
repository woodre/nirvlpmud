#define tp this_player()->query_name()
inherit "obj/treasure";

int light;

reset(arg)
{   if (arg) return;
   set_id("starglow");
   set_short("A strand of Starglow");
   set_alias("strand");
   set_long("A strand of enchanted starglow.\n"+
       "It has been woven out of star dust.\n"+
       "To make the strand glow, rub it.\n"+
       "To put it out, shake it.\n");
   set_weight(1);
   set_value(500);
   set_light(0);
}
init()  {
  add_action("rub_glow","rub");
  add_action("shake_glow","shake");
        }

rub_glow(str)  {
if(str == "strand" || str == "starglow")  {
if(light == 0)  {
write("You rub the strand of Starglow.\n"+
  "\n\n\n\n\n                 THE WHOLE ROOM BEGINS TO GLOW.\n\n\n\n\n\n\n");
say(tp+" rubs a strand of Starglow.\n"+
     "\n\n\n\n\n                     THE WHOLE ROOM BEGINS TO GLOW.\n\n\n\n\n\n");
 set_light(1);
light = 1;
call_out("light_me",10);
    return 1;   }
write("It is already glowing.\n");
  return 1;
        }
}

shake_glow(str)  {
if(str == "strand" || str == "starglow")  {
if(light !=0)  {
write("You shake the strand of STARGLOW.\n"+
     "The room gets a lot darker.\n");
say(tp+" shakes a strand of STARGLOW.\n"+
     "The whole room gets a lot darker.\n");
set_light(-1);
remove_call_out("light_me");
light = 0;
  return 1;
        }
write("You have not yet rubbed it.\n");
  return 1;
}
}

light_me()  {
object ob;
string temp;
  temp = "starglow";
  ob = environment(this_object());
  if(light == 1)  {
   if(environment(ob))
  if(call_other(environment(ob), "light",0) != "DARK")  {
  command("shake starglow", ob);
  return 1;
        }
        }
  call_out("light_me",100);
  return 1;
        }
