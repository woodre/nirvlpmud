#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
int changed;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("figure");
set_alt_name("archangel");
set_alias("ice");
set_race("unknown");
set_short("A dark figure");
set_long(
  "  Before you is a figure dressed in Blue tinted robes.  Its hands, feet,\n"+
  "and face are completely covered by the drooping robe, allowing no hints\n"+
  "too what might lay beneath. You feel a cold rush of air and a chill that\n"+
  "permeates the air.\n");

set_level(15);
set_hp(300);
set_al(-random(1000));
set_wc(22);
set_ac(12);
set_heart_beat(2);
set_aggressive(0);
set_dead_ob(this_object());
set_changed(0);
set_chat_chance(5);
  load_chat("You feel a cold draft rush at you from somewhere in the room.\n");
  load_chat("The figure stands looking at you, its unseen eyes studying you.\n");
set_a_chat_chance(15);
  load_a_chat("Archangels eyes "+HIB+"GLOW "+NORM+"with a cold rage.\n");
  load_a_chat("Archangel snarls with anger as his Staff strikes at you!\n");
  load_a_chat("Archangels Crystalline form deflects some of the damage.\n");

set_chance(5);
set_spell_dam(random(10));

set_spell_mess1(
  "Archangels eyes fire twin rays of pure "+HIB+"ICE"+NORM+" at his foe!\n");
set_spell_mess2(
  "You scream in pain as Archangels eyes fire twin rays of"+HIB+" ICE"+NORM+""+
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
  	"\n\n\n\n   The dark figures clothes shread as "+HIB+"Crystalline Armor"+NORM+""+
      " grows from beneath!\n\n\n\n"+
  	"          Now standing before you is an"+
      " "+HIB+"Archangel of Ice."+NORM+"\n\n\n");
  	this_object()->set_short("an Archangel of "+HIB+"Ice"+NORM+"");
  	this_object()->set_long(
  	"Now standing before you is a being of pure evil, its body\n"+
  	"protected by a shell of Crystalline Ice.  You look into its\n"+
  	"eyes and see that they are twin orbs of pure blue, leaving\n"+
  	"you with a feeling of little humanity. Wielded in its hands\n"+
  	"is a long staff, its gleaming shaft covered with a frosty\n"+
  	"coating. This creature seems nearly impenetrable in its armor.\n");
  	this_object()->set_race("archangel"); 
	this_object()->set_changed(1);
      this_object()->set_name("archangel");
	}
}
monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  tell_room(environment(this_object()),
  "As the Archangel dies you see it's armor shatter, its hand crumbling and\n"+
  "allowing the Staff to fall from its grasp. It clatters to the ground\n"+
  "with a loud clang.\n\n\n"+
  "\n\nThe body immediately melts leaving a blackened puddle of water.\n");	
  move_object(clone_object("/players/maledicta/ruins/weapons/ice_staff.c"),
      environment(this_object()));
 if(corpse)
    destruct(corpse);
return 1; }
