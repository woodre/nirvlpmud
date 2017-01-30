#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  if(PO->query_guarding()
    || PO->query_guard())
    return (notify_fail("You can not update while guarding someone.\n"), 0);
  if(PO->query_sheathed())
    return (notify_fail("You can not update when you "+
    "have weapons sheathed.\n"), 0);
  if((PO->query_attribb(0) + PO->query_attribb(1)
    + PO->query_attribb(2) + PO->query_attribb(3)
    + PO->query_attribb(4) + PO->query_attribb(5)) > 0)
    return (notify_fail(
    "You can not update while you have attribute bonuses.\n"), 0);
  tell_object(environment(PO),
    "Updating your guild object...\n");
  PO->update_gob();
  return 1;
}
