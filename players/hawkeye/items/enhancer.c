query_auto_load(){
  return("/players/static/obj/enhancer.c:");
    }

#define V this_player()->query_name() 
reset(arg)
{
    if (arg) return;
}

drop(){
     if (query_verb() == "drop")
   write("You wouldn't want to do that!\n");
     return 1;
}

id(str){
  return str == "enhancer";
}

get(){
  return 1;
}

short(){
  return "Emotions enhancer";
}
long(){
  write ("Emotions enhancer (type 'help2' for list of added emotions)\n"+
    "This enhancer is far from being complete.  If you have any\n"+
    "comments, please send mail to Static or Hawkeye.\n");
}

init()
{
  add_action("help2", "help2");

  add_action("ack",       "ack");
  add_action("agree",     "agree");
  add_action("be",        "be");
  add_action("blink",     "blink");
  add_action("cackle",    "cackle");
  add_action("exclaim",   "exclaim");
  add_action("goose",     "goose");
  add_action("high_five", "high5");
  add_action("hmm",       "hmm");
  add_action("innocent",  "innocent");
  add_action("okay",      "ok");
  add_action("shake",     "shake");
  add_action("think",     "think");
  add_action("thwap",     "thwap");
  add_action("who2",      "who2");
  add_action("noogie",   "noogie");
  add_action("headlock", "headlock");
  add_action("jab", "jab");
  add_action("sucker", "sucker");
  add_action("snort", "snort");
  add_action("flipoff", "flipoff");
  add_action("blah", "blah");

}

gender_pos() {

string gender, genpos;
object plyr;

plyr = this_player();

gender = plyr->query_gender_string();

if (gender == "female")
  genpos = "her";

if (gender == "male")
  genpos = "his";

if (gender == "creature")
  genpos = "its";

return genpos;
}

help2()
{
  cat("/players/static/obj/enhance_help");
  return 1;
}

who2() {
string name, spaces, where;
int count, i, t, amt, invis, lvl;

object list, scratch;
list = users();
count = 1;
write("\n"+
"     Name            Location\n"+
"<----------------------------------------------------------------------->\n");
for (i<0; i<sizeof(users()); i++) {
  name = list[i]->query_name();
  invis = list [i]->query_invis();
  lvl = list[i]->query_level();
  scratch = environment(list[i]);
  if(scratch && invis < 1 && lvl < 20) {
    where = call_other(scratch, "short");
  amt = (15 - strlen(name));
  spaces = " ";
  for(t=0; t<amt; t++) {
    spaces = spaces + " ";
    }
  name = name + spaces;
if (count < 10)
   write("  "+count+": " + name + where + "\n");
else
   write (" "+count+": "+name+where+"\n");
count += 1;
        }
  }
write(
"<----------------------------------------------------------------------->\n");
  return 1;
}

ack() {
  say(this_player()->query_name()+" acks.\n");
  write("You ack.\n");
  return 1;
}

agree() {
  say(this_player()->query_name()+" nods in agreement.\n");
  write("You nod in agreement.\n");
  return 1;
}

be(str) {

  if(!str) {
    write("Be what?\n");
    return 1;
    }
  say(this_player()->query_name()+" appears to be "+str+".\n");
  write("You appear to be "+str+".\n");
  return 1;
}

blink() {

  say(V+" blinks.\n");
  write("You blink.\n");

  return 1;
}

cackle() {

  say(V+" throws back "+gender_pos()+
      " head and cackles with glee!\n");
  write("You cackle gleefully.\n");
  return 1;
}

exclaim(str)
{
  if(!str) {
    write("Exclaim what?\n");
    return 1;
    }

    write("You exclaim: " + str + "\n");
    say(V + " exclaims: " + str + "\n");
    return 1;
}

goose(str)
{
  object friend;
  if(!str) {
    write("Goose who?\n");
    return 1;
    }
  friend = present(lower_case(str), environment(this_player()));
  if (!friend || !living(friend) || friend == this_player())
    return 0;
  write("You goose "+str+"!\n");
  tell_object(friend, this_player()->query_name()+" sneaks up "+
    "behind you and gooses you!\n");
  say(this_player()->query_name()+" sneaks up and gooses "+str+"!\n",
    friend);
  return 1;
}

