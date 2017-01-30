/* 11/15/05 Earwax: moved the if(arg) return; line to above the staff cloning */
#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";

reset(arg) {
  object staff;
  ::reset(arg);
  if(arg) return;
  staff=clone_object("obj/weapon");
  staff->set_name("staff");
  staff->set_short("Teacher's Staff");
  staff->set_long(
"A tall ornamental staff once owned by the storyteller of the\n"+
"jungle village.  Two lions are carved into the staff's head.\n"
  );
  staff->set_type("staff");
  staff->set_class(6);
  staff->set_weight(1);
  staff->set_value(150);
  move_object(staff,this_object());
  set_name("storyteller");
  set_short("Storyteller");
  set_long(
"     The Storyteller is the village's oral historian and\n"+
"teacher.  He is a tanned old greybeard carrying a staff\n"+
"and wearing a long robe.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(4);
  set_wc(7);
  set_ac(5);
  set_hp(65);
  set_al(50);
  set_chat_chance(15);
  load_chat(
"Storyteller says: Our village has come upon sad times.\n"
  );
  load_chat(
"\nStoryteller says: Once, we ruled this island.  Now, none dare\n"+
  "                  enter the jungle.\n"
  );
  load_chat(
"\nStoryteller says: Takaya and her sisters have brought great sorrow\n"+
  "                  to this island.\n"
  );
}

init() {
  ::init();
  add_action("ask","ask");
}
int ask(string str) {
  if(!str) {
    write("Ask about what?\n");
    return 1;
  }
  if(str=="about quest"||str=="help"||str=="about help"||str=="about ngana"||str=="storyteller") {
    write(
"The Storyteller says: Five years ago, our people were happy and\n"+
"  prosperous.  Now, our people are sad, and fear to tread far\n"+
"  from our village.  Once, we had a strong and brave chief man\n"+
"  and his son to lead us.  But one day, Prince Ngana, the chief\n"+
"  man's son, set out into the heart of the jungle to slay the\n"+
"  wicked hags who live in the ruins of our people's ancestral\n"+
"  home and bring disaster on any who stray too far into the jungle.\n"+
"  But alas, the great witch Takaya, leader of their coven, cast a\n"+
"  curse upon Ngana, so that he would sleep in the heart of the\n"+
"  jungle until he is awakened by a great adventurer.\n"
    );
    call_out("script1",1,this_player());
    return 1;
  }
  if(str=="about chief"||str=="about chief man") {
    write(
"The Storyteller says: Our Chief Man was once among the greatest\n"+
"  leaders this village has ever seen.  But after Takaya took his\n"+
"  son from him, he became stooped and bent before our eyes.  His\n"+
"  hair turned grey and his vitality left him.  He is still just\n"+
"  as wise, but he no longer has the strength to lead us.\n"
    );
    return 1;
  }
  if(str=="about doctor"||str=="about witch doctor") {
    write(
"The Storyteller says: Our current Witch Doctor is a fool and a\n"+
"  charlatan.  He always runs around shaking his rattle at people\n"+
"  and going, 'Hoo-ha!'.  It's terribly annoying.  Still...I bet\n"+
"  he's the most content man in the village.\n"
    );
    return 1;
  }
  if(str=="about talker"||str=="about bird talker"||str=="about birdtalker") {
    write(
"The Storyteller says: The Bird talkers of our village speak to\n"+
"  the birds that naturally gravitate to them.  Through our bird\n"+
"  talkers, we learn much that goes on in the jungle.  You should\n"+
"  go listen to our current Bird talker.  I think she's quite mad\n"+
"  but the whispers she hears could be valuable to your quest.\n"
    );
    return 1;
  }
  if(str=="about hags"||
     str=="about witches"||
     str=="about takaya"||
     str=="about sisters") {
    write(
"The Storyteller says: The hags of the jungle have terrorized our\n"+
"  people for generations.  They cursed our Prince Ngana, and some\n"+
"  of our oldest tales tell of their part in the catastrophe that\n"+
"  drove us from our ancestral home in the heart of the jungle.\n"+
"  They have strange powers, to summon hideous creatures such as\n"+
"  the skybeast, and the eye that can see into your soul.  They\n"+
"  use these creatures to defend themselves and save their curses\n"+
"  for special occasions.\n"
    );
    return 1;
  }
  if(str=="about maria"||str=="about lady maria") {
    write(
"The Storyteller says: Lady Maria is the betrothed of Prince Ngana.\n"+
"  I think it is she more than any other who has suffered from his\n"+
"  disappearance.  She used to dream about crossing the jungle and\n"+
"  waking him, but sadly, she isn't the fighting type.  I think she\n"+
"  had a few ideas about defeating the skybeast.  You might want to\n"+
"  ask her about them.\n"
    );
    return 1;
  }
  if(str=="about pirates") {
    write(
"The Storyteller says: The pirates have raided our village several\n"+
"  times in the last four years, stealing food, women, and the few\n"+
"  precious riches that we have.  Thus far we have managed to drive\n"+
"  them off our island, but I fear that we will not be able to do it\n"+
"  for much longer.\n");
    return 1;
  }
  write("Ask about what?\n");
  return 1;
}
void script1(object ob) {
  if(present(ob)) tell_object(ob,
"The Storyteller says:  I have a feeling YOU are that adventurer.  Feel\n"+
"  free to ask me about anything else.  Good luck in your quest.\n"
  );
}
