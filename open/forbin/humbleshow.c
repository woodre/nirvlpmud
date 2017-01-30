/*  Forbin | Create date:  mar2002.28 | Last mod:  mar2002.31  */

#include "/players/forbin/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

object gold;
int coins;
int COLOR;

get_random_type()
  {
  switch(random(13))
    {
    case 0: COLOR = HIR; break;
    case 1: COLOR = HIG; break;
    case 2: COLOR = HIM; break;
    case 3: COLOR = HIB; break;
    case 4: COLOR = HIC; break;
    case 5: COLOR = HIY; break;
    case 6: COLOR = YEL; break;
    case 7: COLOR = GRN; break;
    case 8: COLOR = BLU; break;
    case 9: COLOR = HIW; break;
    case 10: COLOR = CYN; break;
    case 11: COLOR = MAG; break;
    case 12: COLOR = RED; break;
    }
  switch(random(26))
    {
    case 0: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Deneb Drei"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Deneb Drei.  She is here\n"+
                     "visiting the outworld planet of Hyperion.\n");                  
            break;
    case 1: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Deneb Drei"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Deneb Drei.  He is here\n"+
                     "visiting the outworld planet of Hyperion.\n");                  
            break;
    case 2: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"God's Grove"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  An abnormally tall lady, she wears the dark robe of the  \n"+
                     "Templars of God's Grove.  You see the very long fingers and \n"+
                     "notice a plantive joy in her eyes.\n");                  
            break;
    case 3: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"God's Grove"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  An abnormally tall gentleman, he wears the dark robe of   \n"+
                     "the Templars of God's Grove.  You see the very long fingers  \n"+
                     "and notice a plantive joy in his eyes.\n");                  
            break;
    case 4: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Hebron"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Hebron.  She is here\n"+
                     "visiting the outworld planet of Hyperion.\n");                  
            break;
    case 5: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Hebron "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Hebron.  He is here\n"+
                     "visiting the outworld planet of Hyperion.\n");                  
            break;
    case 6: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Lusus"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  A rather short and stocky woman, she is very bulky\n"+
                     "due to the increased gravity on the planet Lusus.\n");                  
            break;
    case 7: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Lusus"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  A rather short and stocky man, he is very bulky\n"+
                     "due to the increased gravity on the planet Lusus.\n");                  
            break;
    case 8: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Mare Infinitus"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Mare Infinitus.  She is\n"+
                     "here visiting the outworld planet of Hyperion.\n");                  
            break;
    case 9: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Mare Infinitus"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Mare Infinitus.  He is\n"+
                     "here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 10: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Maui Covenant"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Maui Covenant.  She is\n"+
                     "here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 11: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Maui Covenant"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Maui Covenant.  He is\n"+
                     "here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 12: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Nevermore"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Nevermore.  She is here\n"+
                     "visiting the outworld planet of Hyperion.\n");                  
            break;
   case 13: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Nevermore"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Nevermore.  He is here\n"+
                     "visiting the outworld planet of Hyperion.\n");                  
            break;
   case 14: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Qom Riyadh"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Qom Riyadh.  She is\n"+
                     "here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 15: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Qom Riyadh"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Qom Riyadh.  He is\n"+
                     "here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 16: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Rennaissance Vector"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Rennsissance Vector.  She\n"+
                     "is here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 17: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Rennaissance Vector"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Rennsissance Vector.  He\n"+
                     "is here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 18: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Sol Draconi Septum"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Sol Draconi Septum.\n"+
                     "She is here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 19: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Sol Draconi Septum"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Sol Draconi Septum.\n"+
                     "He is here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 20: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Tau Ceti Center"+NORM+" "+COLOR+"("+NORM+"female"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Tau Ceti Center.  She\n"+
                     "is here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 21: set_name("citizen");
		set_race("human");
		set_short("a citizen - "+COLOR+"Tau Ceti Center"+NORM+" "+COLOR+"("+NORM+"male"+COLOR+")"+NORM+"");
		set_long("  This is a resident of the planet Tau Ceti Center.  He\n"+
                     "is here visiting the outworld planet of Hyperion.\n");                  
            break;
   case 22: set_name("priest");
		set_race("human");
		set_short("a priest - "+HIK+"Pacem"+NORM+" "+HIK+"("+NORM+"male"+HIK+")"+NORM+"");
		set_long("  Wearing the dark robe and vestments of a priest, he\n"+
                     "has come to this place at the urging of the New Vatican\n"+
                     "on the catholic homeworld of Pacem.\n");                  
            break;
   case 23: set_name("ouster");
		set_race("ouster");
		set_short(""+HIK+"Ouster"+NORM+" "+HIW+"["+HIY+"butterfly"+NORM+""+HIW+"]"+NORM+"");
		set_long("  Ousters - humans that are biologically and cybernetically\n"+
                     "enhanced in order to travel between the stars are beautiful\n"+
                     "creations.  This ouster, skin a dull yellow, has beautiful\n"+
                     "butterfly-like wings.\n");                  
            break;
   case 24: set_name("ouster");
		set_race("ouster");
		set_short(""+HIK+"Ouster"+NORM+" "+HIW+"["+HIG+"dragon"+NORM+""+HIB+"fly"+NORM+""+HIW+"]"+NORM+"");
		set_long("  Ousters - humans that are biologically and cybernetically\n"+
                     "enhanced in order to travel between the stars are beautiful\n"+
                     "creations.  This ouster, skin a bright greenish blue, has\n"+
                     "four strange, dragonfly-like wings.\n");                  
            break;
   case 25: set_name("ouster");
		set_race("ouster");
		set_short(""+HIK+"Ouster"+NORM+" "+HIW+"["+MAG+"gossamer"+NORM+""+HIW+"]"+NORM+"");
		set_long("  Ousters - humans that are biologically and cybernetically\n"+
                     "enhanced in order to travel between the stars are beautiful\n"+
                     "creations.  This ouster, skin a silky purple, has enormous\n"+
                     "gossamer wings.\n");                  
            break;
    }
  }
get_random_stats()
  {
  switch(random(4))
    {
    case 0: set_level(4);
            set_hp(55+random(20));
		set_ac(5);
		set_wc(9+random(2));
		set_al(random(2001)-1000);
            coins = 130+random(20);
            break;
    case 1: set_level(5);
            set_hp(70+random(20));
		set_ac(6);
		set_wc(10+random(2));
		set_al(random(2001)-1000);
            coins = 170+random(20);                   
            break;
    case 2: set_level(6);
            set_hp(85+random(25));
		set_ac(6);
		set_wc(11+random(2));
		set_al(random(2001)-1000);
		set_spell_dam(10);
		set_spell_mess1(""+TPN+" is pushed to the ground by "+TPP+" opponent.\n");
		set_spell_mess2("You are shoved to the ground by your opponent\n");
            coins = 220+random(30);                   
            break;
    case 3: set_level(7);
            set_hp(100+random(25));
		set_ac(7);
		set_wc(12+random(2));
		set_al(random(2001)-1000);
		set_chance(10);
		set_spell_dam(15);
		set_spell_mess1(""+TPN+" is pushed to the ground by "+TPP+" opponent.\n");
		set_spell_mess2("You are shoved to the ground by your opponent\n");
            coins = 270+random(30);                   
            break;
    }
  }