#include <prop/item.h>

inherit "/complex/container";

status
can_put_and_get(string str, object arrow)
{
  if (arrow)
    return arrow->id("arrow") && container::can_put_and_get();
  return 1;
}

void
configure()
{
  container::configure();
  set_property(P_WEARABLE);
  set_name("quiver");
  set_id(({"quiver"}));
  set_short("quiver");
}

object *
query_arrows()
{
  return all_inventory();
}

object
get_ammunition()
{
  object *h;
  return sizeof(h=query_arrows()) && h[0];
}

int
query_max_arrows()
{
  return 20;
}

void
create()
{
  int i;
  container::create();
  for (i = query_max_arrows() - sizeof(query_arrows()); i--; )
    move_object(clone_object("/complex/weapon/arrow"),this_object());
}
