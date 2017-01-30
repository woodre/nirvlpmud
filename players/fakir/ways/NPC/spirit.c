#include "/players/fakir/color.h"
inherit "/obj/monster";
int x;
object envir;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("spirit");
  set_alias("soul");
  set_race("spirit");
  set_short(BOLD+BLINK+WHITE+"Spirit Soul"+OFF);
  set_long(
  "Only a trace remains of the beauty once so evident about the shape\n"+
  "before you.  Her form is luminous, and fades to whispy translucent\n"+
  "fingers of mist in places, making her appear as only a faint figure\n"+
  "at times.  Brin lost her way while traveling in the ways with her\n"+
  "beloved, and has searched for him in vain ever since.  She now only\n"+
  "seeks a release from this evil place.\n");
  set_level(15);
  set_hp(400 +random(100));
  set_al(-800);
  set_wc(20);
  set_ac(20);
  set_dead_ob(this_object());
  
  set_chat_chance(10);
  load_chat("The Spirit whispers: "+BOLD+WHITE+"I cannot leave, I cannot find peace."+OFF+"\n\n");
  load_chat(BOLD+WHITE+"Countless turnings of the wheel I have searched for my beloved.\n\n"+
            "I have become a thing of loathing...a thing of evil.  I was\n\n"+
            "not always as you now see me.  Once I was beautiful...lovely..."+OFF+"\n");
  load_chat("The Spirit sighs: "+BOLD+WHITE+"Shall I never be free of this unholy place?"+OFF+"\n\n");
  load_chat(BOLD+WHITE+"I rue the day I ever entered into the Ways.  I was but a foolish child..."+OFF+"\n\n");
  load_chat("The"+BOLD+WHITE+BLINK+" Spirit Soul"+OFF+" floats about.\n\n");
  
  set_a_chat_chance(15);
  load_a_chat("The"+BOLD+WHITE+BLINK+" Spirit Soul"+OFF+" floats about aimlessly...searching.\n\n");
  load_a_chat(BOLD+WHITE+"A deep feeling of regret fills your soul."+OFF+"\n\n");

  set_chance(10);
  set_spell_dam(15);
  set_spell_mess1("The "+BOLD+WHITE+BLINK+"Spirit Soul"+OFF+" floats through you.\n\n");
  set_spell_mess2("The "+BOLD+WHITE+BLINK+"Spirit Soul"+OFF+" floats through you. A chill enters your bones.\n\n");
  
}

monster_died() {
  move_object(clone_object("/players/fakir/ways/ARM/sshield.c"),
      environment(this_object()));
  x = present("corpse",environment(this_object()));
  destruct(x);
  tell_room(environment(this_object()),
  "The "+BOLD+WHITE+"Spirit Soul"+OFF+" at last knows peace and drifts off...leaving a small\n"+
  "gift in return for the freedom you have granted through death.\n");
  return 0;
}


