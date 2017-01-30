/*
* Object for STORM spell by Dragnar. Tinkered with by Balowski
* It is a slow spell, where damage is inflicted during the storm
* After 10s: spell_object(5 + random(25))
* After 16s: spell_object(5 + random(25))
* After 22s: spell_object(15 + random(22))
* During the storm other attack spells have a 75% fail chance (with cost)
* If the caster runs away the storm will follow him and punish him
*/
#pragma strict_types
#include "/players/vertebraker/ansi.h"
#define USER environment()
#define ATT ((object) USER->query_attack())
#define NAME(x) capitalize(x->query_real_name() || "someone")
#define ROOM(x) tell_room(environment(USER), x)

object          room;           /* remember where this was cast */


status id(string str) { return str == "lightningspell"; }
status get()   { return 1;}    /* can get */
status drop()  { return 1;}    /* can't drop */

void
init()
{
   /* no other attack spells can be cast during the storm */
   add_action("frozen", "burn");
   add_action("frozen", "waste");
   add_action("frozen", "breath");
   add_action("frozen", "dagger");
   add_action("frozen", "sonic", 2);
   add_action("frozen", "fireball", 2);
   add_action("frozen", "shock", 2);
   add_action("frozen", "missile", 2);   
   call_out("start", 4);
   if(USER && environment(USER)) room = environment(USER);
}

status
frozen(string arg)
{
   if (!random(4))
      return 0;
   else {
      write("Your spell fails.\n");
      this_player()->add_spell_point(-random(30));
      return 1;
   }
}

void
punish()
{
   tell_room(room, "The storm rolls after " + NAME(USER) +
      ".\nYou hear thunder in the distance.\n");
   ROOM(BOLD + BLK + "Dark clouds come rolling in after " + NAME(USER) + ".\n"+
        HIY + "\nLightning strikes!\n"+NORM);
   tell_object(USER, "The storm has turned against you!\n");
   if (interactive(USER)) {
      USER->hit_player(20 + random(20), "other|dark");
      USER->add_spell_point(-20 - random(5));
   }
   call_out("end", 5);
}

void
start()
{
   ROOM(BOLD+BLK+"You see a mass of black clouds moving toward you.\n"+NORM);
   call_out("bolt", 6);
}

void DoBolt();
void DoLightning();
void DoBall();

void bolt() {
   string str;
   str = catch(DoBolt());
   if (str && USER) tell_object(USER, str);
   call_out("lightning", 6);
}

void lightning() {
   string str;
   str = catch(DoLightning());
   if (str && USER) tell_object(USER, str);
   call_out("ball", 6);
}

void ball() {
   string str;
   str = catch(DoBall());
   if (str && USER) tell_object(USER, str);
   call_out("end", 5);
}

void
end()
{
   ROOM("The storm breaks up and the sky is clear once again.\n");
   destruct(this_object());
}

void
DoBolt()
{
   object enemy;
   
   if (USER && room != environment(USER)) {
      punish();
      return;
   }
   if (!(USER && (enemy = ATT))) {
      end();
      return;
   }
   if (enemy->is_player())
      tell_object(USER, "The storm cannot harm other players.\n");
   else {
      ROOM("\
         A "+HIC+"lightning blue bolt"+NORM+" races down from above.\n\
         The bolt slams into the chest of " + NAME(enemy) + "!\n");
      environment()->spell_object(enemy, "bolt", 5 + random(25), 0);
      environment()->set_spell_dtype("other|electric");
   }
}

void
DoLightning()
{
   object enemy;
   
   if (USER && room != environment(USER)) {
      punish();
      return;
   }
   if (!(USER && (enemy = ATT))) {
      end();
      return;
   }
   if (enemy->is_player())
      tell_object(USER, "The storm cannot harm other players.\n");
   else {
      ROOM("The sky lights up as "+HIY+"lightning"+NORM+
           " shoots from the sky and shocks " +
         NAME(enemy) + ".\n");
      environment()->spell_object(enemy, "lightning", 5 + random(25), 0);
      environment()->set_spell_dtype("other|electric");
   }
}

void
DoBall()
{
   object enemy;
   
   if (USER && room != environment(USER)) {
      punish();
      return;
   }
   if (!(USER && (enemy = ATT))) {
      end();
      return;
   }
   if (enemy->is_player())
      tell_object(USER, "The storm cannot harm other players.\n");
   else {
      ROOM("\
         The dark clouds glow blood red as a ball of fire falls from the storm.\n" +
         NAME(enemy) + " is totally engulfed by a "+HIR+"huge ball of flames"+NORM+"!\n");
      environment()->spell_object(enemy, "ball", 15 + random(22), 0);
      environment()->set_spell_dtype("other|fire");
   }
}

int
clean_up(int refcount)
{
   if (refcount)
      return 1;
   destruct(this_object());
}
