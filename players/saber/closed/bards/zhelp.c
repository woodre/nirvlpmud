bard_lore(str)  {
if(!str)  {
  write("\n");
  write("   (*) >< (*) <> (*) >< (*) <> (*) >BARDS< (*) <> (*) >< (*) <> (*) >< (*)\n"+
   "   )*(                                                                 )*( \n"+
   "   (*)                      **  Bardic Lore  **                        (*)\n"+
   "   )*(                                                                 )*(\n"+
   "   (*)                                                                 (*)\n"+
   "   )*(   ** Instrumental Help: <lore instrument >                      )*(\n"+
   "   (*)                                                                 (*)\n"+
   "   )*(   ** Bardic Lore: <lore lore>                                   )*(\n"+
   "   (*)                                                                 (*)\n"+
   "   )*(   ** Bardic Magic: <lore cantrip> or <cantrip>                  )*(\n"+
   "   (*)                                                                 (*)\n"+
   "   )*(   ** Shaping: <lore shaping> and <lore chaos>                   )*(\n"+
   "   (*)                                                                 (*)\n"+
   "   )*(   ** Bardic Emotions and Songs: <lore emotions or songs>        )*(\n"+
   "   (*)                                                                 (*)\n"+
   "   )*(   ** Bardic Tradition and Games: <lore tradition or games>      )*(\n"+
   "   (*)                                                                 (*)\n"+
   "   )*(                                                                 )*(\n"+
   "   (*)   And remember, a bard can always get information un an ability (*)\n"+
   "   (*)   by typing < lore (ability name) > or < lore (level #) >       (*)\n"+
   "   )*(                                                                 )*(\n"+
   "   (*) >< (*) <> (*) >< (*) <> (*) >>>*<<< (*) <> (*) >< (*) <> (*) >< (*) \n"+
   "");
  return 1;
        }

if(str == "instrument")  {
 write(
 "\n"+
 "ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll\n\n"+
 "Bard Instrument\n\n"+
 "  Communications            Technical               Traditional\n\n"+
 "  Bard Talk (bt)            Lore                    Bury corpse\n"+
 "  Bard Emotion (bte)        Lore Emotions           Pyre corpse\n"+
 "  Communion                 Bard Monitor (monitor)  Succor         (M: 40)\n"+
 "  Emote                     Bard_title              Animal         (M: 40)\n"+
 "  Bards Cant (cant)         Bard_title_list         Animal_list\n"+
 "  FarSing (bsing)           Instrument              Bless          (M: 5 )\n"+
 "  FarIllusion (bising)      Instrument_list         *Knowledge\n"+
 "  Gossipsong (farsong)      Kin                     *Knowledge_list\n"+
 "  Gossipemotion (farsonge)  Song_list <sing>        Charm          (M: ? )\n"+
 "  Bard Who (bwho)           Score  (sco)            *Curse         (M: ? )\n"+
 "                            Clean_instrument        *Marriage      (M: 50)\n"+
 "\nll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll*ll\n");
write("  Type lore tech for more.\n");
  return 1;
        }

if(str == "lore")  {
 write(
 "\n*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*\n\n"+
 "Bard Lore\n\n"+
 "1  Tune of Knowledge            ( finger < player > )                  (M: -- )\n"+
 "2  Chords of Weather Divination ( weather )                            (M: 5  )\n"+
 "2  Ditty of Magic Divination    ( detect < item > )                    (M: 5  )\n"+
 "3  Melody of Strength           ( strength < creature / player > )     (M: 5  )\n"+
 "3  Object Identification        ( identify < item > )                  (M: 30 )\n"+
 "3  Song of Balance              ( balance < player / creature > )      (M: 5  )\n"+
 "4  Eyes of the Hawk             ( hawks < player / obj / creature > )  (M: 10 )\n"+
 "4  Song of Knowledge            ( know < player / obj > )              (M: 30 )\n"+
 "5  Ayre of Ability              ( ayre < player > )                    (M: 15 )\n"+
 "5  Song of Second Sight         ( sight < direction > )                (M: 25 )\n"+
 "6  Rythm of Wealth              ( wealth < player > )                  (M: 10 )\n"+
 "7  *Lei of True Sight\n"+
 "8  Canticle of Reflection       ( reflect < player > )                 (M: 30 )\n"+
 "9  Words of Power: True Name    ( true_name < monster > )              (M: 100)\n"+
 "\n*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*\n");
  return 1;
        }

if(str == "shaping")  {
  write(
 "\n[*]=]=[=[*]_]=[_[*]=]_[=[*]_]=[_[*]=]_[=[*]_]=[_[*]=]_[=[*]_]=[_[*]=]=[=[*]\n"+
 "                                Shaping\n"+
 "Healing\n"+
 "2  Chant of Healing       ( cheal < monster or player > )           (M: 15)\n"+
 "4  Chord of Agony         ( agony < monster > )                     (M: 20)\n"+
 "6  *Lay of Curing         ( cure < player > )                       (M: 15)\n"+
 "8  Hymn of Healing        ( healing )                               (M: 50)\n"+
 "9  Words of Power: Rhapsody of Regeneration  ( regen )              (M:100)\n"+
 "\n"+
 "Illusion\n"+
 "2  Canticle of Light                   ( song < light or extinguish > ) (M: 10)\n"+
 "2  The Haunting                        ( haunt < player or creature > ) (M: 5 )\n"+
 "3  Note of Cloaking                    ( cloak )                        (M: 10)\n"+
 "4  Chords of Distortion                ( distort )                      (M: 20)\n"+
 "6  Canticle of Darkness                ( song < darken > )              (M: 30)\n"+
 "6  Harpers Song of Spectral Binding    ( bind < creature > )            (M: 35)\n"+
 "7  Song of Illusion                    ( illusion < name/h > < text > ) (M: 40)\n"+
 "9  *Words of Power: The Chant of Change ( shapechange < number > )      (M: 50)\n"+
 "\n"+
 "Evocation\n"+
 "2  Words of Pain                   ( word < creature > )              (M: 10 )\n"+
 "4  Tunes of Elemental Power        ( ele or elemental < creature > )  (M: 25 )\n"+
 "5  Psalm of the Chromatic Spheres  ( sphere )                         (M: 100)\n"+
 "7  Requiem of the Falling Stars    ( starfire )                       (M: 50+)\n"+
 "\n[*]=]=[=[*]_]_[_[*]=]_[=[*]_]=[_[*]=]_[=[*]_]=[_[*]=]_[=[*]_]_[_[*]=]=[=[*]\n");
  return 1;
        }

if(str == "chaos2")  {
  write(
 "\n"+
 "Cantrip Strand <5> Summons a strand of chaos from the very fabric of reality.\n"+
 "                    This is the first step in any shaping process.\n"+
 "                   <Cantrip strand>\n\n"+
 "Name        <20>  The most important part of the shaping process.  Here the bard\n"+
 "                    utters the True Name, the name of Appearance and the Common\n"+
 "                    name.\n"+
 "                   <S (object) name <true name> | <appearance> | <common name> >\n\n"+
 "xName       <5>    You may give an additional or formal name to your object.\n"+
 "                   <S (object) xname <additional name>\n\n"+
 "  Type chaos3 for further details on shaping.\n\n");
  return 1;
        }

if(str == "chaos3")  {
  write(
 "Detail      <5>    This aspect of shaping anchors the object more firmly in\n"+
 "                    reality so that details of it may be observed by looking\n"+
 "                    or examining it.\n"+
 "                   <S (object) detail <description> >\n\n"+
 "Inscribe    <5>    Lets the bard trace runes or an inscription upon the item.\n"+
 "                   <S (object) inscribe <runes to be inscribed> >\n\n"+
 "Shine       <10>   An aspect of shaping which causes the item to glow brightly.\n"+
 "                   <S (object) shine 1 >\n\n"+
 "Mass        <12>   You may shape the item so that it weighs less than usual.\n"+
 "                   <S (object) mass 0 >\n\n"+
 " For more help type <lore choas4>\n\n");
  return 1;
        }

if(str == "emotions2")  {
  write(
 "\n"+
 " > <    New Bardic Emotions                                 > <\n"+
 "  |                                                          |\n"+
 " > <         Juggle              Juggle2                    > <\n"+
 "  |          Scarf               Blueli                      |\n"+
 " > <         Disappear           Sing1                      > <\n"+
 "  |          Sing2               Holo                        |\n"+
 " > <         Strings             Clearth                    > <\n"+
 "  |          Tune                Sparkle                     |\n"+
 " > <         Bows                Handkiss                   > <\n"+
 "  |                                                          |\n"+
 " > <                                                        > <\n\n");
  return 1;
        }

if(str == "emotions")  {
  write(
 "\n"+
 " > <                             EMOTIONS                               > <\n"+
 "  |                                                                      |\n"+
 " > <    Bard speech                                                     > <\n"+
 "  |          By using the <;> key, you may speak as does a bard...       |\n"+
 " > <         with emotion!  Typing: ; <phrase> will produce the line    > <\n"+
 "  |          which appears: <your name> '<phrase>'  i.e. If I type       |\n"+
 " > <         ; Hi there.   the line produced will appear:               > <\n"+
 "  |                Saber says 'Hi there.'                                |\n"+
 " > <         ? and ! may also be used in a sentence to changed the      > <\n"+
 "  |          word <says> to something else.  The use of ! will change    |\n"+
 " > <         says to exclaims, !!! will be yells, ? will be asks and    > <\n"+
 "  |          ??? will be wonders.                                        |\n"+
 " > <                                                                    > <\n"+
 "  |     Bard Emote                                                       |\n"+
 " > <         As a bard you may substitute : for the word emote.  To     > <\n"+
 "  |          use, just type : <phrase>.  For example, : smiles.  will    |\n"+
 " > <         produce the line  Saber smiles.                            > <\n"+
 "  |                                                                      |\n"+
 " > <    Type lore emotions2 for help on the unique bardic emotions.     > <\n\n"+
  "\n");
  return 1;
        }

if(str == "cantrip")  {
  write(
 "\n"+
 "       Cantrips are the only true magic that bards possess.  All other bardic\n"+
 "magic is based upon their ability to shape the primal forces of law and chaos\n"+
 "to a more desirable reality.  Cantrips are pure, none music based magic.\n"+
 "       For a list of bardic cantrips, type <cantrip>\n\n");
  return 1;
        }

if(str == "songs")  {
  write("\n"+
 "    Bards are by both nature and definition musicians.  For a bard, music is\n"+
 "friend and companion, lover and master.\n"+
 "    To play a song, the bard must simply type < sing <song #> <verse #>\n"+
 "A list of songs, and their length and verses can be found with by typing <sing>\n"+
 "Because the songs have been divided into verses, a bard my improvise on their\n"+
 "performance.  For example, song one <Hay nonny nonny> is divided into three\n"+
 "parts, with sections 1 and 3 being the verses and section 2 being the chorus.\n"+
 "A proper rendition of the song would therefore be section 1, section 2, section\n"+
 "3 and section 2.  <You gotta end with the chorus, after all.>  However, if the\n"+
 "bard desired, she could play sections 1 and 3 only, or repeat the chorus 2\n"+
 "times in a row.  One note of caution, wait for the first section to end before\n"+
 "beginning the second.  It is a good idea to practice alone before playing in\n"+
 "public.  Type <sing> for a list of songs.\n\n");
  return 1;
        }
  if(str == "rules")  {
  write(
 "\nBard Rules and Limitations.\n\n"+
 "1)  Bards do not player kill.\n"+
 "      Bards are not pkers.  Neither a bard nor their pet may attack a player,\n"+
 "      even in a pk zone.\n"+
 "2)  Bardic magic does not kill.\n"+
 "      No bard spell (with one exception) will ever kill a creature.  It is\n"+
 "      contrary to the nature of bardic magic to take a life.\n"+
 "3)  Bards must maintain a positive balance within their soul.\n"+
 "      Bards are champions of noble causes.  Their abilities and gifts will not\n"+
 "      work if their soul is not balanced towards the light.\n"+
 "4)  Bards do NOT help other bards with their bard trials.\n"+
 "      Bard trials serve in lue of donating xp for guild levels.  Help with \n"+
 "      these tasks removes the thinking aspect from these trials and destroys\n"+
 "      the system.  Helping with a bard trial (info, hints, ect...) is one of\n"+
 "      the few ways to get kick out of the guild.\n"+
 "\nType <lore rules2> to continue.\n\n");
  return 1;
        }
  if(str == "rules2")  {
  write(
 "\nBard Rules and Limitations (cont.)\n\n"+
 "5)  Bards work for the good of the realm.\n"+
 "      Bards are the champions of light, and should work for the betterment and\n"+
 "      good of the realm.\n"+
 "6)  Bards value style over substance.\n"+
 "      Bards are flamboyant and like to show off.  They usually value\n"+
 "      appearance more than actual effects.\n"+
 "7)  Bards are social.\n"+
 "      As a bard, it is your DUTY (!!!) to talk a lot, hang out a lot and be\n"+
 "      an all around social person. (Have fun!).\n\n");
  return 1;
        }
  if(str == "tradition")  {
  write(
 "\n(*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*)\n\n"+
 "                            Bardic Tradition\n\n\n"+
 "    Bardic Rules (read this!)              <lore rules and lore rules2>\n\n"+
 "    Bardic Trials (gaining bard levels)    <lore trials>\n\n"+
 "    New Members (recruiting members)       <lore members>\n\n"+
 "    Bard Slang (how to talk like a bard)   <lore slang>\n\n"+
 "    Bardic Tradition (odd tidbits)         <lore traditions>\n\n\n"+
 "(*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*) )*( (*)\n\n");
  return 1;
        }
  if(str == "slang")  {
  write(
 "\Bard Slang\n\n"+
 " Bardprice - The coins paid to the guild for the teaching/training of a\n"+
 "               new bard.\n"+
 " Trial -     How bards advance in levels.  A quest must be done for each\n"+
 "               bard level.\n"+
 " Mana -      Spell points.  Mana just sounds cooler.\n"+
 " A Mark -    A gullible/easily fooled person.\n"+
 " Realms of magic - On the mud.\n"+
 " Reading period - The time when you just become a bard and are reading\n"+
 "               ALL of the lore files.  <help!>\n"+
 "\nGot more slang?  Talk to Saber...\n\n");
  return 1;
        }
  if(str == "trials")  {
  write(
"\nBard Trials\n\n"+
 "      Bards advance in bardic levels by solving bard trials.  No xp donation\n"+
 "is required; it is much more within the bardic tradition to solve riddles and\n"+
 "use wits than to kill things.\n"+
 "      As bard trials serve in leu of xp donation, they are to be done ALONE.\n"+
 "Bard trials are tests; those worthy of progressing will do so.  Helping\n"+
 "another with a bard trial is one of the only ways to get kicked out of the\n"+
 "guild.\n"+
 "      Information on specific bard trials can be found in the lore room.\n"+
 "Check the scrolls.\n\n");
  return 1;
        }
  if(str == "traditions")  {
  write(
  "\nBardic Traditions\n\n"+
 "  Conflicts between bards are settled via bard games. <lore games>\n\n"+
 "  A 'Bardfest' is held every month.\n\n"+
 "\nGot a tradition to add?  Write Saber...\n\n");
  return 1;
        }
  if(str == "members")  {
  write(
  "\nThere is no lore on this topic yet...\n\n");
  return 1;
        }
  if(str == "1")  {
  write(
 "Bard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n\n"+
 "Bard Help                   1        -       use: lore\n"+
 "Bard Monitor                1        -       use: monitor (toggle)\n"+
 "Bard Talk                   1        -       use: bt <string>\n"+
 "Bard Talk Emotions          1        -       use: bte <string>\n"+
 "Bard Title                  1+       -       use: bard_title (#)\n"+
 "Bard Title List             1        -       use: bard_title_list\n"+
 "Bard Who                    1        -       use: bwho\n"+
 "Bury Corpse                 1        -       use: bury corpse\n"+
 "Cantrip: Bauble             1        3       use: cantrip < bauble >\n"+
 "Clean instrument            1        -       use: clean_instrument\n"+
 "Communion                   1        -       use: communion <message>\n"+
 "Emote                       1        -       use: emote or : <string>\n"+
 "Instrument list             1        -       use: instrument_list\n"+
 "Kin                         1        -       use: kin\n"+
 "Pyre corpse                 1        -       use: pyre corpse\n"+
 "Succor                      1        40      use: succor\n"+
 "Switch instrument           1+       -       use: instrument_name <number>\n"+
 "Tune of Knowledge           1        -       use: finger <player>\n"+
 "\n");
  return 1;
        }
  if(str == "2")  {
  write(
 "\nBard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n\n"+
 "Animal Companion            2        50      use: animal <type>\n"+
 "Animal List                 2        -       use: animal_list\n"+
 "Bards Cant                  2        -       use: cant <message>\n"+
 "Bless                       2        5       use: bless <player/object>\n"+
 "Canticle of Light           2        10      use: song light/extinguish\n"+
 "Cantrip: Intox              2        5       use: cantrip <intox>\n"+
 "Chant of Healing            2        15      use: cheal <player>\n"+
 "Chords of Weather Divin.    2        5       use: weather\n"+
 "Ditty of Magic Divination   2        5       use: detect <item>\n"+
 "The Haunting                2        5       use: haunt <player/monster>\n"+
 "*Knowledge                  2        -       use: knowledge <place>\n"+
 "*Knowledge list             2        -       use: knowledge_list\n"+
 "Words of Pain               2        10      use: word <creature>\n"+
 "\n");
  return 1;
        }
  if(str == "3")  {
  write(
 "\nBard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n"+
 
 "\nCantrip: Bubble             3        10      use: cantrip <bubble>\n"+
 "Charm                       3        30      use: charm or charm <opponent>\n"+
 "Identify                    3        30      use: identify <object>\n"+
 "Melody of Strength          3        5       use: strength or stre <creature>\n"+
 "Note of Cloaking            3        10      use: cloak <player>\n"+
 "Song of Balance             3        5       use: balance <creature>\n"+
 "\n");
  return 1;
        }
  if(str == "4")  {
  write(
 "\nBard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n\n"+
 "Bard Image                  4        3       use: bising <string>\n"+
 "Bard Sing                   4        3       use: bsing <string>\n"+
 "Chord of Agony              4        20      use: agony <creature>\n"+
 "Chords of Distortion        4        20      use: distort\n"+
 "Eyes of the Hawk            4        10      use: hawks <player/item>\n"+
 "Song of Knowledge           4        30      use: know <player/creature>\n"+
 "Tunes of Elemental Power    4        25      use: elemental/ele <creature>\n"+
 "\n");
  return 1;
        }
  if(str == "5")  {
  write(
 "\nBard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n\n"+
 "Ayre of Ability             5       15       use: ayre <player>\n"+
 "* Curse                     5       ??       use: curse <player>\n"+
 "Psalm of Chromatic Spheres  5       100      use: sphere\n"+
 "Sing                        5       15       use: farsong <str>\n"+
 "Singe                       5       15       use: farsonge <str>\n"+
 "Song of Second Sight        5       25       use: sight <dir> & lore <sight>\n"+
 "\n");
  return 1;
        }
  if(str == "6")  {
  write(
 "\nBard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n\n"+
 "Canticle of Darkness        6       30       use: song darken\n"+
 "Harper's Song of Spectral Binding\n"+
 "                            6       35       use: bind <creature>\n"+
 "* Lay of Curing             6       15       use: cure <player>\n"+
 "Storm                       6       20       use: cantrip <storm>\n"+
 "Rhythm of Wealth            6       10       use: wealth <player>\n"+
 "\n");
  return 1;
        }
  if(str == "7")  {
  write(
 "\nBard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n\n"+
 "Cantrip: Strand              7       5        use: cantrip <strand>\n"+
 "* Lei of True Sight          7       30       use: true sight\n"+
 "Requiem of the Falling Stars 7       20+      use: starfire (#)\n"+
 "Song of Illusion             7       40       use: illusion <player/here>\n"+
 "\n");
  return 1;
        }
  if(str == "8")  {
  write(
 "\nBard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n\n"+
 "Canticle of Reflection      8       30       use: reflect <player>\n"+
 "Hymn of Healing             8       50       use: healing\n"+
 "Shaping                     8       ??       use: lore chaos\n"+
 "\n");
  return 1;
        }
  if(str == "9")  {
  write(
 "\nBard Abilities          Bard Lvl   Mana      Use\n"+
 "_________________________________________________________________________\n\n"+
 "*Marriage                   9       50       use: marry <x> to <y>\n"+
 "*Words of Power: The Chant of Change\n"+
 "                            9       50       use: shapechange #\n"+
 "Words of Power: The Rhapsody of Regeneration\n"+
 "                            9       100      use: regeneration\n"+
 "Words of Power: True Name   9       100      use: true_name <monster>\n"+
 "\n");
  return 1;
        }
if(str == "tech")  {
write(
 "\n\nTECHNICAL STUFF YOU SHOULD KNOW\n\n"+
 "To save your bard stats, type <pppp>.  It auto saves when you quit, but\n"+
 "  you may want to it every once in a while, and after every bard trial.\n\n"+
 "To get a Tome of the Bardic Guild <tells about the bards guild> to\n"+
 "  give to other players, type lore tome.\n"+
 "\n");
  return 1;
        }
if(str == "tome")  {
write("You now have a Bardic Tome.\n");
move_object(clone_object("/players/saber/closed/bards/bard_help.c"),this_player());
  return 1;
        }
if(str == "chaos")  {
write(
 "\n  Shaping is the art of binding chaos to your view of reality.  There will be\n"+
 "more lore on this later.   For now, type <lore chaos2> for additional info.\n\n");
  return 1;
        }
if(str == "bard_title")  {
write(
 "This ability allows the bard to set their title to that appropriate of\n"+
"the guild level (see bard_title_list)\n");
  return 1;
        }
if(str == "bwho")  {
write(
"This ability shows the players currently within the realms of magic.\n");
  return 1;
        }
if(str == "bury corpse")  {
write(
"The powers which watch over the guild will reward you for this noble\n"+
"action by bestowing a minor blessing upon you (see pyre corpse)\n");
  return 1;
        }
if(str == "cantrip bauble")  {
write(
"This cantrip allows the bard to summon a small sphere of solid light.\n"+
"Try <peg> <player name> once you have a bauble.\n");
  return 1;
        }
if(str == "clean_instrument")  {
write(
"This updates your instrument to the latest version.\n");
  return 1;
        }
if(str == "instrument_list")  {
write(
"This will show you a list of the instruments that you are proficient with.\n");
  return 1;
        }
if(str == "kin")  {
write(
"This will show a list of your kin (fellow bards).\n");
  return 1;
        }
if(str == "pyre corpse")  {
write(
"The powers which watch over the guild will reward you for this noble\n"+
"action by bestowing a minor blessing upon you. (see bury corpse)\n");
  return 1;
        }
if(str == "succor")  {
write(
"The enchantment placed upon your bardic instrument will allow it to\n"+
"return you to the guild hall.\n");
  return 1;
        }
if(str == "finger")  {
write(
"This tune will tell you the last log in time of a player.\n");
  return 1;
        }
if(str == "animal")  {
write(
"This ability lets the bard summon an animal companion to\n"+
"accompany them.  <see animal_list>\n");
  return 1;
        }
if(str == "cant")  {
write(
"The speech of Bards.  It can only be understood by other guild member.\n"+
"A bard can teach it to a Paladin by <teach> <player name>.\n");
  return 1;
        }
if(str == "bless")  {
write(
"Lets you whisper a traditional celtic blessing over a person/object.\n");
  return 1;
        }
if(str == "song light")  {
write(
"This spellsong allows the bard to conjure a magical light which will\n"+
"follow them untill extinguished.\n");
  return 1;
        }
if(str == "cantrip intox")  {
write(
"A cantrip which will instantly intoxicate the caster.\n");
  return 1;
        }
if(str == "cheal")  {
write(
"A spellsong which allows the bard to cure a minor wound on themselves\n"+
"or upon another.\n");
  return 1;
        }
if(str == "weather")  {
write(
"This spellsong will tell you what the weather will be like for the next\n"+
"few hours.  <also see the cantrips>\n");
  return 1;
        }
if(str == "detect")  {
write(
"This spellsong of magic detection will analyze the inherent mana stored\n"+
"within any item.\n");
  return 1;
        }
if(str == "haunt")  {
write(
"With this spellsong, the bard bings themselves with an illusion of\n"+
"silence that they may secretly shadow a player/monster.\n");
  return 1;
        }
if(str == "word")  {
write(
"This spellsong allows the bard to focus the power of their mana\n"+
"through their voice to cause physical damage.\n");
  return 1;
        }
if(str == "cantrip bubble")  {
write(
"This cantrip will conjure up a solid sphere of light.\n");
  return 1;
        }
if(str == "charm")  {
write(
"This traditional ability of bards to use there music and charisma to\n"+
"stop all fighting within an area.  If a creature is named, than only\n"+
"it will be calmed.\n");
  return 1;
        }
if(str == "identify")  {
write(
"This is the traditional ability of a bard to analyze the worth\n"+
"and use of an object.\n");
  return 1;
        }
if(str == "strength" || str == "stre")  {
write(
"this spellsong will measure how healthy a creature is.\n");
  return 1;
        }
if(str == "cloak")  {
write(
"This note cloaks the bard in a minor illusion, disguising them from any\n"+
"current hunter.\n");
  return 1;
        }
if(str == "balance")  {
write(
"This spellsong determines the balance of a creatures soul.\n");
  return 1;
        }
if(str == "bsing")  {
write(
"Bards of talent may sing a song which will be heard only by a\n"+
"single individual, no matter what distance or plane may lay between you.\n");
  return 1;
        }
if(str == "bising")  {
write(
"Bards of talent may sing a song which will send a single individual\n"+
"a mental tune of an image or emotion.\n");
  return 1;
        }
if(str == "agony")  {
write(
"When struck, this chord disrupts the natural healing processes of an\n"+
"opponent.  It also hurts like hell.\n");
  return 1;
        }
if(str == "distort")  {
write(
"This spellsong allows the bard to cloak themselves in a blur of shifting\n"+
"illusion, thereby temporarily improving their armor.\n");
  return 1;
        }
if(str == "hawks")  {
write(
"This divination song which shows the bard where a player or\n"+
"object or monster is, IF THEY HAVE RECENTLY been passed.\n");
  return 1;
        }
if(str == "elemental" || str == "ele")  {
write(
"An evocational spellsong which allows the bard to channel one form\n"+
"of elemental energy into an offensive attack.\n");
  return 1;
        }
if(str == "know")  {
write(
"This spellsong grants the bard an excess of information about the target.\n");
  return 1;
        }
if(str == "ayre")  {
write(
"The music of this Ayre will divine the strengths of a player.\n");
  return 1;
        }
if(str == "sphere")  {
write(
"This evocation shapes five spheres of rainbow colors.  The bard may\n"+
"hurl these spheres at their foes in combat.\n");
  return 1;
        }
if(str == "farsong")  {
write(
"Bards need not gossip when they may instead sing.\n");
  return 1;
        }
if(str == "farsonge")  {
write(
"Bards need not gossip emotions when they may instead sing them.\n");
  return 1;
        }
if(str == "sight")  {
write(
"This spellsong allows the bard to view an area adjacent to their own.\n"+
"Type: sight <direction> to see in another direction.\n"+
"Type: sight music to release music (it wanders!)\n"+
"Type: sight   to see where the music is (any bardic music)\n"+
"Type: sight kill to get rid of the wandering music.\n");
  return 1;
        }
if(str == "song darken" || str == "darken")  {
write(
"The reverse of the canticle of light, this spellsong allows the bard\n"+
"to cloak the area in the illusion of darkness.\n");
  return 1;
        }
if(str == "bind")  {
write(
"This spellsong binds a foe in the bard in chains of misty illusion.\n");
  return 1;
        }
if(str == "cure")  {
write(
"This lay allows the bard to cure themselves or another of a disease.\n"+
"It is also effective against curses.\n");
  return 1;
        }
if(str == "cantrip storm")  {
write(
"A cantrip which allows the bard to whistle up a storm.  Literally!\n");
  return 1;
        }
if(str == "wealth")  {
write(
"This spellsong of divination allows the bard to determine the weight of\n"+
"an opponents money pouch.\n");
  return 1;
        }
if(str == "cantrip strand" || str == "strand")  {
write(
"A cantrip which allows the bard to pluck a strand of chaos from reality.\n"+
"The first step in shaping.\n");
  return 1;
        }
if(str == "starfire")  {
write(
"A powerful spellsong of evocation which bathes the immediate area in\n"+
"this white fire of the stars.  Requires a gem as a material component.\n");
  return 1;
        }
if(str == "illusion")  {
write(
"A powerful spellsong of illusion which allows the bard to weave an\n"+
"illusion which appears before all creatures in the chamber.  Alternately,\n"+
"it may be sent across the realms of magic to a single individual.\n"+
"<illusion> <here> <text>  (example <illusion> A large red dragon)\n"+
"<illusion> <player> <text>  (example illusion saber A dragon flies by you)\n");
  return 1;
        }
if(str == "reflect")  {
write(
"A spellsong which polishes a surface to the quality of a mirror.\n"+
"Any creature gazing at the mirror can see a new location.\n");
  return 1;
        }
if(str == "healing")  {
write(
"A powerful healing spellsong which will cure serious wounds.\n");
  return 1;
        }
if(str == "marry")  {
write(
"More to come later.\n");
  return 1;
        }
if(str == "shapechange")  {
write(
"More to come later.\n");
  return 1;
        }
if(str == "regeneration")  {
write(
"A potent healing spellsong which causes the bard to begin regenerating\n"+
"at an astonishing rate.  It lasts untill you reach FULL hp.\n");
  return 1;
        }
if(str == "true_name" || str == "true name")  {
write(
"This word of power divines the true name of a creature.  And the\n"+
"knowledge of a true name is the power to destroy.\n"+
"This power tops healing, does damage, and lowers the creatures wc and ac!\n");
  return 1;
        }

  write("There is no lore on that topic.\n");
  return 1;
        }

