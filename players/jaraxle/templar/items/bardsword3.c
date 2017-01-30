#define tp this_player()->query_name()
#define ROM tell_room(environment(this_player()), "\n
int w,n,ahp;
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("bardsword");
     set_short("A Crystal Bardsword");
     set_long("An ivory white longsword of gleaming crystal.\n"+
       "It is very light, and has a wicked edge to it.\n"+
       "There is a Bardic rune on the hilt.\n");
    set_class(17);
    set_weight(2);
    set_type("sword"); /* 6.6.01 by verte */
    set_value(10000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(120);

if(w < 40)  {

if(w < 2)  {
       write("The Bardsword gleams with a pure white fire as it cleaves through your foe.\n");
       write(capitalize(attacker->query_real_name())+" staggers.\n");
       say(tp+"'s Bardsword gleams with a pure white fire as "+this_player()->query_pronoun()+" cleaves through "+this_player()->query_possessive()+" foe.\n"+
         capitalize(attacker->query_real_name())+" staggers.\n");
    }
if(w == 2)  {
  ROM  "+tp+"'s sword sings \"\Until the End of the World\"\ by U2\n\n");
        }
if(w == 3)  {
  ROM  "+tp+"'s sword sings \"\Sunday, Bloody Sunday\"\ by U2\n\n");
        }
if(w == 4)  {
  ROM  "+tp+"'s sword sings \"\It's the End of the World as we know it\"\ by REM\n\n");
        }
if(w == 5)  {
  ROM  "+tp+"'s sword sings \"\Green Hell\"\ by The Misfits\n\n");
        }
if(w == 6)  {
  ROM  "+tp+"'s sword sings \"\Devil Inside\"\ by INXS\n\n");
        }
if(w == 7)  {
  ROM  "+tp+"'s sword sings \"\Head like a hole\"\ by Nine Inch Nails\n\n");
        }
if(w == 8)  {
  ROM  "+tp+"'s sword sings \"\Wish\"\ by Nine Inch Nails\n\n");
  this_player()->heal_self(10);
        }
if(w == 9)  {
  ROM  "+tp+"'s sword sings \"\James Brown is Dead\"\ by L.A. Style\n\n");
  if(attacker->query_hp() > 10)
  attacker->heal_self(-10);
        }
if(w == 10)  {
  ROM  "+tp+"'s sword sings \"\No sex until marriage\"\ by Ave Maria\n\n");
        }
if(w == 11)  {
  ROM  "+tp+"'s sword sings \"\Rage + Desire\"\ by Command Co.\n\n");
        }
if(w == 12)  {
  ROM  "+tp+"'s sword sings \"\I Sit on Acid\"\ by Lords of Acid\n\n");
        }
if(w == 13)  {
  ROM  "+tp+"'s sword sings \"\Speed (Hardcore)\"\ by Alpha Team\n\n");
  this_player()->heal_self(5);
        }
if(w == 14)  {
  ROM  "+tp+"'s sword sings \"\Thunder Kiss 66\"\ by White Zombie\n\n");
        }
if(w == 15)  {
  ROM  "+tp+"'s sword sings \"\New World Order\"\ by Ministry\n\n");
        }
if(w == 16)  {
  ROM  "+tp+"'s sword sings \"\Psalm 69\"\ by Ministry\n\n");
        }
if(w == 17)  {
  ROM  "+tp+"'s sword sings \"\Give it Away\"\ by the Red Hot Chili Peppers\n\n");
  if(attacker->query_hp() > 5)
  attacker->heal_self(-5);
        }
if(w == 18)  {
  ROM  "+tp+"'s sword sings \"\Enter Sandman\"\ by Metallica\n\n");
        }
if(w == 19)  {
  ROM  "+tp+"'s sword sings \"\Master of Puppets\"\ by Metallica\n\n");
        }
if(w == 20)  {
  ROM  "+tp+"'s sword sings \"\Sex on Wheels\"\ by My Life With the Thrill Kill Kult\n\n");
        }
if(w == 21)  {
  ROM  "+tp+"'s sword sings \"\Her Sassy Kiss\"\ by My Life With the Thrill Kill Kult\n\n");
        }
if(w == 22)  {
  ROM  "+tp+"'s sword sings \"\I'd do anything for Love\"\ by Meatloaf\n\n");
        }
