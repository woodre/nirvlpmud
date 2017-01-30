
object airship;

short()
{
      return "2nd class section, Graf Nurfberg";
}

long()
{
  write("The second class section of the Nurfberg, the  luxury of it\n"+
 "all surrounds you. There are three rows of padded chairs on both\n"+
 "sides along the windows.\n");
  write("There is a door forward.\n");
}

init() {
    set_light(1);
      add_action("forward","forward");
}


forward() {
say(this_player()->query_name() + " leaves forward.\n");
    move_object(this_player(), airship);
    airship->long();
   return 1;
   }
set_ship(obj) {

airship = obj;
}
