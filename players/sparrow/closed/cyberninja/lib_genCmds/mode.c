#include "../DEFS.h"

status main(string str)
{
  object boo;
  int delay;
  if (!str)
  {
    write("Current mode: "+BOLD);
    if((int)IPTP->query_attack_mode() == 0) write(upper_case(ATTACK_MODE0));
    if((int)IPTP->query_attack_mode() == 1) write(upper_case(ATTACK_MODE1));
    if((int)IPTP->query_attack_mode() == 2) write(upper_case(ATTACK_MODE2));
    write(OFF+"\n");
    write("Usage: mode <"+ATTACK_MODE0+"/"+ATTACK_MODE1+"/"+ATTACK_MODE2+">\n");
    return 1; 
  }
  delay = (int)IPTP->query_mode_delay();
  if (time() < delay + 5)
  {
    write("You are unable to switch attack modes so quickly.\n");
    return 1;
  }
  IPTP->set_mode_delay(time());
  if (str == ATTACK_MODE0)
  {
    IPTP->set_attack_mode(0);
    IPTP->save_me();
    write(BOLD+"Attack mode set to: "+upper_case(ATTACK_MODE0)+OFF+"\n");
    return 1;
  }
  if (str == ATTACK_MODE1)
  {
    IPTP->set_attack_mode(1);
    IPTP->save_me();
    write(BOLD+"You set your attack mode to: "+upper_case(ATTACK_MODE1)+OFF+"\n");
    return 1;
  }
  if (str == ATTACK_MODE2)
  {
    IPTP->set_attack_mode(2);
    IPTP->save_me();
    write(BOLD+"Attack mode set to: "+upper_case(ATTACK_MODE2)+OFF+"\n");
    return 1;
  }
  write("You have chosen an invalid attack mode.\n");
  return 1;
}
