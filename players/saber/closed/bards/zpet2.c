summon_pet(str)  {
object ob, ob2, ob3;
object TO;
int cost, no_pet;
string animal_type, OB;
string name, xname, petname;
#define BBB move_object(ob,environment(this_player()))
#define ENVV environment(this_player())

  if(!str)  {
    write("Animal <type>    <see animal_list>\n");
    return 1;
        }

  if(sscanf(str, "%s %s", name, xname) !=2)  {
    write("Animal <type> <name>\n");
    return 1;
        }

  ob = clone_object("/players/saber/closed/bards/pet/test.c");

  TO = present("instrument",this_player());
  if(!present("instrument",this_player()))  {
    write("The animal senses that you are not a bard and leaves.\n");
    return 1;
        }

  if(name == "raven")  {
  if(spell(-149,2,40) ==-1) return 0;
    ob->load_chat("The raven ruffles its feathers.\n");
    ob->load_chat("The raven says \"\KAARR\"\n");
    ob->load_chat("The raven asks \"\WROAARRKK?\"\n");
    ob->load_chat("The raven says \"\CRAACKK\"\n");
    ob->load_chat("The raven says \"\NEVERMORE\"\n");
    ob->load_chat("The raven circles.\n");
    ob->load_a_chat("The raven circles its foe.\n");
    ob->set_animal("raven");
        }
  else if(name == "crow")  {
  if(spell(-149,2,40) == -1) return 0;
    ob->set_name("crow");
    ob->set_short("A black crow");
    ob->set_long(
      "A black crow with dusky feathers anda wickedly pointed beak.\n"+
      "It has a a look of intelligence in its midnight eyes, and the \n"+
      "smile of a rogue.  The crow has a small silver back around \n"+
      "its left foot.\n");
    ob->load_chat("The crow squaks \"\CAWWWWW\"\n");
    ob->load_chat("The crow asks \"\RARRRRKK?\"\n");
    ob->load_chat("The crow looks up at you.\n");
    ob->load_chat("The crow asks \"\CAAAW?\"\n");
    ob->load_chat("The crow circles.\n");
    ob->load_a_chat("The crow circles its foe.\n");
    ob->set_spell_mess1("The crow pecks at its foe.\n");
    ob->set_spell_mess2("The crow pecks at you.\n");
    ob->set_chance(10);
    ob->set_spell_dam(5);
    ob->set_animal("crow");
        }
  else if(name == "hawk")  {
   if(spell(-149,4,40) ==-1) return 0;
    ob->set_name("hawk");
    ob->set_short("A large hawk");
    ob->set_long(
      "A large hawk with beautiful dusky feathers and strong eyes.\n"+
      "The hawk has a small silver band around its left foot.\n");
    ob->set_level(3);
    ob->set_ac(5);
    ob->set_wc(10);
    ob->set_hp(75);
    ob->load_chat("The hawk ruffles its feathers.\n");
    ob->load_chat("The hawk soars high overhead.\n");
    ob->load_chat("The hawk flies high into the sky and circles.\n");
    ob->load_chat("The hawk gazes at something.\n");
    ob->load_chat("The hawk circles its foe.\n");
    ob->load_a_chat("The hawk screams as it rakes its foe.\n");
    ob->set_spell_mess1("The hawk rakes the face of its foe with razor sharp claws.");
    ob->set_spell_mess2("The hawk rakes your face with razor sharp claws.");
    ob->set_chance(15);
    ob->set_spell_dam(random(10));
    ob->set_animal("hawk");
        }
  else if(name == "pixies")  {
   if(spell(-149,4,40) == -1) return 0;
    ob->set_name("pixies");
    ob->set_short("A band of merry pixies");
    ob->set_long(
      "A band of merry pixies armed with tiny silver swords and cute\n"+
      "little bows.  They have hair of silver and gold, and wear\n"+
      "cloth woven from the strands of a spiders web.\n"+
      "The pixies notice you looking at them, and fly over to look at you.\n");
    ob->set_level(3);
    ob->set_ac(5);
    ob->set_wc(10);
    ob->set_hp(75);
    ob->set_gender("female");
    ob->set_chance_chance(5);
    ob->load_chat("A pixie flies in and joins the band.\n");
    ob->load_chat("The pixies gossip among themselves.\n");
    ob->load_chat("The pixies flex their wings.\n");
    ob->load_chat("The pixies look at you and giggle.\n");
    ob->load_chat("The pixies flutter about.\n");
    ob->load_chat("The pixies whisper to each other.\n");
    ob->load_chat("The pixies polish their tiny swords.\n");
    ob->load_a_chat("A pixies falls to the ground.\n");
    ob->load_chat("The pixies engage in aerial acrobatics.\n");
    ob->set_spell_mess1("The pixies release a volly of arrows into their foe.\n");
    ob->set_spell_mess2("The pixies release a volly of arrows into you.  OUCH!\n");
    ob->set_chance(15);
    ob->set_spell_dam(10);
    ob->set_animal("pixies");
        }
 else if(name == "sprite")  {
  if(spell(-149,4,40) ==-1) return 0;
    ob->set_name("wind sprite");
    ob->set_alt_name("sprite");
    ob->set_short("A whirling wind sprite");
    ob->set_long("A whirling wind sprite.  It appears to be a mini tornado full of\n"+
      "leaves and other loose bits of debris.  The wind sprite has cute\n"+
      "ebony eyes, and you can hear it giggling softly.\n");
    ob->set_level(3);
    ob->set_ac(5);
    ob->set_wc(10);
    ob->set_hp(75);
    ob->load_chat("The wind sprite whirls.\n");
    ob->load_chat("The wind sprite whirls about the chamber.\n");
    ob->load_chat("The wind sprite whirls, sending leaves everywhere.\n");
    ob->load_chat("The wind sprits giggles.\n");
    ob->load_chat("The wind sprite looks up at you.\n");
    ob->load_chat("The wind sprite spins.\n");
    ob->load_a_chat("The wind sprite flies behind its foe.\n");
    ob->set_spell_mess1("The wind sprite engulfs its foe.\n");
    ob->set_spell_mess2("The wind sprite surrounds you.\n");
    ob->set_spell_dam(10);
    ob->set_chance(15);
    ob->set_animal("sprite");
        }
  else if(name == "drake")  {
   if(spell(-149,6,40) ==-1) return 0;
    ob->set_name("drake");
    ob->set_short("A large black drake");
    ob->set_long(
      "A small drake with small black scales and bright green eyes.\n"+
      "It has a tiny red tongue and small talons at the end of its wings.\n"+
      "The drake has a small silver band around its left foot.\n");
    ob->set_level(7);
    ob->set_ac(5);
    ob->set_wc(15);
    ob->set_hp(175);
    ob->load_chat("The drake preens.\n");
    ob->load_chat("The drake looks up with whirling green eyes.\n");
    ob->load_chat("The drake hisses.\n");
    ob->load_chat("The drake licks its tiny white fangs.\n");
    ob->load_chat("The drake flies about the chamber.\n");
    ob->load_chat("The drake hums softly to itself.\n");
    ob->load_a_chat("The drake circles its foe.\n");
    ob->set_spell_mess1("The drake breaths fire upon its foe.");
    ob->set_spell_mess2("The drake breaths fire upon you!");
    ob->set_chance(15);
    ob->set_spell_dam(15);
    ob->set_animal("drake");
        }
  else if(name == "pegasus")  {
   if(spell(-149,6,40) == -1) return 0;
    ob->set_name("pegasus");
    ob->set_short("A majestic white pegasus");
    ob->set_long(
      "A majestic pegasus with a pure white coat and silvery mane.\n"+
      "It has a look of deep intelligence within its opal black\n"+
      "eyes, and radiates an aura of serenity.\n");
    ob->set_level(7);
    ob->set_ac(5);
    ob->set_wc(15);
    ob->set_hp(175);
    ob->load_chat("The pegasus looks up at you.\n");
    ob->load_chat("The pegasus looks up with a sparkle in its dark eyes.\n");
    ob->load_chat("The pegasus stretches its wings.\n");
    ob->load_chat("The pegasus nudges you with a *very* soft nose.\n");
    ob->load_chat("The pegasus shakes its mane, sending silvery hair flying in every direction.\n");
    ob->load_chat("The pegasus radiates an aura of serenity.\n");
      ob->load_a_chat("The pegasus bites its foe.\n");
    ob->set_spell_mess1("The pegasus kicks out at its foe.\n");
    ob->set_spell_mess2("The pegasus kicks out at you!  Ouch!\n");
    ob->set_chance(15);
    ob->set_spell_dam(15);
    ob->set_animal("pegasus");
        }
  else if(name == "phoenix")  {
   if(spell(-149,8,40) ==-1) return 0;
    ob->set_name("phoenix");
    ob->set_short("A firey phoenix with blazing eyes");
    ob->set_long(
      "A firey phoenix with chromatic edged feathers and blazing eyes.\n"+
      "It has a fifteen foot wing span and large razor sharp claws.\n"+
      "The phoenix has a small silver band around its left foot.\n");
    ob->set_level(10);
    ob->set_ac(8);
    ob->set_wc(18);
    ob->set_hp(200);
    ob->set_al(1000);
    ob->load_chat("The phoenix ruffles its feathers.\n");
    ob->load_chat("The phoenix stretches its mighty wings.\n");
    ob->load_chat("The phoenix looks up with a sparkle in its firey eyes.\n");
    ob->load_a_chat("The phoenix circles its foe.\n");
    ob->load_a_chat("The phoenix rakes its foe with razor sharp claws.\n");
    ob->set_spell_mess1("The phoenix flies to its foe and EXPLODES in an inferno of fire.");
    ob->set_spell_mess2("The phoenix flies up to you and EXPLODES in an inferno of fire.\nOuch!");
    ob->set_chance(15);
    ob->set_spell_dam(20);
    ob->set_animal("phoenix");
        }
 else if(name == "bpegasus")  {
  if(spell(-149,8,40) == -1) return 0;
    ob->set_name("black pegasus");
    ob->set_alt_name("pegasus");
    ob->set_short("A sleek black pegasus");
    ob->set_long(
      "A sleek black pegasus with a midnight black coat and silvery mane.\n"+
      "Its eyes sparkle with intelligence, and there appears to be a look\n"+
      "or wry humor on its equine face.  The mane of the black pegasus has\n"+
      "a slight glow radiating from it.\n");
    ob->set_level(10);
    ob->set_ac(8);
    ob->set_wc(18);
    ob->set_hp(200);
    ob->set_al(1000);
    ob->load_chat("The black pegasus looks up at you.\n");
    ob->load_chat("The black pegasus looks up with a sparkle in its dark eyes.\n");
    ob->load_chat("The black pegasus stretches its wings.\n");
    ob->load_chat("The black pegasus paws the ground with an impatient hoof.\n");
    ob->load_chat("The black pegasus shakes its silvery glowing mane.\n");
    ob->load_chat("The black pegasus radiates an aura of profound serenity.\n");
    ob->load_chat("The black pegasus snorts.\n");
    ob->load_a_chat("The black pegasus bites its foe.\n");
    ob->set_spell_mess1("The black pegasus lunges out and kicks its foe.\n");
    ob->set_spell_mess2("The black pegasus lunges out and kicks you!\n");
    ob->set_chance(15);
    ob->set_spell_dam(20);
    ob->set_animal("bpegasus");
        }
  else { write("That is not a bardic animal.\n");
   return 1;
        }

  petname = TO->query_pet_name();
  if(petname != 0)  {
  if(present(petname,environment(this_player())))  {
   ob2 = present(petname,environment(this_player()));
  call_other(ob2, "bye");
        }
        }

  if(ob->query_level() > 1)  cost = 600;
  if(ob->query_level() > 3)  cost = 1200;

  if(TP->query_money() < cost)  {
    write("You do not have enough gold to summon a pet.\n");
    destruct(ob);
    return 1;
        }

  if(TO->query_bard_level() < 2)  no_pet = 1;
  if(TO->query_bard_level() < 4 && ob->query_level() > 1)  no_pet = 1;
  if(TO->query_bard_level() < 6 && ob->query_level() > 3)  no_pet = 1;
  if(TO->query_bard_level() < 8 && ob->query_level() > 7)  no_pet = 1;

  if(no_pet > 0)  {
    write("You can not summon an animal of this power yet...\n");
    write("You feel sad...\n");
    return 1;
        }

  write("You spend "+cost+" golden coins on material components.\n");
  call_other(TP, "add_money", -cost);
  call_other(ob,"set_master",this_player()->query_real_name());
  call_other(ob,"set_alias",xname);
  call_other(TO, "set_pet_name", xname);
   BBB;
  tell_room(environment(TP), "\n\n");
  write("You play a tune of summoning upon your "+TO->query_instrument()+".\n");
  say(tp+" plays a tune upon "+TP->query_possessive()+" "+TO->query_instrument()+".\n");

 if(name == "raven")  {
  tell_room(ENVV, "A raven flies in and circles "+tp+".\n");
        }
 if(name == "crow")  {
   tell_room(ENVV, "A crow flies in and lands on "+tp+"'s shoulder.\n");
        }
  if(name == "hawk")  {
   tell_room(ENVV, "An hawk flies in and circles "+tp+".\n");
        }
 if(name == "pixies")  {
  tell_room(ENVV, "A small band of pixies flutter into the room and surround "+tp+".\n");
        }
 if(name == "sprite")  {
  tell_room(ENVV, "A gust of wind surrounds "+tp+".\n"+
      "A small whirl of leaves solidifies into a wind sprite.\n");
        }
  if(name == "drake")  {
   tell_room(ENVV, "A shadow crosses over you as a small drake descends from the sky\n"+
       "and circles "+tp+" three times before landing upon "+TP->query_possessive()+" shoulder.\n");
        }
 if(name == "pegasus")  {
  tell_room(ENVV, "A pure white pegasus soars in and lands before "+tp+".\n"+
      "The pegasus rubs up against "+tp+"\n");
        }
 if(name == "griffon")  {
  tell_room(ENVV, "A shadow falls over you as a huge griffon flies into the room.\n"+
    "The griffon lands before "+tp+" and bows.\n");
        }
 if(name == "bpegasus")  {
  tell_room(ENVV, "A black pegasus with a silver mane soars into the chamber.\n"+
      "The pegasus lands and rubs up against "+tp+".\n");
        }
 if(name == "elemental")  {
  tell_room(ENVV,"\nThere is a sudden gust of wind.\n"+
    "The wind solidifies into to shape of a near transparent woman.\n"+
    "The air elemental soars over to "+tp+" and bows.\n\n");
        }
  if(name == "phoenix")  {
   if(present("corpse",environment(TP)))  {
   ob = present("corpse",environment(TP));
   if(ob->short() == "corpse of Phoenix")  {
   destruct(ob);
   tell_room(ENVV, "The corpse of the Phoenix is engulfed in an explsion of crimson fire.\n\n"+
       "A Phoenix rises from the ashes of its corpse.\n\n");
        }
        }
   tell_room(ENVV, "A column of crimson fire descends from the sky.\n\n"+
       "A phoenix rises from the ashes of the fire and flies over to "+tp+".\n");
        }
  if(name == "test")  {
   tell_room(ENVV, "A test pet flies in and bows to "+tp+".\n");
        }

  call_other(TP,"add_spell_point",-40);
  return 1;
        }

