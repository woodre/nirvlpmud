#include "/players/guilds/bards/def.h"
#define SOCIAL "/players/guilds/bards/socials/social_create.c"

status main(string str) {
  object socob;
  if(spell(0, 10, 0) == -1)
    return 0;
  socob=present("bard_social_creator",this_player());
  if(!socob) {
    socob=clone_object(SOCIAL);
    move_object(socob,this_player());
  }
  socob->start_create();
  return 1;
}
