inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   switch(random(6)+1) {
      case 1:
         set_name("Pilot Legoman");
         set_alias("pilot");
         set_short("A Pilot Legoman");
         set_long("The Pilot legoman has a body colored like a flight suit and legs\n"+
                  "to match.  He gives you a big black and yellow legoman smile.\n");
         break;
      case 2:
         set_name("Space Legoman");
         set_alias("space");
         set_short("A Space Legoman");
         set_long("The Space legoman has a white space suit on with a big white helmet.\n"+
                  "He gives you a big black and yellow legoman smile.\n");
         break;
      case 3:
         set_name("Knight Legoman");
         set_alias("knight");
         set_short("A Knight Legoman");
         set_long("The Knight legoman is covered with steel armor and helmet, and he\n"+
                  "carries a long plastic lance with him.  He gives you a big black\n"+
                  "and yellow legoman smile.\n");
         break;
      case 4:
         set_name("Fire Legoman");
         set_alias("fire");
         set_short("A Fire Legoman");
         set_long("The Fire legoman has a red firefighter's suit on with a big red hat.\n"+
                  "He gives you a big black and yellow legoman smile.\n");
         break;
      case 5:
         set_name("Race Driver Legoman");
         set_alias("driver");
         set_short("A Race Driver Legoman");
         set_long("The Race Driver legoman wears his suit with his sponsors' logos\n"+
                  "patched across it with a black racing helmet.  He gives you a big\n"+
                  "black and yellow legoman smile.\n");
         break;
      case 6: 
         set_name("Ranger Legoman");
         set_alias("ranger");
         set_short("A Ranger Legoman");
         set_long("The Ranger legoman has a green ranger outfit with a bright green hat,\n"+
                  "and a long bow slung across it's shoulder.  He gives you a big black\n"+
                  "and yellow legoman smile.\n");
         break;
   }
   set_level(4);
   set_race("legoman");
   set_hp(50+random(20));
   set_al(75);
   set_wc(7+random(3));
   set_ac(4);
   set_chat_chance(4);
   set_a_chat_chance(12);
   load_chat("Legoman says, \"I'm so happy to be a lego.\"\n");
   load_chat("Legoman smiles happily.\n");
   load_chat("Legoman says, \"I'm worried about our King.\"\n");
   load_chat("Legoman says, \"It's fun being a lego.\"\n");
   load_chat("Legoman grins.\n");
   load_chat("Legoman says, \"We need our King back in one piece.\"\n");
   load_chat("Legoman whistles happily.\n");
   load_a_chat("Legoman frowns.\n");
   load_a_chat("Legoman sighs.\n");
   load_a_chat("Legoman pokes you in the ribs.\n");
   load_a_chat("Legoman tries to make you feel better.\n");
   load_a_chat("Legoman says, \"We'll never save our King this way.\"\n");
   load_a_chat("Legoman wonders what is the matter.\n");
   move_object(clone_object("/players/llew/Toys/misc/lego"),this_object());
   set_alt_name("rand_legoman");
}
