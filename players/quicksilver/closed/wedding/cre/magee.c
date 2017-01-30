inherit "obj/monster";

#define MSG1 "Bishop Magee says: He is half part a blessed man, left to be finished by such\n                   as she, and she a fair devided excellence, whose fullness\n                   of perfection lies in him.\n"
#define MSG2 "Bishop Magee says: You come hither, my lord, to marry this lady?\n"
#define MSG3 "Bishop Magee says: Lady, you come hither to be married to this lord?\n"
#define MSG4 "Bishop Magee says: If any of you know any inward impediment why these two\n                   should not be conjoined, I charge you on your souls to\n                   utter it.\n"
#define MSG5 "Bishop Magee says: The rings please.\n"
#define MSG6 "Bishop Magee says: One feast, one house, one mutual happiness.\n"

             
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("bishop");
   set_race("human");
   set_gender("male");
   set_short("Bishop John Magee");
   set_long("With a warm smile, Bishop Magee welcomes you to the ceremony.  He is a rather\n"+
   "large man, with an even larger heart.  His dark brown eyes sparkle as he\n"+
   "glances around at those gathered to witness this union of two souls.\n");
   set_level(100);
   set_hp(300000);
   set_al(0);
   set_wc(1);
   set_ac(1000000000);
}

catch_tell(str) {
   int n;
   string foo;
       if (sscanf(str, "Quicksilver tells you: cue %d man%s", n, foo)) {
       switch(n) {
          case 1: tell_room(environment(this_object()), MSG1); break;
          case 2: tell_room(environment(this_object()), MSG2); break;
          case 3: tell_room(environment(this_object()), MSG3); break;
          case 4: tell_room(environment(this_object()), MSG4); break;
          case 5: tell_room(environment(this_object()), MSG5); break;
          case 6: tell_room(environment(this_object()), MSG6); break;
       }
       }
    return;
}
