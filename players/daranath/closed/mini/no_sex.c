inherit"obj/treasure";

reset(arg){
   set_id("no_sex");
   set_short();
   set_long();
   set_weight(0);
   set_value(0);
}
drop() {return 1;}
get() {return 1;}

init()  {
  ::init();
  add_action("sex_no","sex");
  add_action("fix_balls","fix_balls");
        }

sex_no()  {
  write("You don't quite have the equipment to do that...\n");
  return 1;
        }

fix_balls()  {
object balls;

  balls = present("balls", this_player());
  if(!balls)  {
    write("You need your balls before you can sew them back on!\n");
    return 1;
        }

  write("You sew your balls back on.\nOuch!\n");
  say(this_player()->query_name()+" sews "+this_player()->query_possessive()+" balls back on.\n");
    destruct(balls);
    destruct(this_object());
    return 1;
        }
