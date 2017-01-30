/* xemote.c - a little toy to add extra things to says and emotes-
 *            notably colored says, and color inside double quotes
 *            in emotes.  It also adds a pemote command, which is the
 *            same as emote except it adds "'s" after the name of the
 *            emoting person.
 *       Illarion - March 2000
 */
 
#include "/players/illarion/dfns.h"
inherit "obj/treasure";

string color;

/* not dropable, kept until player logs out */
status drop() {
  return 0;
}
void reset(status arg) {
  if(arg) return;
  color = CYN;
  set_id("sliver");
  set_short("A sliver of color");
  set_long("This tool will let you make your says and emotes a tad more\n"+
           "flashy.  Type "+BLD("emhelp")+" for a list of functions.\n");
  set_weight(1);
  set_value(0);
}
string short() {
  return "A sliver of "+color+"color"+NORM;
}
void init() {
  ::init();
  add_action("cmd_emhelp","emhelp");
  add_action("cmd_say","say");
  add_action("cmd_emote","emote");
  add_action("cmd_pemote","pemote");
  add_action("cmd_emcolor","emcolor");
  add_action("cmd_emoteto","emoteto");
  add_action("cmd_decolor","decolor");
}
/* gives a brief (and incomplete) description of this object's abilities.
 */
status cmd_emhelp() {
  write("*----------------------Exending your Emotes---------------------*\n");
  write("| This tool will change your says to add a little color and a   |\n");
  write("| little class.  Below is a summary of what it lets you do, but |\n");
  write("| experimenting will tell the real story.                       |\n");
  write("| say <string>    -   You speak, and the room hears.            |\n");
  write("| emote <string>  -   Your name, followed by a string.          |\n");
  write("| pemote <string> -   Your name and \"'s\" followed by a string.  |\n");
  write("| emcolor <color> -   Change the color you use.                 |\n");
  write("| decolor         -   Get rid of this item.                     |\n");
  write("| emoteto <person> <string>  - create your own emote.           |\n");
  write("|     Example of emoteto:                                       |\n");
  write("| emoteto illarion points at your foot, and laughs at you.      |\n");
  write("| Illarion sees:                                                |\n");
  write("|    <yourname> points at your foot, and laughs at you.         |\n");
  write("| Everyone else sees:                                           |\n");
  write("|    <yourname> points at Illarion's foot, and laughs at him.   |\n");
  write("| Experiment to see what you can do, and enjoy.                 |\n");
  write("*---------------------------------------------------------------*\n");
  return 1;
}
/* Just like normal say except for the addition of color, a few cosmetic
 * changes, and reaction to various forms of punctuation
 */
status cmd_say(string str) {
  string sverb,rverb,modifier,temp;
  modifier = "";
  rverb= "says";
  sverb= "say";
  if(!str)
    return 0;
    if((temp=extract(str,strlen(str)-2))=="?!" || temp == "!?") {
    sverb="demand";
    rverb="demands";
  } else if(extract(str,strlen(str)-1)=="?") {
    sverb="ask";
    rverb="ask";
  } else if(extract(str,strlen(str)-1)=="!") {
    sverb="exclaim";
    rverb="exclaims";
  }
  if(sscanf(str,"%s:)",temp)) {
    modifier=" with a smile";
  } else if(sscanf(str,"%s;)",temp)) {
    modifier=" with a wink";
  } else if(sscanf(str,"%s:(",temp)) {
    modifier=" with a frown";
  }
  write((string)CLF->colorformat("You "+sverb+modifier+", \""+color+str+NORM+"\"",75));
  say((string)CLF->colorformat(TPN+" "+rverb+modifier+", \""+color+str+NORM+"\"",75));
  return 1;
}
/* helper function
 */
string resolve_quotes(string str) {
   string final;
   string *tokens;
   int x,n;
   tokens=explode(str,"\"");
   n=sizeof(tokens);
   if(n<=1)
      return str;
   for(x=1;x<n;x+=2)
      tokens[x]="\""+color+tokens[x]+NORM+"\"";
   final = implode(tokens,"");
   return final;
}
/* Just like normal emote, except that any text enclosed in double quotes
 * is colorized.
 */
int cmd_emote(string str) {
   tell_room(environment(this_player()),
       (string)CLF->colorformat(resolve_quotes((string)TPN+" "+str),75));
   return 1;
}
/* just like cmd_emote, except that it starts with <name>'s instead of
 * just the user's name.
 */
int cmd_pemote(string str) {
   tell_room(environment(this_player()),
       (string)CLF->colorformat(resolve_quotes((string)TPN+"'s "+str),75));
   return 1;
}
/* changes the color used everywhere the object uses color
 */
int cmd_emcolor(string str) {
   if(!str) {
      write(color+"This is your current color.\n"+NORM);
      write("To set another color, enter a choice from the following list:\n");
      write("black, white, green, red, blue, cyan, magenta, brown, and none.\n");
      return 1;
   }
   switch(str) {
      case "black":
         color = BLK;
         break;
      case "white":
         color = WHT;
         break;
      case "green":
         color = GRN;
         break;
      case "red":
         color = RED;
         break;
      case "blue":
         color = BLU;
         break;
      case "cyan":
         color = CYN;
         break;
      case "brown":
         color = YEL;
         break;
      case "magenta":
         color = MAG;
         break;
      case "none":
         color = "";
         break;
      default:
         write(str+" is not a valid color choice.\n");
         return 1;
   }
   write("Your new color is "+color+str+NORM+".\n");
   return 1;
}
/* emoteto allows a player to create an emote that will substitute the name
 * of the target and appropriate pronouns, which everyone but the target
 * (including the user) will see.
 */
int cmd_emoteto(string str) {
   string whos,whats,roomstr,nextletter;
   string *tokens;
   object who;
   status usedname,useposs;
   int n,x;
   if(!str || sscanf(str,"%s %s",whos,whats) !=2)
      FAIL("Syntax: emoteto <who> <what>\n");
   who=present(whos,environment(TP));
   if(!who)
      FAIL(whos+" is not here.\n");
   /* Put a character on either end of the string to ensure explode() creates
      the right number of strings */
   whats= "|"+whats+"|";
   tokens = explode(whats,"you");
   n=sizeof(tokens);
   roomstr="";
   for(x=0;x<n-1;x++) {
      useposs=0;
      nextletter=extract(tokens[x+1],0,0);
      roomstr+=tokens[x];
      if(nextletter == "n" || nextletter == "t") {
         roomstr+="you";
         continue;
      }
      if(nextletter == "r") {
         useposs=1;
         tokens[x+1]=extract(tokens[x+1],1);
      }
      if(!usedname) {
         usedname=1;
         roomstr+=(string)who->query_name()+(useposs?"'s":"");
      } else {
         if(useposs)
           roomstr+=(string)who->query_possessive();
         else
           roomstr+=(string)who->query_objective();
      }
   }
   if(!usedname) {
      write("You must use 'you' at least once in an emoteto.\n");
      return 1;
   }
   roomstr+=tokens[n-1];
   sscanf(roomstr,"|%s|",roomstr);
   sscanf(whats,"|%s|",whats);
   tell_room(environment(TP),format(TPN+" "+roomstr),({who}));
   tell_object(who,format(TPN+" "+whats));
   return 1;
}
status cmd_decolor() {
  write("The splinter of color fades away.\n");
  destruct(TO);
  TP->recalc_carry();
  return 1;
}
