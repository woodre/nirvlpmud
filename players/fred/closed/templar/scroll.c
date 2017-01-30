inherit "/obj/treasure.c";
#include <ansi.h>
#include "/players/fred/closed/templar/defs.h"
int a,b,c,d,e,f,g,h;
int doubles, invoked;

reset (arg)
{
  set_name("scroll");
  SetMultipleIds(({"templar scroll", "elite scroll", "quest scroll", "templar_quest_scroll"}));
  set_short("An ancient scroll");
  set_long("A very old scroll with a small ribbon tied around it.\n"+
           "It is said that those with a pure heart can 'invoke'\n"+
           "the power of it's writings.\n");
}

init(){
  ::init();
  add_action("Cmd_invoke","invoke");
}

Cmd_invoke(str)
{
  int x;
  string what;
  if(!str) return;
  if(str == "scroll")
    build_scroll();
  return 1;
}

build_scroll()
{
  if(!invoked) get_items();
  TOU "\nYou must obtain 8 items to test your fighting skills and\n"+
      "your knowledge of various realms.  You must retrieve the\n"+
      "following items:\n\n");

  TOU DAEMON->get_task(a)+"\n\n");
  TOU DAEMON->get_task(b)+"\n\n");
  TOU DAEMON->get_task(c)+"\n\n");
  TOU DAEMON->get_task(d)+"\n\n");
  TOU DAEMON->get_task(e)+"\n\n");
  TOU DAEMON->get_task(f)+"\n\n");
  TOU DAEMON->get_task(g)+"\n\n");
  TOU DAEMON->get_task(h)+"\n\n");

  TRU Name+" carefully opens the scroll and begins to read it.\n", ({User}));
}

get_items()
{
  doubles = 0;
  a = random(ITEMS);     b = random(ITEMS);
  c = random(ITEMS);     d = random(ITEMS);
  e = random(ITEMS);     f = random(ITEMS);
  g = random(ITEMS);     h = random(ITEMS);


  /* Check for duplicate numbers */

  if(a == b || a == c || a == d || a == e || a == f ||
     a == g || a == h)
     doubles++;
  if(b == c || b == d || b == e || b == f || b == g)
     doubles++;
  if(c == d || c == e || c == f || c == g)
     doubles++;
  if(d == e || d == f || d == g)
     doubles++;
  if(e == f || e == g)
     doubles++;
  if(f == g)
     doubles++;

  /* End check for duplicate numbers */

  if(doubles > 0)
  {
    get_items();
    return 1;
  }
  invoked = 1;
}

/* Variable junk. To be used later on */

query_a(){ return a; }
query_b(){ return b; }
query_c(){ return c; }
query_d(){ return d; }
query_e(){ return e; }
query_f(){ return f; }
query_g(){ return g; }
query_h(){ return h; }


