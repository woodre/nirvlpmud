inherit "obj/treasure.c";
#include <ansi.h>

reset(arg){
  if(arg) return;
set_id("soup");
set_alias("turtle soup");
set_short(HBGRN+"Glowing Turtle Soup"+NORM);
set_long("A very large shell, containing which appears to be\n"+
""+HBGRN+"glowing"+NORM+HIG+" turtle"+NORM+" soup.\n"+
"If daring one could attempt to drink it.\n");
set_value(17000);
set_weight(1);
}
init(){
  add_action("drink","drink");
}

drink(string str){
if(!str || (str != "soup" && str != "turtle soup")){
    notify_fail("What would you like to drink?\n");
    return 0;
  }
write("You lift the shell to your mouth, and empty it's contents into your mouth.\nYou start to feel somewhat sick to your stomach.\nYet the feeling passes and you end up feeling quite refreshed!\n");
this_player()->heal_self(1000);
say(this_player()->query_name()+" drinks a potion.\n");
call_other(this_player(),"drink_alcohol",-1000);
call_other(this_player(),"drink_soft",-1000);
call_other(this_player(),"eat_food",-1000);
destruct(this_object());
this_player()->recalc_carry();
return 1;
}
