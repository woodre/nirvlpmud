#include "/players/francesco/univ/ansi.h"
inherit "obj/monster";
int x, play;
   object gold;
reset(arg){
   ::reset(arg);
   set_name("narrator");
   set_race("human");
   set_alias("narrator");
      set_short("The Narrator");
     set_long("The Narrator is an old man, with glasses and a notebook on his\n"+
              "hand.  He looks very wise and you might 'ask' him his thoughts.\n"+
              "Once upon a time he also used to 'trade' any item.\n");
   set_level(10);
   set_hp(150);
   set_al(0);
   set_wc(14);
   set_ac(8);
}


init() {
   ::init();
   add_action("ask","ask");
}

ask(str) {
   if(play) { write("Shhhhhh, he is already narrating...\n"); return 1; }
   if(!str) {write("Ask whom?\n"); return 1;}
   if (str!="narrator") {write("Ask whom?\n"); return 1;}
   tell_room(environment(this_player()),HIR+"The narrator clears his throat."+NORM+"\n");
   play = 1; call_out("narrate",3);
   return 1; }

narrate(){
   narrate_it();
   x += 1;
   if(x<67) call_out("narrate",4);
   else { play = 0; x = 0; }
   return 1; }

narrate_it() {
   string lyric;
   switch(x) {
      case 0: lyric = "The remorseless drought had lasted now for ten million years,";break;
      case 1: lyric = "and would not end for another million. The reign of the terrible";break;
      case 2: lyric = "lizards had long since passed, but here on the continent";break;
      case 3: lyric = "which would one day be known as Africa, the battle for survival";break;
      case 4: lyric = "had reached a new climax of ferocity, and the victory was not";break;
      case 5: lyric = "yet in sight. In this dry and barren land, only the small or";break;
      case 6: lyric = "the swift or the fierce could flourish, or even hope to exist";break;
      case 7: lyric = "anymore. ";break;
      case 8: lyric = "The man-apes of the field had none of these attributes, and";break;
      case 9: lyric = "they were on the long, pathetic road to racial extinction.";break;
      case 10: lyric = "About twenty of them occupied a group of caves overlooking";break;
      case 11: lyric = "a small, parched valley, divided by a sluggish, brown stream.";break;
      case 12: lyric = "The tribe had always been hungry, and now it was starving.";break;
      case 13: lyric = "As the first dim glow of dawn creeps into the cave, Moonwatcher";break;
      case 14: lyric = "discovered that his father has died during the night. He did not";break;
      case 15: lyric = "know the Old One was his father, for such a relationship was";break;
      case 16: lyric = "beyond his understanding. but as he stood looking down at the";break;
      case 17: lyric = "emaciated body he felt something, something akin to sadness.";break;
      case 18: lyric = "Then he carried his dead father out of the cave, and left him";break;
      case 19: lyric = "for the hyenas.";break;
      case 20: lyric = "Dozing fitfully and weakened by his stuggle, Moonwatcher was";break;
      case 21: lyric = "startled by a sound.";break;
      case 22: lyric = "He sat up in the fetid darkness of the cave, straining his";break;
      case 23: lyric = "senses out into the night, and fear creeps slowly into his soul.";break;
      case 24: lyric = "Never in his life - already twice as long as most members of";break;
      case 25: lyric = "his species could expect - has he heard a sound like this. The";break;
      case 26: lyric = "great cats approached in silence, and the only thing that";break;
      case 27: lyric = "betrayed them was a rare slide of earth, or the occasional";break;
      case 28: lyric = "cracking of a twig. Yet this is a continuing crunching noise";break;
      case 29: lyric = "that grows steadily louder. It seemed that some enormous";break;
      case 30: lyric = "beast was moving through the night, making no attempt at";break;
      case 31: lyric = "concealment, and ignoring all obstacles.";break;
      case 32: lyric = "And then there came a sound which Moonwatcher could not";break;
      case 33: lyric = "possibly have identified, for it had never been heard before";break;
      case 34: lyric = "in the history of this planet.";break;
      case 35: lyric = "Moonwatcher comes face to face with the Monolith when he";break;
      case 36: lyric = "leaded the tribe down to the river in the first light of morning.";break;
      case 37: lyric = "He had almost forgotten the terror of the night, because nothing";break;
      case 38: lyric = "had happened after that initial noise, so he did not even";break;
      case 39: lyric = "associate this strange thing with danger or with fear. ";break;
      case 40: lyric = "There was nothing in the least alarming about it.";break;
      case 41: lyric = "It was a cube about fifteen feet on a side, and it was made of";break;
      case 42: lyric = "some completely transparent material. Indeed, it is not easy";break;
      case 43: lyric = "to see except when a power source of light glints on its edges.";break;
      case 44: lyric = "There are no natural objects to which Moonwatcher could";break;
      case 45: lyric = "compare this apparition. Though he was wisely cautious";break;
      case 46: lyric = "of most new things, he did not hesitate to walk up to it.";break;
      case 47: lyric = "As nothing happened, he put out his hand, and felt a warm,";break;
      case 48: lyric = "hard surface.";break;
      case 49: lyric = "After several minutes of intense thought, he arrived at a";break;
      case 50: lyric = "brilliant explanation. 'It is a rock, of course, and it";break;
      case 51: lyric = "must have grown during the night. There are many plants";break;
      case 52: lyric = "that do this - white, pulpy things shaped like pebbles, that";break;
      case 53: lyric = "seem to shoot up in the hours of darkness.'  It is true that";break;
      case 54: lyric = "they are small and round, whereas this was large and square,";break;
      case 55: lyric = "but greater and later philosophers than Moonwatcher would be";break;
      case 56: lyric = "prepared to overlook equally striking exceptions to their laws.";break;
      case 57: lyric = "This really superb piece of abstract thinking lead Moonwatcher";break;
      case 58: lyric = "to a deduction which he immediately put to the test. 'The white,";break;
      case 59: lyric = "round pebble-plants are very tasty (though there were a few";break;
      case 60: lyric = "that made one violently sick) perhaps this square one...?'";break;
      case 61: lyric = "A few licks and attempted nibbles quickly disillusioned him.";break;
      case 62: lyric = "There was no nourishment here. So like a sensible hominid, he";break;
      case 63: lyric = "continued on his way to the river and forgot all about ";break;
      case 64: lyric = "the Monolith.";break;
      case 65: lyric = " ";break;
      case 66: lyric = HIR+"The Narrator closes his eyes and returns to his deep thoughts.";break;}
      tell_room(environment(this_player()),HIW+lyric+NORM+"\n");
   return 1; }


