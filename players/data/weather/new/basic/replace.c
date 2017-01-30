/*
 * replace()
 * replaces all occurences of a set of strings in a given string 
 * with a corresponding set of other strings.
 * 1st argument is the initial string in which the strings should be replaced
 * 2nd argument is either an array of arrays, each of those having 
 * the string to be replaced as the first and the string to replace it with
 * as the second item, or it is a flat array of strings containing the
 * strings to be replaced. In the second case, the 3rd argument has to 
 * be the corresponding set of strings that should replace each of their
 * corresponding item in the 1st array.
 * Thus it is possible to: replace ("a b c",({({"a","d"}),({"b","f"})}))
 * which will result in "d f c", and it is also possible to achieve the
 * same with: replace("a b c",({"a","b"}),({"d","f"})).
 */
varargs string replace(string str, mixed old, string *new) {
  int size, i, j;
  string *arr;
  size = sizeof(old);
  if (!size)
    return str;
  if (mappingp(old)) {
    new = m_values(old);
    old = m_indices(old);
  }
  if (pointerp(old[0]))
    for(i=0;i<size;i++) {
      if (sizeof(arr = regexplode(str, old[i][0]))>1) {
	for(j=sizeof(arr)-2;j>0;j-=2)
	  arr[j] = old[i][1];
	str = implode(arr,"");
      }
    }
  else
    for(i=0;i<size;i++) {
      if (sizeof(arr = regexplode(str, old[i]))>1) {
	for(j=sizeof(arr)-2;j>0;j-=2)
	  arr[j] = new[i];
	str = implode(arr,"");
      }
    }
  return str;
}

