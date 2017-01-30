#define AMMOTYPE "chickens"
inherit "obj/weapon";

/**
 * This is a WIZARD ONLY MODEL!!!!!
 *
 *
 *
 */

int pleva;
int total_damage;
string battle_prefix;
string battle_noun;
string battle_verb;

reset(arg) 
{
   ::reset(arg);
   pleva=1;
   set_name("FAA Chicken flexgun");
   set_alias("flexgun");
   set_class(666);
   set_weight(53);
   set_value(4667000);
   set_hit_func(this_object());

   battle_prefix = 
      ({
      "The FAA Chicken flexgun cuts loose and",
      "An explosion of sticky meat jolts you and",
      "The FAA Chicken flexgun erupts violently and",
      "The FAA Chicken flexgun rips into action and",
      "All hell breaks loose as",
      "You cringe in terror as",
      "Death erupts from the FAA Chicken flexgun as",
      "Pain is dealt from the FAA Chicken flexgun as",
      "There is no escaping the FAA Chicken flexgun as",
      "You gasp in terror as",
      "The FAA Chicken flexgun spits death as",
      "The FAA Chicken flexgun bursts into action as",
      "BLOMP! BLOMP! BLOMP! is all you hear as",
      "The FAA Chicken gun fires off and",
      "The FAA Chicken gun thunders violently and",
      });

   battle_noun =
      ({
      "a frozen chicken",
      "a screaming chicken",
      "a frozen turkey",
      "a chicken",
      "a smoked chicken",
      "a flaming chicken",
      "a burning chicken",
      "a turtle",
      "a frozen rabbit",
      "a flaming rabbit",
      "a molten chicken",
      "an explosive chicken",
      "a firey chicken",
      "a Peking duck",
      "a bag of frozen hamsters",
      "a box of frozen gerbils",
      "the head of Barney",
      "the sticky head of Guest",
      "a can of rocks",
      "a box of banana peels",
      "a flaming pig",
      "a fish head",
      "a tree trunk",
      "a bowling ball",
      });

   battle_verb =
      ({
      "pelts",
      "disintegrates into",
      "splinters ruthlessly into",
      "barrels into",
      "explodes into",
      "detonates into",
      "blasts into",
      "utterly destroys",
      "savagely rips into",
      "savagely pummels",
      "pummels",
      "savagely blasts",
      "blasts",
      "rips a new asshole in",
      "disintegrates the abdomen of",
      "decimates",
      "ruthlessly violates",
      "ruthlessly barrels into",
      "ruthlessly pelts",
      "punches a BIG hole into",
      });
      

}

init() {
  ::init();
  add_action("load","load");
  add_action("adjust_dial","shape");
}

short() 
{
   string doh;
   int ammo;
   object ob;
 
   ob = present(AMMOTYPE, this_object());
   if(ob) 
   {
      ammo = ob->query_ammo();
   }
   doh = "The FAA Chicken flexgun Mk4 [" + ammo + "]";
   
   if(wielded) doh = doh + " (wielded)";

   if(this_player() && this_player()->query_level() > 39)
      doh = doh + " <Total damage inflicted: [" + total_damage + "]>";

   return doh;
}

long() 
{
   if(this_player()) say(capitalize(this_player()->query_name()) + 
      " gazes reverently at the FAA Chicken flexgun.\n");
 
   write("This is a large, elegant contraption that shoots frozen chickens.\n"+
      "It is the luggable version of the infamous FAA Chicken Gun used to\n"+
      "fire frozen poultry on aircraft at speeds of 900MPH to test systems\n"+
      "survivability.\n");
   write("Now imagine something that fires three times that speed, and its\n"+
      "portable. Frock! Today is a good day to make enemies.\n");

   write("\nIt appears that you can 'shape' the barrel of this weapon.\n");
   
   if(pleva == 4) 
      write("The barrel is flat, like a vacuum cleaner nozzle.\n");

   if(pleva == 2)
      write("The barrel is spread wide and seems to be fully opened up.\n");

   if(pleva == 1)
      write("The barrel opening is narrow and seems to be somewhat smaller than usual.\n");
}

load(str) 
{
   object ammo,all_in_ob;
   int round_weight;
   int rounds2;
   if(!str || str != "flexgun") return 0;
   all_in_ob = all_inventory(this_object());
   if(sizeof(all_in_ob) > 18) 
   {
      write("There is no room for more chickens.\n");
      return 1;
   }
   ammo = present(AMMOTYPE, this_player());
   if(!ammo) 
   {
      write("You don't have any bags of frozen chickens.\n");
      return 1;
   }
   move_object(ammo, this_object());
   round_weight=ammo->query_weight();
   this_player()->add_weight(-round_weight);
   rounds2=ammo->query_ammo();
   if(!rounds2 || rounds2 > 99990) 
   {
      destruct(ammo);
      write("The FAA Chicken flexgun rejects the crappy ammo.\n");
   }
   write("You stuff a bag of frozen chickens into the flexgun.\n");
   write("There are [" + rounds() + "] rounds remaining.\n");
   say(capitalize(this_player()->query_name()) + 
      " stuffs a bag of frozen chickens into an FAA Chicken flexgun.\n");
   return 1;
}

