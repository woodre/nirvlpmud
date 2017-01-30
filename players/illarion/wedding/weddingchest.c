/* weddingchest.c - unlimited supply of certain clothing type items
 * Illarion 3/2000
 */

#define BASE "/players/illarion/obj/clothes.c"


void create_clothes();


status id(string str) {
   return str == "chest";
}
string short() {
   return "A large clothes chest";
}
void long() {
   write("A heavy chest made for holding clothes.  A minor enchantment\n"+
         "keeps anything left in it fresh and wrinkle free.\n");
}
status can_put_and_get() {
   return 1;
}
void reset(status arg) {
   if(arg) return;
   call_out("create_clothes",2);
}
status add_weight() {
   return 1;
}

void create_clothes() {
  object ob; 
  if(!environment()) return;
  if(!present("shirt")) {
    ob=clone_object(BASE);
    ob->set_id("shirt");
    ob->set_short("A loose-fitting `BLACK`black silk`off` poet shirt");
    ob->set_long(
      "A loose-fitting poet shirt of the softest black silk, with laces at "+
      "the neck and the wrists.  The neck falls open in a V-shape, laces "+
      "hanging loose from their bindings.  The wrists of the voluminous "+
      "sleeves are tightly bound, wrapped in layers of silken strands. ");
    ob->set_wear_mess("wear_room",
      "&NAME& pulls on a black poet shirt and laces the sleeves.\n");
    ob->set_wear_mess("wear_self",
      "You pull on the shirt and lace up the sleeves.\n");
    ob->set_wear_mess("remove_room",
      "&NAME& unlaces &POSS& and removes &POSS& shirt.\n");
    ob->set_wear_mess("remove_self",
      "You unlace the sleeves and remove your shirt.\n");
    move_object(ob,this_object());
  }
  if(!present("cloak")) {
    ob=clone_object(BASE);
    ob->set_id("cloak");
    ob->set_short("A `BLACK`midnight `blue`blue`off` cloak shot through with `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off` threads");
    ob->set_long("A floor-length cloak of deepest midnight blue velvet, shot "+
         "through with silver strands that catch the light.  The lining is "+
         "a lighter blue, made of shimmering satin that plays with the "+
         "light like a rippling pond.\n");
    ob->set_wear_mess("wear_room",
      "&NAME& fastens a long midnight blue cloak around &POSS& neck.");
    ob->set_wear_mess("wear_self",
      "You hang the cloak around your neck.");
    ob->set_wear_mess("remove_room",
      "&NAME& unfastens the cloak from around &POSS& neck, and removes it.");
    ob->set_wear_mess("remove_self",
      "You lift the cloak free of your neck.");
    ob->set_move_emote("self",
                      "As you move, the silver threading of your cloak "+
                      "catches and throws the light.\n");
    ob->set_move_emote("room","A bit of light glints into your eye, reflected from "+
                      "&NAME&'s cloak.\n");
    move_object(ob,this_object()); 
  }
  if(!present("belt")) {
    ob=clone_object(BASE);
    ob->set_id("belt");
    ob->set_short("A belt of glittering `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off` links");
    ob->set_long(
      "A belt of glittering silver, made to hang around the hips instead of "+
      "encircling the waist, in the medieval style.  A small silver dragon in "+
      "fighting stance serves as the clasp, and the end of the chain hangs "+
      "down below the clasp.  Occasional licks of flame from the dragon's "+
      "mouth set the whole belt to glittering. ");
    ob->set_wear_mess("wear_room",
      "&NAME& winds a long silver belt around &POSS& hips, and fastens it "+
      "with a silver dragon clasp.");
    ob->set_wear_mess("wear_self",
      "You wind the belt around your hips and fasten the clasp.");
    ob->set_wear_mess("remove_room",
      "&NAME& unfastens the clasp on her &POSS& belt, and removes it from "+
      "&POSS& hips.");
    ob->set_wear_mess("remove_self",
      "You unfasten your belt's clasp, and slip it from around your hips.");
    move_object(ob,this_object());
  }
  if(!present("dress")) {
    ob=clone_object(BASE);
    ob->set_id("dress");
    ob->set_short("A `WHITE`white silk`off` dress with trailing hem and cuffs");
    ob->set_long(
      "A medieval style dress of silk so white it is almost blinding.  The "+
      "long sweep of the neckline leaves the shoulders bare and dips low "+
      "across the chest.  Under the neckline, the dress falls gracefully "+
      "over the bosom and hugs the hips, then flares out into wide skirts, "+
      "with a long, trailing hem.  The long, graceful sleeves flare out "+
      "into long cuffs that hang to join the hem trailing on the ground.  "+
      "An intricate pattern of silver thread, almost invisible, decorates "+
      "the bodice, and opal beadwork lines the neckline, cuffs, and hem.");
    ob->set_wear_mess("wear_room",
      "&NAME& puts on a wedding gown, in whatever mysterios way women "+
      "do that.");
    ob->set_wear_mess("wear_self",
      "You pull on and arrange the wedding dress.");
    ob->set_wear_mess("remove_room",
      "&NAME& pulls on &POSS& wedding dress, and it falls off in an instant.");
    ob->set_wear_mess("remove_self",
      "As soon as you decide to remove the dress, it seems to fall away "+
      "almost of its own accord.");
    move_object(ob,this_object());

  }
  if(!present("shoes")) {
    ob=clone_object(BASE);
    ob->set_id("shoes");
    ob->set_short("A pair of `WHITE`white satin`off` shoes");
    ob->set_long("A comfortable and fairly simple pair of white shoes, "+
                 "without heels or any other adornment.");
    move_object(ob,this_object());
  }
  if(!present("circlet")) {
    ob=clone_object(BASE);
    ob->set_id("circlet");
    ob->set_alias("veils");
    ob->set_short("A simple `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off` cirlet that supports two `WHITE`white silk`off` veils");
    ob->set_long(
      "A graceful, shining circlet of silver that supports two veils of "+
      "thin white silk, an inner and an outer.  The inner veil frames the "+
      "face, and tapers all the way down to the floor in the back.  The "+
      "outer veil, so thin it is almost invisible, hangs down all around "+
      "the head nearly to shoulder level, and is trimmed around the edges "+
      "in opal beading.");
    ob->set_wear_mess("wear_room",
      "&NAME& places a silver circlet on &POSS& head, and arranges the "+
      "two veils attached to it.");
    ob->set_wear_mess("wear_self",
      "You place the cirlet on your head and arrange the veils.");
    ob->set_wear_mess("remove_room",
      "&NAME& removes the cirlet and veils from &POSS& head.");
    ob->set_wear_mess("remove_self",
      "You slip the cirlet and attached veils off your head.");
    move_object(ob,this_object());
  }
  if(!present("trousers")) {
    ob=clone_object(BASE);
    ob->set_id("trousers");
    ob->set_short("A pair of `BLACK`matte black`off` wool trousers");
    ob->set_long(
    "A pair of wool trousers so soft they hardly seem like wool at all, and "+
    "so black they appear to consume the light.\n");
    ob->set_wear_mess("wear_room",
      "&NAME& slips &POSS& legs into a pair of black trousers, and "+
      "buttons them");
    ob->set_wear_mess("wear_self",
      "You slip your legs into the trousers, and button them.\n");
    ob->set_wear_mess("remove_room",
      "&NAME& unbuttons &POSS& pants and slips them off.\n");
    ob->set_wear_mess("remove_self",
      "You unbutton the pants and slip them off.\n");
    move_object(ob,this_object());
  }
  if(!present("clasp")) {
    ob=clone_object(BASE);
    ob->set_id("clasp");
    ob->set_short("A `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off` dragon cloak clasp");
    ob->set_long(
      "A brilliant silver cloak fastening in the shape of an attacking "+
      "dragon.  An occasional tiny lick of flame from its mouth sets the "+
      "whole clasp glittering brightly.");
    ob->set_wear_mess("wear_room",
      "&NAME& fastens &POSS& cloak with a clasp in the shape of a silver "+
      "dragon.");
    ob->set_wear_mess("wear_self","You fasten your cloak with the clasp.\n");
    ob->set_wear_mess("remove_room","&NAME& unfastens &POSS& cloak clasp.\n");
    ob->set_wear_mess("remove_room","You unfasten your cloak clasp.\n");
    move_object(ob,this_object());
  }
  if(!present("gloves")) {
    ob=clone_object(BASE);
    ob->set_id("gloves");
    ob->set_short("A pair of `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off`-backed `BLACK`black kid-leather`off` gloves");
    ob->set_long(
      "These closely-fitting gloves are made of the softest kid-leather, "+
      "dyed black.  An intricate pattern of silver rings sewn onto the "+
      "backs catches and throws the light in unexpected directions with "+
      "every movement.");
    ob->set_wear_mess("wear_room",
      "&NAME& pulls a pair of silver-backed gloves onto &POSS& hands.");
    ob->set_wear_mess("wear_self",
      "You slip the gloves over your fingers.");
    ob->set_wear_mess("remove_room",
      "&NAME& removes &POSS& gloves.");
    ob->set_wear_mess("remove_self",
      "You pull off the gloves.");
    move_object(ob,this_object());
  }
  if(!present("sash")) {
    ob=clone_object(BASE);
    ob->set_id("sash");
    ob->set_short("A layered `BLACK`black silk`off` sash with `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off` braiding");
    ob->set_long(
      "A length of silk long enough to wrap around the waist several times, "+
      "twined with thin silver braiding.  A glittering silver clasp in the "+
      "shape of an attacking dragon serves to hold it in place, occasionally "+
      "growing brighter when it spits fire.");
    ob->set_wear_mess("wear_room",
      "&NAME& wraps a long silk sash around &POSS& waist, and fastens it "+
      "with a silver dragon clasp.");
    ob->set_wear_mess("wear_self",
      "You wrap the sash around your waist and fasten it with the clasp.");
    ob->set_wear_mess("remove_room",
      "&NAME unfastens the clasp of &POSS& sash, and unwraps it from around "+
      "&POSS& waist.");
    ob->set_wear_mess("remove_self",
      "You unfasten the clasp on your sash, and unwrap it from your waist.");
    move_object(ob,this_object());
  }
  if(!present("boots")) {
    ob=clone_object(BASE);
    ob->set_id("boots");
    ob->set_short("A pair of knee-high `BLACK`midnight `blue`blue`off` boots");
    ob->set_long(
      "A comfortable pair of supple, knee-high leather boots, dyed a deep "+
      "midnight blue.");
    ob->set_wear_mess("wear_room",
      "&NAME& pulls on a pair of dark blue boots.\n");
    ob->set_wear_mess("wear_self",
      "You pull the boots onto your feet.\n");
    ob->set_wear_mess("remove_room",
      "&NAME& kicks off &POSS& boots.\n");
    ob->set_wear_mess("remove_self",
      "You kick the boots off your feet.\n");
    move_object(ob,this_object());
  }
}
