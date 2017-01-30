#define tp this_player()->query_name()
#define TP this_player()

inherit "/obj/monster";
int n, count;
object ob;

reset(arg) {

ob = clone_object("/players/saber/weapons/rapier.c");
move_object(ob,this_object());

   ::reset(arg);
if (!arg){

     set_name("tuyen");
     set_short("Tuyen the Song Keeper (paladin)");
     set_alias("girl");
     set_race( "human");
     set_gender("female");
     set_long(
       "Tuyen is the Song Keeper of the Bards.\n"+
       "Tuyen is a young oriental woman with cropped black hair and a\n"+
       "sparkle in her dark eyes.  She wears a rapier at her side,\n"+
       "and is garbed in traditional bardic blue and black.\n");
     set_level(20);
     set_ac(35);
     set_wc(18);
     set_hp(475);
     set_al(900);
     set_aggressive(0);
     set_chat_chance(3);
     set_a_chat_chance(20);
     load_chat("Tuyen looks up at you and smiles.\n");
     load_chat("Tuyen looks up at you and winks.\n");
     load_chat("Tuyen hums to herself.\n");
     load_chat("Tuyen sings softly.\n");
     load_chat("Tuyen sings softly.\n");
     load_a_chat("Tuyen dodges the attack.\n");
     load_a_chat("Tuyen traces mystic symbols in the air.\n");
     load_a_chat("Tuyen slashes her foe across the face.\n");
     load_a_chat("Tuyen nimbly dodges the blow.\n");
     load_a_chat("Tuyen whispers mystic whispers.\n");
     set_chance(25);
     set_spell_dam(50);
     set_spell_mess1("Tuyen runs her blade through her foe.\n"+
                     "The blade hummms with power.");
     set_spell_mess2("Tuyen runs her blade THROUGH you!!!");

set_object(this_object());
   set_function("hugs");
   set_type("hug");
   set_match("");
   set_function("hi_there");
   set_type("arrives");
   set_match("");
        }
        }


hugs(str)  {
  string who;
  if(sscanf(str, "%s hugs", who) == 1) {
  if(who == "tuyen" || who == "Tuyen")  return;
  say("Tuyen hugs "+who+".\n");
       }   
       }

hi_there(str) {
string who;
 if(sscanf(str, "%s arrives.", who) == 1)  {
  say("Tuyen smiles at "+who+".\n");
       }  
       }
