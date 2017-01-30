/*  thread.c is a pseadu thread object
  it is meant to be inherited 
   - Mythos <8-12-1999>
*/
int wake, wait;
int returnvali;
string returnvals;
private int nswitch, cycle;

nomask id(str) { return str == "thread"; }

nomask reset(arg) {
  if(arg) return;
  nswitch = cycle = 0;
  wake = 1;
  wait = 0;
  returnvali = 0;
  returnvals = 0;
  begin();
}

/* these functions are meant to be rewritten  */
begin() { return 1;}
    /* begin - the function that is called when the thread is cloned */
ndoatstop() { return 1; }
    /* ndoatstop- function called when stopis called */
fallasleep() { return 1; }
    /* fallasleep - function when thread is put to sleep */
whattondo() { return 1; }
    /* whattondo - function called that is what the thread is to do every cycle */

nomask drop() { return 1; }
nomask get() { return 0; }

nomask query_wake() { return wake; }
nomask query_wait() { return wait; }
nomask query_cycle() { return cycle; }
nomask set_returnvali(int a) { returnvali = a; }
nomask set_returnvals(string h) { returnvals = h; }
nomask query_returnvali() { return returnvali; }
nomask query_returnvals() { return returnvals; }

nomask start() {
  if(wake && !cycle) { cycle = 1; ndo(); cycle = 0; }
  if(!nswitch) { remove_call_out("start"); call_out("start",1); }
  else stop();
return 1; }

nomask stop() {
  ndoatstop();
  end();
return 1; }

nomask sleep() {
  fallasleep();
  wake = 0;
return 1;}

nomask wait() {
  wait = 1;
  returnvali = 0;
  returnvals = 0;
  remove_call_out("start");
  call_out("waitcycle",1);
return 1; }

static wait_cycle() {
  if(!returnvali && !returnvals) { call_out("waitcycle",1); return 1; }
  end_wait();
return 1; }

nomask end_wait() {
  if(wait) {
    wait = 0;
    call_out("start",1);
  }
return 1; }

static ndo() {
  if(wait) { wait(); return 1; }
  whattondo();
return 1;}

static end() {
  destruct(this_object());
return 1;}
