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
  ROM  "+tp+"'s sword sings \"\Tender Lover\"\ by Babyface\n\n");
        }
if(w == 3)  {
  ROM  "+tp+"'s sword sings \"\Here and Now\"\ by Luther Vandross\n\n");
        }
if(w == 4)  {
  ROM  "+tp+"'s sword sings \"\Humppin' Around\"\ by Bobby Brown\n\n");
        }
if(w == 5)  {
  ROM  "+tp+"'s sword sings \"\Let's Chill\"\ by Guy\n\n");
        }
if(w == 6)  {
  ROM  "+tp+"'s sword sings \"\End of the Road\"\ by Boyz II Men\n\n");
        }
if(w == 7)  {
  ROM  "+tp+"'s sword sings \"\Giving You The Best\"\ by Anita Baker\n\n");
        }
if(w == 8)  {
  ROM  "+tp+"'s sword sings \"\Rythmn Nation\"\ by Janet Jackson\n\n");
  this_player()->heal_self(10);
        }
if(w == 9)  {
  ROM  "+tp+"'s sword sings \"\5-F Man\"\ by Shabba Ranks\n\n");
  if(attacker->query_hp() > 10)
  attacker->heal_self(-10);
        }
if(w == 10)  {
  ROM  "+tp+"'s sword sings \"\Knockin' Da Boots\"\ by H-Town\n\n");
        }
if(w == 11)  {
  ROM  "+tp+"'s sword sings \"\Here We Go!\"\ by Portrait\n\n");
        }
if(w == 12)  {
  ROM  "+tp+"'s sword sings \"\Lose Control\"\ by Silk\n\n");
        }
if(w == 13)  {
  ROM  "+tp+"'s sword sings \"\Come and Talk\"\ by Jodeci\n\n");
  this_player()->heal_self(5);
        }
if(w == 14)  {
  ROM  "+tp+"'s sword sings \"\Breathe Again\"\ by Toni Braxton\n\n");
        }
if(w == 15)  {
  ROM  "+tp+"'s sword sings \"\Can You Stand The Rain\"\ by New Edition\n\n");
        }
if(w == 16)  {
  ROM  "+tp+"'s sword sings \"\Sensitivity\"\ by Ralph Tresvant\n\n");
        }
if(w == 17)  {
  ROM  "+tp+"'s sword sings \"\Poison\"\ by Bell Biv DeVoe\n\n");
  if(attacker->query_hp() > 5)
  attacker->heal_self(-5);
        }
if(w == 18)  {
  ROM  "+tp+"'s sword sings \"\My, My, My\"\ by Johnny Gill\n\n");
        }
if(w == 19)  {
  ROM  "+tp+"'s sword sings \"\Time and Chance\"\ by Color Me Badd\n\n");
        }
if(w == 20)  {
  ROM  "+tp+"'s sword sings \"\Right Here\"\ by SWV\n\n");
        }
if(w == 21)  {
  ROM  "+tp+"'s sword sings \"\Ain't 2 Proud 2 Beg\"\ by TLC\n\n");
        }
if(w == 22)  {
  ROM  "+tp+"'s sword sings \"\Mamma said knock you out\"\ by L L Cool J\n\n");
        }
if(w == 23)  {
  ROM  "+tp+"'s sword sings \"\Freak It\"\ by Das EFX\n\n");
  if(attacker->query_hp() > 5)
  attacker->heal_self(-5);
        }
if(w == 24)  {
  ROM  "+tp+"'s sword sings \"\Gangsta Bitch\"\ by Apache\n\n");
        }
if(w == 25)  {
  ROM  "+tp+"'s sword sings \"\Check Yo'self\"\ by Ice Cube\n\n");
        }
if(w == 26)  {
  ROM  "+tp+"'s sword sings \"\Mr. Vain\"\ by Culture Beat\n\n");
        }
if(w == 27)  {
  ROM  "+tp+"'s sword sings \"\Gin and Juice\"\ by Snoop Dogg\n\n");
        }
if(w == 28)  {
  ROM  "+tp+"'s sword sings \"\Don't be cruel\"\ by Bobby Brown\n\n");
        }
if(w == 29)  {
  ROM  "+tp+"'s sword sings \"\Motownphilly\"\ by Boyz 2 Men\n\n");
  this_player()->heal_self(5);
        }
if(w == 30)  {
  ROM  "+tp+"'s sword sings \"\Freak Me\"\ by Silk\n\n");
        }
if(w == 31)  {
  ROM  "+tp+"'s sword sings \"\Can't Stop\"\ by After 7\n\n");
        }
if(w == 32)  {
  ROM  "+tp+"'s sword sings \"\Tennessee\"\ by Arrested Development\n\n");
        }
if(w == 33)  {
  ROM  "+tp+"'s sword sings \"\Ways of the Wind\"\ by P.M. Dawn\n\n");
        }
if(w == 34)  {
  ROM  "+tp+"'s sword sings \"\Mind over Matter\"\ by Ice T.\n\n");
  this_player()->heal_self(3);
        }
if(w == 35)  {
  ROM  "+tp+"'s sword sings \"\Rhythmn is a Dancer\"\ by Snap\n\n");
        }
if(w == 36)  {
  ROM  "+tp+"'s sword sings \"\Twilight Zone\"\ by 2 Unlimited\n\n");
        }
if(w == 37)  {
  ROM  "+tp+"'s sword sings \"\3 A.M. Eternal\"\ by KLF\n\n");
         }
if(w == 38)  {
  ROM  "+tp+"'s sword sings \"\Rub you the Right Way\"\ by Johnny Gill\n\n");
        }
if(w == 39)  {
  ROM  "+tp+"'s sword sings \"\Whatta Man\"\ by Salt 'N Peppa\n\n");
        }
if(w == 40)  {
  ROM  "+tp+"'s sword sings \"\Jump Around\"\ by House of Pain\n\n");
        }
if(w == 41)  {
  ROM  "+tp+"''s sword sings \"\Mr. Loverman\"\ by Shabba Ranks\n\n");
        }
if(w == 42)  {
  ROM  "+tp+"'s sword sings \"\Monster Mack\"\ by Sir Mix-a-Lot\n\n");
        }
if(w == 43)  {
  ROM  "+tp+"'s sword sings \"\Gonna make you sweat\"\ by C&C Music Factory\n\n");
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
