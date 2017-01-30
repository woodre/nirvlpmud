/* docs.c
 * This contains all the help functions
 */
#include "path.h"

rules() {
  write("These rules are an exact copy of the rules that come with the\n"
      +"Monopoly game and are not exactly the rules used by this version.\n\n");
  TP->more("/"+RULES);
  return 1;
}

_help(what) {
  string tmp;

  if(!what) what="topics";

  sscanf(what,"%s %s",what,tmp);

  if(!function_exists("_"+what)) FAIL("No help available on that topic\n");
  call_other(this_object(),"_"+what);
  write("\n");
  return 1;
}

_monopoly() {
  TP->more("/"+MHELP);
  return 1;
}

_topics() {
  string str;

  str="-----------------\nMonopoly Commands:\n-----------------\n\n"
   +"  mwho:              monopoly who\n"
   +"  mshout:            monopoly shout\n"
   +"  exit game:         leaves monopoly game\n"
   +"  l <property>       look at property card\n"
   +"  l <player>         show players status in game\n"
   +"  mi or i            game inventory (use mi if i does regular inv.)\n"
   +"  list properties    to show owners and property names\n"
   +"  roll               take your turn (roll dice)\n"
   +"  buy                buy this property\n"
   +"  buy houses..       do 'help buy' or 'buy' for usage\n"
   +"  sell houses..      opposite of buy.  (also 'remove')\n"
   +"  mortgage <prop>    mortgage a property to get 1/2 its price.\n"
   +"  unmortgage <prop>  unmortgage a property at "
                    +MORTGAGE_PERCENT+"% interest\n"
   +"  return             return to current game square\n"
   +"  pay                pay to get out of jail\n"
   +"  use card           use Get Out Of Jail card\n"
   +"  give               for trading (also 'mgive')\n"
   +"  brief              toggle brief or verbose\n"
   +"->help               show this\n"
   +"->help monopoly      explain game\n"
   +"->help <command>     give help on a specific command\n"
   +"->help id            explain naming conventions of the squares.\n"
   +"  rules              shows the authentic rules from the board game.\n  \n";
/*
  this_player()->more_str(str);
*/
  write(str);
  return 1;
}

_mwho() {
  write("Command:  mwho\n");
  write("optional argument:  game name\n\n");
  write("Shows players and the following info:\n");
  write("  Cash held, current square and turn number.\n");
}

_mshout() {
  write("Command:  mshout\n");
  write("argument:  string\n\n");
  write("Shouts a string to all players in your game.\n");
}

_exit() {
  write("Command:  exit\n");
  write("optional argument:  game\n\n");
  write("'exit' when you are at the Go square will leave the board.\n");
  write("'exit game' anywhere will quit the monopoly game.\n");
}

_l() { return _look(); }
_look() {
  write("Command:  look\n");
  write("optional argument:  <property name> <player name>\n\n");
  write("Monopoly extends the normal look command of the mud so that\n");
  write("can also look at property cards and other players monopoly\n");
  write("holdings (even on another space)\n");
}

_list() {
  write("Command:  list\n");
  write("argument:  properties\n\n");
  write("Shows all properties and the following information:\n");
  write("  ID (help id), owner and number of houses\n");
}

_roll() {
  write("Command:  roll\n\n");
  write("Takes your turn by rolling dice and moving forward.\n");
}

_buy() {
  write("Command:  buy\n");
  write("optional argument:  house [at|on] <square>\n");
  write("                    houses [at|on] <monopoly number>\n\n");
  write("By itself, this will try to buy the current square you are on.\n");
  write("'buy' can also buy houses, on one square or a house for each\n");
  write("square in a monopoly.  Examples:\n");
  write("  buy house on charles\n");
  write("  buy houses at 4    (see inventory for monopoly number)\n");
}

_remove() {
  write("Command:  remove\n\n");
  write("This command is the opposite of buy for houses.\n");
}

_sell() { 
  write("Command:  sell\n\n");
  write("This command is the opposite of buy for houses.\n");
}

_mortgage() {
  write("Command:  mortgage\n");
  write("argument:  property\n\n");
  write("Mortgages a property for 1/2 the price (no rent will be collected)\n");
}

_unmortgage() {
  write("Command:  unmortgage\n");
  write("argument:  property\n\n");
  write("Unmortgages a property at "+MORTGAGE_PERCENT+"% interest.\n");
}

_rules() {
  write("Command:  rules\n\n");
  write("Print out the monopoly rules as per Parker Brothers.\n");
}

_return() {
  write("Command:  return\n\n");
  write("Returns to current square.\n");
  write("This only works if you are somewhere on the monopoly board.\n");
}

_i() { return _inventory(); }
_inventory() {
  write("Command:  inventory  (or 'i')\n");
  write("optional argument:  <player name>\n\n");
  write("Shows player information:\n");
  write("  Cash, properties and cards.\n");
  write("with argument, will show inventory of another player.\n");
}

_brief() {
  write("Command:  brief\n\n");
  write("Monopoly uses the regular mud brief switch to suppress\n");
  write("the printing of some unimportant information.\n");
}

_pay() {
  write("Command:  pay\n\n");
  write("Pay "+MS+"50 to get out of jail.\n");
  write("After paying, you can then take your turn.\n");
}

_use() {
  write("Command:  use\n");
  write("argument:  card\n\n");
  write("Use a Get Out of Jail Free card.\n");
  write("After using the card, you can then take your turn.\n");
}

_give() { return _mgive(); }
_mgive() {
  write("Command:  mgive  (or 'give')\n");
  write("argument:  <what> to <who>\n\n");
  write("This command allows trading in the game.  the 'what' field can be:\n");
  write("  $<money>,  <property name>, card\n");
  write("A trade requires two mgives, and it is based on the honor system.\n");   write("The rules require that trades that are agreed upon must be\n");
  write("followed through, but there is nothing to enforce this.\n");
}

_ID() { return _id(); }
_id() {
  write("  ID help\n\n");
  write("Monopoly properties can only be referenced by ONE name, "
       +"called the id.\n");
  write("Other references to properties will not work, for example:\n");
  write("  buy house on stcharles       (won't work)\n");
  write("  buy house on charles         (will work)\n");
  write("To find out the id of a property, you can either 'list properties'\n");
  write("or, if you own it, by 'inventory'\n");
  write("I have tried to stick to this convention in picking ids:\n");
  write("  1)  pick first full word\n");
  write("  (discounting abbreviations like st in St. James and St. Charles,\n");
  write("   but using new for New York)\n");
  write("  2)  exceptions:\n");
  write("      b&o       B. & O.  RailRoad\n");
  write("      pennrr    Pennsylvania RailRoad\n");
  write("      pennave   Pennsylvania Avenue\n");
}

