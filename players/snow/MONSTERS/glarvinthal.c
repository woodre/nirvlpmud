/*
A spell-casting, healing Archwizard.
*/
 
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("glarvinthal");
     set_short("A friendly archwizard");
     set_race("man");
     set_alias("archwizard");
     set_long(
"This is a wizened old man who appears to be very happy to see you.\n" +
"He is wearing a shimmering white robe that seems to blend well with \n" +
"his iron grey hair and beard. He looks old and weak but appearances \n" +
"can be deceiving...\n");
     set_level(30);
     set_ac(50);
     set_wc(50);
     set_hp(1000);
     set_heal(3,2);
     set_al(1000);
     set_aggressive(0);
 
  set_chat_chance(12);
  set_a_chat_chance(7);
  load_chat(
"Glarvinthal says: In the east tower lies an Ogre Mage's domain.\n");
  load_chat(
"Glarvinthal says: In the west tower is passage to the Tundra-\n"+
"a realm of snow, rock, ice, and demons.\n");
  load_chat(
"Glarvinthal says: The north tower holds the greatest challenge for foolish\n"+
"and strong. The evil Icingdeath awaits his next meal.\n");
  load_chat(
"Glarvinthal says: Do not complain if you die. You have been warned.\n");
  load_chat("Glarvinthal says: Be careful.. and don't say I didn't warn ya!\n");
  load_a_chat("Glarvinthal says: Thought I was a doddering old fool, didja?\n");
  load_a_chat("Glarvinthal says: Take this you little fools!\n");
 
  set_chance(80);
  set_spell_mess1(
"Glarvinthal seems to glow with an internal light...\n"+"\n"+
"He sends a bolt of pure energy into his foe!\n");
  set_spell_mess2(
"Glarvinthal glows with an internal light...\n"+"\n"+
"He directs a bolt of pure energy burning into you!\n");
  set_spell_dam(50);
call_out("glar_life",1);
   }
}
 
glar_life() {
  call_out("glar_life",1);
    if(MEAT) {
glar_heal();
r_spell();
    }
return 1;
}
 
glar_heal() {
  int H;
H = random(8)+1;
  if(H > 5) {
    say("Glarvinthal's wounds seem to magically close!\n");
  }
call_other(TO,"heal_self",H);
return 1;
}
 
r_spell() {
  int R;
R = random(10);
  if(R < 6) return 1;
  if(R > 5) {
    write("Glarvinthal is wreathed in POWER!\n");
      if(R == 6) {
flame_ball();
return 1;
      }
      if(R == 7) {
lightning_bolt();
return 1;
      }
      if(R == 8) {
vamp_drain();
return 1;
      }
      if(R == 9) {
r_spell();
r_spell();
return 1;
      }
  }
}
 
flame_ball() {
  say(
"Glavinthal conjures a ball of flame and sends it burning at "+MEATN+"!\n");
  tell_player(MEAT,"The huge, burning ball crashes into you!\n");
call_other(MEAT,"hit_player",random(50)+10);
return 1;
}
 
lightning_bolt() {
  say(
"Glarvinthal stretches his hands toward "+MEATN+" and lightning blasts forth!\n");
  tell_player(MEAT,"The lightning bolt sizzles into your chest!\n");
call_other(MEAT,"hit_player",random(50)+15);
return 1;
}
 
vamp_drain() {
  int drain;
drain = random(30)+20;
  say(
"Glarvinthal reaches out and drains life force from "+MEATN+"!\n");
  tell_player(MEAT,"You are drained of life!\n");
call_other(MEAT,"heal_self",-drain);
  say("Glarvinthal appears to grow stronger!\n");
call_other(TO,"heal_self",drain);
return 1;
}
