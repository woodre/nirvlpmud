
/* DescMasterDM.c
 *
 * Sentence builder and object generator for Plane of Etheriel.
 * Shut up. I know this is one big string but a single bulletin board
 * is worse. How many bulletin boards do you know can build random
 * descriptions for castles? Huh? Huh? Yeah. I thought so.
 */

#define HOME "/players/mizan/core/02h/room04.c"
#define LISTENING_ROOM "/players/mizan/core/02h/room02.c"

string ev1,ev_no,ev_act,ev_fin;
string ds_pre,ds_l,ds_e;
string ob;

reset(arg) 
{
    if(arg) return;
    move_object(this_object(), HOME);
    reset_desc_vars();
    reset_event_vars();
    reset_object_list();
}

id(str) { return str == "wordmajig"; }

short() { return "The Wordmajig [Version 1.0]"; }

long() {
  if(this_player()->query_level() < 20) {
    write("It notices you looking at it, and grunts: What you want, dummy?\n");
    return 1;
  }
  write("This thing assigns random descriptions and monster combinations\n"+
  "within the Plane of Etheriel. It has no statistical recording capabilites.\n"+
  "and it does'nt need them.\n");
}

build_description() 
{
  string temp,polished;
  int i,j,k,l;
  i = random(2) + 1;
  temp = "      ";
  while(j < i) {
    k = random(2);
    if(k == 1) {
      if(!ev1) reset_event_vars();
      temp = temp + ev1[random(sizeof(ev1))] + " " + ev_no[random(sizeof(ev_no))] + " ";
      temp = temp + ev_act[random(sizeof(ev1))] + " " + ev_fin[random(sizeof(ev_fin))] + " ";
    } else temp = temp + ds_pre[random(sizeof(ds_pre))] + " " + ds_l[random(sizeof(ds_l))] + " ";
    j++;
  }
  if(1 == random(3)) temp = temp + ds_e[random(sizeof(ds_e))];
/*
#define WIDTH 71
  temp = format(temp, WIDTH - 1);
  polished = "";
  while(strlen(temp) > ((polished * WIDTH) * l)) {
    if(strlen(temp) > (WIDTH * l)) 
      polished = polished + extract(temp, ((WIDTH * l) - WIDTH), (WIDTH * l)) + "\n  ";
    l++;
  }
  return polished + "\n";
 */
  if(temp)
  temp = format(temp, 70);
  else temp = "\tYou are drifting somewhere in the ether muck. It it annoying.\n"+
  "  You are cold and hungry. You want to watch television. You have\n"+
  "  developed a strange rash. Ack.\n";
  return temp + "\n";
}

build_object_list() {
  string temp;
  int counter,i;
  if(!ob) reset_object_list();
  i = random(3) + 3;
  temp = allocate(i);
  while(counter < (i)) {
    temp[counter] = "/players/mizan/etheriel/" + ob[random(sizeof(ob))];
    counter++;
  }
  return temp;
}

