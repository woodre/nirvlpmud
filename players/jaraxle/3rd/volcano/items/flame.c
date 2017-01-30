mixed
basename(object ob)
{
    string a, b;
    sscanf(file_name(ob), "%s#%s", a, b);
    return a ? a : file_name(ob);
}

#include "/players/vertebraker/swamp/define.h"

#define new "/players/vertebraker/closed/shardak/obj/etorch"

inherit ITEM;
int st;

get() { return 0; }

reset(arg) {
   if(arg) return;
   set_id("flame");
   set_alias("verte_eternal_flame");
   set_long(
      "     a darkened flame rises from within the room.\n"
      +   "     it is fed even though there is no available\n"
      +"     fuel. you wonder if this somehow has meaning?\n");
   set_light(2);
   call_out("fade",100);
}
short() {
   if(!creator(ENV())) return (destruct(this_object()), 0);
   if(!st) return "A "+RED+"blood red"+NORM+" flame, burning brightly";
   if(st == 1) return "A "+RED+"blood red"+NORM+" flame, waning a bit...";
   if(st == 2) return "A " + BOLD + BLK + "deathly grey" + NORM + " flame";
   if(st == 3) return "A "+HIW+"white hot"+NORM+" flame";
   if(st == 4) return "An "+GRN+"eerie green"+NORM+" flame";
}

fade() 
{
   if(!USER) return;
   switch(random(3)) 
   {
      case 0: tell_room(USER,BOLD+"The flames darken....\n"+NORM); break;
      case 1: tell_room(USER, BOLD + "Shadows dance across the room.\n" + NORM); break;
      case 2: tell_room(USER, "A blood-red spark flies from the flame!\n"); break;
   }
   if(st < 4) st += 1;
   if(st == 4) st = 0;
   call_out("fade",50);
   return 1; }

/* code added 5.19.2001 */
void
init()
{
    ::init();
    add_action("cmd_light", "light");
}

status
cmd_light(string arg)
{
    object a;

    if((string)this_player()->query_guild_name() != "shardak")
      return 0;

    if(arg == "torch" || arg == "eternal torch")
    {
      if(!(a = present("torch", this_player())) ||
         basename(a) != "players/saber/stuff/etorch" &&
         !a->shardakEternalTorch())
      {
        write("You do not have an Eternal Torch.\n");
        return 1;
      }
      if((status)a->shardakEternalTorch())
      {
        write("The Eternal Torch has drank from the Eternal Flame.\n");
        return 1;
      }
      write("You light the Eternal Torch from the Eternal Flame.\n");
      tell_room(environment(), "\
The eternal flame kicks up sparks!\n");
      destruct(a);
      move_object(clone_object(new), this_player());
      return 1;
    }
}