high_five(str)
{
  object friend;
  if(!str) return 0;
  friend = present(lower_case(str), environment(this_player()));
  if (!friend || !living(friend) || friend == this_player())
    return 0;
  write("You run up and slap "+capitalize(str)+" a high-five!\n");
tell_object(friend, this_player()->query_name()+" runs up to you "+
  "and slaps you a high-five!\n");
  say(this_player()->query_name()+" slaps "+capitalize(str)+
  " a high-five!\n", friend);
  return 1;
}

hmm()
{
  say(V + " says: hmm...\n");
  write("You say: hmm...\n");
  return 1;
}

innocent()
 {
  say(this_player()->query_name()+" whistles innocently.\n");
  write("You whistle innocently.\n");
  return 1;
}

melt(str)
{
  object friend;
  if(!str){
    say(this_player()->query_name()+" melts.\n");
    write("You melt.\n");
    return 1;
    }
  friend = present(lower_case(str), environment(this_player()));
  if (!friend || !living(friend) || friend == this_player())
    return 0;
  say(this_player()->query_name()+" melts in "+capitalize(str)+
    "'s arms.\n", friend);
  write("You melt in "+capitalize(str)+"'s arms.\n");
  tell_object(friend, this_player()->query_name()+" melts in your "+
    "arms.\n");
  return 1;
}

okay() {

  say(V + " says: okay\n");
  write("You say: okay\n");
  return 1;
}

shake(str) {

object who;

if (!str) {
  write("You shake your head.\n");
  say(this_player()->query_name()+" shakes "+gender_pos()+
  " head.\n");
  return 1;
  }

if (str == lower_case(V)) return 0;
who = present(str, environment(this_player()));
if (!who) return 0;

write("You shake hands with "+str+".\n");
say(V + " shakes hands with " + str + ".\n", who);
tell_object(who, V + " shakes your hand.\n");
return 1;
}

think(str)
{
if (!str) {
   write("You think carefully.\n");
     say(V+ " thinks carefully.\n");
   return 1;
}

   write("You think "+str+".\n");
     say(V+ " thinks "+str+".\n");
   return 1;
}

thwap(str)
{
object victim;
if (!str) return 0;
victim = present(str, environment(this_player()));
if (!victim) return 0;

write("You thwap "+str+".\n");
say(V + " thwaps "+str+".\n", victim);
tell_object(victim, V + " thwaps you.\n");
return 1;
}
  noogie(str) {
  object victim;
  if(!str) return 0;
   victim = present(str, environment(this_player()));
  if(!victim) return 0;
   write("You grab "+str+" and give 'em a noogie.\n");
  say(V + " gives "+str+" a noogie.\n");
tell_object(victim, V + " gave you a noogie.\n");
 return 1;
}
headlock(str) {
  object victim;
  if(!str) return 0;
  victim = present(str, environment(this_player()));
  if(!victim) return 0;
write("You put "+str+" in a head lock.\n");
  say(V + " puts "+str+" in a headlock.\n");
  tell_object(victim, V +" put you in a headlock.\n");
  return 1;
}
jab(str) {
  object victim;
  if(!str) return 0;
  victim = present(str, environment(this_player()));
  if(!victim) return 0;
  write("You reach out with two fingers and jab "+str+" in the eyes.\n");
  say(V + " reaches out with two fingers and jabs "+str+" in the eyes.\n");

  tell_object(victim, V +" just jabbed you in the eyes.\n");
return 1;
}
sucker(str) {
  object victim;
 if(!str) return 0;
victim = present(str, environment(this_player()));
  if(!victim) return 0;
  write("Pointing to the sky, you get "+str+" to look up and you sucker punch 'em in the stomach.\n");
  say(V + " points to the sky and as "+str+" looks up, "+V+" sucker punches 'em.\n");
   tell_object(victim, V +" just sucker punched you!\n");
  return 1;
}
  blah() {
  say(V + "says: Blah!!\n");
   write("You say: Blah!!\n");
  return 1;
}
    flipoff(str) {
  object victim;
 if (!str) return 0;
  victim = present(str, environment(this_player()));
  if(!victim) return 0;
  write("You extend your middle finger and flip off "+str+".\n");
  say(V + " extends " + gender_pos()+ " middle finger towards " + str+" and says Screw YOU!\n");
   tell_object(victim, V +" just gave you the byrd!\n");
  return 1;
}
snort() {
say(V + " snorts loudly!\n");
   write("You snort loudly.\n");
  return 1;
}
