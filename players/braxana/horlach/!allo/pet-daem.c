/* cat system for saber's Dreamers
   note: please make sure all vars are in sinc
      i may have made sp mistakes
   basic idea is to creat ethe illusion that the
   cat is in existance in the room
   several ways to do so:
    1> create a 1k object that has a switch that 
       turns on and off the killability of the pet
      i.e. spirit cat form- kill off
            other forms- on
       best way to initiate combat is to place
       a hit_player() and heal_self() function in the
       1k object.. should these be triggered while in
       combatable mode the 1k ob is dested, a new 'monster'
       object is placed in and damage is done to monster
       and monster object starts combat
    2> usage of a master object to create illusionary
       imagery unless in combat.  
       i.e. master ob keeps track of pet owner and places
            tell_rooms to the environment to simulate
            pet emotes etc
    3> combination of 1 and 2 .. IMHO: this is the best 
       choice.  have the 1k object etc but use the master
       object to simulate the pet being alive.  combat 
       form and during combat should be a rather small
       mem monster best way to simply do an inherit 
       why this is probably best is that: the data base
       for the pets can be the master object itself
       data base will keep track of pet name, personality,
       owner vs pet relationship (good bad respected hate),
       what monster it has killed and had combat with,
       what players have attacked it, basic gossip about 
       owner, etc etc. heart_beat function will be used
       to simulate living.  note: consider rewriting 
       living and monster for combat form to slim it down
       i.e. take out the functions that are not needed. 
            no need to have hit_player be so long, no need
            for intox etc....
       
oks this is an example of the master object database idea
for option(3).  note: this is a rough base and will need to
be explanded and refined....- Mythos <11-22-96>
*/

/* again notes on the combat base monster
   in monster_died() have a destruct for the pet object
   and also do a erase() in this object that erases the
   array member from owner , pet object, options and 
   numop
   also, have in heart_beat or even a callout in the
   combat monster a check for query_attack()
   as soon as nocombat comes up, the master object is
   updated as for stats (hp etc) and then is dested while
   bringing in the original pet object in its place
   NOTE:   the normal pet object has a var
   called noncombat which can be referenced as noncombat()
   this noncombat is set to 1 when not in combat
   when combat begins this is set to 0 and then cloning
   and moving is done
*/

/* this will be using an odd array system there are better
   ways to do this but this is the easiest and most 
   intuitive databasing i can think up off the top of my
   head - Mythos 

  this is how it is done
    array pet        [ob1][ob2][ob3] etc
    array options    [str1][str2][str3] etc
    array numop      [int1][int2][int3] etc

    now options and intop are both a line of strings or  
    numbers to which each array member is a set of strings
    divided by the string "*" this way a explode efun
    can be used to divide up each member and compartmentized
    for usage in effect thi is what occurs:
         [ob1]  [ob2]  [ob3]
          ---    ---    ---
           s      s      s
           t      t      t
           r      r      r
           1      2      3  
           a      a      a
          ---    ---    ---
           s      s      s  
           t      t      t
           r      r      r
           1      2      3
           b      b      b
          ---    ---    ---
           etc   etc     etc
  
  NOTE: Im sure that mapping would make this simpler
        but improvements can always be made, again
        this is a rough rough sketch         
*/

#define SAVE "filepath to which data is saved"
#define PET  "filepath of 1k object"
#define CMBT "filepath of combat form"
#define HAVEN "filepath of safe haven"

static object pet; /* array for the pets */
string owner; /* array of owner names */
string options; /* array string for each pet */
                /* petname will most likely be member 0 */
string numop; /* array num for each pet 
                 note this is a tring array not an int
                 this so that the explode etc cant be
                 used */

string responses;  /* string array of responses
                      example: <such and such> dances
                               <such and such> screams
                      this is the string array to which 
                      the heartbeat uses for the illusion
                      of living
                      if players wish pet to do something
                      thier object (or even the pet object)
                      simply does a MASTER->do(mem);
                      where mem is an int of what array
                      member of response is to be done
                      i.e. responses = ({"moo","cow"});
                           MASTER->do(0);
                           pet does:
                           'moo'
                      this can be done by mapping to have
                      a string reference the array
                           map response;
                           response = ({"sound","eat")} 
                                 check the mapping docs
                                 for proper syntax
                           thus
                            MASTER->do("eat");
                           refernces the int 1 member
                           so responses[2] is done
                            i.e. 'cow'
                      hope that makes sense 
                      for now the usage of int is used
                      i.e. not mapping */


static int h;

id(str) { return str == "master_pet_database"; }