weapon_hit(attacker) 
{
   object clip;
   int ammo;
   string attack_message;

   clip = present(AMMOTYPE,this_object());
   
   if(clip)
   {
    
      if(rounds() < (pleva * 18)) 
      {
          write("There are not enough chickens to make the flexgun work properly!\n"+
          "It begins to chuggle and convulse violently.\n");
          return -22;
      }

      if(pleva > 1) tell_room(environment(this_player()), "* * *  B C H O O M ! ! ! * * *\n");
  
      if(pleva == 2 || pleva == 1) 
      {
         attack_message = battle_prefix[random(sizeof(battle_prefix))] +
            " " + battle_noun[random(sizeof(battle_noun))] + 
            " " + battle_verb[random(sizeof(battle_verb))] +
            " " + capitalize(attacker->query_name()) + "!\n";
         
         tell_room(environment(this_player()), attack_message);
      }

      if(pleva == 4) 
      {
         tell_room(environment(this_player()), "The flattened barrel of the flexgun speads guts and destruction everywhere.\n");
         say(capitalize(attacker->query_name()) + " is caught in the middle of the fanned blast.\n");
      }
    
      clip->lose_ammo(pleva * 18);
  
      if(pleva == 4) area_checked_hit();
      if(pleva == 2) checked_hit(800);
      if(pleva == 1) checked_hit(80);

      if(!rounds()) 
      {
         destruct(clip);
         write("You've shot the last of your chickens!\n");
         return 1;
      }
    
      if(1==random(10) && pleva > 1 && this_player()->query_level() < 20) 
      {
         write("The recoil of the blast knocks you off your feet!\n");
         say((this_player()->query_name())+ " is rocketed clear across the room from the recoil.\n");
         this_player()->run_away();
         return 1;
       }
      return 1;
   }
   write("Your flexgun is out of chickens!\n");
   return -21;
}

checked_hit(arg) 
{
   int a_hp,a_dam;
   object a_attack;
   a_attack=this_player()->query_attack();
   if(a_attack) 
   {
      a_hp=a_attack->query_hp();
      a_dam=random(arg);
      if(!a_attack->query_npc() && a_dam > 1199) a_dam = 1200;
      if(a_hp < a_dam || a_hp == a_dam) a_dam = a_hp - 1;
      a_attack->hit_player(a_dam);
      total_damage = total_damage + a_dam;
   }
}

area_checked_hit(arg) 
{
   object foo;
   int dam_divisor,dam_charges;
   dam_divisor = count_livings();
   if(dam_divisor > 2) dam_divisor = dam_divisor - 1;
   dam_charges = 200 / dam_divisor;
   foo=first_inventory(environment(this_player()));
   while(foo) 
   {
    object foo2;
    foo2 = foo;
    foo = next_inventory(foo);
    if(living(foo2)) 
    {
      if(foo2->query_npc()) 
      {
        int foo_hp,foo_damage;
        foo_hp=foo2->query_hp();
        foo_damage=random(dam_charges);
        if(foo_hp < foo_damage || foo_hp == foo_damage) foo_damage = foo_hp - 1;
        tell_room(environment(this_player()),
        capitalize(foo2->query_name()) + " is battered by the wave of molten flesh!\n");

        /* CHECK FOR FIGHT TOO */
        foo2->attack_object(this_player());
        foo2->hit_player(foo_damage);
        total_damage = total_damage + foo_damage;
      } else {
        tell_room(environment(this_player()),
        capitalize(foo2->query_name()) + " escapes harm.\n");
      }
    }
  }
  return 1;
}

count_livings() 
{
   object moo;
   int mmmrugs,whees;
   moo=first_inventory(environment(this_player()));
   while(moo) 
   {
      object squish;
      squish = moo;
      moo = next_inventory(moo);
     if(living(squish)) whees = whees + 1;
   }
   return whees;
}

adjust_dial(str) 
{
   int temp_pleva;
   if(str != "barrel" || !str) return 0;
   
   if(environment(this_object()) != this_player()) 
   {
      write("You have to get the FAA Chicken flexgun first.\n");
      return 1;
   }
   
   say(capitalize(this_player()->query_name()) + " shapes the barrel on the FAA Chicken flexgun.\n");
   write("You adjust the lever which shapes the barrel.\n");
   
   if(pleva == 4) 
   {
      write("The barrel of the FAA Chicken flexgun narrows and shrinks to half its size.\n"+
      "You can barely stick your fist inside it.\n");
      say("The barrel of the weapon shrinks and narrows into a purposeful gaze.\n");
      temp_pleva = 1;
   }

   if(pleva == 2) 
   {
      write("The barrel of the FAA Chicken flexgun seems to flatten out and expand.\n"+
      "It's scope and spread of its attack seems much wider too.\n");
      say("The barrel expands and flattens.\n");
      temp_pleva = 4;
   }

   if(pleva == 1) 
   {
       write("The barrel of the FAA Chicken flexgun expands biggly.\n"+
       "You can fit your head in it now.\n");
       say("The barrel keeps expanding until it is as big as your head. Holy shit!\n");
       temp_pleva = 2;
   }
   
   pleva = temp_pleva;
   return 1;
}

rounds() {
  object rc;
  int i;
  rc=present(AMMOTYPE, this_object());
  i=rc->query_ammo();
  return i;
}

can_put_and_get() { return 1; }

query_save_flag() { return 1; }

