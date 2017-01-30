#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/dmon/mon";
int switcher, dwep;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dom");
  set_alias("morph");
  set_race("lizard");
  set_short("Dom");
  set_long("A rather large (approx 8ft long) colorful lizard.\n"+
           "It flutters around with its stubby legs and its mandibles\n"+
           "snap erratically.  The colors of its skin changes erratically\n"+
           "moving from one color to the next.  Beware, a strange aura\n"+
           "eminates from it.\n");
  set_hp(850);
  set_level(16);
  if(random(2) == 0) set_al(-random(1000));
  else set_al(random(1000));
  set_wc(22);
  set_ac(13);
  set_heal(10,20);
  if(random(3) > 0) set_aggressive(1);
  if(random(2)==0) set_gender("male");
  else set_gender("female");
  set_exx(1999000); /* a little under level 18 exp */
  set_chat_chance(20);
  set_a_chat_chance(2);
  load_chat("The Dom whips around and stares at you.\n");
  load_chat("The lizard's skin brightens for a second and then changes color.\n");
  load_chat("The Dom chirps in delight.\n");
  load_a_chat("The lizard springs at you with blazing eyes.\n");   
  load_a_chat("The Dom screams!\n");
  set_chance(10);
  set_spell_dam(150);
  set_spell_mess1("The Dom snaps at its foe!\n");
  set_spell_mess2("Mandibles filled with row upon row of sharp teeth\n"+
                  "sinks into your flesh.  You feel great agony!\n"); 
  set_mult(2);
  set_dead_ob(this_object());
  switcher = 0;
  dwep = 0;
}

query_prevent_shadow() { return 1; }

monster_died() {
object leave;
   switch(random(2)) {
     case 0: leave = clone_object("/obj/money.c");
             leave->set_money(3000 + random(1000));  /* look at the monster */
             break;
     case 1: leave = clone_object("/players/mythos/darmor/skin.c");
             break;
   }
  move_object(leave,this_object());
}

heart_beat() {
  ::heart_beat();
  switch(random(12)) {
    case 0: set_short(BOLD+"Dom"+NORM); break;
    case 1: set_short(RED+"Dom"+NORM); break;
    case 2: set_short(BLU+"Dom"+NORM); break;
    case 3: set_short(GRN+"Dom"+NORM); break;
    case 4: set_short(YEL+"Dom"+NORM); break;
    case 5: set_short(NORM+"Dom"+NORM); break;
    case 6: set_short(CYN+"Dom"+NORM); break;
    case 7: set_short(HIR+"Dom"+NORM); break;
    case 8: set_short(HIG+"Dom"+NORM); break;
    case 9: set_short(HIY+"Dom"+NORM); break;
    case 10: set_short(HIB+"Dom"+NORM); break;
    case 11: set_short(HIC+"Dom"+NORM); break;
 }
}

hit_player(dam,zap) {
int damm;
object weps;
  damm = dam;
  weps = 0;
      if(living(previous_object())) {
        if(previous_object()->query_weapon()) 
         weps = previous_object()->query_weapon();
       } else {
       if(previous_object()->weapon_class()) weps = previous_object();
       }
  if(weps) if(weps->query_dwep() || weps->query_desert_weapon()) dwep = 1;
  if(!switcher && !dwep && damm != 0) { 
    if(damm > 0) {
     switcher = 1; 
     hit_point += damm;
     if (hit_point > max_hp) hit_point = max_hp;
     spell_points += damm;
     if (spell_points > max_spell) spell_points = max_spell;
     tell_room(environment(this_object()),short()+" grows stronger as it is wounded!"+"\n");
     damm = 0; }
     else {
     damm = -damm;
     tell_room(environment(this_object()), short()+" screams in pain as it is healed!"+"\n");
     switcher = 1; }
  }
  :: hit_player(damm,zap);
  if(switcher) switcher = 0;
  if(dwep) dwep = 0;
}

heal_self(n) {
int h;
object weps;
string msg;
  h = n;
  weps = 0;
  if(previous_object()->weapon_class()) weps = previous_object();
  if(weps) if(weps->query_dwep() || weps->query_desert_weapon()) dwep = 1;
  if(!switcher && !dwep && h != 0) { switcher = 1; h = -h; }
  if(switcher) {
    if(h > 0) msg = short()+" grows stronger as you wound it!";
    if(h < 0) msg = short()+" screams in pain as you heal it!";
    if(h != 0 && this_object()) tell_room(environment(this_object()),msg+"\n");
  }
  ::heal_self(h);
  if(dwep) dwep = 0;
} 