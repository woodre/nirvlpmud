inherit "obj/clean";
#include "/players/snakespear/closed/ansi.h"
id(str) {
    return str == "machine" || str == "randomizer";
}

short() { 
   return HIW+"The Randomizer"+HIM+" [humming]"+NORM;
}

long()  {
 write(
 "\n  A small machine with knobs and button all over the front.  It's shaking\n"+
 "violently with all the little gears and levers working so fast.  This\n"+
 "thing has a little note hanging over all the buttons.\n");
}

get()  { return 0;  }
query_weight()  { return 1; }
query_value()  { return 1;  }
init()  {
  add_action("title_set", "title_me");
  add_action("read_note", "read");
}

read_note(str) {
   if(str != "note") { 
      notify_fail("\nWhat are you trying to read?\n");
      return 0;
   }
 if(str == "note"){
 write(
 HIW+"\t\t\t*^*^*^*  N O T I C E  *^*^*^*\n\n"+HIC+
 "\n\n\n\n\t  The Randomizer has gone berzerk!  If you want a title.  You\n"+
 "\tcan type 'title_me'.  The machine isn't working correctly, so\n"+
 "\tthe titles are coming out quite oddly.  You can use the machine\n"+
 "\tas many times as you wish, but it will cost 5000 coins and you\n"+
 "\tmust be over level 10 to use it.\n\n\n\n"+
 "\tBrought to you by "+HIW+"Snakespear.\n\n\n\n"+NORM);
 return 1;
 }
} 
title_set() {
   int blah;
   string msg;
   blah = random(85);
   switch(blah) {
    case 0:   msg="Rox U!";break;
    case 1:   msg="is Rockin' !!";break;
    case 2:   msg="the Schizophrenic Killing Machine";break;
    case 3:   msg="the Lover";break;
    case 4:   msg="the Wanton Soul";break;
    case 5:   msg="is wanting chinese food!!";break;
    case 6:   msg="the Flap-Master";break;
    case 7:   msg="the insanely romantic stuffed teddy bear";break;
    case 8:   msg="the Dark Force Rising";break;
    case 9:   msg="the Scorcher";break;
    case 10:  msg="just got a new title!";break;
    case 11:  msg="the wandering poppy seed";break;
    case 12:  msg="just spent too much money on a title";break;
    case 13:  msg="the bogus frugal matter";break;
    case 14:  msg="had sex with Trixie";break;
    case 15:  msg="the Annihilator";break;
    case 16:  msg="the wannabe Faded Power Ranger";break;
    case 17:  msg="the pink powder puff";break;
    case 18:  msg="just ran from a fight with a cream filled twinkie";break;
    case 19:  msg="wants a real title";break;
    case 20:  msg="is addicted to mudding";break;
    case 21:  msg="the snake charmer";break;
    case 22:  msg="is a stick in the mud";break;
    case 23:  msg="the spectral force";break;
    case 24:  msg="can be reached at 1-900-REAL-SEX";break;
    case 25:  msg="is For Rent <just send a tell>";break;
    case 26:  msg="the sensual lover";break;
    case 27:  msg="the MudPuppy";break;
    case 28:  msg="the Ecto-Plasmic Goo";break;
    case 29:  msg="the Lunatic";break;
    case 30:  msg="the Heretic";break;
    case 31:  msg="is fearsome!";break;
    case 32:  msg="just got his Butt Kicked!";break;
    case 33:  msg="the angelic";break;
    case 34:  msg="is dazed and confused";break;
    case 35:  msg="really is a female";break;
    case 36:  msg="really is a male";break;
    case 37:  msg="the Master of Disaster";break;
    case 38:  msg="hopes to be a kewl as Snakespear";break;
    case 39:  msg="remembers the glory days";break;
    case 40:  msg="has bad gas today";break;
    case 41:  msg="got his butt kicked by Jaraxle";break;
    case 42:  msg="has been MOGGED!";break;
    case 43:  msg="is hunted by Wombats";break;
    case 44:  msg="ran from a fight with Guest";break;
    case 45:  msg="spent too much for this title";break;
    case 46:  msg="hopes to be a wiz";break;
    case 47:  msg="refuses to pay for net service";break;
    case 48:  msg="is hunting wabbits!";break;
    case 49:  msg="exclaims: No animals got hurt!";break;
    case 50:  msg="is a case sensitizing bogglenut";break;
    case 51:  msg="the human catapult";break;
    case 52:  msg="worships Shiverheart as God";break;
    case 53:  msg="the Lost Cause";break;
    case 54:  msg="the Master of the Game";break;
    case 55:  msg="is a dull pen";break;
    case 56:  msg="the WannaBe";break;
    case 57:  msg="hates Rap!";break;
    case 58:  msg="will work for food";break;
    case 59:  msg="is a veternarian cause I love kids!";break;
    case 60:  msg="is a Barbie Girl in a BarbieWorld (tm)";break;
    case 61:  msg="rocks the party that rocks the body";break;
    case 62:  msg="is a player hater";break;
    case 63:  msg="is in deperate need of therapy";break;
    case 64:  msg="is more hardcore than the Wu-Tang Clan";break;
    case 65:  msg="killed Kenny";break;
    case 66:  msg="puts their hand upon their hip and does da dip";break;
    case 67:  msg="_needs_ a hug!";break;
    case 68:  msg="sings: Carma Carma Carma Chamileon..";break;
    case 69:  msg="was shot through the heart and YER to blame";break;
    case 70:  msg="played twister too!!!";break;
    case 71:  msg="killed a cheesenub in the church with a thingamajig";break;
    case 72:  msg="is Smurfette in disguise";break;
    case 73:  msg="needs a clue";break;
    case 74:  msg="is Barney incognito";break;
    case 75:  msg="stars in: As the Mud Turns";break;
    case 76:  msg="gets jiggy wit it!";break;
    case 77:  msg="has fallen and can't get up!";break;
    case 78:  msg="the Fallen";break;
    case 79:  msg="the Reaver";break;
    case 80:  msg="the Borg";break;
    case 81:  msg="the Flopnistic Gargletron";break;
    case 82:  msg="grunts for monopoly money!";break;
    case 83:  msg="has their heart on their sleeve";break;
    case 84:  msg=HIR+"has a COLOR title!"+NORM;break;
    }
if(this_player()->query_level() < 10) {
  write(HIY+"\n\nYou need to grow up before doing big kid things!\n\n"+NORM);
  return 1;
  }
if(this_player()->query_money() < 5000) {
  write(HIG+"\n\nI think you need to check your funds!\n\n"+NORM);
  return 1;
  }
this_player()->add_money(-5000);
write(HIW+"Title set to: "+HIR+this_player()->query_name()+NORM+" "+msg+".\n");
say(this_player()->query_name()+" looks around to see what's been done.\n");
this_player()->set_title(msg);
return 1;
}
