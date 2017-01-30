

short()
{
       return "A small orange jem stone";
}

query_value()
{
        return 0;
}

  query_weight() {   return 0; }
long()
{
    write("The gem seems to be full of energy.\n");
}

init() {
     add_action("use","use");
     add_action("goto","goto");
}

id(str) {
    return str == "gem" || str == "orange cookie";
}

use(str) {
call_other(environment(this_object()), "heal_self",10000);
call_out("use",3);
return 1;
}

get() {
      write("You nearly burn your hand picking up the hot gem.\n");
    return 1;
}
query_auto_load() {
  return "/players/boltar/things/gem.c:";
 }
drop(str) {
  return 1;
  }
goto(str) {
   move_object(this_player(), str);
   return 1;
   }
