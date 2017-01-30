#include "defs.h"
/*
Temple of the Seven Gods:
A regeneration spell that only works in combat may be bought here...
It works very slowly, and only during combat, so the cost is somewhat
lower than the guidelines, which to be perfectly honest are rather
absurd anyway.
*/
#define DIV 50

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(2);
  short_desc="Temple of the Seven Gods";
  long_desc=
"  This temple was built in honor of the Seven Major Deities of the\n\
Allandrian pantheon: The Sage, The Builder, The Hunter, The Maiden,\n\
The Stranger, The Guardian, and The Trickster.  An icon of each deity\n\
is placed on each of the seven walls of the temple, with a prayer bench\n\
and an offering table before each of them.\n\
Commands: pray, donate\n";
  items=({
    "icon","An icon of each of the deities is placed on each wall of the temple",
    "bench","It looks uncomfortable",
    "table","Offerings may be donated to the temple on these tables",
  });
  dest_dir=({
    PATH+"stab.c","leave",
  });
}

void init() {
  ::init();
  add_action("cmd_donate","donate");
  add_action("cmd_pray","pray");
}

int cmd_pray(string str) {
  if(!str) {
    notify_fail("Which deity do you wish to pray to?\n");
    return 0;
  }
  sscanf(str,"to %s",str);
/*
This should be a case statement, but I started out with fewer gods
so it didn't seem necessary until it was too late.
*/
  if(str=="sage" || str=="the sage") {
    write("The path to enlightenment is found in the inner struggle.\n"+
          "Worldly struggles are meaningless until that battle is won.\n");
    return 1;
  }
  if(str=="builder" || str=="the builder") {
    write("The only reason for living is to build, whether it is\n"+
          "merely shelter from the cold, or a statue that expresses\n"+
          "an artist's mastery.  Creation is the ultimate expression\n"+
          "of the soul.\n");
    return 1;
  }
  if(str=="hunter" || str=="the hunter") {
    write("The ultimate reason for living is for the thrill of the hunt,\n"+
          "to test your mettle against another living creature, better the\n"+
          "hunter than the hunted.\n");
    return 1;
  }
  if(str=="maiden" || str=="the maiden") {
    write("Beauty takes many forms, whether in the smile of a lover's lips\n"+
          "or the morning dew on a spider's web.  Surround your life with\n"+
          "beauty and your life will be a happy one.\n");
    return 1;
  }
  if(str=="stranger" || str=="the stranger") {
    write("The others seek meaning, but what is meaning but a random\n"+
          "fluctuation that reflects back upon itself?  'Truth' and 'good'\n"+
          "are meaningless concepts.  Watch the chaos and order twist\n"+
          "and turn back in on itself.  Watch the ripples in the pond as\n"+
          "they crest and fall.\n");
    return 1;
  }
  if(str=="guardian" || str=="the guardian") {
    write("The true meaning of life may be creation, or beauty, or inner\n"+
          "peace, but those meanings cannot be realized while the forces\n"+
          "of chaos and destruction roam the planes.  The people must be\n"+
          "protected.\n");
    return 1;
  }
  if(str=="trickster" || str=="the trickster") {
    write("Life was a joke that got out of hand.  At first it had only one\n"+
          "punchline, but now it has grown and spread across the cosmos and\n"+
          "until the joke has become tired and worn and nobody laughs anymore.\n");
    return 1;
  }
  notify_fail("That god is not represented here.\n");
  return 0;
}


int cmd_donate(string str) {
  object blessing;
  object sac;
  int donation;
  if(!str) {
    notify_fail("Donate what?\n");
    return 0;
  }
  if(sscanf(str,"%d",donation)!=1) {
    sac=present(str,TP);
    if(!sac) {
      notify_fail("Donate what?\n");
      return 0;
    }
    if((int)sac->drop()) {
      notify_fail("Donate what?\n");
      return 0;
    }
    donation=(int)sac->query_value();
    if(!donation) {
      write("The gods would not want that.\n");
      return 1;
    }
    if(donation > 1000+random(250))
      donation=1000;
    write("You donate "+(string)sac->short()+" to the seven gods.\n");
    say(TPN+" donates "+(string)sac->short()+" to the seven gods.\n");
    destruct(sac);
    this_player()->recalc_carry();
  }
  else {
    if((int)this_player()->query_money() < donation) {
      write("You don't have that much money.\n");
      return 1;
    }
    write("You donate "+str+" coins to the Seven Gods.\n");
    this_player()->add_money(-donation);
  }
  donation=(int)this_player()->query_attrib("pie") * donation / 20;
  blessing=present("gods_blessing",this_player());
  if(!blessing) {
    blessing=clone_object(HEAL_PATH+"blessing.c");
    move_object(blessing,this_player());
  }
  blessing->add_blessing(donation/DIV);  

  if(donation >= 10000)
    write("You hear the angels singing from on high.\n");
  else if(donation >= 5000)
    write("You feel blessed.\n");
  else if(donation >= 2500)
    write("You sense the approval of the gods.\n");
  else if(donation >= 1000)
    write("You sense that you've attracted the gods' attention.\n");
  else
    write("Nothing happens.\n");
  return 1;
}

