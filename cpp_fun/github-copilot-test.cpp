float Q_rsqrt(float number) {
  float x2 = number * 0.5f;
  float y = number;
  long i = *(long *)&y;      // evil floating point bit level hacking
  i = 0x5f3759df - (i >> 1); // what the fuck?
  y = *(float *)&i;
  y = y * (1.5f - (x2 * y * y)); // 1st iteration
  //	y = y * ( 1.5f - ( x2 * y * y ) ); // 2nd iteration, this can be removed
  return number * y;
}