/*
 *
 * Darkness spell for the Shardak guild
 * Blocks teleport and some ordinary exits of the room we're in
 */
#pragma strict_types

#include "/players/vertebraker/ansi.h"
#define p possessive(b)
#define a (BOLD + BLK)
#include "../std.h"
#include "../def.h"
#include "../macros.h"
#define COST 70
string x;

inherit CMD;

status
main()
{
   object          whore, it, b;
   
   needrank(7);
   if(this_player()->query_attack())
   {
     write("\
You are in battle...\n\
You must be more focused to use this power.\n");
     return 1;
   }
   /*
   * only cast darkness if we are in a room-room
      */
   if (!environment(this_player()) ||
         environment(environment(this_player()))) {
      write("Darkness can not be cast here.\n");
      return 1;
   }
   /*
   * no casting darkness in starting realm
   */
   if (!sscanf(file_name(environment(this_player())), "%s" + PATH + "%s", x, x)) {
      write("Darkness can not be cast here.\n");
      return 1;
   }
   /*
   * check if darkness already exists in the room
      */
   if (environment(this_player())->shardak_darkness(0)) {
      write("Darkness has already been cast here.\n");
      return 1;
   }
   /*
   * cast darkness
   */
   it = clone_object(OBJDIR + "darkness");
   if (it->shardak_darkness(whore = environment(b = this_player()))) {
      write("\
You cough in spasms, and a " + a + "dark black liquid" + NORM + " \
sputters from your mouth.\n\
Catching a bit of it with your arms, you smear it all over yourself...\n\
You spin around...\n\t");
      write("\
The liquid coalesces all over...\n\n\
Suddenly, the " + a + "black liquid" + NORM + " \
expels itself from your body, raining a\n\
hideous " + a + "black darkness" + NORM + " all over the area...\n");
      write("\
The light in the room seems to fade as the " + a + "darkness" + NORM + "\n\
spreads, shadowing the area....\n");
      tell_room(whore,
(string)b->query_name() + " \
coughs in spasms.\n\
A " + a + "black liquid" + NORM + " pours from " + p + 
" mouth, sprinkling into \
" + p + " hands.\n\n", ({ b }));
      tell_room(whore,
"Spreading " + p + " arms, " + (string)b->query_name() + " \
spins around in place, scattering\n\
the matte liquid around the area.\n", ({ b }));
      tell_room(whore,
"\t\t" + a + "Darkness" + NORM + " descends upon you.\n\n", ({ b }));
   }
   else {
      write("You cough spasmodically and nothing happens.\n");
      say(this_player()->query_name() + " coughs spasmodically.\n");
      destruct(it);
   }
   this_player()->add_spell_point(-COST);
   return 1;
}

