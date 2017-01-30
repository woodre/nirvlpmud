inherit "obj/monster";

object weapon,treasure;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Gheron");
  set_race("gheron");
  set_alias("gheron");
  set_short("A Gheron");
  set_long(
	"The Gheron is a very rare and hideously evil beast.  Gheron's are\n"+
	"energy-vortices, which survive by sucking Magic from the world.\n"+
	"Thier short stumpy bodies are covered with tiny spikes which they\n"+
	"coat with thier venomous saliva.\n");
  set_level(15);
  set_hp(225);
  set_al(600);
  set_ac(50);
  set_wc(50);
  set_chance(25);
  set_spell_dam(30);
  set_spell_mess1("Gheron's eyes glow red as he hacks wildly");
  set_spell_mess2("Gheron slices deep into your body!\n"+
  "You his poisonous saliva burn inside your body.");
  set_a_chat_chance(30);
  load_a_chat("Gheron licks his sword and grins evily.\n");
  load_a_chat("Saliva drips from Gheron and burn holes through the floor.\n");
  load_a_chat("Gheron hisses at you.\n");
  load_a_chat("Gheron's red eyes burn brightly as he hacks at you.\n");
}
