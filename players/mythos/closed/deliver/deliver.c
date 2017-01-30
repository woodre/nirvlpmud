#define person1  "autumn"
#define present1  "/players/mythos/closed/deliver/notea.c"
#define person2  "laurana"
#define present2  "/players/mythos/closed/deliver/notel.c"
#define person3  "servant"
#define present3  "/players/mythos/closed/deliver/note.c"

int del1, del2, del3;

id(str) {return str == "deliver"; }
drop() {return 1;}

reset(arg) {
  if(arg) return;
  del1 = 0;
  del2 = 0;
  del3 = 0;
}

init() {
  call_out("hb",10);
}

hb() {
 restore_object("players/mythos/closed/deliver/check");
   if(!del1 && find_player(person1)) {
     tell_room(environment(find_player(person1)),
          "\nA small fairy flies over to "+capitalize(person1)+".\n"+
          "It whispers something to "+capitalize(person1)+".\n\n");
     tell_object(find_player(person1),
          "The fairy hands you something and whispers: From Mythos.\n\n");
     tell_room(environment(find_player(person1)),
          "Then the fairy flies off.\n\n");
     move_object(clone_object(present1),find_player(person1));
     del1 = 1; }
   if(!del2 && find_player(person2)) {
     tell_room(environment(find_player(person2)),
          "A grumpy looking dwarf stomps over to "+capitalize(person2)+".\n"+
          "The dwarf whispers something to "+capitalize(person2)+".\n\n");
     tell_object(find_player(person2),
          "The dwarf hands you something and whispers: From Mythos.\n\n");
     tell_room(environment(find_player(person2)),
          "Then the dwarf stomps off.\n\n");
     move_object(clone_object(present2),find_player(person2));
     del2 = 1; }
   if(!del3 && find_player(person3)) {
     tell_room(environment(find_player(person3)),
          "A grumpy looking dwarf stomps over to "+capitalize(person3)+".\n"+
          "The dwarf whispers something to "+capitalize(person3)+".\n\n");
     tell_object(find_player(person3),
          "The dwarf hands you something and whispers: From Mythos.\n\n");
     tell_room(environment(find_player(person3)),
          "Then the dwarf stomps off.\n\n");
     move_object(clone_object(present3),find_player(person3));
     del3 = 1; }
 save_object("players/mythos/closed/deliver/check");
 call_out("hb",10);
return 1;}

