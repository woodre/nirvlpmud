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
    soul = this_player();
    if(!(wkrm=(string)soul->query_alt_wkrm()))
      move_object(this_player(), "players/"+(string)this_player()->query_real_name()+"/workroom");
    else
      move_object(this_player(), wkrm);
    command("look", this_player());
    write("Ok.\n");
    return 1;
}
