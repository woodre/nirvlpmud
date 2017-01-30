inherit"obj/weapon";
int i,n;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("balig");
set_alias("longsword");
set_short("Spectacular Elven Longsword");
set_long(
"This is Balig the goblin slayer. It has been used in many a war\n" +
"against mass armies of goblins and orcs and was forged for that\n" +
"purpose. It is an ancient weapon and holds mystical powers within\n" +
"it's depths. It has a silvered blade worked with fine elven runes\n" +
"that glow a soft fiery red when spilling the black blood of it's\n" +
"intended prey.\n");
set_value(5000);
set_weight(3);
set_class(15);
set_int_init();
set_hit_func(this_object());
}
set_int_init() {
   i = 0;
   n = 2;
}
weapon_hit(attacker) {
   if(!attacker) return;
   if(call_other(attacker, "id", "goblin")) goblin_attack(attacker);
      if(!attacker) return 1;
   if(call_other(attacker, "id", "hobgoblin")) hob_attack(attacker);
      if(!attacker) return 1;
   if(call_other(attacker, "id", "orc")) orc_attack(attacker);
      if(!attacker) return 1;
   return 1;
}
goblin_attack(attacker) {
   object ob;
   ob = present(attacker, environment(this_player()));
   if(!ob) return;
   if(i!=n) {
      i++;
      if(!ob) return;
      ob->hit_player(random(this_player()->query_level()));
      if(random(100) > 80) {
         write("Goblin screams in terror.\n");
      }
      if(random(100) > 60) {
         write("Balig hums, filling you with an unnatural blood lust.\n");
      }
      if(!ob) return;
      weapon_hit(attacker);
            }
   i=0;
   return 1;
}
hob_attack(attacker) {
   object ob;
   ob = present(attacker, environment(this_player()));
   if(!ob) return;
   if(i!=n) {
      i++;
      ob->hit_player(random(this_player()->query_level()));
      if(random(100) > 80) {
         write("Hobgoblin looks at Balig with fear and loathing.\n");
      }
      if(random(100) > 60) {
         write("Balig surges towards the Hobgoblin, dragging you with it.\n");
      }
      if(random(100) > 80) {
         write("A fine red mist rises around the Hobgoblin as Balig "+
               "slices and dices.\n");
      }
      if(!ob) return;
      weapon_hit(attacker);
            }
   i=0;
   return 1;
}
orc_attack(attacker) {
   object ob;
   ob = present(attacker, environment(this_player()));
   if(!ob) return;
   if(i!=n) {
      i++;
      ob->hit_player(random(this_player()->query_level()));
      if(random(100) > 80) {
         write("Orc cries out: No! Not the slayer!\n");
      }
      if(random(100) > 50) {
         write("Orc tries to run, but is tripped by Balig.\n");
      }
      if(random(100) >40) {
         write("Balig becomes a blur in your hands.\n");
      }
      if(!ob) return;
      weapon_hit(attacker);
            }
   i=0;
   return 1;
}
