#include "../include/def.h"
#include "../include/macros.h"
#include "../include/ansi.h"

int x, strength;

object owner;

void reset(int arg)
{
    if(arg) return;
    call_out("blaze", 5);
}

void blaze()
{
    string msg;
    strength--;
    x ++;
    if(!environment() && root()) { return; }
    if(!environment() && !root()) { destruct(this_object()); return; }
    if(x >= 40 || !owner || !present(owner, environment()) || !strength)
    {
      tell_room(environment(), "\
The ebullient flame blazes quietly away...\n");
      destruct(this_object());
      return;
    }
    if(0 == random(3))
      msg = "The flames snap and pop...\n";
    else if(0 == random(3))
      msg = "Fire leaps into the air and sails back down...\n";
    else if(0 == random(3))
      msg = "Flames barely lick your flesh...\n";
    else if(0 == random(3))
      msg = "Heat rises from the twisted flame...\n";
    else if(0 == random(3))
      msg = "Smoke puffs from the flame...\n";
    else
      msg = "The fire burns from your hatred...\n";
    tell_room(environment(), msg);
    call_out("blaze", 5);
}

short()
{
    if(0 == random(3))
      return RED + "A twisting, wretched blaze" + NORM;
    else if(0 == random(3))
      return RED + "The flames of hatred" + NORM;
    else if(0 == random(3))
      return HIR + "A wildly burning bonfire" + NORM;
    else if(0 == random(3))
      return RED + "An unquenched, madly burning flame" + NORM;
    else
      return RED + "A demonic blaze" + NORM;
}

id(str)
{
    return str == "shardak_fire" || str == "blaze" ||
    str == "flames" || str == "bonfire" || str == "fire"
    || str == "flame";
}

long()
{
    return write("\
The heat assaults your senses and just looking at\n\
these twisted, maniacally burning flames, your throat\n\
parches dry..   The swirling chaotic inferno within\n\
is quite a sight to behold..  it is quite ominous...\n");
}

set_owner(O) { owner = O; }

add_strength(x) { strength += x; }
reduce_strength(x) { strength -= x; }

set_strength(x) { strength = x; }

status
get()
{
    if(this_player())
    if((string)this_player()->query_guild_name() != "shardak") {
    write("You burn your hand on the flame!\n");
    if(this_player()->query_level() >= 8)
    this_player()->hit_player(30 + random(30), "other|fire");
    }
}

query_strength() { return strength; }
