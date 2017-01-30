/*
 * This is the V10 statistic archive of the Banking domain
 */

#include <banking.h>
#include <kernel.h>

inherit ACCESS;
inherit "basic/copy";

mapping data;

void
notify_destruct()
{
  if (clonep(this_object()))
    return;
  BANKING_LOG("Statistic archive destructed by "+
              this_interactive()->query_vis_name());
}

public void
save_me()
{
  unguarded(1,#'save_object,BANKINGSTATISTIC_ARCHIVE_SAVEFILE);
}

void
reset(status arg)
{
  if (clonep(this_object()))
  {
    destruct(this_object());
    return;
  }
  if (arg)
    return;
  unguarded(1,#'restore_object,BANKINGSTATISTIC_ARCHIVE_SAVEFILE);
  if (!data)
    data = m_allocate(0,2);
}

varargs void
add_data(string which,mixed d,int t)
{
  if (!check_previous_privilege("Banking:"))
    raise_error("Illegal call of add_data()\n");
  d = copy(d);
  if (member(data,which))
  {
    data[which] += ({ d });
    data[which,1] += ({ t || time() });
  }
  else
  {
    data[which] = ({ d });
    data[which,1] = ({ t || time() });
  }
}

mapping
query_data()
{
  return copy(data);
}
