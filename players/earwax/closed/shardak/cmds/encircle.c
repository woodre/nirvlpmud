#include "../tasks.h"
#include "../def.h"
#include "../macros.h"
#include "/players/vertebraker/ansi.h"
#include "../std.h"

inherit CMD;
status main(string str)
{
    int        cost;
    object     borg, flames;
    
    cost = 100;

    needrank(5);
    if(previous_object()->CastingSpell())
    {
      notify_fail("You are currently intoning a spell...\n");
      return 0;
    }
    needtask(FLAMES_TASK);
    needmana(cost);
    flames = (mixed)previous_object()->query_flames();
    if(!flames && !(flames = present("shardak_fire", environment(this_player()))))
    {
      notify_fail("\
You must conjure some of the dark flames in order\n\
to cast a spell with them...\n");
      return 0;
    }
    if(!str)
      borg = this_player();
    else
    {
      str = lower_case(str);
      if(!(borg = present(str, environment(this_player()))))
      {
        notify_fail("You don't see " + capitalize(str) + " here.\n");
        return 0;
      }
      if(borg->query_ghost() || !this_player()->valid_attack(borg))
      {
        notify_fail("\
That organism seems to be protected by some sort of\n\
otherworldly power.  The circle cannot be cast upon\n\
" + borg->query_objective() + " at this time.\n");
        return 0;
      }
    }
    this_player()->add_spell_point(-cost);
    previous_object()->CastingSpell(1);
    write("You begin the incantation...\n\n");
    tell_room(environment(this_player()),
(string)this_player()->query_name() + " begins an incantation...\n\n",
    ({ this_player() }));
    tell_room(environment(this_player()), RED + "\
Blood-red magik energy builds around " +
 (string)this_player()->query_name() + "\n" + NORM,
  ({ this_player() }));
    tell_object(this_player(), RED + "\
Blood-red magik energy builds around you.....\n" + NORM);
     flames->reduce_strength(3 + random(3));
    call_out("do_incantation", 3, ({ this_player(), borg }));
    return 1;
}

void do_incantation(mixed *muppets)
{
    object fozzy, gonzo, kermit;

    fozzy = muppets[0];
    gonzo = muppets[1];
    if(!fozzy || !environment(fozzy))
      return;
    if(!gonzo || gonzo->query_prevent_shadow())
    {
      tell_room(environment(fozzy), "\
The magik power around " + (string)fozzy->query_name() +
" dies down...\n", ({ fozzy }));
      tell_object(fozzy, "\
The magik power around you dies down...\n");
      present(OBJID, fozzy)->ResetCasting();
      return;
    }
    tell_room(environment(fozzy), RED + "\n\
Flames explode from " + (string)fozzy->query_name() + 
" in a colossal burst!\n\n" + NORM, ({ fozzy }));
    tell_object(fozzy, RED + "\n\
Flames explode from you in a colossal burst!\n\n" + NORM);
    if(gonzo->encircled_with_flame())
      return;
    tell_room(environment(fozzy), RED + 
"A surge of flame encircles " + 
(string)gonzo->query_name() + "...\n" + NORM, ({ gonzo }));
    tell_object(gonzo,
RED + "A surge of flame encircles you...\n" + NORM);
    if(gonzo->encircled_in_flame())
      gonzo->encircle_off();
    kermit = clone_object(OBJDIR + "circle");
    kermit->start_shadow(gonzo);
    return;
}
