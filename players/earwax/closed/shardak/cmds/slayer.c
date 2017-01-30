#define TP this_player()
static object wep, shad;
#define CO clone_object

/*
* SLAYER spell for the Shardak guild
* by Dragnar, tampered with by Balowski
* rewritten by verte
*/
int busy;

#include "../std.h"
#include "../def.h"
#include "../tasks.h"
#include "../macros.h"
#define TOU(x) tell_object(User, x)
#define TRU(x) if(environment(User)) \
tell_room(environment(User), x, ({ User }))
inherit CMD;

status
main(string str)
{
   int             power;
   object  weapon;
   needrank(4);
   needtask(AVENGER_TASK);
   needmana(100);
   if(str) return 0;
   if(busy)
   {
      write("\
This action cannot be performed at the moment...\n\
The very smiths of darkness are at work with another Servant.\n");
      return 1;
   }
   if (present("slayer_sword", this_player())) 
   {
      write("\
Shardak does not allow you to have more than one Slayer Sword.\n");
      return 1;
   }
    if(environment(TP)->query_no_fight())
    {
      notify_fail("\
This room is protected by some sort of magical means.\n");
      return 0;
    }
   if((object)this_player()->query_attack())
   {
      write("You are too busy in combat.\n");
      return 1;
   }
   weapon = (object)this_player()->query_weapon();
   if(!weapon)
   {
      write("You must be wielding a sword...\n");
      return 1;
   }
   if(!weapon->id("sword") && !weapon->id("katana") && !weapon->id("blade")
      && !weapon->id("longsword"))

   {
      write("You must be wielding a sword...\n");
      return 1;
   }
   if((int)weapon->weapon_class() < 15 ||
      !weapon->is_weapon() ||
      (status)weapon->drop())
   {
      write("You cannot use this...\n");
      return 1;
   } 

   power = (
             ( (int)this_player()->query_guild_rank() * 8 ) + 
             ( (int)this_player()->query_level()      * 8 ) + 
             ( (int)weapon->weapon_class()            * 4 )
           );

   command("drop " + (string)weapon->query_name(), this_player());
   this_player()->add_spell_point(-100);
   if(!weapon) { write("Error\n"); return 1; }
   write("You drive your sword into the ground....\n");
   say((string)this_player()->query_name() + " drives " + 
        possessive(this_player())+" sword into the ground...\n");
   move_object(clone_object(OBJDIR +"slayer_block"), this_player());
   shad = clone_object(OBJDIR + "slayshad");
   shad->load_shadow(wep = weapon);
   call_out("quake_ground",2 + random(2),({ power, this_player(), 0 }));
   busy = 1;
   return 1;
}

quake_ground(mixed *stuff)
{
   int power, x;
   object User, slayer;
   object *inv;
   int check;
   User = stuff[1];
   check = stuff[2];
   check += 1;
   if(!User) { busy = 0; return; }
   if(check > 5)
      {
      TOU("You raise your head, covered in a stygian veil...\n"+
         "Grasping your new Slayer Sword, you rise to face your \
enemies anew.\n");
      TRU(User->query_name()+" raises "+possessive(this_player())
+" head...\n"+
         "Grasping "+possessive(this_player())+" Slayer Sword, "
         + subjective(this_player())+" rises to face "+
        possessive(this_player())+" enemies...\n");
      slayer = CO(OBJDIR +"slayer");
      power = stuff[0];
      slayer->set_amt(power);
      move_object(slayer, User);
      destruct(present("slayer_block", User));
      busy = 0;
      if(wep) destruct(wep);
      return;
   }
   else if(check > 4)
      {
      TOU("From the eclipse of shade rises a Slayer Sword...\n"+ 
         "You tremble in anticipation...\n");
      TRU("From the eclipse of shade rises a Slayer Sword....\n");
   }
   else if(check > 3)
      {
      TOU("A patch of darkness befouls the area.....\n"+
         "Dark as the blackness of the noonday night, it rolls in\n"+
         "and infests every pore of the area.....\n");
      TRU("A patch of darkness befouls the area.....\n"+
         "Dark as the blackness of the noonday night, it rolls in\n"+
         "and infests every pore of the area.....\n");
   }
   else if(check > 2)
      {
      TOU("The ground stops trembling....\n"+
         "The earth again responds to your touch.\n");
      TRU("The ground stops trembling....\n"+
         "The earth again responds to your touch.\n");
   }
   else if(check > 1)
      {
      TOU("\
The ground quakes madly!   Shaking and spinning, you\n\
fall onto the ground, wondering when the insanity will stop...\n");
      TRU("\
The ground quakes madly!   Shaking and spinning, you\n\
fall onto the ground, wondering when the insanity will stop...\n");
      User->hit_player(30 + random(20));
      inv = all_inventory(environment(User));
      for(x = 0; x < sizeof(inv); x++)
      if(living(inv[x]) && inv[x] != User)
         if(inv[x]->query_level() > 7)
         inv[x]->hit_player(10 + random(10), "other|earth");
   }
   else if(check > 0)
   {
      TOU("The world begins to whirl around you...  The vortical spin\n"+
         "sends you reeling about the room....\n");
      TRU(User->query_name()+" reels about the room....\n");
   }
   else
      {
      TOU("The sword glimmers faintly, and then disappears....\n"+
         "You hear the shudders of an earthquake rapidly approaching...\n");
      TRU("The sword glimmers faintly, and then disappears....\n"+
         "You hear the shudders of an earthquake rapidly approaching...\n");
   }
   call_out("quake_ground",2 + random(2),({ stuff[0], User, check }));
}
