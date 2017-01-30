#include "/players/llew/closed/ansi.h"
align() {
   string *queen;
   queen=({"Keep Yourself Alive","Doing All Right","Great King Rat","My Fair King","Liar","The Night Comes Down","Modern Times Rock'n'roll","Son And Daughter","Seven Seas of Rhye","Procession","Father to Son","White Queen(As it Began)","Some Day One Day",
      "The Loser","Ogre Battle","The Fairy Fellow's Master Stroke","Nevermore","March of the Black Queen","Funny How Love Is","Brighton Rock","Killer Queen","Tenement Funster","Flick of the Wrist","Lily of the Valley","Now I'm Here",
      "In the Lap of the Gods","Stone Cold Crazy","Dear Friends","Misfire","Bring Back That Leroy Brown","She Makes Me(Stormtrooper in Stilettoes)","Death on Two Legs(Dedicated to...)","Lazing on a Sunday Afternoon","I'm in Love with My Car",
      "You're My Best Friend","'39","Sweet Lady","Seaside Rendezvous","The Prophet's Song","Love of my Life","Good Company","Bohemian Rhapsody","Tie Your Mother Down","You Take My Breath Away","Long Away","The Millionare Waltz","You and I",
      "Somebody to Love","White Man","Good Old Fashioned Lover Boy","Drowse","Teo Torriate(Let Us Cling Together)","We Will Rock You","We Are the Champions","Sheer Heart Attack","All Dead All Dead","Spread Your Wings","Flight from the Inside",
      "Get Down Make Love","Sleeping on the Sidewalk","Who Needs You","It's Late","My Melencholy Blues","Mustapha","Fat Bottemed Girls","Jealousy","Bicycle Race","If You Can't Beat Them","Let Me Entertain You","Dead on Time","In Only Seven Days",
      "Dreamer's Ball","Fun It","Leaving Home Ain't Easy","Don't stop me Now","More of That Jazz","Play the Game","Dragon Attack","Another One Bites the Dust","Need Your Loving Tonight","Crazy Little Thing Called Love","Rock it(Prime Jive)",
      "Don't Try Suicide","Sail Away Sweet Sister","Coming Soon","Save Me","Flash Gordan","Staying Power","Dancer","Back Chat","Body Language","Action This Day","Put Out the Fire","Life is Real(Song for Lennon)","Calling All Girls","Las Palabras de Amour",
      "Cool Cat","Under Pressure","Radio Ga Ga","Tear it Up","It's a Hard Life","Man on the Prowl","Machines(Or Back to Humans)","I Want to Break Free","Keep Passing the Open Windows","Hammer to Fall","Is This the World We Created?","One Vision",
      "A Kind of Magic","One Year of Love","Pain Is So Close to Pleasure","Friends Will Be Friends","Who Wants to Live Forever?","Gimme the Prize","Don't Lose Your Head","Princes of the Universe","Party","Kashoggi's Ship","The Miricle","I Want it All",
      "The Invisible Man","Breakthru","Rain Must Fall","Scandal","My Baby Does Me","Was It All Worth It","Hang on in There","Chinese Torture","Innuendo","I'm Going Slightly Mad","Headlong","I Can't Like With You","Ride the Wild Wind","All God's People",
      "These Are the Days of Our Lives","Delilah","Don't Try So Hard","The Hitman","Bijou","The Show Must Go On","See What a Fool I've Been","A Human Body","Soul Brother","I Go Crazy","Thank God's it's Christmas","Blured Vission","It's a Beautiful Day",
      "Made in Heaven","Let Me Live","Mother Love","My Life Has Been Saved","I Was Born to Love You","Heaven for Everyone","Too Much Love Will Kill You","You Don't Fool Me","A Winter's Tale"});
   find_player("llew")->set_al_title(queen[random(sizeof(queen))]);
   find_player("llew")->save_me();
/*
   title();
*/
   return 1;
}

title() {
   string titles;
   int rand;
   titles=({
      GRY+"Slimy"+HIY,
      NORM+"the "+HIY+"B"+BLK+"a"+YEL+"n"+BLK+"a"+YEL+"n"+BLK+"a "+YEL+"S"+BLK+"l"+YEL+"u"+BLK+"g"+NORM,
      YEL+"Cymric "+BOLD+"Celt"+NORM,
      "the "+GRN+"Forest Lord"+NORM,
      RED+"/"+BOLD+"-"+NORM+RED+"\\ "+BLU+"Mercenary Captain"+HIC,
      NORM+"the "+HIC+"Guppy "+RED+"Terrorist "+NORM+". "+BOLD+"o "+NORM+BLU+"O "+BOLD+"("+NORM+CYN+"Glub Glub"+HIB+")"+NORM,
      RED+"Papa"+NORM+BLU,
      NORM+"is feeling "+BOLD+"S"+RED+"m"+BLU+"u"+NORM+BOLD+"r"+RED+"f"+BLU+"y"+NORM,
      "",
      "the "+BLU+"C"+RED+"o"+YEL+"l"+MAG+"o"+CYN+"r"+GRN+"f"+BOLD+BLK+"u"+NORM+BOLD+"l "+HIB+"J"+RED+"e"+YEL+"s"+MAG+"t"+CYN+"e"+GRN+"r"+NORM,
      HIY + "$" + NORM + YEL + "BLING" + BOLD + "$" + NORM + YEL + "BLING" + BOLD + "$" + GRY + " Masta",
      NORM + "the " + HIM + "P" + NORM + MAG + "imp " + BOLD + "D" + NORM + MAG + "addy" + NORM,
   });
   rand=random(sizeof(titles)/2)*2;
   find_player("llew")->set_pretitle(titles[rand]);
   find_player("llew")->set_title(titles[rand+1]);
   find_player("llew")->save_me();
}
