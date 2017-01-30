/*
 *      A QUEST OBJECT FOR SABER'S QUEST
 *
 *      THE SCROLL OF ASTRAL TRAVEL
 *
 */


#define CAP capitalize(str)
#define YES write("You have   ");
#define NO  write("You need   ");
#define DEST destruct(check_part)

int ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT;
int VARB1, VARB2, VARB3, VARB4;

id(str)  {
  return str == "astral scroll"  ||
         str == "astral travel scroll";
          }

  can_put_and_get()  { return 0; }
  get()  { return 1; }


short()  { 
  return "A scroll of extra planer gate";
        }

long()  {
  write("\n"+
     "A scroll of astral travel.\n"+
    "This scroll has eight components.  Once you find one, to add it\n"+
    "to the scroll, type <component> <component name>.\n\n");
  if(ONE == 0) NO else YES;
    write("A star ruby,\n");
  if(TWO == 0) NO else YES;
    if(VARB1 == 0)  {
    write("A silver mirror,\n");  }  else {
    write("A silver rose,\n");  }
  if(THREE == 0) NO else YES;
    if(VARB2 == 0)  {
    write("A crucifix of pure silver,\n");  }  else  {
    write("A comb of worked silver,\n");  }
  if(FOUR == 0) NO else YES;
    write("The blessing of a poor man,\n");
  if(FIVE == 0) NO else YES;
    write("A chilled ring of ice crystal,\n");
  if(SIX == 0) NO else YES;
    write("The still dripping heart of a nightmare,\n");
  if(SEVEN == 0) NO else YES;
    write("A cloak woven from the strands of a damned fire,\n");
  if(EIGHT == 0) NO else YES;
    write("And boots made from the nothingness of a fine mist.\n");
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
  if(str == "ruby" || str == "star ruby")  {
    ONE = 1;  ADD(str);  DEST;
        }
  if(str == "mirror" || str == "rose" || str == "silver rose" || str == "silver mirror")  {
    TWO = 1;  ADD(str);  DEST;
        }
  if(str == "crucifix" || str == "comb" || str == "silver crucifix")  {
    THREE = 1;  ADD(str);  DEST;
        }
  if(str == "ring" || str == "ice ring")  {
    FIVE = 1;  ADD(str);  DEST;
        }
  if(str == "heart")  {
    SIX = 1;  ADD(str);  DEST;
        }
  if(str == "cloak" || str == "cloak of fire")  {
    SEVEN = 1;  ADD(str);  DEST;
        }
  if(str == "boots" || str == "boots of mist")  {
    EIGHT = 1;  ADD(str);  DEST;
        }
  return 1;
        }

read_scroll(str)  {
  if(str == "astral scroll" || str == "astral travel scroll")  {
  if(ONE == 1 && TWO == 1 && THREE == 1 && FOUR == 1 && FIVE == 1 && SIX == 1 && EIGHT == 1 && SEVEN == 1)  {
  say(this_player()->query_name()+" reads a scroll of astral travel.\n");
  write("\nYou read the scroll of astral travel.\n"+
    "You feel your body slowly begin to fade away.\n\n\n");
  write("Your soul is ready for Astral Travel.\n\n");
  say(this_player()->query_name()+" slowly fades from view.\n");
  destruct(this_object());
  return 1;
        }
  write("You have not yet found all the material components.\n");
  return 1;
        }
        }

ADD(str)  {
  write("You have added the "+CAP+" component to the scroll of astral travel.\n");
  return 1;
        }
