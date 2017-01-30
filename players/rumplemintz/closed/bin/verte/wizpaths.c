#include <security.h>

status
main(string arg)
{
    if(arg) return 0;

    else
    {
      object *us, hmm; int s;
      write("\n");
      s = sizeof(us = users());
      while(s--)
        if(objectp(hmm = us[s]) && 
        ((int)hmm->query_level() > APPRENTICE))
          write(pad(capitalize((string)us[s]->query_real_name()), 13) +
               (string)us[s]->get_path() + "\n");

      write("\n");
      return 1;
    }
}
