#include "/obj/clean.c"

int sitvar;
object sitob;
string sitname;

short()
{
  if(!sitvar)
  return "A large metal examination table";
  return "An occupied metal examination table";
}

query_value()
{
        return 212;
}

long()
{
  write("This table is of alien manufacture and used for medical \n"+
   "examinations. It is bolted to the floor\n");
if(sitvar == 1) {
  write(sitname + " is strapped on to the table.\n");
  }
   environment(this_object())->long();
}

init() {
      add_action("no","quit");
/*
      add_action("no"); add_xverb("");      
*/
}

id(str) {
    return str == "table" || str == "metal table";
}

get() {
   string whonme;
    if (call_other(this_player(), "query_name") != "Boltar") {
    write("The table is attached to the floor. It would be unwise to remove it.\n");
        return 0;
    }
    return 1;
}
strapdown(arg){
   object ob;
   if (sitvar == 1) {
   write(sitname + " is on the table.\n");
   return 1;
   }
   sitname=arg;
   sitob=present(arg,this_object());
   sitvar = 1;
/*
   move_object(sitob, this_object());
*/
   return 1;
}
leave() {
     move_object(sitob,environment(this_object()));
     sitname = 0;
     sitvar = 0;
     sitob = 0;
     return 1;
}
realm() { return "NT"; }
no() {
  if(sitob && environment(this_player()) == this_object() ) {
  write("You are tied down.\n");
  return 1;
   }
  return 0;
}
