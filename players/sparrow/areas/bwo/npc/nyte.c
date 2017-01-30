#include <ansi.h>
inherit "/obj/monster";
inherit "/players/sparrow/areas/bwo/include/mob_funcs.c";
inherit "/players/sparrow/areas/bwo/include/gear_funcs.c";

object ob;
int mydmg;
int hpbonus;

/* GLOBALS */
int *Heals_left;        /* how many heal spells Nyte has memorized */
int Silence_left;       /* how many silence spells she has memorized */
object Nyte;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    if(random(10)>2){
      ob=generate_accessory("amulet", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear amulet");
    }
    if(random(10)>2){
      ob=generate_accessory("chest", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear chest"); 
    }
    if(random(10)>2){
      ob=generate_accessory("necklace", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear necklace");
    }
    if(random(10)>2){
      ob=generate_accessory("cloak", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear cloak");
    }
    if(random(10)>2){
      ob=generate_accessory("bracelet", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear bracelet");
    }
    if(random(10)>2){
      ob=generate_accessory("belt", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear belt");
    }
    if(random(10)>2){
      ob=generate_accessory("earring", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear earring");
    }
    if(random(10)>2){
      ob=generate_accessory("ring", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear ring");
    }
    if(random(10)>2){
      ob=generate_accessory("boots", (random(2)+3));
      move_object(ob, this_object());
      init_command("wear boots");
    }
    
Heals_left = random(3)+3;
    hpbonus = Heals_left*400;
Silence_left = random(3)+1;
    Nyte = this_object();
    set_name("nyte");
    set_alias("cleric");
    set_short(CYAN+"Nyte"+NORM+" - "+HIK+"B"+NORM+"orn of the "+HIK+"Dark"+NORM);
    set_race("human");
    set_long(
      "Nyte is the Cleric - Enchanter of the Black Willow Order. Born in an act\n"+
      "of desperation by Shaade, Nyte is almost and exact clone of the former\n"+
      "Black Willow. Trained in the Clerical and Enchantment arts, Nytes main\n"+
      "role in combat is one of support.\n"
    );
    set_gender("female");
set_level(35);

set_ac(35+random(10));
set_wc(48+random(10));
set_hp(2000+random(1000));
    set_al(0);
    set_aggressive(0);
    set_chat_chance(2);
    set_a_chat_chance(10);
    set_armor_params("other|dark",10,50,0);
    set_ac_bonus(60);
    set_hp_bonus(1500+hpbonus);
    set_wc_bonus(35);
    load_chat("Nyte Prays.\n");
    load_a_chat("Nyte invokes the wrath of xxxx.\n");
    /* Disarm spell. Weak physical attack, calls disarm function in mob_funcs.c */
    add_spell("heatmetal",
      HIK+"#CMN# performs several hand signs in a furious "+HIR+"BLUR"+HIK+" as thousands of voices echo in your head!\n"+NORM,
      HIK+"#CMN# performs several hand signs in a furious "+HIR+"BLUR"+HIK+"!\n"+NORM,
25,"5d10","other|fire",0,"heatmetal");
    
    add_spell("lightning",
      HIK+"\n       Nyte kneels and invokes the power of the "+HIB+"N"+HIK+"ight "+HIB+"S"+HIK+"ky!\n"+
      HIK+"There is a bright flash of light as you are consumed by a bolt of\n"+
      HIY+"      __    ____   ___   _   _  ____  _  _  ____  _  _  ___   \n"+
          "     (  )  (_  _) / __) ( )_( )(_  _)( \\( )(_  _)( \\( )/ __)  \n"+
          "      )(__  _)(_ ( (_-.  ) _ (   )(   )  (  _)(_  )  (( (_-.  \n"+
          "     (____)(____) \\___/ (_) (_) (__) (_)\\_)(____)(_)\\_)\\___/  \n\n"+
      HIK+"  A crack of loud thunder follows, knocking you off your feet!.\n\n"+NORM,
      HIK+"\n#MN# kneels and invokes the power of the "+HIB+"N"+HIK+"ight "+HIB+"S"+HIK+"ky!\n"+
      HIY+"There is a bright flash of light, #CTN# is struck by a bolt of lightning!\n"+
      HIK+"A crack of loud thunder follows, knocking #CTN# off #TP# feet!.\n\n"+NORM,
30,({50,25}),({"other|electric","other|sonic"}),0);
    
    add_spell("shadowmissile",
      HIK+"\n#MN# screams a prayer to the "+HIB+"N"+HIK+"ight "+HIB+"S"+HIK+"ky!\n"+
      "Your body is rocked by a wave of "+HIM+"D"+HIK+"ark "+HIM+"M"+HIK+"issiles!\n\n"+NORM,
      HIK+"\n#MN# screams a prayer to the "+HIB+"N"+HIK+"ight "+HIK+"S"+HIK+"ky!\n"+
      "#CTN#'s body is rocked by a wave of "+HIM+"D"+HIK+"ark "+HIM+"M"+HIK+"issiles!\n\n"+NORM,      20,({20,20,20,15,15,15}),({"other|dark","other|dark","other|dark","magical",
      "magical","magical"}),0);
    
    add_spell("paralyze",
      HIR+"\nNyte waves her hands in the air and calls out for the Black Willow.\n"+
      "                      You are engulfed by\n"+NORM+
      HIK+"             _                 _ \n"+                        
      "            ( )               ( ) \n"+                       
      "        ___ | |__     _ _    _| |   _    _   _   _   ___ \n"+
      "      /',__)|  _ `\\ /'_` ) /'_` | /'_`\\ ( ) ( ) ( )/',__)\n"+
      "      \\__, \\| | | |( (_| |( (_| |( (_) )| \\_/ \\_/ |\\__, \\\n"+
      "      (____/(_) (_)`\\__,_)`\\__,_)`\\___/'`\\___x___/'(____/\n\n"+NORM,
      HIK+"Nyte causes the shadows to engulf #CTN#, #TS# is bound in place!\n"+NORM,
      10,10,"other|dark",6,"paralyze");
    
    set_multi_cast(0);
  }
}


do_damage(int *damage, string *method)
{
  int i, x;
  int new_dmg;
  string type,desc;
  if(!damage){
	return 0;
  }
  /* examine all the damage amounts and damage types that were given to us */
  i = sizeof(damage);
  if(Nyte->query_hp() < 300)
  {
    if(Heals_left > 0)
    {
      tell_room(environment(Nyte),
      HIK+"\nNyte casts a spell of dark healing!\nShe looks "+HIG+"much"+
      HIK+" better!\n\n"+NORM);
heal_self(500+random(500));
      Heals_left -= 1;
    }
    else 
    {
      if(environment() && environment(Nyte) && (!present("silence", environment(Nyte))))
      {
        if(Silence_left < 1) { return ::do_damage(damage, method); }
        tell_room(environment(Nyte),
        HIK+"\nIn an act of desperation, Nyte casts a spell of Silence on you!\n\n"+NORM);
addsilence();
heal_self(500+random(500));
        Silence_left -= 1;
      }
      else
      {
        switch(random(5))
        {
          case 0:
            tell_room(environment(Nyte),
            HIM+"You try to sceam but no sound comes out!!!\n"+NORM);
            break;
          case 1:
            tell_room(environment(Nyte),
            HIG+"You can hear nothing!!!\n"+NORM);
            break;
          case 2:
            tell_room(environment(Nyte),
            HIR+"Your throat is RAW from trying to scream in terror!!!\n"+NORM);
            break;
          case 3:
            tell_room(environment(Nyte),
            HIK+"The darkness fills your ears, blocking all sound!\n"+NORM);
            break;
          case 4:
            tell_room(environment(Nyte),
            HIC+"The silence is begining to drive you mad!\n");
        }
      }
    }
  }
  /* now pass the modified do_damage call onto the inherited object (living.c) */
  return ::do_damage(damage, method);
}

void
addsilence()
{
  object silence;
  if(environment() && environment(Nyte) && (!present("silence", environment(Nyte))))
  {
    environment(Nyte)->add_property("no_magic");
    silence = clone_object("/players/sparrow/areas/bwo/obj/silence.c");
    move_object(silence, environment(Nyte));
    call_other(silence,"init");
    return;
  }
  return;
}

void
paralyze(object att)
{
  object paralyze;
  if(random(4)==0)
  {
    if(!att || (present("paralyze",att))) { return; }
    paralyze = clone_object("/players/sparrow/areas/bwo/obj/paralyze.c");
    move_object(paralyze,att);
  }
  return;
}
