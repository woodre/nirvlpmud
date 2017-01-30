#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
int changed;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("figure");
set_alt_name("archangel");
set_alias("fire");
set_race("unknown");
set_short("A dark figure");
set_long(
  "   Standing before you is a tall figure. Its dark frame \n"+
  "is shrouded in a long coat which covers it from the\n"+
  "shoulders down to its booted feet.  Its head is covered\n"+
  "with some sort of black cloth, with no visible eyeholes.\n"+
  "It stands perfectly still\n");

set_level(15);
set_hp(300);
set_al(-random(1000));
set_wc(25);
set_ac(8);
set_heart_beat(2);
set_aggressive(0);
set_dead_ob(this_object());
set_changed(0);
set_chat_chance(5);
  load_chat("You feel heat eminating from somewhere in the room.\n");
  load_chat("The figure stands looking at you, its unseen eyes studying you.\n");
set_a_chat_chance(15);
  load_a_chat("Archangels eyes "+RED+"BLAZE"+NORM+" with rage.\n");
  load_a_chat("Archangel snarls with anger as his Spear strikes at you!\n");
  load_a_chat("Archangels fiery wings rake the air with searing heat.\n");

set_chance(5);
set_spell_dam(random(16));

set_spell_mess1(
  "Archangels wings "+BOLD+""+RED+"----SLICE----"+NORM+" at his foe!\n");
set_spell_mess2(
  "You scream in pain as Archangels fiery wings "+BOLD+""+RED+"----SLICE----"+NORM+""+
  " into you!\n");
}

set_changed(int n){ changed = n; }
query_changed(){ return changed; }

heart_beat() {
	object attacked;
	::heart_beat();
	attacked=(this_object()->query_attack());
  if(attacked && query_changed() == 0){
  	tell_room(environment(this_object()),
  	"\n\n\n"+
  	"\n\n\n\n\n\n\n"+
  	"          The dark figures clothes shread in a "+BOLD+""+RED+"FIERY"+NORM+""+
      " Explosion!\n\n\n\n\n\n\n"+
  	"                          Now standing before you is an....\n\n\n"+
      " "+BOLD+""+RED+""+
      "                                   Archangel of Fire."+NORM+"\n");
  	this_object()->set_short("an Archangel of "+BOLD+""+RED+"Fire"+NORM+"");
  	this_object()->set_long(
  	"Quite different that its original form, this creature now burns\n"+
  	"bright with a flaming aura. With the cloth and coat burned away\n"+
  	"you now see the true features of it. Its head is covered with short\n"+
  	"white hair, its eyes nearly the same color. It's skin is charcoal\n"+
  	"black and its torso, arms, and legs are covered with redish tinged\n"+
  	"armor. A flaming spear is held in his hands, its long shaft tipped\n"+
  	"with a razor sharp point.  Huge flaming wings spread out from its\n"+
  	"back, sending out flaming waves of heat. You detect no humanity\n"+
  	"eminating from this thing of evil.\n");
  	this_object()->set_race("archangel"); 
	this_object()->set_changed(1);
      this_object()->set_name("archangel");
	}
}
monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  tell_room(environment(this_object()),
  "As the Archangel dies you see his flaming Spear fall from his limp hands, it\n"+
  "clatters to the ground loudly.\n\n\n"+
  "\n\nA searing heat encompasses the corpse, burning it into ashes.\n");	
  move_object(clone_object("/players/maledicta/ruins/weapons/flaming_spear.c"),
      environment(this_object()));
 if(corpse)
    destruct(corpse);
return 1; }