animal_list()  {
write("\n"+
"  Those of the Bardic tradition may summon an animal companion to accompany\n"+
"them on their journeys.  Bardic animals are mentally linked to the summoner.\n"+
"If a bard pet dies, the bard takes mental backlash.\n"+
"  Commands use the syntax: <capitalize> command\n\n"+
"  Pet Level   Bard Level     Fighting\n"+
"_____________________________________________\n\n"+
"    One           2          pathetic\n"+
"    Two           4          decent\n"+
"    Three         6          good\n"+
"    Four          8          excellent\n"+
"_____________________________________________\n\n"+
"  Type: <animal_list2> for a list of animal commands.\n"+
"  Type: <animal_list3> for a list of bardic animals.\n");
  return 1;
        }
animal_list2()  {
write("\n"+
"\nPets have the following abilities: (just capitalize the command)\n"+
"\n talk/silence   Pets normally fly around, squawk, ect.  By typing <animal\n"+
"                  type> silence, your pet will be silent.  <animal type> talk\n"+
"                  will let them know its ok to move again.\n"+
" guard          An important ability.  If any bard pet is attacked by a pet, a\n"+
"                  kid or a player, type <animal type> guard.  This will summon\n"+
"                  the goddess Crysea, who watches over the bardic pets.\n"+
" sic            Will tell your animal friend to attack a <monster>.\n"+
" bye            Dismisses your animal companion.\n"+
" give           Syntax: <animal type> give <object> to <player>\n"+
"                  Your animal friend will take the named object from your inv\n"+
"                  and give it to the player named.\n"+
" munch          Tells your animal that they may chow down upon a corpse.\n"+
" hand           Syntax: <animal type> hand <object> to <player>\n"+
"                  Have your animal give an object they carry to a player\n"+
"                  in the same room as you.  (hand is the same room, give is a\n"+
"                  different one)\n"+
" back           Syntax: back <monster that your pet is fighting>\n"+
"                  Moves your pet out of the fight.\n"+
"\n");
  return 1;
        }

animal_list3()  {
write("\n\nBardic Animals\n\n"+
 "Rank 1):\n"+
 "    Crow\n"+
 "    Raven\n"+
 "\n"+
 "Rank 2):\n"+
 "    Hawk\n"+
 "    Pixies\n"+
 "    Sprite (wind sprite)\n"+
 "\n"+
 "Rank 3):\n"+
 "    Drake\n"+
 "    Pegasus\n"+
 "\n"+
 "Rank 4):\n"+
 "    Black pegasus  <bpegesus to summon>\n"+
 "    Phoenix\n"+
 "\n"+
 "To summon a pet, type <animal> <animal type> <name>\n"+
 "Note: name should be your animals name, like Star or Dancer, etc.\n");
  return 1;
        }
