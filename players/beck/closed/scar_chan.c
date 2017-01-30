/* quick patch for the bloodscar since the original scar
   used something in balowski's dirs that was wiped by him
   note: not very efficient, nor does it use the many
  functions balowski put into the scar but again
  this is a quickfix
   - Mythos <1-3-97>
*/
object all;

reset(arg) {
  if(arg) return;
  all = ({});
}

register(object what,string name) {
   all += ({what}); }

deregister(object what,string name) { all -= ({what}); }

users(string name) { return all; }

broadcast(string msg,int muf,string name) {
  int h;
  for(h=0;h<sizeof(all);h++) {
    if(all[h] && environment(all[h])) {
      if(muf || (!muf && !all[h]->query_muffled())) 
        tell_object(environment(all[h]),msg); 
    }
  }
}
