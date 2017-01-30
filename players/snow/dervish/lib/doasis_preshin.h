#define ENV environment
#define TP this_player()
#define ENVTP ENV(TP)
#define CAP capitalize
#define QN query_name()

dervish_oasis()
{
 object att, *ob;
 int    h, s;
 s = sizeof(ob = all_inventory(ENVTP));
 
 while(h < s)
 {
  if(att = (object)ob[h]->query_attack())
  {
   ob[h]->stop_fight();
   att->stop_fight();
  }
  h ++;
 }

 tell_room(ENVTP, 
  CAP((string)TP->QN)+" summons a calming oasis into the room.\n");
 return 1;
}