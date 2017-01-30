 
 
id(str) {return str == "koosh" || str == "kooshball";  }
short() {return "A special kooshball";}
long() {write("This is a special koosh ball made for special people.  It was created just\n"+
              "to make people happy.  You may 'hug','squeeze', and juggle it.\n"); return 1; }
drop() {return 1;}
get() {return 1;}
init() {
 add_action("hug","hug");
 add_action("squeeze","squeeze");
 add_action("juggle_ball","juggle");
}
juggle_ball(str) {
   if ((!str) || !id(str)) {
       return 0;
       }
   write("You skillfuly juggle the kooshball!\n");
     say(this_player()->query_name()+" deftly juggles a koosh!(only one???)\n");
      return 1;
         }
hug(str) {
  if ((!str) || !id(str)) {
    return 0;
  }
  write("You get the feeling that someone cares as you hug this special kooshball.\n");
  say(this_player()->query_name()+" hugs a kooshball tightly.\n");
  return 1;
}
squeeze(str) {
  if ((!str) || !id(str)) {
    return 0;
  }
  write("You squeeze some of the koosh's endless love from it..\n");
  say(this_player()->query_name()+" squeezes a kooshball tightly.\n");
  return 1;
}
