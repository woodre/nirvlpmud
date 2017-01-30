/* For command line calls in the format "cmd -flags arg", just sent the chars
 * from "flags" here and get the return mapping.
 * Used to read through an list of option flags from a command line
 * and fill in a mapping with the values.
 * All it really does right now is explode the letters from the string given
 * into a mapping with the values always 1.  In the future we can be more
 * intelligent with this, allowing options to assign specific values other than 1.
*/

mapping parse_options(string option_str) {
  int i, option_strlen;
  mapping ret;

  ret = ([ ]);
  option_strlen = strlen(option_str);
  for(i=0; i<option_strlen; i++)
    ret[option_str[i..i]] = 1;
  return ret;
}

