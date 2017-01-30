 inherit "/obj/monster";
 reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob;
  string shortdesc;
  int color;
  ob = clone_object("/players/arrina/treas/horseshoe.c");
 move_object(ob,this_object());
  color = random(14);
  if(color == 0) shortdesc = "bay";
  if(color == 1) shortdesc = "chestnut";
  if(color == 2) shortdesc = "grey";
  if(color == 3) shortdesc = "white";
  if(color == 4) shortdesc = "black";
  if(color == 5) shortdesc = "roan";
  if(color == 6) shortdesc = "dun";
  if(color == 7) shortdesc = "buckskin";
  if(color == 8) shortdesc = "young";
  if(color == 9) shortdesc = "mare";
  if(color == 10) shortdesc = "stallion";
  if(color == 11) shortdesc = "colt";
  if(color == 12) shortdesc = "filly";
  if(color == 13) shortdesc = "gelding";
  if(color == 14) shortdesc = "palomino";
      set_name("charger");
     set_short("A "+shortdesc+" ghost charger");
     set_race("ghost");
     set_alias("charger");
    set_long("A ghost horse, intent on destroying you.\n");
     set_level(9 + random(4));
     set_ac(6+ random(6));
     set_wc(12 + random(8));
     set_hp(120 + random(80));
     set_al(-400);
     set_aggressive(1);
     set_chat_chance(2);
     set_a_chat_chance(2);
     load_chat("The charger lashes out at you with it's sharp hooves.\n");
     load_chat("The charger whickers hollowly.\n");
     load_a_chat("The charger stamps it's hoof in anger.\n");
     load_a_chat("The charger rushes you with it's teeth bared.\n");
    }
}
