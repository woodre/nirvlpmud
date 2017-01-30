#include "/obj/clean.c"

short()
{
      return "A shiny chrome whistle";
}

query_value()
{
        return 0;
}

long()
{
    write("A great sounding instrument.\n");
     write("You can blow into it.\n");
}

init() {
       add_action("blow","blow");
}

id(str) {
    return str == "whistle" || str == "chrome whistle";
}

blow(str) {
  object cop;
    if (str && !id(str))
        return 0;
  if(present("peace keeper",environment(this_player()))) {
    write("Why bother, there is already one here.\n");
    return 1;
   }
  write ("You blow into the whistle.\n");
   write("Calling town guard.....\n");
   cop = find_living("peace keeper");
   if (!cop) {
  write("No town guards are nearby.\n");
   return 1;
    }
   move_object(cop, environment(this_player()));
/*
  write ("\n");
*/
say(call_other(this_player(), "query_name") +
     " blows into a whistle.\n" +
/*
   "  \n"+
   "         \n"+
*/
   "A town guard has been summoned.\n");
   write("A town guard has been summoned.\n");
    return 1;
}

get() {
    if (call_other(this_player(), "query_level") < 1) {
        write("It is too heavy!\n");
        return 0;
    }
    return 1;
}
drop() {
   write("The whistle breaks as it hits the ground.\n");
   destruct(this_object());
   return 1;
}
