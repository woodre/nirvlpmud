inherit "/obj/monster.c";

/* if the monster is ready to smack */
   int is_preparing_attack;
object my_target;

reset(arg)
{
   object gold, what;
   ::reset(arg);
   if(arg) return;
   set_name("Beano");
   set_race("beano");
   set_alias("deathbeano");
   set_short("Deathbeano");
   set_long("This is Beano. This one is crazy.\n");
   set_level(3);
   set_hp(390);
   set_al(0);
   set_wc(6);
   set_ac(3);
   set_chance(1);
   set_spell_dam(4);
   set_spell_mess1("Beano does something to you.");
   set_spell_mess2("Beano ebverflugs you.");
   set_chat_chance(10);
   load_chat("Beano quibbles.\n");
   load_chat("Beano goes: wibble.\n");
   load_chat("Beano does something.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(2)+10);
   move_object(gold,this_object());
   what=clone_object("players/mizan/etheriel/items/thingamajig.c");
   move_object(what, this_object());
   
   /* reset our akid-pet ttacking variable */
   is_preparing_attack = 0;
}

/* bear in mind this is SO ghetto. Its also cheap.
* The target has no time to react or run. Our next example will
* use catch_tell() so a delay happens.
*/

init()
{
   /* Okay, interesting stuff happens here... */
   
   
   /* First we call our parent class... */
   ::init();
   
   /* Now when someone trips init, they might be a pet or kid.
   * This sample monster will attack pets. For kids, change the
   * line 'is_pet' to 'is_kid'.
   */
   
   
   /* so what happens here? We check if something is triggering init.
      * We then check to see if it is a pet.
      * Then we see if we are fighting. If all conditions are met, we pick
      * a fight. 
   */
   if(this_player() && 
         living(this_player()) &&
      call_other(this_player(), "is_pet") &&
      !is_preparing_attack,
      !query_attack())
   {
      /* we indicate that we are going to attack */
      is_preparing_attack = 1;
      my_target = this_player();
      
      /* reset our callout counter */
      remove_call_out("delayed_attack");
      
      /* we are going to call the delayed_attack() function in X heartbeats...
      */
      call_out("delayed_attack", 1);
   }
}

delayed_attack()
{
   object attacker_room;
   object my_room;
   
   /* reset this */
   is_preparing_attack = 0;
   say("called\n");
   
   if(!my_target) 
      {
      /* our object disappeared on us?     
      say("no target!");
      return 0;
   }
   
   my_room = environment(this_object());
   attacker_room = environment(my_target);
   
   say("called past first condition - " + my_target->query_name());
   
   if(my_room &&
         attacker_room &&
      my_room == attacker_room)
   {     
      say("Beano spots a delicious target and attacks!\n");
      
      this_object()->attack_object(my_target));
     say("attacking");
  }
  
  else
  {
  say("nothing");
     /* otherwise we do nothing. The object is no longer in our room. */
     return 0;
  }
  
  
}
