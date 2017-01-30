#include "/players/zeus/closed/all.h"
#define TOU tell_object(usr,
#define TRU tell_room(usr_room,
#define USER usr

object usr, nmy, wep, usr_room;
object *env;
object c;
mixed a,b;
object ths, gob, ench, loc;
int wep_lvl, stype, forged, socket, o, so, p, h;
int spec, ws;
int thp, tsp, ahp, asp, cnt, sizeof_locs, Z, X; /* gem of eternity, vortex */
int soak, stuff, tox, ssoak, sstuff, ttox;
int k,l,q,y;
string *gnames, me,nn,tt,he,his,him,col, *spec1, *spec2, *spec3;
string *locs; /* vortex gem */
object corpse, gold; /* gem of decay, unholy death rites, gold */

r(x){  return random(x); }
c(x){  return capitalize(x); }

wield_checks(object x, int aa, ab){
  gob = x;
  if(!gob) return;
  spec = aa;
  ws = ab;

  if(spec == 1 && ws == 1)      /* minor gem of agility */
    gob->add_attribb(0, 15);
  else if(spec == 2 && ws == 1) /* gem of agility */
    gob->add_attribb(0, 30);
  else if(spec == 3 && ws == 1) /* major gem of agility */
    gob->add_attribb(0, 50);
  else if(spec == 1 && ws == 2) /* minor gem of might */
    gob->add_attribb(1, 15);
  else if(spec == 2 && ws == 2) /* gem of might */
    gob->add_attribb(1, 30);
  else if(spec == 3 && ws == 2) /* major gem of might */
    gob->add_attribb(1, 50);
  else if(spec == 1 && ws == 3) /* minor gem of accuracy */
    gob->add_attribb(2, 15);
  else if(spec == 2 && ws == 3) /* gem of accuracy */
    gob->add_attribb(2, 30);
  else if(spec == 3 && ws == 3) /* major gem of accuracy */
    gob->add_attribb(2, 50);
  else if(spec == 1 && ws == 4) /* minor gem of vigor */
    gob->add_attribb(3, 15);
  else if(spec == 2 && ws == 4) /* gem of vigor */
     gob->add_attribb(3, 30);
  else if(spec == 3 && ws == 4) /* major gem of vigor */
    gob->add_attribb(3, 50);
  else if(spec == 1 && ws == 5) /* minor gem of wisdom */
    gob->add_attribb(4, 15);
  else if(spec == 2 && ws == 5) /* gem of wisdom */
    gob->add_attribb(4, 30);
  else if(spec == 3 && ws == 5) /* major gem of wisdom */
    gob->add_attribb(4, 50);
  else if(spec == 1 && ws == 6) /* minor gem of faith */
    gob->add_attribb(5, 15);
  else if(spec == 2 && ws == 6) /* gem of faith */
    gob->add_attribb(5, 30);
  else if(spec == 3 && ws == 6) /* major gem of faith */
    gob->add_attribb(5, 50);
  else if(spec == 1 && ws == 10) /* gem of purity */
    this_player()->add_alignment(10000);
  else if(spec == 1 && ws == 11) /* gem of hatred */
    this_player()->add_alignment(-10000);
  else if(spec == 1 && ws == 12){ /* minor gem of performance */
    gob->add_attribb(0, 5);
    gob->add_attribb(1, 10);
    gob->add_attribb(2, 10);
    gob->add_attribb(3, 5);
  }
  else if(spec == 2 && ws == 8){ /* gem of speed */
    gob->add_attribb(0, 30);
    gob->add_attribb(3, 30);
  }
  else if(spec == 2 && ws == 9){ /* gem of performance */
    gob->add_attribb(0, 10);
    gob->add_attribb(1, 17);
    gob->add_attribb(2, 17);
    gob->add_attribb(3, 10);
  }
  else if(spec == 3 && ws == 7){ /* major gem of performance */
    gob->add_attribb(0, 15);
    gob->add_attribb(1, 30);
    gob->add_attribb(2, 30);
    gob->add_attribb(3, 15);
  }
  else if(spec == 1 && ws == 14){ /* gem of fury */
    gob->add_attribb(0, 10);
    gob->add_attribb(2, -10);
    gob->add_attribb(3, 10);
  }
  else if(spec == 3 && ws == 18){ /* gem of battle rites */
    gob->add_attribb(0, 30);
    gob->add_attribb(1, 30);
    gob->add_attribb(2, 30);
    gob->add_attribb(3, 30);
    gob->add_attribb(4, -25);
    gob->add_attribb(5, -25);
  }
  else if(spec == 3 && ws == 19){ /* sage gem */
    gob->add_attribb(0, 30);
    gob->add_attribb(1, -20);
    gob->add_attribb(2, -15);
    gob->add_attribb(3, 30);
    gob->add_attribb(4, 40);
    gob->add_attribb(5, 30);
  }  
  else if(spec == 3 && ws == 20){ /* timeless gem */
    gob->add_attribb(0, 30);
    gob->add_attribb(2, 20);
  }
  else if(spec == 1 && ws == 33){ /* gem of combat skills */
    gob->add_attribb(0, 8);
    gob->add_attribb(1, 12);
    gob->add_attribb(2, 12);
    gob->add_attribb(3, 8);
  }
}

special_checks(object x, int aa, ab){
  gob = x;
  if(!gob) return;
  spec = aa;
  ws = ab;
  if(spec == 1 && ws == 1)      /* minor gem of agility */
    gob->add_attribb(0, -15);
  else if(spec == 2 && ws == 1) /* gem of agility */
    gob->add_attribb(0, -30);
  else if(spec == 3 && ws == 1) /* major gem of agility */
    gob->add_attribb(0, -50);
  else if(spec == 1 && ws == 2) /* minor gem of might */
    gob->add_attribb(1, -15);
  else if(spec == 2 && ws == 2) /* gem of might */
    gob->add_attribb(1, -30);
  else if(spec == 3 && ws == 2) /* major gem of might */
    gob->add_attribb(1, -50);
  else if(spec == 1 && ws == 3) /* minor gem of accuracy */
    gob->add_attribb(2, -15);
  else if(spec == 2 && ws == 3) /* gem of accuracy */
    gob->add_attribb(2, -30);
  else if(spec == 3 && ws == 3) /* major gem of accuracy */
    gob->add_attribb(2, -50);
  else if(spec == 1 && ws == 4) /* minor gem of vigor */
    gob->add_attribb(3, -15);
  else if(spec == 2 && ws == 4) /* gem of vigor */
    gob->add_attribb(3, -30);
  else if(spec == 3 && ws == 4) /* major gem of vigor */
    gob->add_attribb(3, -50);
  else if(spec == 1 && ws == 5) /* minor gem of wisdom */
    gob->add_attribb(4, -15);
  else if(spec == 2 && ws == 5) /* gem of wisdom */
    gob->add_attribb(4, -30);
  else if(spec == 3 && ws == 5) /* major gem of wisdom */
    gob->add_attribb(4, -50);
  else if(spec == 1 && ws == 6) /* minor gem of faith */
    gob->add_attribb(5, -15);
  else if(spec == 2 && ws == 6) /* gem of faith */
    gob->add_attribb(5, -30);
  else if(spec == 3 && ws == 6) /* major gem of faith */
    gob->add_attribb(5, -50);
  else if(spec == 1 && ws == 12){ /* minor gem of performance */
    gob->add_attribb(0, -5);
    gob->add_attribb(1, -10);
    gob->add_attribb(2, -10);
    gob->add_attribb(3, -5);
  }
  else if(spec == 2 && ws == 8){ /* gem of speed */
    gob->add_attribb(0, -30);
    gob->add_attribb(3, -30);
  }
  else if(spec == 2 && ws == 9){ /* gem of performance */
    gob->add_attribb(0, -10);
    gob->add_attribb(1, -17);
    gob->add_attribb(2, -17);
    gob->add_attribb(3, -10);
  }
  else if(spec == 3 && ws == 7){ /* major gem of performance */
    gob->add_attribb(0, -15);
    gob->add_attribb(1, -30);
    gob->add_attribb(2, -30);
    gob->add_attribb(3, -15);
  }
  else if(spec == 1 && ws == 14){ /* gem of fury */
    gob->add_attribb(0, -10);
    gob->add_attribb(2, 10);
    gob->add_attribb(3, -10);
  }
  else if(spec == 3 && ws == 18){ /* gem of battle rites */
    gob->add_attribb(0, -30);
    gob->add_attribb(1, -30);
    gob->add_attribb(2, -30);
    gob->add_attribb(3, -30);
    gob->add_attribb(4, 25);
    gob->add_attribb(5, 25);
  }
  else if(spec == 3 && ws == 19){ /* sage gem */
    gob->add_attribb(0, -30);
    gob->add_attribb(1, 20);
    gob->add_attribb(2, 15);
    gob->add_attribb(3, -30);
    gob->add_attribb(4, -40);
    gob->add_attribb(5, -30);
  }  
  else if(spec == 3 && ws == 20){ /* timeless gem */
    gob->add_attribb(0, -30);
    gob->add_attribb(2, -20);
  }
  else if(spec == 1 && ws == 33){ /* gem of combat skills */
    gob->add_attribb(0, -8);
    gob->add_attribb(1, -12);
    gob->add_attribb(2, -12);
    gob->add_attribb(3, -8);
  }
}


