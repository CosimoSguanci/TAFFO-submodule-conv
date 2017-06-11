

float random(void)
{
  static unsigned int seed = 123456;
  seed = (seed * 0xc8a1248f + 42) % 0xfffffffe;
  return (double)seed / (double)(0xffffffff);
}


float test(int p1, int p2, float num1, float num2, float num3)
{
  float phi __attribute((annotate("no_float")));
  
  if (p1)
    phi = num3;
  else
    phi = 1.5;
  phi *= random();
  if (p2) {
    phi += num1;
    phi *= random();
  } else
    phi /= random();
  return phi;
}
  
