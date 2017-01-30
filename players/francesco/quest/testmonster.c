#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

int counter;

reset(arg){
  ::reset();
  if(arg) return;
  counter = 0 ;
   set_name("professor");
   set_race("human");
   set_alias("prof");
   set_gender("male");
     set_short("Prof. DeRossi,  full professor");
     set_long("Professor DeRossi is an old man, with fluent white hair till \n"+
              "his shoulders.  He is wearing a very elegant black suit with \n"+
              "the waistcoat.  A golden chain connects two pockets of his\n"+
              "waistcoat, through a buttonhole, making a double curved meander.\n"+  
              "Most likely, the chain is fastened to a golden watch.  Would you \n"+
              "dare to 'search' out?  He wears a blue bow tie with minuscule \n"+
              "pink dots.  As he moves around, you notice that he is helping \n"+
              "himself with a robust walking cane. \n");
   set_dead_ob(this_object());
   set_level(22);
   set_hp(930);
   set_wc(41);
   set_ac(25);
   set_chat_chance(10);
   set_heal(12,2);
   set_wc_bonus(16);
/* to be eventually determined   set_ac_bonus(); */
   load_chat("Professor mumbles: 'Yes... good point.... a very good point indeed'\n");
   set_chance(30);
   set_spell_mess1("Professor says:  Ahh!  you are not studying, are you?\n"+
                   "Professor slaps you hard.");
   set_spell_mess2("Professor swishes the blade of his cane through your neck.");
   set_spell_dam(60);
}

id(str) {return str=="full professor" || str=="derossi" || str=="professor" || str=="prof";}

init() {
::init();
  add_action("search","search");
}

heart_beat() {
   ::heart_beat();
   if(attacker_ob){
     if(this_object()->query_hp() > 700 && this_object()->query_hp() < 800)
       {
       if(counter < 5) {
       counter ++;
       say("Professor DeRossi yells: Help me, Help me!!\n");
       write("Professor DeRossi yells: Help me, Help me!!\n");
       move_object(clone_object("/players/francesco/letters/mobs/usher"+counter+".c"),environment(attacker_ob));
       say("An usher arrives to help Professor DeRossi.\n");
       write("An usher arrives to help Professor DeRossi.\n");
       /* 
        With an average damage of 30 per round, there will be at least three or 
        four ushers cloned (in same cases even more since the prof heals himself).
        If there's is a party of two or three members, there will still be at least
        one or two ushers. In conclusion, average number of ushers cloned could 
        be estimated to be three.
        The ushers have wc 9 then they average 2 points of damage per round 
        (against ac 10), and each of them contributes to wc_bonus = 2
        Then the total wc_bonus will be 2 * 3 = 6 
        PS: calming the fight to stop the usher's attack wouldnt be of much help 
            for some reasons: 
            1. he will heal again and more ushers will be cloned later
            2. they will start attacking again when the player will re-attack the prof
            3. calming still costs something (at least 25 sps)
       */
       }
     if(attacker_ob->query_hp() > 210 && attacker_ob->query_hp() < 240) 
       {   
       attacker_ob->heal_self(-100); 
        say("Professor DeRossi yells: LEAVE ME ALONE!!\n");
        write("Professor DeRossi yells: LEAVE ME ALONE!!\n");
       /* 
        with an average damage of 30 per round, the fight lasts for 31 rounds, 
        thus this heal_spell is like an average damage per round equal to 3.3
        and contributes to wc_bonus = 3.3, 
        also, within a fight the player's hp might be in the set hp range more than 
        once, lets say two or three times or maybe even more.  Thus this spell 
        will be cast, hmmmm, three/four times per fight.  
        finally, 100 damage in one single round is more dangerous than 3.3 damage 
        per every round and thus i will add 1 further bonus for this.
        total wc_bonus 3.3 * 3 + 1 = 11
       */
       }
     }
   }
} 


monster_died() {
   object ob1, ob2;
   ob1=(clone_object("/players/francesco/letters/items/corpse.c"));
   ob2=(clone_object("/players/francesco/letters/mobs/prof2.c"));
   destruct(present("corpse",environment()));
   move_object(ob1,environment(attacker_ob));
   move_object(ob2,environment(attacker_ob));
   say("Dr. Smith arrives and yells: What?? did you kill my Professor??\n");
   write_file("/players/francesco/quest/log/"+this_player()->query_real_name(),this_player()->query_real_name());    
 
/*   write("Dr. Smith arrives and yells: What?? did you kill my Professor??\n");*/
  return 0; }
 
search(str) {
  write("As you try to search,  Professor DeRossi steps back and scolds you:\n"+
        "'That is not polite from you.  You ought to kill me before searching \n"+
        "on my body!'\n");
  return 1;
}