/*        usr       nmy    stype  spec   ws                */       
go(object f, object h, int k, int l, int m)
{
  usr = f;
  nmy = h;
  wep = usr->query_weapon();
  usr_room = environment(usr);
  stype = k;
  spec = l;
  ws = m;
  ths = usr->query_weapon();

  a = 0;
  b = 0;
  me = c((string)USER->query_real_name());
  nn = nmy->query_name();
  tt = ths->query_type();           if(!tt) tt = "weapon";
  he = USER->query_pronoun();
  his = USER->query_possessive();
  him = USER->query_objective();

/******************** GEM SPECIFIC SPECIAL ABILITIES ************************/

  if(stype == 1)         /** RUBY - FIRE **/
  {
    if(!random(4))
    {
      if(!present("bf_f_o", nmy))
      {
        ench = clone_object("/players/fred/closed/bloodfist/obj/fire_ench.c");
        ench->set(nmy);
        move_object(ench, nmy);
        TOU"A ball of flame explodes from your "+tt+" as you strike "+nn+
          "!\n\t"+RED+nn+" is engulfed in flames!\n"+NORM);
        TRU
          "A ball of flames explodes from "+me+"'s "+tt+" as "+he+
          " strikes "+nn+"!\n\t"+RED+nn+" is engulfed in flames!\n"+NORM,
          ({ USER }));
      }
      else 
      {
        TOU"Your "+tt+" ignites with fire as you strike "+nn+"!\n"+
          "There is a sudden "+RED+"EXPLOSION OF FLAMES"+NORM+
          " around "+nn+"!\n");
        TRU
          me+"'s "+tt+" ignites with fire as "+he+" strikes "+nn+"!\n"+
          "There is a sudden "+RED+"EXPLOSION OF FLAMES"+NORM+
          " around "+nn+"!\n", ({ USER }));
        nmy->hit_player(6, "other|fire");
      }
    }
  }

  else if(stype == 2)    /** EMERALD - POISON **/
  {
    if(!random(4))
    {
      if(!present("bf_f_p", nmy))
      {
        ench = clone_object("/players/fred/closed/bloodfist/obj/pois_ench.c");
        ench->set(nmy);
        move_object(ench, nmy);
        TOU"You lunge at "+nn+", piercing "+nmy->query_objective()+
          " with your "+tt+"...\n"+
          HIG+"The poison from your "+tt+" seeps into "+nn+"!\n"+NORM);
        TRU
          me+" lunges at "+nn+", piercing "+nmy->query_objective()+
          " with "+his+" "+tt+"...\n"+HIG+"The poison from "+
          me+"'s "+tt+" seeps into "+nn+"!\n"+NORM, ({ USER }));
        nmy->hit_player(4, "other|poison");
      }
      else
      {
        TRU HIG+"The poison eats its way through "+nn+"...\n"+NORM);
        nmy->hit_player(6, "other|poison");
      }
    }
  }

  else if(stype == 3)    /** SAPPHIRE - COLD **/
  {
    if(!random(6))
    {
      TOU"You swing your "+tt+" into "+nn+"...\n\t"+
        BLU+"A cold ice slowly spreads across "+nn+"!\n"+NORM);
      TRU
        me+" swings "+his+" "+tt+" into "+nn+"...\n\t"+
        BLU+"A cold ice slowly spreads across "+nn+"!\n"+NORM, ({ USER }));
      if(nmy->query_cold_enchantment())
        nmy->reapply();
      else
      {
        ench = clone_object("/players/fred/closed/bloodfist/obj/cold_shadow.c");
        ench->apply_cold_enchantment(nmy);
      }
    }
    else if(!random(6))
    {
      TOU"You swing your "+tt+" into "+nn+"...\n\t"+
        BLU+"Shards of ice explode in every direction!\n"+NORM);
      TRU
        me+" swings "+his+" "+tt+" into "+nn+"...\n\t"+
        BLU+"Shards of ice explode in every direction!\n"+NORM, ({ USER }));
      nmy->hit_player(2, "other|ice");
    }
    else if(!random(6))
    {
      TOU"You slash "+nn+" with your "+tt+"...\n\t"+
        BLU+"You rip open a gaping wound of frozen blood and ice!\n"+NORM);
      TRU
        me+" slashes "+nn+" with "+his+" "+tt+"...\n\t"+
        BLU+me+" rips open a gaping wound of frozen blood and ice!\n"+NORM,
        ({ USER }));
      nmy->hit_player(2, "other|ice");
    }
  }

                         /** DIAMOND - HOLY **/
  else if(stype == 4 && nmy->id("demon") || nmy->id("undead")
    || nmy->id("spirit") || nmy->id("daemon"))
  {
    TOU HIW+"Your "+tt+" shimmers as it cuts into "+nn+"!\n"+NORM);
    TRU HIW+
      me+"'s "+tt+" shimmers as it cuts into "+nn+"!\n"+NORM, ({ USER }));
    nmy->hit_player(random(4), "other|good");
  }

  else if(stype == 5)    /** ONYX - DARK **/
  {
    if(r(nmy->query_level()) == USER->query_level())
    {
      TOU"Your "+tt+" glows with a dark aura as you strike "+nn+"!\n");
      TRU
        me+"'s "+tt+" glows with a dark aura as "+he+" strikes "+nn+"!\n",
        ({ USER }));
      USER->add_spell_point(3);
      nmy->hit_player(3, "other|dark");
    }
    else if(!r(10))
    {
      TOU"Your "+tt+" emits a dark aura of energy!\n");
      TRU me+"'s "+tt+" emites a dark "+
        "aura of energy!\n", ({ USER }));
      USER->add_spell_point(2);
      nmy->hit_player(2, "other|dark");
    }
    else if(!r(6))
    {
      TOU "Your "+tt+" glows dark in your hand.\n");
      TRU me+"'s "+tt+" glows dark in "+his+
        " hand.\n", ({ USER }));
      USER->add_spell_point(1);
      nmy->hit_player(2, "other|dark");
    }
  }

  else if(stype == 6)    /** TOPAZ - LIGHT **/
  {
    if(!random(10))
    {
      TOU"Your "+tt+" glows bright in your hand...\n\n\t"+HIY+
        "An arc of lightning jumps from your "+tt+" striking "+nn+"!\n\n"+
        NORM);
      TRU me+"'s "+tt+" glows bright in "+his+
        " hand...\n\n\t"+HIY+"An arc of lightning jumps from "+his+" "+tt+
        " striking "+nn+"!\n\n"+NORM, ({ USER }));
      nmy->hit_player(8, "other|electric");
    }
  }

  else if(stype == 7)    /** AMETHYST - EARTH **/
  {
    if(!random(10))
    {
      TOU"Your "+tt+" shakes slightly in your hand...\n\n\t"+MAG+
        "Rocks fall from the sky pelting "+nn+"!\n\n"+
        NORM);
      TRU me+"'s "+tt+" shakes slightly in "+his+
        " hand...\n\n\t"+MAG+"Rocks fall from the sky pelting "+nn+"!\n\n"+
        NORM, ({ USER }));
      nmy->hit_player(8, "other|earth");
    }
  }

