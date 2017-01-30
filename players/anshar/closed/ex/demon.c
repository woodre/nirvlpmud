/* approved by Mythos on <6-19-96>
   if anyone has a problem with this monster 
  please contact me (mythos)
  btw note the heart_beat().. this monster does double attack
  ths i have allowed for the wc of rnd(20) + 16 of average 26 instead of the prescribed 30..
*/

/*  I've changed it some since it was approved.  The wc was raised a bit and hp raised.
    Look at the heart_beart.  It attackes more than once a round.  The
average is about 1.75 attacks per round.  Its been seen to
get up to seven attacks in a round.  It hits everything that
is attacking it.  They don't like parties. :)  (Llew) */

inherit "obj/monster";

reset(arg) {
   string adj;
   ::reset(arg);
   adj=({"grotesque","deformed","squat","mutated","bloody","writhing","black","green",
      "rippling","irate","snivelling","decayed","screaming","horrible","putrid",
      "smelly","yellow","rotting","horned","huge","barbed","infuriated","maniacal",
      "pestulent","scaled","angry","insane","wailing","psychotic","deranged","cackling"});
if(!arg) {
   object gold;
   gold=clone_object("/obj/money");
   gold->set_money(random(5000)+2300);
   move_object(gold,this_object());
   set_name("xetra");
   set_level(20);
   set_race("demon");
   set_hp(random(300)+400);
   set_al(-1000);
   set_aggressive(1);
   set_short("A "+adj[random(sizeof(adj))]+" Xetra");
   set_long("\tA Xetra sucking the light from all around.  Bigger and bigger he\n"+
      "becomes with each particle of blue light.  The light touches the skin of the\n"+
      "Xetra and fades to nothing.\n");
   set_wc(random(18)+20);
   set_ac(random(8)+7);
   set_dead_ob(this_object());
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood","thrashed"," with blood dripping claws","sliced"," cleanly","cut","","grazed","","scratched"," a glancing blow"}));
   set_chance(10);
   set_spell_mess2("The Xetra reaches into your soul with icy fingers.\n"+
      "Cold evil invades your blood, draining your life.");
   set_spell_mess1("The Xetra eats at a soul.");
   set_spell_dam(20);
   set_a_chat_chance(10);
   load_a_chat("The Xetra eats the blue light.\n");
   load_a_chat("Xetra says:  Hurocdt rufk tri!\n");
   load_a_chat("Xetra says:  Tlurrk bsiri corr.\n");
   load_a_chat("The Xetra reaches for your soul.\n");
}
}

heart_beat() {
   object *ri,first;
   int X,x,so;
   ::heart_beat();
   if(attacker_ob==this_object() && !random(3)) {
      object rob;
      tell_room(environment(),"The xetra screams in rage!\n");
      rob=first_inventory(environment());
      attacker_ob=0;
      while(!attacker_ob && rob) {
         if(living(rob) && rob->query_race() != "demon") {
            attacker_ob=rob; }
         else rob=next_inventory(rob);
      }
   }
   first=attacker_ob;
   for(x=0,ri=all_inventory(environment()),so=sizeof(ri);so>x;x++) {
      /*  Here it checks everything in the room to see if its attacking.
         It switches back to the original attack when it's done.
*/
      if(ri[x]->query_attack() == this_object() && ri[x] != first && ri[x]->is_player()) {
         already_fight=0;
         attack_object(ri[x]);
         attack();
      }
         attack_object(first);
   }
   /*  The multi hits per round.  Each time it hits the chance it hits again is reduced. */
   X=2;
   while(!random(X)) {
      already_fight=0;
      attack();
      X++;
   }
}

monster_died() {
   say("The Xetra screams in agony as light explodes from it's dying body.\n"+
      "A small fragment of light falls to the ground where it stood.\n");
   move_object(clone_object("/players/llew/closed/crystal/fragment.c"),environment(this_object()));
}


