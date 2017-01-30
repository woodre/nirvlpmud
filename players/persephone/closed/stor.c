inherit "obj/monster";
#include "/players/persephone/rooms.h"
object stas;
string given
reset(int arg){
 ::reset(arg);
  if(!arg){
   object dance;
   given="no";
    dance=clone_object("players/persephone/closed/dsword");
    move_object(dance, TOB);
    init_command("wield stormcleaver");
    set_name("storm");
    set_alias("lord");
    set_short("Lord Storm the Great");
    set_long("This strong and mighty looking warrior is none other than\n" +
             "the Lord Storm founder of the town of Stormhold. He seems\n" +
             "to be carrying a heavy burden and and his face is grave\n" +
             "and troubled. In his left hand he carries the legendary\n" +
             "and magical weapon Stormcleaver. As you look at him you\n" +
             "he seems to be sizing you up.\n\n");
    set_level(100);
    set_hp(20000);
    set_wc(60);
    set_ac(40);
    set_al(1000);
    set_aggressive(0);
    set_chance(10);
    set_spell_dam(100);
    set_spell_mess1("Storm calls forth a mighty Stormcloud\n");
    set_spell_mess2("Storm summons a bolt of lightning from the sky\n" +
                    "when you foolishly try to hit him\n");
   }
}
catch_tell(str){
 object from;
 string a, b, c;
 object next_dest;
 string next_out;
 from = TPL;
 if(!from)
  return 1;
 if(sscanf(str, "%s gives %s to Storm.", a, b) == 2) {
  object ob, ob2;
  ob2 = TOB;
  ob = present(b, TOB);
  if(!ob || !ob->id("scroll"))
   return 1;
  call_out("quest_intro", 4);
 }
 if(sscanf(str, "%s yes%s", a, b)==2 || sscanf(str, "%s sure%s", a, b)==2)
 call_out("affirm_ye", 3);
 if(sscanf(str, "%s help%s", a, b)==2 || sscanf(str, "%s instructions%s", a, b)==2)
 call_out("help_mes", 3);
/*
*/
  return 1;
}
quest_intro() {
 say("\nStorm says: Great warrior I have a task which only the bravest\n"+
     "            warrior can accomplish. Do you think you are brave\n" + 
     "            enough?\n\n");
 return 1;
}
affirm_ye(){
 say("\nStorm says: Long ago Stormhold use to be the cultural center of\n" +
     "            Nirvana now it is a haven to thieves and pirates. I\n" +
     "            want you to help bring peace.\n");
 say("Storm says: Tell me now if you need instructions\n\n");
 return 1;
}
help_mes(){
 say("\nStorm says: Listen carefully it is your task to return Stormhold\n" +
     "            to piece and tranquility to do this you must free the\n" +
     "            prisoners and destroy the pirates but I will.\n");
 say("            require proof which is the head of Jeny and the return\n" +
     "            of the mystic Tiarra. If you do this I will give you\n" +
     "            the legendary sword Stormcleaver as a reward\n\n");
 call_out("done_tal", 4);
 return 1;
}
done_tal(){
 say("Storm bows in front of you and shimmers slightly before he turns\n" +
     "back into a statue\n\n");
  stas=clone_object("players/persephone/closed/statc");
  move_object(stas, environment(TOB));
  destruct(present("stormcleaver"));
  destruct(TOB);
 return 1;
}