/********************* GEM SPECIFIC GENERAL EMOTES **************************/

  if(stype == 1)
  {
    col = RED;
    o = r(9);
    switch(o)
    {
    case 0:
      a = "Flames burn along your "+tt+".\n";
      b = "Flames burn along "+me+"'s "+tt+".\n";
      break;
    case 1:
      a = "Flames surge up from your "+tt+".\n";
      b = "Flames surge up from "+me+"'s "+tt+".\n";
      break;
    case 2:
      a = "An aura of flames can be seen around your "+tt+".\n";
      b = "An aura of flames can be seen around "+me+"'s "+tt+".\n";
      break;
    case 3:
      a = "Waves of fire leap up from your "+tt+".\n";
      b = "Waves of fire leap up from "+me+"'s "+tt+".\n";
      break;
    case 4:
      a = "Flames dance across your "+tt+".\n";
      b = "Flames dance across "+me+"'s "+tt+".\n";
      break;
    case 5:
      a = "Heat surges out from your "+tt+".\n";
      b = "Heat surges out from "+me+"'s "+tt+".\n";
      break;
    case 6:
      a = "Your "+tt+" burns with enchanted flames.\n";
      b = me+"'s "+tt+" burns with enchanted flames.\n";
      break;
    case 7:
      a = "Your "+tt+" eminates an aura of enchanted fire.\n";
      b = me+"'s "+tt+" eminates an aura of enchanted fire.\n";
      break;
    case 8:
      a = "The ruby in your "+tt+" glows softly.\n";
      b = "The ruby in "+me+"'s "+tt+" glows softly.\n";
      break;
    }
  }

  else if(stype == 2)
  {
    col = HIG;
    o = r(6);
    switch(o)
    {
    case 0:
      a = "Your "+tt+" eminates a greenish hue.\n";
      b = me+"'s "+tt+" eminates a greenish hue.\n";
      break;
    case 1:
      a = "The emerald in your "+tt+" glows softly.\n";
      b = "The emerald in "+me+"'s "+tt+" glows softly.\n";
      break;
    case 2:
      a = "You notice a strange liquid on the tip of your "+tt+".\n";
      b = "You notice a strange liquid on the tip of "+me+"'s "+tt+".\n";
      break;
    case 3:
      a = "An aura of poison can be felt around your "+tt+".\n";
      b = "An aura of poison can be felt around "+me+"'s "+tt+".\n";
      break;
    case 4:
      a = "Poison seeps from your "+tt+".\n";
      b = "Poison seeps from "+me+"'s "+tt+".\n";
      break;
    case 5:
      a = "Poison drips down your "+tt+".\n";
      b = "Poison drips down "+me+"'s "+tt+".\n";
      break;
    }
  }

  else if(stype == 3)
  {
    col = BLU;
    o = r(9);
    switch(o)
    {
    case 0:
      a = "The sapphire in your "+tt+" glows softly.\n";
      b = "The sapphire in "+me+"'s "+tt+" glows softly.\n";
      break;
    case 1:
      a = "A chill shoots through your body.\n";
      b = "You notice "+me+" shiver from the cold.\n";
      break;
    case 2:
      a = "Your "+tt+" makes the air around it cold.\n";
      b = me+"'s "+tt+" makes the air around it cold.\n";
      break;
    case 3:
      a = "You notice a thin layer of ice around your "+tt+".\n";
      b = "You notice a thin layer of ice around "+me+"'s "+tt+".\n";
      break;
    case 4:
      a = "You are chilled by the cold air surrounding your "+tt+".\n";
      b = "You are chilled by the cold air surrounding "+me+"'s "+tt+".\n";
      break;
    case 5:
      a = "Cold air flows around you.\n";
      b = "Cold air flows around "+me+".\n";
      break;
    case 6:
      a = "Your "+tt+" glows with a chilled aura of power.\n";
      b = me+"'s "+tt+" glows with a chilled aura of power.\n";
      break;
    case 7:
      a = "You notice a soft blue glow eminating from the sapphire in your "+
        tt+".\n";
      b = "You notice a soft blue glow eminating from the sapphire in "+me+
        "'s "+tt+".\n";
      break;
    case 8:
      a = "Your "+tt+" glows with a soft blue light.\n";
      b = me+"'s "+tt+" glows with a soft blue light.\n";
      break;
    }
  }

  else if(stype == 4)
  {
    col = HIW;
    o = r(4);
    switch(o)
    {
    case 0:
      a = "Your "+tt+" eminates a holy aura of power.\n";
      b = me+"'s "+tt+" eminates a holy aura of power.\n";
      break;
    case 1:
      a = "The diamond in your "+tt+" glows softly.\n";
      b = "The diamond in "+me+"'s "+tt+" glows softly.\n";
      break;
    case 2:
      a = "You feel a holy energy surge from your "+tt+".\n";
      b = "You notice "+me+"'s "+tt+" surge with holy energy.\n";
      break;
    case 3:
      a = "Your "+tt+" glows with the strength of the righteous.\n";
      b = me+"'s "+tt+" glows with the strength of the righteous.\n";
      break;
    }
  }

  else if(stype == 5)
  {
    col = BOLD+BLK;
    o = r(5);
    switch(o)
    {
    case 0:
      a = "Your "+tt+" glows with a dark aura.\n";
      b = me+"'s "+tt+" glows with a dark aura.\n";
      break;
    case 1:
      a = "The onyx gem in your "+tt+" glows softly.\n";
      b = "The onyx gem in "+me+"'s "+tt+" glows softly.\n";
      break;
    case 2:
      a = "Waves of dark energy seem to flow from your "+tt+".\n";
      b = "Waves of dark energy seem to flow from "+me+"'s "+tt+".\n";
      break;
    case 3:
      a = "Your "+tt+" seems to absorb the light.\n";
      b = me+"'s "+tt+" seems to absorb the light.\n";
      break;
    case 4:
      a = "A dark aura is visible around your "+tt+".\n";
      b = "A dark aura is visible around "+me+"'s "+tt+".\n";
      break;
    }
  }

  else if(stype == 6)
  {
    col = HIY;
    o = r(6);
    switch(o)
    {
    case 0:
      a = "Your "+tt+" glows with an aura of light.\n";
      b = me+"'s "+tt+" glows with an aura of light.\n";
      break;
    case 1:
      a = "The topaz gem in your "+tt+" glows softly.\n";
      b = "The topaz gem in "+me+"'s "+tt+" glows softly.\n";
      break;
    case 2:
      a = "Your "+tt+" seems to exude light.\n";
      b = me+"'s "+tt+" seems to exude light.\n";
      break;
    case 3:
      a = "An aura of light is visible around your "+tt+".\n";
      b = "An aura of light is visible around "+me+"'s "+tt+".\n";
      break;
    case 4:
      a = "Your "+tt+" glows warm with light.\n";
      b = me+"'s "+tt+" glows warm with light.\n";
      break;
    case 5:
      a = "Beams of light escape from the topaz gem in your "+tt+".\n";
      b = "Beams of light escape from the topaz gem in "+me+"'s "+tt+".\n";
      break;
    }
  }
  
  if(a && b)
  {
    TOU col+a+NORM);
    TRU col+a+NORM, ({ USER }));
  }

