inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   switch(random(7)+1) {
      case 1:
         set_name("rabbit");
         set_long("Rabbit is a dull yellow a white colored stuffed\n"+
                  "animal from the Hundred Acre Woods.  His long ears\n"+
                  "flop loosly about his head as he works nervously in\n"+
                  "his garden.\n");
         load_chat("Rabbit says, \"I've got to get my carrots picked before Tigger comes.\"\n");
         load_chat("Rabbit nibbles on a carrot.\n");
         load_chat("Rabbit rakes his garden.\n");
         load_a_chat("Rabbit whacks you with his hoe.\n");
         load_a_chat("Rabbit says, \"You'll never get my carrots!\"\n");
         move_object(clone_object("/players/llew/Toys/heals/carrot"),this_object());
         move_object(clone_object("/players/llew/Toys/heals/carrot"),this_object());
         break;
      case 2:
         set_name("tigger");
         set_long("Tigger is an orange and black striped.. Tigger.  Tiggers\n"+
                  "are wonderful things.  Their tops are made out of rubber;\n"+
                  "their bottoms are made out of springs.\n");
         load_chat("Tigger bounces around.\n");
         load_chat("Tigger pounces.\n");
         load_chat("Tigger practices his frightening growl.\n");
         load_chat("Tigger proclaims, \"I'm Tigger!\"\n");
         load_a_chat("Tigger pounces on you!\n");
         load_a_chat("Tigger tries to hide.\n");
         load_a_chat("Tigger growls.\n");
         move_object(clone_object("/players/llew/Toys/weapons/growl"),this_object());
         break;
      case 3:
         set_name("piglet");
         set_long("Piglet is a cute little pink pig with a red and black\n"+
                  "striped shirt.  He is the best little friend of Pooh\n"+
                  "in the Hundred Acre Woods.\n");
         load_chat("Piglet says, \"I'm P-p-p-piglet.\"\n");
         load_chat("Piglet looks around for Pooh.\n");
         load_chat("Piglet groans.\n");
         load_a_chat("Piglet says, \"P-p-p-please don't hurt me.\"\n");
         load_a_chat("Piglet says, \"Ouch!\"\n");
         load_a_chat("Piglet says, \"Oh dear, oh dear, oh dear...\"\n");
         move_object(clone_object("/players/llew/Toys/misc/piglet_broom"),this_object());
         break;
      case 4:
         set_name("owl");
         set_long("Owl is a tall feathered owl of great wisdom.  He lives in\n"+
                  "a great oak in the Hundred Acre Woods.  He rambles on\n"+
                  "at great length about nothing at all.\n");
         load_chat("Owl hoots.\n");
         load_chat("Owl reads one of his books.\n");
         load_chat("Owl rambles on about his uncle Theodore.\n");
         load_a_chat("Owl says, \"Oh, this will never do.\"\n");
         load_a_chat("Owl hoots loudly.\n");
         load_a_chat("Owl blinks.\n");
         move_object(clone_object("/players/llew/Toys/misc/owl_book"),this_object());
         move_object(clone_object("/players/llew/Toys/misc/owl_book"),this_object());
         break;
      case 5:
         set_name("eeyore");
         set_long("Eeyore is a dark gray donkey with long floppy ears and a\n"+
                  "tail pinned on his backside that's slightly off center.\n"+
                 "He hangs his head down low.\n");
         load_chat("Eeyore looks all dejected.\n");
         load_chat("Eeyore eats a thistle.\n");
         load_chat("Eeyore eyes you warily.\n");
         load_a_chat("Eeyore says, \"Thanks fer noticin' me.\"\n");
         load_a_chat("Eeyore says, \"I guess I'll just die now.\"\n");
         load_a_chat("Eeyore shakes a hoof at you.\n");
         move_object(clone_object("/players/llew/Toys/misc/eeyore_tail"),this_object());
         break;
      case 6:
         set_name("kanga");
         set_long("Kanga is a loving mother of her little Roo.\n"+
                  "She is very kind to everyone, but mostly watches\n"+
                  "out for Roo.\n");
         load_chat("Kanga says, \"Everything will be fine in the Hundred Acre Wood.\"\n");
         load_chat("Kanga hops around taking care of things.\n");
         load_chat("Kanga smiles warmly at you.\n");
         load_a_chat("Kanga gets a very worried look on her face.\n");
         load_a_chat("Kanga looks very dissapointed in you.\n");
         break;
      case 7:
         set_name("roo");
         set_long("Little Roo hops about playfully exploring the woods.\n"+
                  "He is almost always around his mother, or following\n"+
                  "Tigger into trouble.  He is very curious, but unlike\n"+
                  "Tigger, her learns his lesson.\n");
         load_chat("Roo hops about playfully.\n");
         load_chat("Roo looks at you curiously.\n");
         load_chat("Roo says, \"Won't you be my friend.\"\n");
         load_a_chat("Roo tries to get away.\n");
         load_a_chat("Roo kicks you in the stomach!.\n");
      break;
   }
   set_level(6);
   set_race("stuffed animal");
   set_hp(70+random(40));
   set_al(50);
   set_wc(10);
   set_ac(5);
   set_chat_chance(8);
   set_a_chat_chance(15);
   set_alt_name("rand_pooh");
}
