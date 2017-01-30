#include "/players/fakir/color.h"
inherit "/obj/monster";
int x;
object envir;
reset(arg)  {
object armor;
  ::reset(arg);
  if(arg) return;
  set_name("soul");
  set_alias("searching");
  set_race("spirit");
  set_short(BOLD+WHITE+"Searching Soul"+OFF);
  set_long(
  "Once dashing and handsome, the searching soul has succumbed to the\n"+
  "persistent evil of the Ways.  Once young and full of hope, he now\n"+
  "searches endlessly for his bethrothed, who, taking a wrong turn,\n"+
  "became lost in the Ways.  Only the faint hope of finding her has\n"+
  "kept his soul alive for so long a time, and only the ring he carries\n"+
  "has kept him safe from harm.\n");
  
  set_level(16);
  set_hp(500 +random(100));
  set_al(-800);
  set_wc(20);
  set_ac(30);
  set_dead_ob(this_object());

  armor=clone_object("/players/fakir/ways/ARM/ring.c");
  move_object(armor,this_object());
  
  set_chat_chance(10);
  load_chat("The searching soul whispers: "+BOLD+WHITE+"I cannot leave, I must find my beloved."+OFF+"\n\n");
  load_chat(BOLD+WHITE+"She has been gone so long...so very long.  I am lost without her.\n\n"+
            "I was once young, once handsome...and so very much in love...but now...\n\n"+
            "I was not always as you see me.  Please, help me find my love..."+OFF+"\n");
  load_chat("The Spirit sighs: "+BOLD+WHITE+"Shall I never be free of this unholy place?"+OFF+"\n\n");
  load_chat(BOLD+WHITE+"I knew better than to take the Ways...but I was in a hurry..."+OFF+"\n\n");
  load_chat("The"+BOLD+WHITE+" Searching Soul"+OFF+" drifts in and out of view.\n\n");
  
  set_a_chat_chance(15);
  load_a_chat("The"+BOLD+WHITE+" Searching Soul"+OFF+" drifts about aimlessly...searching.\n\n");
  load_a_chat("The soul says: "+BOLD+WHITE+"Ahhh....the pain, the endless pain...she has been lost so long..."+OFF+"\n\n");

  set_chance(10);
  set_spell_dam(15);
  set_spell_mess1("The "+BOLD+WHITE+"Searching Soul"+OFF+" invokes his "+BOLD+CYAN+"Angreal Ring"+OFF+".\n\n");
  set_spell_mess2("The "+BOLD+WHITE+"Searching Soul"+OFF+" invokes his "+BOLD+CYAN+"Angreal Ring"+OFF+".  Your heart skips a beat...\n\n");
  
}

monster_died() {
  
  x = present("corpse",environment(this_object()));
  destruct(x);
  tell_room(environment(this_object()),
  "The "+BOLD+WHITE+"Searching Soul"+OFF+" at last knows peace and drifts off...leaving his ring\n"+
  "as a gift in return for the freedom you have granted him through death.\n");
  return 0;
}


