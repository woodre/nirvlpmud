#include "/players/guilds/bards/def.h"

status main() {
  write("The following Bard-only emotions are available:\n\n");
  call_other("/players/guilds/bards/socials/social_create","list_socials",1);
  write("\n");
  return 1;
}
