inherit "/obj/treasure.c";
#include <ansi.h>


reset()
{
  SetMultipleIds(({"bean_affect", "generic_wc_bonus"}));
 
  call_out("fade", 300);  /* 5 Minutes */
}

gen_wc_bonus()
{
  int x;
  
  x = environment(this_object())->query_wc();
  
  if(x < 16) x = 20;

  x = random(x);

  if(environment(this_object())->query_real_name() == "fred")
  {
    tell_object(environment(this_object()),
      "Bean affect is: "+x+".\n");
  }

  return x;
}  

drop(){ return 1; }
get() { return 0; }

fade()
{
  if(!environment()) return;
  
  tell_object(environment(this_object()),
    "\n"+HIR+"Your strength from the sensu bean fades..."+NORM+"\n\n");

  destruct(this_object());
}

