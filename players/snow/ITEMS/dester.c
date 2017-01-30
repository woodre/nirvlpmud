/*Thunderbolt dester*/

#define NAME this_player()->query_real_name()
#define TP this_player()

id(str) {return str == "thunderbolt" || str == "dester"; }
short() {return "Thunderbolt";}
alias() {return "thunderbolt";}
long() {
  write(
"This is Snow's Thunderbolt dester. To use, 'thunderbolt <player>'.\n"+
"Have fun...\n");
       }
can_put_and_get() {return 0;}
get() {return 1;}

init() {
if(NAME == "snow" || NAME == "dune") {
  add_action("thunderbolt","thunderbolt");
  }
       }

thunderbolt(str) {
object ob;
ob = find_player(str);
  if(!str) {
write("Thunderbolt who?\n");
           }
shout("A Thunderbolt rockets down from the heavens!\n");
shout(capitalize(NAME)+" is blasted from the mud!\n");
 if(!ob) {ob = find_living(str);}
  if(!ob) {write("This player is not on right now...\n");
           return 1; }
write("With godly might you cast a Thunderbolt at "+capitalize(str)+"\n");
shout("A Thunderbolt rockets down from the heavens!\n");
  destruct(ob);
write(capitalize(str)+" is blasted from the mud!\n");
shout(capitalize(str)+" is blasted from the mud!\n");
return 1;
}
