#include "../x.h"

int cmd_ntm(string str)
{
 int cm;
 if(str) return 0;
 cm = (int)PO->query_chan_muffle();
 write("NIMHTalk -"+HIC+(cm?"ON":"OFF")+NORM+"-\n");
 cm ^= 1;
 PO->set_chan_muffle(cm);
 return 1;
}
