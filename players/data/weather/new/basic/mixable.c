/*
 * basic/mixable.c by Alfe for Tubmud 2002-Apr-22
 *
 * base class for things which might be mixable, i.e. which can be an
 * ingredient for a mixture.
 */

private mapping ingredients;

void set_ingredients(mixed ing) {
  if (stringp(ing))
    ingredients = ([ ing: 1 ]);
  else if (mappingp(ing))
    ingredients = ing;
  else
    raise_error("Bad argument 1 to set_ingredients()\n");
}

mapping query_ingredients() {
  return ingredients;
}
