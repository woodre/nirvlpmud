inherit "obj/treasure";

reset(arg)
{  if (arg) return;
   set_id("silver coin");
   set_alias("coin");
   set_short("A silver coin");
   set_long(
     "A coin of worked black silver covered with dark runes.\n");
   set_weight(0);
   set_value(100);
}

init()  {
  ::init();
   add_action("read_runes","read");
        }

read_runes(str)  {
  if(str == "runes" || str == "coin")  {
  write("The runes read: Keep this near thee in times of peril.\n");
  return 1;
        }
        }

quest_ob()  { return 1; }
query_save_flag()  { return 1; }
