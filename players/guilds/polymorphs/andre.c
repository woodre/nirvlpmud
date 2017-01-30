inherit "obj/monster";

#include "/players/mizan/esc.h"
#include "definitions.h"

#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define BOLDBLUE ESC + "[1m" + ESC + "[34m"
#define OFF ESC + "[0m"

/*
 * This is Andre the Giant.
 * 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

object last_converser;
object victim;
object follow;

string kill_creature;
string vibe_alias;
string vibe_name;      /* The name we appear on the vibe channel as */

int hp_buffer;

status is_busy;


reset(arg)
{
   object gold,armor,wrench;
   ::reset(arg);
   if(arg) return;

   vibe_name = "Andre the Giant";
   vibe_alias = "Andre";
   
   /* descriptions */
   set_name(vibe_name);
   set_race("andre");
   set_alias("mizPet");
   set_short("Andre the Giant");
   set_long("This is Andre the Giant.\n"+
    "He is seven feet five inches tall, and five hundred twenty pounds.\n"+
    "These numbers alone do not convey the massive size this man has.\n"+
    "Andre the Giant has a posse.\n");
   
   /* vital stats */
   set_level(18);
   set_hp(100000);
   set_al(750);
   set_wc(35);
   set_ac(30);

   /* gold */
   gold = clone_object("obj/money");
   gold->set_money(random(20));
   move_object(gold,this_object());

   move_object(this_object(), "/players/mizan/workroom");
}

heart_beat()
{
   ::heart_beat();
}

attack_object(ob)
{
   if (ob == this_object()) return;

   ::attack_object(ob);
}

guild_tell(str)
{
   string temp, nonansi;
   temp = BOLDBLUE + ">> " + vibe_name + " bellows: " + OFF + str + "\n";
   nonansi = ">> " + vibe_name + " bellows: " + str + "\n";
   MASTER_R->guild_echo(temp);
   log_file("mizan.poly_vibes", nonansi);
   return 1;
}

guild_emote(str)
{
   string temp, nonansi;
   temp = BOLDBLUE + ">> (bellow) " + OFF + vibe_name + " " + str + "\n";
   nonansi = ">> (bellow) " + vibe_name + " " + str + "\n";
   MASTER_R->guild_echo(temp);
   log_file("mizan.poly_vibes", nonansi);
   return 1;
}

catch_tell(str) 
{
   object from;
   string a, b, c;
   object ob;
   object next_dest;
   string next_out;
   string name_oc;
   from = this_player();
   if(!from) return 1;

/*
   if(remote_tl && !present(owner, environment(this_object()))) 
   {
      tell_object(owner, "%" + str);
      return 1;
   }
   
   if(sscanf(str, "%s tells you: %s", a, b) == 2) 
   {
      tell_object(owner,"**" + curr_name + "** "+a+" tells " + curr_name + ": "+b+"\n");
      return 1;
   }

   if(sscanf(str, "%s whispers to you: %s", a, b) == 2) 
   {
      tell_object(owner,"**" + curr_name + "** "+a+" whispers to " + curr_name + ": "+b+"\n");
      return 1;
   }
 */


}

parse_guild_tell(plyr, str)
{
   string tmp, tmp2, tmp3, tmp4;
   tmp = lower_case(str);
   
   last_converser = plyr;
   
   if(tmp == "hello andre" || tmp == "hiya andre" || tmp == "hi andre" || 
      sscanf(tmp, "hello andre!%s", tmp2) == 1  ||
      sscanf(tmp, "hiya andre!%s", tmp2) == 1  ||
      sscanf(tmp, "hi andre!%s", tmp2) == 1)
   {
      remove_call_out("message_hello");
      call_out("message_hello", 4);
   }

   if(sscanf(str, "%s, please %s %s", tmp2, tmp3, tmp4) == 3)
   {
      tmp2 = lower_case(tmp2);
      tmp3 = lower_case(tmp3);
      tmp4 = lower_case(tmp4);
      
      if(tmp2 && tmp2 != "andre") return 1;
      
      /* Parse all of commands here */
      if(tmp3 && tmp3 == "kill")
      {
         if(is_busy)
         {
            remove_call_out("errormsg_busy");
            call_out("errormsg_busy", 5);
            return 1;
         }
         
         kill_creature = tmp4;
         remove_call_out("message_kill_creature");
         call_out("message_kill_creature", 5);
         is_busy = 1;
      }
      else if(tmp3 && tmp3 == "report")
      {
         remove_call_out("message_report");
         call_out("message_report", 5);
         return 1;
      }
      else
      {
         remove_call_out("errormsg_what");
         call_out("errormsg_what", 5);
         return 1;
      }
      
   }

   if(tmp == "goodbye andre" || tmp == "bye andre" || tmp == "seeya andre" || 
      sscanf(tmp, "goodbye andre!%s", tmp2) == 1  ||
      sscanf(tmp, "bye andre!%s", tmp2) == 1  ||
      sscanf(tmp, "seeya andre!%s", tmp2) == 1)
   {
      remove_call_out("message_goodbye");
      call_out("message_goodbye", 4);
   }
   
}