/********************* SPECIAL GEM EMOTES ***********************************/

  if(spec == 1 && ws == 7) /* prismatic gem */
  {
   o = r(31);
    switch(o)
    {
    case 0:
      TOU RED+
        "                                                    *  *      *\n"+
        "                                                *    *      *    \n"+
        "                                             * ** *  *   *  *  \n"+
        "                                         ** ** *  *  *  *\n"+
        "                                     *** **   *   * *    \n"+NORM+
        " Flames erupt from your "+tt+RED+" ** ** *  * *\n"+
        "                                    *  ** * *   *   *   \n"+
        "                                      **  *  *  *    *    *   \n"+
        "                                         *  **   *   *   *   *  * \n"+
        "                                             *    *       *    *  \n"+
        "                                                    *  *      *\n"+
        "\n"+NORM);
      TRU RED+
        "                                                    *  *      *\n"+
        "                                                *    *      *    \n"+
        "                                             * ** *  *   *  *  \n"+
        "                                         ** ** *  *  *  *\n"+
        "                                     *** **   *   * *    \n"+NORM+
        " Flames erupt from "+me+"'s "+tt+RED+" ** ** *  * *\n"+
        "                                    *  ** * *   *   *   \n"+
        "                                      **  *  *  *    *    *   \n"+
        "                                         *  **   *   *   *   *  * \n"+
        "                                             *    *       *    *  \n"+
        "                                                    *  *      *\n"+
        "\n"+NORM, ({ USER }));
      nmy->hit_player(6, "other|fire");
      break;
    case 1:
      TOU BLU+"A pillar of water shoots out from your "+tt+"!\n"+
        nn+" is sent flying back from the incredible blow!\n"+NORM);
      TRU BLU+
        "A pillar of water shoots out from your "+tt+"!\n"+
        nn+" is sent flying back from the incredible blow!\n"+NORM,
        ({ USER }));
      nmy->hit_player(5, "other|water");
      break;
    case 2:
      TOU"A lance of ice flies into "+nn+"!\n\n"+HIB+
        "        -------\n"+
        "             ----------------    -----------------------\n"+
        "        ------------      --------------   -------   ----------\n"+
        "      -----\n"+
        "\n\n"+NORM);
      TRU"A lance of ice flies into "+nn+"!\n\n"+HIB+
        "        -------\n"+
        "             ----------------    -----------------------\n"+
        "        ------------      --------------   -------   ----------\n"+
        "      -----\n"+
        "\n\n"+NORM, ({ USER }));
      nmy->hit_player(6, "other|ice");
      break;
    case 3:
      TRU HIY+
        "A bolt of lightning shoots up through "+nn+
        " and into the sky!\n"+NORM);
      nmy->hit_player(4, "other|electric");
      break;
    case 4:
      TRU
        "Tiny stones fly at "+nn+BOLD+BLK+"!         *\n"+
        "                         *                          *\n"+
        "             *                            *               *\n"+
        "                                     *\n"+NORM);
      TRU BOLD+BLK+
        "                       *                          *\n\n"+NORM);
      nmy->hit_player(4, "other|earth");
      break;
    case 5..30:
      break;
    }
  }

  else if(spec == 1 && ws == 8) /* gem of decay */
  {
    if(!random(3))
    {
      TOU"The gem of decay in your "+tt+" emits a subtle black aura.\n");
      TRU
        me+"'s "+tt+" emits a subtle black aura.\n", ({ USER }));
      USER->add_spell_point(1);
    }
    if(nmy->query_hit_point() < 50 && nmy->query_mhp() > 300+random(100) &&
      nmy->is_npc())
    {
      TOU"\nYour "+tt+" emits a black aura of decay...\n"+
        "The aura consumes "+nn+" as "+nmy->POS+" strength is absorbed.\n");
      TRU "\n"+me+"'s "+tt+" emits a black aura of decay...\n"+
        "The aura consumes "+nn+" as "+nmy->POS+" strength is absorbed.\n",
        ({ USER }));
      nmy->heal_self(-500);
      nmy->hit_player(500, "other|fred");
      call_out("finish",2);
      return 1;
    }
  }

  else if(spec == 1 && ws == 9) /* chaos gem */
  {
    string *nmymsgs, newmsg;

    if(!random(5))
    {
      nmymsgs = nmy->query_message_hit(random(33));
      newmsg = nn+" "+nmymsgs[1]+" "+nn+nmymsgs[0]+".\n";
      if(!random(8))
        TRU nn+" suddenly looks confused.\n");
      TRU newmsg);
      nmy->hit_player(6);
    }
    if(!random(5))
    {
      object rock;
      o = r(28);
      switch(o)
      {
      case 0:
        a = "You notice a flock of birds flying overhead.\n";
        break;
      case 1:
        a = "You suddenly feel like getting naked.\n";
        break;
      case 2:
        a = "A vortex opens above you in the air.\n"+
          "A small rock falls from it hitting you in the head.\n";
        rock = clone_object("/obj/treasure.c");
        rock->set_weight(1);
        rock->set_value(5);
        rock->set_name("rock");
        rock->set_short("A small rock");
        rock->set_long("This is a small brown rock that fell from the sky.\n");
        move_object(rock, environment(USER));
        break;
      case 3:
        a = HIM+"A flash of purple blinds you momentarily.\n"+NORM;
        break;
      case 4:
        a = HIY+"The sun shines high in the sky.\n"+NORM;
        break;
      case 5:
        a = BOLD+"You step left.\n"+
          "You step right.\nYou jump up and down!\n"+NORM;
        break;
      case 6:
        a = "You notice a trail of ants walking past your feet.\n";
        break;
      case 7:
        a = "A big "+HIR+"red ball "+NORM+"bounces past you.\n";
        break;
      case 8:
        a = "You notice some "+HIW+"white stuff"+NORM+
          " hanging from your ear.\n";
        break;
      case 9:
        a = "You laugh outloud.\n";
        break;
      case 10:
        a = "You scratch behind your ear.\n";
        break;
      case 11:
        a = "All of a sudden pow and then nothing.\n";
        break;
      case 12:
        a = "A leopard licks you and then is gone.\n";
        break;
      case 13:
        a = "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n";
        break;
      case 14:
        a = "A "+HIY+"spiral of light"+NORM+" trails through the air.\n";
        break;
      case 15:
        a = "You notice the "+BOLD+BLK+"Shadows"+NORM+" shifting about.\n";
        break;
      case 16:
        a = "Fred tells you: hit 'em, hit 'em hard!\n";
        break;
      case 17:
        a = "Fred tells you: i'm snooping you\n";
        break;
      case 18:
        a = "You jump up and down excitedly as your breasts jiggle.\n";
        break;
      case 19:
        a = "Never before have you felt so much love for peewee soccer.\n";
        break;
      case 20:
        a = "You hear a voice in your head: Stop coding and get to work!\n";
        break;
      case 21:
        a = "If your name was Dick Hajny how would you feel?\n";
        break;
      case 22:
        a = HIG+"Suddenly visions of moss consume your thoughts!\n"+NORM;
        break;
      case 23:
        a = GRN+"You find yourself wondering if "+
          "the grass really is greener.\n"+NORM;
        break;
      case 24:
        a = HIC+"You pull out a thermos and drink some water.\n"+NORM;
        break;
      case 25:
        a = "  E\n   M\n    I\n     L\n      I\n       O\n";
        break;
      case 26:
        a = "Your appreciation of anime continues to grow.\n";
        break;
      case 27:
        a = "You search the area but find nothing.\n";
        break;
      }
      TRU a);
    }

    if(!random(12))
    {
      gold = clone_object("/obj/money.c");
      gold->set_money(random(120));
      move_object(gold, environment(USER));
      TRU
        "A small rift opens in the fabric of time and space.\n"+
        "A few "+HIY+"gold coins"+NORM+" fall from the "+ 
        "rift as it collapses in on itself.\n");
    }
    else if(!random(100))
    {
      int g, sg;
      object *env;
      env = all_inventory(environment(USER));
      sg = sizeof(env);
      o = r(5);
      switch(o)
      {
      case 0:
        a = HIM+"WAAAAAAZZZOOOOOOMMMMMMMMYYYYYYYYY!!!!!";
        break;
      case 1:
        a = MAG+"ZAZZAAAAAFFFLLLLAAAAAAAZZZZZZYYYYY!!!!";
        break;
      case 2:
        a = HIB+"UUUOOOOMMMMMMKKKKKAAAAAMMMAAAPPAAAA!!!!";
        break;
      case 3:
        a = YEL+"EEESSSSKKKAAAAFLLLLLOOOOWWWNNNNEEEEE!!";
        break;
      case 4:
        a = GRN+"QQQUUIIIITTTTYYYYYEEEERRRRBIIIITTTTCHHNNN!!!!";
        break;
      }
      TRU "\n\n "+a+"\n\n\n"+NORM);

