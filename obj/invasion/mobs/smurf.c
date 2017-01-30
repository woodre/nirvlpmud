/* 
 * Comprehensive Smurf mob monster. - Dune
 */

#include <ansi.h>

inherit "/obj/invasion/mob-monster";

int mobType; /* Memorize 'kind' of smurf' */

void reset(status x)
{
  if(x) return;
  ::reset(x);

  set_race("smurf");
  set_al(0);
  set_aggressive(1);

  mobType = random(50);
  switch(mobType)
  {
    /* continue this pattern .. */
    case 0:
      set_short("A "+HIR+"Papa"+NORM+" "+HIW+"Sm"+HIB+"urf"+NORM);
      set_name("papa smurf");
      set_alias("papa");
      set_long(
"You can recognize the village leader with his white beard and\n"+
"red clothes. Papa Smurf is no less than 542 years old - \n"+
"and no more either. He uses his wisdom to advise rather than\n"+
"tell people what to do. He�s also a pretty good alchemist.\n");
      set_level(20);
      set_hp(500);
      set_wc(30);
      set_ac(17);
      set_spell_mess1("Papa Smurf tosses a potion of dingBat at you!\n");
      set_spell_mess2("Papa Smurf splashes a potion of Smurfing on you!\n");
      set_spell_dam(60);
      set_chance(30);
      break;
    case 1:
      set_short("A "+HIY+"Smurf"+NORM+HIC+"ette"+NORM);
      set_name("smurfette");
      set_alias("smurfette");
      set_long(
"The wicked Gargamel originally created Smurfette to\n"+
"stir up trouble in the village. But Papa Smurf�s magic turned\n"+
"her into the charming little Smurf that everyone adores.\n");
      set_level(18);
      set_hp(400);
      set_wc(26);
      set_ac(15);
      break;
      set_spell_mess2("Smurfette's looks are killing you!\n");
      set_spell_dam(15);
      set_chance(60);
    case 2:
      set_short("A "+HBWHT+HIK+"Brainy"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("brainy smurf");
      set_alias("brainy");
      set_long(
"The only Smurf to take everything seriously. Brainy is a\n"+
"moralizer who believes everything Papa Smurf says is sacred.\n"+
"Everyone puts up with him, but let�s face it: he�s a bore.\n"+
"In fact, he�s a real pain in the Smurf!\n");
      set_level(19);
      set_hp(450);
      set_wc(28);
      set_ac(16);
      set_spell_mess1("Brainy Smurf annoys the very life out of you!\n");
      set_spell_dam(20);
      set_chance(40);
      break;
    case 3:
      set_short("A "+HIM+"Jokey"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("jokey smurf");
      set_alias("jokey");
      set_long(
"Jokey spends all his time concocting pranks. He builds\n"+
"gift-wrapped packages that explode in your face. He has an\n"+
"endless stream of jokes. Sometimes, he gets on everyone�s\n"+
"nerves. And once in a while, his jokes backfire on him!\n");
      set_level(18);
      set_hp(400);
      set_wc(26);
      set_ac(15);
      set_spell_mess1("Jokey Smurf throws an exploding egg at you!\n");
      set_spell_dam(40);
      set_chance(20);
      break;
    case 4:
      set_short("A "+HBWHT+HIR+"Grouchy"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("grouchy smurf");
      set_alias("grouchy");
      set_long(
"No matter what anyone says, Grouchy is against it. He grumbles\n"+
"and mumbles and always thinks negative. But underneath it all,\n"+
"he�s a softy and loves Sassette and Baby. But he�d hate it\n"+
"if people knew.\n");
      set_level(13);
      set_hp(195);
      set_wc(17);
      set_ac(10);
      break;
    case 5:
      set_short("A "+HBGRN+BLK+"Handy"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("handy smurf");
      set_alias("handy");
      set_long(
"If anything ever needs fixing, Handy is the man for the job.\n"+
"He is also a creator. The pencil behind his ear is always being\n"+
"used to sketch things like a robot, a choo-choo train or a\n"+
"machine to smurf rain.\n");
      set_level(16);
      set_hp(300);
      set_wc(22);
      set_ac(13);
      break;
    case 6:
      set_short("A "+HBCYN+HIY+"Vanity"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("vanity smurf");
      set_alias("vanity");
      set_long(
"Mirror in hand, and with a flower in his bonnet, Vanity simply\n"+
"adores himself. He thinks he is the smurfiest Smurf in the village\n"+
"and loves talking fashion with Smurfette.\n");
      set_level(15);
      set_hp(250);
      set_wc(20);
      set_ac(12);
      break;
    case 7:
      set_short("A "+HIW+"Hefty"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("hefty smurf");
      set_alias("hefty");
      set_long(
"Distinguished by a heart-shaped tattoo on his arm. Hefty is the\n"+
"strongest Smurf in the village. He exercises, he is a sportsman\n"+
"and has even organized the Olympic Smurfs. One can always depend\n"+
"on him if there is any hard work to be done. He is kind of a lout\n"+
"but everyone loves him.\n");
      set_level(17);
      set_hp(350);
      set_wc(24);
      set_ac(14);
      break;
    case 8:
      set_short("A Lazy "+HIB+"Smurf"+NORM);
      set_name("lazy smurf");
      set_alias("lazy");
      set_long(
"Lazy only thinks of sleeping. When he painfully wakes in the\n"+
"morning, he waits for the evening to go back to sleep. He loves\n"+
"his pillow. He isn�t idle, but any little job tires him. Lazy�s\n"+
"laziness doesn�t bother the other Smurfs except Brainy who�s\n"+
"always after him, admonishing him each time he dozes off.\n");
      set_level(9);
      set_hp(135);
      set_wc(13);
      set_ac(7);
      break;
    case 9:
      set_short("A "+HIG+"Greedy"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("greedy smurf");
      set_alias("greedy");
      set_long(
"Eat, eat, eat. Everything is tasty: sarsaparilla, soup, cheese,\n"+
"fruit. But what he really prefers are the goodies he often steals\n"+
"from Cook Smurf. His motto:\n"+
"'One should live to smurf, and not smurf to live'\n");
      set_level(12);
      set_hp(180);
      set_wc(16);
      set_ac(9);
      break;
    case 10:
      set_short("A "+HIC+"Harmony"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("harmony smurf");
      set_alias("harmony");
      set_long(
"Harmony has the soul of a great musician, but not the talent.\n"+
"He plays in the philharmonic smurfestra. But the only sounds that\n"+
"come from his cornet are Kwaaak and Pweeet. Smurfs who want to\n"+
"nap need a stock of earplugs.\n");
      set_level(8);
      set_hp(120);
      set_wc(12);
      set_ac(7);
      break;
    case 11:
      set_short("A "+HIW+"C"+NORM+HIR+"oo"+NORM+HIW+"k"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("cook smurf");
      set_alias("cook");
      set_long(
"You can�t miss him with his tall white hat and apron. And his\n"+
"house is always the source of the delicious smell of hot bread,\n"+
"muffins, pies and sweets. Needles to say, he is a 'cordon bleu'.\n");
      set_level(9);
      set_hp(135);
      set_wc(13);
      set_ac(7);
      break;
    case 12:
      set_short("A "+GRN+"Farm"+NORM+"er"+HIY+NORM+" "+HIB+"Smurf"+NORM);
      set_name("farmer smurf");
      set_alias("farmer");
      set_long(
"Farmer is the opposite of Poet; he is a Smurf of the earth.\n"+
"He�s never satisfied. When he needs a little rain to help his\n"+
"salads grow, the sun shines, and vice versa. His speech is rough\n"+
"but he�s the best at sorting out fertilizers and growing the\n"+
"tastiest vegetables and fruits in the world.\n");
      set_level(7);
      set_hp(105);
      set_wc(11);
      set_ac(6);
      break;
    case 13:
      set_short("A "+HIW+"Po"+NORM+HIM+"et"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("poet smurf");
      set_alias("poet");
      set_long(
"With a quill in one hand and a parchment in the other, Poet spends\n"+
"his days scribbling prose, quatrains and essays. He daydreams\n"+
"so much he doesn�t realise the danger he gets himself into.\n"+
"His latest tale is called: 'Smurfy Dumpty sat on a smurf'.\n");
      set_level(8);
      set_hp(120);
      set_wc(12);
      set_ac(7);
      break;
    case 14:
      set_short("An "+HIR+"Enamoured"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("enamoured smurf");
      set_alias("enamoured");
      set_long(
"Since Smurfette�s arrival, all the Smurfs are in love. But none\n"+
"more than this chap. He dreams about her, carves her name in\n"+
"trees and pulls the petals off daisies, reciting\n"+
"'She loves me, she loves me not...'. When she loves him not,\n"+
"he cries all night.\n");
      set_level(7);
      set_hp(105);
      set_wc(11);
      set_ac(6);
      break;
    case 15:
      set_short("A "+HIW+"P"+NORM+HIR+"a"+NORM+HIY+"i"+NORM+HIB+"n"+NORM+HIM+"t"+NORM+HIY+"er"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("painter smurf");
      set_alias("painter");
      set_long(
"Painter lives only for his craft. Canvas, brushes and colour\n"+
"are the joys of his life. He paints portraits and landscapes\n"+
"dressed in an apron with an oversized bow tie.\n"+
"Smurfette is his favourite model.\n");
      set_level(6);
      set_hp(90);
      set_wc(10);
      set_ac(5);
      break;
    case 16:
      set_short("A "+HBWHT+HIB+"Baby"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("baby smurf");
      set_alias("baby");
      set_long(
"On a blue, moonlit night, Baby Smurf was brought to the village\n"+
"by a stork. But where did he come from? Nobody knows,\n"+
"but everyone immediately adopted him - even though he breaks the\n"+
"routine of their lives.\n");
      set_level(2);
      set_hp(30);
      set_wc(6);
      set_ac(3);
      break;
    case 17:
      set_short("A "+HIY+"Grand"+NORM+HIR+"pa"+NORM+" "+HIB+"Smurf"+NORM);
      set_name("grandpa smurf");
      set_alias("grandpa");
      set_long(
"Back in the village after a five hundred-year leave, Grandpa Smurf\n"+
"is the oldest of all Smurfs. He has not taken Papa�s leading role\n"+
"but his energy and enthusiasm are impressive. Besides wearing a\n"+
"bright yellow cap and pants, Grandpa always wears pince-nez glasses.\n"+
"He�s an avid storyteller and loves to show off some of the souvenirs\n"+
"he has collected during his travels.\n");
      set_level(4);
      set_hp(60);
      set_wc(8);
      set_ac(4);
      break;
    case 18..33:
      set_short("A "+HIB+"Smurf"+NORM);
      set_name("smurf");
      set_alias("smurf");
      set_long(
"Far, very far from here, in a little village full of\n"+
"mushroom-shaped houses live the Smurfs. The little characters are\n"+
"three apples high, have blue skin and are dressed in white trousers\n"+
"and a cap. Yet they are a happy, easy-going bunch -\n"+
"give or take one or two.\n");
      set_level(1);
      set_hp(15);
      set_wc(5);
      set_ac(3);
      break;
    case 34..44:
      set_short("A "+HIB+"Smurf"+NORM);
      set_name("smurf");
      set_alias("smurf");
      set_long(
"Far, very far from here, in a little village full of\n"+
"mushroom-shaped houses live the Smurfs. The little characters are\n"+
"three apples high, have blue skin and are dressed in white trousers\n"+
"and a cap. Yet they are a happy, easy-going bunch -\n"+
"give or take one or two.\n");
      set_level(3);
      set_hp(45);
      set_wc(7);
      set_ac(4);
      break;
    case 45..50:
      set_short("A "+HIB+"Smurf"+NORM);
      set_name("smurf");
      set_alias("smurf");
      set_long(
"Far, very far from here, in a little village full of mushroom\n"+
"houses live the Smurfs. The little characters are three apples\n"+
"apples high, have blue skin and are dressed in white trousers\n"+
"and a cap. Yet they are a happy, easy-going bunch -\n"+
"give or take one or two.\n");
      set_level(5);
      set_hp(75);
      set_wc(9);
      set_ac(5);
      break;
  }
  set_aggressive(1);

}
