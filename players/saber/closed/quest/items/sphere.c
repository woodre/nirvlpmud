inherit "obj/treasure";

int FILLED, FIL, fil;

reset(arg)
{   if (arg) return;
   set_id("sphere");
   set_alias("iron_sphere");
   set_short("An iron sphere");
   set_long("An iron sphere.  It seems to be magical.\n");
   set_weight(1);
   set_value(6001);
}

init()  {
   add_action("fill_sphere","fill");
        }

fill_sphere(str)  {
  if(str == "sphere")  {
    if(FILLED == 0)  {
      if(!present("stream"), environment(this_player())  ||
         !present("waterfall"), environment(this_player()))  {
      write("You need water to fill the sphere.\n");
      return 1;
      }
        write("You fill the sphere up with icy water.\n");
        say(this_player()->query_name()+" fills up an iron sphere with water.\n");
        FILLED = 1;
        set_filled(1);
        return 1;
        }
    write("There sphere is already full.\n");
    return 1;
    }    }

quest_ob() { return 1; }
query_save_flag() { return 1; }
set_filled(str)  {   FIL = str;  }
query_filled()   { return FIL; }