/*
      for(g = 0; g < sg; g++)
      {
        env[g]->stop_fight();
        env[g]->stop_fight();
        env[g]->stop_hunter();
      }
*/
    }
    else if(!random(100))
    {
      object little;
      little = clone_object("/obj/monster.c");
      little->set_wc(5);
      little->set_ac(2);
      little->set_hp(20);
      little->set_level(3);
      o = random(4);
      switch(o)
      {
      case 0:
        little->set_name("fuzzy");
        little->set_short("A fuzzy");
        little->set_long("This is a cute little fuzzy.  "+
          "You want to give it your love.\n");
        little->set_chat_chance(5);
        little->load_chat("The fuzzy blows around in the wind.\n");
        break;
      case 1:
        little->set_name("oomy");
        little->set_short("A long but very cute oomy");
        little->set_long(
          "As everyone knows, this is an oomy.  It's a little longer than\n"+
          "your average oomy but it doesn't seem to care.  It's still cute\n"+
          "as a button.\n");
        little->set_chat_chance(5);
        little->load_chat("The oomy purrs at you.\n");
        break;
      case 2:
        little->set_name("frank");
        little->set_short("Frank the farmer");
        little->set_alias("farmer");
        little->set_long(
          "This if Frank the farmer.  He looks a little confused and seems\n"+
          "to be looking around as though he's not sure where he is.\n");
        little->set_chat_chance(5);
        little->load_chat("Frank looks around confusedly.\n");
        break;
      case 3:
        little->set_name("nun");
        little->set_short("A catholic nun");
        little->set_long("This is a stern looking catholic nun.\n"+
          "She is wearing a long black robe.\n");
        little->set_chat_chance(5);
        little->load_chat("The nun frowns at you.\n");
        break;
      }
      TRU "You feel a shift in the fabric of space.\n");
      move_object(little, environment(USER));
      o = r(4);
      switch(o)
      {
      case 0:     little->attack_object(USER);     break;
      case 1:     little->attack_object(nmy);      break;
      case 2..3:                                   break;
      }
    }
  }

  else if(spec == 1 && ws == 10)  /* gem of purity */
  {
    USER->add_alignment(10000);
    if(present("poison", USER))
      destruct(present("poison", USER));
    if(nmy->query_alignment() < -100)
    {
      if(!random(3))
      {
        write("Your "+tt+" glows hot as you strike "+nn+".\n");
        tell_room(environment(USER), me+
          "'s "+tt+" glows hot as "+he+" strikes "+nn+".\n");
        nmy->hit_player(3, "other|good");
      }
    }
  }

  else if(spec == 1 && ws == 11) /* gem of hatred */
  {
    USER->add_alignment(-10000);
    if(nmy->query_alignment() > 100)
    {
      if(!random(3))
      {
        write("Your "+tt+" glows hot as you strike "+nn+".\n");
        tell_room(environment(USER), me+
          "'s "+tt+" glows hot as "+he+" strikes "+nn+".\n");
        nmy->hit_player(3, "other|evil");
      }
    }
  }

  else if(spec == 1 && ws == 13) /* gem of beauty */    
  { 
    int z;
    z = 0;
    if(!random(5))
    {
      a = first_inventory(environment(USER));
      while(a)
      {
        b = next_inventory(a);
        if(a->query_bf_mob())
        {
           z++;
        }
        a = b;
      }
      if(z < 2 && !random(3) && USER->query_gender() == "female")
      {
        TOU "One of your adoring fans arrives!!\n");
        TRU "One of "+me+"'s adoring fans arrives!!!\n", ({ USER }));
         c = clone_object("/players/fred/closed/bloodfist/NPC/person.c");
        if(!random(2))
         c = clone_object("/players/fred/closed/bloodfist/NPC/person1.c");
        c->patch_owner(USER);
        move_object(c, environment(USER));
      }
      if(z < 2 && !random(3) && USER->query_gender() == "male") 
      {
        TOU "One of your adoring fans arrives!!\n");
        TRU "One of "+me+"'s adoring fans arrives!!!\n", ({ USER }));
         c = clone_object("/players/fred/closed/bloodfist/NPC/person2.c");
        if(!random(2))
         c = clone_object("/players/fred/closed/bloodfist/NPC/person3.c");
        c->patch_owner(USER);
        move_object(c, environment(USER));   
      }
    }
  }

  else if(spec == 1 && ws == 14) /* gem of fury */
  {
    int ac;
    ac = USER->query_ac() / 2;
    if(!random(ac+3))
    {
      write(HIW+"Your motions blur as you strike "+nn+".\n"+NORM+
        nn+" is sent reeling by the massive attack.\n");
      tell_room(environment(USER), HIW+me+
        "'s motions blur as "+he+" strikes "+nn+".\n"+NORM+
        nn+" is sent reeling by the massive attack.\n", ({ USER }));
      if(ac < 6)
        nmy->hit_player(14);
      else if(ac < 10)
        nmy->hit_player(10);
      else if(ac < 15)
        nmy->hit_player(6);
      else
        nmy->hit_player(3);
    }
    if(!random(4))
    {
      write(HIW+"Your movements blur as you fight "+nn+".\n"+NORM);
      tell_room(environment(USER), HIW+me+
        "'s movements blur as "+he+" fights "+nn+".\n"+NORM, ({ USER }));
      USER->heal_self(-1);
    }
  }

  else if(spec == 1 && ws == 15) /* gem of eternity */
  {
    if(!random(3))
    {
      cnt++;
      thp += USER->query_hp();
      ahp = thp / cnt;
      tsp += USER->query_sp();
      asp = tsp / cnt;

      if(!random(3) && ahp < USER->query_hp() && asp < USER->query_spell_point())
      {
        TOU"A dark glow flows from your "+tt+" into you...\n"+
          BOLD+BLK+"The warmth of eternity spreads through your body.\n"+NORM);
        TRU
          "A dark glow flows from "+me+"'s "+tt+" into "+him+".\n",
          ({ USER }));
        if(!random(2))
          USER->add_hit_point(r(ahp - USER->query_hp()));
        else
          USER->add_spell_point(r(asp - USER->query_spell_point()));
      }
      else if(!random(300))
      {
        TOU"A sudden flash of black consumes your vision...\n\n\t\t\t"+
          BOLD+BLK+"...You see stars...\n\n"+NORM+
          "Your vision suddenly returns to normal.\n");
        TRU
          "A flash of black consumes "+me+"'s vision.\n", ({ USER }));
        thp = 0;
        tsp = 0;
        USER->heal_self(-10);
      }
    }
  }

  else if(spec == 1 && ws == 16) /* vortex gem */
  {
    if(sizeof_locs > 50)
      sizeof_locs = 0;
    if(!random(20))
    {
      if((sizeof(locs) && index(locs, file_name(environment(USER))) < 0)
        || !sizeof_locs)
      {
        if(environment(USER)->realm() != "NM" &&
          environment(USER)->realm() != "NT" &&
          !environment(USER)->query_no_fight())
        {
          write(HIY+"Your "+tt+" quivers in your hand.\n"+NORM);
          tell_room(environment(USER), HIY+me+
            "'s "+tt+" quivers in "+his+" hand.\n"+NORM, ({ USER }));
          locs[sizeof_locs] = file_name(environment(USER));
          sizeof_locs++;
        }
      }
    }
    else if(sizeof_locs && !random(20))
    {
      env = all_inventory(environment(USER));
      so = sizeof(env);
      p = r(sizeof_locs);
      while(locs[p] == file_name(environment(USER)) && sizeof_locs > 1)
        p = r(sizeof_locs);
      if(locs[p] != file_name(environment(USER)) &&
        environment(USER)->realm() != "NM" &&
        environment(USER)->realm() != "NT" &&
        !environment(USER)->query_no_fight())
      {
        if((loc = find_object(locs[p])))
        {
          write(HIY+"\nA blinding flash of light erupts outward...\n\n"+NORM+
            "\tA vortex appears before you.\n"+
            "\tYou feel helpless to it's power.\n"+
            "\tSuddenly you are within the vortex.\n\n");
          tell_room(environment(USER), HIY+
            "\nA blinding flash of light erupts outward...\n\n"+NORM,
            ({ USER }));
          for(o = 0; o < so; o++)
          {
            if(env[o]->query_attack() == USER)
            {
              tell_room(environment(USER), HIY+env[o]->query_name()+
                " vanishes in a bright flash of light.\n"+NORM,
                ({ USER }));
              write(HIY+env[o]->query_name()+
                " is pulled into the vortex.\n"+NORM);
              move_object(env[o], loc);
            }
          }
          write("\nAnd then you are elsewhere...\n\n");
          this_player()->move_player("in a flash#"+locs[p]);
        }
      }
    }
  }

  else if(spec == 1 && ws == 17) /* lightning gem */
  {
    o = random(20);
    switch(o)
    {
    case 0:
      TOU HIY+"Lightning ripples along your "+tt+".\n"+NORM);
      TRU HIY+
        "Lightning ripples along "+me+"'s "+tt+".\n"+NORM, ({ USER }));
      break;
    case 1:
      TOU HIY+"A circle of lightning explodes from your "+tt+".\n"+NORM);
      TRU HIY+
      "A circle of lightning explodes from "+me+"'s "+tt+".\n"+NORM,
      ({ USER }));
      break;
    case 2:
      TOU HIY+"Your "+tt+" glows with an aura of crackling energy.\n"+NORM);
      TRU HIY+me+"'s "+tt+
        " glows with an aura of crackling energy.\n"+NORM, ({ USER }));
      break;
    case 3:
      TOU HIY+
        "\t       ********************************\n"+
        "\t   *                                      *\n"+
        "\tYou strike "+nn+" with an explosion of lightning!\n"+
        "\t   *                                      *\n"+
        "\t       ********************************\n"+NORM);
      TRU HIY+
        "\t       ********************************\n"+
        "\t   *                                      *\n"+
        "\t"+me+" strikes "+nn+" with an explosion of lightning!\n"+
        "\t   *                                      *\n"+
        "\t       ********************************\n"+NORM, ({ USER }));
      nmy->hit_player(10, "other|electric");
      break;
    case 4:
      TRU HIY+
      "    \\\n"+
      "     \\\n"+
      "     |\n"+
      "      \\"+NORM+"       Lightning erupts from the sky!\n"+HIY+
      "       |\n"+
      "       /\\\n"+
      "      /  |\n"+
      "     |    \\"+NORM+"        "+nn+" is wracked by the bolt!\n"+HIY+
      "     |     |\n");
      TRU "     /     /\\\n"+
      "    /|     | \\\n"+
      "   /  \\   / \\ \\"+NORM+"\n\n"+NORM);
      nmy->hit_player(10, "other|electric");
      break;
    case 5..19:
      break;
    }
  }

  else if(spec == 1 && ws == 18) /* gem of unholy death rites */
  {
    if(random(3))
      USER->add_hit_point(-1);
    if(nmy->query_alignment() > 100 && random(3))
    {
      TOU BOLD+BLK+"Your "+tt+" pulsates in your hand.\n"+NORM);
      TRU BOLD+BLK+me+"'s "+tt+
        " pulsates in "+his+" hand.\n"+NORM, ({ USER }));
      if(nmy->is_npc())
        nmy->heal_self(-1);
      else
        nmy->add_hit_point(-1);
      USER->add_spell_point(1);
    }
    if(corpse = present("corpse", environment(USER)))
    {
      string cshort, cn, clong;
      o = r(6);
      cn = corpse->query_name();
      switch(o)
      {
      case 0:
        cshort = "The horribly mutilated and burned remains of "+cn+".\n";
        break;
      case 1:
        cshort = "A pile of gore that was once "+cn+".\n";
        break;
      case 2:
        cshort = "A bloody pile of "+cn+"'s remains.\n";
        break;
      case 3:
        cshort = "The scorched remains of "+cn+".\n";
        break;
      case 4:
        cshort = "The gooey and black remains of "+cn+".\n";
        break;
      case 5:
        cshort = "A mess of blood and bones that was "+cn+".\n";
        break;
      }
      corpse->set_short(cshort);
      corpse->set_long(
        "These are the mutilated remains of "+cn+".  They sit loosely\n"+
        "in a pile on the ground, blood slowly seeping into the ground.\n"+
        "Black patches have been burnt into solid chunks of flesh and\n"+
        "blood mixed among the bones.  A horrible smell wafts up from\n"+
        "the remains.\n");
    }
  }

  else if(spec == 1 && ws == 19) /* gem of fortitude */
  {
    if(!r(3))
    {
      o = r(3);
      switch(o)
      {
        case 0:
          TOU GRN+"Your mind races as pain shoots through you're body!\n"+NORM);
          TRU GRN+me+
            "'s mind races as pain shoots through "+USER->POS+" body!\n"+NORM, ({ USER }));
          break;
        case 1:
          TOU BOLD+BLK+"Your fighting skills are magnified by the pains of battle.\n"+NORM);
          TRU BOLD+BLK+me+
            "'s fighting skills are magnified by the pains of battle.\n"+NORM, ({ USER }));
          break;
        case 2:
          TOU HIR+"Pain amplifies your senses.\n"+NORM);
          TRU HIR+
            "Pain amplifies "+me+"'s senses.\n"+NORM, ({ USER }));
        break;
      } 
    } 
  }
 
  else if(spec == 1 && ws == 20) /* gem of moss */
  {
    o = r(14);
    switch(o)
    {
    case 0:
      TOU GRN+"A piece of moss falls from your "+tt+".\n"+NORM);
      TRU GRN+
        "A piece of moss falls from "+me+"'s "+tt+".\n"+NORM, ({ USER }));
      break;
    case 1:
      TRU GRN+
        "Little pieces of moss go flying!\n"+NORM);
      break;
    case 2:
      TRU GRN+
        "A chunk of moss flies right at "+nn+"!\n"+NORM);
      nmy->hit_player(10);
      break;
    case 3:
      TOU GRN+"You clutch at your moss-coated "+tt+".\n"+NORM);
      TRU GRN+me+
        " clutches at "+his+" moss-coated "+tt+".\n", ({ USER }));
      break;
    case 4:
      TOU GRN+"The moss on your "+tt+" is kind of squishy.\n"+NORM);
      TRU GRN+
        "The moss on "+me+"'s "+tt+" squishes in "+his+" hand.\n"+NORM,
        ({ USER }));
      break;
    case 5..13:
      break;
    }
  }

  else if(spec == 1 && ws == 21) /* gem of rain */
  {
    o = r(18);
    switch(o)
    {
    case 0:
      tell_room(environment(USER),
        HIC+"A light rain falls from the sky.\n"+NORM);
      break;
    case 1:
      tell_room(environment(USER),
        HIC+"You feel the rain against your face.\n"+NORM);
      break;
    case 2:
      tell_room(environment(USER),
        HIC+"Rain is pouring down all around you.\n"+NORM);
      break;
    case 3:
      tell_room(environment(USER),
        HIC+"Water pools around your feet.\n"+NORM);
      break;
    case 4:
      tell_room(environment(USER),
        HIC+"A stream of water runs across the ground.\n"+NORM);
      break;
    case 5:
      tell_room(environment(USER),
        HIC+"Water pours from "+USER->query_name()+"'s "+tt+".\n"+NORM,
        ({ USER }));
      tell_object(USER, HIC+"Water pours from your "+tt+".\n"+NORM);
      break;
    case 6:
      tell_room(environment(USER),
        HIC+"You feel soaked to the bone.\n"+NORM);
      break;
    case 7:
      tell_room(environment(USER),
        HIC+"A soft rainfall is falling all around you.\n"+NORM);
      break;
    case 8..17:
      break;
    }
  }

  else if(spec == 1 && ws == 22) /* gem of idiocy */
  {
    o = r(18);
    switch(o)
    {
    case 0:
      tell_object(nmy, "You laugh outloud.\n");
      tell_room(environment(USER), nmy->query_name()+
        " laughs outloud.\n", ({ nmy }));
      break;
    case 1:
      tell_object(nmy, "You giggle inanely.\n");
      tell_room(environment(USER), nmy->query_name()+
        " giggles inanely.\n", ({ nmy }));
      break;
    case 2:
      tell_object(nmy, "You snicker.\n");
      tell_room(environment(USER), nmy->query_name()+
        " snickers.\n", ({ nmy }));
      break;
    case 3:
      tell_object(nmy, "You grab your sides as you laugh.\n");
      tell_room(environment(USER), nmy->query_name()+
        " grabs "+nmy->POS+" sides as "+nmy->PRO+" laughs.\n", ({ nmy }));
      break;
    case 4:
      tell_object(nmy, "You find everything to be so funny.\n");
      tell_room(environment(USER), nmy->query_name()+
        " seems very amused.\n", ({ nmy }));
      break;
    case 5:
      tell_object(nmy, "You drool slightly.\n");
      tell_room(environment(USER), nmy->query_name()+
        " drools slightly.\n", ({ nmy }));
      break;
    case 6:
      tell_object(nmy, "You trip over yourself and laugh.\n");
      tell_room(environment(USER), nmy->query_name()+
        " trips and laughs.\n", ({ nmy }));
      break;
    case 7..17:
      break;
    } 
  }

  else if(spec == 1 && ws == 23) /* gem of emotion */
  {
    string *rr;
    string verb, arg;
#ifdef __LDMUD__
    string cn;
#endif
    arg = lower_case(nn);
    rr = get_dir("/bin/soul/");
    cn = rr[random(sizeof(rr))];
#ifndef __LDMUD__ /* Rumplemintz */
    verb = cn[1..-3];
#else
    verb = cn[1..<3];
#endif
    TOU"\n");
    TRU"\n", ({ USER}));
    (int)call_other("/bin/soul/"+cn+"", "cmd_"+verb+"", arg);
    TOU"\n");
    TRU"\n", ({USER}));
