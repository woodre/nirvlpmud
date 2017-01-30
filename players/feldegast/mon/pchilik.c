#include "defs.h"

inherit MONSTER;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(WEP_PATH+"martyr.c"),this_object());
  init_command("wield spear");
  set_name("p'Chilik");
  set_alias("p'chilik");
  set_alt_name("chilik");
  set_race("p'kalian");
  set_short(HIC+"P'Chilik"+NORM+" the "+HIG+"P'Kalian"+NORM);
  set_long(
"P'Chilik's dark green skin shines with health and vigor.  His two\n\
eye stalks are long, flexible and tense with alertness.  He wears\n\
the loose cotton clothes favored by the P'Kalians.  On the back of\n\
his vest is the symbol of his teacher, Master Usmitha and on the\n\
shoulder is his own symbol, signifying he is also a master.\n"
  );
  set_gender("male");
  set_level(20);
  set_hp(600);
  set_wc(34);
  set_ac(19);
  set_al(500);
  load_spell(30,15,0,
    BBLK+"\nP'Chilik bellows a loud yell as he focuses his will into\n"+
    HIC+"\t\tA BLAST OF ENERGY\n\n"+NORM,
    BBLK+"\nP'Chilik bellows a loud yell as he focuses his will into\n"+
    HIC+"\t\tA BLAST OF ENERGY\n\n"+NORM
  );
  load_spell(10,25,1, /* Spell point attack */
    BOLD+"P'Chilik knocks the wind out of you!\n"+NORM,
    BOLD+"P'Chilik knocks the wind out of #ATT#!\n"+NORM
  );
  add_talk("key", "P'chilik says: I gave the key to the well to P'lila.\n");
  add_talk("p'salin", "P'chilik says: His skill with herbs is well-respected.\n");
  add_talk("p'lila", "P'chilik says: She makes an excellent bowl of Qadlflik.\n");
  add_talk("tully", "P'chilik says: He tells many stories, few of which are true.\n");
  add_talk("p'kolitor", "P'chilik says: P'kolitor is very wise and honorable.\n");
}

void heart_beat() {
  int attack;
  string emote;
  int i;
  ::heart_beat();
  if(!attacker_ob) return;
  for(i=random(random(7)); i > 0; i--) {
    switch(random(2)) {
      case 0: emote="P'Chilik performs a ";
              switch(random(5)) {
                case 0: emote+=BBLK+RED+"Raven Slaughter"+NORM;
                        attack+=3;
                        break;
                case 1: emote+=BBLK+BLU+"Splitting Divide"+NORM;
                        attack+=3;
                        break;
                case 2: emote+=HIY+"Rising Moon"+NORM;
                        attack+=2;
                        break;
                case 3: emote+=BOLD+BLK+"Rising Slash"+NORM;
                        attack+=4;
                        break;
                case 4: emote+=HIC+"Gale Kick"+NORM;
                        attack+=3;
                        break;
              }
              emote+=".\n";
              break;
      case 1: emote="P'Chilik";
              switch(random(3)) {
                 case 0: emote+=" kicks ";
                         attack+=4;
                         break;
                 case 1: emote+=" punches ";
                         attack+=2;
                         break;
                 case 2: emote+=" chops ";
                         attack+=3;
                         break;
               }
               emote+=(string)attacker_ob->query_name();
               switch(random(5)) {
                 case 0: emote+=" in the ribs.\n"; break;
                 case 1: emote+=" in the knee.\n"; break;
                 case 2: emote+=" in the face.\n"; break;
                 case 3: emote+=" in the chest.\n"; break;
                 case 4: emote+=" in the kidneys.\n"; break;
               }
               break;
    }
    if(emote) tell_room(environment(),emote);
  }
  attacker_ob->hit_player(attack);
}
