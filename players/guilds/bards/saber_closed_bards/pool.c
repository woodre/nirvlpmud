#define tp this_player()->query_name()

inherit "obj/treasure";

int count, count2;

reset(arg)  {
 count = random(5) + 5;
 count2 = 0;
   if (arg) return;
   set_id("pool");
   set_short("A pool of dark water");
   set_alias("water");
   set_long("A pool of very dark water.\n"+
       "You believe that you could <gaze> into it.\n");
   set_weight(100);
   set_value(0);
}

init()  {
   add_action("gaze_pool","gaze");  }

gaze_pool(str)  {
object ob;
string there;

  if(!str)  {
  write("\n    <gaze> at <who>\n\n");
  return 1;
        }

ob = find_player(str);
  if(!ob)  ob = find_living(str);
    if(!ob || ob->query_invis() > 17) {
      write("The pool remains dark.\n");
      return 1;
        }
write("You look into the dark pool and see and image of:\n");
there = call_other(ob,"look");
say(tp+" gazes into the pool of dark water.\n");
count2 = count2 + 1;
if(count2 > count)  { call_out("bye",2);  }
  return 1;
}

bye()  {
tell_room(environment(this_object()),
 "\nThe pool of dark water turns in to mist and floats away...\n\n");
  destruct(this_object());
  return 0;
        }
