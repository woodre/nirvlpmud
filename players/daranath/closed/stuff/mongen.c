/* arrays-> imagine a big box with stuff in it
            each 'stuff' is in its own compartment
            in the box.  the box is the array
            the compartments are 'partitions'
            the stuff are the members
            each of the stuff can be referenced
            by the partition and each partition has 
            a number to which it is assigned
            to reference the stuff you reference the
            partition number (kind of like when one is
            given a number when waiting at the DMV)
            now the symbols to which the arrays are 
            referenced and defined are as follows:
              (say the array is an array of strings)
              string *arr;  (note: in LPC the * is not 
                             needed, one can simply use
                             string arr; )
              arr = ({"hi","moo","poing","zoom"});
                  the above array arr has 4 members
                  which can each individually be referenced
                  like this:
                       arr[0]  or arr[1] etc
                       arr[0] is "hi"
                       arr[3] is "zoom"
                  note: arrays are numbered with the first
                        member as 0
              now to add to an array (ie. add a new member)
              arr += ({"added"});  which makes 
                 arr[4] is now "added"
              to get rid of a member one can do this:
              arr -= ({"moo"}); which gets rid of 
                arr[1] so arr is now ({"hi","poing","zoom"})
                one could even do this arr -= arr[1];
              basic 'math functions' can be done to the
              array members like:
              arr[0] = arr[0] + " art";
              thus arr[0] is now "hi art";
              (note: math functions with strings is a tad
                     odd any additions simply add onto
                     the end of the string - dont try 
                     subtraction or multiplicatin..:> )
              (note: however when dealing with a numbered
                     array (i.e. int arr) each member can
                     be referenced and manipulated in normal
                     fahion)
              now there are 2 basic ways to set up an array
              in say a master object
              first way:   make arr = ({}); and then
                           whenever you wish to add member
                           you make a function that allows
                           that ->   
                               add_mem(str) { 
                                   arr += ({str}); }
              second way:  use somethign called allocate
                           arr = allocate(100);
                           this makes a 100 membered array
                           (i.e. 100 prtitions)
                           all of which the values are 0
                           and with another fuction
                           change array members to what you
                           wish ->
                                add_mem(str,n) {
                                     arr[n] = str; }
              in the case of this object the second way is 
              used 
    if the above is in any way unclear just ask...
    - Mythos <12-02-96>

p.s. there are several specidic external functions (efun)
for array manipulation remind me to give you the efun 
list up ... but quick examples of such efuns are:
    sizeof(arr)             returns a int which is the
                            number of members in the array
    member_array(what,arr)  returns the 'partition' number
                            of 'what' in the array
                            a -1 indicates that 'what' is
                            not in arr
    filter_array(arr,func)  puts the members of the array
                            into the function func and
                            produces a new array
  etc
*/

#define NUM 12;

string file1,file2,file3,file4,file5,file6;
string where;

id(str) { return str == "monster_gen" || str == "mongen"; }
  /* id(str) is the id of the object.. it 'name' */

get() { return 0; }  /* prevents someone from getting it
                        return  1 allows getting */

drop() { return 1; } /* prevents dropping object return 0 
                        allows dropping */

short(){ return "Daranath's Diabolique Monster Generator"; }

reset(arg) {
  if(arg) return;

  file1 = allocate(NUM);
  file2 = allocate(NUM);
  file3 = allocate(NUM);
  file4 = allocate(NUM);
  file5 = allocate(NUM);
  file6 = allocate(NUM);
  where = allocate(6);   /* where is the room dir
                            for the levels */

  where[0] = "players/daranath/level1";
  where[1] = "players/daranath/level2"; /* etc */

  /* here you will want to create the list up for each 
     array 
     note: there are other ways to do this but for now
           this is easiest */

  /* examples: */

  file1[0] = "/players/daranath/mon/ogre.c";

  /* etc */

  set_heart_beat(1);  /* starts the heartbeat */

}

/* note: the monster generator checks every hb! */

heart_beat() {
object ob;
string null;
int h;
object env,mon;
ob = users(); /* ob is an array of players on line */
  for(h=0;h<sizeof(ob);h++) {
    if(environment(ob[h])) {    /* making sure the
                                    referenced player is
                                    in a room */
        env = environment(ob[h]);
      if(creator(env) == "daranath") {
                       /* checks if that room is made
                          by daranath */
        if(sscanf(env,where[0]+"%s",null)) {
             /* checking to see if the room path is
                in the where[0] dir */
             /* note on sscanf: this is a bit of a
                     hard one to explain- we'll wait  */
        if(random(10) == 0) {    
              /* 1 in 10 chance to happen */
            mon = clone_object(file1[random(NUM)]);
            mon->set_aggressive(1);
            move_object(mon,env); }
        }
      /* do the same for the other members of where arr */
       }
     }
    }
}


