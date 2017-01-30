#include <security.h>
int cmd_home()
{
    object soul;
    string wkrm;
    
    if ((int)this_player()->query_level() < CREATE)
      return 0;
    if((int)this_player()->query_invis() < INVIS_TELEPORT)
      this_player()->remote_say((string)this_player()->query_name() 
       + " " + (string)this_player()->query_msghome() + ".\n");
    if(!(soul=present("soul", this_player())))
    { 
      write("Sorry! You need a soul to perform this action.\n");
      return 1;
    }
    if(!(wkrm=(string)soul->query_alt_wkrm()))
      move_object(this_player(), "players/"+(string)this_player()->query_real_name()+"/workroom");
    else
      move_object(this_player(), wkrm);
    this_player()->look();
    write("Ok.\n");
    return 1;
}
