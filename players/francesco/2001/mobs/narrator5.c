#include "/players/francesco/univ/ansi.h"
inherit "obj/monster";
int x, play;
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
   if(x<14) call_out("narrate",17);
   else { play = 0; x = 0; }
   return 1; }

narrate_it() {
   string lyric1,lyric2,lyric3,lyric4,lyric5;
   switch(x) {         
      case 0: lyric1 = "\n   For two million years, it had circled Saturn, awaiting a moment\n"+
                       "of destiny  that might never come.  In its making, the moon had\n"+
                       "been shattered and around the central world,  the debris of its\n";
              lyric2 = "creation orbited yet - the glory and the enigma of the solar system.\n"+
                       "Now, the long wait was ending.\n";
              lyric3 = " ";
              lyric4 = "\n";break;
      case 1: lyric1 = "   On yet another world intelligence had been born and was\n"+
                       "escaping from its planetary cradle. An ancient experiment\n"+
                       "was about to reach its climax.\n";
              lyric2 = " ";
              lyric3 = " ";
              lyric4 = "\n";break;
      case 2: lyric1 = "   Those who had begun the experiment so long ago had not been men.\n"+
                       "But when they looked out across the deeps of space, they felt\n"+
                       "awe and wonder - and loneliness.  In their explorations, they\n";
              lyric2 = "encountered life in many forms,  and watched on a thousand worlds\n"+
                       "the workings of evolution.  They saw how often the first faint\n"+
                       "sparks of intelligence flickered  and died in the cosmic night.\n";
              lyric3 = "And because, in all the galaxy,  they had found nothing more\n"+
                       "precious than Mind, they encouraged its dawning everywhere.\n";
              lyric4 = "\n";break;
      case 3: lyric1 = "   The great Dinosaurs had long since perished when their ships\n"+
                       "entered the solar system, after a voyage that had already lasted\n"+
                       "thousands of years.  They swept past the frozen outer planets, \n";
              lyric2 = "paused briefly above the deserts of dying Mars and presently \n"+
                       "looked down on Earth.\n";
              lyric3 = " ";
              lyric4 = "\n";break;
      case 4: lyric1 = "   For years they studied, collected and catalogued.  When\n"+
                       "they had learned all they could, they began to modify.  They\n"+
                       "tinkered with the destiny of many species on the land and in\n";
              lyric2 = "the ocean, but which of their experiments would succeed\n"+
                       "they could not know for at least a million years.\n";
              lyric3 = " ";
              lyric4 = "\n";break;
      case 5: lyric1 = "   They were patient, but they were not yet immortal. There was\n"+
                       "much to do in this Universe of a hundred billion stars. So they\n"+
                       "set forth once more across the abyss, knowing that they would\n";
              lyric2 = "never come this way again.  Nor was there any need.  Their \n"+
                       "wonderful machines could be trusted to do the rest.\n";
              lyric3 = " ";
              lyric4 = "\n";break;
      case 6: lyric1 = "   On Earth, the glaciers came and went, while above them, the\n"+
                       "changeless Moon still carried its secret.  With a yet slower rhythm\n"+
                       "than the Polar ice, the tide of civilization ebbed and flowed across\n";
              lyric2 = "the galaxy.  Strange and beautiful and terrible empires rose and fell\n"+
                       "and passed on their knowledge to their successors.  Earth was not \n"+
                       "forgotten, but it was one of a million silent worlds, a few of which\n";
              lyric3 = "would ever speak.\n";
              lyric4 = "\n";break;
      case 7: lyric1 = "   Then the first explorers of Earth, recognising the limitations\n"+
                       "of their minds and bodies, passed on their knowledge to the great\n"+
                       "machines they had created, and who now transcended them in every way.\n";
              lyric2 = "For a few thousand years, they shared their Universe with their\n"+
                       "machine children; then, realizing that it was folly to linger when\n"+
                       "their task was done, they passed into history without regret.\n";
              lyric3 = "Not one of them ever looked through his own eyes upon the planet\n"+
                       "Earth again.\n";
              lyric4 = "\n";break;
      case 8: lyric1 = "   But even the age of the Machine Entities passed swiftly. In their\n"+
                       "ceaseless experimenting, they had learned to store knowledge\n"+
                       "in the structure of space itself, and to preserve their thoughts\n";
              lyric2 = "for eternity in frozen lattices of light. They could become\n"+
                       "creatures of radiation, free at last from the tyranny of matter.\n"+
                       "Now, they were Lords of the galaxy, and beyond the reach\n";
              lyric3 = "of time.  They could rove at will among the stars, and sink like \n"+
                       "a subtle mist through the very interstices of space.  But despite \n"+
                       "their God-like powers, they still watched over the experiments their \n";
              lyric4 = "ancestors had started so many generations.\n\n";break;
      case 9: lyric1 = "   The companion of Saturn knew nothing of this, as it orbited in its\n"+
                       "no man's land between Mimas and the outer edge of rings.  It had only\n"+
                       "to remember and to wait, and to look forever Sunward with its strange\n";
              lyric2 = "senses.  For many weeks, it had watched the approaching ship. Its long-\n"+
                       "dead makers had prepared it for many things and this was one of them\n"+
                       "And it recognised what was climbing starward from the Sun.  If it had \n";
              lyric3 = "been alive, it would have felt excitement, but such an emotion was \n"+
                       "irrelevant to its great powers.  Even if the ship had passed it by, it\n"+
                       "would not have known the slightest trace of disappointment.  It had \n";
              lyric4 = "waited four million years; it was prepared to wait for eternity.\n\n";break;
      case 10: lyric1 = "   Presently, it felt the gentle touch of radiations, trying  to probe\n"+
                        "its secrets.  Now, the ship was in orbit and it began to speak, with \n"+
                        "prime numbers from one to eleven, over and over again.  Soon, these \n";
               lyric2 = "gave way to more complex signals at many frequencies, ultra-violet, \n"+
                        "infra-red, X-rays.  The machine made no reply. It had nothing to say.\n"+
                        "Then it saw the first robot probe, which descended and hovered above \n";
               lyric3 = "the chasm. Then, it dropped into darkness.\n";
              lyric4 = "\n";break;
      case 11: lyric1 = "   The great machine knew that this tiny scout was reporting back to\n"+
                       "its parent. But it was too simple, too primative a device to detect the \n"+
                       "forces that were gathering round it now.  Then the pod came, carrying \n";
               lyric2 ="life the great machine searched its memories.  The logic circuits made \n"+
                       "their decision when the pod had fallen beyond the last faint glow of the \n"+
                       "reflected Saturnian light.\n";
              lyric3 = " ";
              lyric4 = "\n";break;
      case 12: lyric1 = "   In a moment of time, too short to be measured, space turned and\n"+
                       "twisted upon itself.\n";
              lyric2 = " ";
              lyric3 = " ";
              lyric4 = "\n";break;
      case 13: lyric1 = HIR+"The Narrator closes his eyes and returns to his deep thoughts.\n";
              lyric2 = "";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;}

      tell_room(environment(this_player()),HIW+lyric1+NORM);
      tell_room(environment(this_player()),HIW+lyric2+NORM);
      tell_room(environment(this_player()),HIW+lyric3+NORM);
      tell_room(environment(this_player()),HIW+lyric4+NORM);
   return 1; }