/*
    o = r(18);
    switch(o)
    {
    case 0: command("smile", USER);  break;
    case 1: command("laugh", USER);  break;
    case 2: command("cry", USER);    break;
    case 3: command("sigh", USER);   break;
    case 4: command("wiggle", USER); break;
    case 5: command("snort", USER);  break;
    case 6: command("spit", USER);   break;
    case 7: command("yawn", USER);   break;
    case 8..17: break;
    }
*/
  }
  
  else if(spec == 1 && ws == 24) /* minor gold gem */
  {
    if(!r(30))
    {
      object gold;
      gold = clone_object("/obj/money.c");
      gold->set_money(random(50));
      move_object(gold, environment(USER));
      TRU "A small rift opens in the fabric of time and space.\n"+
        "A few "+HIY+"gold coins"+NORM+" fall from the "+ 
        "rift as it collapses in on itself.\n");
    }
  }
 
  else if(spec == 1 && ws == 25) /* minor gem of regen */
  {
    if(!random(5))
    {
      tell_object(USER, HIC+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIC+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->add_hit_point(2);
    }
  }

  else if(spec == 1 && ws == 26) /* minor gem of rejuv */
  {
    if(!random(5))
    {
      tell_object(USER, HIM+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIM+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->add_spell_point(2);
    }
  }

  else if(spec == 1 && ws == 27) /* minor gem of restoration */
  {
    if(!random(5))
    {
      tell_object(USER, HIM+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIM+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->heal_self(2);
    }
  }

  else if(spec == 1 && ws == 28) /* gem of instability */
  {
    if(!random(30))
    {
      a = first_inventory(environment(USER));
      while(a)
      {
        b = next_inventory(a);
        if(a->is_kid() || a->is_pet() && !random(5))
        {
          TOU "Energy flares from your "+BOLD+YEL+tt+NORM+" causing "+a->query_name()+" to attack you...\n");
          TRU 
            "Energy flares from "+me+"'s "+BOLD+YEL+tt+NORM+" causing "+a->query_name()+" to attack "+me->query_objective()+"...\n", ({ USER }));
          a->attack_object(me); 
        }
        a = b;
      }
    }   
  }

  else if(spec == 1 && ws == 29) /* fairie gem */
  {
    int qx;
    qx = 0;
    if(!random(3))
    {
      a = first_inventory(environment(USER));
      while(a)
      {
        b = next_inventory(a);
        if(a->query_bf_faerie())
          qx += 1;
       a = b;
      }
      if(qx < 3)
      {
        TOU "Your "+BOLD+BLU+tt+NORM+" shakes with an iridescent "+BOLD+YEL+"glow"+NORM+" as a "+CYN+"faerie"+NORM+" enters the room!\n");
          TRU me+
            "'s "+BOLD+BLU+tt+NORM+" shakes with an iridescent "+BOLD+YEL+"glow"+NORM+" as a "+CYN+"faerie"+NORM+" enters the room!\n", ({ USER }));
          c = clone_object("/players/fred/closed/bloodfist/NPC/faerie.c");
          c->patch_owner(USER);
          move_object(c, environment(USER));
      }
    }
  }

  else if(spec == 1 && ws == 30) /* gem of pk */
  {
    if(!random(3))
    {
      tell_object(USER, RED+"Your "+tt+" glows blood red.\n"+NORM);
      tell_room(environment(USER), 
        RED+me+"'s "+tt+" glows blood red.\n"+NORM, ({ USER }));
      nmy->heal_self(-2);
      USER->heal_self(2);
    }
  }

  else if(spec == 1 && ws == 31) /* gem of winter */
  {
    string ldesc, sdesc;
    sdesc = (string)nmy->short();
    ldesc = (string)nmy->query_long();
    if(!nmy->query_long())
    { 
      if(text_contains(sdesc, "fire") || text_contains(sdesc, "flame")
      || text_contains(sdesc, "hot") || text_contains(sdesc, "heat")
      || text_contains(sdesc, "flames") || text_contains(sdesc, "fires")
      && !nmy->is_player())
      {
        tell_room(environment(USER), BLU+"Winter storms consume "+
          nmy->query_name()+"!\n"+NORM);
        nmy->hit_player(10, "other|ice");
      }
    }
    else if(!nmy->short())
    {
      if(text_contains(ldesc, "fire") || text_contains(ldesc, "flame")
      || text_contains(ldesc, "hot") || text_contains(ldesc, "heat")
      || text_contains(ldesc, "flames") || text_contains(ldesc, "fires")
      && !nmy->is_player())
      {
        tell_room(environment(USER), BLU+"Winter storms consume "+
          nmy->query_name()+"!\n"+NORM);
        nmy->hit_player(10, "other|ice");
      }
    }  
    else
    {
      if(text_contains(sdesc, "fire") || text_contains(sdesc, "flame")
        || text_contains(sdesc, "hot") || text_contains(sdesc, "heat")
        || text_contains(sdesc, "flames") || text_contains(sdesc, "fires") 
        || text_contains(ldesc, "fire") || text_contains(ldesc, "flame")
        || text_contains(ldesc, "hot") || text_contains(ldesc, "heat")
        || text_contains(ldesc, "flames") || text_contains(ldesc, "fires")
        && !nmy->is_player())
      {
        tell_room(environment(USER), BLU+"Winter storms consume "+
          nmy->query_name()+"!\n"+NORM);
        nmy->hit_player(10, "other|ice");
      }
    }
  }

  else if(spec == 1 && ws == 32) /* minor gem of cleansing */
  {
    if(!random(5))
    {
      TOU "The gem in your "+tt+" glows softly...\n");
      USER->add_stuffed(-1);
      USER->add_soaked(-1);
    }
  }

  else if(spec == 2 && ws == 7)  /* soul gem */
  {
  }

  else if(spec == 2 && ws == 8)  /* gem of speed */
  {
    if(!random(9))
    {
      TOU "You move with "+HBBLU+HIY+BLINK+"lightning"+NORM+" speed...\n");
      TRU me+" moves with "+HBBLU+HIY+BLINK+"lightning"+NORM+" speed...\n", ({ USER }));
    }
  }

  else if(spec == 2 && ws == 10)  /* blood gem */
  {
    if(!random(5))
    {
      if(!present("happyfamilygoodtime", nmy))
      {
        TOU "Your "+HIR+"blood gem"+NORM+" pulsates with energy as you destroy "+nn+" with a vicious attack\n");
        TRU me+
          "'s "+HIR+"blood gem"+NORM+" pulsates with energy as "+nmy->PRO+" destroys "+nn+" with a vicious attack\n", ({ USER }));
        MO(CO("players/fred/closed/bloodfist/obj/blood_wound.c"), nmy);
      }
    }
  }

  else if(spec == 2 && ws == 11)  /* sand gem */
  {
    int num;
    string BAM;
    if(!random(8))
    {
      num = random(10);
      switch(num)
      {
        case 0: BAM = " whirlwind"; break;
        case 1: BAM = " torment"; break;
        case 2: BAM = " cyclone"; break;
        case 3: BAM = " wall"; break;
        case 4: BAM = " sheet"; break;
        case 5: BAM = " cloud"; break;
        case 6: BAM = "n onslaught"; break;
        case 7: BAM = "n explosion"; break;
        case 8: BAM = " flurry"; break;
        case 9: BAM = " cylinder"; break;
      } 
      TOU "Your "+YEL+"sand gem"+NORM+" flashes with light...\n");
      TRU me+
        "'s "+YEL+"sand gem"+NORM+" flashes with light....\n", ({ USER }));
      TRU "A"+BAM+" of sand whips into "+nn+"\n");
      nmy->hit_player(5, "other|sand");
    }
    if(!random(300))
    {
      TOU "The "+YEL+"sand gem"+NORM+" explodes with "+BOLD+YEL+"light"+NORM+" making your "+wep->query_name()+" seem new again.\n");
      TRU me+
        "'s "+YEL+"sand gem"+NORM+" explodes with "+BOLD+YEL+"light"+NORM+"\n", ({ USER }));
      wep->set_hits(1);
      wep->set_misses(1);
    }
  }

  else if(spec == 2 && ws == 12)  /* ryo gem */
  {
    if(!random(30) && !nmy->is_player())
    {
      a = first_inventory(environment(USER));
      while(a)
      {
        b = next_inventory(a);
        if(!a->query_bf_ryo() && !random(3))
        {
          TOU "Your "+BOLD+BLU+tt+NORM+" shakes with an iridescent "+CYN+"glow"+NORM+" as a Ryo enters the room!\n");
          TRU me+
            "'s "+BOLD+BLU+tt+NORM+" shakes with an iridescent "+CYN+"glow"+NORM+" as a Ryo enters the room!\n", ({ USER }));
          c = clone_object("/players/fred/closed/bloodfist/NPC/ryo.c");
          c->patch_owner(USER);
          move_object(c, environment(USER));
        }
        a = b;
      }
    }
  }

  else if(spec == 2 && ws == 13)  /* xetra gem */
  {
    if(!random(30) && !nmy->is_player())
    {
      a = first_inventory(environment(USER));
      while(a)
      {
        b = next_inventory(a);
        if(!a->query_bf_xetra() && !random(3))
        {
          TOU "Your "+BOLD+BLU+tt+NORM+" shakes with an iridescent "+BOLD+YEL+"glow"+NORM+" as a Xetra enters the room!\n");
          TRU me+
            "'s "+BOLD+BLU+tt+NORM+" shakes with an iridescent "+BOLD+YEL+"glow"+NORM+" as a Xetra enters the room!\n", ({ USER }));
          c = clone_object("/players/fred/closed/bloodfist/NPC/xetra.c");
          c->patch_owner(USER);
          move_object(c, environment(USER));
        }
        a = b;
      }
    }
  }

  else if(spec == 2 && ws == 14) /* gold gem */
  {
    if(!r(30))
    {
      gold = clone_object("/obj/money.c");
      gold->set_money(random(100));
      move_object(gold, environment(USER));
      TRU "A small rift opens in the fabric of time and space.\n"+
        "A few "+HIY+"gold coins"+NORM+" fall from the "+ 
        "rift as it collapses in on itself.\n");
    }
  }

  else if(spec == 2 && ws == 15)  /* angelic gem */
  {
    if((o = nmy->query_alignment()) < 0)
    {
      TOU "Your "+tt+" burns into "+nmy->short()+"!\n");
      tell_room(environment(USER), me+"'s "+tt+" burns into "+
        nmy->short()+"!\n", ({ USER }));
      nmy->hit_player((-o * (1+random(2))) / 100 + 1);
    }
  }

  else if(spec == 2 && ws == 16)  /* demonic gem */
  {
    if((o = nmy->query_alignment()) > 0)
    {
      TOU "Your "+tt+" burns into "+nmy->short()+"!\n");
      tell_room(environment(USER), me+"'s "+tt+" burns into "+
        nmy->short()+"!\n", ({ USER }));
      nmy->hit_player((o * (1+random(2))) / 100 + 1);
    }
  }

  else if(spec == 2 && ws == 17)  /* gem of regeneration */
  {
    if(!random(5))
    {
      tell_object(USER, HIC+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIC+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->add_hit_point(5);
    }
  }

  else if(spec == 2 && ws == 18)  /* gem of rejuvenation */
  {
    if(!random(5))
    {
      tell_object(USER, HIM+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIM+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->add_spell_point(5);
    }
  }

  else if(spec == 2 && ws == 19)  /* gem of restoration */
  {
    if(!random(5))
    {
      tell_object(USER, HIM+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIM+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->heal_self(4);
    }
  }

  else if(spec == 2 && ws == 20)  /* gem of provoked aggression */
  {
    if(!random(25))
    {
      Z = nmy->query_wc();
      X = (Z / 30);
      TOU "The gem in your "+tt+" glows brightly covering "+nn+" in a strange aura.\n");
      TRU "The gem in "+me+"'s "+tt+" glows brighly covering "+nn+" in a strange aura.\n", ({ USER }));
      TRU "As the aura fades..."+nn+" screams in rage and fights harder...\n");
      nmy->set_wc(Z + X);
    }
  }

  else if(spec == 2 && ws == 21)  /* gem of the dragon */
  {
    string *lmess,*fmess,*imess;
    if(!random(20))
    {
      y = random(3);
      lmess = ({"jolts ","shocks ","fries ","electrocutes ","destroys ","singes "});
      fmess = ({"fries ","torches ","barbeques ","singes ","burns ","blisters "});
      imess = ({"freezes ","crystallizes ","chills ","grazes ","blisters "});
      switch(y)
      {
        case 0:
        TRU "\nA massive dragon swoops down from the sky and "+BOLD+YEL+lmess[random(sizeof(lmess))]+NORM+nmy->query_name()+" with a bolt of "+BBLU+"Lightning"+NORM+".\n\n");
        nmy->hit_player(random(6), "other|lightning");
        break;
        
        case 1:
        TRU "\nA massive dragon swoops down from the sky and "+BOLD+RED+fmess[random(sizeof(fmess))]+NORM+nmy->query_name()+" with a "+BRED+"Breath of Flame"+NORM+".\n\n");
        nmy->hit_player(random(6), "other|fire");
        break;
 
        case 2:
        TRU "\nA massive dragon swoops down from the sky and "+BOLD+RED+imess[random(sizeof(imess))]+NORM+nmy->query_name()+" with an "+BCYN+"Explosion of Frost"+NORM+".\n\n");
        nmy->hit_player(random(6), "other|ice");
        break;
      }
    }
  }

  else if(spec == 2 && ws == 22)  /* gem of cleansing */
  {
    if(!random(5))
    {
      TOU "The gem in your "+tt+" glows softly...\n");
      USER->add_stuffed(-2);
      USER->add_soaked(-2);
      USER->add_intox(-1);
    }
  }

  else if(spec == 3 && ws == 8)  /* major gold gem */
  {
    if(!r(30))
    {
      gold = clone_object("/obj/money.c");
      gold->set_money(random(150));
      move_object(gold, environment(USER));
      TRU "A small rift opens in the fabric of time and space.\n"+
        "A few "+HIY+"gold coins"+NORM+" fall from the "+ 
        "rift as it collapses in on itself.\n");
    }
  }

  else if(spec == 3 && ws == 9)  /* gem of Zeus */
  {
    if(!r(3))
    {
      if(creator(environment(USER)) == "zeus" || creator(nmy) == "zeus")
      {
        y = random(4);
         
        switch(y)
        {
          case 0:
            TOU BOLD+BLK+"Zeus helps to guide your attack.\n"+NORM);
            TRU ""+BOLD+BLK+"Zeus helps to guide "+me+"'s attack."+NORM+"\n", ({ USER }));
            nmy->hit_player(random(15), "other|zeus");
            break;
          case 1:
            TOU HIR+"Zeus lends you some of his strength!\n"+NORM);
            TRU ""+HIR+"Zeus lends "+me+" some of his strength!"+NORM+"\n", ({ USER }));
            USER->heal_self(random(10));
            break;
          case 2:
            TOU HIG+"Zeus forces you to fight harder..."+NORM+".\n");
            TRU ""+HIG+"Zeus forces "+me+" to fight harder..."+NORM+".\n", ({ USER }));
            USER->attack();
            break;        
          case 3:
            TOU HIY+"The gem in your "+tt+" flashes brightly partially blinding "+nn+NORM+".\n");
            TRU ""+HIY+"The gem in "+me+"'s "+tt+" flashes brightly partially blinding "+his+" "+nn+NORM+".\n", ({ USER }));
            nmy->hit_player(5 + random(10), "other|light");
         }        
      }
    }
  }

  else if(spec == 3 && ws == 10)  /* holy angelic gem */
  {
    if((o = nmy->query_alignment()) < 0) 
    {
      TOU "Your "+tt+" burns into "+nmy->short()+"!\n");
      tell_room(environment(USER), me+"'s "+tt+" burns into "+
        nmy->short()+"!\n", ({ USER }));
      nmy->hit_player((-o * 4) / 100 + 5);
    }
  }

  else if(spec == 3 && ws == 11)  /* unholy demonic gem */
  {
    if((o = nmy->query_alignment()) > 0)
    {
      TOU "Your "+tt+" burns into "+nmy->short()+"!\n");
      tell_room(environment(USER), me+"'s "+tt+" burns into "+
        nmy->short()+"!\n", ({ USER }));
      nmy->hit_player((o * 4) / 100 + 5);
    }
  }

  else if(spec == 3 && ws == 12)  /* major gem of regeneration */
  {
    if(!random(5))
    {
      tell_object(USER, HIC+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIC+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->add_hit_point(10);
    }
  }

  else if(spec == 3 && ws == 13)  /* major gem of rejuvenation */
  {
    if(!random(5))
    {
      tell_object(USER, HIM+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIM+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->add_spell_point(10);
    }
  }

  else if(spec == 3 && ws == 14)  /* major gem of restoration */
  {
    if(!random(5))
    {
      tell_object(USER, HIM+"Your "+tt+" emits a healing glow.\n"+NORM);
      tell_room(environment(USER), 
        HIM+me+"'s "+tt+" emits a healing glow.\n"+NORM, ({ USER }));
      USER->heal_self(8);
    }
  }

  else if(spec == 3 && ws == 15)  /* minds eye gem */
  {
    k = nmy->query_sp();
    l = nmy->query_hp();
    q = nmy->query_mhp();
    y = nmy->query_msp();
    soak = nmy->query_soaked();
    if(soak) ssoak = ((soak * 100) / (nmy->query_max_soak()));
    stuff = nmy->query_stuffed();
    if(stuff) sstuff = ((stuff * 100) / (nmy->query_max_stuff()));
    tox = nmy->query_intoxication();
    if(tox) ttox = ((tox * 100) / (nmy->query_max_intox()));
    if(nmy->is_player())
    {
      if((ttox > 0) && (sstuff > 0) && (soak > 0))
      {
        TOU "\n"+nmy->query_name()+" is currently at:\n"+BOLD+BLK+
        "["+RED+"MinDsEye"+BLK+"]"+YEL+" ~~~      HP      SP      Intox      Stuff      Soak      ~~~ \n"+
        "                   "+l+"/"+q+"     "+k+"/"+y+"     "+ttox+"%     "+sstuff+"%     "+ssoak+"%"+NORM+"\n");
      }
      else if((ttox > 0) && (sstuff > 0) && (ssoak < 1))
      {
        TOU "\n"+nmy->query_name()+" is currently at:\n"+BOLD+BLK+
        "["+RED+"MinDsEye"+BLK+"]"+YEL+" ~~~      HP      SP      Intox      Stuff      ~~~ \n"+
        "                   "+l+"/"+q+"     "+k+"/"+y+"     "+ttox+"%     "+sstuff+"%"+NORM+"\n");
      }
      else if((ttox > 0) && (sstuff < 1) && (ssoak > 0))
      {
        TOU "\n"+nmy->query_name()+" is currently at:\n"+BOLD+BLK+
        "["+RED+"MinDsEye"+BLK+"]"+YEL+" ~~~      HP      SP      Intox      Soak      ~~~ \n"+
        "                   "+l+"/"+q+"     "+k+"/"+y+"     "+ttox+"%     "+ssoak+"%"+NORM+"\n");
      }
      else if((ttox < 1) && (sstuff > 0) && (ssoak > 0))
      {
        TOU "\n"+nmy->query_name()+" is currently at:\n"+BOLD+BLK+
        "["+RED+"MinDsEye"+BLK+"]"+YEL+" ~~~      HP      SP      Stuff      Stuff      ~~~ \n"+
        "                   "+l+"/"+q+"     "+k+"/"+y+"     "+sstuff+"%     "+sstuff+"%"+NORM+"\n");
      }    
      else if((ttox > 0) && (sstuff < 1) && (ssoak < 1))
      {
        TOU "\n"+nmy->query_name()+" is currently at:\n"+BOLD+BLK+
        "["+RED+"MinDsEye"+BLK+"]"+YEL+" ~~~      HP      SP      Intox      ~~~ \n"+
        "                   "+l+"/"+q+"     "+k+"/"+y+"     "+ttox+"%"+NORM+"\n");
      }
      else if((ttox < 1) && (sstuff > 0) && (ssoak < 1))
      {
        TOU "\n"+nmy->query_name()+" is currently at:\n"+BOLD+BLK+
        "["+RED+"MinDsEye"+BLK+"]"+YEL+" ~~~      HP      SP      Stuff      ~~~ \n"+
        "                   "+l+"/"+q+"     "+k+"/"+y+"     "+sstuff+"%"+NORM+"\n");
      }
      else if((ttox < 1) && (sstuff < 1) && (ssoak > 0))
      {
        TOU "\n"+nmy->query_name()+" is currently at:\n"+BOLD+BLK+
        "["+RED+"MinDsEye"+BLK+"]"+YEL+" ~~~      HP      SP      Soak      ~~~ \n"+
        "                  "+l+"/"+q+"     "+k+"/"+y+"     "+ssoak+"%"+NORM+"\n");
      }
    }
    TOU "\n"+nmy->query_name()+" is currently at:\n"+BOLD+BLK+
    "["+RED+"MinDsEye"+BLK+"]"+YEL+" ~~~      HP      ~~~ \n"+
    "                 "+l+"/"+q+NORM+"\n");
  }

  else if(spec == 3 && ws == 16)  /* gem of inescapable horror */
  {
    object blah;
    if(!random(5))
    {
      if(!present("no_go", environment(USER)))
      {
        blah = CO("/players/fred/closed/bloodfist/obj/no_go.c");
        MO(blah, environment(USER));
        blah->set_owner(USER);
      }
    }
  }

  else if(spec == 3 && ws == 17)  /* major gem of cleansing */
  {
    if(!random(5))
    {
      TOU "The gem in your "+tt+" glows softly...\n");
      USER->add_stuffed(-3);
      USER->add_soaked(-3);
      USER->add_intox(-2);
    }
  }
}

finish()
{
  corpse = present("corpse", environment(USER)); 
  TOU BOLD+BLK+"The corpse withers into nothingness.\n\n"+NORM);
  TRU BOLD+BLK+
    "The corpse withers into nothingness.\n\n"+NORM, ({ USER }));
  h = corpse->query_corpse_level();
  h *= 4;
  h /= 3;
  USER->heal_self(h);
  destruct(corpse);
  return 1;
}
