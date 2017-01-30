#include "/obj/clean.c"

int sitvar;
object sitob;
string sitname;

short()
{
  if(!sitvar)
     return "A large metal chair";
  return "An occupied metal chair";
}

query_value()
{
        return 212;
}

long()
{
   write("This chair appears quite odd, it is of industrial quality and attached to the\n");
   write("the floor\n");
if(sitvar == 1) {
  write(sitname + " is strapped into the chair.\n");
  }
}

init() {
      add_action("sit","sit");
      add_action("no","east");
      add_action("no","quit");
      add_action("leave","break");
}

id(str) {
    return str == "chair" || str == "metal chair";
}

get() {
   string whonme;
    if (call_other(this_player(), "query_name") != "Boltar") {
    write("The chair is attached to the floor. It would be unwise to remove it.\n");
        whonme = call_other(this_player(), "query_name", 0);
        say(whonme + " tried to steal the chair.\n");
        return 0;
    }
    return 1;
}
sit(){
   object ob;
   if (sitvar == 1) {
   write(sitname + " is in the chair.\n");
   return 1;
  }
   write("You sit in the chair.\n");
   sitname=this_player()->query_name();
   sitob=this_player();
   say(this_player()->query_name() + " sits in the chair.\n");
   sitvar = 1;
   move_object(this_player(), this_object());
   write("Straps come out of the chair and tie you down!! You might be able\n");
   write("to break the bonds.\n");
   call_out("f_eat", 8);
    return 1;
}
leave() {
   if(this_player()->query_attrib("str") > random(30)) {
     write("You break out of the bonds.\n");
     move_object(this_player(), "/players/boltar/lv1/dnroom.c");
     say(sitname + " gets out of the chair.\n");
     sitname = 0;
     sitvar = 0;
     sitob = 0;
     remove_call_out("f_eat");
   } else
   write("You fail to break the bonds.\n");
   return 1;
}
f_eat() {
    tell_object(sitob,"A mechanical arm comes out from behind the chair and stuffs a doughnut\n");
    tell_object(sitob,"into your mouth!\n");
   if(sitob->query_phys_at(3) < 500)
     sitob->add_phys_at(3,random(2));
     sitob->eat_food(1);
    call_out("f_eat",8);
   return 1;
}
realm() { return "NT"; }
no() {
    if(this_player() == sitob) {
  write("You are tied down.\n");
  return 1;
   }
  return 0;
}