reset(arg) { 
  if(arg) return;
  object obs;
  if(!restore_object(SAVE)) {
   owner = ({});
   options = ({});
   numop = ({});
   pet = ({});
   responses = ({"dances"}); /* etc */
   save_object(SAVE);
  }
  else 
   for(h=0;h<sizof(owner);h++) 
    if(owner[h]) { 
     obs = clone_object(PET);
     pet += ({obs});
       /* note: this takes up mem space but saves
                cpu crunch by cloning the objects
                ahead of time and leaving them in
                mem. MAKE SURE THAT a !environment()
                check is placed in the objects 
                actually best bet is to move all objects
                to the safe haven 
       move_object(obs,HAVEN);  */
}
  set_heart_beat(1);  /* hb starts */
}

heart_beat() {
   /* this heart beat is set up to create th illusion of
      life */
  
  for(h=0;h<sizeof(pet);h++) {
    if(pet[h]) {
      if(pet[h]->noncombat()) {
          /* noncombat() is a function in the main 1k object
             that returns 1 if not in combat and if combat
             form is in play then returns 0 */
         if(!pet[h]->out() && find_player(owner[h])) {
              out function is set up so that it returns
              1 if it is out in nirvana and not in the
              haven otherwise it is 0
              */
            pet[h]->set_out(1);
            move_object(pet[h],
              environment(find_player(owner[h])));
         } 
         if(pet[h]->out()) {
         if(environment(pet[h]) != find_player(owner[h])) {
          tell_room(environment(pet[h],
               "such and such leaves the room.\n");
          move_object(pet[h],
                environment(find_player(owner[h])));
          do(owner[h],1); 
               /* where member 1 is 
                    "silently enters the room."
               */
        } }
     if(present("corpse",environment(pet[h]))) {
        /* set the value of the healing in the corpse to
           0 as you wished after you do the following : 
           assuming hp is array member 1 in the numop
           array set and member 0 is maxhp 
           this is of course array set after the extract
           is done - note you can make this easier by
           creating a direct hp and mhp reference in
           the master object */
        int hp,mhp;
        hp = extraction(numop[h],1,1);
        mhp = extraction(numop[h],0,1);
        hp += present("corpse",environment(pet[h]))->
                     heal_value();
        hp -= 1;
        if(hp > mhp) hp = mhp;
        trnt(numop[h],1,hp);   /* reinserts the hp into the
                                  array */
     /* reset the heal-value of the corpse */
     /* might want to do a do response with the pet 
        sucking out the corpse's essence */
   }
        
    if(random(10) == 0) {  /* might want to change the
                             random here */
      if(extraction(options,5) == "suave") {
         /* assuming member 5 is the personality */
         do(owner[h],10+random(5));
          /* assuming the personailty "suave" has the
             room responses members 10 - 14
             like: member 10 is "hangs back in the shadows."
                 member 11 is "peers at you with dark eyes."
                 member 12 is "looks very cool." etc
          */
      } }
    } }
  }

   /* to do gossiping between cats and what not
      is simply a transferance of data from one
      array member to another  - up to you on how 
      you wish to set that up and what members you 
      to make */  

}

/* extraction and trans and trnt are used to 
   input and out from the arrays in database
   arr should be options or numop
   it should be inputed into the functions as
   the array used (options or numop) and member array
   i.e. options[num] where num is from the 
     owner array: return for this is
     member_array(owner,nametoberefer);
     return of -1 means the name does not exist
*/

extraction(str arr,int mem,arg) {
/* this function allows one to extract stats from 
   the options or numop arrays */
string ext;
int exn;
ext = explode(arr,"*");
if(!arg) return ext[mem];
sscanf(ext[mem],"%d",exn);
return exn; }

trans(str arr,int mem,string what) {  
/* trans() and trnt() are functions to change stats etc
   in the options and numop arrays for each pet */
/* for integer array inserts use trnt() */
string ext;
ext = explode(arr,"*");
ext[mem] = what;
arr = implode(ext,"*");
return 1; }

trnt(str arr,int mem,int what) {
string moo;
sscanf(what,"%s",moo);  /* dont recall if sscanf works
                           on int to str but if it doesnt
                           simply do moo = ""+what+""; */
trans(arr,mem,moo);
return 1; }

erase(string who) {  /* clears the pet and all its
                        stats etc. who is name of owner */
int k;
  k = member_array(owner,who);
  pet -= ({pet[k]});
  owner -= ({who});
  options -= ({options[k]});
  numop -= ({numop[k]});
return 1; }

do(string own,int n) {  /* do function that creates illusion
                           of living */
tell_room(environment(find_player(own)),
    capitalize(extraction(option,member_array(owner,own)))+
    " "+responses[n]+"\n");
return 1; }


/* may want to make a function called dostr(string own,str)
  which allows you to do a direct tell_room
   without referenceing the responses array *shrugs*
*/

/* again this is all a rough sketch
   if you have any questions just ask...:>
  - Mas  ... Mythos <11-22-96> */