message_hello()
{
    if(last_converser && last_converser->query_gender() == "female")
        guild_tell("Hello Lady!");
    else guild_tell("Hello boss!");
}

message_goodbye()
{
    if(last_converser && last_converser->query_gender() == "female")
       guild_tell("Goodbye Lady!");
    else guild_tell("Goodbye boss!");
}

message_kill_creature()
{
   object ob, room;
   room = environment(this_object());

   /* We have been ordered to attack a creature. */
      
   if(last_converser && room)
   {
      ob = present(kill_creature, room);
      
      if(!ob)
      {
         /* The creature does not exist in the same room as us. */
         remove_call_out("message_kill_notarget");
         call_out("message_kill_notarget", 5);
         return 1;
      }
      else
      {
         /* Now check if the object is a creature and if it is a valid target */
         if(!living(ob))
         {
            remove_call_out("errormsg_not_living");
            call_out("errormsg_not_living", 5);
            return 1;
         }
         else if(ob->is_player())
         {
            remove_call_out("errormsg_is_player");
            call_out("errormsg_is_player", 5);
            return 1;
         }
         
         /*Okay. We can attack the creature. Queue it up. */
         victim = ob;
         remove_call_out("message_kill_confirmed");
         call_out("message_kill_confirmed", 5);
         is_busy = 1;
         return 1;
      }
   }
}


errormsg_is_busy()
{
   if(last_converser && last_converser->query_gender() == "female")
       guild_tell("Hello Lady! I am busy right now...");
   else guild_tell("Hey boss... I am busy right now.");
   is_busy = 0;
   return 1;
}


errormsg_is_player()
{
   if(last_converser && last_converser->query_gender() == "female")
       guild_tell("Hello Lady! That person is a player...");
   else guild_tell("Hey boss... That person is a player.");
   is_busy = 0;
   return 1;
}

errormsg_what()
{
   if(last_converser && last_converser->query_gender() == "female")
       guild_tell("Hello Lady! I don't understand what you want me to do...");
   else guild_tell("Hey boss... I don't understand what you want me to do.");
   is_busy = 0;
   return 1;
}


message_kill_confirmed()
{
   object room1, room2;

   if(victim)
   {
      room1 = environment(victim);
      room2 = environment(this_object());

      if(room1 && room2 && room1 == room2)
      {
         if(last_converser->query_gender() == "female")
             guild_tell(victim->short() + ", I will start killing it Lady!");
         else guild_tell(victim->short() + ", I will start killing it boss!");
         
         this_object()->attack_object(victim);
         remove_call_out("tick_check_target");
         call_out("tick_check_target", 4);
         is_busy = 1;
      }
      else
      {
          guild_tell(victim->short() + " is not in the same room as me anymore.");
          is_busy = 0;
      }
   
   }
   else
   {
      if(last_converser->query_gender() == "female")
          guild_tell("Lady... I cannot find the '" + kill_creature + "' no more.");
      else guild_tell("Boss... I cannot find the '" + kill_creature + "' no more.");
      is_busy = 1;
   }
}

tick_check_target()
{
   object room1, room2;

   if(victim)
   {
      room1 = environment(victim);
      room2 = environment(this_object());

      if(room1 && room2 && room1 == room2)
      {
         remove_call_out("tick_check_target");
         call_out("tick_check_target", 4);
      }
      else
      {
          guild_tell(victim->short() + " is not in the same room as me anymore.");
          is_busy = 0;
      }
   
   }
   else
   {
      if(last_converser->query_gender() == "female")
          guild_tell("Lady... I think the '" + kill_creature + "' is dead.");
      else guild_tell("Boss... I think the '" + kill_creature + "' is dead.");
      is_busy = 0;
   }
}

message_kill_notarget()
{
   if(last_converser && last_converser->query_gender() == "female")
       guild_tell("Hello Lady! I don't find one of those here.");
   else guild_tell("I don't find one of those here, boss...");
   is_busy = 0;
}

message_report()
{
   object ob, room;
   string temp;
   
   ob = this_object()->query_attack();
   room = environment(this_object());

   if(room) temp = "I am in '" + room->short() + "', ";
   else temp = "I don't know where I am,";
   
   if(ob) temp = temp + "I am fighting '" + ob->query_name() + "', ";
   else temp = temp + "I am not fighting, ";
   
   if(follow) temp = temp + "and I am following " + follow->query_name();
   else temp = temp + "and I am not following anybody.";
      
   guild_tell(temp);
}


