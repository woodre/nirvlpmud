inherit "obj/monster";
#include "/players/persephone/rooms.h"
object stas;
reset(int arg){
 ::reset(arg);
  if(!arg){
   object dance;
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
    set_hp(4000);
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
  return;
 if(sscanf(str, "%s gives %s to Storm.", a, b) == 2) {
  object ob, ob2;
  ob2 = TOB;
  ob = present(b, TOB);
  if(!ob || !call_other(ob,"id","scroll"))
   return;
  say("Storm says: Oh listen mighty warriors this is a task only the bravest\n" +
      "            need attempt if you are indeed as brave as you appear\n");
  say("            free Stormhold of the evil that has befallen it and\n" +
      "            return it to peace and tranquility. If you complete\n");
  say("            this dangerous task return to me the head of Jeny for\n" +
      "            a great and powerful reward before I send you on your\n");
  say("            way I must warn you this task is both hard and treacherous\n" +
      "            not all is what it seems.\n\n");
  say("            Storm bows and changes back into a statue\n\n");
  stas=clone_object("players/persephone/closed/statc");
  move_object(stas, TOB);
  destruct("stormcleaver");
  destruct(TOB);
  return;
 }
}
