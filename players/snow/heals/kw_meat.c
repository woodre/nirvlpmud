inherit "/obj/treasure";

int meat_val;

reset(arg) {
  if(!arg) {
set_id("whale meat");
set_short("A hunk of whale meat");
set_alias("meat");
set_long("A hunk of tasty-looking whale meat.\n");
set_value(500);
set_weight(2);
  }
}

init() {
  add_action("eat_meat","eat");
}

set_meat_value(mv) { meat_val = mv; }

eat_meat(arg) {
  if(!arg) { write("Eat what?\n"); return 1; }
  if(arg == "meat" || arg == "whale meat") {
/*
    write_file("/players/snow/log/heals",ctime(time())+" "+
          this_player()->query_real_name()+" ate whale meat.\n");
*/
    write("You chew up the hunk of whale meat. It is raw but good!\n");
    say(capitalize(this_player()->query_name())+
       " chews up a hunk of whale meat and looks satisfied.\n");
if(!meat_val) meat_val = 25;
   this_player()->heal_self(meat_val);
   this_player()->eat_food(10);
     destruct(this_object()); this_player()->recalc_carry();
  return 1;
  }
}
query_save_flag() { return 1; }
