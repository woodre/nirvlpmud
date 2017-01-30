#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("shin");
   set_alias("machin");
   set_alt_name("wind");
   set_race("spirit");
   set_short("Machin Shin");
   set_long(
      "The Black Wind, spawned in the Time of Madness, and given form in the\n"+
      "caverns of the Ways.  Born of decay, hating life and light, it is a\n"+
      "creature of corruption.\n");

   move_object(clone_object("/players/fakir/ways/ARM/tshield.c"),
   (this_object()));
   init_command("wear shield");
   move_object(clone_object("/players/fakir/ways/WEP/noctis.c"),
   (this_object()));
   init_command("wield noctis");
   
   set_level(23);
   set_hp(1000 +random(200));
   set_al(-1000);
   set_wc(30+random(10));
   set_ac(30);
   set_heal(5,5);
   set_aggressive(1);
   set_dead_ob(this_object());
   
   set_chat_chance(15);
   load_chat("The Black Wind softly calls to you.\n");
   load_chat("The voices chant: "+BOLD+BLUE+"'Flesh so fine...so fine to tear...'."+OFF+"\n");
   load_chat("A single voice speaks: "+BOLD+BLUE+"'Skin to strip...to plait...so red the drops.'"+OFF+"\n");
   
   set_a_chat_chance(35);
   load_a_chat(YELLOW+"A RASPY voice speaks and a thin strip of flesh is pulled from your arm."+OFF+"\n");
   load_a_chat(MAGENTA+"A HARSH voice speaks and a vein is stripped from your neck."+OFF+"\n");
   load_a_chat("Several LOUD voices speak at once and "+BOLD+RED+"blood"+OFF+" drips from your wrists.\n");
   load_a_chat("The voices "+YELLOW+"*W*A*I*L*"+OFF+" and your mind cries out in silent agony.\n");
   load_a_chat("The Black Wind  "+BROWN+"~S W I R L S~"+OFF+"  about your weapon dulling its edge.\n");
        
   set_chance(15);
   set_spell_dam(70);
   
   set_spell_mess1(
      "A THOUSAND VOICES cry out in anguish and need...."+BOLD+RED+"SKIN BLEEDS FROM EVERY PORE."+OFF+"\n");
   set_spell_mess2(
      "A THOUSAND VOICES cry out in anguish and need...."+BOLD+RED+"YOUR SKIN BLEEDS FROM EVERY PORE."+OFF+"\n");
   
  call_out("movement",20+random(10));
}

monster_died() {
   tell_room(environment(this_object()),
      CYAN+"You have defeated The Black Wind and are granted deaths gifts.\n"+
      "       Pick up the gifts and be on your way."+OFF+"\n");
   return 0; 

 write_file("/players/fakir/closed/dead_log", ctime(time())+" "+
    query_attack()->query_name()+" killed Shin.\n");
  return 1; }


movement() {
   command("travel",this_object());
   call_out("movement",20+random(10));
   return 1; }
