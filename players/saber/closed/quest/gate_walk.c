/*
 *      A QUEST OBJECT FOR SABER'S QUEST
 *
 *      THE SCROLL OF EXTRA PLANER GATE
 *
 */


#define CAP capitalize(str)
#define YES write("You have   ");
#define NO  write("You need   ");
#define DEST destruct(check_part)

int ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT;
int VARB1, VARB2, VARB3, VARB4;

id(str)  {
  return str == "gate scroll"  ||
         str == "extra planer gate scroll";
          }

  can_put_and_get()  { return 0; }
  get()  { return 1; }


short()  { 
  return "A scroll of extra planer gate";
        }

long()  {
  write("\n"+
    "A scroll of extra planer gate.\n"+
    "This scroll has seven components.  Once you find one, to add it\n"+
    "to the scroll, type <component> <component name>.\n\n");
  if(ONE == 0) NO else YES;
    if(VARB1 == 0)  {
    write("A stone of blood,\n");  }  else  {
    write("A preserved corpse,\n");  }
  if(TWO == 0) NO else YES;
    write("A living hellkitten,\n");
  if(THREE == 0) NO else YES;
    if(VARB2 == 0)  {
    write("A cursed metal trinket,\n");  }  else  {
    write("A cursed power system,\n");  }
  if(FOUR == 0) NO else YES;
    if(VARB3 == 0)  {
    write("A pair of demonic claws,\n");  }  else  {
    write("The dark whip of a demon,\n"); }
  if(FIVE == 0) NO else YES;
    if(VARB4 == 0)  {
    write("A blessed ring of protection,\n");  }  else  {
     write("A blessed amulet of protection,\n");  }
  if(SIX == 0) NO else YES;
    write("The symbol of the cursed death god,\n");
  if(SEVEN == 0) NO else YES;
    write("And a blessed coin of worked black silver.\n");
         }

init()  {
   add_action("add_part","component");
   add_action("read_scroll","read");
        }

add_part(str)  {
object check_part;
  if(!(check_part = present(str, environment(this_object()))))  {
    write("There is no "+CAP+" here to add to the scroll.\n");
    return 1;
        }
  if(check_part->quest_ob() != 1)  {
    write("This is not the correct component for your scroll.\n");
    return 1;
        }
  if(str == "bloodstone" || str == "stone" || str == "corpse")  {
    ONE = 1;  ADD(str);  DEST;
        }
  if(str == "kitten" || str == "hell kitten")  {
    TWO = 1;  ADD(str);  DEST;
        }
  if(str == "power system" || str == "trinket" || str == "metal trinket" ||
        str == "system")  {
    THREE = 1;  ADD(str);  DEST;
        }
  if(str == "claws" || str == "demon claws" || str == "whip" || str == "demonwhip")  {
    FOUR = 1;  ADD(str);  DEST;
        }
  if(str == "amulet" || str == "ring" || str == "ring of protection" || str == "amulet of protection")  {
    FIVE = 1;  ADD(str);  DEST;
        }
  if(str == "unholy symbol" || str == "symbol")  {
    SIX = 1;  ADD(str);  DEST;
        }
  if(str == "coin" || str == "silver coin")  {
    SEVEN = 1;  ADD(str);  DEST;
        }
  return 1;
        }

read_scroll(str)  {
  if(str == "gate scroll" || str == "extra planer gate scroll")  {
  if(ONE == 1 && TWO == 1 && THREE == 1 && FOUR == 1 && FIVE == 1 && SIX == 1 && SEVEN == 1 && SEVEN == 1)  {
  say(this_player()->query_name()+" reads a scroll of extra planer gate.\n");
  write("\nYou read the scroll of extra planer gate.\n"+
    "You feel your body slowly begin to fade away.\n\n\n");
  write("You have entered into the Dark Circle.\n\n");
  say(this_player()->query_name()+" slowly fades from view.\n");
  destruct(this_object());
  return 1;
        }
  write("You have not yet found all the material components.\n");
  return 1;
        }
        }

ADD(str)  {
  write("You have added the "+CAP+" component to the scroll of extra planer gate.\n");
  return 1;
        }
