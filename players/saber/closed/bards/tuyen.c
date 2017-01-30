#define tp this_player()->query_name()
#define TP this_player()

inherit "/obj/monster";
int n, count;
object ob, ob2;

reset(arg) {
ob = clone_object("/players/saber/weapons/rapier.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/closed/bards/bard_mark.c");
move_object(ob2,this_object());
   ::reset(arg);
if (!arg){
     set_name("tuyen");
     set_short("A young oriental bard");
     set_alias("girl");
     set_race( "human");
     set_gender("female");
     set_long(
       "Tuyen is the Song Keeper of the Bards.\n"+
       "Tuyen is a young oriental woman with cropped black hair and an\n"+
       "sparkle in her dark eyes.  She wears a rapier at her side,\n"+
       "and is garbed in bardic blue and black.\n");
     set_level(19);
     set_ac(35);
     set_wc(10);
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
   load_a_chat("Tuyen whispers mystic soundind whispers.\n");
set_chance(25);
   set_spell_dam(random(30));
    set_spell_mess1("Tuyen runs her blade through her foe.\n"+
       "The blade seems to hummm with power.");
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
notify(str)  {
  say(str);
 write(str);
}

hugs(str)  {
  string who;
  if(sscanf(str, "%s hugs", who) == 1) {
if(who == "tuyen" || who == "Tuyen")
  return;
 notify("Tuyen hugs "+who+".\n");
}   }

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  notify("Tuyen smiles at "+who+".\n");
}  }

