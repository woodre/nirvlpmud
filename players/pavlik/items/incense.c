#define ME capitalize(this_player()->query_real_name())

int sticks_burned;

id(str) { return (str == "incense" || str == "stick"); }

reset() {}

long()
{
 write("Incense.  A wax stick the gives of healing fumes when you light it.\n");
  write("There are " + (3-sticks_burned) + " sticks remaining.\n");
}

short() { return "Incense"; }


init() {
  add_action("light","light");
}

light(arg)
{
  if (id(arg)) {
 say(ME+" lights a stick of incense and inhales the healing fumes.\n");
 write("You light a stick of incense and hold it close to your nose.\n"+
   "You breathe in the healing fumes deeply through your nose and\n"+
   "feel much better.\n");
if(sticks_burned == 2) { write("You have burned up the last of your incense.\n"); }
 else { write("You still have "+(2 - sticks_burned)+" sticks remaining.\n"); }
      call_other(this_player(),"heal_self",25);
      sticks_burned++;
      if (sticks_burned > 2) { 
        this_player()->add_weight(-1);
        destruct(this_object()); 
      return 1;
    }
    return 1;
   }
}
 


get() { return 1; }

query_weight() { return 1; }

query_value() { return 2500; }


