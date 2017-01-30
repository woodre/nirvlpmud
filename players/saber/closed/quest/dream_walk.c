/*
 *      A QUEST OBJECT FOR SABER'S QUEST
 *
 *      THE SCROLL OF DREAM WALKING
 *
 */


#define CAP capitalize(str)
#define YES write("You have   ");
#define NO  write("You need   ");
#define DEST destruct(check_part)

int ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT;
int VARB1, VARB2;

id(str)  {
  return str == "dreamwalk scroll"  ||
         str == "dream walk scroll";
          }

  can_put_and_get()  { return 0; }
  get()  { return 1; }


short()  { 
  return "A dream walk scroll";
        }

long()  {
  write("\n"+
    "A scroll of dream walking.\n"+
    "This scroll has six components.  Once you find one, to add it\n"+
    "to the scroll, type <component> <component name>.\n\n");
  if(ONE == 0) NO else YES;
    if(VARB1 == 0)  {
    write("The pelt of a large cat,\n");  }  else  {
    write("The pelt of a wolf,\n");  }
  if(TWO == 0) NO else YES;
    write("A still bound pouch of sand,\n");
  if(THREE == 0) NO else YES;
    if(VARB2 == 0)  {
    write("Blood from the head of a troll,\n"); } else {
    write("An iron sphere filled with water,\n");  }
  if(FOUR == 0) NO else YES;
    write("The shadow cast by a running demon,\n");
  if(FIVE == 0) NO else YES;
    write("A bolt from a body of living lightning,\n");
  if(SIX == 0) NO else YES;
    write("And scales red as blood from the ghost of a dragon.\n");
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
  if(str == "pelt" || str == "skin")  {
    ONE = 1;  ADD(str);  DEST;
        }
  if(str == "pouch" || str == "pouch of sand")  {
    TWO = 1;  ADD(str);  DEST;
        }
  if(str == "head" || str == "troll head" || str == "sphere" ||
        str == "iron sphere")  {
    THREE = 1;  ADD(str);  DEST;
        }
  if(str == "shadow")  {
    FOUR = 1;  ADD(str);  DEST;
        }
  if(str == "bolt" || str == "lightning")  {
    FIVE = 1;  ADD(str);  DEST;
        }
  if(str == "scale" || str == "armor")  {
    SIX = 1;  ADD(str);  DEST;
        }
  return 1;
        }

read_scroll(str)  {
  if(str == "dreamwalk scroll" || str == "dream walk scroll")  {
  if(ONE == 1 && TWO == 1 && THREE == 1 && FOUR == 1 && FIVE == 1 && SIX == 1)  {
  say(this_player()->query_name()+" reads a scroll of dream walking.\n");
  write("\nYou read the scroll of dream walking.\n"+
    "You feel your body slowly begin to fade away.\n\n\n");
  write("You have entered into the realm of the Nightmare.\n\n");
  say(this_player()->query_name()+" slowly fades from view.\n");
  destruct(this_object());
  return 1;
        }
  write("You have not yet found all the material components.\n");
  return 1;
        }
        }

ADD(str)  {
  write("You have added the "+CAP+" component to the scroll of dream walking.\n");
  return 1;
        }
