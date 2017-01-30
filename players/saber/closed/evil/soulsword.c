#define tp this_player()->query_name()
int w, POISON;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name("soulblade");
     set_alias("blade");
     set_short("The Soulblade of the Magi");
     set_long("A long blade covered with silver runes and dark symbols.\n"+
       "Legend has it that the Soulblade was forged on the bones of a dead god.\n"+
       "You know that this blade was not ment for use by mortals.\n");
     set_read("I, Saber have forged this blade for the use of the Magi of Nirvana.\n"+
        "Let it bring terror and chaos to all who wield it.\n");
     set_class(50);
     set_weight(0);
     set_value(50000);
     set_hit_func(this_object());
}


weapon_hit(attacker){

 if((this_player()->query_level()) < 21)  {

  write("Mortals were not ment to use the Soulblade...\n\n"+
    "You scream in agony as the blade eats part of your soul.\n\n");
    this_player()->hit_player(random(70));
  return 1;
        }

  if((this_player()->query_level()) > random(400))  {

write("Your blade cleaves through the flesh of "+attacker->query_name()+" and cuts away at their soul.\n");
say(tp+"'s Soulblade cuts away a part of "+attacker->query_name()+"'s soul.\n");

if(attacker->is_pet())  {
if((this_player()->query_level()) > random(300))  {

write("The runes on your Soulblade flare as you hit "+attacker->query_name()+".\n\n"+
  "You cut a hole through "+attacker->query_name()+".\n"+
  "\nYou reach in and pull out part of the SOUL of "+attacker->query_name()+".\n\n");
say("The runes on "+tp+"'s Soulblade flare as "+this_player()->query_pronoun()+" hits "+attacker->query_name()+".\n"+
  "\n"+
  tp+" cuts a hole through "+attacker->query_name()+".\n"+
  "\n"+
  tp+" reaches in and pulls out part of the SOUL of "+attacker->query_name()+".\n\n");
    attacker->heal_self(-40);
    }
    }

if((this_player()->query_level()) > random(600))  {

if(POISON > 0)  {
move_object(clone_object("/players/saber/closed/poison.c"),attacker);
write("\nYour blade glows an evil purple as it poisons "+attacker->query_name()+".\n");
say("\n"+tp+"'s Soulblade glows an evil purple as it poisons "+attacker->query_name()+".\n");
        }
        }
  return 40;
    }
    return;
}

init()  {
  ::init();
   add_action("msg_wield","wield");
   add_action("poison","poison");
        }

msg_wield()  {
  write("\nYou feel the power of the Soulblade surge through your body.\n\n");
  say("\nA chill passes through your soul.\n\n");
        }

poison()  {
  if(POISON != 1) POISON = 1;
  else POISON = 0;
  return 1;
        }