reset_event_vars() {
 ev1 = allocate(15);
 ev1[0]="You never suspected that it could happen, but";
 ev1[1]="Never in a million years did you expect to see when";
 ev1[2]="Now is a good time to bow to stupidity, as";
 ev1[3]="It's not every day when";
 ev1[4]="It takes superhuman effort to hold back laughter as";
 ev1[5]="Its rather amusing, not intimidating as you expected when";
 ev1[6]="You stumble into";
 ev1[7]="You start screaming uncontrollably as";
 ev1[8]="A nervous twitch kicks into you as";
 ev1[9]="Anarchy it is'nt, but";
 ev1[10]="Prescience would be a nice thing to have, so it can be known when";
 ev1[11]="The end would be at hand in the ordinary world when";
 ev1[12]="Boggled and bemused,";
 ev1[13]="Your head begins to spin and your stomach tumbles when";
 ev1[14]="People pay good money to see things like when";

 ev_no = allocate(37);
 ev_no[0]="a running steam locomotive";
 ev_no[1]="a broken bowling ball";
 ev_no[2]="a renegade tablecloth";
 ev_no[3]="an orange";
 ev_no[4]="an army of fungi";
 ev_no[5]="an elite band of Marine vegetables and produce";
 ev_no[6]="a lawnmower";
 ev_no[7]="a stuttering can opener";
 ev_no[8]="an utterly clueless lower invertibrate";
 ev_no[9]="a refrigerator wearing a turban";
 ev_no[10]="some fundamentalist ferrets of the Church of Pakka Moo";
 ev_no[11]="a baby nuclear bomb";
 ev_no[12]="a toaster";
 ev_no[13]="a pair of green bowling shoes";
 ev_no[14]="a vial of nitroglycerin";
 ev_no[15]="a half-eaten cheesenub";
 ev_no[16]="twenty gallons of amorphous mush";
 ev_no[17]="a goldfish named Bruce";
 ev_no[18]="a tree named Rich";
 ev_no[19]="a gibbering bag of potato chips";
 ev_no[20]="eighty pounds of animated kitty litter";
 ev_no[21]="a giraffe";
 ev_no[22]="a happy spotted gecko";
 ev_no[23]="a can of cling peaches";
 ev_no[24]="a police officer";
 ev_no[25]="some overgrown zucchini";
 ev_no[26]="a delirious hippo";
 ev_no[27]="an unemployed chipmunk";    
 ev_no[28]="a bad-tempered ferret";
 ev_no[29]="a socially inept catfish";
 ev_no[30]="Jim from the Dublin Pub";
 ev_no[31]="a bald guy named Stuart";
 ev_no[32]="someone with a rolling pin stuck to his head";
 ev_no[33]="a mildly overweight chameleon";
 ev_no[34]="a street lamp named Julie";
 ev_no[35]="a guy who looks sexually aroused (drunk)";
 ev_no[36]="a little girl wielding a fully automatic weapon";

 ev_act = allocate(24);
 ev_act[0]="growls so loudly that everything around it shakes the entire area";
 ev_act[1]="is blown to bits for no apparent reason";
 ev_act[2]="begins fuming and frothing";
 ev_act[3]="is shredding losing lottery tickets";
 ev_act[4]="dances";
 ev_act[5]="taunts and humiliates anything nearby";
 ev_act[6]="sings in Yiddish";
 ev_act[7]="barks like a happy wombat";
 ev_act[8]="begins to attack the nearest Beano for no apparent reason";
 ev_act[9]="withdraws some money from an automatic teller machine";
 ev_act[10]="splits in two";
 ev_act[11]="starts digging in search of truffles";
 ev_act[12]="merrily reproduces";
 ev_act[13]="licks you";
 ev_act[14]="haks a wave of wet loogies at you";
 ev_act[15]="begs for a backrub";
 ev_act[16]="begins chanting 'Garbanzo!'";     
 ev_act[17]="wins several thousand US dollars on a lottery ticket";
 ev_act[18]="locates and captures a someone's missing prostrate gland";
 ev_act[19]="licks a stamp and pastes it on your forehead";
 ev_act[20]="beeps you on the nose";
 ev_act[21]="devours a can of cling peaches";
 ev_act[22]="makes fun of Mizan";
 ev_act[23]="babbles uncontrollably about the merits of rack-and-pinion steering";

 ev_fin = allocate(26);
 ev_fin[0]="right here before your very eyes.";
 ev_fin[1]="in a Spuck-like way.";
 ev_fin[2]="while wearing nothing but a jockstrap.";
 ev_fin[3]="and covers you with a thin, green ooze.";
 ev_fin[4]="in a most bewildernoggling fashion.";
 ev_fin[5]="and leaves you dripping with a fine, organic ooze.";
 ev_fin[6]="and leaves you with the sudden urge to find a McDonald's cheeseburger.";
 ev_fin[7]="while juggling several pounds of pocket lint.";
 ev_fin[8]="while clutching a copy of the Farmer's Almanac.";
 ev_fin[9]="while eating a hard, leather bone.";
 ev_fin[10]="while holding a sign that reads: 'Mean People Suck'.";
 ev_fin[11]="to the point of insanity and beyond.";
 ev_fin[12]="while reciting the entirety of Act One in Shakespeare's Othello.";
 ev_fin[13]="while sneezing violently.";
 ev_fin[14]="while threatening someone with a pair of moose antlers.";
 ev_fin[15]="while guzzling grape juice.";
 ev_fin[16]="while drinking a virgin screwdriver.";
 ev_fin[17]="while inhaling Pepsi.";
 ev_fin[18]="while smoking banana peels.";
 ev_fin[19]="and causes more confusion (Poof!) to confuse, among other things.";
 ev_fin[20]="and causes the ether-muck to expand somewhat.";
 ev_fin[21]="while causing the ozone layer back on Earth to deplete.";
 ev_fin[22]="while taking apart a ceiling fan.";
 ev_fin[23]="while ordering a pizza.";
 ev_fin[24]="while insulting the entire wizard population of the mud.";
 ev_fin[25]="while threatening to systematically remove your fingernails with a pair of needle-nose pliers.";
}

