/* This is taken from a file of Mizan's (with premission).
   Many thankx.
  Further modifications made by Saber.
*/

#define PATH1 "players/saber/tower/"
#define PATH2 "players/saber/closed/quest/ice/"

string room0, room1, room2, room3, room4;
string room5, room6, room7, room8, room9, room10;
object ob;
int i;

id(str)  { return str == "device"; }

init()  {
  add_action("update_tower","Reset");
        }

get()  { return 0; }

short()  { return "An anti lag device";  }

long()  {
 write(
  "This is an anti lag device, which can reset parts of Ryllian.\n\n"+
   "It can reset any of the following by typing <Reset> <place>\n\n"+
   "   The tower of portals <tower>\n"+
   "   The bandit forest <bandit>\n"+
   "   The innocent dreams <dreams>\n"+
   "   The eternal bar fight & hades rift <rift>\n"+
   "   The icy mountain <ice>\n"+
   "\n  Quest Rooms\n\n"+
   "   The ice mines <mines>\n"+
   "\nThankx to Mizan for the origional code and idea, which i'm afraid\n"+
   "I have rather strangely twisted to my own needs.  ;p\n");
        }

update_tower(str)  {
  if(!str || this_player()->query_level() < 20) return 0;
  switch(str)  {
    case "bandit": return update_1(); break;
    case "dreams": return update_2(); break;
    case "tower": return update_3(); break;
    case "rift": return update_5(); break;
    case "ice": return update_6(); break;
    case "mines": return update_7(); break;
    default: notify_fail("There is nothing to update by that name.\n");
      return 0; break;
        }
        }

update_1()  {
  write("Destroying ");
  set_array1();
  while(i < 9)  {
    ob = find_object(PATH1 + room0[i]);
    if(ob)  {
      destruct(ob);
      write(".");
        }
   i++;
        }
  write("\n[Device]: The Bandit Forest has been destroyed.\n");
  return 1;
        }

update_2()  {
  write("\nDestroying ");
  set_array2();
  while(i < 20)  {
    ob = find_object(PATH1 + room1[i]);
    if(ob)  {
      destruct(ob);
      write(".");
        }
  i++;
        }
  write("\n[Device]: The realm of innocent dreams has been destroyed.\n");
  return 1;
        }

update_3()  {
  update_1();
  update_2();
  update_4();
  update_5();
  update_6();
  write("\nThe Tower of Portals has been destroyed.\n");
  return 1;
        }

update_4()  {
  write("\nDestroying ");
  set_array4();
  while(i < 10)  {
    ob = find_object(PATH1 + room4[i]);
    if(ob)  {
      destruct(ob);
      write(".");
        }
  i++;
        }
  write("\n[Device]: The Tower of Portals fades away.\n");
  return 1;
        }

update_5()  {
  write("\nDestroying ");
  set_array5();
  while(i < 5)  {
    ob = find_object(PATH1 + room5[i]);
    if(ob)  {
      destruct(ob);
      write(".");
        }
  i++;
        }
  write("\n[Device]: Hades Rift and The Eternal Bar Fight are destroyed.\n");
  return 1;
        }

update_6()  {
  write("\nDestroying ");
  set_array6();
  while(i < 18)  {
    ob = find_object(PATH1 + room6[i]);
    if(ob)  {
      destruct(ob);
      write(".");
        }
  i++;
        }
  write("\n[Device]: The Icy Mountain has been destroyed.\n");
  return 1;
        }

update_7()  {
  write("\nDestroying ");
  set_array7();
  while(i < 23)  {
    ob = find_object(PATH2 + room7[i]);
      if(ob)  {
        destruct(ob);
        write(".");
        }
  i++;
        }
  write("\n[Device]: The Ice Mines have been destroyed.\n");
  return 1;
        }

set_array1()  {
  room0 = allocate(9);
  room0[0] = "tower10";
  room0[1] = "tower10+01";
  room0[2] = "tower10+1";
  room0[3] = "tower10+11";
  room0[4] = "tower10+2";
  room0[5] = "tower10+3";
  room0[6] = "tower10+4";
  room0[7] = "tower10+5";
  room0[8] = "tower10+6";
        }

set_array2()  {
  room1 = allocate(20);
  room1[0] = "dream1";
  room1[1] = "dream2";
  room1[2] = "dream3";
  room1[3] = "dream4";
  room1[4] = "dream5";
  room1[5] = "dream6";
  room1[6] = "dream7";
  room1[7] = "dream8";
  room1[8] = "dream9";
  room1[9] = "dream10";
  room1[10] = "dream11";
  room1[11] = "dream12";
  room1[12] = "dream13";
  room1[13] = "dream14";
  room1[14] = "dream15";
  room1[15] = "dream16";
  room1[16] = "dream17";
  room1[17] = "dream18";
  room1[18] = "dream19";
  room1[19] = "dream20";
        }

set_array4()  {
  room4 = allocate(10);
  room4[0] = "tower1";
  room4[1] = "tower2";
  room4[2] = "tower3";
  room4[3] = "tower4";
  room4[4] = "tower5";
  room4[5] = "tower1";
  room4[6] = "tower6";
  room4[7] = "tower11";
  room4[8] = "tower15";
  room4[9] = "tower16";
        }

set_array5()  {
  room5 = allocate(5);
  room5[0] = "tower9";
  room5[1] = "tower9+1";
  room5[2] = "tower14";
  room5[3] = "tower14+1";
  room5[4] = "tower14+2";
        
        }

set_array6()  {
  room6 = allocate(18);
  room6[0] = "tower20+5";
  room6[1] = "tower20+6";
  room6[2] = "tower20+61";
  room6[3] = "tower20+7";
  room6[4] = "tower20+71";
  room6[5] = "tower20+8";
  room6[6] = "tower20+01";
  room6[7] = "tower20+9";
  room6[8] = "tower20+02";
  room6[9] = "tower20";
  room6[10] = "tower20+1";
  room6[11] = "tower20+10";
  room6[12] = "tower20+11";
  room6[13] = "tower20+12";
  room6[14] = "tower20+13";
  room6[15] = "tower20+2";
  room6[16] = "tower20+3";
  room6[17] = "tower20+4";
        }

set_array7()  {
  room7 = allocate(23);
  room7[0] = "x1.c";
  room7[1] = "x2.c";
  room7[2] = "x3.c";
  room7[3] = "x4.c";
  room7[4] = "x5.c";
  room7[5] = "x6.c";
  room7[6] = "x7.c";
  room7[7] = "x8.c";
  room7[8] = "x9.c";
  room7[9] = "x10.c";
  room7[10] = "x11.c";
  room7[11] = "x12.c";
  room7[12] = "x13.c";
  room7[13] = "x14.c";
  room7[14] = "x15.c";
  room7[15] = "x16.c";
  room7[16] = "x17.c";
  room7[17] = "x18.c";
  room7[18] = "x19.c";
  room7[19] = "x20.c";
  room7[20] = "x21.c";
  room7[21] = "x22.c";
  room7[22] = "final.c";
        }
