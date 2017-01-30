#include "/players/tristian/lib/supermaxdefine.h"

inherit "obj/weapon";

#define GUILDID "mageobj"
#define BONUS_TYPE "evocation"
#define BONUS_AMOUNT 2

string belt;
string *Styles;
string *Hits;
string *Body;
string *Color;

void set_belt(string str) { belt = str; }
string query_belt() { return belt; }

void reset(int arg) {
  if (arg)
    return;
  ::reset();
  set_name("Black Tiger Fist Martial Arts");
  set_class(1);
  set_weight(3);
  set_value(750);
  set_hit_func(this_object());
  belt = BOLD + "White" + NORM;
  Styles = ({ " runs across the tree tops using the "+HIR+"Fast Feet"+NORM+" Technique to gain the advantage on "+POSESS+" foe.",
              " leaps high in the sky casting a long shadow across "+POSESS+" opponent using the "+HIG+"Jumping Cricket"+NORM+" maneuver.",
              " crouches low, widens "+POSESS+" feet and strikes "+POSESS+" foe using the "+HIY+"Taming of the Tiger"+NORM+" stance.",
              " grasps "+POSESS+" opponent and tosses them through the air using the "+HIM+"Ippon-Seoi-Nage"+NORM+" throw.",
              " uses the elbow strike known as "+HIG+"Phoenix Flap Wings"+NORM+" to immobilize "+POSESS+" foe.",
              " launches into the air using the "+HIB+"Snake in the Monkey's Shadow"+NORM+" form and paralyses "+POSESS+" foe with fear.",
              " rapidly strikes "+POSESS+" opponent using the "+HIM+"The Five Deadly Venom's"+NORM+ " stance.",
              " strikes "+POSESS+" opponent in the solar plexus, knocking the wind from them utilizing the "+HIC+"Northern Preying Mantis"+NORM+" form.",
              " utilizes the "+HIC+"Knife Hand Hold"+NORM+" to freeze "+POSESS+" opponent, opening them up for the upcoming onslaught.",
              " grapples "+POSESS+" opponent with a "+HIR+"Gracie Jiu Jitsu"+NORM+" arm bar, rendering the arm useless.",
              " begins to sway and swing back and forth in a "+HIG+"Capoeira Ginga"+NORM+" and launches into a leg sweep toppling "+POSESS+" opponent to the ground.",
              " uses lighting fast strikes from "+HIR+"Wing Chung Kung Fu"+NORM+" to dazzle "+POSESS+" opponent into a momentary trance like state.",

/*/Phoenix Eye Fist
Hits = ({ " kicks " + POSESS + Color[random(sizeof(Color))] + " opponent " + NORM + "in the ", });
//Snake and Crane Arts of Shaolin*/
           });
  Hits = ({ " kicks "+POSESS+" opponent in the ",
            " punches "+POSESS+" opponent in the ",
            " performs a spinning back kick to "+POSESS+" opponent's ",
            " does a spinning backfist and strikes "+POSESS+" opponent in the ",
            " chops "+POSESS+ " opponent in the ",
            " uses a jumping front kick to strike "+POSESS+ " opponent in the "
         });

  Body = ({ "head",
            "groin",
            "knee",
            "arm",
            "leg",
            "knee",
            "shoulder",
            "back",
            "thigh",
            "foot"
         });
    Color = ({ HIR,HIG,HIY,HIK,HIB,HIM,HIC,HIW,BRED,BGRN,BYEL,BBLU,BMAG,BCYN,BWHT
         });

  message_hit=({
    ""+HIR+"ends"+NORM+""," with a coup de grace",  
    ""+RED+"destroyed"+NORM+""," into small pieces",
    ""+HIC+"shattered"+NORM+""," leaving broken bones",
    ""+HIY+"crushed"+NORM+""," leaving a deep bruise",
    ""+HIK+"hammered"+NORM+""," hard enough to leave a welt",
    ""+BLU+"chopped"+NORM+""," with a moderate force",
    ""+BLU+"prodded"+NORM+""," with a weak blow",
  });
}

void init() {
  ::init();
  add_action("wield", "wield");
}

int id(string str) {
  return str == "kung fu" || str == "martial arts" || str == "tiger fist" ||
         str == "tiger" || str == "black tiger" || str == "kungfu";
}

void long() {
  write("This is the essence of the Black Tiger Fist Style of Martial Arts.\n" +
        "It is the very embodiment of the principles of Hei hun quan and\n" +
        "the stronger you are, the strong it is.\n" +
        "It appears you have a " + query_belt() + " belt in Martial Arts.\n");
}

string short() {
  return ""+HIK+"Black"+HIR+" Tiger Fist"+NORM+" Martial Arts [" + query_belt() + " belt]";
}