reset_desc_vars() {
 ds_pre = allocate(12);
 ds_pre[0]="Pokey and slightly delirious,";
 ds_pre[1]="Bewildernoggled by the consistently inconsistent current,";
 ds_pre[2]="Strange thoughts grace your mind, and you begin to think about a more normal existence but";
 ds_pre[3]="Sometimes it seems like a limitless expanse, sometimes it seems terribly claustrophobic, but it has a strange, secure feeling to it. Off in the distance (or nearby?)";
 ds_pre[4]="You holler at the top of your lungs: 'Crap... What the hell am I doing here???' Nearby creature drift away, secretly amused, and";
 ds_pre[5]="Ouch. Your head hurts and";
 ds_pre[6]="Somehow, everything seems a bit more ordered around here. That's boggling since";
 ds_pre[7]="Just as you feel that you have mastered movement in the ether-muck, disorientation sets in as";
 ds_pre[8]="An array of ever-shapeshifting forms greets you by floating through your stomach, and emerging on the other side covered in what was your lunch. You almost vomit but";
 ds_pre[9]="Who created this place? It seems to have a predictable unpredictability evident as";
 ds_pre[10]="Drifting into this area,";
 ds_pre[11]="Arriving in a state of mental messiness, it is compounded as";

 ds_l = allocate(21);
 ds_l[0]="you can see a small hole in the 'fabric' of the ether-muck here. Something in it is pulsating and constantly shifting the current.";
 ds_l[1]="you see some Boofers playing some kind of game with what appears to be a Beano. The Beano is the ball, yes.";
 ds_l[2]="a gloopey glowing thing drifting nearby suddenly explodes without warning, killing several smaller gloopey things.";
 ds_l[3]="you see a variety of beat-up kitchen appliances drifting by.";
 ds_l[4]="a semi-elliptical wave of funky energy spread and diverge on all four dimensions.";
 ds_l[5]="there is a manhole cover that seems to go nowhere when you open it.";
 ds_l[6]="a chessboard with pieces done in characture of Star Trek characters drift on by.";
 ds_l[7]="there is a blender here going on at full blast shredding raw tomatoes.";
 ds_l[8]="a scantily clad member of of your species (opposite sex of course) drifts by driving a steamroller.";
 ds_l[9]="you see a garbage can arguing with a toaster about the politics of wizardhood.";
 ds_l[10]="there is a plant of some sort waving a huge sign that reads: 'Support the fungal movement! Vote YES for Operative 939!";
 ds_l[11]="there is a halogen lamp drifting by, waving a huge sign that reads: 'Mean People Suck!'";
 ds_l[12]="you see a saber toothed wombat debating with a tree about the moral consequence of legalizing mind-expanding drugs.";
 ds_l[13]="a grand piano hurling at great speed crashes mercilessly into an unsuspecting Boofer, and disembowels it.";
 ds_l[14]="a ten-ton truck with the engine still running is ingested by a Nog. It burps. It grins biggly.";
 ds_l[15]="something explodes with great force in the distance, and the irregular, variable shockwaves collide into you.";
 ds_l[16]="some green icky stuff suddenly latches on to your face. Some makes its way into your mouth... but it tasted GOOD!";
 ds_l[17]="a toaster punts a Spuckball off into oblivion, obviously after losing an argument. Yes.";
 ds_l[18]="a chunk of depleted uranium collides into your head. Thunk!";
 ds_l[19]="a tree with wings sails by you, screaming 'Wheeeeee!'";
 ds_l[20]="a baseball bat covered with sausage grease drifts by, singing the 'Kimigayo', the Japanese national anthem.";

 ds_e = allocate(13);
 ds_e[0]="Bog that!";
 ds_e[1]="You are left in a mild bogglement.";
 ds_e[2]="Admit it. It was amusing, however little, and in its own abject way.";
 ds_e[3]="You feel like what you are swimming in. Jello. Is this mental state truly nirvana?";
 ds_e[4]="Time seems to be another in a long list of laws distorted by the ether-muck. How long have you been here? Several minutes? Several hours? Eep.";
 ds_e[5]="This all reminds you of a delirious dream once had many moons ago.";
 ds_e[6]="Deep down inside, you are beginning to enjoy it here, due to the "+
  "absence of any kind of rule. It is a utopian society in a sense, "+
  "complete anarchy and freedom... yet stability and benevolence somehow exist.";
 ds_e[7]="Somehow, you feel introspective and relaxed.";
 ds_e[8]="Your head begins to smart just trying to come up with "+
  "a logical explanation for what you have just observed.";
 ds_e[10]="Wow! Explain that in rational terms! You fail.";
 ds_e[11]="It's another normal day in the Plane of Etheriel.";
 ds_e[12]="What? You don't like raw toast? How dare you!";
}

reset_object_list() 
{
 ob = allocate(23);
 ob[0] = "beasties/boofer.c";
 ob[1] = "beasties/oofa.c";
 ob[2] = "beasties/mboofer.c";
 ob[3] = "beasties/beano.c";
 ob[4] = "beasties/wombat.c";
 ob[5] = "beasties/grimpo.c";
 ob[6] = "beasties/colormonger.c";
 ob[7] = "beasties/spuckball.c";
 ob[8] = "beasties/symidryl.c";
 ob[9] = "beasties/blinking-oofa.c";
 ob[10] = "beasties/blinking-boofer.c";
 ob[11] = "beasties/fuzzy.c";
 ob[12] = "beasties/bullfrog.c";
 ob[13] = "beasties/giraffe.c";
 ob[14] = "beasties/sarawak.c";
 ob[15] = "environs/faucet.c";
 ob[16] = "environs/spigot.c";
 ob[17] = "environs/exploder.c";
 ob[19] = "environs/wz-pinball.c";
 ob[20] = "beasties/cactus.c";
  ob[21] = "environs/berynol-pump.c";
  ob[22] = "environs/grimpo2.c";
}


