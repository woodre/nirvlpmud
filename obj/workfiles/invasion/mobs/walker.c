#include <ansi.h>

inherit "/obj/invasion/mob-monster";

/******************************************************************************
 * Program: walker.c
 * Path: /obj/invasion/mobs/
 * Type: Mob
 * Created: Feb 07, 2014 by Dragnar
 *
 * Purpose: Walker mob used for monster invasion.
 * 
 * History:
 *          02/07/2014 - Dragnar
 *            Created
 ******************************************************************************/

int mobType; /* Memorize 'kind' of walker' */


add_walker_id( string id ) {
  multipleIds += ({ id });
}

void reset(status x)
{
  if(x) return;
  ::reset(x);

  set_race("zombie");
  set_al(0);
  set_aggressive(1);
  
  SetMultipleIds( ({ "walker", "undead", "zombie", "biter", "geek", "dead", "walking dead" }) );
  
  move_object(clone_object("/players/dragnar/WalkingDead/obj/kill_check"), this_object());
  set_dead_ob(this_object());
  
  msgin = "shambles in";
  msgout = "stumbles";
  message_hit=({
        "eviscerates"," with a vicious slash",
        "bites"," with a sound of tearing flesh",
        "gouges"," very deeply",
        "gouges"," deeply",
        "gashes","",
        "wounds","",
        "scratches",""
  });
  
  add_spell("groan",
    "#MN# emits a loud $Y$GGGGGGGRRRRRRRRRRROOOOOOOOOAAAAANNNN$N$ that makes your flesh crawl!\n",
    "#MN# emits a loud $Y$GGGGGGGRRRRRRRRRRROOOOOOOOOAAAAANNNN$N$ that makes #TN#'s flesh crawl!\n",
    25,30,"physical",0 );
    
  add_spell("bite",
    "\n#MN# lunges suddenly and $R$ B I T E S$N$ you!\n\n",
    "#MN# lunges suddenly and $R$B I T E S$N$ #TN#!\n",
    20,random(25)+10,"physical",0 );
    
  add_spell("tackle",
    "#MN# jumps at you and $HK$tackles$N$ you to the ground!\n",
    "#MN# jumps at #TN# and $HK$tackles$N$ them to the ground!\n",
    15,random(20)+15,"physical",0 );

  mobType = random(50);
  switch(mobType)
  {
    /* continue this pattern .. */
    case 0:
      set_short("A Pair of "+HIBLK+"Walking Dead"+NORM);
      set_name("pair of walkers");
      add_walker_id( "pair" );
      set_long(
"Two Walking Dead in tattered and beat up old clothes shuffles\n\
around. Their eyes are glazed over and almost "+GRY+"white"+NORM+" like and\n\
the flesh seems to be starting to peel from the bones. A foul stench\n\
pours from the rotting flesh. Blood flows from the mouth of the \n\
zombies as they stalk their next meal.\n");
      set_level(15);
      break;
    case 1:
      set_short("A Trio of "+HIBLK+"Walking Dead"+NORM);
      set_name("trio of walkers");
      add_walker_id( "trio" );
      set_long(
"A mob of three Walking Dead Zombies that are looking for their next\n\
meal of human flesh. They will stop at nothing to get what they want.\n\
The smell coming from them is putrid and they took terrifying. One of\n\
them used to be a young teenage girl, but she looks just as vicious\n\
as the others.");
      set_level(16);
      break;
    case 2:
      set_short("A Small Group of "+HIBLK+"Walking Dead"+NORM);
      set_name("small group of walkers");
      add_walker_id( "group" );
      set_long(
"A mob of four Walking Dead in tattered and beat up old clothes shuffles\n\
around. Their eyes are glazed over and almost "+GRY+"white"+NORM+" like and\n\
the flesh seems to be starting to peel from the bones. A foul stench\n\
pours from the rotting flesh. Blood flows from the mouth of the \n\
zombies as they stalk their next meal.");
      set_level(17);
      break;
    case 3:
      set_short("A "+HIBLK+"Large Group "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      set_name("large group of walkers");
      add_walker_id( "group" );
      set_long(
"A mob of five Walking Dead in tattered and beat up old clothes shuffles\n\
around. Their eyes are glazed over and almost "+GRY+"white"+NORM+" like and\n\
the flesh seems to be starting to peel from the bones. A foul stench\n\
pours from the rotting flesh. Blood flows from the mouth of the \n\
zombies as they stalk their next meal.");
      set_level(18);
      break;
    case 4:
      set_short("A "+RED+"Swarm "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      set_name("swarm of walkers");
      add_walker_id( "swarm" );
      set_long(
"A mob of six Walking Dead in tattered and beat up old clothes shuffles\n\
around. Their eyes are glazed over and almost "+GRY+"white"+NORM+" like and\n\
the flesh seems to be starting to peel from the bones. A foul stench\n\
pours from the rotting flesh. Blood flows from the mouth of the \n\
zombies as they stalk their next meal.\n"+
"if people knew.\n");
      set_level(19);
      break;
    case 5:
      set_short("A "+HIR+"Horde "+NORM+"of "+HIBLK+"Walking Dead"+NORM);
      set_name("horde of walkers");
      add_walker_id( "horde" );
      set_long(
"A mob of seven Walking Dead Zombies. They shuffle around looking\n\
their next meal. The stench from this group is over whelming. Every-\n\
thing about this horde is meant to cause fear in their prey. Fear\n\
causes panic and panic draws their dead milky eyes. Once they are\n\
focused on a target they will never stop until they feast.\n");
      set_level(20);
      break;
    case 6..11:
      set_short("A Walking "+HIBLK+"Dead Man"+NORM);
      set_name("walker");
      add_walker_id("man");
      add_walker_id("don");
      set_long(
"A Walking Dead Zombie who obviously used to be blue collar worker.\n\
He has on blue overalls that you would bet were used in an auto\n\
repair shop. He has a sickening bite out of his neck and his chest\n\
is covered in blood. He has a name tag on that reads: 'Don'.\n");
      set_level(8);
      break;
    case 12..16:
      set_short("A Walking "+HIBLK+"Dead Woman"+NORM);
      set_name("walker");
      add_walker_id("woman");
      set_long(
"A Walking Dead woman who has dark hair and a hideous wound that\n\
removed one of her eyes. She is casually dressed with half of her\n\
shirt ripped away. A tattoo on her chest reads: "+HIB+"'My heart will\n\
always belong to Don"+NORM+".' You wonder how that worked out for Don?\n");
      set_level(7);
      break;
    case 17..20:
      set_short("A Walking "+HIBLK+"Dead Man"+NORM);
      set_name("walker");
      add_walker_id("man");
      set_long(
"A Walking Dead who used to be a middle aged man with dark skin. He\n\
has completely lost the bottom part of his jaw, and his tongue\n\
is exposed. His missing teeth don't seem to be slowing him down\n\
at all. He slowly swings his head back and forth looking for some\n\
flesh that he can rip and tear.\n");
      set_level(7);
      break;
    case 21..25:
      set_short("A Walking "+HIBLK+"Dead Man in a Hazmat suit"+NORM);
      set_name("walker");
      add_walker_id("man");
      set_long(
"A Walking Dead who is wearing a Hazmat suit. There is a gash in the\n\
along one side which is how the man wearing it must have gotten\n\
infected. The "+HIY+"suit"+NORM+" is bright yellow except where it is stained with\n\
blood and gore.\n");
      set_level(8);
      break;
    case 26..30:
      set_short("A Walking "+HIBLK+"Dead Man in Riot Gear"+NORM);
      set_name("walker");
      add_walker_id("man");
      set_long(
"This is a fearsome Walker who is dressed in a full suit of Riot\n\
gear. He must have been a policeman before he was bitten and turned\n\
into this eater of flesh. With the riot gear he is especially\n\
dangerous. The gear does nothing to hide the rotten flesh and sunken\n\
milky white eyes.\n");
      set_level(10);
      break;
    case 31..33:
      set_short("A Walking "+HIBLK+"Dead Man"+NORM);
      set_name("walker");
      add_walker_id("man");
      set_long(
"A Walking Dead who was previously was some sort of a business man.\n\
He still wears the suit that marks who he was, although it is torn,\n\
faded, and bloody now. He longer cares about sales, he only wants a\n\
single thing: human flesh.\n");
      set_level(7);
      break;
    case 34..37:
      set_short("A Walking "+HIBLK+"Dead Grandpa"+NORM);
      set_name("walker");
      add_walker_id("grandpa");
      set_long(
"An older man with white hair who was bitten and then turned into\n\
a Walking Dead Zombie. He looks like he was frail before being turned,\n\
but now he looks strong and deadly. He is still dressed in a hospital\n\
gown and has an IV tube sticking out of one arm. He is covered in "+BRED+"gore"+NORM+"\n\
from a previous meal.\n");
      set_level(3);
      break;
    case 38..41:
      set_short("A Walking "+HIBLK+"Dead Girl"+NORM);
      set_name("walker");
      add_walker_id( "girl" );
      set_long(
"A previously cute blond little girl who has been turned into a\n\
Walking Zombie. She is dressed in a pink nightgown and still has\n\
fuzzy slippers on one foot. Nothing is cute about her any longer:\n\
her mouth on one side has been ripped open exposing her teeth. "+RED+"Blood"+NORM+"\n\
constantly dribbles from her bottom lip. Her eyes are dark and they\n\
hold a hunger that is simply not human.\n");
      set_level(6);
      break;
    case 42..45:
      set_short("A Walking "+HIBLK+"Dead"+NORM+" Man");
      set_name("walker");
      add_walker_id( "man" );
      set_long(
"A Walking Dead Zombie who used to be a man in his mid twenties.\n\
He has lost his shirt and has a large "+RED+"gash"+NORM+" on his forehead and\n\
more open wounds on his shoulder and torso. His teeth are bloody\n\
and his mouth is a constant snarl.\n");
      set_level(7);
      break;
    case 46..50:
      set_short("A Walking "+HIBLK+"Dead"+NORM);
      set_name("walker");
      set_long(
"A Walking Dead Zombie straight from your nightmares. The dead milky\n\
eyes, rotten stink, exposed tissues, and unending appetite for human\n\
flesh are there but more terrifying than you ever realized. Every\n\
instinct inside you is screaming for you to run from this creature.\n");
      set_level(8);
      break;
  }
  set_aggressive(1);

}

monster_died() {
  object corpse;
  object item;
  
  corpse = present( "corpse", environment() );
  if( corpse ) {
    item = present( "kill_check_object", corpse );
    if( item )
      destruct( item );
  }
    return 0; 
}