int wield(string str) {
  int stats, newclass;

  stats = ((int)this_player()->query_attrib("int") +
           (int)this_player()->query_attrib("wil") +
           (int)this_player()->query_attrib("str")) / 3;
  if (id(str)) {
    switch(stats) {
      case 0..10:
        newclass = 5;
         write (BLINK+HIW+"Your kung fu skills are very weak, you should try to become smarter and mentally stronger\n"+
                "to gain any use from your skills.\n"+NORM);
        belt = HIW + "White" + NORM;
        break;
      case 11..19:
        newclass = 16;
         write (BLINK+HIB+"Your kung fu skills could use improvement, while you are capable you should\n"+
                "try to become smarter and mentally stronger to gain full benefit of your skills.\n"+NORM);
        belt = HIB + "Blue" + NORM;
        break;
      case 20..29:
        newclass = 18;
         write (BLINK+HIR+"Your kung fu skills are improving, you are almost gaining full benefit of your skills,\n"+
                "if you were a little smarter and mentally stronger you would gain full benefit from your skills\n"+NORM);
        belt = HIR + "Red" + NORM;
        break;
      default:
        newclass = 20;
         write (BLINK+HIK+"Your have mastered your kung fu skills, not many can stand up to the onslaught you bring to bear.\n"+NORM);
        belt = HIK + "Black" + NORM;
        break;
    }
    set_class(newclass);
    set_belt(belt);
    ::wield(str);
    return 1;
  }
  return 0;
}

weapon_hit(attacker) {
  tell_room(environment(this_player()),TPN+ Styles[random(sizeof(Styles))] + "\n");
  tell_room(environment(this_player()),Color[random(sizeof(Color))] + TPN + Hits[random(sizeof(Hits))] + Color[random(sizeof(Color))] + Body[random(sizeof(Body))] + ".\n"+NORM);
  special_hit(attacker);

  return 1;
    }


special_hit(attacker) {
  int w, sps, hps;
  w=random(3);

  if(!w) {
    switch(random(4)) {
      case 0: tell_room(environment(this_player()),HIW+TPN+" focuses "+POSESS+HIY+" CHI"+HIW+" and gains "+HIR+"mental clarity"+NORM+".\n\n"+
          HIR+"   CCCCC    HH   HH   IIIIII\n"+
              "  CCCCCCC   HH   HH   IIIIII\n"+
              " CC    CC   HH   HH     II\n");
              tell_room(environment(this_player()),
              " CC         HHHHHHH     II\n"+
              " CC    CC   HH   HH     II\n"+
              "  CCCCCCC   HH   HH   IIIIII\n"+
              "   CCCCC    HH   HH   IIIIII\n\n"+NORM);
              sps = (random(5));
              this_player()->add_spell_point(sps);
              break;
      case 1: tell_room(environment(this_player()),HIW+TPN+" focuses "+POSESS+HIR+" CHI"+HIW+" and gains "+HIY+"physical power"+NORM+".\n\n"+
          HIY+"   CCCCC    HH   HH   IIIIII\n"+
              "  CCCCCCC   HH   HH   IIIIII\n"+
              " CC    CC   HH   HH     II\n");
              tell_room(environment(this_player()),
              " CC         HHHHHHH     II\n"+
              " CC    CC   HH   HH     II\n"+
              "  CCCCCCC   HH   HH   IIIIII\n"+
              "   CCCCC    HH   HH   IIIIII\n\n"+NORM);
              hps = (random(5));
              this_player()->add_hit_point(hps);
              break;
      case 2: tell_room(environment(this_player()),HIY+TPN+" quietly stands amid "+attacker->query_name()+"'s flurry of attacks and centers "+POSESS+" focus.\n\n"+
          HIG+" FFFFFFF    OOOO     CCCCCC   UU   UU    SSS\n"+
              " FFFFFFF   OOOOOO    CCCCCC   UU   UU  SSS  SSS\n"+
              " FFF      OO    OO  CC    CC  UU   UU   SSS\n");
              tell_room(environment(this_player()),
              " FFFFFFF  OO    OO  CC        UU   UU    SSSSS\n"+
              " FFFFFFF  OO    OO  CC        UU   UU       SSS\n"+
              " FFF      OO    OO  CC    CC  UU   UU        SSS\n");
              tell_room(environment(this_player()),
              " FFF       OOOOOO    CCCCCC   UUUUUUU  SSS SSS\n"+
              " FFF        OOOO     CCCCC    UUUUUUU    SSS\n\n"+NORM);
              attacker->do_damage(({(random(10) + 5)}),({"other:tristian"}));
              break;
      case 3: tell_room(environment(this_player()),HIW+TPN+" closes "+POSESS+" eyes, while "+attacker->query_name()+" flails ineffectively around "+OBJECTIVE+", \n"+
              "after what seems like an"+HIR+" eternity "+HIW+TPN+" launches into a "+HIG+BLINK+"flurry of blows.\n"+NORM);
              tell_room(environment(this_player()),TPN+ Styles[random(sizeof(Styles))] + "\n");
              tell_room(environment(this_player()),Color[random(sizeof(Color))] + TPN + Hits[random(sizeof(Hits))] + Color[random(sizeof(Color))] + Body[random(sizeof(Body))] + ".\n"+NORM);
              special_hit(attacker);
              break;
    }
    return 1;
  }
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);   
 }
                        
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);  
  }
}

