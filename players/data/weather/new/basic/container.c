/*
    basic/container.c - container logic
    Feb 1992 by marion@cs.tu-berlin.de
*/

/* removed variable container_encumbrance and all places which referred
   to it, we now calculate the encumbrance whenever we need it, it's
   more costy, I know, but it's the safest (I ran into problems with
   persistence and containers so I did that), Carador, 18-Aug-1997 */

#include <encumbrance.h>

private int container_max_encumbrance;
private int container_closed;
private mixed reduce_factor = 300;  // measured in 1/1000

void
set_max_encumbrance(int max)
{
    container_max_encumbrance = max;
}

void set_encumbrance_reduce_factor(mixed factor) {
  reduce_factor = factor;
}

int query_encumbrance_reduce_factor() {
  return funcall(reduce_factor);
}

varargs int
query_container_encumbrance(status reduced)
{
    int enc;
    object ob;

    for (ob = first_inventory(); ob; ob = next_inventory(ob))
      enc += get_encumbrance(ob);

    return (!reduced? enc : enc * query_encumbrance_reduce_factor() / 1000);
}

int
query_container_max_encumbrance()
{
    return container_max_encumbrance;
}

int
insert_objects()
{
    return !container_closed;
}

int
remove_objects()
{
    return !container_closed;
}

status
test_encumbrance(int enc)
{
  if (!container_max_encumbrance)
    return 1;
  if (enc < 0)  // always allow adding of negative weights.   Alfe 1997-Jan-02
    return 1;
  if (enc + query_container_encumbrance() > container_max_encumbrance)
    return 0;
  return 1;
}

int
add_encumbrance(int add)
{
  if (!test_encumbrance(add))
    return 0;
  return 1;
}

// for compatibility reasons ...
int add_weight(int add) {
  return add_encumbrance(add * WEIGHT_FACTOR);
}

void
set_container_closed(int flag)
{
    container_closed = flag;
}

/* Added on 04-AUG-1994 by Hal: new arguments container_id, to_insert */
varargs int
can_put_and_get(string container_id, object to_insert)
{
    return insert_objects();
}

status
hide_inventory(string str)
{
    return !insert_objects();
}
