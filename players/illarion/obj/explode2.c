/* Redoes explode so that starting or ending the string with the 
   element to be exploded around still creates the 'correct' number
   of elements in the resulting array:
   old explode:
     explode("aaababbabaa","a") = ({"b","bb","b",""});
   explode2 results in:
     ({"","","","b","bb","b","",""})
   
   This results in implode(explode2(str,whatever)) == str
   no matter what the contents of str
*/

string *explode2(string what, string by) {
  string *result;
  string word;
  int wsize,bsize;
  int s;
  if(!what || !by)
    return 0;
  bsize=strlen(by)-1;

  if(bsize<0)
    return explode(what,by);
  wsize=strlen(what);
  s=0;
  word="";
  result=({});
  while(s < wsize) {
    if(what[s..s+bsize]==by) {
      result+=({word});
      word="";
      s+=bsize+1;
    } else {
      word+=what[s..s];
      s++;
    }
  }
  result+=({word});
  return result;
}
  