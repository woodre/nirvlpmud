#include <ansi.h>
#define MAX_BEATS 10

int beats;

id(str) { return str == "welt"; }

long()
{
        write("\n"+
"This\n"+
"Is\n"+
"A\n"+
"Welt.\n");
}

extra_look()
{
        if(environment() == this_player())
                write("A giant welt in the form of a dick is on the side of your face.\n");
        else
                write(environment()->query_name() + " has a large welt on "+
possessive(environment())+" face in the resemblance of a dick.\n");
}

drop() { return 1; }
get() { return 1; }


start_it()
{
  set_heart_beat(1);
}

heart_beat()
{
	object ob;
  
  ob = environment();
  if(++beats == MAX_BEATS)
  {
    tell_object(ob,
      "The welt seems to wear off.\n");
    return destruct(this_object());
  }
}