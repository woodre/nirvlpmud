/*
v2.0 of the great dragon Icingdeath is even tougher than before.
It is now evil, with several special attacks.
*/
 
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(15000) + 10000);
  move_object(gold,this_object());
 
move_object(clone_object("/players/snow/WEAPONS/hon_sword"),this_object());

     set_name("icingdeath");
     set_short("Icingdeath, the Great Wyrm");
     set_race( "dragon");
     set_alias("frost dragon");
     set_long(
"This is the legendary Icingdeath. Huge, enchanted claws and teeth are his\n"+
"weapons while scales of frosty adamantium line his flanks. No mortal has\n"+
"ever defeated this mighty being. You know that if you attempt to do battle,\n"+
"you also will die.\n");
     set_level(50);
      set_ac(random(25)+15);
     set_wc(105);
     set_hp(6000);
     set_heal(5,1);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("Icingdeath sneers at you.\n");
     load_chat("Icingdeath says: Have you come to pay tribute?\n");
     load_chat("Icingdeath gazes into your eyes. You tremble in fear.\n");
     load_a_chat(
"Icingdeath roars: Another battle, at last!\n");
     load_a_chat(
"Icingdeath laughs at your puny attacks!\n");
  set_chance(35);
  set_spell_mess1("Icingdeath breaths a whirling storm of ice onto his foes! \n");
  set_spell_mess2(
"Icingdeath breaths forth a cloud of ice crystals!\n"+"\n"+
"  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * \n"+
" *     *     *     *     *     *     *     *     *     *     *     * \n"+
"    *     *     *     *     *     *     *     *     *     *     *     *\n"+
"  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * \n"+
"\n"+"You are shredded by slivers of ice!\n");
     set_spell_dam(80);
call_out("ice_life",1);
   }
}
 
ice_life() {
  call_out("ice_life",1);
    if(MEAT) {
ice_heal();
ice_hurt();
    }
return 1;
}
 
ice_heal() {
  int X;
X = random(15);
call_other(TO,"heal_self",X);
  if(X > 10) {
    say("Icingdeath's wounds seem to close before your eyes!\n");
  }
return 1;
}
 
ice_hurt() {
  int L;
  object meat;
L = MEAT->query_level();
meat = present(MEAT,environment(TO));
    if(L > 17) {
multi_rip();
return 1;
    }
    if(L > 10) {
ice_rip();
return 1;
    }
return 1;
}
 
ice_rip() {
  int N,L,X;
  object meat;
  string claw1,claw2;
N = random(6);
L = MEAT->query_level();
X = MEAT->query_extra_level();
meat = find_player(lower_case(MEAT->query_real_name()));
claw1 = "Icingdeath claws into your ";
claw2 = "Icingdeath claws into "+MEATN+"'s ";
  if(N == 0) {
    tell_player(meat,claw1+"head!\n");
    say(claw2+"head!\n");
call_other(meat,"heal_self",random((L/2)+(X/4)));
return 1;
  }
  if(N == 1) {
    tell_player(meat,claw1+"shoulder!\n");
    say(claw2+"shoulder!\n");
call_other(meat,"hit_player",random((L/3)+(X/5)));
return 1;
  }
  if(N == 2) {
    tell_player(meat,claw1+"chest!\n");
    say(claw2+"chest!\n");
call_other(meat,"hit_player",random((L/2)+(X/6)));
return 1;
  }
  if(N == 3) {
    tell_player(meat,claw1+"arm!\n");
    say(claw2+"arm!\n");
call_other(meat,"hit_player",random((L/4)+(X/6)));
return 1;
  }
  if(N == 4) {
    tell_player(meat,claw1+"leg!\n");
    say(claw2+"leg!\n");
call_other(meat,"hit_player",random((L/4)+(X/6)));
return 1;
  }
  if(N == 5) {
    tell_player(meat,claw1+"groin!\n");
    say(claw2+"groin!\n");
call_other(meat,"heal_self",random((L/3)+(X/3)));
return 1;
  }
return 1;
}

multi_rip() {
  int X,L,T;
X = MEAT->query_extra_level();
L = MEAT->query_level();
T = (X + L)/8;
  if(T == 1) { ice_rip(); }
  if(T == 2) { ice_rip(); ice_rip(); }
  if(T == 3) { ice_rip(); ice_rip(); ice_rip(); }
  if(T > 3) { ice_rip(); ice_rip(); ice_rip(); ice_rip(); }
return 1;
}

