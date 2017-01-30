/*
 * This is the V10 valueserver of the Banking domain
 * There is one data-structure:
 * wares : mapping
 *           names -> number_of_buys; number_of_sells; time_of_last_change
 *
 * Both numbers are stored as floats. The time_of_last_change is stored as an
 * int.
 * Each time the query functions of the numbers are called the value of the
 * numbers is computed anew, based on the the decay.
 * When one number changes (when the item is traded) both numbers are
 * refreshed and stored together with the current time.
 */

#include <banking.h>
#include <kernel.h>
#include <describe.h>
#include <wizlevels.h>
#include <time_units.h>
#include <prop/player.h>
#include <is_wizard.h>

#define SAVE_ME unguarded(1,#'save_object,VALUESERVER_SAVEFILE)

inherit ACCESS;
inherit "basic/math";

#define INFLUENCE_FLAG 320

mapping wares;

#define BUYS 0
#define SELLS 1
#define TIME 2

mapping query_wares() { return copy(wares); }
status ware_known(mixed key) { return member(wares,key); }

/*
 * Internal functions
 */
void
notify_destruct()
{
  if (clonep(this_object()))
    return;
  if (this_interactive())
    BANKING("Valuserver destructed by " + 
            this_interactive()->query_vis_name());
  SAVE_ME;
}

void
reset(status refresh)
{
  mixed h;
  int i,start;
  if (clonep(this_object()))
    destruct(this_object());
  if (refresh)
  {
    /* Check 200 randomly chosen entries and delete all which have not been
     * traded in the last month
     */
    h = m_indices(wares);
    if (!sizeof(h))
      return;
    start = random(sizeof(h));
    for (i=start; i<start+200; i++)
      if (wares[h[i % sizeof(h)],TIME] < time()-ONE_MONTH)
        m_delete(wares,h[i % sizeof(h)]);
    SAVE_ME;
    return;
  }
  if (file_size(VALUESERVER_SAVEFILE + ".o") > 0)
    unguarded(1,#'restore_object,VALUESERVER_SAVEFILE);
  if (!wares)
    wares = m_allocate(0,3);
}

/*
 * This function builds the key which is used in the memory
 */
mixed
object2key(object o)
{
  return (o->query_valueserver_key() ||
          o->query_property(P_VALUESERVER_KEY) ||
          (o->query_weight() + "#" +
           lower_case(describe(o,ARTICLE_NONE,DESCRIBE_FULL)||"INVIS") + "#" +
           creator(o) + "#" +
           o->query_value()));
}

/*
 * Value functions
 */

float
number_of_buys(mixed m)
{
  if (objectp(m))
    m = object2key(m);
  return to_float(wares[m,BUYS] *
                  pow(TRADING_DECAY,to_floag(time()-wares[m,TIME])/ONE_WEEK));
}

float
number_of_sells(mixed m)
{
  if (objectp(m))
    m = object2key(m);
  return to_float(wares[m,SELLS] *
                  pow(TRADING_DECAY,to_float(time()-wares[m,TIME])/ONE_WEEK));
}

int
time_of_last_trade(mixed m)
{
  if (objectp(m))
    return time_of_last_trade(object2key(m));
  return wares[m,TIME];
}

int
round(int z)
{
  int tmp, tmp2;
  if ((tmp = strlen(""+z) - 2) <= 0)
  {
    if (z < 10)
      return z && 10;
    return ((z + 5) / 10) * 10;
  }
  tmp2 = 1;
  while (tmp--)
    tmp2 *= 10;
  return ((z + tmp2/2) / tmp2) * tmp2;
}

varargs int
value(mixed m,int v,status dont_round)
{
  mixed h;
  if (objectp(m))
    if (!(v=m->query_value()))
      return 0;
    else
      m = object2key(m);
  else if (!v)
    return 0;
  if (!wares)
    wares = m_allocate(0,3);
  if (!member(wares,m))
    h = v;
  else
  {
    h = to_int(0.5+v*pow(INFLATION,number_of_buys(m)-number_of_sells(m)));
    v = to_int(explode(m, "#")[<1]);
    if (v > 0)
    {
      if (h > (25 * v) / 10)
        h = (25 * v) / 10;
      else if (h < v / 5)
        h = v / 5;
    }
  }
  return dont_round ? h : round(h);
}

/*
 * Trading functions
 */

void
buy(mixed m)
{
  if (is_wizard(this_player(),IW_TOOLUSER) &&
      !this_player()->test_flag(INFLUENCE_FLAG))
    return;
  if (objectp(m))
    m = object2key(m);
  if (member(wares,m))
    wares += ([ m: number_of_buys(m)+1.0; number_of_sells(m); time() ]);
  else
    wares += ([ m: 1.0; 0.0; time() ]);
}

void
sell(mixed m)
{
  if (is_wizard(this_player(),IW_TOOLUSER) &&
      !this_player()->test_flag(INFLUENCE_FLAG))
    return;
  if (objectp(m))
    m = object2key(m);
  if (member(wares,m))
    wares += ([ m: number_of_buys(m); number_of_sells(m)+1.0; time() ]);
  else
    wares += ([ m: 0.0; 1.0; time() ]);
}