if(w == 23)  {
  ROM  "+tp+"'s sword sings \"\Ah Ha\"\ by Moby\n\n");
  if(attacker->query_hp() > 5)
  attacker->heal_self(-5);
        }
if(w == 24)  {
  ROM  "+tp+"'s sword sings \"\Welcome to the Jungle\"\ by Guns and Roses\n\n");
        }
if(w == 25)  {
  ROM  "+tp+"'s sword sings \"\Paradise City\"\ by Guns and Roses\n\n");
        }
if(w == 26)  {
  ROM  "+tp+"'s sword sings \"\Down, Down, Down\"\ by House of Lords\n\n");
        }
if(w == 27)  {
  ROM  "+tp+"'s sword sings \"\Hell on Earth\"\ by Motorhead\n\n");
        }
if(w == 28)  {
  ROM  "+tp+"'s sword sings \"\...And Justice For All\"\ by Metallica\n\n");
        }
if(w == 29)  {
  ROM  "+tp+"'s sword sings \"\One\"\ by Metallica\n\n");
  this_player()->heal_self(5);
        }
if(w == 30)  {
  ROM  "+tp+"'s sword sings \"\The Frayed Ends of Sanity\"\ by Metallica\n\n");
        }
if(w == 31)  {
  ROM  "+tp+"'s sword sings \"\Dead Mans Party\"\ by Oingo Boingo\n\n");
        }
if(w == 32)  {
  ROM  "+tp+"'s sword sings \"\Only a Lad\"\ by Oingo Boingo\n\n");
        }
if(w == 33)  {
  ROM  "+tp+"'s sword sings \"\Immigrant Song\"\ by Led Zeppelin\n\n");
        }
if(w == 34)  {
  ROM  "+tp+"'s sword sings \"\Hellbent for Leather\"\ by Ozzy\n\n");
  this_player()->heal_self(3);
        }
if(w == 35)  {
  ROM  "+tp+"'s sword sings \"\Radar Love\"\ by Golden Earing\n\n");
        }
if(w == 36)  {
  ROM  "+tp+"'s sword sings \"\We will rock you\"\ by Queen\n\n");
        }
if(w == 37)  {
  ROM  "+tp+"'s sword sings \"\Stone cold crazy\"\ by Queen\n\n");
         }
if(w == 38)  {
  ROM  "+tp+"'s sword sings \"\Iron Man\"\ by Ozzy\n\n");
        }
if(w == 39)  {
  ROM  "+tp+"'s sword sings \"\Surprise, You're DEAD\"\ by Faith No More\n\n");
        }
if(w == 40)  {
  ROM  "+tp+"'s sword sings \"\Breed\"\ by Nirvana\n\n");
        }
if(w == 41)  {
  ROM  "+tp+"'s sword sings \"\From out of Nowhere\"\ by Faith No More\n\n");
        }
if(w == 42)  {
  ROM  "+tp+"'s sword sings \"\Black Sunshine\"\ by White Zombie\n\n");
        }
if(w == 43)  {
  ROM  "+tp+"'s sword sings \"\Been Caught Stealing\"\ by Janes Addiction\n\n");
        }

  return 6;
        }

    return;
}

init()  {
  ::init();
add_action("new_wield","wield");
add_action("new_wield","ready");
        }

new_wield(str)  {
if(str == "bardsword")  {
/*
if(this_player()->query_guild_name() != "bard")  {
  write("You are not a Bard!\n");
  return 1;
        }
*/
write("\nYou feel a surge of power as you wield your BARDSWORD.\n\n");
say("\n"+tp+" is surrounded by a blue aura as "+this_player()->query_pronoun()+" wields a BARDSWORD.\n\n");
  return 0;
        }
        }
