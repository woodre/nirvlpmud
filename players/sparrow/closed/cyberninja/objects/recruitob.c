#include "../DEFS.h"

string recruiter;


void init()
{
  add_action("learn","devote");
  add_action("info_database","cyber");
}


status id(string str)
{
  return str == "way" || str == "Way" || str == RECRUIT || str == AFFILIATE;
}


string short() { return "Way of the "+FUNKYNAME; }


void long()
{
  tell_object(TP, 
    "This is your guide to becoming a full-fledged "+FUNKYNAME+".\n"+
    "To receive information just type 'devote'.\n"); 
}


status get()  { return 1; }


status drop()
{
  destruct(this_object());
  return 1;
}


status learn()
{
  tell_object(TP,
  "_____________________The "+FUNKYNAME+"_____________________\n"+
  "You must now go to the "+FUNKYNAME+" guild and register at the\n"+
  "chop shop.  Then you must join.  If you do so successfully,\n"+
  "you will be a brand new "+FUNKYNAME+"!\n"+
  "(For detailed info, type 'cyber')\n");
  return 1;
}


status info_database(string str)
{ 
  call_other(LIB_GENCMDS+"cyber.c", "main", str); 
  return 1; 
}


set_recruiter(str) { recruiter=str; }
query_recruiter() { return recruiter; }
