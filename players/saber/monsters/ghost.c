inherit "/obj/monster";
int n;
object ob;

reset(arg) {
ob = clone_object("/players/saber/stuff/bear.c");
move_object(ob,this_object());
   ::reset(arg);
if (!arg){
     set_name("melody");
     set_short("The ghost of a young girl");
     set_alt_name("girl");
     set_alias("ghost");
     set_race( "spirit");
     set_long("The ghost of a young girl is sitting in the empty air, staring at you with\n"+
      "moist eyes of a deep blue hue.  She is young, perhaps seven, and has silky\n"+
     "blond hair which falls down around her shoulders.\n");
     set_level(5);
     set_ac(5);
     set_wc(9);
     set_hp(75);
     set_al(500);
     set_aggressive(0);
     set_chat_chance(8);
   set_a_chat_chance(15);
     load_chat("The young girl asks: Have you seen Christopher?\n");
     load_chat("The young girl hums part of an old irish tune.\n");
     load_chat("The young girl says: You're not really going up there are you?\n");
     load_chat("The young girl watches the Go player.\n");
     load_chat("The young girl says: Be careful.  It's dangerous to go through the portals\n");
     load_chat("The young girl says: My name is Melody.  What's yours?\n");
     load_chat("The young girl sniffles.\n");
     load_chat("The young girl looks over at the pot of hot chocolate with\n"+
          "a wistful look in her eyes...\n");
     load_a_chat("The young girl yells: Christopher!  Help!\n");
     load_a_chat("The young girl cowers in fear.\n");

     set_object(this_object());
     set_function("buyme");
     set_type("says:");
     set_match("chocolate");
   set_function("hugs");
     set_type("hug");
     set_match("");
     set_function("hi_there");
     set_type("arrives");
     set_match("");
     set_function("orderme");
     set_type("orders");
     set_match("");
   }

}
notify(str)  {
  say(str);
 write(str);
}
buyme(str)  {
    string who, rest;
    sscanf(str, "%s %s\n", who, rest);
    say("Melody whispers: Please "+who+", order me some chocolate.\n");
   }
hugs(str)  {
  string who;
  if(sscanf(str, "%s hugs", who) == 1) {
if(who == "melody" || who == "Melody")
  return;
 notify("Melody hugs "+who+".\n");
}   }
hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  notify("Melody says: Hello "+who+".\n");
  notify("Melody smiles at "+who+".\n");
}  }
orderme(str) {
string who;
if(sscanf(str, "%s orders a chocolate for Melody.",who) == 1) {
notify("Melody drinks down the cup of chocolate.\n");
  notify("Melody smiles happily.\n");
  notify("Melody says: Thank you "+who+"!\n");
  notify("Melody hugs "+who+".\n");
}  }
