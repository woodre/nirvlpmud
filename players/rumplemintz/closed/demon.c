inherit "obj/monster";
string owner,chat,attacker;
int i;
object weapon,armor;

init(arg)
{
   ::init() ;
   add_action("dodge","zap");
   add_action("dodge","dest");
   add_action("ignore","slap");
   add_action("ignore","puke");
   add_action("ignore","knee");
   add_action("ignore","kiss");
   add_action("ignore","hug");
   add_action("ignore","love");
   add_action("ignore","growl");
   add_action("silence","silence");
   add_action("ignore","hold");
   add_action("ignore","kick");
   add_action("ignore","nudge");
   add_action("ignore","pat");
   add_action("purr","pet");
   add_action("ignore","poke");
   add_action("ignore","spank");
   add_action("ignore","drool");
   add_action("ignore","cuddle");
   add_action("ignore","fart");
   add_action("ignore","french");
   add_action("ignore","french");
   add_action("ignore","bearhug");
   add_action("ignore","laugh");
}

reset(arg)
{
   ::reset(arg);
   if(!arg)
      {
      weapon=clone_object("players/rumplemintz/weapon/demonsword");
      name="demonsword";
      move_object(weapon, this_object());
      command("wield "+name, this_object());
      armor=clone_object("players/rumplemintz/armor/demonarmor");
      move_object(armor, this_object());
      command("wear garb", this_object());
      set_name("demon");
      set_short("Demon Guardian of Rumplemintz");
      set_aggressive(0);
      set_long("A massive Black Guardian Demon.\n He is assigned the task\n"+
         "of making mince-meat of anyone who tries to touch Rumplemintz.\n"+
         "It looks like he could probably kick your ass with his \n"+
         "equipment.  I'd advise against attacking him also.\n");
      set_race("demon");
      set_ac(5);
      chat = allocate(5);
      chat[0] = "The Guardian eyes you with suspicion.\n";
      chat[1] = "The Guardian sharpens his claws.\n";
      chat[2] = "The Guardian thinks he might have to kill you.\n";
      chat[3] = "The Guardian seems to be on the brink of battle.\n";
      chat[4] = "The Guardian looks cautiously all around.\n";
      this_object()->load_chat(20,chat);
   }
}

purr(str)
{
   if(str = "demon")
      {
      write("You rub the Guardian's back scales.\n");
      say(""+this_player()->query_name()+" pets the Guardian Demon.\n");
      return 1;
   }
   return 0;
}

do_damage()
{
   say(""+this_player()->query_name()+" foolishly attacks Guardian and gets BASHED in the head!\n");
   write("The Guardian knocks you out with a single blow.\n");
   write("You almost die !!!\n");
   i = this_player()->query_hp();
   i+=-10;
   this_player()->heal_self(-i);
   write("The Guardian decides not to destroy you.\n");
   write("You feel VERY lucky.\n");
   this_player()->stop_fight();
   this_object()->stop_fight();
   return 0;
}

heart_beat()
{
  if(!environment())  set_heart_beat(0); return; 
   ::heart_beat();
   owner = find_player("rumplemintz");
   if(!owner || !living(owner))
      {
      move_object(this_object(),"players/rumplemintz/workroom");
      set_heart_beat(0);
   }
   if(!present(owner))
      {
      move_object(this_object(),environment(owner));
      write("An evil looking Guardian Demon wanders in.\n");
      say("The Guardian Demon pushes people out of his way as he enters.\n");
   }
}

dodge(arg)
{
   if(arg = "demon")
      {
      if (this_player()->query_real_name() !="rumplemintz") {
         say(""+this_player()->query_name()+" foolishly tries to ZAP the Guardian.\n");
         write("The Guardian Demon dodges your lame attack!\n");
         return 1;
      }
   }
}

ignore(arg)
{
   if(!arg)
      {
      return 0;
   }
   if(arg == "demon")
      {
      if (this_player()->query_real_name() != "rumplemintz") {
         write("The Guardian ignores your worthless attempts to get his attention.\n");
         write("Then suddenly he knees you, sending you writhing to the floor in pain.\n");
         say(""+this_player()->query_name()+" tries to irritate the Guardian...and it\n"+
            "works!  "+this_player()->query_name()+" falls to the ground after a single\n"+
            "blow to the stomach!\n");
         return 1;
      }
   }
   return 0;
}

silence()
{
   i == 0;
   write("You eye the Demon nastily!\n");
   i == 1;
   if(i != 1 || i !=0)
      {
      i == 0;
   }
   if(i == 1)
      {
      write("You force the Demon to shut up!\n");
      say("The Demon shuts his mouth because "+this_player()->query_name()+" is mad.\n");
      i == 0;
      return 1;
   }
   if(i == 0)
      {
      write("The Demon comes back to his normal composure.\n");
      say(""+this_player()->query_name()+" gives the Demon permission to be normal.\n");
      i == 1;
      return 1;
   }
   return 0;
}
