
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

summon_pet(str)  {

object ob, ob2, ob3;
string animal_type, OB;
string name, xname, petname;
#define BBB move_object(ob,environment(this_player()))


 if(!str || (sscanf(str, "%d %s", name, xname) !=2))  {
    write("Syntax: Animal < type > < name >   < see companion_list>\n");
    return 1;
        }

  ob = clone_object("/players/saber/closed/bard/pet/companion.c");


  if(name < 8)  {
   if(spell(-50,5,40) ==-1) return 0;
        }

  if(name > 7 && name < 15)  {  
   if(spell(-50,5,40) ==-1) return 0;
    ob->set_level(3);
    ob->set_ac(5);
    ob->set_wc(10);
    ob->set_hp(75);
    ob->set_chance(15);
    ob->set_spell_dam(10);
        }

  if(name > 14 && name < 22)  {  
   if(spell(-50,8,40) ==-1) return 0;
    ob->set_level(7);
    ob->set_ac(5);
    ob->set_wc(15);
    ob->set_hp(175);
    ob->set_chance(15);
    ob->set_spell_dam(15);
        }

  if(name > 21)  {  
   if(spell(-50,11,40) ==-1) return 0;
    ob->set_level(10);
    ob->set_ac(8);
    ob->set_wc(18);
    ob->set_hp(200);
    ob->set_chance(15);
    ob->set_spell_dam(20);
    ob->set_al(1000);
        }


  if(name == 1)  {
    ob->load_chat("The raven ruffles its feathers.\n");
    ob->load_chat("The raven says \"\KAARR\"\n");
    ob->load_chat("The raven asks \"\WROAARRKK?\"\n");
    ob->load_chat("The raven says \"\CRAACKK\"\n");
    ob->load_chat("The raven says \"\NEVERMORE\"\n");
    ob->load_chat("The raven circles.\n");
    ob->load_a_chat("The raven circles its foe.\n");
    ob->set_animal("raven");
        }
        
  else if(name == 2)  {
    ob->set_name("crow");
    ob->set_short("A black crow");
    ob->set_long(
      "A black crow with dusky feathers and a wickedly pointed beak.\n"+
      "It has a look of intelligence in its midnight eyes, and the \n"+
      "smile of a rogue.  The crow has a small silver band around \n"+
      "its left foot.\n");
    ob->load_chat("The crow squaks \"\CAWWWWW\"\n");
    ob->load_chat("The crow asks \"\RARRRRKK?\"\n");
    ob->load_chat("The crow looks up at you.\n");
    ob->load_chat("The crow asks \"\CAAAW?\"\n");
    ob->load_chat("The crow circles.\n");
    ob->load_a_chat("The crow circles its foe.\n");
    ob->set_spell_mess1("The crow pecks at its foe.\n");
    ob->set_spell_mess2("The crow pecks at you.\n");
    ob->set_animal("crow");
        }
        
  else if(name == 3)  {
    ob->set_name("kitten");
    ob->set_race("feline");
    ob->set_short("A flying kitten");
    ob->set_long(
      "A cute little black and white kitten with tiny feathered wings.\n"+
      "It has soft fur and bright midnight eyes.  Listening, you can hear\n"+
      "the it purr.  The flying kitten has a small silver band around its\n"+
      "left paw.\n");
    ob->load_chat("The flying kitten mews.\n");
    ob->load_chat("The flying kitten meows.\n");
    ob->load_chat("The flying kitten looks up at you.\n");
    ob->load_chat("The flying kitten pounces on something small.\n");
    ob->load_chat("The flying kitten circles above you.\n");
    ob->load_a_chat("The flying kitten circles its foe.\n");
    ob->set_spell_mess1("The flying kitten scratches its foe.\n");
    ob->set_spell_mess2("The flying kitten scratches you.\n");
    ob->set_animal("flying kitten");
        }

  else if(name == 4)  {
    ob->set_name("dove");
    ob->set_short("A white dove");
    ob->set_long(
      "A dove with dusky white feathers and a midnight eyes.  The\n"+
      "dove has a small silver band around its left foot.\n");
    ob->load_chat("The dove coo's\n");
    ob->load_chat("The dove coo's\n");
    ob->load_chat("The dove looks up at you.\n");
    ob->load_chat("The dove circles above you.\n");
    ob->load_a_chat("The dove circles its foe.\n");
    ob->set_spell_mess1("The dove pecks at its foe.\n");
    ob->set_spell_mess2("The dove pecks at you.\n");
    ob->set_animal("dove");
        }

  else if(name == 5)  {
    ob->set_name("owl");
    ob->set_short("A magestic owl");
    ob->set_long(
      "A magestic owl with dusky brown feathers and a wickedly pointed\n"+
      "beak.  It has a look of wisdom in its midnight eyes.  The owl has\n"+
      "a small silver band around its left talon.\n");
    ob->load_chat("The owl says \"woo woo\"\n");
    ob->load_chat("The owl asks \"woo woo?\"\n");
    ob->load_chat("The owl looks up at you.\n");
    ob->load_chat("The owl gazes off into the distance.\n");
    ob->load_chat("The owl circles silently above you.\n");
    ob->load_a_chat("The owl circles its foe.\n");
    ob->set_spell_mess1("The owl pecks at its foe.\n");
    ob->set_spell_mess2("The owl pecks at you.\n");
    ob->set_animal("owl");
        }

  else if(name == 8)  {
    ob->set_name("pixies");
    ob->set_short("A band of merry pixies");
    ob->set_race("faerie");
    ob->set_long(
      "A band of merry pixies armed with tiny silver swords and cute\n"+
      "little bows.  They have hair of silver and gold, and wear cloth\n"+
      "woven from the strands of a spiders web.  The pixies notice you\n"+
      "looking at them, and fly over to look at you.\n");
    ob->set_gender("female");
    ob->set_chance_chance(5);
    ob->load_chat("A pixie flies in and joins the band.\n");
    ob->load_chat("The pixies gossip amongst themselves.\n");
    ob->load_chat("The pixies flex their wings.\n");
    ob->load_chat("The pixies look at you and giggle.\n");
    ob->load_chat("The pixies flutter about.\n");
    ob->load_chat("The pixies whisper to each other.\n");
    ob->load_chat("The pixies polish their tiny swords.\n");
    ob->load_chat("The pixies engage in aerial acrobatics.\n");
    ob->load_a_chat("A pixies falls to the ground.\n");
    ob->set_spell_mess1("The pixies release a volly of arrows into their foe.\n");
    ob->set_spell_mess2("The pixies release a volly of arrows into you.  OUCH!\n");
    ob->set_animal("pixies");
        }
        
  else if(name == 9)  {
    ob->set_name("hawk");
    ob->set_short("A large hawk");
    ob->set_long(
      "A large hawk with beautiful dusky feathers and strong eyes.\n"+
      "The hawk has a small silver band around its left foot.\n");
    ob->load_chat("The hawk ruffles its feathers.\n");
    ob->load_chat("The hawk soars high overhead.\n");
    ob->load_chat("The hawk flies high into the sky and circles.\n");
    ob->load_chat("The hawk gazes at something.\n");
    ob->load_a_chat("The hawk circles its foe.\n");
    ob->load_a_chat("The hawk screams as it rakes its foe.\n");
    ob->set_spell_mess1("The hawk rakes the face of its foe with razor sharp claws.");
    ob->set_spell_mess2("The hawk rakes your face with razor sharp claws.");
    ob->set_animal("hawk");
        }
        
  else if(name == 10)  {
    ob->set_name("wind sprite");
    ob->set_race("faerie");
    ob->set_alt_name("sprite");
    ob->set_short("A whirling wind sprite");
    ob->set_long(
      "A whirling wind sprite.  It appears to be a mini tornado full of\n"+
      "leaves and other loose bits of debris.  The wind sprite has cute\n"+
      "ebony eyes, and you can hear it giggling softly.\n");
    ob->load_chat("The wind sprite whirls.\n");
    ob->load_chat("The wind sprite whirls about the chamber.\n");
    ob->load_chat("The wind sprite whirls, sending leaves everywhere.\n");
    ob->load_chat("The wind sprits giggles.\n");
    ob->load_chat("The wind sprite looks up at you.\n");
    ob->load_chat("The wind sprite spins.\n");
    ob->load_a_chat("The wind sprite flies behind its foe.\n");
    ob->set_spell_mess1("The wind sprite engulfs its foe.\n");
    ob->set_spell_mess2("The wind sprite surrounds you.\n");
    ob->set_animal("sprite");
        }
        
  else if(name == 11)  {
    ob->set_name("winged cat");
    ob->set_race("feline");
    ob->set_alt_name("cat");
    ob->set_short("A winged cat");
    ob->set_long(
      "A fluffy black and white cat with tiny feathered wings.  It has soft\n"+
      "fur and bright midnight eyes.  Listening, you can hear the it purr.\n"+ 
      "The winged cat has a small silver band around its left paw.\n");
    ob->load_chat("The winged cat mews.\n");
    ob->load_chat("The winged cat meows.\n");
    ob->load_chat("The winged cat looks up at you.\n");
    ob->load_chat("The winged cat pounces on something small.\n");
    ob->load_chat("The winged cat circles above you.\n");
    ob->load_chat("The winged cat circles purrs.\n");
    ob->load_a_chat("The winged cat circles its foe.\n");    
    ob->set_spell_mess1("The winged cat scratches its foe.\n");
    ob->set_spell_mess2("The winged cat scratches you.\n");
    ob->set_animal("winged cat");
        }

  else if(name == 12)  {
    ob->set_name("eagle");
    ob->set_short("A fierce eagle");
    ob->set_long(
      "A fierce eagle with beautiful dusky feathers and piercing eyes.\n"+
      "The eagle has a small silver band around its left foot.\n");
    ob->load_chat("The eagle ruffles its feathers.\n");
    ob->load_chat("The eagle soars high overhead.\n");
    ob->load_chat("The eagle flies high into the sky and circles.\n");
    ob->load_chat("The eagle gazes at something.\n");
    ob->load_a_chat("The eagle circles its foe.\n");
    ob->load_a_chat("The eagle screams as it rakes its foe.\n");
    ob->set_spell_mess1("The eagle rakes the face of its foe with razor sharp claws.");
    ob->set_spell_mess2("The eagle rakes your face with razor sharp claws.");
    ob->set_animal("eagle");
        }

  else if(name == 13)  {
    ob->set_name("fire sprite");
    ob->set_race("faerie");
    ob->set_alt_name("sprite");
    ob->set_short("A whirling fire sprite");
    ob->set_long(
      "A whirling fire sprite.  It appears to be a mini tornado full of\n"+
      "sparks and tiny bits of flame.  The fire sprite has cute ruby eyes.\n"+
      "Listening, you think you hear it giggling softly.\n");
    ob->load_chat("The fire sprite whirls.\n");
    ob->load_chat("The fire sprite whirls about the chamber.\n");
    ob->load_chat("The fire sprite whirls, sending sparks everywhere.\n");
    ob->load_chat("The fire sprits giggles.\n");
    ob->load_chat("The fire sprite looks up at you.\n");
    ob->load_chat("The fire sprite spins.\n");
    ob->load_a_chat("The wind sprite flanks its foe.\n");
    ob->set_spell_mess1("The fire sprite engulfs its foe in fire.\n");
    ob->set_spell_mess2("The fire sprite surrounds you with fire.\n");
    ob->set_animal("sprite");
        }

  else if(name == 14)  {
    ob->set_name("rain sprite");
    ob->set_race("faerie");
    ob->set_alt_name("sprite");
    ob->set_short("A whirling rain sprite");
    ob->set_long(
      "A whirling rain sprite.  It appears to be a mini tornado full of\n"+
      "rain and tiny hail stones.  The rain sprite has cute topaz eyes.\n"+
      "Listening, you think you hear it giggling softly.\n");
    ob->load_chat("The rain sprite whirls.\n");
    ob->load_chat("The rain sprite whirls about the chamber.\n");
    ob->load_chat("The rain sprite whirls, sending water everywhere.\n");
    ob->load_chat("The rain sprits giggles.\n");
    ob->load_chat("The rain sprite looks up at you.\n");
    ob->load_chat("The rain sprite spins.\n");
    ob->load_a_chat("The rain sprite flanks its foe.\n");
    ob->set_spell_mess1("The rain sprite engulfs its foe.\n");
    ob->set_spell_mess2("The rain sprite surrounds you.\n");
    ob->set_animal("sprite");
        }

  else if(name == 15)  {
    ob->set_name("drake");
    ob->set_race("dragon");
    ob->set_short("A large black drake");
    ob->set_long(
      "A small drake with small black scales and bright green eyes.\n"+
      "It has a tiny red tongue and small talons at the end of its wings.\n"+
      "The drake has a small silver band around its left foot.\n");
    ob->load_chat("The drake preens.\n");
    ob->load_chat("The drake looks up with whirling green eyes.\n");
    ob->load_chat("The drake hisses.\n");
    ob->load_chat("The drake licks its tiny white fangs.\n");
    ob->load_chat("The drake flies about the chamber.\n");
    ob->load_chat("The drake hums softly to itself.\n");
    ob->load_a_chat("The drake circles its foe.\n");
    ob->set_spell_mess1("The drake breaths fire upon its foe.");
    ob->set_spell_mess2("The drake breaths fire upon you!");
    ob->set_animal("drake");
        }
        
  else if(name == 16)  {
    ob->set_name("pegasus");
    ob->set_short("A majestic white pegasus");
    ob->set_race("pegasus");
    ob->set_long(
      "A majestic pegasus with a pure white coat and silvery mane.\n"+
      "It has a look of deep intelligence within its opal black\n"+
      "eyes, and radiates an aura of serenity.\n");
    ob->load_chat("The pegasus looks up at you.\n");
    ob->load_chat("The pegasus looks up with a sparkle in its dark eyes.\n");
    ob->load_chat("The pegasus stretches its wings.\n");
    ob->load_chat("The pegasus nudges you with a *very* soft nose.\n");
    ob->load_chat("The pegasus shakes its mane, sending silvery hair flying in every direction.\n");
    ob->load_chat("The pegasus radiates an aura of serenity.\n");
    ob->load_a_chat("The pegasus bites its foe.\n");
    ob->set_spell_mess1("The pegasus kicks out at its foe.\n");
    ob->set_spell_mess2("The pegasus kicks out at you!  Ouch!\n");
    ob->set_animal("pegasus");
        }
        
  else if(name == 17)  {
    ob->set_name("wind spirit");
    ob->set_race("spirit");
    ob->set_alt_name("spirit");
    ob->set_short("A whistling wind spirit");
    ob->set_long(
      "A whistling wind spirit.  It appears to be a small tornado full of\n"+
      "leaves and other loose bits of debris.  The wind spirit deep topaz\n"+
      "eyes, and the laugh of wind through the trees.\n");
    ob->load_chat("The wind spirit whistles.\n");
    ob->load_chat("The wind spirit whirls about the chamber.\n");
    ob->load_chat("The wind spirit whirls, sending leaves everywhere.\n");
    ob->load_chat("The wind spirit laughs.\n");
    ob->load_chat("The wind spirit looks up at you.\n");
    ob->load_chat("The wind spirit circles high above you.\n");
    ob->load_a_chat("The wind spirit flanks its foe.\n");
    ob->set_spell_mess1("The wind spirit engulfs its foe in its tornado body.\n");
    ob->set_spell_mess2("The wind spirit surrounds you with its tornado body.\n");
    ob->set_animal("spirit");
        }

  else if(name == 18)  {
    ob->set_name("griffon");
    ob->set_race("griffon");
    ob->set_alt_name("griffon");
    ob->set_short("A majestic griffon");
    ob->set_long(
      "A whistling wind sprite.  It appears to be a small tornado full of\n"+
      "leaves and other loose bits of debris.  The wind spirit deep topaz\n"+
      "eyes, and the laugh of wind through the trees.\n");
    ob->load_chat("The griffon stretches its wings.\n");
    ob->load_chat("The griffon radiates an aura of majesty.\n");
    ob->load_chat("The griffon paws the ground impatiently.\n");
    ob->load_chat("The griffon preens.\n");
    ob->load_chat("The griffon looks at you.\n");
    ob->load_chat("The griffon circles high above you.\n");
    ob->load_a_chat("The griffon circles behind you.\n");
    ob->set_spell_mess1("The griffon rakes its foe with razor sharp claws.\n");
    ob->set_spell_mess2("The griffon rakes you with razor sharp claws.\n");
    ob->set_animal("griffon");
        }

  else if(name == 19)  {
    ob->set_name("rain spirit");
    ob->set_race("spirit");
    ob->set_alt_name("spirit");
    ob->set_short("A thundering rain spirit");
    ob->set_long(
      "A thundering wind spirit.  It appears to be a small tornado full of\n"+
      "rain and large chunks of hail.  The rain spirit deep emerald eyes,\n"+
      "and the laugh of rain falling on the ocean.\n");
    ob->load_chat("The rain spirit thunders.\n");
    ob->load_chat("The rain spirit whirls about the chamber.\n");
    ob->load_chat("The rain spirit whirls, sending water everywhere.\n");
    ob->load_chat("The rain spirit laughs.\n");
    ob->load_chat("The rain spirit looks up at you.\n");
    ob->load_chat("The rain spirit circles high above you.\n");
    ob->load_a_chat("The rain spirit flanks its foe.\n");
    ob->set_spell_mess1("The rain spirit engulfs its foe in its tornado body.\n");
    ob->set_spell_mess2("The rain spirit surrounds you with its tornado body.\n");
    ob->set_animal("spirit");
        }
  
  else if(name == 20)  {
    ob->set_name("lightning spirit");
    ob->set_race("spirit");
    ob->set_alt_name("spirit");
    ob->set_short("A flashing lightning spirit");
    ob->set_long(
      "A flashing lightning spirit.  It appears to be a small tornado full of\n"+
      "eletrical sparks and pulsing embers.  The lightning spirit has light\n"+
      "amber eyes, and the laugh of distant thunder.\n");
    ob->load_chat("The lightning spirit pulses.\n");
    ob->load_chat("The lightning spirit whirls about the chamber.\n");
    ob->load_chat("The lightning spirit whirls, sending sparks everywhere.\n");
    ob->load_chat("The lightning spirit laughs.\n");
    ob->load_chat("The lightning spirit looks up at you.\n");
    ob->load_chat("The lightning spirit circles high above you.\n");
    ob->load_a_chat("The lightning spirit flanks its foe.\n");
    ob->set_spell_mess1("The lightning spirit engulfs its foe in a column of electrical fury.\n");
    ob->set_spell_mess2("The lightning spirit surrounds you in a column of electrical fury.\n");
    ob->set_animal("spirit");
        }

  else if(name == 21)  {
    ob->set_name("fire spirit");
    ob->set_race("spirit");
    ob->set_alt_name("spirit");
    ob->set_short("A flaming fire spirit");
    ob->set_long(
      "A flashing lightning spirit.  It appears to be a small tornado full of\n"+
      "eletrical sparks and pulsing embers.  The lightning spirit light amber\n"+
      "eyes, and the laugh of distant thunder.\n");
    ob->load_chat("The fire spirit blazes.\n");
    ob->load_chat("The fire spirit whirls about the chamber.\n");
    ob->load_chat("The fire spirit whirls, sending sparks everywhere.\n");
    ob->load_chat("The fire spirit laughs.\n");
    ob->load_chat("The fire spirit looks up at you.\n");
    ob->load_chat("The fire spirit circles high above you.\n");
    ob->load_a_chat("The fire spirit flanks its foe.\n");
    ob->set_spell_mess1("The fire spirit engulfs its foe in a column of blazing fury.\n");
    ob->set_spell_mess2("The fire spirit surrounds you in a column of blazing fury.\n");
    ob->set_animal("spirit");
        }

  else if(name == 22)  {
    ob->set_name("phoenix");
    ob->set_race("immortal");
    ob->set_short("A firey phoenix with blazing eyes");
    ob->set_long(
      "A firey phoenix with chromatic edged feathers and blazing eyes.\n"+
      "It has a fifteen foot wing span and large razor sharp claws.\n"+
      "The phoenix has a small silver band around its left foot.\n");
    ob->load_chat("The phoenix ruffles its feathers.\n");
    ob->load_chat("The phoenix stretches its mighty wings.\n");
    ob->load_chat("The phoenix looks up with a sparkle in its firey eyes.\n");
    ob->load_a_chat("The phoenix circles its foe.\n");
    ob->load_a_chat("The phoenix rakes its foe with razor sharp claws.\n");
    ob->set_spell_mess1("The phoenix flies to its foe and EXPLODES in an inferno of fire.");
    ob->set_spell_mess2("The phoenix flies up to you and EXPLODES in an inferno of fire.\nOuch!");
    ob->set_animal("phoenix");
        }
        
 else if(name == 23)  {
    ob->set_name("black pegasus");
    ob->set_race("pegasus");
    ob->set_alt_name("pegasus");
    ob->set_short("A sleek black pegasus");
    ob->set_long(
      "A sleek black pegasus with a midnight black coat and silvery mane.\n"+
      "Its eyes sparkle with intelligence, and there appears to be a look\n"+
      "or wry humor on its equine face.  The mane of the black pegasus has\n"+
      "a slight glow radiating from it.\n");
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
    ob->set_animal("pegasus");
        }
        
 else if(name == 24)  {
    ob->set_name("puffball of doom");
    ob->set_alt_name("puffball");
    ob->set_race("faerie");
    ob->set_short("A puffball of doom");
    ob->set_long(
      "A tiny glowing pufball of silvery shadow.  It pulses to an unheard\n"+
      "beat, and views the world through crimson eyes.\n");
    ob->load_chat("The puffball of doom looks up at you.\n");
    ob->load_chat("The puffball of doom drifts about the chamber.\n");
    ob->load_chat("The puffball of doom drifts about the chamber.\n");
    ob->load_chat("The puffball of doom brushes against you.\nHummm.  Soft.\n");
    ob->load_chat("The puffball of doom whirls.\n");
    ob->load_chat("The puffball of doom giggles.\n");
    ob->load_a_chat("The puffball of doom floats menacingly towards its foe.\n");
    ob->set_spell_mess1("The puffball of doom engulfs its foe in an explosion of spores.\n");
    ob->set_spell_mess2("The puffball of doom explodes around you!\nAck!  Spores...\n");
    ob->set_animal("puffball");
        }

  else if(name == 25)  {
    ob->set_name("wind elemental");
    ob->set_race("elemental");
    ob->set_alt_name("elemental");
    ob->set_short("A whirling wind elemental");
    ob->set_long(
      "A whirling wind elemental.  It appears to be a tornado full of loose\n"+
      "debris whipping round at breakneck speed.  The wind elemental has deep\n"+
      "orb-eyes of translucent silver, and the laugh of a distant storm.\n");
    ob->load_chat("The wind elemental whirls.\n");
    ob->load_chat("The wind elemental whirls about the chamber.\n");
    ob->load_chat("The wind elemental whirls, sending leaves flying.\n");
    ob->load_chat("The wind elemental laughs.\n");
    ob->load_chat("The wind elemental looks up at you.\n");
    ob->load_chat("The wind elemental circles high above you.\n");
    ob->load_a_chat("The wind elemental flanks its foe.\n");
    ob->set_spell_mess1("The wind elemental engulfs its foe in a column of air.\n");
    ob->set_spell_mess2("The wind elemental surrounds you in a column of air.\n");
    ob->set_animal("elemental");
        }
   
  else if(name == 26)  {
    ob->set_name("rain elemental");
    ob->set_race("elemental");
    ob->set_alt_name("elemental");
    ob->set_short("A stormy rain elemental");
    ob->set_long(
      "A whirling rain elemental.  It appears to be a tornado filled with\n"+
      "large chunks of razor sharp hail.  The rain elemental has deep\n"+
      "orb-eyes of translucent ebony, and the laugh of thunder.\n");
    ob->load_chat("The rain elemental whirls.\n");
    ob->load_chat("The rain elemental whirls about the chamber.\n");
    ob->load_chat("The rain elemental whirls, sending water flying.\n");
    ob->load_chat("The rain elemental laughs.\n");
    ob->load_chat("The rain elemental looks up at you.\n");
    ob->load_chat("The rain elemental circles high above you.\n");
    ob->load_a_chat("The rain elemental flanks its foe.\n");
    ob->set_spell_mess1("The rain elemental engulfs its foe in a column of water.\n");
    ob->set_spell_mess2("The rain elemental surrounds you in a column of water.\n");
    ob->set_animal("elemental");
        }

  else if(name == 27)  {
    ob->set_name("lightning elemental");
    ob->set_race("elemental");
    ob->set_alt_name("elemental");
    ob->set_short("A pusling lightning elemental");
    ob->set_long(
      "A whirling lightning elemental.  It appears to be a tornado filled\n"+
      "furies of raging electricity.  The lightning elemental has deep\n"+
      "orb-eyes of translucent crystal, and the laugh of nearby thunder.\n");
    ob->load_chat("The lightning elemental whirls.\n");
    ob->load_chat("The lightning elemental whirls about the chamber.\n");
    ob->load_chat("The lightning elemental whirls, sending sparks flying.\n");
    ob->load_chat("The lightning elemental laughs.\n");
    ob->load_chat("The lightning elemental looks up at you.\n");
    ob->load_chat("The lightning elemental circles high above you.\n");
    ob->load_a_chat("The lightning elemental flanks its foe.\n");
    ob->set_spell_mess1("The lightning elemental engulfs its foe in a column raging electricity.\n");
    ob->set_spell_mess2("The lightning elemental surrounds you in a column of raging electricity.\n");
    ob->set_animal("elemental");
        }

  else if(name == 28)  {
    ob->set_name("fire elemental");
    ob->set_race("elemental");
    ob->set_alt_name("elemental");
    ob->set_short("A blazing fire elemental");
    ob->set_long(
      "A blazing fire elemental.  It appears to be a tornado filled\n"+
      "furies of raging electricity.  The lightning elemental has deep\n"+
      "orb-eyes of translucent crystal, and the laugh of nearby thunder.\n");
    ob->load_chat("The fire elemental whirls.\n");
    ob->load_chat("The fire elemental whirls about the chamber.\n");
    ob->load_chat("The fire elemental whirls, sending sparks and embers flying.\n");
    ob->load_chat("The fire elemental laughs.\n");
    ob->load_chat("The fire elemental looks up at you.\n");
    ob->load_chat("The fire elemental circles high above you.\n");
    ob->load_a_chat("The fire elemental flanks its foe.\n");
    ob->set_spell_mess1("The fire elemental engulfs its foe in a column of fire.\n");
    ob->set_spell_mess2("The fire elemental surrounds you in a column of fire.\n");
    ob->set_animal("elemental");
        }
        
  else { write("That is not a bardic companion.\n");
   return 1;
        }


  petname = this_object()->query_pet_name();
  if(petname != 0)  {
    if(present(petname,environment(TP)))  {
     ob2 = present(petname,environment(TP));
     call_other(ob2, "bye");
        }
        }

  call_other(ob,"set_master",this_player()->query_real_name());
  call_other(ob,"set_alias",xname);
  call_other(TO, "set_pet_name", xname);
  
  BBB;

  tell_room(environment(TP), "\n\n");
  write("\nYou play a "+BOLD+"Tune of Summoning"+NORM+" upon your "+TO->query_instrument()+".\n");
  say(tp+" plays a tune upon "+TP->query_possessive()+" "+TO->query_instrument()+".\n");


 if(name == "raven")  {
  tell_room(ENV, "A raven flies in and circles "+tp+".\n");
        }
 if(name == "crow")  {
   tell_room(ENV, "A crow flies in and lands on "+tp+"'s shoulder.\n");
        }
  if(name == "hawk")  {
   tell_room(ENV, "An hawk flies in and circles "+tp+".\n");
        }
 if(name == "pixies")  {
  tell_room(ENV, "A small band of pixies flutter into the room and surround "+tp+".\n");
        }
 if(name == "sprite")  {
  tell_room(ENV, "A gust of wind surrounds "+tp+".\n"+
      "A small whirl of leaves solidifies into a wind sprite.\n");
        }
  if(name == "drake")  {
   tell_room(ENV, "A shadow crosses over you as a small drake descends from the sky\n"+
       "and circles "+tp+" three times before landing upon "+TP->query_possessive()+" shoulder.\n");
        }
 if(name == "pegasus")  {
  tell_room(ENV, "A pure white pegasus soars in and lands before "+tp+".\n"+
      "The pegasus rubs up against "+tp+"\n");
        }
 if(name == "griffon")  {
  tell_room(ENV, "A shadow falls over you as a huge griffon flies into the room.\n"+
    "The griffon lands before "+tp+" and bows.\n");
        }
 if(name == "bpegasus")  {
  tell_room(ENV, "A black pegasus with a silver mane soars into the chamber.\n"+
      "The pegasus lands and rubs up against "+tp+".\n");
        }
 if(name == "elemental")  {
  tell_room(ENV,"\nThere is a sudden gust of wind.\n"+
    "The wind solidifies into to shape of a near transparent woman.\n"+
    "The air elemental soars over to "+tp+" and bows.\n\n");
        }
 if(name == "phoenix")  {
   tell_room(ENV, "A column of crimson fire descends from the sky.\n\n"+
       "A phoenix rises from the ashes of the fire and flies over to "+tp+".\n");
        }
  if(name == "test")  {
   tell_room(ENV, "A test pet flies in and bows to "+tp+".\n");
        }

  call_other(TP,"add_spell_point",-40);
  return 1;
        }

/*
set_pet_name(str)  { pet_name = str; }
query_pet_name()   { return pet_name;}
*/
