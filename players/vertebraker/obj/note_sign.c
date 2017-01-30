#include <ansi.h>

string short()
{
  return "A "+HIG+"big green sign"+NORM;
}

int id(string str)
{
  return (str=="sign");
}

void long()
{
  write(HIG+"READ NOTE #28 ON THIS BOARD, ENTITLED TYPO/BUG/IDEA AND CONTEST.\n"+NORM);
  write("WIN PRIZES!\n");
}

 
