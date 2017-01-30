/*
    complex/container.c - container add_weight compatibility requirements
    Mar 1992 by marion@cs.tu-berlin.de
*/

#include <persistence.h>
#include <describe.h>
#include <encumbrance.h>
#include <libs.h>

inherit "complex/item";
inherit "basic/container";

private string container_long_desc;

status prevent_insert()
{
  if (first_inventory()) return 1;
}

static string
container_long()
{
  return
    container_long_desc ||
    (capitalize(describe(this_object(),ARTICLE_A,DESCRIBE_FULL)||"")+".\n");
}

void configure()
{
  item::configure();

  set_persistence(  // Carador, Oct-96
    "complex/container",
    PER_KEEP_VARS,
    ({ ({ "max_encumbrance", "set_max_encumbrance",
          "query_container_max_encumbrance" }),
       ({ "encumbrance", "set_encumbrance", "query_empty_encumbrance" }),
       PER_PERM_VAR + "container_closed",
#if 0  // moved to complex/item, Coogan, 16-Feb-98
       PER_PERM_VAR + "persistent_content"  // Carador, 18-Aug-97
#endif
    })
  );

  set_short("non-descript container");
  set_long(#'container_long);
  set_id("container");
  remove_persistence("set_long");
}


// The items in the container have an influence on the container's
// encumbrance. So the fuller a bag gets, the heavier it is.
// 30 per cent of the inventory's encumbrance are added to the
// container's encumbrance. Carador, Aug-96.

int query_empty_encumbrance() {
  return item::query_encumbrance();
}

int query_encumbrance() {
  return item::query_encumbrance() + query_container_encumbrance(1);
}

void set_container_long(string desc) {
  container_long_desc = desc;
}

string query_container_long() {  // Coogan, 21-Apr-98
  return container_long_desc;
}
